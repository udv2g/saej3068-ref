#ifndef _SERIALCMDS_H
#define _SERIALCMDS_H

#include "types.h"

#define CONT_OPEN   0
#define CONT_CLOSED 1

void command_contactor(uint8_t ch, uint8_t state);
void parse_command(int8_t *buffer);

#endif