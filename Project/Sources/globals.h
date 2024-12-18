#ifndef __GLOBALS_H_
#define __GLOBALS_H_

#include "pilot.h"
#include "sci.h"
#include "evse_smarts.h"
#include "hardware.h"
#include "lin-cp.h"

extern int8_t SCI2_receive_buffer[];
extern uint8_t SCI2_receive_pointer;
extern uint8_t SCI2_receive_flag;

extern uint8_t debug_gate;
extern bool timebase_flag;

extern bool j1939_charge_desired[2];

/*********<Pilot**********/
extern PILOT_VOLTAGE Pilot_Voltage[], Negative_Pilot_Voltage[];
extern IEC_PROX_VOLTAGE IEC_Prox_Voltage[];

extern volatile bool pilot_in_range[], PWM_present[], PWM_5duty[];

extern uint8_t Majority_Duty_Cycle[];

extern three_phase_currents_t ev_max_c[];
extern bool is_single_phase;
/*********Pilot>**********/

/*********<EVSE**********/
extern struct evse_state_t evse_state[];
/*********EVSE>**********/

/*********<SCI**********/
extern circular_buffer print_buf;
extern uint8_t print_buf_data[];
/*********SCI>**********/

/*********<LIN**********/
extern uint8_t LINPermitVoltage[2];

extern three_phase_currents_t SeAvailAmps[2];
extern l_u8 SeStatusVer[2], SeStatusInit[2], SeStatusOp[2]; // 3 = Not Available

extern l_u16 SeNomVoltsLN[2], SeNomVoltsLL[2];
extern l_u8 SeFrequency[2], EvFrequencies[2];
/*********LIN>**********/

/*********<SLASH1**********/
extern uint8_t ev_id_status[2];
extern uint8_t se_id_status[2];
/*********SLASH1>**********/

/*********<SLASH2**********/
extern uint8_t ev_j3072_status[2];
extern uint8_t se_j3072_status[2];
/*********SLASH2>**********/

#endif
