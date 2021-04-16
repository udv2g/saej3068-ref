/*************************************************************************************************
 * File:          string_utils.c
 * Originator:    Andrew Robbins
 * Date Created:  December 7, 2018
 * Description:   Since using the standard string library would consume a lot of space and only
 *                a few functions may be used, this file can be used to add only the neccessary
 *                functions needed and also customize certain ones to the needs of the VEL SW
 *************************************************************************************************/

#include "sci.h"
#include "string_utils.h"

/*int isalpha(char ch) {
     ch |= 0x20; // Convert to lowercase
     return ((ch >= 'a') && (ch <= 'z'));
}*/

uint8_t StringEqualsSafe(const char *string1, const char *string2, uint8_t length) {
  uint8_t i = 0;

  if (string1 == ((void *)0) || string1[0] == 0 || string2 == ((void *)0) || string2[0] == 0) {
    return 0;
  }

  for (i = 0; (string1[i] != 0 && string2[i] != 0 && i < length); i++) {
    if (string1[i] != string2[i]) {
      return 0;
    }
  }

  if (i == length && string1[i] == 0 && string2[i] == 0) {
    return 1;
  } else {
    return 0;
  }
}

uint8_t hex_to_dex(uint8_t ch) {
  uint8_t val = 0;

  if (ch >= 'a' && ch <= 'f') {
    val = 10 + ch - 'a';
  } else if (ch >= 'A' && ch <= 'F') {
    val = 10 + ch - 'A';
  } else if (ch >= '0' && ch <= '9') {
    val = ch - '0';
  }
  return val;
}

uint8_t HexToDex(uint8_t ch) {
  uint8_t val = 0;

  if (ch >= 'a' && ch <= 'f') {
    val = (uint8_t)((uint8_t)10 + (uint8_t)ch - (uint8_t)'a');
  } else if (ch >= 'A' && ch <= 'F') {
    val = (uint8_t)((uint8_t)10 + (uint8_t)ch - (uint8_t)'A');
  } else if (ch >= '0' && ch <= '9') {
    val = (uint8_t)((uint8_t)ch - (uint8_t)'0');
  } else {
    //Error invalid Hex number
    val = (uint8_t)UINT8_MAX;
  }

  return val;
}

uint8_t HexStringToInt(const char *hexString, uint8_t numHexDigits, uint32_t *const result) {
  uint32_t intResult  = 0;
  uint8_t digitResult = 0;
  uint8_t i           = 0;

  if (hexString == ((void *)0) || hexString[0] == 0 || result == ((void *)0)) {
    return 0;
  }

  for (i = 0; hexString[i] != 0 && i < numHexDigits; i++) {
    digitResult = HexToDex((uint8_t)hexString[i]);

    if (digitResult == UINT8_MAX) {
      return 0;
    }

    intResult = (intResult << 4) | digitResult;
  }

  if (i != numHexDigits) {
    return 0;
  }

  *result = intResult;

  return 1;
}

int32_t _atoi(char *src) {
  int i;
  int32_t value = 0;

  for (i = 0; src[i] != '\0'; ++i) {
    char ch = src[i];
    if ((ch >= '0') && (ch <= '9')) {
      value = (10 * value) + (ch - '0');
    } else {
      return 0;
    }
  }
  return value;
}

#define INT_DIGITS 10 /* enough for 32 bit integer */

char *itoa(int32_t intToConvert) {
  // Room for INT_DIGITS digits, - and '\0'
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1; //points to terminating '\0'

  if (intToConvert >= 0) {
    do {
      *--p = '0' + (intToConvert % 10);
      intToConvert /= 10;
    } while (intToConvert != 0);
    return p;
  } else { //intToConvert negative
    do {
      *--p = '0' - (intToConvert % 10);
      intToConvert /= 10;
    } while (intToConvert != 0);
    *--p = '-';
  }
  return p;
}

//The function that performs the conversion. Accepts a buffer with "enough space"
//and populates it with a string of hexadecimal digits.Returns the length in digits
char *uintToHexStr(uint32_t num) {
  // Room for INT_DIGITS digits, - and '\0'
  static char buff[INT_DIGITS + 1];
  static char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  int len = 0, k = 0;

  do { //for every 4 bits
    //get the equivalent hex digit
    buff[len] = hex[num & 0xF];
    len++;
    num >>= 4;
  } while (num != 0);

  //since we get the digits in the wrong order reverse the digits in the buffer
  for (; k < len / 2; k++) { //xor swapping
    buff[k] ^= buff[len - k - 1];
    buff[len - k - 1] ^= buff[k];
    buff[k] ^= buff[len - k - 1];
  }

  //null terminate the buffer and return the length in digits
  buff[len] = '\0';
  return buff;
}

/*void ChecksumOfString(const char *stringToChecksum, uint16_t stringSize, uint16_t *checksum) {
  uint16_t i;

  for (i = 0; i < stringSize; i++) {
    AccumulateCRC(stringToChecksum[i], checksum);
  }
}*/

/*uint8_t StringAppend(const char *string1, const char *string2, char *resultString, uint16_t resultStringSize) {
  int i;
  int resultIndex = 0;
  uint8_t success =  0;

  for (i = 0; string1[i] != 0 && resultIndex < resultStringSize; i++) {
    resultString[resultIndex] = string1[i];
    ++resultIndex;
  }

  for (i = 0; string2[i] != 0 && resultIndex < resultStringSize; i++) {
    resultString[resultIndex] = string2[i];
    ++resultIndex;
    success =  1;
  }

  return success;
}*/

//Simple version of snprintf with two arguments passed, one string one int
//This could be upgraded to full implementation with a byte **array for "infinite" args
uint16_t SafeNPrintf(char *buffer, uint16_t maxSize, const char *format, char *strArg, int32_t intArg) {
  uint16_t i            = 0;
  uint16_t j            = 0;
  uint16_t charsPrinted = 0;
  char *intStr;

  for (i = 0; format[i] != 0; i++) {
    if (charsPrinted < maxSize) {
      if (format[i] != '%') {
        buffer[charsPrinted] = format[i];
        ++charsPrinted;
      } else {
        ++i;
        switch (format[i]) {
          case 'c':
            if (strArg[0] != 0) {
              buffer[charsPrinted] = strArg[0];
              ++charsPrinted;
            }
            break;
          case 's':
            for (j = 0; (strArg[j] != 0 && charsPrinted < maxSize); j++) {
              buffer[charsPrinted] = strArg[j];
              ++charsPrinted;
            }
            break;
          case 'd':
            //8 bit signed
            //break;
          case 'u':
            //8 bit unsigned
            //break;
          case 'l':
            //16 bit signed
            intStr = itoa(intArg);

            for (j = 0; (intStr[j] != 0 && charsPrinted < maxSize); j++) {
              buffer[charsPrinted] = intStr[j];
              ++charsPrinted;
            }
            break;
          case 'x':
            break;
          case 'X':
            break;
          default:
            break;
        }
      }
    } else {
      break;
    }
  }

  if (charsPrinted == maxSize) {
    --charsPrinted;
  }

  buffer[charsPrinted] = 0;

  return charsPrinted;
}
