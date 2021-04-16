#ifndef _PILOT_H
#define _PILOT_H

#include "types.h"
#include "evse_smarts.h"

typedef enum { GFI_OFF,
         GFI_TRANSITIONING,
         GFI_ON,
         GFI_ERROR,
         GFI_FAULT,
         GFI_UNKNOWN,
} GFI_STATE;

typedef enum {OPEN, CLOSED} EVSE_HARDWARE_STATE;

#define LOCK_MONITOR_TIMEOUT 40

/*******************************************************
* Arbitrary Filter Code
********************************************************/

enum INHIBIT_STATEB2 {
  NOT_INHIBITED,
  INHIBITED_TILL_UNPLUG,
  INHIBITED_TILL_CLEARED
};

#define MAX_FILTER_SIZE 24
#define FILTER_CONSISTENT_TOLERANCE 25

#define PROCESS_FILTERS_DELAY 10

#define PILOT_PRESENT(ch) ((PWM_present[ch] || PWM_5duty[ch]) && pilot_in_range[ch])

#define EVSE_LEARN_PROX 0
#define EVSE_LOCK_PROX 1

#define COMM_UNINIT 0
#define COMM_INBAND 1
#define COMM_J1772 2
#define COMM_LIN_SMART_EV 3

typedef enum {
  CHARGING_ENABLED             = 0x00,
  CHARGING_DISABLED_SLEEPING   = 0x01,
  CHARGING_DISABLED_ON_REQUEST = 0x02,
  CHARGING_DISABLED_ERROR      = 0x04,
  CHARGING_DISABLED_RCD        = 0x08,
  CHARGING_DISABLED_UNLOCK_REQ = 0x10,
  CHARGING_DISABLED_START_DELY = 0x20,
  CHARGING_DISABLED_J1939      = 0x40,
} CHARGE_CONTROL;

typedef enum {STATE_A=0, STATE_B, STATE_C, STATE_D, STATE_E, STATE_F, STATE_R, STATE_I} PILOT_VOLTAGE ;

typedef enum {DISCONNECTED=0,  CONNECTED_OFF, CONNECTED_ON, ERROR} PROX_VOLTAGE;
//typedef enum {IEC_DISCONNECTED=0, IEC_13A, IEC_20A, IEC_32A, IEC_63A, IEC_RESERVED_HIGH, IEC_RESERVED_LOW, IEC_J1772_PRESSED, IEC_J1772_RELEASED, IEC_ERROR_LOW, IEC_ERROR_HIGH} IEC_PROX_VOLTAGE;
typedef enum {IEC_ERROR_LOW=0, IEC_RESERVED_LOW, IEC_63A, IEC_J1772_RELEASED, IEC_32A, IEC_J1772_PRESSED, IEC_20A, IEC_13A, IEC_RESERVED_HIGH, IEC_DISCONNECTED, IEC_ERROR_HIGH} IEC_PROX_VOLTAGE;

typedef enum {EVGP_INIT=0, EVGP_A, EVGP_B, EVGP_C, EVGP_E, EVGP_F} EV_GEN_PILOT_STATE;
// FIXME: Add high speed communication states
typedef enum {EV_A=0, EV_B1, EV_B2, EV_C2, EV_E, EV_LN, EV_LR, EV_NN, EV_NR, EV_F1} EV_STATE;
typedef enum {EVSE_A0=0, EVSE_B0, EVSE_B1, EVSE_N5, EVSE_B2, EVSE_C2, EVSE_E0, EVSE_F0, EVSE_LT, EVSE_LN, EVSE_LR, EVSE_NT, EVSE_NN, EVSE_NR} EVSE_STATE;

typedef enum {NO_DUTY=0, DIGITAL_DUTY=1, J1772_DUTY=2, ERROR_DUTY=3} DUTY_STATE;

typedef enum {
  NO_CODE=0,
  ERROR_DETECTED,
  BSC_ESTABLISHED,
  BSC_FAILED,
  BSC_TIMEOUT,
  DELAY_FINISHED,
  HIDE,
  PWM_DISABLE_TILL_UNPLUG,
  PWM_DISABLE_TILL_CLEARED,
  PWM_ENABLE,
} DETERMINE_STATE_CODE;



/*******************************************************
 * Initialization
 ********************************************************/

void pilot_init(void);
void init_communication_structs(void);

/*******************************************************
 * Desire to Charge
 ********************************************************/

bool desire_to_charge_p(uint8_t);
void disable_desire_to_charge (uint8_t ch, CHARGE_CONTROL cause);
void enable_desire_to_charge (uint8_t ch, CHARGE_CONTROL cause);

/*******************************************************
 * Communication
 ********************************************************/

#define DELAY_BETWEEN_SOLICITATIONS 5
#define DELAY_BETWEEN_STATUS_MESSAGES 5

uint32_t SendStatusMessage(void);
void check_for_timeouts(void);

uint32_t DigitalCommunicationTimeout(void);
uint32_t DigitalSolicitation(void *);
uint32_t DigitalSolicitationFailed(void *);
bool inband_comm_established_p(void);

/*******************************************************
 * State Machine
 ********************************************************/

#define B0_DELAY 250

void DetermineEvState(uint8_t, DETERMINE_STATE_CODE);

void SetEvState(uint8_t, EV_STATE);

void DetermineEvseState(uint8_t ch, DETERMINE_STATE_CODE);

void SetEvseState(uint8_t ch, EVSE_STATE);

uint32_t DelayInCurrentState(void);

uint8_t InLINState(uint8_t ch);

/*******************************************************
 * Lookup Functions
 ********************************************************/

uint8_t LookupPilotState(uint8_t);
uint8_t LookupProxState(uint8_t);
uint8_t LookupDutyState(uint8_t);

/*******************************************************
 * Duty Cycle
 ********************************************************/

uint8_t duty2amps(uint8_t);
uint8_t amps2duty(uint8_t);

/*******************************************************
 * EV Max C
 ********************************************************/

void update_ev_maxc_pwm(uint8_t);
three_phase_currents_t DetermineEvMaxC(uint8_t, three_phase_currents_t);

/*******************************************************
 * VEHICLE MANAGEMENT SYSTEM (VMS)
 ********************************************************/

bool evse_present_p (uint8_t);
bool charging_evse_present_p (uint8_t);
bool lin_evse_present_p (uint8_t ch);
bool evse_prox_present_p (uint8_t);
uint32_t process_disable_pwm (void *param);
uint8_t power_unavailable_sleep_p(void);

/*******************************************************
 * Pilot
 ********************************************************/
 
bool pilot_check_state_C(uint8_t ch, uint8_t threshold);
bool pilot_check_state_B(uint8_t ch, uint8_t threshold);

/*******************************************************
 * Prox
 ********************************************************/

void ResetEVSEProxMode(void);
void EVSELearnProx(void);
uint8_t prox_safe_to_energize_filter_func(uint8_t prox_state);

/*******************************************************
 * Input Capture Interrupt
 ********************************************************/

/*******************************************************
 * Arbitrary Filter Code
 ********************************************************/

#define MAX_FILTER_SIZE 24
#define FILTER_CONSISTENT_TOLERANCE 25

typedef struct filter {
  uint8_t index;
  uint8_t size;
  uint8_t needs_processing;
  uint8_t filter[MAX_FILTER_SIZE];
} filter_t;

void filter_init(filter_t*, uint8_t);
void filter_init_value(filter_t* f, uint8_t size, uint8_t value);
void filter_add(filter_t*, uint8_t);
uint8_t filter_check_for_val(filter_t*, uint8_t, uint8_t, uint8_t(*)(uint8_t));
int8_t filter_check_majority(filter_t*);
uint8_t filter_avg(filter_t*);
void EmptyBuffers(unsigned char *ptr, uint16_t length);
uint32_t ProcessFilters();
void SetPilotDutyCycle(uint8_t ch, uint8_t duty);

/*******************************************************
 * Specific Filter Code
 ********************************************************/
 
void Pilot_Voltage_Filter_Add(uint8_t ch, uint8_t value);
void Pilot_Voltage_Neg_Filter_Add(uint8_t ch, uint8_t value);
void Pilot_Period_Filter_Add(uint8_t ch, uint8_t value);
void Pilot_Duty_Cycle_Filter_Add(uint8_t ch, uint8_t value);
void Prox_Voltage_Filter_Add(uint8_t ch, uint8_t value); 


/*******************************************************
 * Status and current limits of the charging station
 ********************************************************/

typedef struct {
    /* Bit 7: boolean, EVSE ready to supply power  
     * (False=not ready, True=ready) */
    unsigned int SeSupplyReadyStatus     : 1;
    /* Bit 6: boolean, EVSE available 
     * (False=not available, True=available) */
    unsigned int SeAvailabilityStatus     : 1;
    /* Bit 5: boolean, ventilation active
     * (False=not active, True=active) */
    unsigned int SeVentilationStatus : 1;
    /* Bit 4: boolean, higher level communication required 
     * (false=not required, true=required). */ 
    unsigned int SeHighLevelCommunicationRequest : 1;  
    /* Bit 3: boolean, charging delayed 
     * (false=not active, true=active). */ 
    unsigned int SeDelayStatus : 1;      
    /* Bit 2: boolean, solicit response
     * (true = request EV to respond with a EvMessage1 
     */
    unsigned int SeSolicitResponse : 1;
    /* Bits 1 and 0: void3, reserved, these bits shall be set to 0. */
    unsigned int reserved : 2;
    
    /* Each MaxCurrent value indicates the maximum current for one phase. 
     * Resolution is 1A (range: 0A to 80A). Values above 80A are reserved 
     * and shall not be used. Unavailable phases shall be set to 0. These 
     * MaxCurrent values implement Table D.2 line 9.
     */
    uint8_t SeCurrent1LimitCommand;
    uint8_t SeCurrent2LimitCommand;
    uint8_t SeCurrent3LimitCommand;
} st_station_t;


/*******************************************************
 * Status of the EV
 ********************************************************/

typedef struct {
    /* Bit 7: boolean, EV ready to receive power
     * (False=not ready, True=ready) */
    unsigned int EvSupplyRequest     : 1;    
    /* Bit 6: boolean, ventilation request 
     * (false=not requested, true=request) */
    unsigned int EvVentilationRequest : 1;     
    /* Bit 5: boolean
     * (False=not active, True=active) */
    unsigned int EvDelayClearRequest     : 1;
    /* Bit 4: boolean
     * (False=not active, True=active) */
    unsigned int EvDelayAllowRequest     : 1;             
    /* bit 3 to 0: void4, reserved, these bits shall be set to 0. */
    unsigned int reserved : 4;

    /* Each NomCurrent value indicates the nominal current for one phase. 
     * Resolution is 1A (range: 0A to 80A). Values above 80A are reserved and 
     * shall not be used. Phases that are not used shall be set to 0. */
    uint8_t EvCurrent1Nominal;
    uint8_t EvCurrent2Nominal;
    uint8_t EvCurrent3Nominal;    
} st_vehicle_t;

#endif