#ifndef __CANBUS_H_
#define __CANBUS_H_

#include "types.h"
#include "hardware.h"


/*******************************************************
 *  Controller Area Network Interrupt (CAN)
 ********************************************************/


void InitCAN(uint8_t, uint8_t);

#define LISTEN_ONLY_MODE 1
#define NORMAL_MODE 0

#define STANDARD_IDENTIFIERS 0
#define EXTENDED_IDENTIFIERS 1


#define CAN250KBAUD 0
#define CAN500KBAUD 1
#define CAN1MBAUD 2
#define CAN20KBAUD 3 
#define CAN125KBAUD 4


extern uint8_t maxcansize;

#define CANBUFSIZE 24

typedef struct{
    uint8_t type;
    uint8_t inpos;
    uint8_t outpos;
    uint8_t diff;
    uint8_t data[CANBUFSIZE];
} can_circular_buffer;

typedef struct{
    uint32_t ID;
    uint8_t data[8];
    uint8_t length;
    uint8_t priority;
    uint16_t time_stamp;
} can_data_reg;
  
//volatile can_data_reg * const CAN0rxbuf 

bool CanBufPush(can_circular_buffer *buf, int bufsize, char in);
//bool CanBufPop(can_circular_buffer *buf, int bufsize);

#endif
