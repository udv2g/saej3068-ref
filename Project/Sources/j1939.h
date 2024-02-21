#ifndef __J1939_H__
#define __J1939_H__

#include "types.h"

#include "pilot.h"
#include "hardware.h"
#include "j1939-signals.h"

void CAN0_RXRoutine(void);

#define CAN_ID_PTRN_1 J1939_ID_HSC1 | (J1939_CHANNEL_A_INLET_ID << 8) | J1939_ECU_ID                                                       //HSC1
#define CAN_MASK_PTRN_1 0
#ifdef CH_A_ONLY
#define CAN_ID_PTRN_2 (J1939_ID_HSS1 & J1939_ID_EVSE1AC3PL) | (J1939_ECU_ID & J1939_CHANNEL_A_INVERTER_ID)                                 //HSS1 and EVSE1AC3PL
#define CAN_MASK_PTRN_2 (J1939_ID_HSS1 ^ J1939_ID_EVSE1AC3PL)
#else
#define CAN_ID_PTRN_2 (J1939_ID_HSS1 & J1939_ID_EVSE1AC3PL) | (J1939_ECU_ID & J1939_CHANNEL_A_INVERTER_ID & J1939_CHANNEL_B_INVERTER_ID)   //HSS1 and EVSE1AC3PL for each channel
#define CAN_MASK_PTRN_2 (J1939_ID_HSS1 ^ J1939_ID_EVSE1AC3PL) | ((J1939_ECU_ID ^ J1939_CHANNEL_A_INVERTER_ID) |                             \
                                                                 (J1939_ECU_ID ^ J1939_CHANNEL_B_INVERTER_ID))
#endif

typedef enum {
    EV_MODE_UNKNOWN = 0x00,
    EV_MODE_CHARGE  = 0x01,
    EV_MODE_V2G     = 0x02,
    EV_MODE_ERROR   = 0x03,
    EV_MODE_STOP    = 0x04,
    EV_MODE_DRIVE   = 0x05,
} ev_mode_t;

enum {
    CAN_INIT_MSG_OPCODE,
    CAN_INIT_MSG_KIND,
    CAN_INIT_MSG_TYPE,
    CAN_INIT_MSG_VERSION,
    CAN_INIT_MSG_DEBUG_FLAGS,
    CAN_INIT_MSG_SIZE
};

enum can_offsets {
    CAN_OFFSET_ID0     = 0,
    CAN_OFFSET_ID1     = 1,
    CAN_OFFSET_DATA    = 4,
    CAN_OFFSET_MSG_LEN = 12
};

enum can_ids {
    CAN_ID_STATION_STATUS = 0x181,
    CAN_ID_EV_STATUS      = 0x182,
    
    CAN_ID_INBAND_DATA    = 0x2C0,
    
    CAN_ID_PPP1           = 0x481,
    CAN_ID_PPP2           = 0x482,
};

enum can_ops {
    CAN_PARAM_REQUEST         = 0x01,
    CAN_PARAM_ACK             = 0x02,
    CAN_PARAM_NACK            = 0x03,
     
    CAN_OP_INIT               = 0xA0,
    CAN_OP_MAX_RATES          = 0xC0,
    CAN_OP_EVSE_EV_CMD        = 0xC1,
    CAN_OP_EV_EVSE_CMD        = 0xC2,
    CAN_OP_EVSE_STATUS        = 0xC3,
    CAN_OP_EV_STATUS          = 0xC4,
    CAN_OP_OEM_STATUS         = 0xC5,
    CAN_OP_ID_DESC            = 0xC6,
    CAN_OP_ID_DATA            = 0xC7,
    CAN_OP_ARBITRARY_DATA     = 0xC8,
    CAN_OP_REQUEST_DEBUG_INFO = 0xC9,
    CAN_OP_SET_DEBUG_VAR      = 0xCA,
    CAN_OP_DEBUG_DATA         = 0xCB,
     
    CAN_OP_OEM_ERROR          = 0xCE,          
    CAN_OP_DISABLE_PWM        = 0xCF,
};

enum can_data_keys {
    CAN_KEY_V12BATT = 0x0001,
    CAN_KEY_TOTAL_NUMBER_OF_DEFINED_KEYS,
};

typedef struct  {
  EVSE1ACS1_t EVSE1ACS1_A;
  EVSE1ACS1_t EVSE1ACS1_B;
  HSI1_t HSI1;
  EVSE1S1_t EVSE1S1_A;
  EVSE1S1_t EVSE1S1_B;
  EVSE1ACSV_t EVSE1ACSV_A;
  EVSE1ACSV_t EVSE1ACSV_B;
  InletProxAndSeInfo_t ProxSEInfo_A;
  InletProxAndSeInfo_t ProxSEInfo_B;
  HSC1_t HSC1;
} j1939_messages_to_send_t;

typedef struct  {
  HSC1_t HSC1_A;
  HSC1_t HSC1_B;
  HSS1_t HSS1;
  EVSE1AC3PL_t EVSE1AC3PL_A;
  EVSE1AC3PL_t EVSE1AC3PL_B;
} j1939_messages_received_t;

void j1939_init_hardware(void);
void send_j1939_messages(void);
void populate_j1939_messages(void);

#endif // HEADER GUARD
