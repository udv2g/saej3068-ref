#ifndef __EVSE_SMARTS_H_
#define __EVSE_SMARTS_H_

#include "types.h"

typedef struct {
  uint8_t pwm;
  uint8_t C1_L1;
  uint8_t C2_L2;
  uint8_t C3_L3;
  uint8_t C4_N;
} three_phase_currents_t;

struct evse_state_t {
  //three_phase_currents_t min_c;
  three_phase_currents_t max_c;
  three_phase_currents_t default_c;
  three_phase_currents_t set_c;

  uint8_t command_not_received_count;
  uint16_t nominal_voltage;

  uint8_t duty;
  uint8_t ch;
};

void evse_init_defaults(uint8_t ch, struct evse_state_t *evse_state);
void EVSE_Init(struct evse_state_t *evse_state);
void evse_init_current(struct evse_state_t *evse_state);
uint32_t command_evse(struct evse_state_t *evse_state);
void evse_set_c(struct evse_state_t *evse_state, three_phase_currents_t current);
void evse_set_d(struct evse_state_t *evse_state, uint8_t current);

void InitMonitoring(void);
void InitVoltagePhases(void);
uint32_t rcd_relay_monitor(void *);
void PrintRCDTransceiverStats(void);

#endif
