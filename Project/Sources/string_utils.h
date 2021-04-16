/*************************************************************************************************
 * File:          string_utils.h
 * Originator:    Andrew Robbins
 * Date Created:  December 7, 2018
 * Description:   Since using the standard string library would consume a lot of space and only
 *                a few functions may be used, this file can be used to add only the neccessary
 *                functions needed and also customize certain ones to the needs of the VEL SW
 *************************************************************************************************/

#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H

#include "types.h"

#define UINT8_MAX  255
#define UINT16_MAX 65535
#define INT32_MAX  2147483647

uint8_t StringEqualsSafe(const char *, const char *, uint8_t);
uint8_t hex_to_dex(uint8_t);
uint8_t HexToDex(uint8_t);
uint8_t HexStringToInt(const char *, uint8_t, uint32_t *const);
int32_t _atoi(char *);
char *itoa(int32_t);
char *uintToHexStr(uint32_t);
void AccumulateCRC(char, uint16_t *);
//uint8_t StringAppend(const char *, const char *, char *, uint16_t);
uint16_t SafeNPrintf(char *, uint16_t, const char *, char *, int32_t);

#endif
