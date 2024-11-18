/******************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2023 NXP
* ALL RIGHTS RESERVED.
* 
****************************************************************************//*!
*
* @file      lin_cfg.c
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Wed Oct 11 19:28:34 EDT 2023
*
* @brief     Common LIN configuration, data structure
*
******************************************************************************/
#include "lin_cfg.h"
#include "lin.h"
/* Mapping interface with hardware */
const lin_hardware_name lin_virtual_ifc[LIN_NUM_OF_IFCS] = {SCI0, SCI1};
/* Low level response buffer */
l_u8 lin_lld_response_buffer[LIN_NUM_OF_IFCS][10];
 /* Successful transfer flags */
l_u8 lin_successful_transfer[LIN_NUM_OF_IFCS];
/* Error in response */
l_u8 lin_error_in_response[LIN_NUM_OF_IFCS];
/* Goto sleep flag */
l_u8 lin_goto_sleep_flg[LIN_NUM_OF_IFCS];
/* Save configuration flag */
l_u8 lin_save_configuration_flg[LIN_NUM_OF_IFCS] = {0, 0};
 /* Next transmit tick */
l_u8 lin_next_transmit[LIN_NUM_OF_IFCS];
 /* lin word status */
lin_word_status_str lin_word_status[LIN_NUM_OF_IFCS];
/* current pid */
l_u8 lin_current_pid[LIN_NUM_OF_IFCS];
const l_signal_handle LI0_response_error_signal = LI0_EvResponseError;
const l_signal_handle LI1_response_error_signal = LI1_EvResponseError;

volatile l_u8 buffer_backup_data[8];
volatile l_u8            lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS];


/* definition and initialization of signal array */
l_u8    lin_pFrameBuf[LIN_FRAME_BUF_SIZE] =
{
  0xff /* 0 : 11111111 */ /* start of frame LI0_SeVersionList */
  ,0x81 /* 1 : 10000001 */  ,0x00 /* 2 : 00000000 */  ,0xff /* 3 : 11111111 */  ,0xff /* 4 : 11111111 */  ,0xff /* 5 : 11111111 */  ,0xff /* 6 : 11111111 */  ,0xff /* 7 : 11111111 */
  ,0xff /* 8 : 11111111 */ /* start of frame LI0_EvVersionList */
  ,0x80 /* 9 : 10000000 */
    ,0x00 /* 10 : 00000000 */
    ,0xff /* 11 : 11111111 */
    ,0xff /* 12 : 11111111 */
    ,0xff /* 13 : 11111111 */
    ,0xff /* 14 : 11111111 */
    ,0xff /* 15 : 11111111 */
    ,0xff /* 16 : 11111111 */ /* start of frame LI0_SeStatus */
  ,0x81 /* 17 : 10000001 */
    ,0xff /* 18 : 11111111 */
    ,0xff /* 19 : 11111111 */
    ,0xff /* 20 : 11111111 */
    ,0xff /* 21 : 11111111 */
    ,0xff /* 22 : 11111111 */
    ,0xff /* 23 : 11111111 */
    ,0xff /* 24 : 11111111 */ /* start of frame LI0_EvStatus */
  ,0x80 /* 25 : 10000000 */
    ,0xff /* 26 : 11111111 */
    ,0xff /* 27 : 11111111 */
    ,0xff /* 28 : 11111111 */
    ,0xff /* 29 : 11111111 */
    ,0xff /* 30 : 11111111 */
    ,0xff /* 31 : 11111111 */
    ,0xff /* 32 : 11111111 */ /* start of frame LI0_EvPresentCurrents */
  ,0xff /* 33 : 11111111 */
    ,0xff /* 34 : 11111111 */
    ,0xff /* 35 : 11111111 */
    ,0xff /* 36 : 11111111 */
    ,0xff /* 37 : 11111111 */
    ,0xff /* 38 : 11111111 */
    ,0xff /* 39 : 11111111 */
    ,0xff /* 40 : 11111111 */ /* start of frame LI0_SeNomVoltages */
  ,0xff /* 41 : 11111111 */
    ,0xff /* 42 : 11111111 */
    ,0xff /* 43 : 11111111 */
    ,0xff /* 44 : 11111111 */
    ,0xff /* 45 : 11111111 */
    ,0xff /* 46 : 11111111 */
    ,0xff /* 47 : 11111111 */
    ,0xff /* 48 : 11111111 */ /* start of frame LI0_SeMaxCurrents */
  ,0xff /* 49 : 11111111 */
    ,0xff /* 50 : 11111111 */
    ,0xff /* 51 : 11111111 */
    ,0xff /* 52 : 11111111 */
    ,0xff /* 53 : 11111111 */
    ,0xff /* 54 : 11111111 */
    ,0xff /* 55 : 11111111 */
    ,0xff /* 56 : 11111111 */ /* start of frame LI0_EvMaxVoltages */
  ,0xff /* 57 : 11111111 */
    ,0xff /* 58 : 11111111 */
    ,0xff /* 59 : 11111111 */
    ,0xff /* 60 : 11111111 */
    ,0xff /* 61 : 11111111 */
    ,0xff /* 62 : 11111111 */
    ,0xff /* 63 : 11111111 */
    ,0xff /* 64 : 11111111 */ /* start of frame LI0_EvMinVoltages */
  ,0xff /* 65 : 11111111 */
    ,0xff /* 66 : 11111111 */
    ,0xff /* 67 : 11111111 */
    ,0xff /* 68 : 11111111 */
    ,0xff /* 69 : 11111111 */
    ,0xff /* 70 : 11111111 */
    ,0xff /* 71 : 11111111 */
    ,0xff /* 72 : 11111111 */ /* start of frame LI0_EvMaxMinCurrents */
  ,0xff /* 73 : 11111111 */
    ,0xff /* 74 : 11111111 */
    ,0xff /* 75 : 11111111 */
    ,0xff /* 76 : 11111111 */
    ,0xff /* 77 : 11111111 */
    ,0xff /* 78 : 11111111 */
    ,0xff /* 79 : 11111111 */
    ,0xff /* 80 : 11111111 */ /* start of frame LI0_EvInfoList */
  ,0x00 /* 81 : 00000000 */
    ,0xff /* 82 : 11111111 */
    ,0xff /* 83 : 11111111 */
    ,0xff /* 84 : 11111111 */
    ,0xff /* 85 : 11111111 */
    ,0xff /* 86 : 11111111 */
    ,0xff /* 87 : 11111111 */
    ,0xff /* 88 : 11111111 */ /* start of frame LI0_SeInfoList */
  ,0x00 /* 89 : 00000000 */
    ,0xff /* 90 : 11111111 */
    ,0xff /* 91 : 11111111 */
    ,0xff /* 92 : 11111111 */
    ,0xff /* 93 : 11111111 */
    ,0xff /* 94 : 11111111 */
    ,0xff /* 95 : 11111111 */
    ,0xff /* 96 : 11111111 */ /* start of frame LI0_StErrorList */
  ,0x00 /* 97 : 00000000 */
    ,0xff /* 98 : 11111111 */
    ,0xff /* 99 : 11111111 */
    ,0xff /* 100 : 11111111 */
    ,0xff /* 101 : 11111111 */
    ,0xff /* 102 : 11111111 */
    ,0xff /* 103 : 11111111 */
    ,0xff /* 104 : 11111111 */ /* start of frame LI0_EvErrorList */
  ,0x00 /* 105 : 00000000 */
    ,0xff /* 106 : 11111111 */
    ,0xff /* 107 : 11111111 */
    ,0xff /* 108 : 11111111 */
    ,0xff /* 109 : 11111111 */
    ,0xff /* 110 : 11111111 */
    ,0xff /* 111 : 11111111 */
    ,0xff /* 112 : 11111111 */ /* start of frame LI0_SeID */
  ,0xff /* 113 : 11111111 */
    ,0xff /* 114 : 11111111 */
    ,0xff /* 115 : 11111111 */
    ,0xff /* 116 : 11111111 */
    ,0xff /* 117 : 11111111 */
    ,0xff /* 118 : 11111111 */
    ,0xff /* 119 : 11111111 */
    ,0xff /* 120 : 11111111 */ /* start of frame LI0_EvID */
  ,0xff /* 121 : 11111111 */
    ,0xff /* 122 : 11111111 */
    ,0xff /* 123 : 11111111 */
    ,0xff /* 124 : 11111111 */
    ,0xff /* 125 : 11111111 */
    ,0xff /* 126 : 11111111 */
    ,0xff /* 127 : 11111111 */
    ,0xff /* 128 : 11111111 */ /* start of frame LI0_EvModeCtrl */
  ,0xff /* 129 : 11111111 */
    ,0xff /* 130 : 11111111 */
    ,0xff /* 131 : 11111111 */
    ,0xff /* 132 : 11111111 */
    ,0xff /* 133 : 11111111 */
    ,0x00 /* 134 : 00000000 */
    ,0x00 /* 135 : 00000000 */
    ,0xff /* 136 : 11111111 */ /* start of frame LI0_SeModeCtrl */
  ,0xff /* 137 : 11111111 */
    ,0xff /* 138 : 11111111 */
    ,0xff /* 139 : 11111111 */
    ,0xff /* 140 : 11111111 */
    ,0xff /* 141 : 11111111 */
    ,0xff /* 142 : 11111111 */
    ,0xff /* 143 : 11111111 */
    ,0xff /* 144 : 11111111 */ /* start of frame LI0_EvJ3072 */
  ,0xff /* 145 : 11111111 */
    ,0xff /* 146 : 11111111 */
    ,0xff /* 147 : 11111111 */
    ,0xff /* 148 : 11111111 */
    ,0xff /* 149 : 11111111 */
    ,0xff /* 150 : 11111111 */
    ,0xff /* 151 : 11111111 */
    ,0xff /* 152 : 11111111 */ /* start of frame LI0_SeJ3072 */
  ,0xff /* 153 : 11111111 */
    ,0xff /* 154 : 11111111 */
    ,0xff /* 155 : 11111111 */
    ,0xff /* 156 : 11111111 */
    ,0xff /* 157 : 11111111 */
    ,0xff /* 158 : 11111111 */
    ,0xff /* 159 : 11111111 */
    ,0xff /* 160 : 11111111 */ /* start of frame LI0_SeTargets1 */
  ,0xff /* 161 : 11111111 */
    ,0xff /* 162 : 11111111 */
    ,0xff /* 163 : 11111111 */
    ,0xff /* 164 : 11111111 */
    ,0xff /* 165 : 11111111 */
    ,0xff /* 166 : 11111111 */
    ,0xff /* 167 : 11111111 */
    ,0xff /* 168 : 11111111 */ /* start of frame LI1_SeVersionList */
  ,0x81 /* 169 : 10000001 */
    ,0x00 /* 170 : 00000000 */
    ,0xff /* 171 : 11111111 */
    ,0xff /* 172 : 11111111 */
    ,0xff /* 173 : 11111111 */
    ,0xff /* 174 : 11111111 */
    ,0xff /* 175 : 11111111 */
    ,0xff /* 176 : 11111111 */ /* start of frame LI1_EvVersionList */
  ,0x80 /* 177 : 10000000 */
    ,0x00 /* 178 : 00000000 */
    ,0xff /* 179 : 11111111 */
    ,0xff /* 180 : 11111111 */
    ,0xff /* 181 : 11111111 */
    ,0xff /* 182 : 11111111 */
    ,0xff /* 183 : 11111111 */
    ,0xff /* 184 : 11111111 */ /* start of frame LI1_SeStatus */
  ,0x81 /* 185 : 10000001 */
    ,0xff /* 186 : 11111111 */
    ,0xff /* 187 : 11111111 */
    ,0xff /* 188 : 11111111 */
    ,0xff /* 189 : 11111111 */
    ,0xff /* 190 : 11111111 */
    ,0xff /* 191 : 11111111 */
    ,0xff /* 192 : 11111111 */ /* start of frame LI1_EvStatus */
  ,0x80 /* 193 : 10000000 */
    ,0xff /* 194 : 11111111 */
    ,0xff /* 195 : 11111111 */
    ,0xff /* 196 : 11111111 */
    ,0xff /* 197 : 11111111 */
    ,0xff /* 198 : 11111111 */
    ,0xff /* 199 : 11111111 */
    ,0xff /* 200 : 11111111 */ /* start of frame LI1_EvPresentCurrents */
  ,0xff /* 201 : 11111111 */
    ,0xff /* 202 : 11111111 */
    ,0xff /* 203 : 11111111 */
    ,0xff /* 204 : 11111111 */
    ,0xff /* 205 : 11111111 */
    ,0xff /* 206 : 11111111 */
    ,0xff /* 207 : 11111111 */
    ,0xff /* 208 : 11111111 */ /* start of frame LI1_SeNomVoltages */
  ,0xff /* 209 : 11111111 */
    ,0xff /* 210 : 11111111 */
    ,0xff /* 211 : 11111111 */
    ,0xff /* 212 : 11111111 */
    ,0xff /* 213 : 11111111 */
    ,0xff /* 214 : 11111111 */
    ,0xff /* 215 : 11111111 */
    ,0xff /* 216 : 11111111 */ /* start of frame LI1_SeMaxCurrents */
  ,0xff /* 217 : 11111111 */
    ,0xff /* 218 : 11111111 */
    ,0xff /* 219 : 11111111 */
    ,0xff /* 220 : 11111111 */
    ,0xff /* 221 : 11111111 */
    ,0xff /* 222 : 11111111 */
    ,0xff /* 223 : 11111111 */
    ,0xff /* 224 : 11111111 */ /* start of frame LI1_EvMaxVoltages */
  ,0xff /* 225 : 11111111 */
    ,0xff /* 226 : 11111111 */
    ,0xff /* 227 : 11111111 */
    ,0xff /* 228 : 11111111 */
    ,0xff /* 229 : 11111111 */
    ,0xff /* 230 : 11111111 */
    ,0xff /* 231 : 11111111 */
    ,0xff /* 232 : 11111111 */ /* start of frame LI1_EvMinVoltages */
  ,0xff /* 233 : 11111111 */
    ,0xff /* 234 : 11111111 */
    ,0xff /* 235 : 11111111 */
    ,0xff /* 236 : 11111111 */
    ,0xff /* 237 : 11111111 */
    ,0xff /* 238 : 11111111 */
    ,0xff /* 239 : 11111111 */
    ,0xff /* 240 : 11111111 */ /* start of frame LI1_EvMaxMinCurrents */
  ,0xff /* 241 : 11111111 */
    ,0xff /* 242 : 11111111 */
    ,0xff /* 243 : 11111111 */
    ,0xff /* 244 : 11111111 */
    ,0xff /* 245 : 11111111 */
    ,0xff /* 246 : 11111111 */
    ,0xff /* 247 : 11111111 */
    ,0xff /* 248 : 11111111 */ /* start of frame LI1_EvInfoList */
  ,0x00 /* 249 : 00000000 */
    ,0xff /* 250 : 11111111 */
    ,0xff /* 251 : 11111111 */
    ,0xff /* 252 : 11111111 */
    ,0xff /* 253 : 11111111 */
    ,0xff /* 254 : 11111111 */
    ,0xff /* 255 : 11111111 */
    ,0xff /* 256 : 11111111 */ /* start of frame LI1_SeInfoList */
  ,0x00 /* 257 : 00000000 */
    ,0xff /* 258 : 11111111 */
    ,0xff /* 259 : 11111111 */
    ,0xff /* 260 : 11111111 */
    ,0xff /* 261 : 11111111 */
    ,0xff /* 262 : 11111111 */
    ,0xff /* 263 : 11111111 */
    ,0xff /* 264 : 11111111 */ /* start of frame LI1_StErrorList */
  ,0x00 /* 265 : 00000000 */
    ,0xff /* 266 : 11111111 */
    ,0xff /* 267 : 11111111 */
    ,0xff /* 268 : 11111111 */
    ,0xff /* 269 : 11111111 */
    ,0xff /* 270 : 11111111 */
    ,0xff /* 271 : 11111111 */
    ,0xff /* 272 : 11111111 */ /* start of frame LI1_EvErrorList */
  ,0x00 /* 273 : 00000000 */
    ,0xff /* 274 : 11111111 */
    ,0xff /* 275 : 11111111 */
    ,0xff /* 276 : 11111111 */
    ,0xff /* 277 : 11111111 */
    ,0xff /* 278 : 11111111 */
    ,0xff /* 279 : 11111111 */
    ,0xff /* 280 : 11111111 */ /* start of frame LI1_SeID */
  ,0xff /* 281 : 11111111 */
    ,0xff /* 282 : 11111111 */
    ,0xff /* 283 : 11111111 */
    ,0xff /* 284 : 11111111 */
    ,0xff /* 285 : 11111111 */
    ,0xff /* 286 : 11111111 */
    ,0xff /* 287 : 11111111 */
    ,0xff /* 288 : 11111111 */ /* start of frame LI1_EvID */
  ,0xff /* 289 : 11111111 */
    ,0xff /* 290 : 11111111 */
    ,0xff /* 291 : 11111111 */
    ,0xff /* 292 : 11111111 */
    ,0xff /* 293 : 11111111 */
    ,0xff /* 294 : 11111111 */
    ,0xff /* 295 : 11111111 */
    ,0xff /* 296 : 11111111 */ /* start of frame LI1_EvModeCtrl */
  ,0xff /* 297 : 11111111 */
    ,0xff /* 298 : 11111111 */
    ,0xff /* 299 : 11111111 */
    ,0xff /* 300 : 11111111 */
    ,0xff /* 301 : 11111111 */
    ,0x00 /* 302 : 00000000 */
    ,0x00 /* 303 : 00000000 */
    ,0xff /* 304 : 11111111 */ /* start of frame LI1_SeModeCtrl */
  ,0xff /* 305 : 11111111 */
    ,0xff /* 306 : 11111111 */
    ,0xff /* 307 : 11111111 */
    ,0xff /* 308 : 11111111 */
    ,0xff /* 309 : 11111111 */
    ,0xff /* 310 : 11111111 */
    ,0xff /* 311 : 11111111 */
    ,0xff /* 312 : 11111111 */ /* start of frame LI1_EvJ3072 */
  ,0xff /* 313 : 11111111 */
    ,0xff /* 314 : 11111111 */
    ,0xff /* 315 : 11111111 */
    ,0xff /* 316 : 11111111 */
    ,0xff /* 317 : 11111111 */
    ,0xff /* 318 : 11111111 */
    ,0xff /* 319 : 11111111 */
    ,0xff /* 320 : 11111111 */ /* start of frame LI1_SeJ3072 */
  ,0xff /* 321 : 11111111 */
    ,0xff /* 322 : 11111111 */
    ,0xff /* 323 : 11111111 */
    ,0xff /* 324 : 11111111 */
    ,0xff /* 325 : 11111111 */
    ,0xff /* 326 : 11111111 */
    ,0xff /* 327 : 11111111 */
    ,0xff /* 328 : 11111111 */ /* start of frame LI1_SeTargets1 */
  ,0xff /* 329 : 11111111 */
    ,0xff /* 330 : 11111111 */
    ,0xff /* 331 : 11111111 */
    ,0xff /* 332 : 11111111 */
    ,0xff /* 333 : 11111111 */
    ,0xff /* 334 : 11111111 */
    ,0xff /* 335 : 11111111 */
  
};

/* definition and initialization of signal array */
l_u8    lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{
  0x00 /* 0: start of flag frame LI0_SeVersionList */
  ,0x00 /* 1: */
  ,0x00 /* 2: start of flag frame LI0_EvVersionList */
  ,0x00 /* 3: */
    ,0x00 /* 4: start of flag frame LI0_SeStatus */
  ,0x00 /* 5: start of flag frame LI0_EvStatus */
  ,0x00 /* 6: */
    ,0x00 /* 7: start of flag frame LI0_EvPresentCurrents */
  ,0x00 /* 8: start of flag frame LI0_SeNomVoltages */
  ,0x00 /* 9: start of flag frame LI0_SeMaxCurrents */
  ,0x00 /* 10: start of flag frame LI0_EvMaxVoltages */
  ,0x00 /* 11: start of flag frame LI0_EvMinVoltages */
  ,0x00 /* 12: start of flag frame LI0_EvMaxMinCurrents */
  ,0x00 /* 13: start of flag frame LI0_EvInfoList */
  ,0x00 /* 14: start of flag frame LI0_SeInfoList */
  ,0x00 /* 15: start of flag frame LI0_StErrorList */
  ,0x00 /* 16: start of flag frame LI0_EvErrorList */
  ,0x00 /* 17: start of flag frame LI0_SeID */
  ,0x00 /* 18: start of flag frame LI0_EvID */
  ,0x00 /* 19: start of flag frame LI0_EvModeCtrl */
  ,0x00 /* 20: start of flag frame LI0_SeModeCtrl */
  ,0x00 /* 21: start of flag frame LI0_EvJ3072 */
  ,0x00 /* 22: start of flag frame LI0_SeJ3072 */
  ,0x00 /* 23: start of flag frame LI0_SeTargets1 */
  ,0x00 /* 24: start of flag frame LI1_SeVersionList */
  ,0x00 /* 25: */
    ,0x00 /* 26: start of flag frame LI1_EvVersionList */
  ,0x00 /* 27: */
    ,0x00 /* 28: start of flag frame LI1_SeStatus */
  ,0x00 /* 29: start of flag frame LI1_EvStatus */
  ,0x00 /* 30: */
    ,0x00 /* 31: start of flag frame LI1_EvPresentCurrents */
  ,0x00 /* 32: start of flag frame LI1_SeNomVoltages */
  ,0x00 /* 33: start of flag frame LI1_SeMaxCurrents */
  ,0x00 /* 34: start of flag frame LI1_EvMaxVoltages */
  ,0x00 /* 35: start of flag frame LI1_EvMinVoltages */
  ,0x00 /* 36: start of flag frame LI1_EvMaxMinCurrents */
  ,0x00 /* 37: start of flag frame LI1_EvInfoList */
  ,0x00 /* 38: start of flag frame LI1_SeInfoList */
  ,0x00 /* 39: start of flag frame LI1_StErrorList */
  ,0x00 /* 40: start of flag frame LI1_EvErrorList */
  ,0x00 /* 41: start of flag frame LI1_SeID */
  ,0x00 /* 42: start of flag frame LI1_EvID */
  ,0x00 /* 43: start of flag frame LI1_EvModeCtrl */
  ,0x00 /* 44: start of flag frame LI1_SeModeCtrl */
  ,0x00 /* 45: start of flag frame LI1_EvJ3072 */
  ,0x00 /* 46: start of flag frame LI1_SeJ3072 */
  ,0x00 /* 47: start of flag frame LI1_SeTargets1 */

};

/*************************** Flag set when signal is updated ******************/
/* Diagnostic signal */
l_u8 lin_diag_signal_tbl[LIN_NUM_OF_IFCS][16];
/*****************************event trigger frame*****************************/
/* all event trigger frames for master node */


/*****************************sporadic frame*****************************/
/*all sporadic frames for master node*/
/**********************************  Frame table **********************************/
const lin_frame_struct lin_frame_tbl[LIN_NUM_OF_FRMS] ={
    { LIN_FRM_UNCD, 8, LIN_RES_SUB, 0, 0, 2   , (l_u8*)0 }
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 8, 2, 2 , (l_u8*)&LI0_response_error_signal }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 16, 4, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 24, 5, 2 , (l_u8*)&LI0_response_error_signal }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 32, 7, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 40, 8, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 48, 9, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 56, 10, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 64, 11, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 72, 12, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 80, 13, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 88, 14, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 96, 15, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 104, 16, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 112, 17, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 120, 18, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 128, 19, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 136, 20, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 144, 21, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 152, 22, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 160, 23, 1 , (l_u8*)0 }
    ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
    ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 168, 24, 2 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 176, 26, 2 , (l_u8*)&LI1_response_error_signal }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 184, 28, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 192, 29, 2 , (l_u8*)&LI1_response_error_signal }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 200, 31, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 208, 32, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 216, 33, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 224, 34, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 232, 35, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 240, 36, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 248, 37, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 256, 38, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 264, 39, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 272, 40, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 280, 41, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 288, 42, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 296, 43, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 304, 44, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 312, 45, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 320, 46, 1 , (l_u8*)0 }
    ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 328, 47, 1 , (l_u8*)0 }
    ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
    ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
  
};

/*********************************** Frame flag Initialization **********************/
l_bool lin_frame_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/**************************** Lin configuration Initialization ***********************/
/* max_response_frame_timeout = round((1.4x(10+Nx10)xTbit)/Tbase_period) + 3 */
const l_u16 lin_max_frame_res_timeout_val[LIN_NUM_OF_IFCS][8]= {
   {6, 7, 9, 10, 12, 13, 15, 16 }
  
   ,{6, 7, 9, 10, 12, 13, 15, 16}
  
};

l_u8 LI0_lin_configuration_RAM[LI0_LIN_SIZE_OF_CFG]= {0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0C, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3C, 0x3D ,0xFF};
l_u8 LI1_lin_configuration_RAM[LI1_LIN_SIZE_OF_CFG]= {0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0C, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3C, 0x3D ,0xFF};

const l_u16  LI0_lin_configuration_ROM[LI0_LIN_SIZE_OF_CFG]= {0x0000, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0C, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3C, 0x3D ,0xFFFF};
const l_u16  LI1_lin_configuration_ROM[LI1_LIN_SIZE_OF_CFG]= {0x0000, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0C, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3C, 0x3D ,0xFFFF};

static l_u16 LI0_lin_response_error_byte_offset[2] = {LIN_BYTE_OFFSET_LI0_EvResponseError_EvVersionList, LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus};

static l_u8 LI0_lin_response_error_bit_offset[2] = {LIN_BIT_OFFSET_LI0_EvResponseError_EvVersionList, LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus};

static l_u16 LI1_lin_response_error_byte_offset[2] = {LIN_BYTE_OFFSET_LI1_EvResponseError_EvVersionList, LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus};

static l_u8 LI1_lin_response_error_bit_offset[2] = {LIN_BIT_OFFSET_LI1_EvResponseError_EvVersionList, LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus};

/**************** Node attributes Initialization  ****************************/

lin_node_attribute  LI0_node_attribute = {
   LIN_PROTOCOL_21,    /*lin_protocol_version*/
   0x01,    /*configured_NAD*/
   0x01,    /*initial_NAD*/
   { 0x005B, 0x0001, 0x00FF },   /*{<supplier_id>,<function_id>,<variant>}*/
   LI0_EvResponseError,    /*<interface_name>_< response_error>*/
   2,                                 /*number of frame contain error signal*/
   LI0_lin_response_error_byte_offset,                  /*<interface_name>_< response_error>*/
   LI0_lin_response_error_bit_offset,                  /*<interface_name>_< response_error>*/
   0,    /*<num_faut_state_signal>*/
   (const l_signal_handle*)0,
   50,    /*<P2_min>*/
   0,    /*<ST_min>*/
   1000,   /*< N_As_timeout >*/
   1000  /*<N_Cr_timeout >*/
};
lin_node_attribute  LI1_node_attribute = {
   LIN_PROTOCOL_21,    /*lin_protocol_version*/
   0x01,    /*configured_NAD*/
   0x01,    /*initial_NAD*/
   { 0x005B, 0x0001, 0x00FF },   /*{<supplier_id>,<function_id>,<variant>}*/
   LI1_EvResponseError,    /*<interface_name>_< response_error>*/
   2,                                 /*number of frame contain error signal*/
   LI1_lin_response_error_byte_offset,                  /*<interface_name>_< response_error>*/
   LI1_lin_response_error_bit_offset,                  /*<interface_name>_< response_error>*/
   0,    /*<num_faut_state_signal>*/
   (const l_signal_handle*)0,
   50,    /*<P2_min>*/
   0,    /*<ST_min>*/
   1000,   /*< N_As_timeout >*/
   1000  /*<N_Cr_timeout >*/
};






/********************* Schedule table structure Initialization ***************/
const lin_schedule_struct lin_schedule_tbl[LIN_NUM_OF_SCHD_TBL] ={
   /*interface_name = LI0 */
   {0, LIN_SCH_TBL_NULL  ,(lin_schedule_data*)0 }
  
   ,{0, LIN_SCH_TBL_NULL  , (lin_schedule_data*)0 }
  
};
/********************** Schedule table status Initialization ******************/
l_u8 lin_schedule_start_entry[LIN_NUM_OF_SCHD_TBL] = {0, 0};
l_u8 lin_active_schedule_id[LIN_NUM_OF_IFCS] = {0, 0};
l_u8 lin_previous_schedule_id[LIN_NUM_OF_IFCS] = {0, 0};

l_u8 lin_diag_frame_to_send[LIN_NUM_OF_IFCS] = {0, 0};
/********************** PDU data Initialization *******************************/
lin_tl_pdu_data tx_single_pdu_data[LIN_NUM_OF_IFCS] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

};
lin_tl_pdu_data rx_single_pdu_data[LIN_NUM_OF_IFCS] = {
 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

};


/****************************Support SID Initialization ***********************/
const l_u8 LI0_lin_diag_services_supported[_LI0_DIAG_NUMBER_OF_SERVICES_] = {0xB2,0xB7,0xB0,0xB3,0xB6};
l_u8 LI0_lin_diag_services_flag[_LI0_DIAG_NUMBER_OF_SERVICES_] = {0,0,0,0,0};
const l_u8 LI1_lin_diag_services_supported[_LI1_DIAG_NUMBER_OF_SERVICES_] = {0xB2,0xB7,0xB0,0xB3,0xB6};
l_u8 LI1_lin_diag_services_flag[_LI1_DIAG_NUMBER_OF_SERVICES_] = {0,0,0,0,0};


/****************************Transport Layer Initialization ***********************/

lin_tl_descriptor lin_tl_desc[LIN_NUM_OF_IFCS] = {
   /* interface_name = LI0 */
   {
   &tx_single_pdu_data[LI0],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[LI0],          /* *pointer to receive queue on TL */
   (lin_tl_pdu_data*)0,          /* tl_current_tx_pdu_ptr */
   (lin_tl_pdu_data*)0,          /* tl_current_rx_pdu_ptr */
   /* Declaration only for Master interface */
   0,      /* tl_cnt_to_send */
   LD_SERVICE_IDLE,    /* tl_service_status */
   LD_SUCCESS,   /* tl_last_cfg_result */
   0,    /* last_RSID */
   0,    /* ld_error_code */
   (l_u8*)0,   /* *tl_ident_data */
   /* End of declaration for only Master interface */
   /* Declaration only for Slave interface */
   _LI0_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &LI0_lin_diag_services_supported,
   (l_u8*) &LI0_lin_diag_services_flag,           /* diagnostic services flags*/
   0, /* tl_slaveresp_cnt */
   /* End of declaration only for Slave interface */

   }

   /*interface_name = LI1*/
   ,{
   &tx_single_pdu_data[LI1],          /* *pointer to transmit queue on TL */
   &rx_single_pdu_data[LI1],          /* *pointer to receive queue on TL */
   (lin_tl_pdu_data*)0,          /* *tl_current_tx_pdu_ptr */
   (lin_tl_pdu_data*)0,          /* *tl_current_rx_pdu_ptr */
   /* Declaration only for Master interface */
   0,      /* tl_cnt_to_send */
   LD_SERVICE_IDLE,    /* tl_service_status */
   LD_SUCCESS,   /* tl_last_cfg_result */
   0,    /* last_RSID */
   0,    /* ld_error_code */
   (l_u8*)0,   /* *tl_ident_data */
   _LI1_DIAG_NUMBER_OF_SERVICES_,
   (l_u8*) &LI1_lin_diag_services_supported,
   (l_u8*) &LI1_lin_diag_services_flag,           /* diagnostic services flags*/
   0 /* tl_slaveresp_cnt */
   /* End of declaration for only Master interface */
   }

};

/****************************LIN interface configuration ****************************/
const lin_configuration lin_ifc_configuration[LIN_NUM_OF_IFCS] = {
   /* Interface_name = LI0 */
   {
   LIN_PROTOCOL_21,         /*lin_protocol_version */
   LIN_PROTOCOL_21,         /*lin_language_version */
   19200,            /*  baud_rate */
   _SLAVE_,                  /*  function _SLAVE_ | _MASTER_*/
   &LI0_node_attribute,             /*  node attribute */
   /* LIN data pointer */
   &lin_lld_response_buffer[LI0][0],        /*  *response_buffer */
   &lin_successful_transfer[LI0],           /*  *lin_successful_transfer */
   &lin_error_in_response[LI0],             /*  *lin_error_in_response */
   &lin_goto_sleep_flg[LI0],              /*  *goto_sleep_flg */
   &lin_current_pid[LI0],                 /*  *current_pid */
   &lin_word_status[LI0],                 /*  *word_status */
   /* Protocol */
   0,        /* timebase is not used in Slave node*/
   &lin_diag_signal_tbl[LI0][0],          /*  *diag_signal_tbl */
   23,                            /*  num_of_frames */
   0,                              /*  frame_start */
   &lin_frame_tbl[0],                                          /*  frame_tbl */
   &lin_frame_flag_tbl[0],                                       /*  *frame_flg */

   0,                                  /*  num_of_schedules */
   0,                                  /*  schedule_start */
   (const lin_schedule_struct *)0,             /* schedule_tbl */
   (l_u8*)0,        /*  *schedule_start_entry */
   (l_u8*)0,        /*  *next_transmit_tick */
   (l_u8*)0,        /*  *active_schedule_id */
   (l_u8*)0,        /*  *previous_schedule_id */
   (l_u8*)0,        /*  *diagnostic_frame_to_send */
   DIAG_NONE,    /*  diagnostic_mode */
   &LI0_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &LI0_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[LI0]
   }

   ,{
   /* interface_name = LI1 */
   LIN_PROTOCOL_21,           /*lin_protocol_version */
   LIN_PROTOCOL_21,           /*lin_language_version */
   19200,                /*  baud_rate */
   _SLAVE_,                              /*  function _SLAVE_ | _MASTER_*/
   &LI1_node_attribute,   /*  node attribute */

   /* LIN data pointer */
   &lin_lld_response_buffer[LI1][0],      /*  *response_buffer */
   &lin_successful_transfer[LI1],         /*  *lin_successful_transfer */
   &lin_error_in_response[LI1],           /*  *lin_error_in_response */
   &lin_goto_sleep_flg[LI1],            /*  *goto_sleep_flg */
   &lin_current_pid[LI1],               /*  *current_pid */
   &lin_word_status[LI1],               /*  *word_status */
   /* Protocol */
   0,                                    /* timebase is not used in Slave node*/

   &lin_diag_signal_tbl[LI1][0],       /*  diag_signal_tbl */
   23,      /*  num_of_frames */
   23,        /*  frame_start */
   &lin_frame_tbl[0],                /* frame_tbl */
   &lin_frame_flag_tbl[0],             /*frame_flg */

   0,      /*  num_of_schedules */
   0,      /*  schedule_start */
   (const lin_schedule_struct *)0,      /*  *schedule_tbl */
   (l_u8*)0,        /*  *schedule_start_entry */
   (l_u8*)0,        /*  *next_transmit_tick */
   (l_u8*)0,        /*  *active_schedule_id */
   (l_u8*)0,        /*  *previous_schedule_id */
   (l_u8*)0,        /*  *diagnostic_frame_to_send */
   DIAG_NONE,    /*  diagnostic_mode */
   &LI1_lin_configuration_RAM[0],   /*  *configuration_RAM */
   &LI1_lin_configuration_ROM[0],   /*  *configuration_ROM */
   &lin_tl_desc[LI1]
  }
 
};
/*************************** Node hardware configuration definition *************************/
/* Node hardware configuration */

#ifdef S12X
lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL]={
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI3_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI4_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI5_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
};
#else
lin_node lin_node_descrs[NUM_OF_SCI_CHANNEL]={
   {(tSCI*)SCI0_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI1_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 },
   {(tSCI*)SCI2_ADDR, 0, 0xFF, UNINIT,  0, 0,(l_u8*)0, 0x00, (l_u8*)0, 0x80, 0, 0, 0, 0 }
};
#endif


/*This ld_read_by_id_callout() function is used when the master node transmits a read by
 identifier request with an identifier in the user defined area (id from 32 to 63).
 The driver will call this function when such request is received.
 * id: the identifier in the user defined area (32 to 63)
 * data: pointer points to a data area with 5 bytes, used to give the positive response.
  Driver uses 0xFF "do not care value" for unassigned data values.
  Data length in PCI is (1 + number of assigned meaningful data values).
  Driver will take as data for all data before and including the last value in the frame that is different from 0xFF.
  PCI is 0x02-0x06, so data should have at least one value different from 0xFF.
  For example, a response frame, (NAD) (PCI) (0xF2) (0xFF) (0x00) (0xFF) (0xFF) (0xFF),
  PCI will be 0x03, since in this case driver takes all data before 0x00 and 0x00 as meaningful data,
  and values after 0x00 are do not care value.
 * return: LD_NEGATIVE_RESPONSE Respond with a negative response.
           LD_POSTIVE_RESPONSE Respond with a positive response.
           LD_ID_NO_RESPONSE The slave node will not answer.
 */
l_u8 ld_read_by_id_callout(l_ifc_handle iii, l_u8 id, l_u8 *data)
{
   l_u8 retval = LD_NEGATIVE_RESPONSE;
    const lin_configuration * conf;

    /* Get the current configuration */
    conf = (lin_configuration *)&lin_ifc_configuration[iii];

    if (conf->function == _SLAVE_)
    {
        /* Following code is an example - Real implementation is application-dependent */
        /* the handling does essentially depend on the id of the requested identifier */
        /* This example implement with ID = 32 - LIN_READ_USR_DEF_MIN */
        if (id == LIN_READ_USR_DEF_MIN)
        {
            /* id received is user defined 32 */
            data[0] = (l_u8) (id + 1);    /* Data user define */
            data[1] = (l_u8) (id + 2);    /* Data user define */
            data[2] = (l_u8) (id + 3);    /* Data user define */
            data[3] = (l_u8) (id + 4);    /* Data user define */
            data[4] = (l_u8) (id + 5);    /* Data user define */
            retval = LD_POSITIVE_RESPONSE;
        }
        else
        {
            /* other identifiers, respond with negative response by default*/
        }
    } /* End (conf->function == _SLAVE_) */
   return retval;
}