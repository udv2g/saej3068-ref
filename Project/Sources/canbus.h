#ifndef __CANBUS_H_
#define __CANBUS_H_

#include "types.h"
#include "hardware.h"


/*******************************************************
 *  Controller Area Network Interrupt (CAN)
 ********************************************************/

void InitCAN_ExtendedIDs (uint8_t * const base_address, uint8_t mode, uint8_t speed, uint32_t id_ptrn_1, uint32_t mask_ptrn_1, uint32_t id_ptrn_2, uint32_t mask_ptrn_2);
void InitCAN_StandardIDs (uint8_t * const base_address, uint8_t mode, uint8_t speed, uint16_t id_ptrn_1, uint16_t mask_ptrn_1, uint16_t id_ptrn_2, uint16_t mask_ptrn_2, uint16_t id_ptrn_3, uint16_t mask_ptrn_3, uint16_t id_ptrn_4, uint16_t mask_ptrn_4);

int8_t send_command_CAN(uint8_t * const base_address, uint8_t identifiers, uint32_t id, uint8_t *data, uint8_t msg_size);

typedef struct {
    uint32_t id;
    void *obj;
    int (*parser) (void *obj, uint8_t *buf, int offset, int buf_size);
    int (*handler) (void *obj);
    uint8_t process_message_p;
} can_msg_dispatcher_t;

uint32_t parse_message_CAN(uint8_t * const base_address, uint8_t identifiers, uint8_t table_size, can_msg_dispatcher_t* table);

#define LISTEN_ONLY_MODE 1
#define NORMAL_MODE 0

#define STANDARD_IDENTIFIERS 0
#define EXTENDED_IDENTIFIERS 1

#define CAN250KBAUD 0
#define CAN500KBAUD 1
#define CAN1MBAUD 2
#define CAN20KBAUD 3 
#define CAN125KBAUD 4


#endif
