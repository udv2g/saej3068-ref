#include "hardware.h"
#include "canbus.h"
#include "globals.h"
#include "pilot.h"
#include "scheduler.h"
#include "utils.h"
#include "lock.h"

#include "j1939.h"
#include "j1939-signals.h"

#ifdef LIN_CHARGE_ENABLE
#include "lin.h"
#include "lin_cfg.h"
#endif

/* GLOBAL VARIABLES */
#define MAX_COMMAND_SIZE 8
uint8_t command_buf[MAX_COMMAND_SIZE + 2];

static j1939_messages_to_send_t j1939_messages_to_send;
static HSC1_t last_HSC1;

static j1939_messages_received_t j1939_messages_received;

void j1939_init_hardware(void) {
  InitCAN(NORMAL_MODE, CAN250KBAUD);

  mem_init_ff(&j1939_messages_to_send, sizeof(j1939_messages_to_send_t));
  mem_init_ff(&last_HSC1, sizeof(HSC1_t));
}

int8_t send_command_CAN(uint32_t id, uint8_t *data, uint8_t msg_size) {
  int i;
  uint8_t tb;
  uint8_t *dest = &CANTXDSR0;

  //PrintConsoleString("sending CAN\r\n",0);

  if (!CANTFLG) {
    CANTARQ = 0x7;
    //this packet will be lost but but next time it should be clear
    return -1; //you could return fail here
  }

  CANTBSEL = CANTFLG;  // make an empty transmit buffer accessible
  tb       = CANTBSEL; //see which one your got

  // Write the identifier
  CANTXIDR0 = ((id >> 21) & 0xFF);
  CANTXIDR1 = ((id >> 13) & 0xE0) | 0x18 | ((id >> 15) & 0x07);
  CANTXIDR2 = ((id >> 7) & 0xFF);
  CANTXIDR3 = ((id << 1) & 0xFE);

  // Write the data
  for (i = 0; i < msg_size; ++i) {
    dest[i] = data[i];
  }

  // Finally write the msg size
  CANTXDLR = msg_size;

  CANTFLG = tb; // buffer marked by tb ready for transmission
  return tb;
}

uint32_t timeout_HSC1(void *ptr) {
  disable_desire_to_charge(A, CHARGING_DISABLED_J1939);
  disable_desire_to_charge(B, CHARGING_DISABLED_J1939);
  PrintConsoleString("Disable Charge Timeout\r\n", 0);
  return 0;
}

int handle_HSC1(void *msg) {
  HSC1_t *HSC1_msg = (HSC1_t *)msg;

#ifdef J1939_REQD_FOR_CHARGE
  if (HSC1_msg->HVESChargeConsent == J1939_SPN10148_ALLOWED) {
    enable_desire_to_charge(A, CHARGING_DISABLED_J1939);
    enable_desire_to_charge(B, CHARGING_DISABLED_J1939);
    schedule_and_reset(J1939_1S_MESSAGE_TIMEOUT, timeout_HSC1, NULL);
    //PrintConsoleString("Enable Charge\r\n",0);
  } else {
    disable_desire_to_charge(A, CHARGING_DISABLED_J1939);
    disable_desire_to_charge(B, CHARGING_DISABLED_J1939);
    PrintConsoleString("Disable Charge\r\n", 0);
  }
#endif

  //PrintConsoleString("18808249 HSC1\r\n",0);
  return (msg) ? 1 : 0;
}

//not used yet
int handle_HSS1(void *msg) {
  HSS1_t *HSS1_msg = (HSS1_t *)msg;

  //PrintConsoleString("18FCC249 HSS1\r\n",0);
  return (msg) ? 1 : 0;
}

uint32_t timeout_EVSE1AC3PL_A(void *ptr) {
#pragma MESSAGE DISABLE C2705 //possible loss of data.  this is related to the flags somehow.
  l_u8_wr_LI0_EvPresentCurrentL1(0xFF);
  l_u8_wr_LI0_EvPresentCurrentL2(0xFF);
  l_u8_wr_LI0_EvPresentCurrentL3(0xFF);
  l_u8_wr_LI0_EvPresentCurrentN(0xFF);
  //PrintConsoleString("chA-PC-Reset\r\n",0);
  return 0;
}

#pragma MESSAGE WARNING C2705

int handle_EVSE1AC3PL_A(void *msg) {
  EVSE1AC3PL_t *EVSE1AC3PL_A_msg = (EVSE1AC3PL_t *)msg;

#pragma MESSAGE DISABLE C2705 //possible loss of data. Duh!
  l_u8_wr_LI0_EvPresentCurrentL1((l_u8)(EVSE1AC3PL_A_msg->HVESS_Charger_RMS_current_L1 >> 4)); //reduce resolution by factor of 16
  l_u8_wr_LI0_EvPresentCurrentL2((l_u8)(EVSE1AC3PL_A_msg->HVESS_Charger_RMS_current_L2 >> 4)); //reduce resolution by factor of 16
  l_u8_wr_LI0_EvPresentCurrentL3((l_u8)(EVSE1AC3PL_A_msg->HVESS_Charger_RMS_current_L3 >> 4)); //reduce resolution by factor of 16
  l_u8_wr_LI0_EvPresentCurrentN((l_u8)(EVSE1AC3PL_A_msg->HVESS_Charger_RMS_current_N >> 4));   //reduce resolution by factor of 16
  schedule_and_reset(J1939_100MS_MESSAGE_TIMEOUT, timeout_EVSE1AC3PL_A, NULL);

  //PrintConsoleString("18FAC549 EVSE1AC3PL_A\r\n",0);
  //PrintConsoleString("chA-PC-L1:",0);
  //PrintConsoleHex(l_u8_rd_LI0_EvPresentCurrentL1());
  //PrintConsoleString("\r\n",0);
  return (msg) ? 1 : 0;
}

uint32_t timeout_EVSE1AC3PL_B(void *ptr) {
#pragma MESSAGE DISABLE C2705 //possible loss of data.
  l_u8_wr_LI1_EvPresentCurrentL1(0xFF);
  l_u8_wr_LI1_EvPresentCurrentL2(0xFF);
  l_u8_wr_LI1_EvPresentCurrentL3(0xFF);
  l_u8_wr_LI1_EvPresentCurrentN(0xFF);
  return 0;
}

int handle_EVSE1AC3PL_B(void *msg) {
  EVSE1AC3PL_t *EVSE1AC3PL_B_msg = (EVSE1AC3PL_t *)msg;

#pragma MESSAGE DISABLE C2705 //possible loss of data. Duh!
  l_u8_wr_LI1_EvPresentCurrentL1((l_u8)(EVSE1AC3PL_B_msg->HVESS_Charger_RMS_current_L1 >> 4)); //reduce resolution by factor of 16
  l_u8_wr_LI1_EvPresentCurrentL2((l_u8)(EVSE1AC3PL_B_msg->HVESS_Charger_RMS_current_L2 >> 4)); //reduce resolution by factor of 16
  l_u8_wr_LI1_EvPresentCurrentL3((l_u8)(EVSE1AC3PL_B_msg->HVESS_Charger_RMS_current_L3 >> 4)); //reduce resolution by factor of 16
  l_u8_wr_LI1_EvPresentCurrentN((l_u8)(EVSE1AC3PL_B_msg->HVESS_Charger_RMS_current_N >> 4));   //reduce resolution by factor of 16
  schedule_and_reset(J1939_100MS_MESSAGE_TIMEOUT, timeout_EVSE1AC3PL_B, NULL);

  //PrintConsoleString("18FAC550 EVSE1AC3PL_B\r\n",0);
  return (msg) ? 1 : 0;
}

#pragma MESSAGE WARNING C2705

#define j1939_msg_dispatch_tbl_SIZE 4
#ifdef CH_A_ONLY
#define CHANNEL_B_ACTIVE 0
#else
#define CHANNEL_B_ACTIVE 1
#endif
j1939_msg_dispatcher_t j1939_msg_dispatch_tbl[] = {
    {
        J1939_ID_HSC1 | (J1939_CHANNEL_A_INLET_ID << 8) | J1939_ECU_ID,
        &j1939_messages_received.HSC1,
        read_HSC1,
        handle_HSC1,
        1,
    },
    {
        J1939_ID_HSS1 | J1939_ECU_ID,
        &j1939_messages_received.HSS1,
        read_HSS1,
        handle_HSS1,
        1,
    },
    {
        J1939_ID_EVSE1AC3PL | J1939_CHANNEL_A_INVERTER_ID,
        &j1939_messages_received.EVSE1AC3PL_A,
        read_EVSE1AC3PL,
        handle_EVSE1AC3PL_A,
        1,
    },
    {
        J1939_ID_EVSE1AC3PL | J1939_CHANNEL_B_INVERTER_ID,
        &j1939_messages_received.EVSE1AC3PL_B,
        read_EVSE1AC3PL,
        handle_EVSE1AC3PL_B,
        CHANNEL_B_ACTIVE,
    },
};

void print_msg(uint32_t id, uint8_t *buf, int start, int end) {
  int i;
  PrintConsoleLongHex(id);
  PrintConsoleString(" :: ", 0);

  for (i = start; i < end; ++i) {
    PrintConsoleHex(buf[i]);
    PrintConsoleString(" ", 0);
  }
  PrintConsoleString("\r\n", 0);
}

uint32_t parse_message_CAN() {
  int i;
  uint32_t id;
  uint8_t msg_length;
  j1939_msg_dispatcher_t *curr_msg_dispatcher;

  //id = CANRIDR0; // Read the higher order bits 8 bits of the id
  //id = (id << 3) | ((CANRIDR1 >> 5) & 0x07); // Read the lower order 3 bits

  // EXTEDED MESSAGES HANDLING
  id = 0;
  id = CANRXIDR0;
  id = (id << 6) | ((CANRXIDR1 & 0xE0) >> 2) | (CANRXIDR1 & 0x07);
  id = (id << 8) | (CANRXIDR2 & 0xFF);
  id = (id << 7) | ((CANRXIDR3 >> 1) & 0x7F);

  msg_length = CANRXDLR;

  // Ok, let's try to parse this message
  for (i = 0; i < j1939_msg_dispatch_tbl_SIZE; ++i) {
    curr_msg_dispatcher = &j1939_msg_dispatch_tbl[i];
    if (curr_msg_dispatcher->id == id) {
      if (curr_msg_dispatcher->process_message_p) {
        (void)curr_msg_dispatcher->parser(curr_msg_dispatcher->obj, &CANRXDSR0, 0, msg_length);
        (void)curr_msg_dispatcher->handler(curr_msg_dispatcher->obj);
      }
      break;
    }
  }

  return 0;
}

#pragma INLINE
void CAN_RXRoutine(void) {

  //PrintConsoleString("receiving CAN\r\n",0);

  (void)parse_message_CAN();
}

// clang-format off
void populate_j1939_messages() {
//HSI1 (PGN 65238) SPN 7551
//reports the presence of an EVSE for vehicle immobilization
#ifdef CH_A_ONLY
#define EVSE_PRESENT evse_prox_present_p(A)
#else
#define EVSE_PRESENT (evse_prox_present_p(A) || evse_prox_present_p(B))
#endif
  if (EVSE_PRESENT) {
    j1939_messages_to_send.HSI1.HybridSystemOffBoardChargerConnectionStatus = J1939_SPN7551_CONNECTED;
  } else  {
    j1939_messages_to_send.HSI1.HybridSystemOffBoardChargerConnectionStatus = J1939_SPN7551_NOTCONNECTED;
  }

//HSC1 (PGN 32768) SPNs 7890 & 13154
//Indicates the type of energy connection.  Will always be "Source" and "AC" when valid in Ver 2.  Indicates if one or both inlets are connected in 2 channel mode.
#ifdef CH_A_ONLY    //handle these cases completely separately
  if (evse_present_p(A)) {
    j1939_messages_to_send.HSC1.ExternalEnergyConnectionDemand = J1939_SPN7890_SOURCE1;              //7890
    j1939_messages_to_send.HSC1.ConnectedEnergySourceType = J1939_SPN13154_ACSOURCE;                 //13154
  } else  {
    j1939_messages_to_send.HSC1.ExternalEnergyConnectionDemand = J1939_SPN7890_NOCONNECTION;         //7890
    j1939_messages_to_send.HSC1.ConnectedEnergySourceType = J1939_SPN13154_NOACTION;                 //13154
  }
#else
  if (evse_present_p(A) || evse_present_p(B)) {
    if (evse_present_p(A) && evse_present_p(B))  {
      j1939_messages_to_send.HSC1.ExternalEnergyConnectionDemand = J1939_SPN7890_SOURCE2;            //7890    treat both inlets as "connection 2"
    } else  {
      j1939_messages_to_send.HSC1.ExternalEnergyConnectionDemand = J1939_SPN7890_SOURCE1;            //7890    treat either inlet individually as "connection 1"
    }
    j1939_messages_to_send.HSC1.ConnectedEnergySourceType = J1939_SPN13154_ACSOURCE;                 //13154
  } else  {
    j1939_messages_to_send.HSC1.ExternalEnergyConnectionDemand = J1939_SPN7890_NOCONNECTION;         //7890
    j1939_messages_to_send.HSC1.ConnectedEnergySourceType = J1939_SPN13154_NOACTION;                 //13154
  }
#endif

//EVSE1S1 (PGN 64214) SPNs 12861, 12862, & 12863
//Indicates the status of the inlet lock
#define EVSE1S1_SPN12861_M(ch) \
  if (IEC_Prox_Voltage[ch] == IEC_J1772_PRESSED) {                                                   \
    j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorReleaseLatch = J1939_SPN12861_ENGAGED;      /*12861*/\
  } else if (IEC_Prox_Voltage[ch] == IEC_J1772_RELEASED) {                                           \
    j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorReleaseLatch = J1939_SPN12861_RELEASED;     /*12861*/\
  } else  {                                                                                          \
    j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorReleaseLatch = J1939_SPN12861_NOTAVAILABLE; /*12861   should be "Not Available" unless a J1772 adapter is used*/\
  }
  EVSE1S1_SPN12861_M(A);
#ifndef CH_A_ONLY
  EVSE1S1_SPN12861_M(B);
#endif

#define EVSE1S1_SPN12862_M(ch) \
  if (getLockStatusMismatch(ch)) {                                                                   \
    j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ManualOverRide = J1939_SPN12862_OVERRIDEN;           /*12862*/\
  } else  {                                                                                          \
    j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ManualOverRide = J1939_SPN12862_NOTOVERRIDEN;        /*12862*/\
  }
  EVSE1S1_SPN12862_M(A);
#ifndef CH_A_ONLY
  EVSE1S1_SPN12862_M(B);
#endif
    
#define EVSE1S1_SPN12863_M(ch) \
  switch(getLockStatus(ch)) {                                                                        \
    case locked:                                                                                     \
    case presumedLocked:                                                                             \
      j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorLockState = J1939_SPN12863_LOCKED;        /*12863*/\
      break;                                                                                         \
    case unlocked:                                                                                   \
    case presumedUnlocked:                                                                           \
      j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorLockState = J1939_SPN12863_UNLOCKED;      /*12863*/\
      break;                                                                                         \
    case locking:                                                                                    \
    case unlocking:                                                                                  \
      j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorLockState = J1939_SPN12863_INTRANSITION;  /*12863*/\
      break;                                                                                         \
    default:                                                                                         \
      j1939_messages_to_send.EVSE1S1_##ch##.EVSE1_ConnectorLockState = J1939_SPN12863_ERROR;         /*12863   how did we get here?*/\
  }
  EVSE1S1_SPN12863_M(A);
#ifndef CH_A_ONLY
  EVSE1S1_SPN12863_M(B);
#endif

//EVSE1ACSV (PGN 64196) SPNs 13006, 13007, & 13007
//indicates voltage/frequency of connected EVSE
#define EVSE1ACSV_M(ch) \
  if (lin_evse_present_p(ch))  {                                                                     \
    j1939_messages_to_send.EVSE1ACSV_##ch##.SeNomVoltageL1N = 2*SeNomVoltsLN[ch];                    /*13006*/\
    j1939_messages_to_send.EVSE1ACSV_##ch##.SeNomVoltageLL = 2*SeNomVoltsLL[ch];                     /*13007*/\
    j1939_messages_to_send.EVSE1ACSV_##ch##.SeFrequency = SeFrequency[ch];                           /*13008   is this safe?*/\
  } else  {   /*Disconnected or PWM*/                                                                \
    j1939_messages_to_send.EVSE1ACSV_##ch##.SeNomVoltageL1N = 0xFFFF;                                /*13006*/\
    j1939_messages_to_send.EVSE1ACSV_##ch##.SeNomVoltageLL = 0xFFFF;                                 /*13007*/\
    j1939_messages_to_send.EVSE1ACSV_##ch##.SeFrequency = J1939_SPN13008_NOTAVAILABLE;               /*13008*/\
  }
  EVSE1ACSV_M(A);
#ifndef CH_A_ONLY
  EVSE1ACSV_M(B);
#endif

//EVSE1C1 (PGN 21248) SPN 12864
//commands external locking mechanism.  not currently implemented.

//InletProxAndSeInfo
//made up nonsense
#define InletProxAndSeInfo_M(ch) \
  if (charging_evse_present_p(ch)){                                                                  \
    j1939_messages_to_send.ProxSEInfo_##ch##.Se_Ev_System_State = 0x2;                               \
  }                                                                                                  \
  else if (evse_present_p(ch)){                                                                      \
    j1939_messages_to_send.ProxSEInfo_##ch##.Se_Ev_System_State = 0x1;                               \
  }                                                                                                  \
  else{                                                                                              \
    j1939_messages_to_send.ProxSEInfo_##ch##.Se_Ev_System_State = 0x0;                               \
  }                                                                                                  \
  j1939_messages_to_send.ProxSEInfo_##ch##.Prox_Status = (uint8_t )IEC_Prox_Voltage[ch];             \
  if (lin_evse_present_p(ch))  {                                                                     \
    if (LR(ch,l_u8,SeInfoPageNumber) == 0)  {       /*only send page 0 for now.  other pages will have to be buffered as this message is so much slower than the LIN*/\
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry1 = LR(ch, l_u8, SeInfoEntry1);            \
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry2 = LR(ch, l_u8, SeInfoEntry2);            \
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry3 = LR(ch, l_u8, SeInfoEntry3);            \
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry4 = LR(ch, l_u8, SeInfoEntry4);            \
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry5 = LR(ch, l_u8, SeInfoEntry5);            \
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry6 = LR(ch, l_u8, SeInfoEntry6);            \
      j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoPageNumber = 0;                                 \
    } /*leave whatever is in there*/                                                                 \
  } else  {  /*undefined if not in LIN*/                                                             \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry1 = 0xFF;                                    \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry2 = 0xFF;                                    \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry3 = 0xFF;                                    \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry4 = 0xFF;                                    \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry5 = 0xFF;                                    \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoEntry6 = 0xFF;                                    \
    j1939_messages_to_send.ProxSEInfo_##ch##.SeInfoPageNumber = 0xFF;                                \
  }
  InletProxAndSeInfo_M(A);
#ifndef CH_A_ONLY
  InletProxAndSeInfo_M(B);
#endif

//EVSE1ACS1 (PGN 64213) SPNs  12865, 13003, 13004, & 13005
//indicates present current limits
#define EVSE1ACS1_M(ch) \
  if (charging_evse_present_p(ch)) {                                                                 \
    if (lin_evse_present_p(ch))  {                                                                   \
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL1 = 16*ev_max_c[ch].C1_L1;    /*12865*/\
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL2 = 16*ev_max_c[ch].C2_L2;    /*13003*/\
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL3 = 16*ev_max_c[ch].C3_L3;    /*13004*/\
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitN =  16*ev_max_c[ch].C4_N;     /*13005*/\
    } else  { /*if charging evse present but not lin evse, must be pwm*/                             \
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL1 = 16*ev_max_c[ch].pwm;      /*12865*/\
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL2 = 16*ev_max_c[ch].pwm;      /*13003*/\
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL3 = 16*ev_max_c[ch].pwm;      /*13004*/\
      j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitN =  16*ev_max_c[ch].pwm;      /*13005*/\
    }                                                                                                \
  } else  {                                                                                          \
    j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL1 = 0xFFFF;                     /*12865*/\
    j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL2 = 0xFFFF;                     /*13003*/\
    j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitL3 = 0xFFFF;                     /*13004*/\
    j1939_messages_to_send.EVSE1ACS1_##ch##.EVSE_AC_RMS_CurrentLimitN =  0xFFFF;                     /*13005*/\
  }
  EVSE1ACS1_M(A);
#ifndef CH_A_ONLY
  EVSE1ACS1_M(B);
#endif
#pragma MESSAGE DISABLE C12056  //debug info incorrect because of optimization or inline assembler
}
// clang-format on

//call every 50ms
void send_j1939_messages() {
  static uint8_t loop_counter;
  int8_t ret_value;

  //1 second total time
  if (loop_counter >= 20) {
    loop_counter = 0;
  }
  loop_counter++;

  //Give each message a time slot to be sent in to minimize bus loading.
  //The CAN transmitter has three buffers, at most two messages will be sent in a time slot.

#ifdef CH_A_ONLY
#define CH_A_STRING
#else
#define CH_A_STRING "CH A "
#endif

  //EVSEACS1, 100ms
  if (loop_counter % 2) {
    (void)write_EVSE1ACS1(&command_buf[0], &j1939_messages_to_send.EVSE1ACS1_A);
    ret_value = send_command_CAN(J1939_ID_EVSE1ACS1 | J1939_CHANNEL_A_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending EVSE1ACS1 " CH_A_STRING "CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }
#ifndef CH_A_ONLY
  else {
    (void)write_EVSE1ACS1(&command_buf[0], &j1939_messages_to_send.EVSE1ACS1_B);
    ret_value = send_command_CAN(J1939_ID_EVSE1ACS1 | J1939_CHANNEL_B_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending EVSE1ACS1 CH B CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }
#endif

  //HSI1, 1s
  if (loop_counter == 2) {
    (void)write_HSI1(&command_buf[0], &j1939_messages_to_send.HSI1);
    ret_value = send_command_CAN(J1939_ID_HSI1 | J1939_CHANNEL_A_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending HSI1 CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }

  //EVSE1S1, 1s
  if (loop_counter == 4) {
    (void)write_EVSE1S1(&command_buf[0], &j1939_messages_to_send.EVSE1S1_A);
    ret_value = send_command_CAN(J1939_ID_EVSE1S1 | J1939_CHANNEL_A_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending EVSE1S1 " CH_A_STRING "CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }

  //EVSE1ACSV, "On Request", send every second
  if (loop_counter == 6) {
    (void)write_EVSE1ACSV(&command_buf[0], &j1939_messages_to_send.EVSE1ACSV_A);
    ret_value = send_command_CAN(J1939_ID_EVSE1ACSV | J1939_CHANNEL_A_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending EVSE1ACSV " CH_A_STRING "CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }

#ifndef CH_A_ONLY
  //EVSE1S1, 1s
  if (loop_counter == 8) {
    (void)write_EVSE1S1(&command_buf[0], &j1939_messages_to_send.EVSE1S1_B);
    ret_value = send_command_CAN(J1939_ID_EVSE1S1 | J1939_CHANNEL_B_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending EVSE1S1 CH B CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }

  //EVSE1ACSV, "On Request", send every second
  if (loop_counter == 10) {
    //printf("EVSE1ACSV-B\t");
    (void)write_EVSE1ACSV(&command_buf[0], &j1939_messages_to_send.EVSE1ACSV_B);
    ret_value = send_command_CAN(J1939_ID_EVSE1ACSV | J1939_CHANNEL_B_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending EVSE1ACSV CH B CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }
#endif

#ifdef J1939_SEND_SEINFO
  //Send InletProxAndSeInfo once per second if desired
  if (loop_counter == 12) {
    (void)write_InletProxAndSeInfo(&command_buf[0], &j1939_messages_to_send.ProxSEInfo_A);
    ret_value = send_command_CAN(J1939_ID_INLETPROXANDSEINFO | J1939_CHANNEL_A_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending InletProxAndSeInfo " CH_A_STRING "CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }

#ifndef CH_A_ONLY
  if (loop_counter == 14) {
    (void)write_InletProxAndSeInfo(&command_buf[0], &j1939_messages_to_send.ProxSEInfo_B);
    ret_value = send_command_CAN(J1939_ID_INLETPROXANDSEINFO | J1939_CHANNEL_B_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending InletProxAndSeInfo CH B CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
  }
#endif
#endif

  //HSC1, Every 1 s and on change but no faster than 100 ms
  if ((loop_counter == 1) || ((loop_counter % 2) && (!mem_compare(&last_HSC1, &j1939_messages_to_send.HSC1, sizeof(HSC1_t))))) {
    //printf("HSC1\t");
    (void)write_HSC1(&command_buf[0], &j1939_messages_to_send.HSC1);
    ret_value = send_command_CAN(J1939_ID_HSC1 | (J1939_ECU_ID << 8) | J1939_CHANNEL_A_INLET_ID, command_buf, 8);

    if (ret_value == -1) {
      PrintConsoleString("Error sending HSC1 CAN message\r\n", 0);
      InitCAN(NORMAL_MODE, CAN250KBAUD);
    }
    last_HSC1 = j1939_messages_to_send.HSC1;
  }
}
