/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2021 NXP
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file      lin_cfg.h
*
* @author    FPT Software
*
* @version   1.0
*
* @date      Sat Feb 27 14:28:09 EST 2021
*
* @brief     Hardware configuration file
*
******************************************************************************/
#ifndef    _LIN_CFG_H_
#define    _LIN_CFG_H_
#include "lin_hw_cfg.h"
/* Define operating mode */
#define _MASTER_MODE_     0
#define _SLAVE_MODE_      1
#define LIN_MODE   _MASTER_MODE_
/* Define protocol version */
#define PROTOCOL_21       0
#define PROTOCOL_J2602    1
#define PROTOCOL_20       2
#define LIN_PROTOCOL    PROTOCOL_21
#define LIN_NUM_OF_IFCS  2     /* For master */
/**********************************************************************/
/***************          Diagnostic class selection  *****************/
/**********************************************************************/
#define _DIAG_CLASS_I_          0
#define _DIAG_CLASS_II_         1
#define _DIAG_CLASS_III_        2

#define _DIAG_CLASS_SUPPORT_    _DIAG_CLASS_I_

#define MAX_LENGTH_SERVICE 8

#define MAX_QUEUE_SIZE 2

#define _LI0_DIAG_NUMBER_OF_SERVICES_    5
#define LI0_DIAGSRV_READ_BY_IDENTIFIER_ORDER    0
#define LI0_DIAGSRV_ASSIGN_FRAME_ID_RANGE_ORDER    1
#define LI0_DIAGSRV_ASSIGN_NAD_ORDER    2
#define LI0_DIAGSRV_CONDITIONAL_CHANGE_NAD_ORDER    3
#define LI0_DIAGSRV_SAVE_CONFIGURATION_ORDER    4

#define _LI1_DIAG_NUMBER_OF_SERVICES_    5
#define LI1_DIAGSRV_READ_BY_IDENTIFIER_ORDER    0
#define LI1_DIAGSRV_ASSIGN_FRAME_ID_RANGE_ORDER    1
#define LI1_DIAGSRV_ASSIGN_NAD_ORDER    2
#define LI1_DIAGSRV_CONDITIONAL_CHANGE_NAD_ORDER    3
#define LI1_DIAGSRV_SAVE_CONFIGURATION_ORDER    4


/**************** FRAME SUPPORT DEFINITION ******************/
#define _TL_SINGLE_FRAME_       0
#define _TL_MULTI_FRAME_        1

#define _TL_FRAME_SUPPORT_      _TL_SINGLE_FRAME_

/* frame buffer size */
#define LIN_FRAME_BUF_SIZE          240
#define LIN_FLAG_BUF_SIZE           36

/**********************************************************************/
/***************               Interfaces           *******************/
/**********************************************************************/
typedef enum {
   LI0, LI1
}l_ifc_handle;

/**********************************************************************/
/***************               Signals              *******************/
/**********************************************************************/
/* Number of signals */
#define LIN_NUM_OF_SIGS  176
/* List of signals */
typedef enum {
   /* Interface_name = LI0 */
   LI0_EvSelectedVersion
   , LI0_EvResponseError
    , LI0_EvStatusVer
    , LI0_EvStatusInit
    , LI0_EvStatusOp
    , LI0_EvAwake
    , LI0_EvVersionPageNumber
    , LI0_EvSupportedVersion1
    , LI0_EvSupportedVersion2
    , LI0_EvSupportedVersion3
    , LI0_EvSupportedVersion4
    , LI0_EvSupportedVersion5
    , LI0_EvRequestedCurrentL1
    , LI0_EvRequestedCurrentL2
    , LI0_EvRequestedCurrentL3
    , LI0_EvRequestedCurrentN
    , LI0_SeSelectedVersion
    , LI0_SeStatusVer
    , LI0_SeStatusInit
    , LI0_SeStatusOp
    , LI0_SeVersionPageNumber
    , LI0_SeSupportedVersion1
    , LI0_SeSupportedVersion2
    , LI0_SeSupportedVersion3
    , LI0_SeSupportedVersion4
    , LI0_SeSupportedVersion5
    , LI0_SeAvailableCurrentL1
    , LI0_SeAvailableCurrentL2
    , LI0_SeAvailableCurrentL3
    , LI0_SeAvailableCurrentN
    , LI0_EvPresentCurrentL1
    , LI0_EvPresentCurrentL2
    , LI0_EvPresentCurrentL3
    , LI0_EvPresentCurrentN
    , LI0_SeNomVoltageL1N
    , LI0_SeNomVoltageLL
    , LI0_SeFrequency
    , LI0_SeMaxCurrentL1
    , LI0_SeMaxCurrentL2
    , LI0_SeMaxCurrentL3
    , LI0_SeMaxCurrentN
    , LI0_EvMaxVoltageL1N
    , LI0_EvMaxVoltageLL
    , LI0_EvFrequencies
    , LI0_EvMinVoltageL1N
    , LI0_EvMinVoltageLL
    , LI0_EvMaxCurrentL1
    , LI0_EvMaxCurrentL2
    , LI0_EvMaxCurrentL3
    , LI0_EvMaxCurrentN
    , LI0_EvMinCurrentL1
    , LI0_EvMinCurrentL2
    , LI0_EvMinCurrentL3
    , LI0_EvInfoEntry1
    , LI0_EvInfoEntry2
    , LI0_EvInfoEntry3
    , LI0_EvInfoEntry4
    , LI0_EvInfoEntry5
    , LI0_EvInfoEntry6
    , LI0_SeInfoEntry1
    , LI0_SeInfoEntry2
    , LI0_SeInfoEntry3
    , LI0_SeInfoEntry4
    , LI0_SeInfoEntry5
    , LI0_SeInfoEntry6
    , LI0_EvInfoPageNumber
    , LI0_SeInfoPageNumber
    , LI0_CaVersion
    , LI0_CaResponseError
    , LI0_CaMaxVoltage
    , LI0_CaMaxCurrentL1
    , LI0_CaMaxCurrentL2
    , LI0_CaMaxCurrentL3
    , LI0_CaMaxCurrentN
    , LI0_StErrorPageNumber
    , LI0_StErrorCode1
    , LI0_StErrorCode2
    , LI0_StErrorCode3
    , LI0_StErrorCode4
    , LI0_StErrorCode5
    , LI0_StErrorCode6
    , LI0_EvErrorPageNumber
    , LI0_EvErrorCode1
    , LI0_EvErrorCode2
    , LI0_EvErrorCode3
    , LI0_EvErrorCode4
    , LI0_EvErrorCode5
    , LI0_EvErrorCode6
  
   /* Interface_name = LI1 */
   , LI1_EvSelectedVersion
    , LI1_EvResponseError
    , LI1_EvStatusVer
    , LI1_EvStatusInit
    , LI1_EvStatusOp
    , LI1_EvAwake
    , LI1_EvVersionPageNumber
    , LI1_EvSupportedVersion1
    , LI1_EvSupportedVersion2
    , LI1_EvSupportedVersion3
    , LI1_EvSupportedVersion4
    , LI1_EvSupportedVersion5
    , LI1_EvRequestedCurrentL1
    , LI1_EvRequestedCurrentL2
    , LI1_EvRequestedCurrentL3
    , LI1_EvRequestedCurrentN
    , LI1_SeSelectedVersion
    , LI1_SeStatusVer
    , LI1_SeStatusInit
    , LI1_SeStatusOp
    , LI1_SeVersionPageNumber
    , LI1_SeSupportedVersion1
    , LI1_SeSupportedVersion2
    , LI1_SeSupportedVersion3
    , LI1_SeSupportedVersion4
    , LI1_SeSupportedVersion5
    , LI1_SeAvailableCurrentL1
    , LI1_SeAvailableCurrentL2
    , LI1_SeAvailableCurrentL3
    , LI1_SeAvailableCurrentN
    , LI1_EvPresentCurrentL1
    , LI1_EvPresentCurrentL2
    , LI1_EvPresentCurrentL3
    , LI1_EvPresentCurrentN
    , LI1_SeNomVoltageL1N
    , LI1_SeNomVoltageLL
    , LI1_SeFrequency
    , LI1_SeMaxCurrentL1
    , LI1_SeMaxCurrentL2
    , LI1_SeMaxCurrentL3
    , LI1_SeMaxCurrentN
    , LI1_EvMaxVoltageL1N
    , LI1_EvMaxVoltageLL
    , LI1_EvFrequencies
    , LI1_EvMinVoltageL1N
    , LI1_EvMinVoltageLL
    , LI1_EvMaxCurrentL1
    , LI1_EvMaxCurrentL2
    , LI1_EvMaxCurrentL3
    , LI1_EvMaxCurrentN
    , LI1_EvMinCurrentL1
    , LI1_EvMinCurrentL2
    , LI1_EvMinCurrentL3
    , LI1_EvInfoEntry1
    , LI1_EvInfoEntry2
    , LI1_EvInfoEntry3
    , LI1_EvInfoEntry4
    , LI1_EvInfoEntry5
    , LI1_EvInfoEntry6
    , LI1_SeInfoEntry1
    , LI1_SeInfoEntry2
    , LI1_SeInfoEntry3
    , LI1_SeInfoEntry4
    , LI1_SeInfoEntry5
    , LI1_SeInfoEntry6
    , LI1_EvInfoPageNumber
    , LI1_SeInfoPageNumber
    , LI1_CaVersion
    , LI1_CaResponseError
    , LI1_CaMaxVoltage
    , LI1_CaMaxCurrentL1
    , LI1_CaMaxCurrentL2
    , LI1_CaMaxCurrentL3
    , LI1_CaMaxCurrentN
    , LI1_StErrorPageNumber
    , LI1_StErrorCode1
    , LI1_StErrorCode2
    , LI1_StErrorCode3
    , LI1_StErrorCode4
    , LI1_StErrorCode5
    , LI1_StErrorCode6
    , LI1_EvErrorPageNumber
    , LI1_EvErrorCode1
    , LI1_EvErrorCode2
    , LI1_EvErrorCode3
    , LI1_EvErrorCode4
    , LI1_EvErrorCode5
    , LI1_EvErrorCode6
  
} l_signal_handle;
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  34
/* List of frames */
typedef enum {
/* All frames for master node */
   /* Interface_name = LI0 */
   LI0_SeVersionList
   , LI0_EvVersionList
    , LI0_SeStatus
    , LI0_EvStatus
    , LI0_EvPresentCurrentList
    , LI0_SeNomVoltages
    , LI0_SeMaxCurrentList
    , LI0_EvMaxVoltageList
    , LI0_EvMinVoltageList
    , LI0_EvMaxMinCurrents
    , LI0_CaProperties
    , LI0_SeInfoList
    , LI0_EvInfoList
    , LI0_StErrorList
    , LI0_EvErrorList
    , LI0_MasterReq
    , LI0_SlaveResp
  
   /* Interface_name = LI1 */
   , LI1_SeVersionList
    , LI1_EvVersionList
    , LI1_SeStatus
    , LI1_EvStatus
    , LI1_EvPresentCurrentList
    , LI1_SeNomVoltages
    , LI1_SeMaxCurrentList
    , LI1_EvMaxVoltageList
    , LI1_EvMinVoltageList
    , LI1_EvMaxMinCurrents
    , LI1_CaProperties
    , LI1_SeInfoList
    , LI1_EvInfoList
    , LI1_StErrorList
    , LI1_EvErrorList
    , LI1_MasterReq
    , LI1_SlaveResp
  
} l_frame_handle;
/**********************************************************************/
/***************        schedule table       *******************/
/**********************************************************************/
/* Number of schedule tables */
#define  LIN_NUM_OF_SCHD_TBL   18
/* List of schedules */
typedef enum {
   /* Interface_name = LI0 */
   LI0_LIN_NULL_SCHEDULE
   ,LI0_GOTO_SLEEP_SCHEDULE
     ,LI0_MasterReqTable
     ,LI0_SlaveRespTable
     ,LI0_Ver
     ,LI0_Init
     ,LI0_Op
     ,LI0_InitAnnexD
     ,LI0_Err
   
   /* Interface_name = LI1 */
   ,LI1_LIN_NULL_SCHEDULE
     ,LI1_GOTO_SLEEP_SCHEDULE
     ,LI1_MasterReqTable
     ,LI1_SlaveRespTable
     ,LI1_Ver
     ,LI1_Init
     ,LI1_Op
     ,LI1_InitAnnexD
     ,LI1_Err
   
}l_schedule_handle;/**********************************************************************/
/***************             Configuration          *******************/
/**********************************************************************/
/* Size of configuration in ROM and RAM used for interface: LI0 */
#define LI0_LIN_SIZE_OF_CFG  19
/* Size of configuration in ROM and RAM used for interface: LI1 */
#define LI1_LIN_SIZE_OF_CFG  19

/*********************************************************************
 * global macros
 *********************************************************************/
#define l_bool_rd(SIGNAL) l_bool_rd_##SIGNAL()
#define l_bool_wr(SIGNAL, A) l_bool_wr_##SIGNAL(A)
#define l_u8_rd(SIGNAL) l_u8_rd_##SIGNAL()
#define l_u8_wr(SIGNAL, A) l_u8_wr_##SIGNAL(A)
#define l_u16_rd(SIGNAL) l_u16_rd_##SIGNAL()
#define l_u16_wr(SIGNAL, A) l_u16_wr_##SIGNAL(A)
#define l_bytes_rd(SIGNAL, start, count, data)  l_bytes_rd_##SIGNAL(start, count, data)
#define l_bytes_wr(SIGNAL, start, count, data) l_bytes_wr_##SIGNAL(start, count, data)
#define l_flg_tst(FLAG) l_flg_tst_##FLAG()
#define l_flg_clr(FLAG) l_flg_clr_##FLAG()
#define LIN_TEST_BIT(A,B) ((l_bool)((((A) & (1U << (B))) != 0U) ? 1U : 0U))
#define LIN_SET_BIT(A,B)                      ((A) |= (l_u8) (1U << (B)))
#define LIN_CLEAR_BIT(A,B)               ((A) &= ((l_u8) (~(1U << (B)))))
#define LIN_BYTE_MASK  ((l_u16)(((l_u16)((l_u16)1 << CHAR_BIT)) - (l_u16)1))
#define LIN_FRAME_LEN_MAX                                             10U

/* Returns the low byte of the 32-bit value    */
#define BYTE_0(n)                              ((l_u8)((n) & (l_u8)0xFF))
/* Returns the second byte of the 32-bit value */
#define BYTE_1(n)                        ((l_u8)(BYTE_0((n) >> (l_u8)8)))
/* Returns the third byte of the 32-bit value  */
#define BYTE_2(n)                       ((l_u8)(BYTE_0((n) >> (l_u8)16)))
/* Returns high byte of the 32-bit value       */
#define BYTE_3(n)                       ((l_u8)(BYTE_0((n) >> (l_u8)24)))

/*
 * defines for signal access
 */
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList    8U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvVersionList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus    24U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvStatus   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList    32U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvPresentCurrentList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList    7U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList    56U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxVoltageList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList    10U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList    64U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMinVoltageList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList    11U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    72U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxMinCurrents   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList    96U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvInfoList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList    0U
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList    112U
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList    0U
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvErrorList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList    0U
#define LIN_BYTE_OFFSET_LI0_EvResponseError_EvVersionList    9U
#define LIN_BIT_OFFSET_LI0_EvResponseError_EvVersionList    0U
#define LIN_SIGNAL_SIZE_LI0_EvResponseError_EvVersionList   1U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList    1U
#define LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus    25U
#define LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus    0U
#define LIN_SIGNAL_SIZE_LI0_EvResponseError_EvStatus   1U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus    1U
#define LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList    9U
#define LIN_BIT_OFFSET_LI0_EvStatusVer_EvVersionList    1U
#define LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList    2U
#define LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus    25U
#define LIN_BIT_OFFSET_LI0_EvStatusVer_EvStatus    1U
#define LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus    2U
#define LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList    9U
#define LIN_BIT_OFFSET_LI0_EvStatusInit_EvVersionList    3U
#define LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList    3U
#define LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus    25U
#define LIN_BIT_OFFSET_LI0_EvStatusInit_EvStatus    3U
#define LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus    3U
#define LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList    9U
#define LIN_BIT_OFFSET_LI0_EvStatusOp_EvVersionList    5U
#define LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList    4U
#define LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus    25U
#define LIN_BIT_OFFSET_LI0_EvStatusOp_EvStatus    5U
#define LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus    4U
#define LIN_BYTE_OFFSET_LI0_EvAwake_EvVersionList    9U
#define LIN_BIT_OFFSET_LI0_EvAwake_EvVersionList    7U
#define LIN_SIGNAL_SIZE_LI0_EvAwake_EvVersionList   1U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList    5U
#define LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus    25U
#define LIN_BIT_OFFSET_LI0_EvAwake_EvStatus    7U
#define LIN_SIGNAL_SIZE_LI0_EvAwake_EvStatus   1U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus    5U
#define LIN_BYTE_OFFSET_LI0_EvVersionPageNumber    10U
#define LIN_BIT_OFFSET_LI0_EvVersionPageNumber    0U
#define LIN_SIGNAL_SIZE_LI0_EvVersionPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvVersionPageNumber    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvVersionPageNumber    6U
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion1    11U
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion1    0U
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion1    2U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion1    7U
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion2    12U
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion2    0U
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion2    3U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion2    0U
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion3    13U
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion3    0U
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion3    3U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion3    1U
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion4    14U
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion4    0U
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion4    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion4    3U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion4    2U
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion5    15U
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion5    0U
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion5    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion5    3U
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion5    3U
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1    26U
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL1    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL1    6U
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2    27U
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL2    5U
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL2    7U
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3    28U
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL3    6U
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL3    0U
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN    29U
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentN    0U
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentN    6U
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentN    1U
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList    0U
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList    0U
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeVersionList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList    0U
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus    16U
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus    0U
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeStatus   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus    0U
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    40U
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    0U
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeNomVoltages   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    8U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    0U
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList    48U
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList    0U
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeMaxCurrentList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList    9U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList    0U
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList    88U
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList    0U
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeInfoList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList    0U
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList    104U
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList    0U
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_StErrorList   8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList    16U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList    0U
#define LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList    1U
#define LIN_BIT_OFFSET_LI0_SeStatusVer_SeVersionList    1U
#define LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList    1U
#define LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus    17U
#define LIN_BIT_OFFSET_LI0_SeStatusVer_SeStatus    1U
#define LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus    1U
#define LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList    1U
#define LIN_BIT_OFFSET_LI0_SeStatusInit_SeVersionList    3U
#define LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList    2U
#define LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus    17U
#define LIN_BIT_OFFSET_LI0_SeStatusInit_SeStatus    3U
#define LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus    2U
#define LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList    1U
#define LIN_BIT_OFFSET_LI0_SeStatusOp_SeVersionList    5U
#define LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList    3U
#define LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus    17U
#define LIN_BIT_OFFSET_LI0_SeStatusOp_SeStatus    5U
#define LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus    3U
#define LIN_BYTE_OFFSET_LI0_SeVersionPageNumber    2U
#define LIN_BIT_OFFSET_LI0_SeVersionPageNumber    0U
#define LIN_SIGNAL_SIZE_LI0_SeVersionPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeVersionPageNumber    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeVersionPageNumber    4U
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion1    3U
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion1    0U
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion1    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion1    5U
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion2    4U
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion2    0U
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion2    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion2    6U
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion3    5U
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion3    0U
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion3    0U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion3    7U
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion4    6U
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion4    0U
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion4    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion4    1U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion4    0U
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion5    7U
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion5    0U
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion5    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion5    1U
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion5    1U
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1    18U
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL1    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL1    4U
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2    19U
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL2    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL2    5U
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3    20U
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL3    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL3    6U
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN    21U
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentN    0U
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentN    4U
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentN    7U
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1    33U
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL1    7U
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL1    1U
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2    34U
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL2    7U
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL2    2U
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3    35U
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL3    7U
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL3    3U
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentN    36U
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentN    0U
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentN    7U
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentN    4U
#define LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N    41U
#define LIN_BIT_OFFSET_LI0_SeNomVoltageL1N    0U
#define LIN_SIGNAL_SIZE_LI0_SeNomVoltageL1N    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageL1N    8U
#define LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageL1N    1U
#define LIN_BYTE_OFFSET_LI0_SeNomVoltageLL    43U
#define LIN_BIT_OFFSET_LI0_SeNomVoltageLL    0U
#define LIN_SIGNAL_SIZE_LI0_SeNomVoltageLL    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageLL    8U
#define LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageLL    2U
#define LIN_BYTE_OFFSET_LI0_SeFrequency    45U
#define LIN_BIT_OFFSET_LI0_SeFrequency    0U
#define LIN_SIGNAL_SIZE_LI0_SeFrequency    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeFrequency    8U
#define LIN_FLAG_BIT_OFFSET_LI0_SeFrequency    3U
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1    49U
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL1    9U
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL1    1U
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2    50U
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL2    9U
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL2    2U
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3    51U
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL3    9U
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL3    3U
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentN    52U
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentN    0U
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentN    9U
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentN    4U
#define LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N    57U
#define LIN_BIT_OFFSET_LI0_EvMaxVoltageL1N    0U
#define LIN_SIGNAL_SIZE_LI0_EvMaxVoltageL1N    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageL1N    10U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageL1N    1U
#define LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL    59U
#define LIN_BIT_OFFSET_LI0_EvMaxVoltageLL    0U
#define LIN_SIGNAL_SIZE_LI0_EvMaxVoltageLL    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageLL    10U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageLL    2U
#define LIN_BYTE_OFFSET_LI0_EvFrequencies    61U
#define LIN_BIT_OFFSET_LI0_EvFrequencies    0U
#define LIN_SIGNAL_SIZE_LI0_EvFrequencies    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvFrequencies    10U
#define LIN_FLAG_BIT_OFFSET_LI0_EvFrequencies    3U
#define LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N    65U
#define LIN_BIT_OFFSET_LI0_EvMinVoltageL1N    0U
#define LIN_SIGNAL_SIZE_LI0_EvMinVoltageL1N    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageL1N    11U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageL1N    1U
#define LIN_BYTE_OFFSET_LI0_EvMinVoltageLL    67U
#define LIN_BIT_OFFSET_LI0_EvMinVoltageLL    0U
#define LIN_SIGNAL_SIZE_LI0_EvMinVoltageLL    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageLL    11U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageLL    2U
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1    73U
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL1    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL1    1U
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2    74U
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL2    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL2    2U
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3    75U
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL3    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL3    3U
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentN    76U
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentN    0U
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentN    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentN    4U
#define LIN_BYTE_OFFSET_LI0_EvMinCurrentL1    77U
#define LIN_BIT_OFFSET_LI0_EvMinCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_EvMinCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL1    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL1    5U
#define LIN_BYTE_OFFSET_LI0_EvMinCurrentL2    78U
#define LIN_BIT_OFFSET_LI0_EvMinCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_EvMinCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL2    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL2    6U
#define LIN_BYTE_OFFSET_LI0_EvMinCurrentL3    79U
#define LIN_BIT_OFFSET_LI0_EvMinCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_EvMinCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL3    12U
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL3    7U
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry1    98U
#define LIN_BIT_OFFSET_LI0_EvInfoEntry1    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry1    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry1    2U
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry2    99U
#define LIN_BIT_OFFSET_LI0_EvInfoEntry2    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry2    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry2    3U
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry3    100U
#define LIN_BIT_OFFSET_LI0_EvInfoEntry3    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry3    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry3    4U
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry4    101U
#define LIN_BIT_OFFSET_LI0_EvInfoEntry4    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry4    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry4    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry4    5U
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry5    102U
#define LIN_BIT_OFFSET_LI0_EvInfoEntry5    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry5    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry5    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry5    6U
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry6    103U
#define LIN_BIT_OFFSET_LI0_EvInfoEntry6    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry6    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry6    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry6    7U
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry1    90U
#define LIN_BIT_OFFSET_LI0_SeInfoEntry1    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry1    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry1    2U
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry2    91U
#define LIN_BIT_OFFSET_LI0_SeInfoEntry2    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry2    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry2    3U
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry3    92U
#define LIN_BIT_OFFSET_LI0_SeInfoEntry3    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry3    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry3    4U
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry4    93U
#define LIN_BIT_OFFSET_LI0_SeInfoEntry4    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry4    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry4    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry4    5U
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry5    94U
#define LIN_BIT_OFFSET_LI0_SeInfoEntry5    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry5    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry5    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry5    6U
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry6    95U
#define LIN_BIT_OFFSET_LI0_SeInfoEntry6    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry6    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry6    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry6    7U
#define LIN_BYTE_OFFSET_LI0_EvInfoPageNumber    97U
#define LIN_BIT_OFFSET_LI0_EvInfoPageNumber    0U
#define LIN_SIGNAL_SIZE_LI0_EvInfoPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoPageNumber    15U
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoPageNumber    1U
#define LIN_BYTE_OFFSET_LI0_SeInfoPageNumber    89U
#define LIN_BIT_OFFSET_LI0_SeInfoPageNumber    0U
#define LIN_SIGNAL_SIZE_LI0_SeInfoPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoPageNumber    14U
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoPageNumber    1U
#define LIN_BYTE_OFFSET_LI0_CaVersion    80U
#define LIN_BIT_OFFSET_LI0_CaVersion    0U
#define LIN_SIGNAL_SIZE_LI0_CaVersion    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaVersion    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaVersion    0U
#define LIN_BYTE_OFFSET_LI0_CaResponseError    81U
#define LIN_BIT_OFFSET_LI0_CaResponseError    0U
#define LIN_SIGNAL_SIZE_LI0_CaResponseError    1U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaResponseError    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaResponseError    1U
#define LIN_BYTE_OFFSET_LI0_CaMaxVoltage    82U
#define LIN_BIT_OFFSET_LI0_CaMaxVoltage    0U
#define LIN_SIGNAL_SIZE_LI0_CaMaxVoltage    16U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaMaxVoltage    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaMaxVoltage    2U
#define LIN_BYTE_OFFSET_LI0_CaMaxCurrentL1    84U
#define LIN_BIT_OFFSET_LI0_CaMaxCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI0_CaMaxCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL1    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL1    3U
#define LIN_BYTE_OFFSET_LI0_CaMaxCurrentL2    85U
#define LIN_BIT_OFFSET_LI0_CaMaxCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI0_CaMaxCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL2    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL2    4U
#define LIN_BYTE_OFFSET_LI0_CaMaxCurrentL3    86U
#define LIN_BIT_OFFSET_LI0_CaMaxCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI0_CaMaxCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL3    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL3    5U
#define LIN_BYTE_OFFSET_LI0_CaMaxCurrentN    87U
#define LIN_BIT_OFFSET_LI0_CaMaxCurrentN    0U
#define LIN_SIGNAL_SIZE_LI0_CaMaxCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentN    13U
#define LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentN    6U
#define LIN_BYTE_OFFSET_LI0_StErrorPageNumber    105U
#define LIN_BIT_OFFSET_LI0_StErrorPageNumber    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorPageNumber    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorPageNumber    1U
#define LIN_BYTE_OFFSET_LI0_StErrorCode1    106U
#define LIN_BIT_OFFSET_LI0_StErrorCode1    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorCode1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode1    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode1    2U
#define LIN_BYTE_OFFSET_LI0_StErrorCode2    107U
#define LIN_BIT_OFFSET_LI0_StErrorCode2    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorCode2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode2    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode2    3U
#define LIN_BYTE_OFFSET_LI0_StErrorCode3    108U
#define LIN_BIT_OFFSET_LI0_StErrorCode3    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorCode3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode3    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode3    4U
#define LIN_BYTE_OFFSET_LI0_StErrorCode4    109U
#define LIN_BIT_OFFSET_LI0_StErrorCode4    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorCode4    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode4    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode4    5U
#define LIN_BYTE_OFFSET_LI0_StErrorCode5    110U
#define LIN_BIT_OFFSET_LI0_StErrorCode5    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorCode5    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode5    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode5    6U
#define LIN_BYTE_OFFSET_LI0_StErrorCode6    111U
#define LIN_BIT_OFFSET_LI0_StErrorCode6    0U
#define LIN_SIGNAL_SIZE_LI0_StErrorCode6    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode6    16U
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode6    7U
#define LIN_BYTE_OFFSET_LI0_EvErrorPageNumber    113U
#define LIN_BIT_OFFSET_LI0_EvErrorPageNumber    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorPageNumber    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorPageNumber    1U
#define LIN_BYTE_OFFSET_LI0_EvErrorCode1    114U
#define LIN_BIT_OFFSET_LI0_EvErrorCode1    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode1    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode1    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode1    2U
#define LIN_BYTE_OFFSET_LI0_EvErrorCode2    115U
#define LIN_BIT_OFFSET_LI0_EvErrorCode2    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode2    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode2    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode2    3U
#define LIN_BYTE_OFFSET_LI0_EvErrorCode3    116U
#define LIN_BIT_OFFSET_LI0_EvErrorCode3    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode3    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode3    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode3    4U
#define LIN_BYTE_OFFSET_LI0_EvErrorCode4    117U
#define LIN_BIT_OFFSET_LI0_EvErrorCode4    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode4    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode4    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode4    5U
#define LIN_BYTE_OFFSET_LI0_EvErrorCode5    118U
#define LIN_BIT_OFFSET_LI0_EvErrorCode5    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode5    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode5    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode5    6U
#define LIN_BYTE_OFFSET_LI0_EvErrorCode6    119U
#define LIN_BIT_OFFSET_LI0_EvErrorCode6    0U
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode6    8U
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode6    17U
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode6    7U

#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList    128U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvVersionList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus    144U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvStatus   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList    152U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvPresentCurrentList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList    25U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList    176U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxVoltageList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList    28U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList    184U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMinVoltageList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList    29U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    192U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxMinCurrents   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList    216U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvInfoList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList    0U
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList    232U
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList    0U
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvErrorList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList    0U
#define LIN_BYTE_OFFSET_LI1_EvResponseError_EvVersionList    129U
#define LIN_BIT_OFFSET_LI1_EvResponseError_EvVersionList    0U
#define LIN_SIGNAL_SIZE_LI1_EvResponseError_EvVersionList   1U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList    1U
#define LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus    145U
#define LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus    0U
#define LIN_SIGNAL_SIZE_LI1_EvResponseError_EvStatus   1U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus    1U
#define LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList    129U
#define LIN_BIT_OFFSET_LI1_EvStatusVer_EvVersionList    1U
#define LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList    2U
#define LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus    145U
#define LIN_BIT_OFFSET_LI1_EvStatusVer_EvStatus    1U
#define LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus    2U
#define LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList    129U
#define LIN_BIT_OFFSET_LI1_EvStatusInit_EvVersionList    3U
#define LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList    3U
#define LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus    145U
#define LIN_BIT_OFFSET_LI1_EvStatusInit_EvStatus    3U
#define LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus    3U
#define LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList    129U
#define LIN_BIT_OFFSET_LI1_EvStatusOp_EvVersionList    5U
#define LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList    4U
#define LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus    145U
#define LIN_BIT_OFFSET_LI1_EvStatusOp_EvStatus    5U
#define LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus    4U
#define LIN_BYTE_OFFSET_LI1_EvAwake_EvVersionList    129U
#define LIN_BIT_OFFSET_LI1_EvAwake_EvVersionList    7U
#define LIN_SIGNAL_SIZE_LI1_EvAwake_EvVersionList   1U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList    5U
#define LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus    145U
#define LIN_BIT_OFFSET_LI1_EvAwake_EvStatus    7U
#define LIN_SIGNAL_SIZE_LI1_EvAwake_EvStatus   1U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus    5U
#define LIN_BYTE_OFFSET_LI1_EvVersionPageNumber    130U
#define LIN_BIT_OFFSET_LI1_EvVersionPageNumber    0U
#define LIN_SIGNAL_SIZE_LI1_EvVersionPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvVersionPageNumber    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvVersionPageNumber    6U
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion1    131U
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion1    0U
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion1    20U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion1    7U
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion2    132U
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion2    0U
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion2    21U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion2    0U
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion3    133U
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion3    0U
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion3    21U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion3    1U
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion4    134U
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion4    0U
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion4    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion4    21U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion4    2U
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion5    135U
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion5    0U
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion5    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion5    21U
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion5    3U
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1    146U
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL1    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL1    6U
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2    147U
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL2    23U
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL2    7U
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3    148U
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL3    24U
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL3    0U
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN    149U
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentN    0U
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentN    24U
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentN    1U
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList    120U
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList    0U
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeVersionList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList    0U
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus    136U
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus    0U
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeStatus   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus    0U
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    160U
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    0U
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeNomVoltages   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    26U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    0U
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList    168U
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList    0U
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeMaxCurrentList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList    27U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList    0U
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList    208U
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList    0U
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeInfoList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList    0U
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList    224U
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList    0U
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_StErrorList   8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList    34U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList    0U
#define LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList    121U
#define LIN_BIT_OFFSET_LI1_SeStatusVer_SeVersionList    1U
#define LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList    1U
#define LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus    137U
#define LIN_BIT_OFFSET_LI1_SeStatusVer_SeStatus    1U
#define LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus    1U
#define LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList    121U
#define LIN_BIT_OFFSET_LI1_SeStatusInit_SeVersionList    3U
#define LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList    2U
#define LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus    137U
#define LIN_BIT_OFFSET_LI1_SeStatusInit_SeStatus    3U
#define LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus    2U
#define LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList    121U
#define LIN_BIT_OFFSET_LI1_SeStatusOp_SeVersionList    5U
#define LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeVersionList   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList    3U
#define LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus    137U
#define LIN_BIT_OFFSET_LI1_SeStatusOp_SeStatus    5U
#define LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeStatus   2U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus    3U
#define LIN_BYTE_OFFSET_LI1_SeVersionPageNumber    122U
#define LIN_BIT_OFFSET_LI1_SeVersionPageNumber    0U
#define LIN_SIGNAL_SIZE_LI1_SeVersionPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeVersionPageNumber    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeVersionPageNumber    4U
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion1    123U
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion1    0U
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion1    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion1    5U
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion2    124U
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion2    0U
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion2    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion2    6U
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion3    125U
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion3    0U
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion3    18U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion3    7U
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion4    126U
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion4    0U
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion4    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion4    19U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion4    0U
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion5    127U
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion5    0U
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion5    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion5    19U
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion5    1U
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1    138U
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL1    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL1    4U
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2    139U
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL2    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL2    5U
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3    140U
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL3    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL3    6U
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN    141U
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentN    0U
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentN    22U
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentN    7U
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1    153U
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL1    25U
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL1    1U
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2    154U
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL2    25U
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL2    2U
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3    155U
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL3    25U
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL3    3U
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentN    156U
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentN    0U
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentN    25U
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentN    4U
#define LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N    161U
#define LIN_BIT_OFFSET_LI1_SeNomVoltageL1N    0U
#define LIN_SIGNAL_SIZE_LI1_SeNomVoltageL1N    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageL1N    26U
#define LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageL1N    1U
#define LIN_BYTE_OFFSET_LI1_SeNomVoltageLL    163U
#define LIN_BIT_OFFSET_LI1_SeNomVoltageLL    0U
#define LIN_SIGNAL_SIZE_LI1_SeNomVoltageLL    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageLL    26U
#define LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageLL    2U
#define LIN_BYTE_OFFSET_LI1_SeFrequency    165U
#define LIN_BIT_OFFSET_LI1_SeFrequency    0U
#define LIN_SIGNAL_SIZE_LI1_SeFrequency    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeFrequency    26U
#define LIN_FLAG_BIT_OFFSET_LI1_SeFrequency    3U
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1    169U
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL1    27U
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL1    1U
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2    170U
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL2    27U
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL2    2U
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3    171U
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL3    27U
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL3    3U
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentN    172U
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentN    0U
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentN    27U
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentN    4U
#define LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N    177U
#define LIN_BIT_OFFSET_LI1_EvMaxVoltageL1N    0U
#define LIN_SIGNAL_SIZE_LI1_EvMaxVoltageL1N    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageL1N    28U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageL1N    1U
#define LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL    179U
#define LIN_BIT_OFFSET_LI1_EvMaxVoltageLL    0U
#define LIN_SIGNAL_SIZE_LI1_EvMaxVoltageLL    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageLL    28U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageLL    2U
#define LIN_BYTE_OFFSET_LI1_EvFrequencies    181U
#define LIN_BIT_OFFSET_LI1_EvFrequencies    0U
#define LIN_SIGNAL_SIZE_LI1_EvFrequencies    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvFrequencies    28U
#define LIN_FLAG_BIT_OFFSET_LI1_EvFrequencies    3U
#define LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N    185U
#define LIN_BIT_OFFSET_LI1_EvMinVoltageL1N    0U
#define LIN_SIGNAL_SIZE_LI1_EvMinVoltageL1N    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageL1N    29U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageL1N    1U
#define LIN_BYTE_OFFSET_LI1_EvMinVoltageLL    187U
#define LIN_BIT_OFFSET_LI1_EvMinVoltageLL    0U
#define LIN_SIGNAL_SIZE_LI1_EvMinVoltageLL    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageLL    29U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageLL    2U
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1    193U
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL1    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL1    1U
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2    194U
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL2    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL2    2U
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3    195U
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL3    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL3    3U
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentN    196U
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentN    0U
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentN    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentN    4U
#define LIN_BYTE_OFFSET_LI1_EvMinCurrentL1    197U
#define LIN_BIT_OFFSET_LI1_EvMinCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_EvMinCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL1    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL1    5U
#define LIN_BYTE_OFFSET_LI1_EvMinCurrentL2    198U
#define LIN_BIT_OFFSET_LI1_EvMinCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_EvMinCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL2    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL2    6U
#define LIN_BYTE_OFFSET_LI1_EvMinCurrentL3    199U
#define LIN_BIT_OFFSET_LI1_EvMinCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_EvMinCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL3    30U
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL3    7U
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry1    218U
#define LIN_BIT_OFFSET_LI1_EvInfoEntry1    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry1    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry1    2U
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry2    219U
#define LIN_BIT_OFFSET_LI1_EvInfoEntry2    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry2    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry2    3U
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry3    220U
#define LIN_BIT_OFFSET_LI1_EvInfoEntry3    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry3    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry3    4U
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry4    221U
#define LIN_BIT_OFFSET_LI1_EvInfoEntry4    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry4    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry4    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry4    5U
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry5    222U
#define LIN_BIT_OFFSET_LI1_EvInfoEntry5    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry5    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry5    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry5    6U
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry6    223U
#define LIN_BIT_OFFSET_LI1_EvInfoEntry6    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry6    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry6    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry6    7U
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry1    210U
#define LIN_BIT_OFFSET_LI1_SeInfoEntry1    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry1    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry1    2U
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry2    211U
#define LIN_BIT_OFFSET_LI1_SeInfoEntry2    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry2    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry2    3U
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry3    212U
#define LIN_BIT_OFFSET_LI1_SeInfoEntry3    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry3    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry3    4U
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry4    213U
#define LIN_BIT_OFFSET_LI1_SeInfoEntry4    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry4    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry4    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry4    5U
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry5    214U
#define LIN_BIT_OFFSET_LI1_SeInfoEntry5    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry5    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry5    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry5    6U
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry6    215U
#define LIN_BIT_OFFSET_LI1_SeInfoEntry6    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry6    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry6    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry6    7U
#define LIN_BYTE_OFFSET_LI1_EvInfoPageNumber    217U
#define LIN_BIT_OFFSET_LI1_EvInfoPageNumber    0U
#define LIN_SIGNAL_SIZE_LI1_EvInfoPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoPageNumber    33U
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoPageNumber    1U
#define LIN_BYTE_OFFSET_LI1_SeInfoPageNumber    209U
#define LIN_BIT_OFFSET_LI1_SeInfoPageNumber    0U
#define LIN_SIGNAL_SIZE_LI1_SeInfoPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoPageNumber    32U
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoPageNumber    1U
#define LIN_BYTE_OFFSET_LI1_CaVersion    200U
#define LIN_BIT_OFFSET_LI1_CaVersion    0U
#define LIN_SIGNAL_SIZE_LI1_CaVersion    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaVersion    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaVersion    0U
#define LIN_BYTE_OFFSET_LI1_CaResponseError    201U
#define LIN_BIT_OFFSET_LI1_CaResponseError    0U
#define LIN_SIGNAL_SIZE_LI1_CaResponseError    1U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaResponseError    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaResponseError    1U
#define LIN_BYTE_OFFSET_LI1_CaMaxVoltage    202U
#define LIN_BIT_OFFSET_LI1_CaMaxVoltage    0U
#define LIN_SIGNAL_SIZE_LI1_CaMaxVoltage    16U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaMaxVoltage    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaMaxVoltage    2U
#define LIN_BYTE_OFFSET_LI1_CaMaxCurrentL1    204U
#define LIN_BIT_OFFSET_LI1_CaMaxCurrentL1    0U
#define LIN_SIGNAL_SIZE_LI1_CaMaxCurrentL1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL1    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL1    3U
#define LIN_BYTE_OFFSET_LI1_CaMaxCurrentL2    205U
#define LIN_BIT_OFFSET_LI1_CaMaxCurrentL2    0U
#define LIN_SIGNAL_SIZE_LI1_CaMaxCurrentL2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL2    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL2    4U
#define LIN_BYTE_OFFSET_LI1_CaMaxCurrentL3    206U
#define LIN_BIT_OFFSET_LI1_CaMaxCurrentL3    0U
#define LIN_SIGNAL_SIZE_LI1_CaMaxCurrentL3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL3    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL3    5U
#define LIN_BYTE_OFFSET_LI1_CaMaxCurrentN    207U
#define LIN_BIT_OFFSET_LI1_CaMaxCurrentN    0U
#define LIN_SIGNAL_SIZE_LI1_CaMaxCurrentN    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentN    31U
#define LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentN    6U
#define LIN_BYTE_OFFSET_LI1_StErrorPageNumber    225U
#define LIN_BIT_OFFSET_LI1_StErrorPageNumber    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorPageNumber    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorPageNumber    1U
#define LIN_BYTE_OFFSET_LI1_StErrorCode1    226U
#define LIN_BIT_OFFSET_LI1_StErrorCode1    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorCode1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode1    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode1    2U
#define LIN_BYTE_OFFSET_LI1_StErrorCode2    227U
#define LIN_BIT_OFFSET_LI1_StErrorCode2    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorCode2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode2    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode2    3U
#define LIN_BYTE_OFFSET_LI1_StErrorCode3    228U
#define LIN_BIT_OFFSET_LI1_StErrorCode3    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorCode3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode3    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode3    4U
#define LIN_BYTE_OFFSET_LI1_StErrorCode4    229U
#define LIN_BIT_OFFSET_LI1_StErrorCode4    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorCode4    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode4    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode4    5U
#define LIN_BYTE_OFFSET_LI1_StErrorCode5    230U
#define LIN_BIT_OFFSET_LI1_StErrorCode5    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorCode5    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode5    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode5    6U
#define LIN_BYTE_OFFSET_LI1_StErrorCode6    231U
#define LIN_BIT_OFFSET_LI1_StErrorCode6    0U
#define LIN_SIGNAL_SIZE_LI1_StErrorCode6    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode6    34U
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode6    7U
#define LIN_BYTE_OFFSET_LI1_EvErrorPageNumber    233U
#define LIN_BIT_OFFSET_LI1_EvErrorPageNumber    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorPageNumber    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorPageNumber    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorPageNumber    1U
#define LIN_BYTE_OFFSET_LI1_EvErrorCode1    234U
#define LIN_BIT_OFFSET_LI1_EvErrorCode1    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode1    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode1    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode1    2U
#define LIN_BYTE_OFFSET_LI1_EvErrorCode2    235U
#define LIN_BIT_OFFSET_LI1_EvErrorCode2    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode2    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode2    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode2    3U
#define LIN_BYTE_OFFSET_LI1_EvErrorCode3    236U
#define LIN_BIT_OFFSET_LI1_EvErrorCode3    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode3    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode3    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode3    4U
#define LIN_BYTE_OFFSET_LI1_EvErrorCode4    237U
#define LIN_BIT_OFFSET_LI1_EvErrorCode4    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode4    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode4    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode4    5U
#define LIN_BYTE_OFFSET_LI1_EvErrorCode5    238U
#define LIN_BIT_OFFSET_LI1_EvErrorCode5    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode5    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode5    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode5    6U
#define LIN_BYTE_OFFSET_LI1_EvErrorCode6    239U
#define LIN_BIT_OFFSET_LI1_EvErrorCode6    0U
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode6    8U
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode6    35U
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode6    7U



#define LIN_FLAG_BYTE_OFFSET_LI0_SeVersionList             0
#define LIN_FLAG_BIT_OFFSET_LI0_SeVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvVersionList             2
#define LIN_FLAG_BIT_OFFSET_LI0_EvVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatus             4
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatus             5
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentList             7
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltages             8
#define LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentList             9
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageList             10
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageList             11
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxMinCurrents             12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxMinCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI0_CaProperties             13
#define LIN_FLAG_BIT_OFFSET_LI0_CaProperties              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoList             14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoList             15
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorList             16
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorList             17
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeVersionList             18
#define LIN_FLAG_BIT_OFFSET_LI1_SeVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvVersionList             20
#define LIN_FLAG_BIT_OFFSET_LI1_EvVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatus             22
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatus             23
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentList             25
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltages             26
#define LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentList             27
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageList             28
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageList             29
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxMinCurrents             30
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxMinCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI1_CaProperties             31
#define LIN_FLAG_BIT_OFFSET_LI1_CaProperties              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoList             32
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoList             33
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorList             34
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorList             35
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorList              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */
 
/* static access macros for signal LI0_EvSelectedVersion */
 #define l_u8_rd_LI0_EvSelectedVersion_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvPresentCurrentList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvMaxVoltageList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvMinVoltageList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvMaxMinCurrents() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvInfoList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_EvSelectedVersion_EvErrorList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvSelectedVersion(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList); \
    } \

/* static access macros for signal LI0_EvResponseError */

 #define l_bool_rd_LI0_EvResponseError_EvVersionList() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvVersionList], \
    LIN_BIT_OFFSET_LI0_EvResponseError_EvVersionList))
#define l_bool_rd_LI0_EvResponseError_EvStatus() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus], \
    LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus))

#define l_bool_wr_LI0_EvResponseError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvVersionList], \
    LIN_BIT_OFFSET_LI0_EvResponseError_EvVersionList)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvVersionList], \
    LIN_BIT_OFFSET_LI0_EvResponseError_EvVersionList));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList);}\
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus], \
    LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus], \
    LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus);}\
 
/* static access macros for signal LI0_EvStatusVer */
 #define l_u8_rd_LI0_EvStatusVer_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList]) >> 1U) & 0x03U))

#define l_u8_rd_LI0_EvStatusVer_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus]) >> 1U) & 0x03U))


#define l_u8_wr_LI0_EvStatusVer(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus); \
    } \

 
/* static access macros for signal LI0_EvStatusInit */
 #define l_u8_rd_LI0_EvStatusInit_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList]) >> 3U) & 0x03U))

#define l_u8_rd_LI0_EvStatusInit_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus]) >> 3U) & 0x03U))


#define l_u8_wr_LI0_EvStatusInit(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus); \
    } \

 
/* static access macros for signal LI0_EvStatusOp */
 #define l_u8_rd_LI0_EvStatusOp_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList]) >> 5U) & 0x03U))

#define l_u8_rd_LI0_EvStatusOp_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus]) >> 5U) & 0x03U))


#define l_u8_wr_LI0_EvStatusOp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus); \
    } \

/* static access macros for signal LI0_EvAwake */

 #define l_bool_rd_LI0_EvAwake_EvVersionList() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvVersionList], \
    LIN_BIT_OFFSET_LI0_EvAwake_EvVersionList))
#define l_bool_rd_LI0_EvAwake_EvStatus() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus], \
    LIN_BIT_OFFSET_LI0_EvAwake_EvStatus))

#define l_bool_wr_LI0_EvAwake(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvVersionList], \
    LIN_BIT_OFFSET_LI0_EvAwake_EvVersionList)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvVersionList], \
    LIN_BIT_OFFSET_LI0_EvAwake_EvVersionList));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList);}\
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus], \
    LIN_BIT_OFFSET_LI0_EvAwake_EvStatus)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus], \
    LIN_BIT_OFFSET_LI0_EvAwake_EvStatus));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus);}\
 
/* static access macros for signal LI0_EvVersionPageNumber */
 #define l_u8_rd_LI0_EvVersionPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvVersionPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvVersionPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvVersionPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvVersionPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvVersionPageNumber); \
    }

 
/* static access macros for signal LI0_EvSupportedVersion1 */
 #define l_u8_rd_LI0_EvSupportedVersion1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvSupportedVersion1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion1); \
    }

 
/* static access macros for signal LI0_EvSupportedVersion2 */
 #define l_u8_rd_LI0_EvSupportedVersion2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvSupportedVersion2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion2); \
    }

 
/* static access macros for signal LI0_EvSupportedVersion3 */
 #define l_u8_rd_LI0_EvSupportedVersion3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvSupportedVersion3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion3); \
    }

 
/* static access macros for signal LI0_EvSupportedVersion4 */
 #define l_u8_rd_LI0_EvSupportedVersion4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion4]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvSupportedVersion4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion4); \
    }

 
/* static access macros for signal LI0_EvSupportedVersion5 */
 #define l_u8_rd_LI0_EvSupportedVersion5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion5]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvSupportedVersion5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion5); \
    }

 
/* static access macros for signal LI0_EvRequestedCurrentL1 */
 #define l_u8_rd_LI0_EvRequestedCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvRequestedCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL1); \
    }

 
/* static access macros for signal LI0_EvRequestedCurrentL2 */
 #define l_u8_rd_LI0_EvRequestedCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvRequestedCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL2); \
    }

 
/* static access macros for signal LI0_EvRequestedCurrentL3 */
 #define l_u8_rd_LI0_EvRequestedCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvRequestedCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL3); \
    }

 
/* static access macros for signal LI0_EvRequestedCurrentN */
 #define l_u8_rd_LI0_EvRequestedCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvRequestedCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentN); \
    }

 
/* static access macros for signal LI0_SeSelectedVersion */
 #define l_u8_rd_LI0_SeSelectedVersion_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_SeSelectedVersion_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_SeSelectedVersion_SeNomVoltages() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_SeSelectedVersion_SeMaxCurrentList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_SeSelectedVersion_SeInfoList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList]) >> 0U) & 0xffU))

#define l_u8_rd_LI0_SeSelectedVersion_StErrorList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeSelectedVersion(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList); \
    } \

 
/* static access macros for signal LI0_SeStatusVer */
 #define l_u8_rd_LI0_SeStatusVer_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList]) >> 1U) & 0x03U))

#define l_u8_rd_LI0_SeStatusVer_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus]) >> 1U) & 0x03U))


#define l_u8_wr_LI0_SeStatusVer(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus); \
    } \

 
/* static access macros for signal LI0_SeStatusInit */
 #define l_u8_rd_LI0_SeStatusInit_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList]) >> 3U) & 0x03U))

#define l_u8_rd_LI0_SeStatusInit_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus]) >> 3U) & 0x03U))


#define l_u8_wr_LI0_SeStatusInit(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus); \
    } \

 
/* static access macros for signal LI0_SeStatusOp */
 #define l_u8_rd_LI0_SeStatusOp_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList]) >> 5U) & 0x03U))

#define l_u8_rd_LI0_SeStatusOp_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus]) >> 5U) & 0x03U))


#define l_u8_wr_LI0_SeStatusOp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus); \
    } \

 
/* static access macros for signal LI0_SeVersionPageNumber */
 #define l_u8_rd_LI0_SeVersionPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeVersionPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeVersionPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeVersionPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeVersionPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_SeVersionPageNumber); \
    }

 
/* static access macros for signal LI0_SeSupportedVersion1 */
 #define l_u8_rd_LI0_SeSupportedVersion1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeSupportedVersion1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion1); \
    }

 
/* static access macros for signal LI0_SeSupportedVersion2 */
 #define l_u8_rd_LI0_SeSupportedVersion2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeSupportedVersion2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion2); \
    }

 
/* static access macros for signal LI0_SeSupportedVersion3 */
 #define l_u8_rd_LI0_SeSupportedVersion3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeSupportedVersion3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion3); \
    }

 
/* static access macros for signal LI0_SeSupportedVersion4 */
 #define l_u8_rd_LI0_SeSupportedVersion4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion4]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeSupportedVersion4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion4); \
    }

 
/* static access macros for signal LI0_SeSupportedVersion5 */
 #define l_u8_rd_LI0_SeSupportedVersion5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion5]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeSupportedVersion5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion5); \
    }

 
/* static access macros for signal LI0_SeAvailableCurrentL1 */
 #define l_u8_rd_LI0_SeAvailableCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeAvailableCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL1); \
    }

 
/* static access macros for signal LI0_SeAvailableCurrentL2 */
 #define l_u8_rd_LI0_SeAvailableCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeAvailableCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL2); \
    }

 
/* static access macros for signal LI0_SeAvailableCurrentL3 */
 #define l_u8_rd_LI0_SeAvailableCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeAvailableCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL3); \
    }

 
/* static access macros for signal LI0_SeAvailableCurrentN */
 #define l_u8_rd_LI0_SeAvailableCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeAvailableCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentN); \
    }

 
/* static access macros for signal LI0_EvPresentCurrentL1 */
 #define l_u8_rd_LI0_EvPresentCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvPresentCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL1); \
    }

 
/* static access macros for signal LI0_EvPresentCurrentL2 */
 #define l_u8_rd_LI0_EvPresentCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvPresentCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL2); \
    }

 
/* static access macros for signal LI0_EvPresentCurrentL3 */
 #define l_u8_rd_LI0_EvPresentCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvPresentCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL3); \
    }

 
/* static access macros for signal LI0_EvPresentCurrentN */
 #define l_u8_rd_LI0_EvPresentCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvPresentCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentN); \
    }

 
/* static access macros for signal LI0_SeNomVoltageL1N */
 #define l_u16_rd_LI0_SeNomVoltageL1N() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_SeNomVoltageL1N(A) \
    { \
    buffer_backup_data[1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N]; \
    lin_frame_updating_flag_tbl[LI0_SeNomVoltages] |= (1U << 1); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[1U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1U]; \
    lin_frame_updating_flag_tbl[LI0_SeNomVoltages] |= (1U << (1 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_SeNomVoltages] &= (~(0x03 << 1)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageL1N); \
    }

 
/* static access macros for signal LI0_SeNomVoltageLL */
 #define l_u16_rd_LI0_SeNomVoltageLL() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_SeNomVoltageLL(A) \
    { \
    buffer_backup_data[3U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL]; \
    lin_frame_updating_flag_tbl[LI0_SeNomVoltages] |= (1U << 3); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[3U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1U]; \
    lin_frame_updating_flag_tbl[LI0_SeNomVoltages] |= (1U << (3 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_SeNomVoltages] &= (~(0x03 << 3)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageLL); \
    }

 
/* static access macros for signal LI0_SeFrequency */
 #define l_u8_rd_LI0_SeFrequency() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeFrequency]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeFrequency(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeFrequency] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeFrequency] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeFrequency],\
         LIN_FLAG_BIT_OFFSET_LI0_SeFrequency); \
    }

 
/* static access macros for signal LI0_SeMaxCurrentL1 */
 #define l_u8_rd_LI0_SeMaxCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeMaxCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL1); \
    }

 
/* static access macros for signal LI0_SeMaxCurrentL2 */
 #define l_u8_rd_LI0_SeMaxCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeMaxCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL2); \
    }

 
/* static access macros for signal LI0_SeMaxCurrentL3 */
 #define l_u8_rd_LI0_SeMaxCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeMaxCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL3); \
    }

 
/* static access macros for signal LI0_SeMaxCurrentN */
 #define l_u8_rd_LI0_SeMaxCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeMaxCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentN); \
    }

 
/* static access macros for signal LI0_EvMaxVoltageL1N */
 #define l_u16_rd_LI0_EvMaxVoltageL1N() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_EvMaxVoltageL1N(A) \
    { \
    buffer_backup_data[1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N]; \
    lin_frame_updating_flag_tbl[LI0_EvMaxVoltageList] |= (1U << 1); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[1U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1U]; \
    lin_frame_updating_flag_tbl[LI0_EvMaxVoltageList] |= (1U << (1 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_EvMaxVoltageList] &= (~(0x03 << 1)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageL1N); \
    }

 
/* static access macros for signal LI0_EvMaxVoltageLL */
 #define l_u16_rd_LI0_EvMaxVoltageLL() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_EvMaxVoltageLL(A) \
    { \
    buffer_backup_data[3U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL]; \
    lin_frame_updating_flag_tbl[LI0_EvMaxVoltageList] |= (1U << 3); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[3U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1U]; \
    lin_frame_updating_flag_tbl[LI0_EvMaxVoltageList] |= (1U << (3 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_EvMaxVoltageList] &= (~(0x03 << 3)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageLL); \
    }

 
/* static access macros for signal LI0_EvFrequencies */
 #define l_u8_rd_LI0_EvFrequencies() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvFrequencies]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvFrequencies(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvFrequencies] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvFrequencies] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvFrequencies],\
         LIN_FLAG_BIT_OFFSET_LI0_EvFrequencies); \
    }

 
/* static access macros for signal LI0_EvMinVoltageL1N */
 #define l_u16_rd_LI0_EvMinVoltageL1N() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_EvMinVoltageL1N(A) \
    { \
    buffer_backup_data[1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N]; \
    lin_frame_updating_flag_tbl[LI0_EvMinVoltageList] |= (1U << 1); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[1U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1U]; \
    lin_frame_updating_flag_tbl[LI0_EvMinVoltageList] |= (1U << (1 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_EvMinVoltageList] &= (~(0x03 << 1)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageL1N); \
    }

 
/* static access macros for signal LI0_EvMinVoltageLL */
 #define l_u16_rd_LI0_EvMinVoltageLL() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_EvMinVoltageLL(A) \
    { \
    buffer_backup_data[3U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL]; \
    lin_frame_updating_flag_tbl[LI0_EvMinVoltageList] |= (1U << 3); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[3U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1U]; \
    lin_frame_updating_flag_tbl[LI0_EvMinVoltageList] |= (1U << (3 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_EvMinVoltageList] &= (~(0x03 << 3)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageLL); \
    }

 
/* static access macros for signal LI0_EvMaxCurrentL1 */
 #define l_u8_rd_LI0_EvMaxCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMaxCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL1); \
    }

 
/* static access macros for signal LI0_EvMaxCurrentL2 */
 #define l_u8_rd_LI0_EvMaxCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMaxCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL2); \
    }

 
/* static access macros for signal LI0_EvMaxCurrentL3 */
 #define l_u8_rd_LI0_EvMaxCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMaxCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL3); \
    }

 
/* static access macros for signal LI0_EvMaxCurrentN */
 #define l_u8_rd_LI0_EvMaxCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMaxCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentN); \
    }

 
/* static access macros for signal LI0_EvMinCurrentL1 */
 #define l_u8_rd_LI0_EvMinCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMinCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL1); \
    }

 
/* static access macros for signal LI0_EvMinCurrentL2 */
 #define l_u8_rd_LI0_EvMinCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMinCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL2); \
    }

 
/* static access macros for signal LI0_EvMinCurrentL3 */
 #define l_u8_rd_LI0_EvMinCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvMinCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL3); \
    }

 
/* static access macros for signal LI0_EvInfoEntry1 */
 #define l_u8_rd_LI0_EvInfoEntry1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoEntry1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry1); \
    }

 
/* static access macros for signal LI0_EvInfoEntry2 */
 #define l_u8_rd_LI0_EvInfoEntry2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoEntry2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry2); \
    }

 
/* static access macros for signal LI0_EvInfoEntry3 */
 #define l_u8_rd_LI0_EvInfoEntry3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoEntry3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry3); \
    }

 
/* static access macros for signal LI0_EvInfoEntry4 */
 #define l_u8_rd_LI0_EvInfoEntry4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry4]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoEntry4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry4); \
    }

 
/* static access macros for signal LI0_EvInfoEntry5 */
 #define l_u8_rd_LI0_EvInfoEntry5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry5]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoEntry5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry5); \
    }

 
/* static access macros for signal LI0_EvInfoEntry6 */
 #define l_u8_rd_LI0_EvInfoEntry6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry6]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoEntry6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry6); \
    }

 
/* static access macros for signal LI0_SeInfoEntry1 */
 #define l_u8_rd_LI0_SeInfoEntry1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoEntry1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry1); \
    }

 
/* static access macros for signal LI0_SeInfoEntry2 */
 #define l_u8_rd_LI0_SeInfoEntry2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoEntry2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry2); \
    }

 
/* static access macros for signal LI0_SeInfoEntry3 */
 #define l_u8_rd_LI0_SeInfoEntry3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoEntry3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry3); \
    }

 
/* static access macros for signal LI0_SeInfoEntry4 */
 #define l_u8_rd_LI0_SeInfoEntry4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry4]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoEntry4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry4); \
    }

 
/* static access macros for signal LI0_SeInfoEntry5 */
 #define l_u8_rd_LI0_SeInfoEntry5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry5]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoEntry5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry5); \
    }

 
/* static access macros for signal LI0_SeInfoEntry6 */
 #define l_u8_rd_LI0_SeInfoEntry6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry6]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoEntry6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry6); \
    }

 
/* static access macros for signal LI0_EvInfoPageNumber */
 #define l_u8_rd_LI0_EvInfoPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvInfoPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoPageNumber); \
    }

 
/* static access macros for signal LI0_SeInfoPageNumber */
 #define l_u8_rd_LI0_SeInfoPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_SeInfoPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoPageNumber); \
    }

 
/* static access macros for signal LI0_CaVersion */
 #define l_u8_rd_LI0_CaVersion() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaVersion]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_CaVersion(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaVersion] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaVersion] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaVersion],\
         LIN_FLAG_BIT_OFFSET_LI0_CaVersion); \
    }

/* static access macros for signal LI0_CaResponseError */

 #define l_bool_rd_LI0_CaResponseError() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaResponseError], \
    LIN_BIT_OFFSET_LI0_CaResponseError))

#define l_bool_wr_LI0_CaResponseError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaResponseError], \
    LIN_BIT_OFFSET_LI0_CaResponseError)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaResponseError], \
    LIN_BIT_OFFSET_LI0_CaResponseError));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaResponseError],\
         LIN_FLAG_BIT_OFFSET_LI0_CaResponseError);} 
/* static access macros for signal LI0_CaMaxVoltage */
 #define l_u16_rd_LI0_CaMaxVoltage() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI0_CaMaxVoltage(A) \
    { \
    buffer_backup_data[2U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage]; \
    lin_frame_updating_flag_tbl[LI0_CaProperties] |= (1U << 2); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[2U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage + 1U]; \
    lin_frame_updating_flag_tbl[LI0_CaProperties] |= (1U << (2 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxVoltage + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI0_CaProperties] &= (~(0x03 << 2)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxVoltage],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxVoltage); \
    }

 
/* static access macros for signal LI0_CaMaxCurrentL1 */
 #define l_u8_rd_LI0_CaMaxCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_CaMaxCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL1); \
    }

 
/* static access macros for signal LI0_CaMaxCurrentL2 */
 #define l_u8_rd_LI0_CaMaxCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_CaMaxCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL2); \
    }

 
/* static access macros for signal LI0_CaMaxCurrentL3 */
 #define l_u8_rd_LI0_CaMaxCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_CaMaxCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL3); \
    }

 
/* static access macros for signal LI0_CaMaxCurrentN */
 #define l_u8_rd_LI0_CaMaxCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_CaMaxCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_CaMaxCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentN); \
    }

 
/* static access macros for signal LI0_StErrorPageNumber */
 #define l_u8_rd_LI0_StErrorPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorPageNumber); \
    }

 
/* static access macros for signal LI0_StErrorCode1 */
 #define l_u8_rd_LI0_StErrorCode1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorCode1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode1); \
    }

 
/* static access macros for signal LI0_StErrorCode2 */
 #define l_u8_rd_LI0_StErrorCode2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorCode2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode2); \
    }

 
/* static access macros for signal LI0_StErrorCode3 */
 #define l_u8_rd_LI0_StErrorCode3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorCode3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode3); \
    }

 
/* static access macros for signal LI0_StErrorCode4 */
 #define l_u8_rd_LI0_StErrorCode4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode4]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorCode4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode4); \
    }

 
/* static access macros for signal LI0_StErrorCode5 */
 #define l_u8_rd_LI0_StErrorCode5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode5]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorCode5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode5); \
    }

 
/* static access macros for signal LI0_StErrorCode6 */
 #define l_u8_rd_LI0_StErrorCode6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode6]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_StErrorCode6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode6); \
    }

 
/* static access macros for signal LI0_EvErrorPageNumber */
 #define l_u8_rd_LI0_EvErrorPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorPageNumber); \
    }

 
/* static access macros for signal LI0_EvErrorCode1 */
 #define l_u8_rd_LI0_EvErrorCode1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode1]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorCode1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode1); \
    }

 
/* static access macros for signal LI0_EvErrorCode2 */
 #define l_u8_rd_LI0_EvErrorCode2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode2]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorCode2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode2); \
    }

 
/* static access macros for signal LI0_EvErrorCode3 */
 #define l_u8_rd_LI0_EvErrorCode3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode3]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorCode3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode3); \
    }

 
/* static access macros for signal LI0_EvErrorCode4 */
 #define l_u8_rd_LI0_EvErrorCode4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode4]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorCode4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode4); \
    }

 
/* static access macros for signal LI0_EvErrorCode5 */
 #define l_u8_rd_LI0_EvErrorCode5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode5]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorCode5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode5); \
    }

 
/* static access macros for signal LI0_EvErrorCode6 */
 #define l_u8_rd_LI0_EvErrorCode6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode6]) >> 0U) & 0xffU))


#define l_u8_wr_LI0_EvErrorCode6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode6); \
    }


 
/* static access macros for signal LI1_EvSelectedVersion */
 #define l_u8_rd_LI1_EvSelectedVersion_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvPresentCurrentList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvMaxVoltageList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvMinVoltageList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvMaxMinCurrents() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvInfoList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_EvSelectedVersion_EvErrorList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvSelectedVersion(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList); \
    } \

/* static access macros for signal LI1_EvResponseError */

 #define l_bool_rd_LI1_EvResponseError_EvVersionList() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvVersionList], \
    LIN_BIT_OFFSET_LI1_EvResponseError_EvVersionList))
#define l_bool_rd_LI1_EvResponseError_EvStatus() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus], \
    LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus))

#define l_bool_wr_LI1_EvResponseError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvVersionList], \
    LIN_BIT_OFFSET_LI1_EvResponseError_EvVersionList)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvVersionList], \
    LIN_BIT_OFFSET_LI1_EvResponseError_EvVersionList));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList);}\
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus], \
    LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus], \
    LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus);}\
 
/* static access macros for signal LI1_EvStatusVer */
 #define l_u8_rd_LI1_EvStatusVer_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList]) >> 1U) & 0x03U))

#define l_u8_rd_LI1_EvStatusVer_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus]) >> 1U) & 0x03U))


#define l_u8_wr_LI1_EvStatusVer(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus); \
    } \

 
/* static access macros for signal LI1_EvStatusInit */
 #define l_u8_rd_LI1_EvStatusInit_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList]) >> 3U) & 0x03U))

#define l_u8_rd_LI1_EvStatusInit_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus]) >> 3U) & 0x03U))


#define l_u8_wr_LI1_EvStatusInit(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus); \
    } \

 
/* static access macros for signal LI1_EvStatusOp */
 #define l_u8_rd_LI1_EvStatusOp_EvVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList]) >> 5U) & 0x03U))

#define l_u8_rd_LI1_EvStatusOp_EvStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus]) >> 5U) & 0x03U))


#define l_u8_wr_LI1_EvStatusOp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus); \
    } \

/* static access macros for signal LI1_EvAwake */

 #define l_bool_rd_LI1_EvAwake_EvVersionList() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvVersionList], \
    LIN_BIT_OFFSET_LI1_EvAwake_EvVersionList))
#define l_bool_rd_LI1_EvAwake_EvStatus() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus], \
    LIN_BIT_OFFSET_LI1_EvAwake_EvStatus))

#define l_bool_wr_LI1_EvAwake(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvVersionList], \
    LIN_BIT_OFFSET_LI1_EvAwake_EvVersionList)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvVersionList], \
    LIN_BIT_OFFSET_LI1_EvAwake_EvVersionList));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList);}\
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus], \
    LIN_BIT_OFFSET_LI1_EvAwake_EvStatus)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus], \
    LIN_BIT_OFFSET_LI1_EvAwake_EvStatus));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus);}\
 
/* static access macros for signal LI1_EvVersionPageNumber */
 #define l_u8_rd_LI1_EvVersionPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvVersionPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvVersionPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvVersionPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvVersionPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvVersionPageNumber); \
    }

 
/* static access macros for signal LI1_EvSupportedVersion1 */
 #define l_u8_rd_LI1_EvSupportedVersion1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvSupportedVersion1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion1); \
    }

 
/* static access macros for signal LI1_EvSupportedVersion2 */
 #define l_u8_rd_LI1_EvSupportedVersion2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvSupportedVersion2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion2); \
    }

 
/* static access macros for signal LI1_EvSupportedVersion3 */
 #define l_u8_rd_LI1_EvSupportedVersion3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvSupportedVersion3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion3); \
    }

 
/* static access macros for signal LI1_EvSupportedVersion4 */
 #define l_u8_rd_LI1_EvSupportedVersion4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion4]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvSupportedVersion4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion4); \
    }

 
/* static access macros for signal LI1_EvSupportedVersion5 */
 #define l_u8_rd_LI1_EvSupportedVersion5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion5]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvSupportedVersion5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion5); \
    }

 
/* static access macros for signal LI1_EvRequestedCurrentL1 */
 #define l_u8_rd_LI1_EvRequestedCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvRequestedCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL1); \
    }

 
/* static access macros for signal LI1_EvRequestedCurrentL2 */
 #define l_u8_rd_LI1_EvRequestedCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvRequestedCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL2); \
    }

 
/* static access macros for signal LI1_EvRequestedCurrentL3 */
 #define l_u8_rd_LI1_EvRequestedCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvRequestedCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL3); \
    }

 
/* static access macros for signal LI1_EvRequestedCurrentN */
 #define l_u8_rd_LI1_EvRequestedCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvRequestedCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentN); \
    }

 
/* static access macros for signal LI1_SeSelectedVersion */
 #define l_u8_rd_LI1_SeSelectedVersion_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_SeSelectedVersion_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_SeSelectedVersion_SeNomVoltages() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_SeSelectedVersion_SeMaxCurrentList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_SeSelectedVersion_SeInfoList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList]) >> 0U) & 0xffU))

#define l_u8_rd_LI1_SeSelectedVersion_StErrorList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeSelectedVersion(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList); \
    } \

 
/* static access macros for signal LI1_SeStatusVer */
 #define l_u8_rd_LI1_SeStatusVer_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList]) >> 1U) & 0x03U))

#define l_u8_rd_LI1_SeStatusVer_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus]) >> 1U) & 0x03U))


#define l_u8_wr_LI1_SeStatusVer(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus] & 0xf9U) | \
    (((A) << 1U) & 0x06U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus); \
    } \

 
/* static access macros for signal LI1_SeStatusInit */
 #define l_u8_rd_LI1_SeStatusInit_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList]) >> 3U) & 0x03U))

#define l_u8_rd_LI1_SeStatusInit_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus]) >> 3U) & 0x03U))


#define l_u8_wr_LI1_SeStatusInit(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus] & 0xe7U) | \
    (((A) << 3U) & 0x18U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus); \
    } \

 
/* static access macros for signal LI1_SeStatusOp */
 #define l_u8_rd_LI1_SeStatusOp_SeVersionList() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList]) >> 5U) & 0x03U))

#define l_u8_rd_LI1_SeStatusOp_SeStatus() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus]) >> 5U) & 0x03U))


#define l_u8_wr_LI1_SeStatusOp(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList); \
    } \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus] & 0x9fU) | \
    (((A) << 5U) & 0x60U)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus); \
    } \

 
/* static access macros for signal LI1_SeVersionPageNumber */
 #define l_u8_rd_LI1_SeVersionPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeVersionPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeVersionPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeVersionPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeVersionPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_SeVersionPageNumber); \
    }

 
/* static access macros for signal LI1_SeSupportedVersion1 */
 #define l_u8_rd_LI1_SeSupportedVersion1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeSupportedVersion1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion1); \
    }

 
/* static access macros for signal LI1_SeSupportedVersion2 */
 #define l_u8_rd_LI1_SeSupportedVersion2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeSupportedVersion2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion2); \
    }

 
/* static access macros for signal LI1_SeSupportedVersion3 */
 #define l_u8_rd_LI1_SeSupportedVersion3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeSupportedVersion3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion3); \
    }

 
/* static access macros for signal LI1_SeSupportedVersion4 */
 #define l_u8_rd_LI1_SeSupportedVersion4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion4]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeSupportedVersion4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion4); \
    }

 
/* static access macros for signal LI1_SeSupportedVersion5 */
 #define l_u8_rd_LI1_SeSupportedVersion5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion5]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeSupportedVersion5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion5); \
    }

 
/* static access macros for signal LI1_SeAvailableCurrentL1 */
 #define l_u8_rd_LI1_SeAvailableCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeAvailableCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL1); \
    }

 
/* static access macros for signal LI1_SeAvailableCurrentL2 */
 #define l_u8_rd_LI1_SeAvailableCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeAvailableCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL2); \
    }

 
/* static access macros for signal LI1_SeAvailableCurrentL3 */
 #define l_u8_rd_LI1_SeAvailableCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeAvailableCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL3); \
    }

 
/* static access macros for signal LI1_SeAvailableCurrentN */
 #define l_u8_rd_LI1_SeAvailableCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeAvailableCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentN); \
    }

 
/* static access macros for signal LI1_EvPresentCurrentL1 */
 #define l_u8_rd_LI1_EvPresentCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvPresentCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL1); \
    }

 
/* static access macros for signal LI1_EvPresentCurrentL2 */
 #define l_u8_rd_LI1_EvPresentCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvPresentCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL2); \
    }

 
/* static access macros for signal LI1_EvPresentCurrentL3 */
 #define l_u8_rd_LI1_EvPresentCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvPresentCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL3); \
    }

 
/* static access macros for signal LI1_EvPresentCurrentN */
 #define l_u8_rd_LI1_EvPresentCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvPresentCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentN); \
    }

 
/* static access macros for signal LI1_SeNomVoltageL1N */
 #define l_u16_rd_LI1_SeNomVoltageL1N() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_SeNomVoltageL1N(A) \
    { \
    buffer_backup_data[1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N]; \
    lin_frame_updating_flag_tbl[LI1_SeNomVoltages] |= (1U << 1); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[1U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1U]; \
    lin_frame_updating_flag_tbl[LI1_SeNomVoltages] |= (1U << (1 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_SeNomVoltages] &= (~(0x03 << 1)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageL1N); \
    }

 
/* static access macros for signal LI1_SeNomVoltageLL */
 #define l_u16_rd_LI1_SeNomVoltageLL() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_SeNomVoltageLL(A) \
    { \
    buffer_backup_data[3U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL]; \
    lin_frame_updating_flag_tbl[LI1_SeNomVoltages] |= (1U << 3); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[3U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1U]; \
    lin_frame_updating_flag_tbl[LI1_SeNomVoltages] |= (1U << (3 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_SeNomVoltages] &= (~(0x03 << 3)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageLL); \
    }

 
/* static access macros for signal LI1_SeFrequency */
 #define l_u8_rd_LI1_SeFrequency() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeFrequency]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeFrequency(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeFrequency] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeFrequency] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeFrequency],\
         LIN_FLAG_BIT_OFFSET_LI1_SeFrequency); \
    }

 
/* static access macros for signal LI1_SeMaxCurrentL1 */
 #define l_u8_rd_LI1_SeMaxCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeMaxCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL1); \
    }

 
/* static access macros for signal LI1_SeMaxCurrentL2 */
 #define l_u8_rd_LI1_SeMaxCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeMaxCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL2); \
    }

 
/* static access macros for signal LI1_SeMaxCurrentL3 */
 #define l_u8_rd_LI1_SeMaxCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeMaxCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL3); \
    }

 
/* static access macros for signal LI1_SeMaxCurrentN */
 #define l_u8_rd_LI1_SeMaxCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeMaxCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentN); \
    }

 
/* static access macros for signal LI1_EvMaxVoltageL1N */
 #define l_u16_rd_LI1_EvMaxVoltageL1N() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_EvMaxVoltageL1N(A) \
    { \
    buffer_backup_data[1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N]; \
    lin_frame_updating_flag_tbl[LI1_EvMaxVoltageList] |= (1U << 1); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[1U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1U]; \
    lin_frame_updating_flag_tbl[LI1_EvMaxVoltageList] |= (1U << (1 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_EvMaxVoltageList] &= (~(0x03 << 1)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageL1N); \
    }

 
/* static access macros for signal LI1_EvMaxVoltageLL */
 #define l_u16_rd_LI1_EvMaxVoltageLL() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_EvMaxVoltageLL(A) \
    { \
    buffer_backup_data[3U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL]; \
    lin_frame_updating_flag_tbl[LI1_EvMaxVoltageList] |= (1U << 3); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[3U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1U]; \
    lin_frame_updating_flag_tbl[LI1_EvMaxVoltageList] |= (1U << (3 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_EvMaxVoltageList] &= (~(0x03 << 3)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageLL); \
    }

 
/* static access macros for signal LI1_EvFrequencies */
 #define l_u8_rd_LI1_EvFrequencies() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvFrequencies]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvFrequencies(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvFrequencies] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvFrequencies] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvFrequencies],\
         LIN_FLAG_BIT_OFFSET_LI1_EvFrequencies); \
    }

 
/* static access macros for signal LI1_EvMinVoltageL1N */
 #define l_u16_rd_LI1_EvMinVoltageL1N() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_EvMinVoltageL1N(A) \
    { \
    buffer_backup_data[1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N]; \
    lin_frame_updating_flag_tbl[LI1_EvMinVoltageList] |= (1U << 1); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[1U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1U]; \
    lin_frame_updating_flag_tbl[LI1_EvMinVoltageList] |= (1U << (1 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_EvMinVoltageList] &= (~(0x03 << 1)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageL1N); \
    }

 
/* static access macros for signal LI1_EvMinVoltageLL */
 #define l_u16_rd_LI1_EvMinVoltageLL() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_EvMinVoltageLL(A) \
    { \
    buffer_backup_data[3U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL]; \
    lin_frame_updating_flag_tbl[LI1_EvMinVoltageList] |= (1U << 3); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[3U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1U]; \
    lin_frame_updating_flag_tbl[LI1_EvMinVoltageList] |= (1U << (3 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_EvMinVoltageList] &= (~(0x03 << 3)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageLL); \
    }

 
/* static access macros for signal LI1_EvMaxCurrentL1 */
 #define l_u8_rd_LI1_EvMaxCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMaxCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL1); \
    }

 
/* static access macros for signal LI1_EvMaxCurrentL2 */
 #define l_u8_rd_LI1_EvMaxCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMaxCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL2); \
    }

 
/* static access macros for signal LI1_EvMaxCurrentL3 */
 #define l_u8_rd_LI1_EvMaxCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMaxCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL3); \
    }

 
/* static access macros for signal LI1_EvMaxCurrentN */
 #define l_u8_rd_LI1_EvMaxCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMaxCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentN); \
    }

 
/* static access macros for signal LI1_EvMinCurrentL1 */
 #define l_u8_rd_LI1_EvMinCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMinCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL1); \
    }

 
/* static access macros for signal LI1_EvMinCurrentL2 */
 #define l_u8_rd_LI1_EvMinCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMinCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL2); \
    }

 
/* static access macros for signal LI1_EvMinCurrentL3 */
 #define l_u8_rd_LI1_EvMinCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvMinCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL3); \
    }

 
/* static access macros for signal LI1_EvInfoEntry1 */
 #define l_u8_rd_LI1_EvInfoEntry1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoEntry1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry1); \
    }

 
/* static access macros for signal LI1_EvInfoEntry2 */
 #define l_u8_rd_LI1_EvInfoEntry2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoEntry2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry2); \
    }

 
/* static access macros for signal LI1_EvInfoEntry3 */
 #define l_u8_rd_LI1_EvInfoEntry3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoEntry3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry3); \
    }

 
/* static access macros for signal LI1_EvInfoEntry4 */
 #define l_u8_rd_LI1_EvInfoEntry4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry4]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoEntry4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry4); \
    }

 
/* static access macros for signal LI1_EvInfoEntry5 */
 #define l_u8_rd_LI1_EvInfoEntry5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry5]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoEntry5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry5); \
    }

 
/* static access macros for signal LI1_EvInfoEntry6 */
 #define l_u8_rd_LI1_EvInfoEntry6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry6]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoEntry6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry6); \
    }

 
/* static access macros for signal LI1_SeInfoEntry1 */
 #define l_u8_rd_LI1_SeInfoEntry1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoEntry1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry1); \
    }

 
/* static access macros for signal LI1_SeInfoEntry2 */
 #define l_u8_rd_LI1_SeInfoEntry2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoEntry2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry2); \
    }

 
/* static access macros for signal LI1_SeInfoEntry3 */
 #define l_u8_rd_LI1_SeInfoEntry3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoEntry3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry3); \
    }

 
/* static access macros for signal LI1_SeInfoEntry4 */
 #define l_u8_rd_LI1_SeInfoEntry4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry4]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoEntry4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry4); \
    }

 
/* static access macros for signal LI1_SeInfoEntry5 */
 #define l_u8_rd_LI1_SeInfoEntry5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry5]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoEntry5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry5); \
    }

 
/* static access macros for signal LI1_SeInfoEntry6 */
 #define l_u8_rd_LI1_SeInfoEntry6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry6]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoEntry6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry6); \
    }

 
/* static access macros for signal LI1_EvInfoPageNumber */
 #define l_u8_rd_LI1_EvInfoPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvInfoPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoPageNumber); \
    }

 
/* static access macros for signal LI1_SeInfoPageNumber */
 #define l_u8_rd_LI1_SeInfoPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_SeInfoPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoPageNumber); \
    }

 
/* static access macros for signal LI1_CaVersion */
 #define l_u8_rd_LI1_CaVersion() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaVersion]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_CaVersion(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaVersion] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaVersion] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaVersion],\
         LIN_FLAG_BIT_OFFSET_LI1_CaVersion); \
    }

/* static access macros for signal LI1_CaResponseError */

 #define l_bool_rd_LI1_CaResponseError() \
    (LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaResponseError], \
    LIN_BIT_OFFSET_LI1_CaResponseError))

#define l_bool_wr_LI1_CaResponseError(A) \
    {(A) ? \
    (LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaResponseError], \
    LIN_BIT_OFFSET_LI1_CaResponseError)):\
    (LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaResponseError], \
    LIN_BIT_OFFSET_LI1_CaResponseError));\
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaResponseError],\
         LIN_FLAG_BIT_OFFSET_LI1_CaResponseError);} 
/* static access macros for signal LI1_CaMaxVoltage */
 #define l_u16_rd_LI1_CaMaxVoltage() \
    ((l_u16)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage] + (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage + 1U] << 8U)) >> 0U) & 0xffffU))


#define l_u16_wr_LI1_CaMaxVoltage(A) \
    { \
    buffer_backup_data[2U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage]; \
    lin_frame_updating_flag_tbl[LI1_CaProperties] |= (1U << 2); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    buffer_backup_data[2U + 1U] =  lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage + 1U]; \
    lin_frame_updating_flag_tbl[LI1_CaProperties] |= (1U << (2 + 1U)); \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage + 1U] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxVoltage + 1U] & 0x00U) | \
    (((A) >> 8U) & 0xffU)); \
    lin_frame_updating_flag_tbl[LI1_CaProperties] &= (~(0x03 << 2)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxVoltage],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxVoltage); \
    }

 
/* static access macros for signal LI1_CaMaxCurrentL1 */
 #define l_u8_rd_LI1_CaMaxCurrentL1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_CaMaxCurrentL1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL1); \
    }

 
/* static access macros for signal LI1_CaMaxCurrentL2 */
 #define l_u8_rd_LI1_CaMaxCurrentL2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_CaMaxCurrentL2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL2); \
    }

 
/* static access macros for signal LI1_CaMaxCurrentL3 */
 #define l_u8_rd_LI1_CaMaxCurrentL3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_CaMaxCurrentL3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentL3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL3); \
    }

 
/* static access macros for signal LI1_CaMaxCurrentN */
 #define l_u8_rd_LI1_CaMaxCurrentN() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentN]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_CaMaxCurrentN(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentN] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_CaMaxCurrentN] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentN); \
    }

 
/* static access macros for signal LI1_StErrorPageNumber */
 #define l_u8_rd_LI1_StErrorPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorPageNumber); \
    }

 
/* static access macros for signal LI1_StErrorCode1 */
 #define l_u8_rd_LI1_StErrorCode1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorCode1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode1); \
    }

 
/* static access macros for signal LI1_StErrorCode2 */
 #define l_u8_rd_LI1_StErrorCode2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorCode2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode2); \
    }

 
/* static access macros for signal LI1_StErrorCode3 */
 #define l_u8_rd_LI1_StErrorCode3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorCode3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode3); \
    }

 
/* static access macros for signal LI1_StErrorCode4 */
 #define l_u8_rd_LI1_StErrorCode4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode4]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorCode4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode4); \
    }

 
/* static access macros for signal LI1_StErrorCode5 */
 #define l_u8_rd_LI1_StErrorCode5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode5]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorCode5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode5); \
    }

 
/* static access macros for signal LI1_StErrorCode6 */
 #define l_u8_rd_LI1_StErrorCode6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode6]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_StErrorCode6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode6); \
    }

 
/* static access macros for signal LI1_EvErrorPageNumber */
 #define l_u8_rd_LI1_EvErrorPageNumber() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorPageNumber]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorPageNumber(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorPageNumber] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorPageNumber] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorPageNumber); \
    }

 
/* static access macros for signal LI1_EvErrorCode1 */
 #define l_u8_rd_LI1_EvErrorCode1() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode1]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorCode1(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode1] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode1] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode1); \
    }

 
/* static access macros for signal LI1_EvErrorCode2 */
 #define l_u8_rd_LI1_EvErrorCode2() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode2]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorCode2(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode2] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode2] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode2); \
    }

 
/* static access macros for signal LI1_EvErrorCode3 */
 #define l_u8_rd_LI1_EvErrorCode3() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode3]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorCode3(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode3] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode3] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode3); \
    }

 
/* static access macros for signal LI1_EvErrorCode4 */
 #define l_u8_rd_LI1_EvErrorCode4() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode4]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorCode4(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode4] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode4] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode4); \
    }

 
/* static access macros for signal LI1_EvErrorCode5 */
 #define l_u8_rd_LI1_EvErrorCode5() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode5]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorCode5(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode5] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode5] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode5); \
    }

 
/* static access macros for signal LI1_EvErrorCode6 */
 #define l_u8_rd_LI1_EvErrorCode6() \
    ((l_u8)  (((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode6]) >> 0U) & 0xffU))


#define l_u8_wr_LI1_EvErrorCode6(A) \
    { \
    lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode6] = \
    (l_u8)((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode6] & 0x00U) | \
    (((A) << 0U) & 0xffU)); \
    LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode6); \
    }




/* Signal flag APIs */
 #define l_flg_tst_LI0_EvSelectedVersion_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList)
#define l_flg_tst_LI0_EvSelectedVersion_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus)
#define l_flg_tst_LI0_EvSelectedVersion_EvPresentCurrentList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList)
#define l_flg_tst_LI0_EvSelectedVersion_EvMaxVoltageList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList)
#define l_flg_tst_LI0_EvSelectedVersion_EvMinVoltageList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList)
#define l_flg_tst_LI0_EvSelectedVersion_EvMaxMinCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents)
#define l_flg_tst_LI0_EvSelectedVersion_EvInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList)
#define l_flg_tst_LI0_EvSelectedVersion_EvErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList)

#define l_flg_clr_LI0_EvSelectedVersion_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrentList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltageList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltageList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList);}\
 #define l_flg_tst_LI0_EvResponseError_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList)
#define l_flg_tst_LI0_EvResponseError_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus)

#define l_flg_clr_LI0_EvResponseError_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus);}\
 #define l_flg_tst_LI0_EvStatusVer_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList)
#define l_flg_tst_LI0_EvStatusVer_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus)

#define l_flg_clr_LI0_EvStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus);}\
 #define l_flg_tst_LI0_EvStatusInit_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList)
#define l_flg_tst_LI0_EvStatusInit_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus)

#define l_flg_clr_LI0_EvStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus);}\
 #define l_flg_tst_LI0_EvStatusOp_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList)
#define l_flg_tst_LI0_EvStatusOp_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus)

#define l_flg_clr_LI0_EvStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus);}\
 #define l_flg_tst_LI0_EvAwake_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList)
#define l_flg_tst_LI0_EvAwake_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus)

#define l_flg_clr_LI0_EvAwake_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus);}\
#define l_flg_tst_LI0_EvVersionPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvVersionPageNumber)
#define l_flg_clr_LI0_EvVersionPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvVersionPageNumber)
#define l_flg_tst_LI0_EvSupportedVersion1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion1)
#define l_flg_clr_LI0_EvSupportedVersion1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion1)
#define l_flg_tst_LI0_EvSupportedVersion2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion2)
#define l_flg_clr_LI0_EvSupportedVersion2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion2)
#define l_flg_tst_LI0_EvSupportedVersion3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion3)
#define l_flg_clr_LI0_EvSupportedVersion3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion3)
#define l_flg_tst_LI0_EvSupportedVersion4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion4)
#define l_flg_clr_LI0_EvSupportedVersion4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion4)
#define l_flg_tst_LI0_EvSupportedVersion5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion5)
#define l_flg_clr_LI0_EvSupportedVersion5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion5)
#define l_flg_tst_LI0_EvRequestedCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL1)
#define l_flg_clr_LI0_EvRequestedCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL1)
#define l_flg_tst_LI0_EvRequestedCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL2)
#define l_flg_clr_LI0_EvRequestedCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL2)
#define l_flg_tst_LI0_EvRequestedCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL3)
#define l_flg_clr_LI0_EvRequestedCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL3)
#define l_flg_tst_LI0_EvRequestedCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentN)
#define l_flg_clr_LI0_EvRequestedCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentN)
 #define l_flg_tst_LI0_SeSelectedVersion_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList)
#define l_flg_tst_LI0_SeSelectedVersion_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus)
#define l_flg_tst_LI0_SeSelectedVersion_SeNomVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages)
#define l_flg_tst_LI0_SeSelectedVersion_SeMaxCurrentList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList)
#define l_flg_tst_LI0_SeSelectedVersion_SeInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList)
#define l_flg_tst_LI0_SeSelectedVersion_StErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList)

#define l_flg_clr_LI0_SeSelectedVersion_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrentList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList);}\
 #define l_flg_tst_LI0_SeStatusVer_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList)
#define l_flg_tst_LI0_SeStatusVer_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus)

#define l_flg_clr_LI0_SeStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus);}\
 #define l_flg_tst_LI0_SeStatusInit_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList)
#define l_flg_tst_LI0_SeStatusInit_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus)

#define l_flg_clr_LI0_SeStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus);}\
 #define l_flg_tst_LI0_SeStatusOp_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList)
#define l_flg_tst_LI0_SeStatusOp_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus)

#define l_flg_clr_LI0_SeStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus);}\
#define l_flg_tst_LI0_SeVersionPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_SeVersionPageNumber)
#define l_flg_clr_LI0_SeVersionPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_SeVersionPageNumber)
#define l_flg_tst_LI0_SeSupportedVersion1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion1)
#define l_flg_clr_LI0_SeSupportedVersion1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion1)
#define l_flg_tst_LI0_SeSupportedVersion2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion2)
#define l_flg_clr_LI0_SeSupportedVersion2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion2)
#define l_flg_tst_LI0_SeSupportedVersion3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion3)
#define l_flg_clr_LI0_SeSupportedVersion3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion3)
#define l_flg_tst_LI0_SeSupportedVersion4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion4)
#define l_flg_clr_LI0_SeSupportedVersion4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion4)
#define l_flg_tst_LI0_SeSupportedVersion5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion5)
#define l_flg_clr_LI0_SeSupportedVersion5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion5)
#define l_flg_tst_LI0_SeAvailableCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL1)
#define l_flg_clr_LI0_SeAvailableCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL1)
#define l_flg_tst_LI0_SeAvailableCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL2)
#define l_flg_clr_LI0_SeAvailableCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL2)
#define l_flg_tst_LI0_SeAvailableCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL3)
#define l_flg_clr_LI0_SeAvailableCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL3)
#define l_flg_tst_LI0_SeAvailableCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentN)
#define l_flg_clr_LI0_SeAvailableCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentN)
#define l_flg_tst_LI0_EvPresentCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL1)
#define l_flg_clr_LI0_EvPresentCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL1)
#define l_flg_tst_LI0_EvPresentCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL2)
#define l_flg_clr_LI0_EvPresentCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL2)
#define l_flg_tst_LI0_EvPresentCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL3)
#define l_flg_clr_LI0_EvPresentCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL3)
#define l_flg_tst_LI0_EvPresentCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentN)
#define l_flg_clr_LI0_EvPresentCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentN)
#define l_flg_tst_LI0_SeNomVoltageL1N_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageL1N)
#define l_flg_clr_LI0_SeNomVoltageL1N_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageL1N)
#define l_flg_tst_LI0_SeNomVoltageLL_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageLL)
#define l_flg_clr_LI0_SeNomVoltageLL_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageLL)
#define l_flg_tst_LI0_SeFrequency_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeFrequency],\
         LIN_FLAG_BIT_OFFSET_LI0_SeFrequency)
#define l_flg_clr_LI0_SeFrequency_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeFrequency],\
         LIN_FLAG_BIT_OFFSET_LI0_SeFrequency)
#define l_flg_tst_LI0_SeMaxCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL1)
#define l_flg_clr_LI0_SeMaxCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL1)
#define l_flg_tst_LI0_SeMaxCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL2)
#define l_flg_clr_LI0_SeMaxCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL2)
#define l_flg_tst_LI0_SeMaxCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL3)
#define l_flg_clr_LI0_SeMaxCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL3)
#define l_flg_tst_LI0_SeMaxCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentN)
#define l_flg_clr_LI0_SeMaxCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentN)
#define l_flg_tst_LI0_EvMaxVoltageL1N_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageL1N)
#define l_flg_clr_LI0_EvMaxVoltageL1N_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageL1N)
#define l_flg_tst_LI0_EvMaxVoltageLL_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageLL)
#define l_flg_clr_LI0_EvMaxVoltageLL_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageLL)
#define l_flg_tst_LI0_EvFrequencies_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvFrequencies],\
         LIN_FLAG_BIT_OFFSET_LI0_EvFrequencies)
#define l_flg_clr_LI0_EvFrequencies_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvFrequencies],\
         LIN_FLAG_BIT_OFFSET_LI0_EvFrequencies)
#define l_flg_tst_LI0_EvMinVoltageL1N_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageL1N)
#define l_flg_clr_LI0_EvMinVoltageL1N_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageL1N)
#define l_flg_tst_LI0_EvMinVoltageLL_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageLL)
#define l_flg_clr_LI0_EvMinVoltageLL_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageLL)
#define l_flg_tst_LI0_EvMaxCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL1)
#define l_flg_clr_LI0_EvMaxCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL1)
#define l_flg_tst_LI0_EvMaxCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL2)
#define l_flg_clr_LI0_EvMaxCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL2)
#define l_flg_tst_LI0_EvMaxCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL3)
#define l_flg_clr_LI0_EvMaxCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL3)
#define l_flg_tst_LI0_EvMaxCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentN)
#define l_flg_clr_LI0_EvMaxCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentN)
#define l_flg_tst_LI0_EvMinCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL1)
#define l_flg_clr_LI0_EvMinCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL1)
#define l_flg_tst_LI0_EvMinCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL2)
#define l_flg_clr_LI0_EvMinCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL2)
#define l_flg_tst_LI0_EvMinCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL3)
#define l_flg_clr_LI0_EvMinCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL3)
#define l_flg_tst_LI0_EvInfoEntry1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry1)
#define l_flg_clr_LI0_EvInfoEntry1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry1)
#define l_flg_tst_LI0_EvInfoEntry2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry2)
#define l_flg_clr_LI0_EvInfoEntry2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry2)
#define l_flg_tst_LI0_EvInfoEntry3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry3)
#define l_flg_clr_LI0_EvInfoEntry3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry3)
#define l_flg_tst_LI0_EvInfoEntry4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry4)
#define l_flg_clr_LI0_EvInfoEntry4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry4)
#define l_flg_tst_LI0_EvInfoEntry5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry5)
#define l_flg_clr_LI0_EvInfoEntry5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry5)
#define l_flg_tst_LI0_EvInfoEntry6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry6)
#define l_flg_clr_LI0_EvInfoEntry6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry6)
#define l_flg_tst_LI0_SeInfoEntry1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry1)
#define l_flg_clr_LI0_SeInfoEntry1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry1)
#define l_flg_tst_LI0_SeInfoEntry2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry2)
#define l_flg_clr_LI0_SeInfoEntry2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry2)
#define l_flg_tst_LI0_SeInfoEntry3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry3)
#define l_flg_clr_LI0_SeInfoEntry3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry3)
#define l_flg_tst_LI0_SeInfoEntry4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry4)
#define l_flg_clr_LI0_SeInfoEntry4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry4)
#define l_flg_tst_LI0_SeInfoEntry5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry5)
#define l_flg_clr_LI0_SeInfoEntry5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry5)
#define l_flg_tst_LI0_SeInfoEntry6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry6)
#define l_flg_clr_LI0_SeInfoEntry6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry6)
#define l_flg_tst_LI0_EvInfoPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoPageNumber)
#define l_flg_clr_LI0_EvInfoPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoPageNumber)
#define l_flg_tst_LI0_SeInfoPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoPageNumber)
#define l_flg_clr_LI0_SeInfoPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoPageNumber)
#define l_flg_tst_LI0_CaVersion_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaVersion],\
         LIN_FLAG_BIT_OFFSET_LI0_CaVersion)
#define l_flg_clr_LI0_CaVersion_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaVersion],\
         LIN_FLAG_BIT_OFFSET_LI0_CaVersion)
#define l_flg_tst_LI0_CaResponseError_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaResponseError],\
         LIN_FLAG_BIT_OFFSET_LI0_CaResponseError)
#define l_flg_clr_LI0_CaResponseError_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaResponseError],\
         LIN_FLAG_BIT_OFFSET_LI0_CaResponseError)
#define l_flg_tst_LI0_CaMaxVoltage_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxVoltage],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxVoltage)
#define l_flg_clr_LI0_CaMaxVoltage_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxVoltage],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxVoltage)
#define l_flg_tst_LI0_CaMaxCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL1)
#define l_flg_clr_LI0_CaMaxCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL1)
#define l_flg_tst_LI0_CaMaxCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL2)
#define l_flg_clr_LI0_CaMaxCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL2)
#define l_flg_tst_LI0_CaMaxCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL3)
#define l_flg_clr_LI0_CaMaxCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentL3)
#define l_flg_tst_LI0_CaMaxCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentN)
#define l_flg_clr_LI0_CaMaxCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_CaMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI0_CaMaxCurrentN)
#define l_flg_tst_LI0_StErrorPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorPageNumber)
#define l_flg_clr_LI0_StErrorPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorPageNumber)
#define l_flg_tst_LI0_StErrorCode1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode1)
#define l_flg_clr_LI0_StErrorCode1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode1)
#define l_flg_tst_LI0_StErrorCode2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode2)
#define l_flg_clr_LI0_StErrorCode2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode2)
#define l_flg_tst_LI0_StErrorCode3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode3)
#define l_flg_clr_LI0_StErrorCode3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode3)
#define l_flg_tst_LI0_StErrorCode4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode4)
#define l_flg_clr_LI0_StErrorCode4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode4)
#define l_flg_tst_LI0_StErrorCode5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode5)
#define l_flg_clr_LI0_StErrorCode5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode5)
#define l_flg_tst_LI0_StErrorCode6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode6)
#define l_flg_clr_LI0_StErrorCode6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorCode6)
#define l_flg_tst_LI0_EvErrorPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorPageNumber)
#define l_flg_clr_LI0_EvErrorPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorPageNumber)
#define l_flg_tst_LI0_EvErrorCode1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode1)
#define l_flg_clr_LI0_EvErrorCode1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode1)
#define l_flg_tst_LI0_EvErrorCode2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode2)
#define l_flg_clr_LI0_EvErrorCode2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode2)
#define l_flg_tst_LI0_EvErrorCode3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode3)
#define l_flg_clr_LI0_EvErrorCode3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode3)
#define l_flg_tst_LI0_EvErrorCode4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode4)
#define l_flg_clr_LI0_EvErrorCode4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode4)
#define l_flg_tst_LI0_EvErrorCode5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode5)
#define l_flg_clr_LI0_EvErrorCode5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode5)
#define l_flg_tst_LI0_EvErrorCode6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode6)
#define l_flg_clr_LI0_EvErrorCode6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode6)

 #define l_flg_tst_LI1_EvSelectedVersion_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList)
#define l_flg_tst_LI1_EvSelectedVersion_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus)
#define l_flg_tst_LI1_EvSelectedVersion_EvPresentCurrentList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList)
#define l_flg_tst_LI1_EvSelectedVersion_EvMaxVoltageList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList)
#define l_flg_tst_LI1_EvSelectedVersion_EvMinVoltageList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList)
#define l_flg_tst_LI1_EvSelectedVersion_EvMaxMinCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents)
#define l_flg_tst_LI1_EvSelectedVersion_EvInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList)
#define l_flg_tst_LI1_EvSelectedVersion_EvErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList)

#define l_flg_clr_LI1_EvSelectedVersion_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrentList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltageList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltageList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList);}\
 #define l_flg_tst_LI1_EvResponseError_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList)
#define l_flg_tst_LI1_EvResponseError_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus)

#define l_flg_clr_LI1_EvResponseError_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus);}\
 #define l_flg_tst_LI1_EvStatusVer_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList)
#define l_flg_tst_LI1_EvStatusVer_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus)

#define l_flg_clr_LI1_EvStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus);}\
 #define l_flg_tst_LI1_EvStatusInit_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList)
#define l_flg_tst_LI1_EvStatusInit_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus)

#define l_flg_clr_LI1_EvStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus);}\
 #define l_flg_tst_LI1_EvStatusOp_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList)
#define l_flg_tst_LI1_EvStatusOp_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus)

#define l_flg_clr_LI1_EvStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus);}\
 #define l_flg_tst_LI1_EvAwake_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList)
#define l_flg_tst_LI1_EvAwake_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus)

#define l_flg_clr_LI1_EvAwake_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus);}\
#define l_flg_tst_LI1_EvVersionPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvVersionPageNumber)
#define l_flg_clr_LI1_EvVersionPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvVersionPageNumber)
#define l_flg_tst_LI1_EvSupportedVersion1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion1)
#define l_flg_clr_LI1_EvSupportedVersion1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion1)
#define l_flg_tst_LI1_EvSupportedVersion2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion2)
#define l_flg_clr_LI1_EvSupportedVersion2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion2)
#define l_flg_tst_LI1_EvSupportedVersion3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion3)
#define l_flg_clr_LI1_EvSupportedVersion3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion3)
#define l_flg_tst_LI1_EvSupportedVersion4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion4)
#define l_flg_clr_LI1_EvSupportedVersion4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion4)
#define l_flg_tst_LI1_EvSupportedVersion5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion5)
#define l_flg_clr_LI1_EvSupportedVersion5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion5)
#define l_flg_tst_LI1_EvRequestedCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL1)
#define l_flg_clr_LI1_EvRequestedCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL1)
#define l_flg_tst_LI1_EvRequestedCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL2)
#define l_flg_clr_LI1_EvRequestedCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL2)
#define l_flg_tst_LI1_EvRequestedCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL3)
#define l_flg_clr_LI1_EvRequestedCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL3)
#define l_flg_tst_LI1_EvRequestedCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentN)
#define l_flg_clr_LI1_EvRequestedCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentN)
 #define l_flg_tst_LI1_SeSelectedVersion_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList)
#define l_flg_tst_LI1_SeSelectedVersion_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus)
#define l_flg_tst_LI1_SeSelectedVersion_SeNomVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages)
#define l_flg_tst_LI1_SeSelectedVersion_SeMaxCurrentList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList)
#define l_flg_tst_LI1_SeSelectedVersion_SeInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList)
#define l_flg_tst_LI1_SeSelectedVersion_StErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList)

#define l_flg_clr_LI1_SeSelectedVersion_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrentList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList);}\
 #define l_flg_tst_LI1_SeStatusVer_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList)
#define l_flg_tst_LI1_SeStatusVer_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus)

#define l_flg_clr_LI1_SeStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus);}\
 #define l_flg_tst_LI1_SeStatusInit_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList)
#define l_flg_tst_LI1_SeStatusInit_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus)

#define l_flg_clr_LI1_SeStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus);}\
 #define l_flg_tst_LI1_SeStatusOp_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList)
#define l_flg_tst_LI1_SeStatusOp_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus)

#define l_flg_clr_LI1_SeStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList);}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus);}\
#define l_flg_tst_LI1_SeVersionPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_SeVersionPageNumber)
#define l_flg_clr_LI1_SeVersionPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeVersionPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_SeVersionPageNumber)
#define l_flg_tst_LI1_SeSupportedVersion1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion1)
#define l_flg_clr_LI1_SeSupportedVersion1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion1)
#define l_flg_tst_LI1_SeSupportedVersion2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion2)
#define l_flg_clr_LI1_SeSupportedVersion2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion2)
#define l_flg_tst_LI1_SeSupportedVersion3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion3)
#define l_flg_clr_LI1_SeSupportedVersion3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion3)
#define l_flg_tst_LI1_SeSupportedVersion4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion4)
#define l_flg_clr_LI1_SeSupportedVersion4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion4],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion4)
#define l_flg_tst_LI1_SeSupportedVersion5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion5)
#define l_flg_clr_LI1_SeSupportedVersion5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion5],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion5)
#define l_flg_tst_LI1_SeAvailableCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL1)
#define l_flg_clr_LI1_SeAvailableCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL1)
#define l_flg_tst_LI1_SeAvailableCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL2)
#define l_flg_clr_LI1_SeAvailableCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL2)
#define l_flg_tst_LI1_SeAvailableCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL3)
#define l_flg_clr_LI1_SeAvailableCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL3)
#define l_flg_tst_LI1_SeAvailableCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentN)
#define l_flg_clr_LI1_SeAvailableCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentN)
#define l_flg_tst_LI1_EvPresentCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL1)
#define l_flg_clr_LI1_EvPresentCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL1)
#define l_flg_tst_LI1_EvPresentCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL2)
#define l_flg_clr_LI1_EvPresentCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL2)
#define l_flg_tst_LI1_EvPresentCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL3)
#define l_flg_clr_LI1_EvPresentCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL3)
#define l_flg_tst_LI1_EvPresentCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentN)
#define l_flg_clr_LI1_EvPresentCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentN)
#define l_flg_tst_LI1_SeNomVoltageL1N_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageL1N)
#define l_flg_clr_LI1_SeNomVoltageL1N_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageL1N)
#define l_flg_tst_LI1_SeNomVoltageLL_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageLL)
#define l_flg_clr_LI1_SeNomVoltageLL_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageLL)
#define l_flg_tst_LI1_SeFrequency_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeFrequency],\
         LIN_FLAG_BIT_OFFSET_LI1_SeFrequency)
#define l_flg_clr_LI1_SeFrequency_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeFrequency],\
         LIN_FLAG_BIT_OFFSET_LI1_SeFrequency)
#define l_flg_tst_LI1_SeMaxCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL1)
#define l_flg_clr_LI1_SeMaxCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL1)
#define l_flg_tst_LI1_SeMaxCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL2)
#define l_flg_clr_LI1_SeMaxCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL2)
#define l_flg_tst_LI1_SeMaxCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL3)
#define l_flg_clr_LI1_SeMaxCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL3)
#define l_flg_tst_LI1_SeMaxCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentN)
#define l_flg_clr_LI1_SeMaxCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentN)
#define l_flg_tst_LI1_EvMaxVoltageL1N_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageL1N)
#define l_flg_clr_LI1_EvMaxVoltageL1N_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageL1N)
#define l_flg_tst_LI1_EvMaxVoltageLL_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageLL)
#define l_flg_clr_LI1_EvMaxVoltageLL_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageLL)
#define l_flg_tst_LI1_EvFrequencies_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvFrequencies],\
         LIN_FLAG_BIT_OFFSET_LI1_EvFrequencies)
#define l_flg_clr_LI1_EvFrequencies_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvFrequencies],\
         LIN_FLAG_BIT_OFFSET_LI1_EvFrequencies)
#define l_flg_tst_LI1_EvMinVoltageL1N_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageL1N)
#define l_flg_clr_LI1_EvMinVoltageL1N_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageL1N],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageL1N)
#define l_flg_tst_LI1_EvMinVoltageLL_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageLL)
#define l_flg_clr_LI1_EvMinVoltageLL_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageLL],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageLL)
#define l_flg_tst_LI1_EvMaxCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL1)
#define l_flg_clr_LI1_EvMaxCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL1)
#define l_flg_tst_LI1_EvMaxCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL2)
#define l_flg_clr_LI1_EvMaxCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL2)
#define l_flg_tst_LI1_EvMaxCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL3)
#define l_flg_clr_LI1_EvMaxCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL3)
#define l_flg_tst_LI1_EvMaxCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentN)
#define l_flg_clr_LI1_EvMaxCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentN)
#define l_flg_tst_LI1_EvMinCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL1)
#define l_flg_clr_LI1_EvMinCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL1)
#define l_flg_tst_LI1_EvMinCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL2)
#define l_flg_clr_LI1_EvMinCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL2)
#define l_flg_tst_LI1_EvMinCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL3)
#define l_flg_clr_LI1_EvMinCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL3)
#define l_flg_tst_LI1_EvInfoEntry1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry1)
#define l_flg_clr_LI1_EvInfoEntry1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry1)
#define l_flg_tst_LI1_EvInfoEntry2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry2)
#define l_flg_clr_LI1_EvInfoEntry2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry2)
#define l_flg_tst_LI1_EvInfoEntry3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry3)
#define l_flg_clr_LI1_EvInfoEntry3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry3)
#define l_flg_tst_LI1_EvInfoEntry4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry4)
#define l_flg_clr_LI1_EvInfoEntry4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry4)
#define l_flg_tst_LI1_EvInfoEntry5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry5)
#define l_flg_clr_LI1_EvInfoEntry5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry5)
#define l_flg_tst_LI1_EvInfoEntry6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry6)
#define l_flg_clr_LI1_EvInfoEntry6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry6)
#define l_flg_tst_LI1_SeInfoEntry1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry1)
#define l_flg_clr_LI1_SeInfoEntry1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry1)
#define l_flg_tst_LI1_SeInfoEntry2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry2)
#define l_flg_clr_LI1_SeInfoEntry2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry2],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry2)
#define l_flg_tst_LI1_SeInfoEntry3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry3)
#define l_flg_clr_LI1_SeInfoEntry3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry3],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry3)
#define l_flg_tst_LI1_SeInfoEntry4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry4)
#define l_flg_clr_LI1_SeInfoEntry4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry4],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry4)
#define l_flg_tst_LI1_SeInfoEntry5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry5)
#define l_flg_clr_LI1_SeInfoEntry5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry5],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry5)
#define l_flg_tst_LI1_SeInfoEntry6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry6)
#define l_flg_clr_LI1_SeInfoEntry6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry6],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry6)
#define l_flg_tst_LI1_EvInfoPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoPageNumber)
#define l_flg_clr_LI1_EvInfoPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoPageNumber)
#define l_flg_tst_LI1_SeInfoPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoPageNumber)
#define l_flg_clr_LI1_SeInfoPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoPageNumber)
#define l_flg_tst_LI1_CaVersion_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaVersion],\
         LIN_FLAG_BIT_OFFSET_LI1_CaVersion)
#define l_flg_clr_LI1_CaVersion_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaVersion],\
         LIN_FLAG_BIT_OFFSET_LI1_CaVersion)
#define l_flg_tst_LI1_CaResponseError_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaResponseError],\
         LIN_FLAG_BIT_OFFSET_LI1_CaResponseError)
#define l_flg_clr_LI1_CaResponseError_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaResponseError],\
         LIN_FLAG_BIT_OFFSET_LI1_CaResponseError)
#define l_flg_tst_LI1_CaMaxVoltage_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxVoltage],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxVoltage)
#define l_flg_clr_LI1_CaMaxVoltage_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxVoltage],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxVoltage)
#define l_flg_tst_LI1_CaMaxCurrentL1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL1)
#define l_flg_clr_LI1_CaMaxCurrentL1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL1],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL1)
#define l_flg_tst_LI1_CaMaxCurrentL2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL2)
#define l_flg_clr_LI1_CaMaxCurrentL2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL2],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL2)
#define l_flg_tst_LI1_CaMaxCurrentL3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL3)
#define l_flg_clr_LI1_CaMaxCurrentL3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentL3],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentL3)
#define l_flg_tst_LI1_CaMaxCurrentN_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentN)
#define l_flg_clr_LI1_CaMaxCurrentN_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_CaMaxCurrentN],\
         LIN_FLAG_BIT_OFFSET_LI1_CaMaxCurrentN)
#define l_flg_tst_LI1_StErrorPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorPageNumber)
#define l_flg_clr_LI1_StErrorPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorPageNumber)
#define l_flg_tst_LI1_StErrorCode1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode1)
#define l_flg_clr_LI1_StErrorCode1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode1)
#define l_flg_tst_LI1_StErrorCode2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode2)
#define l_flg_clr_LI1_StErrorCode2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode2)
#define l_flg_tst_LI1_StErrorCode3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode3)
#define l_flg_clr_LI1_StErrorCode3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode3)
#define l_flg_tst_LI1_StErrorCode4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode4)
#define l_flg_clr_LI1_StErrorCode4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode4)
#define l_flg_tst_LI1_StErrorCode5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode5)
#define l_flg_clr_LI1_StErrorCode5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode5)
#define l_flg_tst_LI1_StErrorCode6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode6)
#define l_flg_clr_LI1_StErrorCode6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorCode6)
#define l_flg_tst_LI1_EvErrorPageNumber_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorPageNumber)
#define l_flg_clr_LI1_EvErrorPageNumber_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorPageNumber],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorPageNumber)
#define l_flg_tst_LI1_EvErrorCode1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode1)
#define l_flg_clr_LI1_EvErrorCode1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode1],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode1)
#define l_flg_tst_LI1_EvErrorCode2_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode2)
#define l_flg_clr_LI1_EvErrorCode2_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode2],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode2)
#define l_flg_tst_LI1_EvErrorCode3_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode3)
#define l_flg_clr_LI1_EvErrorCode3_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode3],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode3)
#define l_flg_tst_LI1_EvErrorCode4_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode4)
#define l_flg_clr_LI1_EvErrorCode4_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode4],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode4)
#define l_flg_tst_LI1_EvErrorCode5_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode5)
#define l_flg_clr_LI1_EvErrorCode5_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode5],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode5)
#define l_flg_tst_LI1_EvErrorCode6_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode6)
#define l_flg_clr_LI1_EvErrorCode6_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode6],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode6)



/* Frame flag APIs */
   /* Interface_name = LI0 */
 #define l_flg_tst_LI0_SeVersionList_flag() \
          lin_frame_flag_tbl[LI0_SeVersionList]
 #define l_flg_clr_LI0_SeVersionList_flag() \
          lin_frame_flag_tbl[LI0_SeVersionList] = 0
 #define l_flg_tst_LI0_EvVersionList_flag() \
          lin_frame_flag_tbl[LI0_EvVersionList]
 #define l_flg_clr_LI0_EvVersionList_flag() \
          lin_frame_flag_tbl[LI0_EvVersionList] = 0
 #define l_flg_tst_LI0_SeStatus_flag() \
          lin_frame_flag_tbl[LI0_SeStatus]
 #define l_flg_clr_LI0_SeStatus_flag() \
          lin_frame_flag_tbl[LI0_SeStatus] = 0
 #define l_flg_tst_LI0_EvStatus_flag() \
          lin_frame_flag_tbl[LI0_EvStatus]
 #define l_flg_clr_LI0_EvStatus_flag() \
          lin_frame_flag_tbl[LI0_EvStatus] = 0
 #define l_flg_tst_LI0_EvPresentCurrentList_flag() \
          lin_frame_flag_tbl[LI0_EvPresentCurrentList]
 #define l_flg_clr_LI0_EvPresentCurrentList_flag() \
          lin_frame_flag_tbl[LI0_EvPresentCurrentList] = 0
 #define l_flg_tst_LI0_SeNomVoltages_flag() \
          lin_frame_flag_tbl[LI0_SeNomVoltages]
 #define l_flg_clr_LI0_SeNomVoltages_flag() \
          lin_frame_flag_tbl[LI0_SeNomVoltages] = 0
 #define l_flg_tst_LI0_SeMaxCurrentList_flag() \
          lin_frame_flag_tbl[LI0_SeMaxCurrentList]
 #define l_flg_clr_LI0_SeMaxCurrentList_flag() \
          lin_frame_flag_tbl[LI0_SeMaxCurrentList] = 0
 #define l_flg_tst_LI0_EvMaxVoltageList_flag() \
          lin_frame_flag_tbl[LI0_EvMaxVoltageList]
 #define l_flg_clr_LI0_EvMaxVoltageList_flag() \
          lin_frame_flag_tbl[LI0_EvMaxVoltageList] = 0
 #define l_flg_tst_LI0_EvMinVoltageList_flag() \
          lin_frame_flag_tbl[LI0_EvMinVoltageList]
 #define l_flg_clr_LI0_EvMinVoltageList_flag() \
          lin_frame_flag_tbl[LI0_EvMinVoltageList] = 0
 #define l_flg_tst_LI0_EvMaxMinCurrents_flag() \
          lin_frame_flag_tbl[LI0_EvMaxMinCurrents]
 #define l_flg_clr_LI0_EvMaxMinCurrents_flag() \
          lin_frame_flag_tbl[LI0_EvMaxMinCurrents] = 0
 #define l_flg_tst_LI0_CaProperties_flag() \
          lin_frame_flag_tbl[LI0_CaProperties]
 #define l_flg_clr_LI0_CaProperties_flag() \
          lin_frame_flag_tbl[LI0_CaProperties] = 0
 #define l_flg_tst_LI0_SeInfoList_flag() \
          lin_frame_flag_tbl[LI0_SeInfoList]
 #define l_flg_clr_LI0_SeInfoList_flag() \
          lin_frame_flag_tbl[LI0_SeInfoList] = 0
 #define l_flg_tst_LI0_EvInfoList_flag() \
          lin_frame_flag_tbl[LI0_EvInfoList]
 #define l_flg_clr_LI0_EvInfoList_flag() \
          lin_frame_flag_tbl[LI0_EvInfoList] = 0
 #define l_flg_tst_LI0_StErrorList_flag() \
          lin_frame_flag_tbl[LI0_StErrorList]
 #define l_flg_clr_LI0_StErrorList_flag() \
          lin_frame_flag_tbl[LI0_StErrorList] = 0
 #define l_flg_tst_LI0_EvErrorList_flag() \
          lin_frame_flag_tbl[LI0_EvErrorList]
 #define l_flg_clr_LI0_EvErrorList_flag() \
          lin_frame_flag_tbl[LI0_EvErrorList] = 0
 #define l_flg_tst_LI0_MasterReq_flag() \
          lin_frame_flag_tbl[LI0_MasterReq]
 #define l_flg_clr_LI0_MasterReq_flag() \
          lin_frame_flag_tbl[LI0_MasterReq] = 0
 #define l_flg_tst_LI0_SlaveResp_flag() \
          lin_frame_flag_tbl[LI0_SlaveResp]
 #define l_flg_clr_LI0_SlaveResp_flag() \
          lin_frame_flag_tbl[LI0_SlaveResp] = 0
   /* Interface_name = LI1 */
 #define l_flg_tst_LI1_SeVersionList_flag() \
          lin_frame_flag_tbl[LI1_SeVersionList]
 #define l_flg_clr_LI1_SeVersionList_flag() \
          lin_frame_flag_tbl[LI1_SeVersionList] = 0
 #define l_flg_tst_LI1_EvVersionList_flag() \
          lin_frame_flag_tbl[LI1_EvVersionList]
 #define l_flg_clr_LI1_EvVersionList_flag() \
          lin_frame_flag_tbl[LI1_EvVersionList] = 0
 #define l_flg_tst_LI1_SeStatus_flag() \
          lin_frame_flag_tbl[LI1_SeStatus]
 #define l_flg_clr_LI1_SeStatus_flag() \
          lin_frame_flag_tbl[LI1_SeStatus] = 0
 #define l_flg_tst_LI1_EvStatus_flag() \
          lin_frame_flag_tbl[LI1_EvStatus]
 #define l_flg_clr_LI1_EvStatus_flag() \
          lin_frame_flag_tbl[LI1_EvStatus] = 0
 #define l_flg_tst_LI1_EvPresentCurrentList_flag() \
          lin_frame_flag_tbl[LI1_EvPresentCurrentList]
 #define l_flg_clr_LI1_EvPresentCurrentList_flag() \
          lin_frame_flag_tbl[LI1_EvPresentCurrentList] = 0
 #define l_flg_tst_LI1_SeNomVoltages_flag() \
          lin_frame_flag_tbl[LI1_SeNomVoltages]
 #define l_flg_clr_LI1_SeNomVoltages_flag() \
          lin_frame_flag_tbl[LI1_SeNomVoltages] = 0
 #define l_flg_tst_LI1_SeMaxCurrentList_flag() \
          lin_frame_flag_tbl[LI1_SeMaxCurrentList]
 #define l_flg_clr_LI1_SeMaxCurrentList_flag() \
          lin_frame_flag_tbl[LI1_SeMaxCurrentList] = 0
 #define l_flg_tst_LI1_EvMaxVoltageList_flag() \
          lin_frame_flag_tbl[LI1_EvMaxVoltageList]
 #define l_flg_clr_LI1_EvMaxVoltageList_flag() \
          lin_frame_flag_tbl[LI1_EvMaxVoltageList] = 0
 #define l_flg_tst_LI1_EvMinVoltageList_flag() \
          lin_frame_flag_tbl[LI1_EvMinVoltageList]
 #define l_flg_clr_LI1_EvMinVoltageList_flag() \
          lin_frame_flag_tbl[LI1_EvMinVoltageList] = 0
 #define l_flg_tst_LI1_EvMaxMinCurrents_flag() \
          lin_frame_flag_tbl[LI1_EvMaxMinCurrents]
 #define l_flg_clr_LI1_EvMaxMinCurrents_flag() \
          lin_frame_flag_tbl[LI1_EvMaxMinCurrents] = 0
 #define l_flg_tst_LI1_CaProperties_flag() \
          lin_frame_flag_tbl[LI1_CaProperties]
 #define l_flg_clr_LI1_CaProperties_flag() \
          lin_frame_flag_tbl[LI1_CaProperties] = 0
 #define l_flg_tst_LI1_SeInfoList_flag() \
          lin_frame_flag_tbl[LI1_SeInfoList]
 #define l_flg_clr_LI1_SeInfoList_flag() \
          lin_frame_flag_tbl[LI1_SeInfoList] = 0
 #define l_flg_tst_LI1_EvInfoList_flag() \
          lin_frame_flag_tbl[LI1_EvInfoList]
 #define l_flg_clr_LI1_EvInfoList_flag() \
          lin_frame_flag_tbl[LI1_EvInfoList] = 0
 #define l_flg_tst_LI1_StErrorList_flag() \
          lin_frame_flag_tbl[LI1_StErrorList]
 #define l_flg_clr_LI1_StErrorList_flag() \
          lin_frame_flag_tbl[LI1_StErrorList] = 0
 #define l_flg_tst_LI1_EvErrorList_flag() \
          lin_frame_flag_tbl[LI1_EvErrorList]
 #define l_flg_clr_LI1_EvErrorList_flag() \
          lin_frame_flag_tbl[LI1_EvErrorList] = 0
 #define l_flg_tst_LI1_MasterReq_flag() \
          lin_frame_flag_tbl[LI1_MasterReq]
 #define l_flg_clr_LI1_MasterReq_flag() \
          lin_frame_flag_tbl[LI1_MasterReq] = 0
 #define l_flg_tst_LI1_SlaveResp_flag() \
          lin_frame_flag_tbl[LI1_SlaveResp]
 #define l_flg_clr_LI1_SlaveResp_flag() \
          lin_frame_flag_tbl[LI1_SlaveResp] = 0



/* SCHEDULE MANAGEMENT */
#define l_sch_tick_LI0() l_sch_tick(LI0)
#define l_sch_tick_LI1() l_sch_tick(LI1)


#define l_sch_set_LI0(schedule, entry) l_sch_set(LI0, schedule, entry)
#define l_sch_set_LI1(schedule, entry) l_sch_set(LI1, schedule, entry)

/* INTERFACE MANAGEMENT */
#define l_ifc_init_LI0() l_ifc_init(LI0)
#define l_ifc_init_LI1() l_ifc_init(LI1)


#define l_ifc_goto_sleep_LI0() l_ifc_goto_sleep(LI0)
#define l_ifc_goto_sleep_LI1() l_ifc_goto_sleep(LI1)

#define l_ifc_wake_up_LI0() l_ifc_wake_up(LI0)
#define l_ifc_wake_up_LI1() l_ifc_wake_up(LI1)


#define l_ifc_rx_LI0() l_ifc_rx(LI0)
#define l_ifc_rx_LI1() l_ifc_rx(LI1)


#define l_ifc_tx_LI0() l_ifc_tx(LI0)
#define l_ifc_tx_LI1() l_ifc_tx(LI1)


#define l_ifc_aux_LI0() l_ifc_aux(LI0)
#define l_ifc_aux_LI1() l_ifc_aux(LI1)


#define l_ifc_read_status_LI0() l_ifc_read_status(LI0)
#define l_ifc_read_status_LI1() l_ifc_read_status(LI1)


#endif    /* _LIN_CFG_H_ */