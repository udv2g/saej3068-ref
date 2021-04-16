#ifndef __TYPES_H_
#define __TYPES_H_

#ifndef STANDALONE

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long int uint32_t;
typedef signed char int8_t;
typedef short int16_t;
typedef long int int32_t;
typedef unsigned char bool; /*unsigned 8 bit bool definition */

#define NULL ((void *)0)

/*******************************************************
 * Booleans
 ********************************************************/
#define ON  1
#define OFF 0

#define TRUE  1
#define FALSE 0

#define OUTPUT 1
#define INPUT  0

#endif

#endif
