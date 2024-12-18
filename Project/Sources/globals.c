#include "types.h"
#include "pilot.h"
#include "sci.h"
#include "hardware.h"
#include "evse_smarts.h"
#include "lin-cp.h"
#include "lock.h"
#include "ids_handler.h"
#include "j3072_handler.h"

int8_t SCI2_receive_buffer[255];
uint8_t SCI2_receive_pointer = 0;
uint8_t SCI2_receive_flag    = FALSE;

uint8_t debug_gate = FALSE;
bool timebase_flag = FALSE;

bool j1939_charge_desired[2] = {FALSE,FALSE};

/*********<Pilot**********/
PILOT_VOLTAGE Pilot_Voltage[2], Negative_Pilot_Voltage[2];
IEC_PROX_VOLTAGE IEC_Prox_Voltage[2];

volatile bool pilot_in_range[2], PWM_present[2], PWM_5duty[2];

uint8_t Majority_Duty_Cycle[2];

three_phase_currents_t ev_max_c[2];
bool is_single_phase = FALSE;
/*********Pilot>**********/

/*********<EVSE**********/
struct evse_state_t evse_state[2];
/*********EVSE>**********/

/*********<SCI**********/
circular_buffer print_buf;
uint8_t print_buf_data[BUFSIZE];
/*********SCI>**********/

/*********<LIN**********/
uint8_t LINPermitVoltage[2];
three_phase_currents_t SeAvailAmps[2];
l_u8 SeStatusVer[2] = {2, 2}, SeStatusInit[2] = {2, 2}, SeStatusOp[2] = {2, 2}; // 3 = Not Available
l_u16 SeNomVoltsLN[2] = {0xFFFF, 0xFFFF}, SeNomVoltsLL[2] = {0xFFFF, 0xFFFF};   // Not Available
l_u8 SeFrequency[2] = {254, 254}, EvFrequencies[2] = {254, 254};                // 2 is 60 Hz
/*********LIN>**********/


/*********<SLASH1**********/
uint8_t ev_id_status[2] = {ID_INCOMPLETE, ID_INCOMPLETE};
uint8_t se_id_status[2] = {ID_INCOMPLETE, ID_INCOMPLETE};
/*********SLASH1>**********/

/*********<SLASH2**********/
uint8_t ev_j3072_status[2] = {CERT_INCOMPLETE, CERT_INCOMPLETE};
uint8_t se_j3072_status[2] = {CERT_INCOMPLETE, CERT_INCOMPLETE};
/*********SLASH2>**********/
