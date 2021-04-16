#include "types.h"
#include "pilot.h"
#include "sci.h"
#include "hardware.h"
#include "evse_smarts.h"
#include "lin-cp.h"
#include "lock.h"

int8_t SCI2_receive_buffer[255];
uint8_t SCI2_receive_pointer = 0;
uint8_t SCI2_receive_flag    = FALSE;

uint8_t debug_gate = FALSE;
bool timebase_flag = FALSE;

/*********<Pilot**********/
PILOT_VOLTAGE Pilot_Voltage[2], Negative_Pilot_Voltage[2];
PROX_VOLTAGE Prox_Voltage[2];
IEC_PROX_VOLTAGE IEC_Prox_Voltage[2];

volatile bool pilot_in_range[2], PWM_present[2], PWM_5duty[2];

uint8_t Majority_Duty_Cycle[2];

three_phase_currents_t ev_max_c[2];
/*********Pilot>**********/

/*********<EVSE**********/
struct evse_state_t evse_state[2];
/*********EVSE>**********/

/*********<SCI**********/
circular_buffer print_c2buf;
uint8_t print_c2buf_data[BUFSIZE];
/*********SCI>**********/

/*********<LIN**********/
uint8_t LINPermitVoltage[2];
three_phase_currents_t SeAvailAmps[2];
l_u8 SeStatusVer[2] = {2, 2}, SeStatusInit[2] = {2, 2}, SeStatusOp[2] = {2, 2}; // 3 = Not Available
l_u16 SeNomVoltsLN[2] = {0xFFFF, 0xFFFF}, SeNomVoltsLL[2] = {0xFFFF, 0xFFFF};   // Not Available
l_u8 SeFrequency[2] = {254, 254}, EvFrequencies[2] = {254, 254};                // 2 is 60 Hz
/*********LIN>**********/

