#include "derivative.h"
#include "pilot.h"
#include "hardware.h"
#include "scheduler.h"
#include "config.h"
#include "sci.h"
#include "globals.h"
#include "lock.h"
#include "j1939.h"
#include "serialCmds.h"
#include "adc_constants.h"

#ifdef LIN_CHARGE_ENABLE
#include "lin-cp.h"

//static st_station_t station_status_struct;
//static st_vehicle_t vehicle_status_struct;
#endif

/*******************************************************
 * File Scope variables
 ********************************************************/

//volatile uint8_t COMM_MODE;

static volatile uint8_t inhibit_StateB2[2];

static EV_STATE Ev_State[2] = {EV_F1, EV_F1}; //ensure known state when in opposite mode
static EVSE_STATE Evse_State[2] = {EVSE_A0, EVSE_A0};

//volatile uint16_t ev_pilot_first_rising, ev_pilot_second_rising, ev_pilot_first_falling, ev_pilot_period_time, ev_pilot_duty_cycle_time;
//volatile BOOL pilot_in_range, PWM_present;
//static volatile bool pilotA_in_range, PWMA_present, PWMA_5duty;
//static volatile bool pilotB_in_range, PWMB_present, PWMB_5duty;

//volatile bool main_powergood;

static volatile bool prox_safe_to_energize[2];

//static volatile int16_t NSSDigitalTimeout;
//static volatile int16_t TimeoutCount;

static volatile uint8_t EVSEProxSmart = 0; //does this need to be a variable?
static volatile uint8_t EVSEProxMode;
static volatile uint16_t ProxSum;
static volatile uint16_t ProxSumCount;
static volatile uint8_t EVSEProxValueMin;
static volatile uint8_t EVSEProxValueMax;
static volatile CHARGE_CONTROL charge_control[2];

static filter_t prox_voltage_filter[2];
//BOOL prox_filter_initialized_p = 0;

static filter_t pilot_voltage_filter[2];
static filter_t pilot_voltage_neg_filter[2];
static filter_t pilot_period_filter[2];

static filter_t pilot_duty_filter[2];

//static uint8_t _send_status_message_p;
//static uint8_t _timeout_enabled_p;
//static uint8_t _status_message_received_p; //maybe not needed?

/*******************************************************
 * Initialization
 ********************************************************/

void pilot_init(void) {
  inhibit_StateB2[A] = NOT_INHIBITED;
  inhibit_StateB2[B] = NOT_INHIBITED;
  //hold_StateB0 = NOT_HELD;

  LINPermitVoltage[A] = 0;
  LINPermitVoltage[B] = 0;

  ResetEVSEProxMode();

  //COMM_MODE = COMM_UNINIT;   // default

  //evse_init(&evse_state);
  //EVSE_duty = amps2duty(EVSE_DEFAULT_C);

  //ev_pilot_first_rising = ev_pilot_second_rising = ev_pilot_first_falling = ev_pilot_period_time = ev_pilot_duty_cycle_time = 0;

  // Zero out all the variables
  charge_control[A] = CHARGING_ENABLED;
  charge_control[B] = CHARGING_ENABLED;

  //if (!prox_filter_initialized_p) {
  filter_init(&prox_voltage_filter[A], FILTER_SIZE);
  filter_init(&prox_voltage_filter[B], FILTER_SIZE);
  //}
  filter_init(&pilot_voltage_filter[A], FILTER_SIZE);
  filter_init(&pilot_voltage_filter[B], FILTER_SIZE);
  filter_init(&pilot_voltage_neg_filter[A], FILTER_SIZE);
  filter_init(&pilot_voltage_neg_filter[B], FILTER_SIZE);
  filter_init(&pilot_period_filter[A], FILTER_SIZE);
  filter_init(&pilot_period_filter[B], FILTER_SIZE);

  //RTM FIXME
  //filter_init(&main_powergood_filter, FILTER_SIZE);
  //hardcode to 1
  //main_powergood = 1;
  filter_init(&pilot_duty_filter[A], FILTER_SIZE);
  filter_init(&pilot_duty_filter[B], FILTER_SIZE);

  //init_communication_structs();

  //NSSDigitalTimeout = 2000;   //default timeout
  //defaultBaudRate = CAN500KBAUD; //default rate

#ifdef EV_CONFIG
  ev_max_c[A].pwm   = 0;
  ev_max_c[A].C1_L1 = 0;
  ev_max_c[A].C2_L2 = 0;
  ev_max_c[A].C3_L3 = 0;
  ev_max_c[A].C4_N  = 0;
  ev_max_c[B]       = ev_max_c[A];
#endif

  /*
  //if(!DIP7){     //longer timeout and 20kbaud
    NSSDigitalTimeout = 20000;   //exteneded timeout
    defaultBaudRate = CAN20KBAUD;
  //}
*/

  //TimeoutCount = NSSDigitalTimeout;  //initalize timeout
}

/*******************************************************
 * Desire to Charge
 ********************************************************/

bool desire_to_charge_p(uint8_t ch) {
  return charge_control[ch] == CHARGING_ENABLED;
}

void disable_desire_to_charge(uint8_t ch, CHARGE_CONTROL cause) {
  /* PrintConsoleString("!DC=",0); */
  /* PrintConsoleHex(cause); */
  /* PrintConsoleString("\r\n",0); */
  charge_control[ch] |= cause;
}

void enable_desire_to_charge(uint8_t ch, CHARGE_CONTROL cause) {
  /* PrintConsoleString("DC=",0); */
  /* PrintConsoleHex(cause); */
  /* PrintConsoleString("\r\n",0); */
  charge_control[ch] &= ~(cause);
}

/*******************************************************
 * Communication
 ********************************************************/

//#pragma MESSAGE DISABLE C5703
//#pragma MESSAGE DISABLE C1825

#ifdef LIN_CHARGE_ENABLE
uint32_t DigitalSolicitationA(void *foo) {
  //USED for LIN only
  //(void)write_status_station(CAN_ID_STATION_STATUS, &station_status_struct);
  return DELAY_BETWEEN_SOLICITATIONS;
}

uint32_t DigitalSolicitationB(void *foo) {
  //USED for LIN only
  //(void)write_status_station(CAN_ID_STATION_STATUS, &station_status_struct);
  return DELAY_BETWEEN_SOLICITATIONS;
}

//this is really goofy.  consider changing
#define DigitalSolicitation(x) ((x) ? DigitalSolicitationB : DigitalSolicitationA)

uint32_t DigitalSolicitationFailedA(void *foo) {
  //USED for CAN and LIN
  unschedule(DigitalSolicitationA);
  DetermineEvseState(A, BSC_FAILED);
  return 0;
}

uint32_t DigitalSolicitationFailedB(void *foo) {
  //USED for CAN and LIN
  unschedule(DigitalSolicitationB);
  DetermineEvseState(B, BSC_FAILED);
  return 0;
}

#define DigitalSolicitationFailed(x) ((x) ? DigitalSolicitationFailedB : DigitalSolicitationFailedA)
#endif

#if 0
static void _enable_timeout() {
  _timeout_enabled_p = 1;
  /* schedule_and_reset(NSSDigitalTimeout, */
  /*                    DigitalCommunicationTimeout, NULL); */
}

static void _disable_timeout() {
  _timeout_enabled_p = 0;
  /* unschedule(DigitalCommunicationTimeout); */
}

void check_for_timeouts() {
  if (_timeout_enabled_p) {
    if (_status_message_received_p) {
      _status_message_received_p = 0;
      TimeoutCount = NSSDigitalTimeout;
    }
    else {
      TimeoutCount--;
      if (TimeoutCount <= 0) {
#ifdef LIN_CHARGE_ENABLE
        (void)DigitalCommunicationTimeout();
#endif
        TimeoutCount = NSSDigitalTimeout;
      }
    }
  }
  else {
    TimeoutCount = NSSDigitalTimeout;
  }
}
#endif

/*******************************************************
 * State Machine
 ********************************************************/

//#pragma MESSAGE DISABLE C12056

enum {
  EV_READY_FLAG_DESIRE_TO_CHARGE      = 0x01,
  EV_READY_FLAG_PROX_SAFE_TO_ENERGIZE = 0x02,
  EV_READY_FLAG_MAX_C_GOOD            = 0x04,
  EV_READY_FLAG_SE_READY              = 0x08,
  EV_READY_FLAG_SE_AVAILABLE          = 0x10,
  EV_READY_J1939_READY                = 0x20,
} EV_READY_FLAGS;

// FIXME:
// With Annex D, we can stay energized without charging for
// 15 minutes. Is J1772 compatible with C2-->C1-->C2?
/* #define _EV_READY (EV_READY_FLAG_DESIRE_TO_CHARGE | \ */
/*                    EV_READY_FLAG_PROX_SAFE_TO_ENERGIZE |    \ */
/*                    EV_READY_FLAG_MAX_C_GOOD |   \ */
/*                    EV_READY_FLAG_SE_READY |     \ */
/*                    EV_READY_FLAG_SE_AVAILABLE | \ */
/*                    EV_READY_J1939_READY) */

#define _EV_READY (EV_READY_FLAG_DESIRE_TO_CHARGE |      \
                   EV_READY_FLAG_PROX_SAFE_TO_ENERGIZE | \
                   EV_READY_FLAG_SE_READY |              \
                   EV_READY_FLAG_SE_AVAILABLE |          \
                   EV_READY_J1939_READY)

//FIXME need to add cond for error handling
//if we need to fake disable PWM
#define _DUTY_READY (EV_READY_FLAG_MAX_C_GOOD | \
                     EV_READY_FLAG_SE_READY |   \
                     EV_READY_FLAG_SE_AVAILABLE)

static uint8_t _get_ev_ready_flags(uint8_t ch, uint8_t check_flags,
                                   uint8_t *last_ready_flags,
                                   char *debug_string) {
  uint8_t ready_flags = 0;

  if ((check_flags & EV_READY_FLAG_DESIRE_TO_CHARGE) &&
      desire_to_charge_p(ch)) {
    ready_flags |= EV_READY_FLAG_DESIRE_TO_CHARGE;
  }

  if ((check_flags & EV_READY_FLAG_PROX_SAFE_TO_ENERGIZE) &&
      (prox_safe_to_energize[ch])) {
    ready_flags |= EV_READY_FLAG_PROX_SAFE_TO_ENERGIZE;
  }
  
  if ((check_flags & EV_READY_FLAG_MAX_C_GOOD) && (ev_max_c[ch].pwm > 0)) {
    ready_flags |= EV_READY_FLAG_MAX_C_GOOD;
  }

  if ((Ev_State[ch] == EV_B2) || (Ev_State[ch] == EV_C2)) {
    if (PILOT_PRESENT(ch)) {
      if (check_flags & EV_READY_FLAG_SE_READY) {
        ready_flags |= EV_READY_FLAG_SE_READY;
      }
      if (check_flags & EV_READY_FLAG_SE_AVAILABLE) {
        ready_flags |= EV_READY_FLAG_SE_AVAILABLE;
      }
    }
  } else {
#ifdef LIN_CHARGE_ENABLE
    if ((check_flags & EV_READY_FLAG_SE_READY) &&
        (SeStatusOp[ch] == 1)) {
      ready_flags |= EV_READY_FLAG_SE_READY;
    }
    if ((check_flags & EV_READY_FLAG_SE_AVAILABLE) &&
        (SeStatusOp[ch] < 2)) {
      ready_flags |= EV_READY_FLAG_SE_AVAILABLE;
    }
//#else  //probably need to change this back
/*
    if ((check_flags & EV_READY_FLAG_SE_READY) &&
      (station_status_struct.SeSupplyReadyStatus)) {
      ready_flags |= EV_READY_FLAG_SE_READY;
    }
    if ((check_flags & EV_READY_FLAG_SE_AVAILABLE) &&
      (station_status_struct.SeAvailabilityStatus)) {
      ready_flags |= EV_READY_FLAG_SE_AVAILABLE;
    }
  */
#endif
  }

  if (check_flags & EV_READY_J1939_READY) {
    ready_flags |= EV_READY_J1939_READY;
  }

#ifdef DEBUG_J1772_STATES
  if (ready_flags != *last_ready_flags) {
    PrintConsoleString("<:", 0);
    PrintConsoleString(debug_string, 0);
    PrintConsoleString("::", 0);
    PrintConsoleHex(check_flags);
    PrintConsoleString("::", 0);
    PrintConsoleHex(*last_ready_flags);
    PrintConsoleString("::", 0);
    PrintConsoleHex(ready_flags);
    PrintConsoleString(":>\r\n", 0);
    *last_ready_flags = ready_flags;
  }
#endif

  return ready_flags;
}

#define STATE_A_TRANSITION_DELAY 100
static uint8_t _transition_scheduled_pA = 0, _transition_scheduled_pB = 0;
#define _transition_scheduled_p(x) (*((x) ? &_transition_scheduled_pB : &_transition_scheduled_pA))

static uint32_t _transition_ev_stateA(void *param) {
  EV_STATE *next_state = (EV_STATE *)param;
  //PrintConsoleString(">T\r\n", 0);
  SetEvState(A, *next_state);
  _transition_scheduled_pA = 0;
  return 0;
}

static uint32_t _transition_ev_stateB(void *param) {
  EV_STATE *next_state = (EV_STATE *)param;
  //PrintConsoleString(">T\r\n", 0);
  SetEvState(B, *next_state);
  _transition_scheduled_pB = 0;
  return 0;
}

//this is really goofy.  consider changing
#define _transition_ev_state(x) ((x) ? _transition_ev_stateB : _transition_ev_stateA)

void DetermineEvState(uint8_t ch, DETERMINE_STATE_CODE code) {
  //uint8_t i = 0;

  static uint8_t last_ready_flagsA = 0, last_ready_flagsB = 0, *last_ready_flags_ptr;
  static EV_STATE next_state[2];

  last_ready_flags_ptr = (ch ? &last_ready_flagsB : &last_ready_flagsA);

  if (code == HIDE) {
    SetEvState(ch, EV_A);
  }

  if (code == ERROR_DETECTED) {
    SetEvState(ch, EV_E);
  }

  //    if (code == BSC_ESTABLISHED)  // Debug
  //        SetEvState(EV_LN);        // Debug

  switch (Ev_State[ch]) {
    case EV_A:
      if ((Pilot_Voltage[ch] == STATE_A) ||
          (Pilot_Voltage[ch] == STATE_B) ||
          (Pilot_Voltage[ch] == STATE_F)) {
        //SetEvState(EV_B1);

        next_state[ch] = EV_B1;

        // Note: This flag is not strictly needed since
        // schedule_if_unscheduled will not reschedule or reset
        // the delay. However, this will be faster since we
        // won't have to iterate through the whole delay table.
        if (!_transition_scheduled_p(ch)) {
          schedule_if_unscheduled(STATE_A_TRANSITION_DELAY,
                                  _transition_ev_state(ch), &next_state[ch]);
          _transition_scheduled_p(ch) = 1;
        }
      } else {
        if (_transition_scheduled_p(ch)) {
          _transition_scheduled_p(ch) = 0;
          unschedule(_transition_ev_state(ch));
        }
        SetEvState(ch, EV_E);
      }
      break;
    case EV_B1:
      update_ev_maxc_pwm(ch);
      if (code == BSC_ESTABLISHED)
        SetEvState(ch, EV_LN);
      else if (Pilot_Voltage[ch] == STATE_B && PILOT_PRESENT(ch))
        SetEvState(ch, EV_B2);
      else if (Pilot_Voltage[ch] == STATE_F || Pilot_Voltage[ch] == STATE_R)
        SetEvState(ch, EV_F1);
      break;

    case EV_B2:
      update_ev_maxc_pwm(ch);

      if (code == BSC_ESTABLISHED) {
        SetEvState(ch, EV_LN);
      } else if ((Pilot_Voltage[ch] != STATE_B) && (Pilot_Voltage[ch] != STATE_C)) {
        SetEvState(ch, EV_B1);
      }
#ifdef PWM_CHARGE_ENABLE
      else if ((Pilot_Voltage[ch] == STATE_B) &&
               (_get_ev_ready_flags(ch, _EV_READY,
                                    last_ready_flags_ptr, "B2") == _EV_READY)) {
        if (getIsLocked(ch)) {
          SetEvState(ch, EV_C2);
        } else {
          lock_if_unlocked(ch);
        }
      }
#endif
      break;
    case EV_C2:
      update_ev_maxc_pwm(ch);
      if ((_get_ev_ready_flags(ch, _EV_READY,
                              last_ready_flags_ptr, "C2") != _EV_READY) ||
                              !getIsLocked(ch)) {
        /* if (!PILOT_PRESENT) {  */
        /*     if (!PWM_present) { */
        /*     } */

        /*     if (!pilot_in_range){ */
        /*     } */
        /* }         */
        /* // FIXME: */
        /* // With Annex D, we can stay energized without charging for  */
        /* // 15 minutes. Is J1772 compatible with C2-->C1-->C2? */
        /* /\* if (ev_max_c == 0){     *\/ */
        /* /\* }        *\/ */
        /* else if (!prox_safe_to_energize) {       */
        /* } */
        if (!_transition_scheduled_p(ch)) {
          next_state[ch] = EV_B2;
          schedule_if_unscheduled(RTI_TICKS_PER_SECOND,
                                  _transition_ev_state(ch), &next_state[ch]);
          _transition_scheduled_p(ch) = 1;
        }
      } else {
        if (_transition_scheduled_p(ch)) {
          _transition_scheduled_p(ch) = 0;
          unschedule(_transition_ev_state(ch));
        }
      }
      break;
    case EV_E:
      if ((Pilot_Voltage[ch] == STATE_A) ||
          (Pilot_Voltage[ch] == STATE_B) ||
          (Pilot_Voltage[ch] == STATE_F)) {
        SetEvState(ch, EV_A);
      }
      break;
    case EV_LN:
#ifndef LIN_CHARGE_ENABLE
      ev_max_c[ch].pwm   = 0;
      ev_max_c[ch].C1_L1 = 0;
      ev_max_c[ch].C2_L2 = 0;
      ev_max_c[ch].C3_L3 = 0;
      ev_max_c[ch].C4_N  = 0;
#else
      ev_max_c[ch] = DetermineEvMaxC(ch, SeAvailAmps[ch]);
#endif
      if (code == BSC_TIMEOUT) {
        SetEvState(ch, EV_B1);
      } else if ((Pilot_Voltage[ch] == STATE_B) &&
                 (_get_ev_ready_flags(ch, _EV_READY,
                                      last_ready_flags_ptr, "LN") == _EV_READY)) {
        if (getIsLocked(ch)) {
          SetEvState(ch, EV_LR);
        } else {
          lock_if_unlocked(ch);
        }
      }
      break;

    case EV_LR:
#ifndef LIN_CHARGE_ENABLE
      ev_max_c[ch].pwm   = 0;
      ev_max_c[ch].C1_L1 = 0;
      ev_max_c[ch].C2_L2 = 0;
      ev_max_c[ch].C3_L3 = 0;
      ev_max_c[ch].C4_N  = 0;
#else
      ev_max_c[ch] = DetermineEvMaxC(ch, SeAvailAmps[ch]);
#endif
      if (code == BSC_TIMEOUT) {
        SetEvState(ch, EV_B1);
      } else if ((_get_ev_ready_flags(ch, _EV_READY,
                                     last_ready_flags_ptr, "LR") != _EV_READY) ||
                                     !getIsLocked(ch)) {
        if (!_transition_scheduled_p(ch)) {
          next_state[ch] = EV_LN;
          schedule_if_unscheduled(RTI_TICKS_PER_SECOND,
                                  _transition_ev_state(ch), &next_state[ch]);
          _transition_scheduled_p(ch) = 1;
        }
      } else {
        if (_transition_scheduled_p(ch)) {
          _transition_scheduled_p(ch) = 0;
          unschedule(_transition_ev_state(ch));
        }
      }
      break;

    case EV_F1:
      if ((Pilot_Voltage[ch] == STATE_A) || (Pilot_Voltage[ch] == STATE_B)) {
        SetEvState(ch, EV_B1);
      } else if (code == BSC_ESTABLISHED) {
        SetEvState(ch, EV_LN);
      }
      break;
  }
#pragma MESSAGE DISABLE C12056 //debug info incorrect because of optimization or inline assembler
}

void SetEvState(uint8_t ch, EV_STATE state) {
  Ev_State[ch] = state;

  /*
  PrintConsoleString("ch:",0);
  PrintConsoleHex(ch);
  PrintConsoleString(" st:",0);
  PrintConsoleHex(state);
  PrintConsoleString("\r\n",0);
  */

  if ((state != EV_C2) && (state != EV_LR)) {
    unlock_if_locked(ch); //CHECK MEEEEE!!!!!
  }

  switch (Ev_State[ch]) {
    case EV_A:
      SetStateA(ch);
      //_disable_timeout();
      //_send_status_message_p = 0;

      ev_max_c[ch].pwm   = 0; // FIXME: Find another place to put this
      ev_max_c[ch].C1_L1 = 0;
      ev_max_c[ch].C2_L2 = 0;
      ev_max_c[ch].C3_L3 = 0;
      ev_max_c[ch].C4_N  = 0;
      //$SetSCIRIE(SCI2_BUF, SCI_RIE_OFF);
      break;

    case EV_B1:
      SetStateB(ch);

      //_send_status_message_p = 0;

      //_disable_timeout();

      enable_desire_to_charge(ch, CHARGING_DISABLED_UNLOCK_REQ); //is this an OK place to put this?

      //$SetSCIRIE(SCI2_BUF, SCI_RIE_OFF);
      break;

    case EV_B2:
      SetStateB(ch);

      //$oem_evse_in_state(EVSE_STATE_PRESENT);
      //$SetSCIRIE(SCI2_BUF, SCI_RIE_OFF);
      break;

    case EV_C2:
      SetStateC(ch);

      //$oem_evse_in_state(EVSE_STATE_CHARGE);
      //$SetSCIRIE(SCI2_BUF, SCI_RIE_OFF);
      break;

    case EV_E:
      //set state B here?

      //$oem_evse_in_state(EVSE_STATE_GONE);

      ev_max_c[ch].pwm   = 0; // FIXME: Find another place to put this
      ev_max_c[ch].C1_L1 = 0;
      ev_max_c[ch].C2_L2 = 0;
      ev_max_c[ch].C3_L3 = 0;
      ev_max_c[ch].C4_N  = 0;
      //$SetSCIRIE(SCI2_BUF, SCI_RIE_OFF);
      break;

    case EV_LN:
      SetStateB(ch);
      //$oem_evse_in_state(EVSE_STATE_PRESENT);
#ifdef LIN_CHARGE_ENABLE
      //vehicle_status_struct.EvSupplyRequest = 0;
#endif
      //_send_status_message_p = 1;
      break;

    case EV_LR:
      SetStateC(ch);
      //$oem_evse_in_state(EVSE_STATE_CHARGE);
      break;

    case EV_F1:
      //$oem_evse_in_state(EVSE_STATE_PRESENT);
      (void)0; //make compiler happy with above removed

      //$SetSCIRIE(SCI2_BUF, SCI_RIE_OFF);
  }
}

typedef struct {
  uint8_t *hold_variable;
  uint32_t check_period;
  uint32_t post_hold_delay;
  EVSE_STATE state;
} hold_state_info_t;

void DetermineEvseState(uint8_t ch, DETERMINE_STATE_CODE code) {
  static uint8_t contactor_state[2] = {0, 0}, last_contactor_state[2] = {0, 0};
  contactor_state[ch] = 0; //open

  if ((Evse_State[ch] != EVSE_A0) && (Pilot_Voltage[ch] == STATE_A)) {
    /* if (Gfi_State == GFI_FAULT) { */
    /*     manual_restart_gfi = 1;  */
    /* }  */
    SetEvseState(ch, EVSE_A0);
    return;
  }

  if (code == ERROR_DETECTED) {
    SetEvseState(ch, EVSE_E0);
  } else if (code == PWM_ENABLE) {
    inhibit_StateB2[ch] = NOT_INHIBITED;
    SetEvseState(ch, EVSE_B0);
  } else if ((code == PWM_DISABLE_TILL_UNPLUG) ||
             (code == PWM_DISABLE_TILL_CLEARED)) {
#if defined(LIN_CHARGE_ENABLE) && defined(PWM_CHARGE_ENABLE)
    unschedule(DigitalSolicitationFailed(ch));
#endif
    //_disable_timeout();
    inhibit_StateB2[ch] = (code == PWM_DISABLE_TILL_UNPLUG) ? INHIBITED_TILL_UNPLUG : INHIBITED_TILL_CLEARED;
    SetEvseState(ch, EVSE_B1);
  }

  switch (Evse_State[ch]) {
    case EVSE_A0:
      if (Pilot_Voltage[ch] == STATE_B) {
        SetEvseState(ch, EVSE_B0);
      }

      // State E0 is an unplug, clear inhibit state B2
      if (inhibit_StateB2[ch] == INHIBITED_TILL_UNPLUG) {
        inhibit_StateB2[ch] = NOT_INHIBITED;
      }
      break;

    case EVSE_B0:

#ifdef LIN_CHARGE_ENABLE
      SetEvseState(ch, EVSE_LT);
#else
      SetEvseState(ch, EVSE_B1);
#endif

      break;

    case EVSE_B1:
      if (desire_to_charge_p(ch) &&
          (inhibit_StateB2[ch] == NOT_INHIBITED)) {
        SetEvseState(ch, EVSE_B2);
      }
      //_send_status_message_p = 0;
      break;
    case EVSE_B2:
      SetPilotDutyCycle(ch, evse_state[ch].duty);
      if (!desire_to_charge_p(ch) ||
          (inhibit_StateB2[ch] != NOT_INHIBITED)) {
        SetEvseState(ch, EVSE_B1);
      } else if ((pilot_check_state_C(ch, FILTER_VERY_HIGH_THRESH)) &&
                 (Negative_Pilot_Voltage[ch] == STATE_F)) {
        SetEvseState(ch, EVSE_C2);
      }
      //_send_status_message_p = 0;
      break;

    case EVSE_C2:
      contactor_state[ch] = 1; //closed
      if (!desire_to_charge_p(ch)) {
        SetEvseState(ch, EVSE_B1);
      } else if (pilot_check_state_B(ch, FILTER_HIGH_THRESH)) {
        SetEvseState(ch, EVSE_B2);
      }
      //_send_status_message_p = 0;
      break;

    case EVSE_LT: //LIN Test (check for LIN responses)
      if (code == BSC_ESTABLISHED) {
        SetEvseState(ch, EVSE_LN);
      } else if (code == BSC_FAILED) {
        SetEvseState(ch, EVSE_B1);
      }
      break;

    case EVSE_LN: //LIN Not Ready to charge
      if (LINPermitVoltage[ch] && desire_to_charge_p(ch) && pilot_check_state_C(ch, FILTER_VERY_HIGH_THRESH))
        SetEvseState(ch, EVSE_LR);
      break;

    case EVSE_LR:              //LIN Ready to charge
      contactor_state[ch] = 1; //closed
      if (!LINPermitVoltage[ch] || !desire_to_charge_p(ch) || pilot_check_state_B(ch, FILTER_HIGH_THRESH))
        SetEvseState(ch, EVSE_LN);
      break;

    case EVSE_E0:
      break;

    case EVSE_F0:
      break;

    default: //"unhandeled cases warning
      (void)0;
  }

  if (contactor_state[ch] != last_contactor_state[ch]) {
    if (ch) {
#ifdef WHITEBOARD_HARDWARE
      CONTACTOR_B_CLOSE = !contactor_state[ch];
      CHARGE_LED_B = contactor_state[ch];
#else
      CONTACTOR_B_CLOSE = contactor_state[ch];
#endif      
    } else {
#ifdef WHITEBOARD_HARDWARE
      CONTACTOR_A_CLOSE = !contactor_state[ch];
      CHARGE_LED_A = contactor_state[ch];
#else
      CONTACTOR_A_CLOSE = contactor_state[ch];
#endif      
    }
    command_contactor(ch, contactor_state[ch]);
  }
  last_contactor_state[ch] = contactor_state[ch];
}

void SetEvseState(uint8_t ch, EVSE_STATE newState) {
  Evse_State[ch] = newState;
  switch (Evse_State[ch]) {
    case EVSE_A0:
      //$LED3 = OFF;
      SetPilotDutyCycle(ch, 100);

#ifdef LIN_CHARGE_ENABLE
      //LIN_CONTROL_A_DIR = OUTPUT;
      //LIN_CONTROL_A = 0;
      DetermineLINCPState(ch, stopLIN);
#endif
      break;

    case EVSE_B1:
      //$LED3 = OFF;
      SetPilotDutyCycle(ch, 100);
#ifdef LIN_CHARGE_ENABLE
      //LIN_CONTROL_A_DIR = OUTPUT;
      //LIN_CONTROL_A = 0;
      DetermineLINCPState(ch, stopLIN);
#endif
      break;

    case EVSE_B2:
      //$LED3 = OFF;
      //RTM FIXME what should this be
      evse_set_c(&(evse_state[ch]), evse_state[ch].default_c);
      SetPilotDutyCycle(ch, evse_state[ch].duty);
      break;

    case EVSE_C2:
      //$LED3 = ON;
      (void)0; //make compiler happy with empty case
      //have we added changes to relay state machine in EVSE?
      break;

    case EVSE_E0:
      //$LED3 = OFF;
      //why would we go into this state
      SetPilotDutyCycle(ch, 255);
      break;

#ifdef LIN_CHARGE_ENABLE
    case EVSE_LT:
      //LIN_CONTROL_A_DIR = INPUT;
#ifdef PWM_CHARGE_ENABLE
      schedule_and_reset(LIN_DETECT_TIMEOUT, DigitalSolicitationFailed(ch), NULL);
#endif
      DetermineLINCPState(ch, startLIN);
      break;
#endif

    case EVSE_LN:
#if defined(LIN_CHARGE_ENABLE) && defined(PWM_CHARGE_ENABLE)
      unschedule(DigitalSolicitationFailed(ch));
#endif
      (void)0; //make the thing happy
      break;

    case EVSE_LR:
      evse_init_current(&(evse_state[ch]));
      break;

    case EVSE_F0:
      //$LED3 = OFF;
      //when do we go into this state
      SetPilotDutyCycle(ch, 0);
      break;

    default: //"unhandeled cases warning
      (void)0;
  }
}

uint32_t DelayInCurrentState() {
#ifdef EV_CONFIG
  DetermineEvState(A, DELAY_FINISHED);
#else
  DetermineEvseState(A, DELAY_FINISHED);
#endif
  return 0;
}

uint8_t InLINState(uint8_t ch) {
  if (ch) {
    return Ev_State[B] == EV_LN || Ev_State[B] == EV_LR || Evse_State[B] == EVSE_LT || Evse_State[B] == EVSE_LN || Evse_State[B] == EVSE_LR;
  } else {
    return Ev_State[A] == EV_LN || Ev_State[A] == EV_LR || Evse_State[A] == EVSE_LT || Evse_State[A] == EVSE_LN || Evse_State[A] == EVSE_LR;
  }
}

/*******************************************************
 * Lookup Functions
 ********************************************************/

uint8_t LookupPilotState(uint8_t byte_value) {
  if (byte_value > STATE_A_MIN)
    return STATE_A;
  else if ((byte_value > STATE_B_MIN) && (byte_value < STATE_B_MAX))
    return STATE_B;
  else if ((byte_value > STATE_C_MIN) && (byte_value < STATE_C_MAX))
    return STATE_C;
  else if ((byte_value > STATE_D_MIN) && (byte_value < STATE_D_MAX))
    return STATE_D;
  else if ((byte_value > STATE_E_MIN) && (byte_value < STATE_E_MAX))
    return STATE_E;
  else if ((byte_value > STATE_R_MIN) && (byte_value < STATE_R_MAX))
    return STATE_R;
  else if ((byte_value > STATE_F_MIN) && (byte_value < STATE_F_MAX))
    return STATE_F;
  else
    return STATE_I;
}

uint8_t LookupProxState(uint8_t byte_value) {

#ifdef DISABLE_PROX_CHECKING

  #ifdef TYPE_I_COUPLER
    return IEC_J1772_RELEASED;
  #else
    return IEC_63A;
  #endif

#else

  if ((byte_value >= IEC_PROX_ERROR_HIGH_MIN)) // no IEC_PROX_ERROR_HIGH_MAX because ff is already the ceiling
    return IEC_ERROR_HIGH;
  else if ((byte_value >= IEC_PROX_DISCONNECTED_MIN) && (byte_value <= IEC_PROX_DISCONNECTED_MAX))
    return IEC_DISCONNECTED;
  else if ((byte_value >= IEC_PROX_RESERVED_HIGH_MIN) && (byte_value <= IEC_PROX_RESERVED_HIGH_MAX))
    return IEC_RESERVED_HIGH;
  else if ((byte_value >= IEC_PROX_13A_MIN) && (byte_value <= IEC_PROX_13A_MAX))
    return IEC_13A;
  else if ((byte_value >= IEC_PROX_20A_MIN) && (byte_value <= IEC_PROX_20A_MAX))
    return IEC_20A;
  else if ((byte_value >= IEC_PROX_RESERVED_BUTTON_DOWN_MIN) && (byte_value <= IEC_PROX_RESERVED_BUTTON_DOWN_MAX))
    return IEC_J1772_PRESSED;
  else if ((byte_value >= IEC_PROX_32A_MIN) && (byte_value <= IEC_PROX_32A_MAX))
    return IEC_32A;
  else if ((byte_value >= IEC_PROX_RESERVED_BUTTON_UP_MIN) && (byte_value <= IEC_PROX_RESERVED_BUTTON_UP_MAX))
    return IEC_J1772_RELEASED;
  else if ((byte_value >= IEC_PROX_63A_MIN) && (byte_value <= IEC_PROX_63A_MAX))
    return IEC_63A;
  else if ((byte_value >= IEC_PROX_RESERVED_LOW_MIN) && (byte_value <= IEC_PROX_RESERVED_LOW_MAX))
    return IEC_RESERVED_LOW;
  else if (byte_value <= IEC_PROX_ERROR_LOW_MAX) // no IEC_PROX_ERROR_LOW_MIN because 00 is already the floor
    return IEC_ERROR_LOW;

#endif
}

uint8_t LookupDutyState(uint8_t duty) {
  if (3 <= duty && duty <= 7)
    return DIGITAL_DUTY;
  else if (8 <= duty && duty <= 97)
    return J1772_DUTY;
  else
    return ERROR_DUTY;
}

/*******************************************************
 * Duty Cycle
 ********************************************************/

void SetPilotDutyCycle(uint8_t ch, uint8_t duty) {
  if (duty == 0) {
    //negative 12
    SET_PWM_PIN(ch, 0);
    DisablePWM(ch);
  } else if (duty == 100) {
    //postive 12
    SET_PWM_PIN(ch, 1);
    DisablePWM(ch);
  } else if ((duty >= 6) && (duty <= 97)) {
    SetPilotDutyCycleRaw(ch, duty);
    EnablePWM(ch);
  } else {
    DisablePWM(ch);
  }
}

uint8_t duty2amps(uint8_t dc) {
  if (dc < 8) return 0;
  if (dc < 10) return 6;
  if (dc < 85) return (uint8_t)(dc * 3 / 5);
  if (dc < 97) return (uint8_t)((dc - 64) * 5 / 2);
  if (dc < 98) return 80;
  return 0; // error value
}

uint8_t amps2duty(uint8_t amp) {
  if (amp < 6) return 100; //FIXME error value
  if (amp < 50) return (uint8_t)((amp * 5) / 3);
  if (amp <= 80) return (uint8_t)(((amp * 2) / 5) + 64);
  return 100; //FIXME error value
}

/*******************************************************
 * EV Max C
 ********************************************************/

void update_ev_maxc_pwm(uint8_t ch) {
  three_phase_currents_t temp;
  if (PILOT_PRESENT(ch)) {
    temp.pwm     = duty2amps(Majority_Duty_Cycle[ch]);
    temp.C1_L1   = temp.pwm;
    temp.C2_L2   = temp.pwm;
    temp.C3_L3   = temp.pwm;
    temp.C4_N    = temp.pwm;
    ev_max_c[ch] = DetermineEvMaxC(ch, temp);
  } else { //pwm mode, but duty cycle is invalid
    ev_max_c[ch].pwm   = 0;
    ev_max_c[ch].C1_L1 = 0;
    ev_max_c[ch].C2_L2 = 0;
    ev_max_c[ch].C3_L3 = 0;
    ev_max_c[ch].C4_N  = 0;
  }
}

three_phase_currents_t DetermineEvMaxC(uint8_t ch, three_phase_currents_t evse_max_c) {
  uint8_t cordset_max_c = 255;

#ifdef EV_CONFIG //only check cordset as an EV
#ifndef TYPE_I_COUPLER 
  cordset_max_c = 0;
  switch (IEC_Prox_Voltage[ch]) {
    case IEC_13A:
      cordset_max_c = 13;
      break;
    case IEC_20A:
      cordset_max_c = 20;
      break;
    case IEC_32A:
      cordset_max_c = 32;
      break;
    case IEC_63A:
      if (Ev_State[ch] == EV_LN || Ev_State[ch] == EV_LR) { //in LIN mode, the maximum current of a "63A" cordset is governed by the LIN signals
        cordset_max_c = 255;
      } else {
        cordset_max_c = 63;
      }
      break;
    case IEC_ERROR_LOW:     //set to zero for these cases above
    case IEC_ERROR_HIGH:
    case IEC_DISCONNECTED:
    default:
      (void)0; //unhandeled cases warning
  }
#endif

#endif

  // Take the min of the EV_MAX_CURRENT_L and cordset_max_c
  if (EV_MAX_CURRENT_L < cordset_max_c) cordset_max_c = EV_MAX_CURRENT_L;

  if (cordset_max_c < evse_max_c.pwm) evse_max_c.pwm = cordset_max_c;
  if (cordset_max_c < evse_max_c.C1_L1) evse_max_c.C1_L1 = cordset_max_c;
  if (cordset_max_c < evse_max_c.C2_L2) evse_max_c.C2_L2 = cordset_max_c;
  if (cordset_max_c < evse_max_c.C3_L3) evse_max_c.C3_L3 = cordset_max_c;
  if (cordset_max_c < evse_max_c.C4_N) evse_max_c.C4_N = cordset_max_c;

#ifdef EV_CONFIG //only check prox as an EV
  if (!prox_safe_to_energize[ch] || (cordset_max_c < EV_MIN_CURRENT_L)) {          //should never be set below EV min current but set to 0 to avoid inverter faults if it does
    evse_max_c.pwm   = 0;
    evse_max_c.C1_L1 = 0;
    evse_max_c.C2_L2 = 0;
    evse_max_c.C3_L3 = 0;
    evse_max_c.C4_N  = 0;
    //$(void)oem_ramp_down();
  }
#endif

  return evse_max_c;
}

/*******************************************************
 * VEHICLE MANAGEMENT SYSTEM (VMS)
 *******************************************************/

#pragma INLINE
bool evse_present_p(uint8_t ch) {
#ifndef DISABLE_EVSE_CHECKING
  return (((Ev_State[ch] == EV_B2) ||
           (Ev_State[ch] == EV_C2) ||
           (Ev_State[ch] == EV_NN) ||
           (Ev_State[ch] == EV_NR) ||
           (Ev_State[ch] == EV_LN) ||
           (Ev_State[ch] == EV_LR)) //&&
          //ev_max_c != 0);
  );
#else
  return 1;
#endif
}

#pragma INLINE
bool charging_evse_present_p(uint8_t ch) {
#ifndef DISABLE_EVSE_CHECKING
  return (((Ev_State[ch] == EV_C2) ||
           (Ev_State[ch] == EV_NR) ||
           (Ev_State[ch] == EV_LR)) &&
          ev_max_c[ch].pwm != 0);
#else
  return 1;
#endif
}

#pragma INLINE
bool lin_evse_present_p(uint8_t ch) {
  return ((Ev_State[ch] == EV_LN) ||
          (Ev_State[ch] == EV_LR));
}

#pragma INLINE
bool evse_prox_present_p(uint8_t ch) {
  return !((IEC_Prox_Voltage[ch] == IEC_DISCONNECTED) ||
           (IEC_Prox_Voltage[ch] == IEC_ERROR_HIGH  ));  //Don't immobilize a vehicle if its inlet is disconnected.
}


#define POWER_UNAVAILABLE_SLEEP_COUNT 60 // 1 minute
uint8_t power_unavailable_sleep_p(void) {
  static int8_t count = POWER_UNAVAILABLE_SLEEP_COUNT;
  if (Ev_State[A] == EV_B1) {
    if (count <= 0) {
      return 1;
    }
    --count;
  } else {
    count = POWER_UNAVAILABLE_SLEEP_COUNT;
  }
  return 0;
}

uint32_t process_enable_pwmA(void *param) {
  PrintConsoleString("Enabling PWM A\r\n", 0);
  inhibit_StateB2[A] = NOT_INHIBITED;
  return 0;
}

uint32_t process_enable_pwmB(void *param) {
  PrintConsoleString("Enabling PWM B\r\n", 0);
  inhibit_StateB2[B] = NOT_INHIBITED;
  return 0;
}

uint32_t process_disable_pwmA(void *param) {
  uint32_t disable_pwm_duration = *((uint32_t *)param);

  if (inhibit_StateB2[A] != NOT_INHIBITED) {
    PrintConsoleString("PWM already disabled!\r\n", 0);
  } else {
    PrintConsoleString("Disabling PWM A for: ", 0);
    PrintConsoleHex((disable_pwm_duration >> 16) & 0xFFFF);
    PrintConsoleHex(disable_pwm_duration & 0xFFFF);
    PrintConsoleString("\r\n: ", 0);

    // FIXME: State B2 should only be inhibited 10 times before
    // an unplug
    if (disable_pwm_duration == 0) {
      DetermineEvseState(A, PWM_DISABLE_TILL_UNPLUG);
    } else {
      // FIXME: Should this be disable till cleared?
      DetermineEvseState(A, PWM_DISABLE_TILL_UNPLUG);
      schedule_if_unscheduled(disable_pwm_duration,
                              process_enable_pwmA, 0);
    }
  }
  return 0;
}

uint32_t process_disable_pwmB(void *param) {
  uint32_t disable_pwm_duration = *((uint32_t *)param);

  if (inhibit_StateB2[B] != NOT_INHIBITED) {
    PrintConsoleString("PWM already disabled!\r\n", 0);
  } else {
    PrintConsoleString("Disabling PWM B for: ", 0);
    PrintConsoleHex((disable_pwm_duration >> 16) & 0xFFFF);
    PrintConsoleHex(disable_pwm_duration & 0xFFFF);
    PrintConsoleString("\r\n: ", 0);

    // FIXME: State B2 should only be inhibited 10 times before
    // an unplug
    if (disable_pwm_duration == 0) {
      DetermineEvseState(B, PWM_DISABLE_TILL_UNPLUG);
    } else {
      // FIXME: Should this be disable till cleared?
      DetermineEvseState(B, PWM_DISABLE_TILL_UNPLUG);
      schedule_if_unscheduled(disable_pwm_duration,
                              process_enable_pwmB, 0);
    }
  }
  return 0;
}

/*******************************************************
 * Prox
 ********************************************************/

void ResetEVSEProxMode(void) {
  ProxSum      = 0;
  ProxSumCount = 0;
  EVSEProxMode = EVSE_LEARN_PROX;
}

void EVSELearnProx(void) {

  if (EVSEProxMode == EVSE_LEARN_PROX) {
    if (ProxSumCount >= 32) {

      //should be power of 2^5 = 32
      ProxSum = ProxSum / ProxSumCount;

      if (ProxSum > 25)
        EVSEProxValueMin = ProxSum - 25;
      else
        EVSEProxValueMin = 0;

      if (ProxSum < 230)
        EVSEProxValueMax = ProxSum + 25;
      else
        EVSEProxValueMax = 255;

      if (EVSEProxValueMin < 15)
        ResetEVSEProxMode();
      else
        EVSEProxMode = EVSE_LOCK_PROX;
    }
  }
}

uint8_t prox_safe_to_energize_filter_func(uint8_t prox_state) {
#ifdef TYPE_I_COUPLER
  return ((IEC_PROX_VOLTAGE)prox_state == IEC_J1772_RELEASED);
#else
  return (((IEC_PROX_VOLTAGE)prox_state == IEC_13A) ||
          ((IEC_PROX_VOLTAGE)prox_state == IEC_20A) ||
          ((IEC_PROX_VOLTAGE)prox_state == IEC_32A) ||
          ((IEC_PROX_VOLTAGE)prox_state == IEC_63A));
#endif
}

bool pilot_state_C_func(uint8_t pilot_state){
    return (pilot_state == STATE_C); 
}

#pragma INLINE
bool pilot_check_state_C(uint8_t ch, uint8_t threshold) {
  return filter_check_for_val(&pilot_voltage_filter[ch], TRUE, threshold, pilot_state_C_func);
}

bool pilot_state_B_func(uint8_t pilot_state){
    return (pilot_state == STATE_B); 
}

#pragma INLINE
bool pilot_check_state_B(uint8_t ch, uint8_t threshold) {
  return filter_check_for_val(&pilot_voltage_filter[ch], TRUE, threshold, pilot_state_B_func);
}

/*******************************************************
 * Arbitrary Filter Code
 ********************************************************/

uint32_t ProcessFilters() {

  int8_t neg_pilotA_voltage, pilotA_voltage, proxA_voltage, pilotA_duty;
#ifndef CH_A_ONLY
  int8_t neg_pilotB_voltage, pilotB_voltage, proxB_voltage, pilotB_duty;
#endif

  //PILOTA
  if (pilot_voltage_filter[A].needs_processing) {
    pilotA_voltage = filter_check_majority(&pilot_voltage_filter[A]);
    //SendString(&print_c2buf, "paf:", 0);
    //SendHexValue(&print_c2buf, FALSE, pilotA_voltage);
    //SendString(&print_c2buf, "\r\n", 0);
    if (pilotA_voltage != -1)
      Pilot_Voltage[A] = (PILOT_VOLTAGE)pilotA_voltage;
    pilot_voltage_filter[A].needs_processing = 0;
  }

  //NEGATIVE PILOT A
  if (pilot_voltage_neg_filter[A].needs_processing) {
    neg_pilotA_voltage = filter_check_majority(&pilot_voltage_neg_filter[A]);
    if (neg_pilotA_voltage != -1)
      Negative_Pilot_Voltage[A] = (PILOT_VOLTAGE)neg_pilotA_voltage;
    pilot_voltage_neg_filter[A].needs_processing = 0;
  }

#ifndef CH_A_ONLY
  //PILOTB
  if (pilot_voltage_filter[B].needs_processing) {
    pilotB_voltage = filter_check_majority(&pilot_voltage_filter[B]);
    if (pilotB_voltage != -1)
      Pilot_Voltage[B] = (PILOT_VOLTAGE)pilotB_voltage;
    pilot_voltage_filter[B].needs_processing = 0;
  }

  //NEGATIVE PILOT B
  if (pilot_voltage_neg_filter[B].needs_processing) {
    neg_pilotB_voltage = filter_check_majority(&pilot_voltage_neg_filter[B]);
    if (neg_pilotB_voltage != -1)
      Negative_Pilot_Voltage[B] = (PILOT_VOLTAGE)neg_pilotB_voltage;
    pilot_voltage_neg_filter[B].needs_processing = 0;
  }
#endif

  //PROX A
  if (prox_voltage_filter[A].needs_processing) {
    //Prox Voltage
    proxA_voltage = filter_check_majority(&prox_voltage_filter[A]);
    if (proxA_voltage != -1) {
      IEC_Prox_Voltage[A] = (IEC_PROX_VOLTAGE)proxA_voltage;
    }

    //Prox Safe to energize
#ifdef EV_CONFIG
    prox_safe_to_energize[A] = //this may need to change
        filter_check_for_val(&prox_voltage_filter[A], 1, FILTER_LOW_THRESH,
                             prox_safe_to_energize_filter_func);
#else
    prox_safe_to_energize[A] = 1;
#endif
    prox_voltage_filter[A].needs_processing = 0;
  }

#ifndef CH_A_ONLY
  //PROX B
  if (prox_voltage_filter[B].needs_processing) {
    //Prox Voltage
    proxB_voltage = filter_check_majority(&prox_voltage_filter[B]);
    if (proxB_voltage != -1) {
      IEC_Prox_Voltage[B] = (IEC_PROX_VOLTAGE)proxB_voltage;
    }

    //Prox Safe to energize
#ifdef EV_CONFIG
    prox_safe_to_energize[B] = //this may need to change
        filter_check_for_val(&prox_voltage_filter[B], 1, FILTER_LOW_THRESH,
                             prox_safe_to_energize_filter_func);
#else
    prox_safe_to_energize[B] = 1;
#endif
    prox_voltage_filter[B].needs_processing = 0;
  }

#endif

  /*    //PILOT IN RANGE
  if(pilot_period_filter.needs_processing){
    pilot_in_range = filter_check_for_val(&pilot_period_filter, 1, FILTER_NOM_THRESH, NULL);
    pilot_period_filter.needs_processing = 0;
  } */

  //PILOT IN RANGE
  if (pilot_period_filter[A].needs_processing) {
    pilot_in_range[A]                       = filter_check_for_val(&pilot_period_filter[A], 1, FILTER_NOM_THRESH, NULL);
    pilot_period_filter[A].needs_processing = 0;
  }

#ifndef CH_A_ONLY
  //PILOT IN RANGE
  if (pilot_period_filter[B].needs_processing) {
    pilot_in_range[B]                       = filter_check_for_val(&pilot_period_filter[B], 1, FILTER_NOM_THRESH, NULL);
    pilot_period_filter[B].needs_processing = 0;
  }
#endif

  //PilotA DUTY FILTER
  if (pilot_duty_filter[A].needs_processing) {

    //Majority Duty Cycle
    pilotA_duty = filter_check_majority(&pilot_duty_filter[A]);
    if (pilotA_duty != -1)
      Majority_Duty_Cycle[A] = pilotA_duty;

    //Pwm Present
    PWM_present[A] = (filter_check_for_val(&pilot_duty_filter[A], (uint8_t)J1772_DUTY, FILTER_NOM_THRESH, LookupDutyState));
    PWM_5duty[A]   = (filter_check_for_val(&pilot_duty_filter[A], (uint8_t)DIGITAL_DUTY, FILTER_NOM_THRESH, LookupDutyState));

    pilot_duty_filter[A].needs_processing = 0;
  }

#ifndef CH_A_ONLY
  //PilotB DUTY FILTER
  if (pilot_duty_filter[B].needs_processing) {

    //Majority Duty Cycle
    pilotB_duty = filter_check_majority(&pilot_duty_filter[B]);
    if (pilotB_duty != -1)
      Majority_Duty_Cycle[B] = pilotB_duty;

    PWM_present[B] = (filter_check_for_val(&pilot_duty_filter[B], (uint8_t)J1772_DUTY, FILTER_NOM_THRESH, LookupDutyState)); // && filter_consistent(&pilot_duty_filter, 8));
    PWM_5duty[B]   = (filter_check_for_val(&pilot_duty_filter[B], (uint8_t)DIGITAL_DUTY, FILTER_NOM_THRESH, LookupDutyState));

    pilot_duty_filter[B].needs_processing = 0;
  }
#endif

  return PROCESS_FILTERS_DELAY;
}

void filter_init(filter_t *f, uint8_t size) {
  f->index            = 0;
  f->size             = size;
  f->needs_processing = 0;
  EmptyBuffers(f->filter, size);
}

void filter_init_value(filter_t *f, uint8_t size, uint8_t value) {
  uint16_t i;
  f->index            = 0;
  f->size             = size;
  f->needs_processing = 0;
  for (i = 0; i < f->size; ++i) {
    f->filter[i] = value;
  }
}

void filter_add(filter_t *f, uint8_t val_to_add) {
  f->index            = (uint8_t)((f->index + 1) % f->size);
  f->filter[f->index] = val_to_add;
  f->needs_processing = 1;
}

uint8_t filter_check_for_val(filter_t *f, uint8_t desired_val, uint8_t num_req, uint8_t (*func)(uint8_t)) {
  uint8_t i;
  uint8_t num_found = 0;
  for (i = 0; i < (f->size); i++) {
    if (func) {
      if ((*func)((f->filter)[i]) == desired_val)
        num_found++;
    } else {
      if ((f->filter)[i] == desired_val)
        num_found++;
    }
  }
  return (num_found >= num_req);
}

int8_t filter_check_majority(filter_t *f) {

  uint8_t counter = 0;
  int8_t x;
  int8_t y = 1;

  for (x = (f->size) - 1; x >= 0; x--) {
    for (y = x; y > 0; y--) {
      if ((f->filter)[x] == (f->filter)[x - y])
        if (counter < 255) counter++;
    }
    if (counter >= ((f->size) / 2)) {
      return (f->filter)[x];
    } else
      counter = 0;
  }

  //No majority found
  return -1;
}

uint8_t filter_avg(filter_t *f) {
  uint8_t i;
  uint16_t avg = 0;
  for (i = 0; i < (f->size); i++)
    avg += (f->filter)[i];
  avg = avg / (f->size);
  return (uint8_t)avg;
}

void EmptyBuffers(unsigned char *ptr, uint16_t length) {
  uint16_t i;
  for (i = 0; i < length; i++) {
    ptr[i] = 0;
  }
}

/*******************************************************
 * Specific Filter Code
 ********************************************************/

#pragma INLINE
void Pilot_Voltage_Filter_Add(uint8_t ch, uint8_t value) {
  filter_add(&pilot_voltage_filter[ch], LookupPilotState(value));
}

#pragma INLINE
void Pilot_Voltage_Neg_Filter_Add(uint8_t ch, uint8_t value) {
  filter_add(&pilot_voltage_neg_filter[ch], LookupPilotState(value));
}

#pragma INLINE
void Pilot_Period_Filter_Add(uint8_t ch, uint8_t value) {
  filter_add(&pilot_period_filter[ch], value);
}

#pragma INLINE
void Pilot_Duty_Cycle_Filter_Add(uint8_t ch, uint8_t value) {
  filter_add(&pilot_duty_filter[ch], value);
}

#pragma INLINE
void Prox_Voltage_Filter_Add(uint8_t ch, uint8_t value) {
  filter_add(&prox_voltage_filter[ch], LookupProxState(value));
}
