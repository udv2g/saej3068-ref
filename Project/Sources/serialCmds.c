#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "types.h"
#include "hardware.h"
#include "globals.h"
#include "sci.h"
#include "config.h" //set configuration flags here NOTE: different usage from old project
#include "pilot.h"
#include "evse_smarts.h"
#include "info_code_handler.h"

#define well_formed_end(pos) (buffer[pos] == '#' || (buffer[pos] == '\r' && buffer[pos + 1] == '\n'))

void command_contactor(uint8_t ch, uint8_t state) {
#ifdef CH_A_ONLY
  int8_t xmit_buffer[] = ">C:X\r\n";
#else
  int8_t xmit_buffer[] = ">C:X:Y\r\n";
#endif

  xmit_buffer[3] = state ? 'C' : 'O';
#ifndef CH_A_ONLY
  xmit_buffer[5] = ch ? 'B' : 'A';
#endif

  PrintCmdsString(xmit_buffer, 0);
}

uint8_t char_to_hex(uint8_t input) {
  if (input >= '0' && input <= '9') {
    return input - '0';
  } else if (input >= 'A' && input <= 'F') {
    return input - 'A' + 10;
  } else {
    return 255;
  }
}

int16_t parse_Hex(uint8_t sixteens, uint8_t ones) {
  sixteens = char_to_hex(sixteens);
  ones     = char_to_hex(ones);
  if (sixteens == 255 || ones == 255) {
    return -1;
  }
  return sixteens * 16 + ones;
}

void parse_command(int8_t *buffer) {
  uint8_t tempC1, tempC2, tempC3;
  int16_t tempS1; 
#ifdef SE_CONFIG
  int16_t tempS2, tempS3, tempS4;
  three_phase_currents_t tempCts;
#endif

  if (buffer[0] == '>') {
    switch (buffer[1]) {
      case 'E':
        switch (buffer[2]) {
          case ':':
            tempS1 = parse_Hex(buffer[3], buffer[4]);
            if (tempS1 < 0) {
              PrintCmdsString(">E:02#Malformed Command 1\r\n", 0);
            } else {
              if (well_formed_end(5)) {
                PrintConsoleString("Error:", 0);
                PrintConsoleHex((uint8_t)tempS1);
                PrintConsoleString("\r\n", 0);
              } else {
                PrintCmdsString(">E:02#Malformed Command 2\r\n", 0);
              }
            }
            break;
          case 'U':
            switch (buffer[3]) {
              case ':':
                tempS1 = parse_Hex(buffer[4], buffer[5]);
                if (tempS1 < 0) {
                  PrintCmdsString(">E:02#Malformed Command 3\r\n", 0);
                } else {
                  switch (tempS1) {
                    case 0x81:
                      tempC1 = CHARGING_DISABLED_SLEEPING;
                      break;
                    case 0x82:
                      tempC1 = CHARGING_DISABLED_ON_REQUEST;
                      break;
                    case 0x83:
                      tempC1 = CHARGING_DISABLED_ERROR;
                      break;
                    case 0x84:
                      tempC1 = CHARGING_DISABLED_RCD;
                      break;
                    case 0x85:
                      tempC1 = CHARGING_DISABLED_UNLOCK_REQ;
                      break;
                    default:
                      PrintCmdsString(">E:02#Malformed Command 4\r\n", 0);
                      goto BREAKOUT; //break out of the rest of the parsing
                  }
                  switch (buffer[6]) {
                    case ':':
                      switch (buffer[7]) {
                        case 'S':
                          tempC2 = 1;
                          break;
                        case 'C':
                          tempC2 = 0;
                          break;
                        default:
                          PrintCmdsString(">E:02#Malformed Command 5\r\n", 0);
                          goto BREAKOUT; //break out of the rest of the parsing
                      }
                      break;
                    default:
                      PrintCmdsString(">E:02#Malformed Command 6\r\n", 0);
                      goto BREAKOUT; //break out of the rest of the parsing
                  }
                  if (well_formed_end(8)) {
                    if (tempC2) {
                      disable_desire_to_charge(A, tempC1);
                    } else {
                      enable_desire_to_charge(A, tempC1);
                    }
                  } else if (buffer[8] == ':') { //channel specified
                    switch (buffer[9]) {
                      case 'A':
                        tempC3 = 0;
                        break;
                      case 'B':
                        tempC3 = 1;
                        break;
                      default:
                        PrintCmdsString(">E:02#Malformed Command 7\r\n", 0);
                        goto BREAKOUT; //break out of the rest of the parsing
                    }
                    if (well_formed_end(10)) {
                      if (tempC2) {
                        disable_desire_to_charge(tempC3, tempC1);
                      } else {
                        enable_desire_to_charge(tempC3, tempC1);
                      }
                    } else {
                      PrintCmdsString(">E:02#Malformed Command 8\r\n", 0);
                    }
                  } else {
                    PrintCmdsString(">E:02#Malformed Command 9\r\n", 0);
                  }
                }
                break;
              default:
                PrintCmdsString(">E:02#Malformed Command 10\r\n", 0);
            }
            break;
          default:
            PrintCmdsString(">E:02#Malformed Command 11\r\n", 0);
        }
        break;
#ifdef SE_CONFIG
      case 'S':
        switch (buffer[2]) {
          case 'I':
            switch (buffer[3]) {
              case ':':
                tempS1 = parse_Hex(buffer[4], buffer[5]);
                tempC1 = 0;
                if (tempS1 < 0) {
                  PrintCmdsString(">E:02#Malformed Command 12\r\n", 0);
                } else {
                  tempS2 = tempS3 = tempS4 = tempS1;
                  if (well_formed_end(6)) {
                    //nothing more necessary
                  } else if (buffer[6] == ':') {
                    if ((buffer[7] == 'A' || buffer[7] == 'B') && well_formed_end(8)) {
                      tempC1 = buffer[7] - 'A'; //0 for A and 1 for B
                    } else if (buffer[9] == ':' && buffer[12] == ':') {
                      if (buffer[15] == ':' && (buffer[16] == 'A' || buffer[16] == 'B') && well_formed_end(17)) {
                        tempC1 = buffer[16] - 'A'; //0 for A and 1 for B
                      } else if (!well_formed_end(15)) {
                        PrintCmdsString(">E:02#Malformed Command 14\r\n", 0);
                        goto BREAKOUT; //break out of the rest of the parsing
                      }
                      tempS2 = parse_Hex(buffer[7], buffer[8]);
                      tempS3 = parse_Hex(buffer[10], buffer[11]);
                      tempS4 = parse_Hex(buffer[13], buffer[14]);
                      if (tempS2 < 0 || tempS3 < 0 || tempS4 < 0) {
                        PrintCmdsString(">E:02#Malformed Command 15\r\n", 0);
                        goto BREAKOUT; //break out of the rest of the parsing
                      }
                    } else {
                      PrintCmdsString(">E:02#Malformed Command 16\r\n", 0);
                      goto BREAKOUT; //break out of the rest of the parsing
                    }
                  } else {
                    PrintCmdsString(">E:02#Malformed Command 17\r\n", 0);
                    goto BREAKOUT; //break out of the rest of the parsing
                  }
                  tempCts.C1_L1 = (uint8_t)tempS1;
                  tempCts.C2_L2 = (uint8_t)tempS2;
                  tempCts.C3_L3 = (uint8_t)tempS3;
                  tempCts.C4_N  = (uint8_t)tempS4;

                  tempCts.pwm = tempCts.C1_L1;
                  if (tempCts.C2_L2 < tempCts.pwm) tempCts.pwm = tempCts.C2_L2;
                  if (tempCts.C3_L3 < tempCts.pwm) tempCts.pwm = tempCts.C3_L3;
                  if (tempCts.C4_N < tempCts.pwm) tempCts.pwm = tempCts.C4_N;

                  //printf("$$ch:%c::%x,%x,%x,%x,%x::%d,%d,%d,%d,%d\n", tempC1? 'B': 'A', tempCts.pwm, tempCts.C1_L1, tempCts.C2_L2, tempCts.C3_L3, tempCts.C4_N, tempCts.pwm, tempCts.C1_L1, tempCts.C2_L2, tempCts.C3_L3, tempCts.C4_N);
                  evse_set_c(&(evse_state[tempC1]), tempCts);
                }
                break;
              default:
                PrintCmdsString(">E:02#Malformed Command 18\r\n", 0);
            }
            break;
          default:
            PrintCmdsString(">E:02#Malformed Command 19\r\n", 0);
        }
        break;
#endif
      case 'I':
        switch(buffer[2]) {
          case 'C':
            switch(buffer[3]) {
              case ':':
                tempS1 = parse_Hex(buffer[4],buffer[5]);
                if (tempS1 < 0)  {
                  PrintCmdsString(">E:02#Malformed Command 20\r\n",0);
                } else  {
                  if (buffer[6] == ':') {
                    if  (well_formed_end(8))  {
                      tempC1 = A;
                    } else if (buffer[8] == ':') {
                      if ((buffer[9] == 'A' || buffer[9] == 'B') && well_formed_end(10))   {
                        tempC1 = buffer[9] - 'A'; //0 for A and 1 for B
                      } else  {
                        PrintCmdsString(">E:02#Malformed Command 21\r\n",0);
                        goto BREAKOUT;  //break out of the rest of the parsing
                      }
                    } else  {
                      PrintCmdsString(">E:02#Malformed Command 22\r\n",0);
                      goto BREAKOUT;  //break out of the rest of the parsing
                    }
                  } else  {
                    PrintCmdsString(">E:02#Malformed Command 23\r\n",0);
                    goto BREAKOUT;  //break out of the rest of the parsing
                  }
                }
                switch(buffer[7]) {
                  case 'S':
                    set_info_code(tempC1, (uint8_t) tempS1);
                    break;
                  case 'P':
                    set_priority_info_code(tempC1, (uint8_t) tempS1);
                    break;
                  case 'C':
                    clear_info_code(tempC1, (uint8_t) tempS1);
                    break;
                  default:
                    PrintCmdsString(">E:02#Malformed Command 24\r\n",0);
                }
                break;
              default:
                PrintCmdsString(">E:02#Malformed Command 25\r\n",0);
            }
            break;
          default:
            PrintCmdsString(">E:02#Malformed Command 26\r\n",0);
        }
        break;
      default:
        PrintCmdsString(">E:01#Invalid Command\r\n", 0);
    }
  } //else (if the received string does not start with '>') do nothing

BREAKOUT:; //; required because no statements follow
}
