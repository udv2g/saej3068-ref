#include "evse_smarts.h"
#include "pilot.h"
#include "globals.h"
#include "hardware.h"
#include "string_utils.h"

void evse_set_c(struct evse_state_t *evse_state, three_phase_currents_t current) {
  // clang-format off
  //if (current.pwm   < evse_state->min_c.pwm)    current.pwm   = evse_state->min_c.pwm;
  //if (current.C1_L1 < evse_state->min_c.C1_L1)  current.C1_L1 = evse_state->min_c.C1_L1;
  //if (current.C2_L2 < evse_state->min_c.C2_L2)  current.C2_L2 = evse_state->min_c.C2_L2;
  //if (current.C3_L3 < evse_state->min_c.C3_L3)  current.C3_L3 = evse_state->min_c.C3_L3;
  //if (current.C4_N  < evse_state->min_c.C4_N)   current.C4_N  = evse_state->min_c.C4_N;

  if (current.pwm   > evse_state->max_c.pwm)    current.pwm   = evse_state->max_c.pwm;
  if (current.C1_L1 > evse_state->max_c.C1_L1)  current.C1_L1 = evse_state->max_c.C1_L1;
  if (current.C2_L2 > evse_state->max_c.C2_L2)  current.C2_L2 = evse_state->max_c.C2_L2;
  if (current.C3_L3 > evse_state->max_c.C3_L3)  current.C3_L3 = evse_state->max_c.C3_L3;
  if (current.C4_N  > evse_state->max_c.C4_N)   current.C4_N  = evse_state->max_c.C4_N;
  // clang-format on

  evse_state->set_c = DetermineEvMaxC(evse_state->ch, current); //Cap set_c to highest allowed value

  evse_state->set_c = current;
  evse_state->duty  = amps2duty(evse_state->set_c.pwm);
  //(void)SendStatusMessage();

  //SetPilotADutyCycle(evse_state->duty);
  evse_state->command_not_received_count = 0;
}

void evse_set_d(struct evse_state_t *evse_state, uint8_t current) {
  //FIXME needs more limit checks like evse_set_c

  evse_state->command_not_received_count = 0;
}

uint32_t command_evse(struct evse_state_t *evse_state) {
  ++evse_state->command_not_received_count;
  /* If the maximum charge rate is set to a value that is
   * *NOT* equal to the default rate AND
   * and we have not received a commend from higher up for
   * the designated wait period, revert to the default rate
   */
  if (evse_state->command_not_received_count > EVSE_DECREASE_SET_C_WAIT_PERIOD) {
    evse_set_c(evse_state, evse_state->default_c);;

    PrintConsoleString("resetting to DEF_C",0);
  }

  return EVSE_MAIN_LOOP;
}

void evse_init_defaults(uint8_t ch, struct evse_state_t *evse_state) {
  //evse_state->min_c.pwm   = EVSE_MIN_C;
  //evse_state->min_c.C1_L1 = EVSE_MIN_C;
  //evse_state->min_c.C2_L2 = EVSE_MIN_C;
  //evse_state->min_c.C3_L3 = EVSE_MIN_C;
  //evse_state->min_c.C4_N  = EVSE_MIN_C;

  evse_state->max_c.pwm   = SE_MAX_CURRENT_N;    //if L and N dfffer, N should always be smaller
  evse_state->max_c.C1_L1 = SE_MAX_CURRENT_L;
  evse_state->max_c.C2_L2 = SE_MAX_CURRENT_L;
  evse_state->max_c.C3_L3 = SE_MAX_CURRENT_L;
  evse_state->max_c.C4_N  = SE_MAX_CURRENT_N;

  evse_state->default_c.pwm   = SE_MAX_CURRENT_N;
  evse_state->default_c.C1_L1 = SE_MAX_CURRENT_L;
  evse_state->default_c.C2_L2 = SE_MAX_CURRENT_L;
  evse_state->default_c.C3_L3 = SE_MAX_CURRENT_L;
  evse_state->default_c.C4_N  = SE_MAX_CURRENT_N;

  evse_state->set_c                      = evse_state->default_c; //copy entire structure
  evse_state->command_not_received_count = 0;

  evse_state->set_c = DetermineEvMaxC(evse_state->ch, evse_state->set_c); //Cap set_c to highest allowed value

  evse_state->duty = amps2duty(evse_state->set_c.pwm);
  evse_state->ch   = ch;
}

void EVSE_Init(struct evse_state_t *evse_state) {
  evse_init_current(evse_state);
}

void evse_init_current(struct evse_state_t *evse_state) {
  evse_state->set_c                      = evse_state->default_c;
  evse_state->command_not_received_count = 0;

  evse_state->set_c = DetermineEvMaxC(evse_state->ch, evse_state->set_c); //Cap set_c to highest allowed value

  evse_state->duty = amps2duty(evse_state->set_c.pwm);
}
