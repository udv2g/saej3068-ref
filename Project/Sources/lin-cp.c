#include "lin-cp.h"
#include "globals.h"
#include "info_codes.h"
#include "info_code_handler.h"
#include "scheduler.h"
#include "protocol_version_handler.h"
#include "ids_handler.h"
#include "j3072_handler.h"


// clang-format off
enum FrameFlag {NotReceived = 0, Compatible, Incompatible, Received = 1, Restart = 2, NotArrived = 3};
#ifdef SE_CONFIG
static enum FrameFlag EvMinVoltsFrame[2], EvCurrentsFrame[2], EvMaxVoltsFrame[2], EvStatusFrame[2];
static bool lin_Restart[2] = {FALSE, FALSE}, ver_Restart[2] = {FALSE, FALSE}, mcu_Restart[2] = {FALSE, FALSE}, pwr_Restart[2] = {FALSE, FALSE}, int_Restart[2] = {FALSE, FALSE};
#else
bool SeNomVoltagesRcvd[2] = {FALSE, FALSE}, SeMaxCurrentsRcvd[2] = {FALSE, FALSE};
#endif
enum {PWM, AnnexD, J3068, Error8bit = 254, NotAvail_8bit = 255};
enum {Incomplete = 0, Complete = 1, Error2bit = 2, NotAvail_2bit = 3};
enum {Deny_V, Permit_V};
#define NotAvail_16bit 0xFFFF
#define MaxValidVoltage 10000  // 1000V
#define MaxValidCurrent 250    // 250A
// clang-format on

static l_u8 SeCommVer[2]   = {Error8bit, Error8bit}; // 254 = error, but should never be seen except for weird crash?
static l_u8 EvCommVer[2]   = {Error8bit, Error8bit};
static l_u8 EvStatusVer[2] = {Error2bit, Error2bit}, EvStatusInit[2] = {Error2bit, Error2bit}, EvStatusOp[2] = {Error2bit, Error2bit};
static l_u16 EvMaxVoltsLL[2] = {0, 0}, EvMaxVoltsLN[2] = {0, 0}; // Don't use default NotAvailable (0xFFFF) here as it looks like a high voltage to an inequality evaulation :(
static l_u16 EvMinVoltsLL[2] = {NotAvail_16bit, NotAvail_16bit}, EvMinVoltsLN[2] = {NotAvail_16bit, NotAvail_16bit};
static l_u8 EvMaxAmpsL1[2], EvMaxAmpsL2[2], EvMaxAmpsL3[2], EvMaxAmpsN[2], EvMinAmpsL1[2], EvMinAmpsL2[2], EvMinAmpsL3[2];
//do not use
//l_u8 SeAvailableAmpsL1 = 254, SeAvailableAmpsL2 = 254, SeAvailableAmpsL3 = 254, l_u8 SeAvailableAmpsN = 254;
static l_u8 SeMaxAmpsL1[2] = {Error8bit, Error8bit}, SeMaxAmpsL2[2] = {Error8bit, Error8bit}, SeMaxAmpsL3[2] = {Error8bit, Error8bit}, SeMaxAmpsN[2] = {Error8bit, Error8bit};
static l_u8 EvSelectedVer[2]       = {Error8bit, Error8bit};

static bool pvers_rcvd[2];

SCHEDULE_PICKER SchedulePicker[2];
//SCHEDULE_PICKER_EVENTS SchedulePickerMessage;

void PrintLinCPStatus(uint8_t ch) {
  PrintConsoleString("V:", 0);
  PrintConsoleHex((SeStatusVer[ch] << 4) | EvStatusVer[ch]);
  PrintConsoleString(" I:", 0);
  PrintConsoleHex((SeStatusInit[ch] << 4) | EvStatusInit[ch]);
  PrintConsoleString(" O:", 0);
  PrintConsoleHex((SeStatusOp[ch] << 4) | EvStatusOp[ch]);
  PrintConsoleString("\r\n", 0);
}

void InitializeLINvariables(uint8_t ch);

#ifdef EV_CONFIG

/**********************************************************
************************<EV_CONFIG*************************
***********************************************************/

uint32_t clear_last_connectionA(void * a)  {
  clear_all_info_codes(A);
  return 0;
}

uint32_t clear_last_connectionB(void * a)  {
  clear_all_info_codes(B);
  return 0;
}

#define clear_last_connection(x) ((x) ? clear_last_connectionB : clear_last_connectionA)

uint32_t version_timeoutA(void * a)  {
  EvStatusVer[A] = Error2bit;
  (void)set_priority_info_code(A, EVINFOENTRY_VERSION_FAILS);
  schedule_if_unscheduled(CONNECTION_CLEAR_TIME, clear_last_connection(A), NULL);    //Don't tell the next station about this one's failures
  InitializeLINvariables(A);
#pragma MESSAGE DISABLE C2705 //possible loss of data
#pragma MESSAGE DISABLE C4002 //result not used -- ternary operator should not be used for assignements
//Why does this fix all of them?
  l_bool_wr_LI0_EvAwake(0);   //request sleep
  return 0;
}

uint32_t version_timeoutB(void * a)  {
  EvStatusVer[B] = Error2bit;
  (void)set_priority_info_code(B, EVINFOENTRY_VERSION_FAILS);
  schedule_if_unscheduled(CONNECTION_CLEAR_TIME, clear_last_connection(B), NULL);    //Don't tell the next station about this one's failures
  InitializeLINvariables(B);
  l_bool_wr_LI1_EvAwake(0);   //request sleep
  return 0;
}

#define version_timeout(x) ((x) ? version_timeoutB : version_timeoutA)

uint32_t init_timeoutA(void * a)  {
  EvStatusInit[A] = Error2bit;
  (void)set_priority_info_code(A, EVINFOENTRY_INITIALIZATION_FAILS);
  schedule_if_unscheduled(CONNECTION_CLEAR_TIME, clear_last_connection(A), NULL);    //Don't tell the next station about this one's failures
  InitializeLINvariables(A);
  l_bool_wr_LI0_EvAwake(0);   //request sleep
  return 0;
}

uint32_t init_timeoutB(void * a)  {
  EvStatusInit[B] = Error2bit;
  (void)set_priority_info_code(B, EVINFOENTRY_INITIALIZATION_FAILS);
  schedule_if_unscheduled(CONNECTION_CLEAR_TIME, clear_last_connection(B), NULL);    //Don't tell the next station about this one's failures
  InitializeLINvariables(B);
  l_bool_wr_LI1_EvAwake(0);   //request sleep
  return 0;
}

#pragma MESSAGE WARNING C2705 
#pragma MESSAGE WARNING C4002

#define init_timeout(x) ((x) ? init_timeoutB : init_timeoutA)

//static l_u8 SeSupportedVersion[2][5]; // SeVersionPageNumber;
static l_u8 SeSelectedVersion[2];                         // There are SE selected Version signals in Frames: 0, 2, 5, 6, 7, 9, 11.

void InitializeLINvariables(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  //PrintConsoleString("\r\n  Inititialized Variables at EV slave  \t",0);  // Debug
  // clang-format off
  SeCommVer[ch] = NotAvail_8bit;                                 // 255 = Not Available
  SeStatusVer[ch] = NotAvail_2bit; SeStatusInit[ch] = NotAvail_2bit; SeStatusOp[ch] = NotAvail_2bit; // 3 = Not Available
  EvStatusVer[ch] = Incomplete; EvStatusInit[ch] = Incomplete; EvStatusOp[ch] = Incomplete;
  EvMaxVoltsLL[ch] = EV_MAX_VOLTAGE_LL; EvMaxVoltsLN[ch] = EV_MAX_VOLTAGE_LN;
  EvMinVoltsLL[ch] = EV_MIN_VOLTAGE_LL; EvMinVoltsLN[ch] = EV_MIN_VOLTAGE_LN;
  EvMaxAmpsL1[ch] = EV_MAX_CURRENT_L; EvMaxAmpsL2[ch] = EV_MAX_CURRENT_L; EvMaxAmpsL3[ch] = EV_MAX_CURRENT_L; EvMaxAmpsN[ch] = EV_MAX_CURRENT_N;
  EvMinAmpsL1[ch] = EV_MIN_CURRENT_L; EvMinAmpsL2[ch] = EV_MIN_CURRENT_L; EvMinAmpsL3[ch] = EV_MIN_CURRENT_L;  // Would an array be more efficient?
  //do we need this anymore?
  // SeAvailableAmpsL1 = 0; SeAvailableAmpsL2 = 0; SeAvailableAmpsL3 = 0;
  //SeAvailableAmpsN =0;
  SeFrequency[ch] = NotAvail_2bit; EvFrequencies[ch] = EV_FREQUENCIES;
  SeMaxAmpsL1[ch] = 0; SeMaxAmpsL2[ch] = 0; SeMaxAmpsL3[ch] = 0; SeMaxAmpsN[ch] = 0;
  EvCommVer[ch] = NotAvail_8bit;
  // 0x0AD2 is  SeNomVoltsLL = 4800; // 277 VAC Line to Neutral, 480 VAC line to line
  //SeNomVoltsLN = 0x08FC; SeNomVoltsLL = 0x0FA0; // 230/400 VAC for testing
  SeNomVoltsLN[ch] = NotAvail_16bit; SeNomVoltsLL[ch] = NotAvail_16bit;
  LINPermitVoltage[ch] = Deny_V; // 0 = Deny_V
  SeNomVoltagesRcvd[ch] = FALSE, SeMaxCurrentsRcvd[ch] = FALSE;
  // clang-format on

  xmit_protocol_version_page(ch);
  LW(ch, l_u8, EvSelectedVersion, NotAvail_8bit);
  LW(ch, l_u16, EvMaxVoltageL1N, EvMaxVoltsLN[ch]);
  LW(ch, l_u16, EvMinVoltageL1N, EvMinVoltsLN[ch]);
  LW(ch, l_u16, EvMaxVoltageLL, SP(EvMaxVoltsLL[ch],NotAvail_16bit));
  LW(ch, l_u16, EvMinVoltageLL, SP(EvMinVoltsLL[ch],NotAvail_16bit));
  LW(ch, l_u8, EvMaxCurrentL1, EvMaxAmpsL1[ch]);
  LW(ch, l_u8, EvMinCurrentL1, EvMinAmpsL1[ch]);
  LW(ch, l_u8, EvMaxCurrentL2, SP(EvMaxAmpsL2[ch],NotAvail_8bit));
  LW(ch, l_u8, EvMinCurrentL2, SP(EvMinAmpsL2[ch],NotAvail_8bit));
  LW(ch, l_u8, EvMaxCurrentL3, SP(EvMaxAmpsL3[ch],NotAvail_8bit));
  LW(ch, l_u8, EvMinCurrentL3, SP(EvMinAmpsL3[ch],NotAvail_8bit));
  LW(ch, l_u8, EvMaxCurrentN, EvMaxAmpsN[ch]);
  LW(ch, l_u8, EvFrequencies, EvFrequencies[ch]);
  LW(ch, l_u8, EvStatusVer, EvStatusVer[ch]);
  LW(ch, l_u8, EvStatusInit, EvStatusInit[ch]);
  LW(ch, l_u8, EvStatusOp, EvStatusOp[ch]);
  LW(ch, l_u8, EvRequestedCurrentL1, NotAvail_8bit);
  LW(ch, l_u8, EvRequestedCurrentL2, SP(NotAvail_8bit,0));
  LW(ch, l_u8, EvRequestedCurrentL3, SP(NotAvail_8bit,0));
  LW(ch, l_u8, EvRequestedCurrentN, NotAvail_8bit);
#pragma MESSAGE DISABLE C4002 //result not used -- ternary operator should not be used for assignements
  l_bool_wr_LI0_EvAwake(1);
  LW(ch, l_bool, EvGridCodeStatusMod, TRUE);
  LW(ch, l_u16, EvGridCodeStatus, 0x7FFF);
  LW(ch, l_u8, EvInverterState, SLEEPSTATE_ON);
  LW(ch, l_u8, EvPwrCtrlModeAck, 0xFF);
  LW(ch, l_u16, EvPwrCtrlModesAvail, 0x0000);
  LW(ch, l_u16, EvPwrCtrlUnitsAvail, PCUNIT_BITMASK(PCUNITS_TOT_WATT) | PCUNIT_BITMASK(PCUNITS_TOT_WATT_VAR));

  
  /* for (i = 0; i < 5; i++) // Compiler says this is never used
  { SeSupportedVersion[i] == 255;
  } */

  ids_init(ch);
  j3072_init(ch);
}
#pragma MESSAGE WARNING C4002

void __op_timeout(uint8_t ch)  {
  SeAvailAmps[ch].pwm   = 0;
  SeAvailAmps[ch].C1_L1 = 0;
  SeAvailAmps[ch].C2_L2 = 0;
  SeAvailAmps[ch].C3_L3 = 0;
  SeAvailAmps[ch].C4_N  = 0;
  EvStatusOp[ch] = Error2bit;
  LW(ch, l_u8, EvStatusOp, EvStatusOp[ch]);
  DetermineEvState(ch, BSC_TIMEOUT); // Also need to clear variables to request to get back to Ver
  schedule_if_unscheduled(CONNECTION_CLEAR_TIME, clear_last_connection(ch), NULL);    //Don't tell the next station about this one's failures
  InitializeLINvariables(ch);
  (void)set_priority_info_code(ch, EVINFOENTRY_NO_LIN);
  //PrintConsoleString("\r\n  LIN Timeout in Op schedule \t",0);
}

uint32_t op_timeoutA(void * a)  {
  __op_timeout(A);
  return 0;
}

uint32_t op_timeoutB(void * a)  {
  __op_timeout(A);
  return 0;
}

#define op_timeout(x) ((x) ? op_timeoutB : op_timeoutA)

void verify_comm_ver(uint8_t ch, uint8_t received_ver, bool op)  {
  if (SeCommVer[ch] != received_ver)  {
      if(SeCommVer[ch] == NotAvail_8bit)  {   //restart requested
        DetermineEvState(ch, BSC_TIMEOUT);    //not exactly a timeout, but does what we want
        InitializeLINvariables(ch);
      } else{ //version changed
        (void)set_priority_info_code(ch, EVINFOENTRY_VERSION_RESTART);    //there isn't a perfect code to represent this
        if(op)  {
          EvStatusOp[ch] = Error2bit;
          LW(ch, l_u8, EvStatusOp, EvStatusOp[ch]);
          LW(ch, l_u8, EvSelectedVersion, NotAvail_8bit);
        } else{
          EvStatusInit[ch] = Error2bit;
          LW(ch, l_u8, EvStatusInit, EvStatusInit[ch]);
          LW(ch, l_u8, EvSelectedVersion, NotAvail_8bit);
        }
      }
    }
}

void InitChecks(uint8_t ch) {
  bool initComplete = TRUE;    //Assume all checks pass and set to false if one fails

  if (!((SeNomVoltsLN[ch] == NotAvail_16bit) || (EvMaxVoltsLN[ch] == NotAvail_16bit))) {        // Only do the check if neither value is not available
    if(!((EvMaxVoltsLN[ch] <= MaxValidVoltage) && (SeNomVoltsLN[ch] <= EvMaxVoltsLN[ch]))) {    // Only need to check if the larger value is valid
      (void)set_priority_info_code(ch, EVINFOENTRY_AVAILABLE_VOLTAGE_TOO_HIGH);
      initComplete = FALSE;
    }
  }
  if (!((SeNomVoltsLN[ch] == NotAvail_16bit) || (EvMinVoltsLN[ch] == NotAvail_16bit))) {        // Only do the check if neither value is not available
    if(!((SeNomVoltsLN[ch] <= MaxValidVoltage) && (SeNomVoltsLN[ch] >= EvMinVoltsLN[ch]))) {    // Only need to check if the larger value is valid
      (void)set_priority_info_code(ch, EVINFOENTRY_AVAILABLE_VOLTAGE_TOO_LOW);
      initComplete = FALSE;
    }
  }
  if (!((SeNomVoltsLL[ch] == NotAvail_16bit) || (EvMaxVoltsLL[ch] == NotAvail_16bit))) {        // Only do the check if neither value is not available
    if(!((EvMaxVoltsLL[ch] <= MaxValidVoltage) && (SeNomVoltsLL[ch] <= EvMaxVoltsLL[ch]))) {    // Only need to check if the larger value is valid
      (void)set_priority_info_code(ch, EVINFOENTRY_AVAILABLE_VOLTAGE_TOO_HIGH);
      initComplete = FALSE;
    }
  }
  if (!((SeNomVoltsLL[ch] == NotAvail_16bit) || (EvMinVoltsLL[ch] == NotAvail_16bit))) {        // Only do the check if neither value is not available
    if(!((SeNomVoltsLL[ch] <= MaxValidVoltage) && (SeNomVoltsLL[ch] >= EvMinVoltsLL[ch]))) {    // Only need to check if the larger value is valid
      (void)set_priority_info_code(ch, EVINFOENTRY_AVAILABLE_VOLTAGE_TOO_LOW);
      initComplete = FALSE;
    }
  }

#define LINE_CURRENT_CHECK(l) \
  if (!((SeMaxAmps##l [ch] == NotAvail_8bit) || (EvMinAmps##l [ch] == NotAvail_8bit))) {        /*Only do the check if neither value is not available*/\
    if (!((SeMaxAmps##l [ch] < MaxValidCurrent) && (SeMaxAmps##l [ch] >= EvMinAmps##l [ch]))) { /*Only need to check if the larger value is valid*/\
      (void)set_priority_info_code(ch, EVINFOENTRY_AVAILABLE_CURRENT_TOO_LOW);                  \
      initComplete = FALSE;                                                                     \
    }                                                                                           \
  }
  LINE_CURRENT_CHECK(L1);
  LINE_CURRENT_CHECK(L2);
  LINE_CURRENT_CHECK(L3);

  // Bitwise and to check if whatever bit is set in SeFrequency is also set in EvFrequency.  Also check that both values are valid
  if ((SeFrequency[ch] == NotAvail_8bit) || ( EvFrequencies[ch]== NotAvail_8bit) || !(SeFrequency[ch] & EvFrequencies[ch]))  {
    (void)set_priority_info_code(ch, EVINFOENTRY_FREQUENCY_MISMATCH);
    initComplete = FALSE;
  }

  if (initComplete) {
    if ((SeMaxAmpsL2[ch] == 0) && (SeMaxAmpsL2[ch] == 0)) {     //single-phase SE detected
      is_single_phase = TRUE;
    }
  
    unschedule(init_timeout(ch));
    EvStatusInit[ch] = Complete;
    LW(ch, l_u8, EvStatusInit, EvStatusInit[ch]);
  }
}

void DetermineLINCPState(uint8_t ch, SCHEDULE_PICKER_EVENTS SchedulePickerMessage) {
#pragma MESSAGE DISABLE C2705
  uint8_t chosen_pver = NotAvail_8bit;

  if (LFT(ch, SeVersionList)) {
    //LFC(ch, SeVersionList);
    unschedule(clear_last_connection(ch));
    schedule_if_unscheduled(T_VER, version_timeout(ch), NULL);
    SeStatusVer[ch]           = LR(ch, l_u8, SeStatusVer_SeVersionList);
    SeStatusInit[ch]          = LR(ch, l_u8, SeStatusInit_SeVersionList);
    SeStatusOp[ch]            = LR(ch, l_u8, SeStatusOp_SeVersionList);
    SeCommVer[ch]             = LR(ch, l_u8, SeSelectedVersion_SeVersionList);

    if ((SeStatusVer[ch] == Incomplete || EvCommVer[ch] != NotAvail_8bit) && SeStatusInit[ch] == Incomplete && SeStatusOp[ch] == Deny_V) {
      chosen_pver = rcv_protocol_version_page(ch);
      if (chosen_pver != NotAvail_8bit) {                 // we need to keep the chosen value in EvCommVer in case it takes the SE into the next paging cycle to reply
        EvCommVer[ch] = chosen_pver;
        LW(ch, l_u8, EvSelectedVersion, EvCommVer[ch]);
      }

      if ((EvCommVer[ch] != NotAvail_8bit) && (SeCommVer[ch] == EvCommVer[ch])) {
        EvStatusVer[ch] = Complete;
        schedule_if_unscheduled(T_INIT, init_timeout(ch), NULL);
        LW(ch, l_u8, EvConnectionType, EV_CONNTP);  //Edition 3 of 3068 defines connection type in protocol version 2
        DetermineEvState(ch, BSC_ESTABLISHED);
        PrintConsoleString("Version Negotiation successful.  Chose Version: ", 0); // Debug
        PrintConsoleHex(EvCommVer[ch]);
        PrintConsoleString("\r\n", 0);
        unschedule(version_timeout(ch));
        clear_all_info_codes(ch);  //clear anything that might be left over from previous connection
      }
    } else  {
      PrintConsoleString("Incorrect SE Status, V:" ,0);
      PrintConsoleHex(SeStatusVer[ch]);
      PrintConsoleString(" I:",0);
      PrintConsoleHex(SeStatusInit[ch]);
      PrintConsoleString(" O:",0);
      PrintConsoleHex(SeStatusOp[ch]);
      PrintConsoleString("\r\n",0);
      EvStatusVer[ch] = Error2bit;
      (void)set_priority_info_code(ch, EVINFOENTRY_VERSION_FAILS);    
    }

    LW(ch, l_u8, EvStatusVer, EvStatusVer[ch]);
  }

  if (LFT(ch, EvVersionList)) {
    xmit_protocol_version_page(ch);
  }

  if (LFT(ch, SeNomVoltages)) // This handles the Init schedule but is NOT FINISHED FIXME
  {
    LFC(ch, SeNomVoltages);
    SeNomVoltsLN[ch]      = LR(ch, l_u16, SeNomVoltageL1N);
    SeNomVoltsLL[ch]      = LR(ch, l_u16, SeNomVoltageLL);
    SeFrequency[ch]       = LR(ch, l_u8, SeFrequency);
    SeSelectedVersion[ch] = LR(ch, l_u8, SeSelectedVersion_SeNomVoltages);
    SeNomVoltagesRcvd[ch] = TRUE;
  }
  if (LFT(ch, SeMaxCurrents)) {
    LFC(ch, SeMaxCurrents);
    SeMaxAmpsL1[ch]       = LR(ch, l_u8, SeMaxCurrentL1);
    SeMaxAmpsL2[ch]       = LR(ch, l_u8, SeMaxCurrentL2);
    SeMaxAmpsL3[ch]       = LR(ch, l_u8, SeMaxCurrentL3);
    SeMaxAmpsN[ch]        = LR(ch, l_u8, SeMaxCurrentN);
    SeSelectedVersion[ch] = LR(ch, l_u8, SeSelectedVersion_SeMaxCurrents);
    SeMaxCurrentsRcvd[ch] = TRUE;
  }
  if (LFT(ch, EvInfoList)) {
    xmit_info_code_page(ch);
  }
  if (LFT(ch, SeInfoList)) {
    rcv_info_code_page(ch);
  }

  if (LFT(ch, EvID)) {
    on_id_frame_xmit(ch);
    LFC(ch, EvID);
  }
  if (LFT(ch, SeID)) {
    on_id_frame_receipt(ch);
    LFC(ch, SeID);
  }

  if (LFT(ch, EvJ3072)) {
    on_j3072_frame_xmit(ch);
    LFC(ch, EvJ3072);
  }
  if (LFT(ch, SeJ3072)) {
    on_j3072_frame_receipt(ch);
    LFC(ch, SeJ3072);
  }

  if (ev_id_status[ch] == DATA && ev_j3072_status[ch] == SUNSPEC) {   //all ID and certification data has been transmitted and received
    LW(ch, l_u16, EvPwrCtrlModesAvail, PCMODES_BITMASK(PCMODES_TGC) | PCMODES_BITMASK(PCMODES_TGC_R));
  }

  if ((SeNomVoltagesRcvd[ch] && SeMaxCurrentsRcvd[ch]) && ((SeNomVoltsLN[ch] != NotAvail_16bit) || (SeNomVoltsLL[ch] != NotAvail_16bit)))  {  // Perform initialization checks only after all information has been read to prevent unread data from bypassing checks R#:9.6.3.1
    InitChecks(ch);
    // Clear any Restart info codes
    (void)clear_info_code(ch, EVINFOENTRY_NO_LIN);
    (void)clear_info_code(ch, EVINFOENTRY_VERSION_RESTART);
    //(void)clear_info_code(ch, EVINFOENTRY_BIT_RATE_RESTART);   //Skip this as we don't support different bit rates
    (void)clear_info_code(ch, EVINFOENTRY_MCU_RESET_RESTART);
    (void)clear_info_code(ch, EVINFOENTRY_PILOT_FAULT_RESTART);
    (void)clear_info_code(ch, EVINFOENTRY_INT_FAULT_RESTART);
    SeNomVoltagesRcvd[ch] = FALSE; SeMaxCurrentsRcvd[ch] = FALSE; // Clear read flags so the checks don't keep happening once in Op
  }
  if (LFT(ch, SeStatus)) // Check for LIN communication timeout, after 2 seconds should open S2
  {
    LFC(ch, SeStatus);
    SeStatusVer[ch]        = LR(ch, l_u8, SeStatusVer_SeStatus);
    SeStatusInit[ch]       = LR(ch, l_u8, SeStatusInit_SeStatus);
    SeStatusOp[ch]         = LR(ch, l_u8, SeStatusOp_SeStatus);

    verify_comm_ver(ch, LR(ch, l_u8, SeSelectedVersion_SeStatus), (SeStatusInit[ch] == Complete) && (EvStatusInit[ch] == Complete));

    //Make sure all currents are 0 if charging is disallowed.  This is probably redundant but there is no harm in being sure.
    if((SeStatusOp[ch] == Permit_V) && (EvStatusOp[ch] == Permit_V))  {
      SeAvailAmps[ch].C1_L1 = LR(ch, l_u8, SeAvailableCurrentL1);
      SeAvailAmps[ch].C2_L2 = LR(ch, l_u8, SeAvailableCurrentL2);
      SeAvailAmps[ch].C3_L3 = LR(ch, l_u8, SeAvailableCurrentL3);
      SeAvailAmps[ch].C4_N  = LR(ch, l_u8, SeAvailableCurrentN);

      //Do not allow available current to exceed maximum current as defined in Init.
      if (SeMaxAmpsL1[ch] < SeAvailAmps[ch].C1_L1) SeAvailAmps[ch].C1_L1 = SeMaxAmpsL1[ch];
      if (SeMaxAmpsL2[ch] < SeAvailAmps[ch].C2_L2) SeAvailAmps[ch].C2_L2 = SeMaxAmpsL2[ch];
      if (SeMaxAmpsL3[ch] < SeAvailAmps[ch].C3_L3) SeAvailAmps[ch].C3_L3 = SeMaxAmpsL3[ch];
      if (SeMaxAmpsN[ch]  < SeAvailAmps[ch].C4_N)  SeAvailAmps[ch].C4_N  = SeMaxAmpsN[ch];

      //Set PWM current to the lowest of the contact currents.  
      SeAvailAmps[ch].pwm = SeAvailAmps[ch].C1_L1;
      if (SeAvailAmps[ch].C2_L2 < SeAvailAmps[ch].pwm) SeAvailAmps[ch].pwm = SeAvailAmps[ch].C2_L2;
      if (SeAvailAmps[ch].C3_L3 < SeAvailAmps[ch].pwm) SeAvailAmps[ch].pwm = SeAvailAmps[ch].C3_L3;
      if (SeAvailAmps[ch].C4_N < SeAvailAmps[ch].pwm) SeAvailAmps[ch].pwm = SeAvailAmps[ch].C4_N;
    } else  {
      SeAvailAmps[ch].pwm   = 0;
      SeAvailAmps[ch].C1_L1 = 0;
      SeAvailAmps[ch].C2_L2 = 0;
      SeAvailAmps[ch].C3_L3 = 0;
      SeAvailAmps[ch].C4_N  = 0;
    }

    if ((SeStatusInit[ch] == Complete) && (EvStatusInit[ch] == Complete)) { //schedule is op
      schedule_and_reset(T_NOLIN, op_timeout(ch), NULL);
    }

  }
  if ((EvStatusInit[ch] == Complete) && (SeStatusInit[ch] == Complete) ) {
    EvStatusOp[ch] = Permit_V;
    LW(ch, l_u8, EvStatusOp, EvStatusOp[ch]);
  }
#pragma MESSAGE DISABLE C12056 //debug info incorrect because of optimization or inline assembler
}

/**********************************************************
************************EV_CONFIG>*************************
***********************************************************/

#else //SE_CONFIG

/**********************************************************
************************<SE_CONFIG*************************
***********************************************************/

uint32_t version_timeoutA(void * a)  {
  SeStatusVer[A] = Error2bit;
  PrintConsoleString("Ver timeout ch A\r\n",0);
  (void)set_priority_info_code(A, SEINFOENTRY_VERSION_FAILS);
  //Allow the EV to decide to stop communication
  return 0;
}

uint32_t version_timeoutB(void * a)  {
  SeStatusVer[B] = Error2bit;
  PrintConsoleString("Ver timeout ch B\r\n",0);
  (void)set_priority_info_code(B, SEINFOENTRY_VERSION_FAILS);
  //Allow the EV to decide to stop communication
  return 0;
}

#define version_timeout(x) ((x) ? version_timeoutB : version_timeoutA)

uint32_t init_timeoutA(void * a)  {
  SeStatusInit[A] = Error2bit;
  PrintConsoleString("Init timeout ch A\r\n",0);
  (void)set_priority_info_code(A, SEINFOENTRY_INITIALIZATION_FAILS);
  //Allow the EV to decide to stop communication
  return 0;
}

uint32_t init_timeoutB(void * a)  {
  SeStatusInit[B] = Error2bit;
  PrintConsoleString("Init timeout ch B\r\n",0);
  (void)set_priority_info_code(B, SEINFOENTRY_INITIALIZATION_FAILS);
  //Allow the EV to decide to stop communication
  return 0;
}

#define init_timeout(x) ((x) ? init_timeoutB : init_timeoutA)

void __op_timeout(uint8_t ch)  {
  LW(ch, l_u8, SeAvailableCurrentL1, 0);
  LW(ch, l_u8, SeAvailableCurrentL2, SP(0, NotAvail_8bit));
  LW(ch, l_u8, SeAvailableCurrentL3, SP(0, NotAvail_8bit));
  LW(ch, l_u8, SeAvailableCurrentN, 0);

  (void)set_priority_info_code(ch, SEINFOENTRY_NO_LIN);
  lin_Restart[ch] = TRUE;         // Set the comm fault code in Ver after the restart

  LINPermitVoltage[ch] = Deny_V; // Requirement R#:10.7.2.1
  SchedulePicker[ch] = StartVer; // Restart
}

uint32_t op_timeoutA(void * a)  {
  __op_timeout(A);
  return 0;
}

uint32_t op_timeoutB(void * a)  {
  __op_timeout(A);
  return 0;
}

#define op_timeout(x) ((x) ? op_timeoutB : op_timeoutA)

void InitializeLINvariables(uint8_t ch) {
  // clang-format off
  SeCommVer[ch] = NotAvail_8bit; EvCommVer[ch] = NotAvail_8bit;      // 255 = Not Available
  SeStatusVer[ch] = Incomplete; SeStatusInit[ch] = Incomplete; SeStatusOp[ch] =Incomplete; // 3 = Not Available
  EvStatusVer[ch] = NotAvail_2bit; EvStatusInit[ch] = NotAvail_2bit; EvStatusOp[ch] = NotAvail_2bit;
  EvMaxVoltsLL[ch] = 0; EvMaxVoltsLN[ch] = 0;
  EvMinVoltsLL[ch] = NotAvail_16bit; EvMinVoltsLN[ch] = NotAvail_16bit;
  EvMaxAmpsL1[ch] = 0; EvMaxAmpsL2[ch] = 0; EvMaxAmpsL3[ch] = 0; EvMaxAmpsN[ch] = 0;
  EvMinAmpsL1[ch] = NotAvail_8bit; EvMinAmpsL2[ch] = NotAvail_8bit; EvMinAmpsL3[ch] = NotAvail_8bit;
  SeFrequency[ch] = SE_FREQUENCY;
  SeMaxAmpsL1[ch] = SE_MAX_CURRENT_L; SeMaxAmpsL2[ch] = SP(SE_MAX_CURRENT_L,0); SeMaxAmpsL3[ch] = SP(SE_MAX_CURRENT_L,0); SeMaxAmpsN[ch] = SE_MAX_CURRENT_N;
  EvSelectedVer[ch] = NotAvail_8bit;
  // clang-format on
  SeNomVoltsLN[ch]       = SE_NOMINAL_VOLTAGE_LN;
  SeNomVoltsLL[ch]       = SE_NOMINAL_VOLTAGE_LL;
  LINPermitVoltage[ch]   = Deny_V; // 0 = contactors open.  Related to SeStatusOp but SeStatusOp is inconsistent between J3068 and Annex D.
  SchedulePicker[ch]     = StartNull;
  pvers_rcvd[ch]         = FALSE;

  LW(ch, l_u16, SeGridCodeRequest, 0x7FFF);
  LW(ch, l_u8, SeInverterRequest, 0xF);
  LW(ch, l_u8, SePwrCtrlMode, PCMODES_NORM_CHRG);
  LW(ch, l_u8, SePwrCtrlUnits, 0xF);
  LW(ch, l_u8, SePwrCtrlAuth, PCAUTH_NONE);
  LW(ch, l_u8, SeTimeStamp, 0xFF);

  ids_init(ch);
  j3072_init(ch);

  //testing info codes {
  //set_info_code(ch, SEINFOENTRY_PILOT_FAULT);
  //set_info_code(ch, SEINFOENTRY_CONTACTOR_FAULT);
  //set_info_code(ch, SEINFOENTRY_INPUT_MISWIRED);

  //print_all_info_codes(ch);
  //}
}

//only checks primary head for now

void LINUpdateEvState(uint8_t ch) {
  /*
  ev_state.e_cap =  LR(ch,l_u16,EvEnergyFull);
  ev_state.soc   =  (uint8_t)LR(ch,l_u16,EvEndCountDownTime2);

  ev_state.voltage_x10  =  LR(ch,l_u16,EvStartCountDownTime2);
  ev_state.i_line_x10   =  LR(ch,l_u16,EvPowerRequest1);
  if (ev_state.i_line_x10 & 0x0800) ev_state.i_line_x10 |= 0xF000;

  ev_state.i_up_x10     =  LR(ch,l_u16,EvPowerRequest2);
  ev_state.i_down_x10   =  LR(ch,l_u16,EvPowerRequest3);
  ev_state.current_mode =  LR(ch,l_u16,EvStartCountDownTime1);

  ev_state.oem1 = LR(ch,l_u16,EvStartTimeCountDown1_EvMin);
  ev_state.oem2 = LR(ch,l_u16,EvEndTimeCountDown1_EvMin);
  ev_state.oem3 = LR(ch,l_u16,EvStartTimeCountDown2_EvMin);
  ev_state.oem4 = LR(ch,l_u16,EvEndTimeCountDown2_EvMin);

  ev_state.v12_batt = (uint8_t)LR(ch,l_u16,EvStartTimeCountDown3_EvMin);

  LW(ch,l_u16,StMaxPowerOffer1,ev_state.requested_amps);
  LW(ch,l_u16,StStartTimeCountDown1,ev_state.desired_mode);
  */

  //LINUpdateSeInfoFrame(ch); //update info list    --Removed; Needs to be rewritten
}

void WriteSeStatus(uint8_t ch) // Use in more places?
{
#pragma MESSAGE DISABLE C2705
  LW(ch, l_u8, SeStatusVer, SeStatusVer[ch]);
  LW(ch, l_u8, SeStatusInit, SeStatusInit[ch]);
  LW(ch, l_u8, SeStatusOp, SeStatusOp[ch]);
}

void StartScheduleNull(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LSS(ch, LIN_NULL_SCHEDULE, 0); // Start the NULL schedule
}

void StartScheduleVer(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LW(ch, l_u8, SeSelectedVersion, NotAvail_8bit); // Initialize LIN signals
  xmit_protocol_version_page(ch);
  LW(ch, l_u8, SeFrequency, SeFrequency[ch]);
  WriteSeStatus(ch);
  LSS(ch, Ver, 0);          // Start the Ver schedule
}
void StartScheduleInit(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LW(ch, l_u8, SeMaxCurrentL1, SeMaxAmpsL1[ch]);
  LW(ch, l_u8, SeMaxCurrentL2, SeMaxAmpsL2[ch]);
  LW(ch, l_u8, SeMaxCurrentL3, SeMaxAmpsL3[ch]);
  LW(ch, l_u8, SeMaxCurrentN, SeMaxAmpsN[ch]);

  LW(ch, l_u16, SeNomVoltageL1N, SeNomVoltsLN[ch]);
  LW(ch, l_u16, SeNomVoltageLL, SP(SeNomVoltsLL[ch],NotAvail_16bit));
  LW(ch, l_u8, SeAvailableCurrentL1, evse_state[ch].set_c.C1_L1);
  LW(ch, l_u8, SeAvailableCurrentL2, SP(evse_state[ch].set_c.C2_L2, NotAvail_8bit));
  LW(ch, l_u8, SeAvailableCurrentL3, SP(evse_state[ch].set_c.C3_L3, NotAvail_8bit));
  LW(ch, l_u8, SeAvailableCurrentN, evse_state[ch].set_c.C4_N);
  EvMinVoltsFrame[ch] = NotReceived, EvCurrentsFrame[ch] = NotReceived, EvStatusFrame[ch] = NotReceived;
  EvMaxVoltsFrame[ch] = NotReceived;

  LW(ch, l_u8, SeConnectionType, SE_CONNTP);  //Edition 3 of 3068 defines connection type in protocol version 2

  LSS(ch, Init, 0); // Start the Init schedule
}
void StartScheduleOp(uint8_t ch) {
  switch(EvCommVer[ch]) {
    case PVER_BASE:
      LSS(ch, Op, 0); // Start the J3068/null Op schedule
      break;
    case PVER_SLASH_1:
      LSS(ch, Op3, 0); // Start the J3068/1 Op schedule
      break;
    case PVER_SLASH_2:
      LSS(ch, Op252, 0);
      break;
  }
}
void StartScheduleSleep(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LSS(ch, GOTO_SLEEP_SCHEDULE, 0);
}
void WriteSeVersion(uint8_t ch) {
  LW(ch, l_u8, SeSelectedVersion, SeCommVer[ch]);
}
void ReadEvVersionListSignals(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LFC(ch, EvVersionList); // Clear the flag once an EvVersionList frame is received.
  EvStatusVer[ch]  = LR(ch, l_u8, EvStatusVer_EvVersionList);
  EvStatusInit[ch] = LR(ch, l_u8, EvStatusInit_EvVersionList);
  EvStatusOp[ch]   = LR(ch, l_u8, EvStatusOp_EvVersionList);
  EvCommVer[ch]    = LR(ch, l_u8, EvSelectedVersion_EvVersionList);
}
void ReadEvMaxVoltsAndFreq(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LFC(ch, EvMaxVoltages);
  EvMaxVoltsLL[ch]  = LR(ch, l_u16, EvMaxVoltageLL);
  EvMaxVoltsLN[ch]  = LR(ch, l_u16, EvMaxVoltageL1N);
  EvFrequencies[ch] = LR(ch, l_u8, EvFrequencies);
  EvSelectedVer[ch] = LR(ch, l_u8, EvSelectedVersion_EvMaxVoltages);
}
void ReadEvMinVolts(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LFC(ch, EvMinVoltages);
  EvMinVoltsLL[ch]  = LR(ch, l_u16, EvMinVoltageLL);
  EvMinVoltsLN[ch]  = LR(ch, l_u16, EvMinVoltageL1N);
  EvSelectedVer[ch] = LR(ch, l_u8, EvSelectedVersion_EvMinVoltages);
}
void ReadEvCurrentRatings(uint8_t ch) {
#pragma MESSAGE DISABLE C2705

  LFC(ch, EvMaxMinCurrents);
  EvMaxAmpsL1[ch]   = LR(ch, l_u8, EvMaxCurrentL1);
  EvMaxAmpsL2[ch]   = LR(ch, l_u8, EvMaxCurrentL2);
  EvMaxAmpsL3[ch]   = LR(ch, l_u8, EvMaxCurrentL3);
  EvMaxAmpsN[ch]    = LR(ch, l_u8, EvMaxCurrentN);
  EvMinAmpsL1[ch]   = LR(ch, l_u8, EvMinCurrentL1);
  EvMinAmpsL2[ch]   = LR(ch, l_u8, EvMinCurrentL2);
  EvMinAmpsL3[ch]   = LR(ch, l_u8, EvMinCurrentL3);
  EvSelectedVer[ch] = LR(ch, l_u8, EvSelectedVersion_EvMaxMinCurrents);
}
void ReadEvStatus(uint8_t ch) {
#pragma MESSAGE DISABLE C2705
  LFC(ch, EvStatus);                                            // Don't forget to clear the flag or things go squirrely
  EvSelectedVer[ch] = LR(ch, l_u8, EvSelectedVersion_EvStatus); // There should be 4 identical signals in different frames, check all
  EvStatusVer[ch]   = LR(ch, l_u8, EvStatusVer_EvStatus);
  EvStatusInit[ch]  = LR(ch, l_u8, EvStatusInit_EvStatus);
  EvStatusOp[ch]    = LR(ch, l_u8, EvStatusOp_EvStatus);
  EvStatusFrame[ch] = Received; // No other frames use "Received" value, they use "Compatible" or "Incompatible" instead
}

void DetermineLINCPState(uint8_t ch, SCHEDULE_PICKER_EVENTS SchedulePickerMessage) {
  //PrintConsoleHex(SchedulePicker);
  //PrintConsoleString("$\r\n",0);
  if (SchedulePickerMessage == startLIN) {
    SchedulePicker[ch] = StartVer;
    //my_peer.valid_p = 0;
  } else if (SchedulePickerMessage == stopLIN) {
    SchedulePicker[ch] = StartNull; //else if (SchedulePickerMessage == continueLin), no action needed.
    //my_peer.valid_p = 0;
  }
  switch (SchedulePicker[ch]) //done with async messages, continue normal operation
  {
    case StartNull:
      InitializeLINvariables(ch);
      lin_Restart[ch] = FALSE;  //disconnect means this is not a restart
      ver_Restart[ch] = FALSE;
      mcu_Restart[ch] = FALSE;
      pwr_Restart[ch] = FALSE;
      int_Restart[ch] = FALSE;
      StartScheduleNull(ch);
      SchedulePicker[ch] = RunNull;
      break;
    case RunNull: // Do nothing, Rodney's code handles wake up
      break;
    case StartVer:
      schedule_if_unscheduled(T_VER, version_timeout(ch), NULL);
      InitializeLINvariables(ch); // reinit if a restart
      clear_all_info_codes(ch); // Clear any info codes from a previous connection
      if (lin_Restart[ch])  {
        (void)set_priority_info_code(ch, SEINFOENTRY_NO_LIN);
        lin_Restart[ch] = FALSE;
      }
      if (ver_Restart[ch])  {
        (void)set_priority_info_code(ch, SEINFOENTRY_VERSION_RESTART);
        ver_Restart[ch] = FALSE;
      }
      if (mcu_Restart[ch])  {
        (void)set_priority_info_code(ch, SEINFOENTRY_MCU_RESET_RESTART);
        mcu_Restart[ch] = FALSE;
      }
      if (pwr_Restart[ch])  {
        (void)set_priority_info_code(ch, SEINFOENTRY_POWER_FAULT_RESTART);
        pwr_Restart[ch] = FALSE;
      }
      if (int_Restart[ch])  {
        (void)set_priority_info_code(ch, SEINFOENTRY_INT_FAULT_RESTART);
        int_Restart[ch] = FALSE;
      }
      StartScheduleVer(ch);
      SchedulePicker[ch] = RunVer; // Will run next time through this loop
      break;
    case RunVer:                  // Ver schedule running, now service the signals
      if (LFT(ch, EvVersionList)) // If EV is responding, process Version signals, otherwise wait for wakeup
      {
        ReadEvVersionListSignals(ch);
        if (!((EvStatusVer[ch] == Incomplete || EvCommVer[ch] != NotAvail_8bit) && SeStatusInit[ch] == Incomplete && SeStatusOp[ch] == Deny_V)) {
          PrintConsoleString("Incorrect EV Status, V:" ,0);
          PrintConsoleHex(EvStatusVer[ch]);
          PrintConsoleString(" I:",0);
          PrintConsoleHex(EvStatusInit[ch]);
          PrintConsoleString(" O:",0);
          PrintConsoleHex(EvStatusOp[ch]);
          PrintConsoleString("\r\n",0);
          SeStatusVer[ch] = Error2bit;
          (void)set_priority_info_code(ch, SEINFOENTRY_VERSION_FAILS);  
        } else {
          if(!rcv_protocol_version_page(ch)) pvers_rcvd[ch] = TRUE;
          if (pvers_rcvd[ch]) {                      // We have the EV support list
            if (check_pver_supported(EvCommVer[ch])) // EV picked a supported version
            {
              SeCommVer[ch] = EvCommVer[ch]; // SE accepts EV's choice
              //LW(ch,l_u8,SeInfoEntry1,NotAvail_8bit); // Clear any info code that might have been set previously
              //LW(ch,l_u8,SeInfoEntry2,NotAvail_8bit);
              SeStatusVer[ch] = Complete;
              if (EvStatusVer[ch] == Complete) {
                SchedulePicker[ch] = StartInit; // Signal transition to Init schedule, which happens next time through this loop
                // DetermineEvseStateA(BSC_ESTABLISHED); // Tells the supervior system that LIN Baseband Communication has been established (it does not determine whether it has, we just did that so it is misnamed)
              }
            } else // EvCommVer must be either NotAvailable, Error, or invalid version
            {
              SeCommVer[ch]   = NotAvail_8bit;
              SeStatusVer[ch] = Incomplete;                                                                        // Assumption to be refined below
              if ((EvCommVer[ch] != NotAvail_8bit && EvCommVer[ch] != Error8bit) || (EvStatusVer[ch] == Complete)) // An invalid version was chosen  OR  EV signaled complete too soon
              {
                SeStatusVer[ch] = Error2bit;
                (void)set_priority_info_code(ch, SEINFOENTRY_VERSION_FAILS);
              } else // EvCommVer = NotAvailable or Error
              {
                (void)clear_info_code(ch, SEINFOENTRY_VERSION_FAILS);
              }
            }
          }
        }
        WriteSeVersion(ch);
        WriteSeStatus(ch);
      }             // End of "if LFT(ch,EvVersionList)"   IE end of processing Version schedule signals
      break;        // End of case RunVer
    case StartInit: // Triggers change to Initialization schedule
      unschedule(version_timeout(ch));
      schedule_if_unscheduled(T_INIT, init_timeout(ch), NULL);
      StartScheduleInit(ch);
      SchedulePicker[ch] = RunInit;
      DetermineEvseState(ch, BSC_ESTABLISHED); // This should move up to Ver right before it exits
      //Clear any Restart fault codes once we reach Init.  Not all of these can be set with the current code
      (void)clear_info_code(ch, SEINFOENTRY_NO_LIN);
      (void)clear_info_code(ch, SEINFOENTRY_VERSION_RESTART);
      //(void)clear_info_code(ch, SEINFOENTRY_BIT_RATE_RESTART);    //Skip this as we don't support different bit rates
      (void)clear_info_code(ch, SEINFOENTRY_MCU_RESET_RESTART);
      (void)clear_info_code(ch, SEINFOENTRY_POWER_FAULT_RESTART);
      (void)clear_info_code(ch, SEINFOENTRY_INT_FAULT_RESTART);
      break;
    case RunInit:
      //This will cause resets if STATE_E is detected during dominate transmit
      /*if ((PilotA_Voltage != STATE_B) && (PilotA_Voltage != STATE_C))
        { SchedulePicker = StartVer;         // Used to be StartNull before merge with Rodney's code
        }  */
      if (LFT(ch, EvStatus)) // Check for EV reboot and check for premature "Complete" from EV
      {
        ReadEvStatus(ch);
        if ((SeCommVer[ch] != EvSelectedVer[ch]) || (EvStatusVer[ch] != Complete)) {
          SchedulePicker[ch] = StartVer; // Restart if any EvSelectedVersion signal that has arrived has changed: add EvVer 12? Not required to read it otherwise...
        }
        if ((EvStatusInit[ch] == Complete) && (SeStatusInit[ch] == Error2bit)) {
          (void)set_priority_info_code(ch, SEINFOENTRY_INITIALIZATION_FAILS);
        } else {
          (void)clear_info_code(ch, SEINFOENTRY_INITIALIZATION_FAILS); // Clear Se Info Code, this does not clear if it is the last error to clear, that is done below
        }
      }
      if (LFT(ch, EvMaxVoltages)) {
        ReadEvMaxVoltsAndFreq(ch);
        EvMaxVoltsFrame[ch] = Compatible; //  Starting assumption to be changed below if needed
        if (!( ((EvMaxVoltsLL[ch] == NotAvail_16bit) || (SeNomVoltsLL[ch] == NotAvail_16bit) || (EvMaxVoltsLL[ch] >= SeNomVoltsLL[ch])) && 
               ((EvMaxVoltsLN[ch] == NotAvail_16bit) || (SeNomVoltsLN[ch] == NotAvail_16bit) || (EvMaxVoltsLN[ch] >= SeNomVoltsLN[ch])) )) {
          EvMaxVoltsFrame[ch] = Incompatible;                                       // Voltage too high
          (void)set_priority_info_code(ch, SEINFOENTRY_AVAILABLE_VOLTAGE_TOO_HIGH); // Info code meaning Supply Voltage Too High for EV
        } else if ((EvMaxVoltsLL[ch] > MaxValidVoltage) && (EvMaxVoltsLN[ch] > MaxValidVoltage))        // Both signals are invalid (greater than 1000.0 V)
        {
          EvMaxVoltsFrame[ch] = Incompatible;
          //No appropriate code
        } else {
          (void)clear_info_code(ch, SEINFOENTRY_AVAILABLE_VOLTAGE_TOO_HIGH);
        }
        if (!((EvFrequencies[ch] == SeFrequency[ch]) || (EvFrequencies[ch] == FiftyOrSixtyHz))) {
          EvMaxVoltsFrame[ch] = Incompatible;                               // Will this get fooled if both EvFrequenices and SeFrequency = 0xFF?  Might need another check.
          (void)set_priority_info_code(ch, SEINFOENTRY_FREQUENCY_MISMATCH); // Info code meaning Power Frequency Not Supported by EV
        } else {
          (void)clear_info_code(ch, SEINFOENTRY_FREQUENCY_MISMATCH); // Clear the info code
        }
      }
      if (LFT(ch, EvMaxMinCurrents)) {
        ReadEvCurrentRatings(ch);
        if (((EvMinAmpsL1[ch] != NotAvail_8bit) && (EvMinAmpsL1[ch] > SeMaxAmpsL1[ch])) || 
            ((EvMinAmpsL2[ch] != NotAvail_8bit) && (EvMinAmpsL2[ch] > SeMaxAmpsL2[ch])) || 
            ((EvMinAmpsL3[ch] != NotAvail_8bit) && (EvMinAmpsL3[ch] > SeMaxAmpsL3[ch]))) // Current too low
        {
          EvCurrentsFrame[ch] = Incompatible;
          (void)set_priority_info_code(ch, SEINFOENTRY_AVAILABLE_CURRENT_TOO_LOW); // Info code meaning Minimum available current is too low
        }                                                                          // Need to check for NotAvailable values as well because that looks like a high current, and would fail just because the EV is not three phase
        else {
          EvCurrentsFrame[ch] = Compatible;
          (void)clear_info_code(ch, SEINFOENTRY_AVAILABLE_CURRENT_TOO_LOW); // Clear the info code
        }
      }
      if (LFT(ch, EvMinVoltages)) {
        ReadEvMinVolts(ch); // Below, one signal can be invalid (>0x2710 or 1000.0 V) but not both
        if (((EvMinVoltsLL[ch] > SeNomVoltsLL[ch]) && (EvMinVoltsLL[ch] < MaxValidVoltage)) || ((EvMinVoltsLN[ch] > SeNomVoltsLN[ch]) && (EvMinVoltsLN[ch] < MaxValidVoltage))) {
          EvMinVoltsFrame[ch] = Incompatible;
          (void)set_priority_info_code(ch, SEINFOENTRY_AVAILABLE_VOLTAGE_TOO_LOW); // Info code meaning Supply Voltage Too Low for EV
        } else if ((EvMinVoltsLL[ch] > MaxValidVoltage) && (EvMinVoltsLN[ch] > MaxValidVoltage)) {
          EvMinVoltsFrame[ch] = Incompatible;
          //No appropriate code
        } else {
          EvMinVoltsFrame[ch] = Compatible;
          (void)clear_info_code(ch, SEINFOENTRY_AVAILABLE_VOLTAGE_TOO_LOW);
        }
      }
      if ((EvMaxVoltsFrame[ch] == Compatible) && (EvCurrentsFrame[ch] == Compatible) && (EvMinVoltsFrame[ch] == Compatible)) // Evaluate all of the frames flags here
      {
        SeStatusInit[ch] = Complete;
        if (EvStatusInit[ch] == Complete) {
          (void)clear_info_code(ch, SEINFOENTRY_INITIALIZATION_FAILS); // Clear Se Info Code if any. this clears when an incompatibility clears while EvStatsInit == Complete, which is obscure
          SchedulePicker[ch] = StartOp;                                // Next time through loop, trigger the Operation schedule
        }
      } else if ((EvMaxVoltsFrame[ch] == Incompatible) || (EvCurrentsFrame[ch] == Incompatible) || (EvMinVoltsFrame[ch] == Incompatible)) {
        SeStatusInit[ch] = Error2bit;
        //add check for unconfigured vector EVCC
        if (!EvMaxVoltsLL[ch] && !EvMaxVoltsLN[ch] && !EvMinAmpsL1[ch] && !EvMinAmpsL2[ch]  && !EvMinAmpsL3[ch] && !EvFrequencies[ch] && !EvMinVoltsLL[ch] && !EvMinVoltsLN[ch])  {
          DetermineEvseState(ch, BSC_FAILED);
        }
      }
      WriteSeStatus(ch);

      break;      // End of case RunInit
    case StartOp: // Triggers change to Op schedule
      unschedule(init_timeout(ch));
      StartScheduleOp(ch);
      SchedulePicker[ch] = RunOp;
      break;
    case RunOp:
      SeStatusOp[ch] = Complete;                //FIXME
      LW(ch, l_u8, SeStatusOp, SeStatusOp[ch]); // Need to clear this on timeout?
      if (LFT(ch, EvStatus))                    // Check for EV reboot
      {
        schedule_and_reset(T_NOLIN, op_timeout(ch), NULL);
        ReadEvStatus(ch);
        if ((SeCommVer[ch] != EvSelectedVer[ch]) || (EvStatusVer[ch] != Complete) || (EvStatusInit[ch] != Complete)) {
          SchedulePicker[ch] = StartVer; // Restart if EvSelectedVersion or EvStatus has changed
        }
        LINPermitVoltage[ch] = (LR(ch, l_u8, EvStatusOp_EvStatus) == Permit_V); // = 1 when contactor closure is allowed
        LW(ch, l_u8, SeAvailableCurrentL1, (((evse_state[ch].set_c.C1_L1 > 0) && (evse_state[ch].set_c.C1_L1 < EvMinAmpsL1[ch])) ? EvMinAmpsL1[ch] : evse_state[ch].set_c.C1_L1));  //R#:9.6.2.5, any value between 0 and MinAmps must be MinAmps
        LW(ch, l_u8, SeAvailableCurrentL2, SP((((evse_state[ch].set_c.C2_L2 > 0) && (evse_state[ch].set_c.C2_L2 < EvMinAmpsL2[ch])) ? EvMinAmpsL2[ch] : evse_state[ch].set_c.C2_L2), NotAvail_8bit));
        LW(ch, l_u8, SeAvailableCurrentL3, SP((((evse_state[ch].set_c.C3_L3 > 0) && (evse_state[ch].set_c.C3_L3 < EvMinAmpsL3[ch])) ? EvMinAmpsL3[ch] : evse_state[ch].set_c.C3_L3), NotAvail_8bit));
        LW(ch, l_u8, SeAvailableCurrentN, (((evse_state[ch].set_c.C4_N > 0) && (evse_state[ch].set_c.C4_N < EvMinAmpsL1[ch])) ? EvMinAmpsL1[ch] : evse_state[ch].set_c.C4_N));     //Not having EvMinAmpsN is kind of a problem, this is the only solution for 1p and seems reasonable for 3p
      }
      break;
    case StartSleep:
      StartScheduleSleep(ch);
      break;
    case RunSleep:
      if (Pilot_Voltage[ch] != STATE_B) // Not used yet
      {
        SchedulePicker[ch] = StartNull; // Also need a wake up on signal from EV here
      }
      break;
    default:
      (void)0;    //make clang happy

  } // End of switch SchedulePicker

  if (LFT(ch, SeInfoList)) {
    xmit_info_code_page(ch);
  }
  if (LFT(ch, EvInfoList)) {
    rcv_info_code_page(ch);
  }

  if (LFT(ch, SeVersionList)) {
    xmit_protocol_version_page(ch);
  }

  if (LFT(ch, SeID)) {
    on_id_frame_xmit(ch);
    LFC(ch, SeID);
  }
  if (LFT(ch, EvID)) {
    on_id_frame_receipt(ch);
    LFC(ch, EvID);
  }

  if (LFT(ch, SeJ3072)) {
    on_j3072_frame_xmit(ch);
    LFC(ch, SeJ3072);
  }
  if (LFT(ch, EvJ3072)) {
    on_j3072_frame_receipt(ch);
    LFC(ch, EvJ3072);
  }
#pragma MESSAGE DISABLE C12056 //debug info incorrect because of optimization or inline assembler
} // End of DetermineLINCPState (which is not all it does)

/**********************************************************
************************SE_CONFIG>*************************
***********************************************************/

#endif

void InitializeLINCP(void) {
  (void)l_sys_init();
  (void)l_ifc_init(LI0);
  InitializeLINvariables(A);
#ifndef CH_A_ONLY
  (void)l_ifc_init(LI1);
  InitializeLINvariables(B);
#endif
}

