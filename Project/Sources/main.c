#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "lin.h"
#include "types.h"
#include "hardware.h"
#include "globals.h"
#include "sci.h"
#include "config.h" //set configuration flags here NOTE: different usage from old project
#include "scheduler.h"
#include "pilot.h"
#include "evse_smarts.h"
#include "lin_cfg.h"
#include "lin-cp.h"
#include "lock.h"
#include "j1939.h"
#include "serialCmds.h"

#define FIVE_MINUTES 5 * 60 * RTI_TICKS_PER_SECOND
//#define FIVE_MINUTES 277800

uint32_t ScheduleTest(void *ptr) {
  PrintConsoleString("5 mins\r\n", 0);
  return FIVE_MINUTES;
}

uint32_t end_Init_Timeout(void *ptr) {
  enable_desire_to_charge(A, CHARGING_DISABLED_START_DELY);
  enable_desire_to_charge(B, CHARGING_DISABLED_START_DELY);
  PrintConsoleString("Startup Timeout Expiry\r\n", 0);
  return 0;
}

void main(void) {
  //uint8_t i,j;
  //uint8_t temp;

  uint8_t rising_edge_gate = TRUE, falling_edge_gate = TRUE;

  init_hardware();

#ifdef LIN_CHARGE_ENABLE
  InitializeLINCP();
#endif

  //configure all timers after LIN init to avoid register overwrite
  init_timers();

  EnableInterrupts;

  //l_sch_set(LI0,LI0_Ver, 0);

  init_delay_table();
  pilot_init();
  schedule_and_reset(FIVE_MINUTES, ScheduleTest, NULL);
  schedule_and_reset(PROCESS_FILTERS_DELAY, ProcessFilters, NULL);

#ifdef EV_CONFIG
  disable_desire_to_charge(A, CHARGING_DISABLED_START_DELY);
  disable_desire_to_charge(B, CHARGING_DISABLED_START_DELY);
#ifdef J1939_REQD_FOR_CHARGE
  disable_desire_to_charge(A, CHARGING_DISABLED_J1939);
  disable_desire_to_charge(B, CHARGING_DISABLED_J1939);
#endif
  schedule_and_reset(INITIALIZATION_DELAY, end_Init_Timeout, NULL);
#endif

  //PWM_A = 1;
  //PWM_B = 1;

  //UC_PILOT_A_STATE_C = 1;

  //DEBUG1 = 1;
  //DEBUG2 = 0;
  //DEBUG3 = 0;
  //DEBUG4 = 0;

  //EnablePWMA();
  //EnablePWMB();
  //SetPilotADutyCycleRaw(5);
  //SetPilotBDutyCycle(5);

  //(void)setPresumedUnlockedA(NULL);
  //(void)setPresumedUnlockedB(NULL);
  //lockStatus[A] = unlocked;
  //lockStatus[B] = unlocked;

  evse_init_defaults(A, &(evse_state[A]));
  evse_init_defaults(B, &(evse_state[B]));
#ifdef SE_CONFIG
  //schedule_and_reset(EVSE_MAIN_LOOP, command_evse, &evse_stateA);     //this resets if a command hasn't been received in some amount of time.  I don't think we want that
  //evse_set_c(&evse_stateA, evse_stateA.default_c);
#ifndef CH_A_ONLY
  //schedule_and_reset(EVSE_MAIN_LOOP, command_evse, &evse_stateB);     //we can't schedule the same thing twice (without modifying the scheduler).  FIXME
  //evse_set_c(&evse_stateB, evse_stateB.default_c);
#endif
#endif

#ifdef EV_CONFIG
  unlock(A);
  schedule_and_reset(LOCK_CHECK_DELAY, verifyLockAStatus, NULL);
#ifndef CH_A_ONLY
  unlock(B);
  schedule_and_reset(LOCK_CHECK_DELAY, verifyLockBStatus, NULL);
#endif
#endif

  for (;;) {
    _FEED_COP(); /* feeds the dog */

    //PTP_PTP4 = !PTP_PTP4;
    //SendString(&print_c0buf, "C\r\n", 0);
    if (SCI2_receive_flag) {

      //PrintConsoleString(SCI2_receive_buffer, 0);
      parse_command(SCI2_receive_buffer);

      SCI2_receive_flag = FALSE;
    }

    /*
    i = 255;
    j = 255;
    while(j--)  {
      while(i--);
      //PTM_PTM2 = !PTM_PTM2;
      //PTM_PTM3 = !PTM_PTM3;
    }
    */

    //execute events with lower priority than interrupts, but higher than scheduler
    if (timebase_flag) {
#ifdef EV_CONFIG
#ifdef J1939_XMIT
      populate_j1939_messages();
      send_j1939_messages();
#endif
#endif
      timebase_flag = FALSE;
    }

    process_delay_table(); //execute scheduled events

#ifdef CH_A_ONLY
    VMU_WAKEUP = evse_present_p(A);
#else
    VMU_WAKEUP = (evse_present_p(A) || evse_present_p(B));
#endif

  } /* loop forever */
  /* please make sure that you never leave main */
}
