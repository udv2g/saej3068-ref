/******************************************************************************
* 
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2016 Freescale Semiconductor, Inc.
* Copyright 2016-2023 NXP
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
* @date      Wed Oct 11 19:28:33 EDT 2023
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
#define LIN_NUM_OF_IFCS  2		/* For master */
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
#define LIN_FRAME_BUF_SIZE			336
#define LIN_FLAG_BUF_SIZE			48

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
#define LIN_NUM_OF_SIGS  262
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
    , LI0_SeConnectionType
    , LI0_EvMaxVoltageL1N
    , LI0_EvMaxVoltageLL
    , LI0_EvFrequencies
    , LI0_EvMinVoltageL1N
    , LI0_EvMinVoltageLL
    , LI0_EvConnectionType
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
    , LI0_SeIDPage
    , LI0_SeIDByteA
    , LI0_SeIDByteB
    , LI0_SeIDByteC
    , LI0_SeIDByteD
    , LI0_SeIDByteE
    , LI0_SeIDByteF
    , LI0_SeIDByteG
    , LI0_EvIDPage
    , LI0_EvIDByteA
    , LI0_EvIDByteB
    , LI0_EvIDByteC
    , LI0_EvIDByteD
    , LI0_EvIDByteE
    , LI0_EvIDByteF
    , LI0_EvIDByteG
    , LI0_EvGridCodeStatus
    , LI0_EvGridCodeStatusMod
    , LI0_EvPwrCtrlUnitsAvail
    , LI0_EvPwrCtrlModesAvail
    , LI0_EvPwrCtrlModeAck
    , LI0_EvInverterState
    , LI0_EvJ3072ByteA
    , LI0_EvJ3072ByteB
    , LI0_EvJ3072ByteC
    , LI0_EvJ3072ByteD
    , LI0_EvJ3072ByteE
    , LI0_EvJ3072ByteF
    , LI0_EvJ3072ByteG
    , LI0_EvJ3072Page
    , LI0_SeGridCodeRequest
    , LI0_SePwrCtrlMode
    , LI0_SePwrCtrlAuth
    , LI0_SeInverterRequest
    , LI0_SeJ3072ByteA
    , LI0_SeJ3072ByteB
    , LI0_SeJ3072ByteC
    , LI0_SeJ3072ByteD
    , LI0_SeJ3072ByteE
    , LI0_SeJ3072ByteF
    , LI0_SeJ3072ByteG
    , LI0_SeJ3072Page
    , LI0_SePwrCtrlUnits
    , LI0_SeTargets1ElementA
    , LI0_SeTargets1ElementB
    , LI0_SeTargets1ElementC
    , LI0_SeTargets1ElementD
    , LI0_SeTimeStamp
  
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
    , LI1_SeConnectionType
    , LI1_EvMaxVoltageL1N
    , LI1_EvMaxVoltageLL
    , LI1_EvFrequencies
    , LI1_EvMinVoltageL1N
    , LI1_EvMinVoltageLL
    , LI1_EvConnectionType
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
    , LI1_SeIDPage
    , LI1_SeIDByteA
    , LI1_SeIDByteB
    , LI1_SeIDByteC
    , LI1_SeIDByteD
    , LI1_SeIDByteE
    , LI1_SeIDByteF
    , LI1_SeIDByteG
    , LI1_EvIDPage
    , LI1_EvIDByteA
    , LI1_EvIDByteB
    , LI1_EvIDByteC
    , LI1_EvIDByteD
    , LI1_EvIDByteE
    , LI1_EvIDByteF
    , LI1_EvIDByteG
    , LI1_EvGridCodeStatus
    , LI1_EvGridCodeStatusMod
    , LI1_EvPwrCtrlUnitsAvail
    , LI1_EvPwrCtrlModesAvail
    , LI1_EvPwrCtrlModeAck
    , LI1_EvInverterState
    , LI1_EvJ3072ByteA
    , LI1_EvJ3072ByteB
    , LI1_EvJ3072ByteC
    , LI1_EvJ3072ByteD
    , LI1_EvJ3072ByteE
    , LI1_EvJ3072ByteF
    , LI1_EvJ3072ByteG
    , LI1_EvJ3072Page
    , LI1_SeGridCodeRequest
    , LI1_SePwrCtrlMode
    , LI1_SePwrCtrlAuth
    , LI1_SeInverterRequest
    , LI1_SeJ3072ByteA
    , LI1_SeJ3072ByteB
    , LI1_SeJ3072ByteC
    , LI1_SeJ3072ByteD
    , LI1_SeJ3072ByteE
    , LI1_SeJ3072ByteF
    , LI1_SeJ3072ByteG
    , LI1_SeJ3072Page
    , LI1_SePwrCtrlUnits
    , LI1_SeTargets1ElementA
    , LI1_SeTargets1ElementB
    , LI1_SeTargets1ElementC
    , LI1_SeTargets1ElementD
    , LI1_SeTimeStamp
    
} l_signal_handle; 
/**********************************************************************/
/*****************               Frame             ********************/
/**********************************************************************/
/* Number of frames */
#define LIN_NUM_OF_FRMS  46 
/* List of frames */
typedef enum {
/* All frames for master node */
   /* Interface_name = LI0 */
   LI0_SeVersionList
   , LI0_EvVersionList
    , LI0_SeStatus
    , LI0_EvStatus
    , LI0_EvPresentCurrents
    , LI0_SeNomVoltages
    , LI0_SeMaxCurrents
    , LI0_EvMaxVoltages
    , LI0_EvMinVoltages
    , LI0_EvMaxMinCurrents
    , LI0_EvInfoList
    , LI0_SeInfoList
    , LI0_StErrorList
    , LI0_EvErrorList
    , LI0_SeID
    , LI0_EvID
    , LI0_EvModeCtrl
    , LI0_SeModeCtrl
    , LI0_EvJ3072
    , LI0_SeJ3072
    , LI0_SeTargets1
    , LI0_MasterReq
    , LI0_SlaveResp
  
   /* Interface_name = LI1 */
   , LI1_SeVersionList
    , LI1_EvVersionList
    , LI1_SeStatus
    , LI1_EvStatus
    , LI1_EvPresentCurrents
    , LI1_SeNomVoltages
    , LI1_SeMaxCurrents
    , LI1_EvMaxVoltages
    , LI1_EvMinVoltages
    , LI1_EvMaxMinCurrents
    , LI1_EvInfoList
    , LI1_SeInfoList
    , LI1_StErrorList
    , LI1_EvErrorList
    , LI1_SeID
    , LI1_EvID
    , LI1_EvModeCtrl
    , LI1_SeModeCtrl
    , LI1_EvJ3072
    , LI1_SeJ3072
    , LI1_SeTargets1
    , LI1_MasterReq
    , LI1_SlaveResp
    
} l_frame_handle; 
/**********************************************************************/
/***************        schedule table       *******************/
/**********************************************************************/
/* Number of schedule tables */
#define  LIN_NUM_OF_SCHD_TBL   2 
/* List of schedules */
typedef enum {
   /* Interface_name = LI0 */
   LI0_LIN_NULL_SCHEDULE

   /* Interface_name = LI1 */
   ,LI1_LIN_NULL_SCHEDULE
   
}l_schedule_handle;  
/**********************************************************************/
/***************             Configuration          *******************/
/**********************************************************************/
/* Size of configuration in ROM and RAM used for interface: LI0 */
#define LI0_LIN_SIZE_OF_CFG  25
/* Size of configuration in ROM and RAM used for interface: LI1 */
#define LI1_LIN_SIZE_OF_CFG  25
 
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
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList    8
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvVersionList    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList    1
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus    24
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvStatus    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus    3
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents    32
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvPresentCurrents    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents    7
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents    4
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages    56
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxVoltages    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages    10
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages    7
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages    64
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMinVoltages    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages    11
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages    8
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    72
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxMinCurrents    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents    9
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList    80
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvInfoList    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList    10
#define LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList    104
#define LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList    0
#define LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvErrorList    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList    13
#define LIN_BYTE_OFFSET_LI0_EvResponseError_EvVersionList    9
#define LIN_BIT_OFFSET_LI0_EvResponseError_EvVersionList    0
#define LIN_SIGNAL_SIZE_LI0_EvResponseError_EvVersionList    1
#define LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvResponseError_EvVersionList    1
#define LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus    25
#define LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus    0
#define LIN_SIGNAL_SIZE_LI0_EvResponseError_EvStatus    1
#define LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvResponseError_EvStatus    3
#define LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList    9
#define LIN_BIT_OFFSET_LI0_EvStatusVer_EvVersionList    1
#define LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList    1
#define LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus    25
#define LIN_BIT_OFFSET_LI0_EvStatusVer_EvStatus    1
#define LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusVer_EvStatus    3
#define LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList    9
#define LIN_BIT_OFFSET_LI0_EvStatusInit_EvVersionList    3
#define LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList    1
#define LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus    25
#define LIN_BIT_OFFSET_LI0_EvStatusInit_EvStatus    3
#define LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusInit_EvStatus    3
#define LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList    9
#define LIN_BIT_OFFSET_LI0_EvStatusOp_EvVersionList    5
#define LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList    1
#define LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus    25
#define LIN_BIT_OFFSET_LI0_EvStatusOp_EvStatus    5
#define LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusOp_EvStatus    3
#define LIN_BYTE_OFFSET_LI0_EvAwake_EvVersionList    9
#define LIN_BIT_OFFSET_LI0_EvAwake_EvVersionList    7
#define LIN_SIGNAL_SIZE_LI0_EvAwake_EvVersionList    1
#define LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvAwake_EvVersionList    1
#define LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus    25
#define LIN_BIT_OFFSET_LI0_EvAwake_EvStatus    7
#define LIN_SIGNAL_SIZE_LI0_EvAwake_EvStatus    1
#define LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvAwake_EvStatus    3
#define LIN_BYTE_OFFSET_LI0_EvVersionPageNumber    10
#define LIN_BIT_OFFSET_LI0_EvVersionPageNumber    0
#define LIN_SIGNAL_SIZE_LI0_EvVersionPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvVersionPageNumber    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvVersionPageNumber    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvVersionPageNumber    1
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion1    11
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion1    0
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion1    2
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion1    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion1    1
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion2    12
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion2    0
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion2    3
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion2    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion2    1
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion3    13
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion3    0
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion3    3
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion3    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion3    1
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion4    14
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion4    0
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion4    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion4    3
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion4    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion4    1
#define LIN_BYTE_OFFSET_LI0_EvSupportedVersion5    15
#define LIN_BIT_OFFSET_LI0_EvSupportedVersion5    0
#define LIN_SIGNAL_SIZE_LI0_EvSupportedVersion5    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvSupportedVersion5    3
#define LIN_FLAG_BIT_OFFSET_LI0_EvSupportedVersion5    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion5    1
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1    26
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentL1    0
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL1    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL1    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentL1    3
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2    27
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentL2    0
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL2    5
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL2    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentL2    3
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3    28
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentL3    0
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentL3    6
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentL3    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentL3    3
#define LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN    29
#define LIN_BIT_OFFSET_LI0_EvRequestedCurrentN    0
#define LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvRequestedCurrentN    6
#define LIN_FLAG_BIT_OFFSET_LI0_EvRequestedCurrentN    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentN    3
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList    0
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList    0
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeVersionList    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList    0
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus    16
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus    0
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeStatus    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus    2
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    40
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    0
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeNomVoltages    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    8
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages    5
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents    48
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents    0
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeMaxCurrents    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents    9
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents    6
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList    88
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList    0
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeInfoList    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList    11
#define LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList    96
#define LIN_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList    0
#define LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_StErrorList    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList    15
#define LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList    12
#define LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList    1
#define LIN_BIT_OFFSET_LI0_SeStatusVer_SeVersionList    1
#define LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList    0
#define LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus    17
#define LIN_BIT_OFFSET_LI0_SeStatusVer_SeStatus    1
#define LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusVer_SeStatus    2
#define LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList    1
#define LIN_BIT_OFFSET_LI0_SeStatusInit_SeVersionList    3
#define LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList    0
#define LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus    17
#define LIN_BIT_OFFSET_LI0_SeStatusInit_SeStatus    3
#define LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusInit_SeStatus    2
#define LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList    1
#define LIN_BIT_OFFSET_LI0_SeStatusOp_SeVersionList    5
#define LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList    0
#define LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus    17
#define LIN_BIT_OFFSET_LI0_SeStatusOp_SeStatus    5
#define LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusOp_SeStatus    2
#define LIN_BYTE_OFFSET_LI0_SeVersionPageNumber    2
#define LIN_BIT_OFFSET_LI0_SeVersionPageNumber    0
#define LIN_SIGNAL_SIZE_LI0_SeVersionPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeVersionPageNumber    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeVersionPageNumber    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeVersionPageNumber    0
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion1    3
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion1    0
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion1    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion1    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion1    0
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion2    4
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion2    0
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion2    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion2    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion2    0
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion3    5
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion3    0
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion3    0
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion3    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion3    0
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion4    6
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion4    0
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion4    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion4    1
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion4    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion4    0
#define LIN_BYTE_OFFSET_LI0_SeSupportedVersion5    7
#define LIN_BIT_OFFSET_LI0_SeSupportedVersion5    0
#define LIN_SIGNAL_SIZE_LI0_SeSupportedVersion5    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeSupportedVersion5    1
#define LIN_FLAG_BIT_OFFSET_LI0_SeSupportedVersion5    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion5    0
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1    18
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentL1    0
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL1    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL1    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentL1    2
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2    19
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentL2    0
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL2    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL2    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentL2    2
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3    20
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentL3    0
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentL3    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentL3    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentL3    2
#define LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN    21
#define LIN_BIT_OFFSET_LI0_SeAvailableCurrentN    0
#define LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeAvailableCurrentN    4
#define LIN_FLAG_BIT_OFFSET_LI0_SeAvailableCurrentN    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentN    2
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1    33
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentL1    0
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL1    7
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL1    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentL1    4
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2    34
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentL2    0
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL2    7
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL2    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentL2    4
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3    35
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentL3    0
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentL3    7
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentL3    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentL3    4
#define LIN_BYTE_OFFSET_LI0_EvPresentCurrentN    36
#define LIN_BIT_OFFSET_LI0_EvPresentCurrentN    0
#define LIN_SIGNAL_SIZE_LI0_EvPresentCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrentN    7
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrentN    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentN    4
#define LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N    41
#define LIN_BIT_OFFSET_LI0_SeNomVoltageL1N    0
#define LIN_SIGNAL_SIZE_LI0_SeNomVoltageL1N    16
#define LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageL1N    8
#define LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageL1N    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeNomVoltageL1N    5
#define LIN_BYTE_OFFSET_LI0_SeNomVoltageLL    43
#define LIN_BIT_OFFSET_LI0_SeNomVoltageLL    0
#define LIN_SIGNAL_SIZE_LI0_SeNomVoltageLL    16
#define LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltageLL    8
#define LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltageLL    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeNomVoltageLL    5
#define LIN_BYTE_OFFSET_LI0_SeFrequency    45
#define LIN_BIT_OFFSET_LI0_SeFrequency    0
#define LIN_SIGNAL_SIZE_LI0_SeFrequency    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeFrequency    8
#define LIN_FLAG_BIT_OFFSET_LI0_SeFrequency    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeFrequency    5
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1    49
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentL1    0
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL1    9
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL1    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentL1    6
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2    50
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentL2    0
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL2    9
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL2    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentL2    6
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3    51
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentL3    0
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentL3    9
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentL3    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentL3    6
#define LIN_BYTE_OFFSET_LI0_SeMaxCurrentN    52
#define LIN_BIT_OFFSET_LI0_SeMaxCurrentN    0
#define LIN_SIGNAL_SIZE_LI0_SeMaxCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrentN    9
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrentN    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentN    6
#define LIN_BYTE_OFFSET_LI0_SeConnectionType    53
#define LIN_BIT_OFFSET_LI0_SeConnectionType    0
#define LIN_SIGNAL_SIZE_LI0_SeConnectionType    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeConnectionType    9
#define LIN_FLAG_BIT_OFFSET_LI0_SeConnectionType    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeConnectionType    6
#define LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N    57
#define LIN_BIT_OFFSET_LI0_EvMaxVoltageL1N    0
#define LIN_SIGNAL_SIZE_LI0_EvMaxVoltageL1N    16
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageL1N    10
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageL1N    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxVoltageL1N    7
#define LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL    59
#define LIN_BIT_OFFSET_LI0_EvMaxVoltageLL    0
#define LIN_SIGNAL_SIZE_LI0_EvMaxVoltageLL    16
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltageLL    10
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltageLL    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxVoltageLL    7
#define LIN_BYTE_OFFSET_LI0_EvFrequencies    61
#define LIN_BIT_OFFSET_LI0_EvFrequencies    0
#define LIN_SIGNAL_SIZE_LI0_EvFrequencies    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvFrequencies    10
#define LIN_FLAG_BIT_OFFSET_LI0_EvFrequencies    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvFrequencies    7
#define LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N    65
#define LIN_BIT_OFFSET_LI0_EvMinVoltageL1N    0
#define LIN_SIGNAL_SIZE_LI0_EvMinVoltageL1N    16
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageL1N    11
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageL1N    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinVoltageL1N    8
#define LIN_BYTE_OFFSET_LI0_EvMinVoltageLL    67
#define LIN_BIT_OFFSET_LI0_EvMinVoltageLL    0
#define LIN_SIGNAL_SIZE_LI0_EvMinVoltageLL    16
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltageLL    11
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltageLL    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinVoltageLL    8
#define LIN_BYTE_OFFSET_LI0_EvConnectionType    69
#define LIN_BIT_OFFSET_LI0_EvConnectionType    0
#define LIN_SIGNAL_SIZE_LI0_EvConnectionType    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvConnectionType    11
#define LIN_FLAG_BIT_OFFSET_LI0_EvConnectionType    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvConnectionType    8
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1    73
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentL1    0
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL1    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL1    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentL1    9
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2    74
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentL2    0
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL2    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL2    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentL2    9
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3    75
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentL3    0
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentL3    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentL3    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentL3    9
#define LIN_BYTE_OFFSET_LI0_EvMaxCurrentN    76
#define LIN_BIT_OFFSET_LI0_EvMaxCurrentN    0
#define LIN_SIGNAL_SIZE_LI0_EvMaxCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxCurrentN    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxCurrentN    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentN    9
#define LIN_BYTE_OFFSET_LI0_EvMinCurrentL1    77
#define LIN_BIT_OFFSET_LI0_EvMinCurrentL1    0
#define LIN_SIGNAL_SIZE_LI0_EvMinCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL1    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL1    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinCurrentL1    9
#define LIN_BYTE_OFFSET_LI0_EvMinCurrentL2    78
#define LIN_BIT_OFFSET_LI0_EvMinCurrentL2    0
#define LIN_SIGNAL_SIZE_LI0_EvMinCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL2    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL2    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinCurrentL2    9
#define LIN_BYTE_OFFSET_LI0_EvMinCurrentL3    79
#define LIN_BIT_OFFSET_LI0_EvMinCurrentL3    0
#define LIN_SIGNAL_SIZE_LI0_EvMinCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinCurrentL3    12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinCurrentL3    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinCurrentL3    9
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry1    82
#define LIN_BIT_OFFSET_LI0_EvInfoEntry1    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry1    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry1    10
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry2    83
#define LIN_BIT_OFFSET_LI0_EvInfoEntry2    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry2    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry2    10
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry3    84
#define LIN_BIT_OFFSET_LI0_EvInfoEntry3    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry3    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry3    10
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry4    85
#define LIN_BIT_OFFSET_LI0_EvInfoEntry4    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry4    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry4    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry4    10
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry5    86
#define LIN_BIT_OFFSET_LI0_EvInfoEntry5    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry5    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry5    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry5    10
#define LIN_BYTE_OFFSET_LI0_EvInfoEntry6    87
#define LIN_BIT_OFFSET_LI0_EvInfoEntry6    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoEntry6    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoEntry6    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoEntry6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry6    10
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry1    90
#define LIN_BIT_OFFSET_LI0_SeInfoEntry1    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry1    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry1    11
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry2    91
#define LIN_BIT_OFFSET_LI0_SeInfoEntry2    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry2    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry2    11
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry3    92
#define LIN_BIT_OFFSET_LI0_SeInfoEntry3    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry3    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry3    11
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry4    93
#define LIN_BIT_OFFSET_LI0_SeInfoEntry4    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry4    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry4    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry4    11
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry5    94
#define LIN_BIT_OFFSET_LI0_SeInfoEntry5    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry5    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry5    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry5    11
#define LIN_BYTE_OFFSET_LI0_SeInfoEntry6    95
#define LIN_BIT_OFFSET_LI0_SeInfoEntry6    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoEntry6    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoEntry6    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoEntry6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry6    11
#define LIN_BYTE_OFFSET_LI0_EvInfoPageNumber    81
#define LIN_BIT_OFFSET_LI0_EvInfoPageNumber    0
#define LIN_SIGNAL_SIZE_LI0_EvInfoPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoPageNumber    13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoPageNumber    10
#define LIN_BYTE_OFFSET_LI0_SeInfoPageNumber    89
#define LIN_BIT_OFFSET_LI0_SeInfoPageNumber    0
#define LIN_SIGNAL_SIZE_LI0_SeInfoPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoPageNumber    14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoPageNumber    11
#define LIN_BYTE_OFFSET_LI0_StErrorPageNumber    97
#define LIN_BIT_OFFSET_LI0_StErrorPageNumber    0
#define LIN_SIGNAL_SIZE_LI0_StErrorPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorPageNumber    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorPageNumber    12
#define LIN_BYTE_OFFSET_LI0_StErrorCode1    98
#define LIN_BIT_OFFSET_LI0_StErrorCode1    0
#define LIN_SIGNAL_SIZE_LI0_StErrorCode1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode1    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode1    12
#define LIN_BYTE_OFFSET_LI0_StErrorCode2    99
#define LIN_BIT_OFFSET_LI0_StErrorCode2    0
#define LIN_SIGNAL_SIZE_LI0_StErrorCode2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode2    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode2    12
#define LIN_BYTE_OFFSET_LI0_StErrorCode3    100
#define LIN_BIT_OFFSET_LI0_StErrorCode3    0
#define LIN_SIGNAL_SIZE_LI0_StErrorCode3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode3    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode3    12
#define LIN_BYTE_OFFSET_LI0_StErrorCode4    101
#define LIN_BIT_OFFSET_LI0_StErrorCode4    0
#define LIN_SIGNAL_SIZE_LI0_StErrorCode4    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode4    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode4    12
#define LIN_BYTE_OFFSET_LI0_StErrorCode5    102
#define LIN_BIT_OFFSET_LI0_StErrorCode5    0
#define LIN_SIGNAL_SIZE_LI0_StErrorCode5    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode5    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode5    12
#define LIN_BYTE_OFFSET_LI0_StErrorCode6    103
#define LIN_BIT_OFFSET_LI0_StErrorCode6    0
#define LIN_SIGNAL_SIZE_LI0_StErrorCode6    8
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorCode6    15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorCode6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode6    12
#define LIN_BYTE_OFFSET_LI0_EvErrorPageNumber    105
#define LIN_BIT_OFFSET_LI0_EvErrorPageNumber    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorPageNumber    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorPageNumber    13
#define LIN_BYTE_OFFSET_LI0_EvErrorCode1    106
#define LIN_BIT_OFFSET_LI0_EvErrorCode1    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode1    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode1    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode1    13
#define LIN_BYTE_OFFSET_LI0_EvErrorCode2    107
#define LIN_BIT_OFFSET_LI0_EvErrorCode2    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode2    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode2    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode2    13
#define LIN_BYTE_OFFSET_LI0_EvErrorCode3    108
#define LIN_BIT_OFFSET_LI0_EvErrorCode3    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode3    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode3    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode3    13
#define LIN_BYTE_OFFSET_LI0_EvErrorCode4    109
#define LIN_BIT_OFFSET_LI0_EvErrorCode4    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode4    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode4    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode4    13
#define LIN_BYTE_OFFSET_LI0_EvErrorCode5    110
#define LIN_BIT_OFFSET_LI0_EvErrorCode5    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode5    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode5    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode5    13
#define LIN_BYTE_OFFSET_LI0_EvErrorCode6    111
#define LIN_BIT_OFFSET_LI0_EvErrorCode6    0
#define LIN_SIGNAL_SIZE_LI0_EvErrorCode6    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorCode6    16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorCode6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode6    13
#define LIN_BYTE_OFFSET_LI0_SeIDPage    112
#define LIN_BIT_OFFSET_LI0_SeIDPage    0
#define LIN_SIGNAL_SIZE_LI0_SeIDPage    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDPage    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDPage    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDPage    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteA    113
#define LIN_BIT_OFFSET_LI0_SeIDByteA    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteA    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteA    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteB    114
#define LIN_BIT_OFFSET_LI0_SeIDByteB    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteB    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteB    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteC    115
#define LIN_BIT_OFFSET_LI0_SeIDByteC    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteC    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteC    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteD    116
#define LIN_BIT_OFFSET_LI0_SeIDByteD    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteD    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteD    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteE    117
#define LIN_BIT_OFFSET_LI0_SeIDByteE    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteE    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteE    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteF    118
#define LIN_BIT_OFFSET_LI0_SeIDByteF    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteF    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteF    14
#define LIN_BYTE_OFFSET_LI0_SeIDByteG    119
#define LIN_BIT_OFFSET_LI0_SeIDByteG    0
#define LIN_SIGNAL_SIZE_LI0_SeIDByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteG    17
#define LIN_FLAG_BIT_OFFSET_LI0_SeIDByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteG    14
#define LIN_BYTE_OFFSET_LI0_EvIDPage    120
#define LIN_BIT_OFFSET_LI0_EvIDPage    0
#define LIN_SIGNAL_SIZE_LI0_EvIDPage    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDPage    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDPage    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDPage    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteA    121
#define LIN_BIT_OFFSET_LI0_EvIDByteA    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteA    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteA    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteB    122
#define LIN_BIT_OFFSET_LI0_EvIDByteB    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteB    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteB    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteC    123
#define LIN_BIT_OFFSET_LI0_EvIDByteC    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteC    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteC    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteD    124
#define LIN_BIT_OFFSET_LI0_EvIDByteD    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteD    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteD    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteE    125
#define LIN_BIT_OFFSET_LI0_EvIDByteE    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteE    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteE    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteF    126
#define LIN_BIT_OFFSET_LI0_EvIDByteF    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteF    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteF    15
#define LIN_BYTE_OFFSET_LI0_EvIDByteG    127
#define LIN_BIT_OFFSET_LI0_EvIDByteG    0
#define LIN_SIGNAL_SIZE_LI0_EvIDByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteG    18
#define LIN_FLAG_BIT_OFFSET_LI0_EvIDByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteG    15
#define LIN_BYTE_OFFSET_LI0_EvGridCodeStatus    128
#define LIN_BIT_OFFSET_LI0_EvGridCodeStatus    1
#define LIN_SIGNAL_SIZE_LI0_EvGridCodeStatus    15
#define LIN_FLAG_BYTE_OFFSET_LI0_EvGridCodeStatus    19
#define LIN_FLAG_BIT_OFFSET_LI0_EvGridCodeStatus    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvGridCodeStatus    16
#define LIN_BYTE_OFFSET_LI0_EvGridCodeStatusMod    128
#define LIN_BIT_OFFSET_LI0_EvGridCodeStatusMod    0
#define LIN_SIGNAL_SIZE_LI0_EvGridCodeStatusMod    1
#define LIN_FLAG_BYTE_OFFSET_LI0_EvGridCodeStatusMod    19
#define LIN_FLAG_BIT_OFFSET_LI0_EvGridCodeStatusMod    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvGridCodeStatusMod    16
#define LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail    132
#define LIN_BIT_OFFSET_LI0_EvPwrCtrlUnitsAvail    0
#define LIN_SIGNAL_SIZE_LI0_EvPwrCtrlUnitsAvail    16
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail    19
#define LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlUnitsAvail    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail    16
#define LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail    134
#define LIN_BIT_OFFSET_LI0_EvPwrCtrlModesAvail    0
#define LIN_SIGNAL_SIZE_LI0_EvPwrCtrlModesAvail    16
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail    19
#define LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlModesAvail    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail    16
#define LIN_BYTE_OFFSET_LI0_EvPwrCtrlModeAck    131
#define LIN_BIT_OFFSET_LI0_EvPwrCtrlModeAck    0
#define LIN_SIGNAL_SIZE_LI0_EvPwrCtrlModeAck    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlModeAck    19
#define LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlModeAck    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPwrCtrlModeAck    16
#define LIN_BYTE_OFFSET_LI0_EvInverterState    130
#define LIN_BIT_OFFSET_LI0_EvInverterState    0
#define LIN_SIGNAL_SIZE_LI0_EvInverterState    4
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInverterState    19
#define LIN_FLAG_BIT_OFFSET_LI0_EvInverterState    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInverterState    16
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteA    145
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteA    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteA    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteA    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteB    146
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteB    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteB    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteB    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteC    147
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteC    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteC    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteC    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteD    148
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteD    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteD    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteD    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteE    149
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteE    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteE    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteE    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteF    150
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteF    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteF    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteF    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072ByteG    151
#define LIN_BIT_OFFSET_LI0_EvJ3072ByteG    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072ByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteG    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteG    18
#define LIN_BYTE_OFFSET_LI0_EvJ3072Page    144
#define LIN_BIT_OFFSET_LI0_EvJ3072Page    0
#define LIN_SIGNAL_SIZE_LI0_EvJ3072Page    8
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072Page    21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072Page    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072Page    18
#define LIN_BYTE_OFFSET_LI0_SeGridCodeRequest    136
#define LIN_BIT_OFFSET_LI0_SeGridCodeRequest    1
#define LIN_SIGNAL_SIZE_LI0_SeGridCodeRequest    15
#define LIN_FLAG_BYTE_OFFSET_LI0_SeGridCodeRequest    20
#define LIN_FLAG_BIT_OFFSET_LI0_SeGridCodeRequest    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeGridCodeRequest    17
#define LIN_BYTE_OFFSET_LI0_SePwrCtrlMode    139
#define LIN_BIT_OFFSET_LI0_SePwrCtrlMode    0
#define LIN_SIGNAL_SIZE_LI0_SePwrCtrlMode    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlMode    20
#define LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlMode    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SePwrCtrlMode    17
#define LIN_BYTE_OFFSET_LI0_SePwrCtrlAuth    140
#define LIN_BIT_OFFSET_LI0_SePwrCtrlAuth    4
#define LIN_SIGNAL_SIZE_LI0_SePwrCtrlAuth    4
#define LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlAuth    20
#define LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlAuth    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SePwrCtrlAuth    17
#define LIN_BYTE_OFFSET_LI0_SeInverterRequest    138
#define LIN_BIT_OFFSET_LI0_SeInverterRequest    0
#define LIN_SIGNAL_SIZE_LI0_SeInverterRequest    4
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInverterRequest    20
#define LIN_FLAG_BIT_OFFSET_LI0_SeInverterRequest    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInverterRequest    17
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteA    153
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteA    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteA    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteA    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteB    154
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteB    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteB    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteB    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteC    155
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteC    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteC    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteC    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteD    156
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteD    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteD    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteD    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteE    157
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteE    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteE    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteE    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteF    158
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteF    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteF    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteF    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072ByteG    159
#define LIN_BIT_OFFSET_LI0_SeJ3072ByteG    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072ByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteG    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteG    19
#define LIN_BYTE_OFFSET_LI0_SeJ3072Page    152
#define LIN_BIT_OFFSET_LI0_SeJ3072Page    0
#define LIN_SIGNAL_SIZE_LI0_SeJ3072Page    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072Page    22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072Page    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072Page    19
#define LIN_BYTE_OFFSET_LI0_SePwrCtrlUnits    140
#define LIN_BIT_OFFSET_LI0_SePwrCtrlUnits    0
#define LIN_SIGNAL_SIZE_LI0_SePwrCtrlUnits    4
#define LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlUnits    20
#define LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlUnits    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SePwrCtrlUnits    17
#define LIN_BYTE_OFFSET_LI0_SeTargets1ElementA    160
#define LIN_BIT_OFFSET_LI0_SeTargets1ElementA    0
#define LIN_SIGNAL_SIZE_LI0_SeTargets1ElementA    16
#define LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementA    23
#define LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementA    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementA    20
#define LIN_BYTE_OFFSET_LI0_SeTargets1ElementB    162
#define LIN_BIT_OFFSET_LI0_SeTargets1ElementB    0
#define LIN_SIGNAL_SIZE_LI0_SeTargets1ElementB    16
#define LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementB    23
#define LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementB    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementB    20
#define LIN_BYTE_OFFSET_LI0_SeTargets1ElementC    164
#define LIN_BIT_OFFSET_LI0_SeTargets1ElementC    0
#define LIN_SIGNAL_SIZE_LI0_SeTargets1ElementC    16
#define LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementC    23
#define LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementC    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementC    20
#define LIN_BYTE_OFFSET_LI0_SeTargets1ElementD    166
#define LIN_BIT_OFFSET_LI0_SeTargets1ElementD    0
#define LIN_SIGNAL_SIZE_LI0_SeTargets1ElementD    16
#define LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementD    23
#define LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementD    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementD    20
#define LIN_BYTE_OFFSET_LI0_SeTimeStamp    143
#define LIN_BIT_OFFSET_LI0_SeTimeStamp    0
#define LIN_SIGNAL_SIZE_LI0_SeTimeStamp    8
#define LIN_FLAG_BYTE_OFFSET_LI0_SeTimeStamp    20
#define LIN_FLAG_BIT_OFFSET_LI0_SeTimeStamp    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTimeStamp    17

#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList    176
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvVersionList    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList    24
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus    192
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvStatus    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus    26
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents    200
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvPresentCurrents    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents    31
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents    27
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages    224
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxVoltages    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages    34
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages    30
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages    232
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMinVoltages    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages    35
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages    31
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    240
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxMinCurrents    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents    32
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList    248
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvInfoList    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList    33
#define LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList    272
#define LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList    0
#define LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvErrorList    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList    36
#define LIN_BYTE_OFFSET_LI1_EvResponseError_EvVersionList    177
#define LIN_BIT_OFFSET_LI1_EvResponseError_EvVersionList    0
#define LIN_SIGNAL_SIZE_LI1_EvResponseError_EvVersionList    1
#define LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvResponseError_EvVersionList    24
#define LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus    193
#define LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus    0
#define LIN_SIGNAL_SIZE_LI1_EvResponseError_EvStatus    1
#define LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvResponseError_EvStatus    26
#define LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList    177
#define LIN_BIT_OFFSET_LI1_EvStatusVer_EvVersionList    1
#define LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList    24
#define LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus    193
#define LIN_BIT_OFFSET_LI1_EvStatusVer_EvStatus    1
#define LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusVer_EvStatus    26
#define LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList    177
#define LIN_BIT_OFFSET_LI1_EvStatusInit_EvVersionList    3
#define LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList    24
#define LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus    193
#define LIN_BIT_OFFSET_LI1_EvStatusInit_EvStatus    3
#define LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusInit_EvStatus    26
#define LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList    177
#define LIN_BIT_OFFSET_LI1_EvStatusOp_EvVersionList    5
#define LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList    24
#define LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus    193
#define LIN_BIT_OFFSET_LI1_EvStatusOp_EvStatus    5
#define LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusOp_EvStatus    26
#define LIN_BYTE_OFFSET_LI1_EvAwake_EvVersionList    177
#define LIN_BIT_OFFSET_LI1_EvAwake_EvVersionList    7
#define LIN_SIGNAL_SIZE_LI1_EvAwake_EvVersionList    1
#define LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvAwake_EvVersionList    24
#define LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus    193
#define LIN_BIT_OFFSET_LI1_EvAwake_EvStatus    7
#define LIN_SIGNAL_SIZE_LI1_EvAwake_EvStatus    1
#define LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvAwake_EvStatus    26
#define LIN_BYTE_OFFSET_LI1_EvVersionPageNumber    178
#define LIN_BIT_OFFSET_LI1_EvVersionPageNumber    0
#define LIN_SIGNAL_SIZE_LI1_EvVersionPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvVersionPageNumber    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvVersionPageNumber    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvVersionPageNumber    24
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion1    179
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion1    0
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion1    26
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion1    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion1    24
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion2    180
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion2    0
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion2    27
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion2    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion2    24
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion3    181
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion3    0
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion3    27
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion3    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion3    24
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion4    182
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion4    0
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion4    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion4    27
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion4    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion4    24
#define LIN_BYTE_OFFSET_LI1_EvSupportedVersion5    183
#define LIN_BIT_OFFSET_LI1_EvSupportedVersion5    0
#define LIN_SIGNAL_SIZE_LI1_EvSupportedVersion5    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvSupportedVersion5    27
#define LIN_FLAG_BIT_OFFSET_LI1_EvSupportedVersion5    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion5    24
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1    194
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentL1    0
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL1    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL1    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentL1    26
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2    195
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentL2    0
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL2    29
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL2    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentL2    26
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3    196
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentL3    0
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentL3    30
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentL3    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentL3    26
#define LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN    197
#define LIN_BIT_OFFSET_LI1_EvRequestedCurrentN    0
#define LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvRequestedCurrentN    30
#define LIN_FLAG_BIT_OFFSET_LI1_EvRequestedCurrentN    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentN    26
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList    168
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList    0
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeVersionList    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList    23
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus    184
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus    0
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeStatus    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus    25
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    208
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    0
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeNomVoltages    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    32
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages    28
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents    216
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents    0
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeMaxCurrents    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents    33
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents    29
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList    256
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList    0
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeInfoList    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList    34
#define LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList    264
#define LIN_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList    0
#define LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_StErrorList    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList    39
#define LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList    35
#define LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList    169
#define LIN_BIT_OFFSET_LI1_SeStatusVer_SeVersionList    1
#define LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList    23
#define LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus    185
#define LIN_BIT_OFFSET_LI1_SeStatusVer_SeStatus    1
#define LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusVer_SeStatus    25
#define LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList    169
#define LIN_BIT_OFFSET_LI1_SeStatusInit_SeVersionList    3
#define LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList    23
#define LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus    185
#define LIN_BIT_OFFSET_LI1_SeStatusInit_SeStatus    3
#define LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusInit_SeStatus    25
#define LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList    169
#define LIN_BIT_OFFSET_LI1_SeStatusOp_SeVersionList    5
#define LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeVersionList    2
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList    23
#define LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus    185
#define LIN_BIT_OFFSET_LI1_SeStatusOp_SeStatus    5
#define LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeStatus    2
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusOp_SeStatus    25
#define LIN_BYTE_OFFSET_LI1_SeVersionPageNumber    170
#define LIN_BIT_OFFSET_LI1_SeVersionPageNumber    0
#define LIN_SIGNAL_SIZE_LI1_SeVersionPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeVersionPageNumber    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeVersionPageNumber    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeVersionPageNumber    23
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion1    171
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion1    0
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion1    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion1    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion1    23
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion2    172
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion2    0
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion2    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion2    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion2    23
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion3    173
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion3    0
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion3    24
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion3    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion3    23
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion4    174
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion4    0
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion4    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion4    25
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion4    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion4    23
#define LIN_BYTE_OFFSET_LI1_SeSupportedVersion5    175
#define LIN_BIT_OFFSET_LI1_SeSupportedVersion5    0
#define LIN_SIGNAL_SIZE_LI1_SeSupportedVersion5    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeSupportedVersion5    25
#define LIN_FLAG_BIT_OFFSET_LI1_SeSupportedVersion5    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion5    23
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1    186
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentL1    0
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL1    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL1    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentL1    25
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2    187
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentL2    0
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL2    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL2    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentL2    25
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3    188
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentL3    0
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentL3    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentL3    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentL3    25
#define LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN    189
#define LIN_BIT_OFFSET_LI1_SeAvailableCurrentN    0
#define LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeAvailableCurrentN    28
#define LIN_FLAG_BIT_OFFSET_LI1_SeAvailableCurrentN    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentN    25
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1    201
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentL1    0
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL1    31
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL1    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentL1    27
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2    202
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentL2    0
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL2    31
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL2    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentL2    27
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3    203
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentL3    0
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentL3    31
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentL3    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentL3    27
#define LIN_BYTE_OFFSET_LI1_EvPresentCurrentN    204
#define LIN_BIT_OFFSET_LI1_EvPresentCurrentN    0
#define LIN_SIGNAL_SIZE_LI1_EvPresentCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrentN    31
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrentN    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentN    27
#define LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N    209
#define LIN_BIT_OFFSET_LI1_SeNomVoltageL1N    0
#define LIN_SIGNAL_SIZE_LI1_SeNomVoltageL1N    16
#define LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageL1N    32
#define LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageL1N    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeNomVoltageL1N    28
#define LIN_BYTE_OFFSET_LI1_SeNomVoltageLL    211
#define LIN_BIT_OFFSET_LI1_SeNomVoltageLL    0
#define LIN_SIGNAL_SIZE_LI1_SeNomVoltageLL    16
#define LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltageLL    32
#define LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltageLL    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeNomVoltageLL    28
#define LIN_BYTE_OFFSET_LI1_SeFrequency    213
#define LIN_BIT_OFFSET_LI1_SeFrequency    0
#define LIN_SIGNAL_SIZE_LI1_SeFrequency    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeFrequency    32
#define LIN_FLAG_BIT_OFFSET_LI1_SeFrequency    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeFrequency    28
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1    217
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentL1    0
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL1    33
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL1    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentL1    29
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2    218
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentL2    0
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL2    33
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL2    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentL2    29
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3    219
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentL3    0
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentL3    33
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentL3    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentL3    29
#define LIN_BYTE_OFFSET_LI1_SeMaxCurrentN    220
#define LIN_BIT_OFFSET_LI1_SeMaxCurrentN    0
#define LIN_SIGNAL_SIZE_LI1_SeMaxCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrentN    33
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrentN    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentN    29
#define LIN_BYTE_OFFSET_LI1_SeConnectionType    221
#define LIN_BIT_OFFSET_LI1_SeConnectionType    0
#define LIN_SIGNAL_SIZE_LI1_SeConnectionType    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeConnectionType    33
#define LIN_FLAG_BIT_OFFSET_LI1_SeConnectionType    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeConnectionType    29
#define LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N    225
#define LIN_BIT_OFFSET_LI1_EvMaxVoltageL1N    0
#define LIN_SIGNAL_SIZE_LI1_EvMaxVoltageL1N    16
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageL1N    34
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageL1N    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxVoltageL1N    30
#define LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL    227
#define LIN_BIT_OFFSET_LI1_EvMaxVoltageLL    0
#define LIN_SIGNAL_SIZE_LI1_EvMaxVoltageLL    16
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltageLL    34
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltageLL    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxVoltageLL    30
#define LIN_BYTE_OFFSET_LI1_EvFrequencies    229
#define LIN_BIT_OFFSET_LI1_EvFrequencies    0
#define LIN_SIGNAL_SIZE_LI1_EvFrequencies    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvFrequencies    34
#define LIN_FLAG_BIT_OFFSET_LI1_EvFrequencies    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvFrequencies    30
#define LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N    233
#define LIN_BIT_OFFSET_LI1_EvMinVoltageL1N    0
#define LIN_SIGNAL_SIZE_LI1_EvMinVoltageL1N    16
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageL1N    35
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageL1N    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinVoltageL1N    31
#define LIN_BYTE_OFFSET_LI1_EvMinVoltageLL    235
#define LIN_BIT_OFFSET_LI1_EvMinVoltageLL    0
#define LIN_SIGNAL_SIZE_LI1_EvMinVoltageLL    16
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltageLL    35
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltageLL    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinVoltageLL    31
#define LIN_BYTE_OFFSET_LI1_EvConnectionType    237
#define LIN_BIT_OFFSET_LI1_EvConnectionType    0
#define LIN_SIGNAL_SIZE_LI1_EvConnectionType    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvConnectionType    35
#define LIN_FLAG_BIT_OFFSET_LI1_EvConnectionType    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvConnectionType    31
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1    241
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentL1    0
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL1    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL1    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentL1    32
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2    242
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentL2    0
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL2    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL2    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentL2    32
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3    243
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentL3    0
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentL3    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentL3    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentL3    32
#define LIN_BYTE_OFFSET_LI1_EvMaxCurrentN    244
#define LIN_BIT_OFFSET_LI1_EvMaxCurrentN    0
#define LIN_SIGNAL_SIZE_LI1_EvMaxCurrentN    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxCurrentN    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxCurrentN    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentN    32
#define LIN_BYTE_OFFSET_LI1_EvMinCurrentL1    245
#define LIN_BIT_OFFSET_LI1_EvMinCurrentL1    0
#define LIN_SIGNAL_SIZE_LI1_EvMinCurrentL1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL1    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL1    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinCurrentL1    32
#define LIN_BYTE_OFFSET_LI1_EvMinCurrentL2    246
#define LIN_BIT_OFFSET_LI1_EvMinCurrentL2    0
#define LIN_SIGNAL_SIZE_LI1_EvMinCurrentL2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL2    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL2    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinCurrentL2    32
#define LIN_BYTE_OFFSET_LI1_EvMinCurrentL3    247
#define LIN_BIT_OFFSET_LI1_EvMinCurrentL3    0
#define LIN_SIGNAL_SIZE_LI1_EvMinCurrentL3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinCurrentL3    36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinCurrentL3    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinCurrentL3    32
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry1    250
#define LIN_BIT_OFFSET_LI1_EvInfoEntry1    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry1    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry1    33
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry2    251
#define LIN_BIT_OFFSET_LI1_EvInfoEntry2    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry2    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry2    33
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry3    252
#define LIN_BIT_OFFSET_LI1_EvInfoEntry3    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry3    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry3    33
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry4    253
#define LIN_BIT_OFFSET_LI1_EvInfoEntry4    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry4    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry4    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry4    33
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry5    254
#define LIN_BIT_OFFSET_LI1_EvInfoEntry5    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry5    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry5    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry5    33
#define LIN_BYTE_OFFSET_LI1_EvInfoEntry6    255
#define LIN_BIT_OFFSET_LI1_EvInfoEntry6    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoEntry6    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoEntry6    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoEntry6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry6    33
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry1    258
#define LIN_BIT_OFFSET_LI1_SeInfoEntry1    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry1    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry1    34
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry2    259
#define LIN_BIT_OFFSET_LI1_SeInfoEntry2    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry2    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry2    34
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry3    260
#define LIN_BIT_OFFSET_LI1_SeInfoEntry3    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry3    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry3    34
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry4    261
#define LIN_BIT_OFFSET_LI1_SeInfoEntry4    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry4    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry4    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry4    34
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry5    262
#define LIN_BIT_OFFSET_LI1_SeInfoEntry5    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry5    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry5    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry5    34
#define LIN_BYTE_OFFSET_LI1_SeInfoEntry6    263
#define LIN_BIT_OFFSET_LI1_SeInfoEntry6    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoEntry6    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoEntry6    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoEntry6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry6    34
#define LIN_BYTE_OFFSET_LI1_EvInfoPageNumber    249
#define LIN_BIT_OFFSET_LI1_EvInfoPageNumber    0
#define LIN_SIGNAL_SIZE_LI1_EvInfoPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoPageNumber    37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoPageNumber    33
#define LIN_BYTE_OFFSET_LI1_SeInfoPageNumber    257
#define LIN_BIT_OFFSET_LI1_SeInfoPageNumber    0
#define LIN_SIGNAL_SIZE_LI1_SeInfoPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoPageNumber    38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoPageNumber    34
#define LIN_BYTE_OFFSET_LI1_StErrorPageNumber    265
#define LIN_BIT_OFFSET_LI1_StErrorPageNumber    0
#define LIN_SIGNAL_SIZE_LI1_StErrorPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorPageNumber    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorPageNumber    35
#define LIN_BYTE_OFFSET_LI1_StErrorCode1    266
#define LIN_BIT_OFFSET_LI1_StErrorCode1    0
#define LIN_SIGNAL_SIZE_LI1_StErrorCode1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode1    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode1    35
#define LIN_BYTE_OFFSET_LI1_StErrorCode2    267
#define LIN_BIT_OFFSET_LI1_StErrorCode2    0
#define LIN_SIGNAL_SIZE_LI1_StErrorCode2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode2    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode2    35
#define LIN_BYTE_OFFSET_LI1_StErrorCode3    268
#define LIN_BIT_OFFSET_LI1_StErrorCode3    0
#define LIN_SIGNAL_SIZE_LI1_StErrorCode3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode3    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode3    35
#define LIN_BYTE_OFFSET_LI1_StErrorCode4    269
#define LIN_BIT_OFFSET_LI1_StErrorCode4    0
#define LIN_SIGNAL_SIZE_LI1_StErrorCode4    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode4    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode4    35
#define LIN_BYTE_OFFSET_LI1_StErrorCode5    270
#define LIN_BIT_OFFSET_LI1_StErrorCode5    0
#define LIN_SIGNAL_SIZE_LI1_StErrorCode5    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode5    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode5    35
#define LIN_BYTE_OFFSET_LI1_StErrorCode6    271
#define LIN_BIT_OFFSET_LI1_StErrorCode6    0
#define LIN_SIGNAL_SIZE_LI1_StErrorCode6    8
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorCode6    39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorCode6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode6    35
#define LIN_BYTE_OFFSET_LI1_EvErrorPageNumber    273
#define LIN_BIT_OFFSET_LI1_EvErrorPageNumber    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorPageNumber    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorPageNumber    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorPageNumber    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorPageNumber    36
#define LIN_BYTE_OFFSET_LI1_EvErrorCode1    274
#define LIN_BIT_OFFSET_LI1_EvErrorCode1    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode1    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode1    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode1    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode1    36
#define LIN_BYTE_OFFSET_LI1_EvErrorCode2    275
#define LIN_BIT_OFFSET_LI1_EvErrorCode2    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode2    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode2    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode2    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode2    36
#define LIN_BYTE_OFFSET_LI1_EvErrorCode3    276
#define LIN_BIT_OFFSET_LI1_EvErrorCode3    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode3    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode3    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode3    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode3    36
#define LIN_BYTE_OFFSET_LI1_EvErrorCode4    277
#define LIN_BIT_OFFSET_LI1_EvErrorCode4    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode4    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode4    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode4    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode4    36
#define LIN_BYTE_OFFSET_LI1_EvErrorCode5    278
#define LIN_BIT_OFFSET_LI1_EvErrorCode5    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode5    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode5    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode5    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode5    36
#define LIN_BYTE_OFFSET_LI1_EvErrorCode6    279
#define LIN_BIT_OFFSET_LI1_EvErrorCode6    0
#define LIN_SIGNAL_SIZE_LI1_EvErrorCode6    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorCode6    40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorCode6    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode6    36
#define LIN_BYTE_OFFSET_LI1_SeIDPage    280
#define LIN_BIT_OFFSET_LI1_SeIDPage    0
#define LIN_SIGNAL_SIZE_LI1_SeIDPage    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDPage    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDPage    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDPage    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteA    281
#define LIN_BIT_OFFSET_LI1_SeIDByteA    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteA    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteA    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteB    282
#define LIN_BIT_OFFSET_LI1_SeIDByteB    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteB    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteB    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteC    283
#define LIN_BIT_OFFSET_LI1_SeIDByteC    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteC    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteC    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteD    284
#define LIN_BIT_OFFSET_LI1_SeIDByteD    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteD    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteD    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteE    285
#define LIN_BIT_OFFSET_LI1_SeIDByteE    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteE    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteE    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteF    286
#define LIN_BIT_OFFSET_LI1_SeIDByteF    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteF    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteF    37
#define LIN_BYTE_OFFSET_LI1_SeIDByteG    287
#define LIN_BIT_OFFSET_LI1_SeIDByteG    0
#define LIN_SIGNAL_SIZE_LI1_SeIDByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteG    41
#define LIN_FLAG_BIT_OFFSET_LI1_SeIDByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteG    37
#define LIN_BYTE_OFFSET_LI1_EvIDPage    288
#define LIN_BIT_OFFSET_LI1_EvIDPage    0
#define LIN_SIGNAL_SIZE_LI1_EvIDPage    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDPage    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDPage    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDPage    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteA    289
#define LIN_BIT_OFFSET_LI1_EvIDByteA    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteA    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteA    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteB    290
#define LIN_BIT_OFFSET_LI1_EvIDByteB    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteB    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteB    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteC    291
#define LIN_BIT_OFFSET_LI1_EvIDByteC    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteC    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteC    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteD    292
#define LIN_BIT_OFFSET_LI1_EvIDByteD    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteD    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteD    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteE    293
#define LIN_BIT_OFFSET_LI1_EvIDByteE    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteE    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteE    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteF    294
#define LIN_BIT_OFFSET_LI1_EvIDByteF    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteF    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteF    38
#define LIN_BYTE_OFFSET_LI1_EvIDByteG    295
#define LIN_BIT_OFFSET_LI1_EvIDByteG    0
#define LIN_SIGNAL_SIZE_LI1_EvIDByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteG    42
#define LIN_FLAG_BIT_OFFSET_LI1_EvIDByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteG    38
#define LIN_BYTE_OFFSET_LI1_EvGridCodeStatus    296
#define LIN_BIT_OFFSET_LI1_EvGridCodeStatus    1
#define LIN_SIGNAL_SIZE_LI1_EvGridCodeStatus    15
#define LIN_FLAG_BYTE_OFFSET_LI1_EvGridCodeStatus    43
#define LIN_FLAG_BIT_OFFSET_LI1_EvGridCodeStatus    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvGridCodeStatus    39
#define LIN_BYTE_OFFSET_LI1_EvGridCodeStatusMod    296
#define LIN_BIT_OFFSET_LI1_EvGridCodeStatusMod    0
#define LIN_SIGNAL_SIZE_LI1_EvGridCodeStatusMod    1
#define LIN_FLAG_BYTE_OFFSET_LI1_EvGridCodeStatusMod    43
#define LIN_FLAG_BIT_OFFSET_LI1_EvGridCodeStatusMod    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvGridCodeStatusMod    39
#define LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail    300
#define LIN_BIT_OFFSET_LI1_EvPwrCtrlUnitsAvail    0
#define LIN_SIGNAL_SIZE_LI1_EvPwrCtrlUnitsAvail    16
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail    43
#define LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlUnitsAvail    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail    39
#define LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail    302
#define LIN_BIT_OFFSET_LI1_EvPwrCtrlModesAvail    0
#define LIN_SIGNAL_SIZE_LI1_EvPwrCtrlModesAvail    16
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail    43
#define LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlModesAvail    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail    39
#define LIN_BYTE_OFFSET_LI1_EvPwrCtrlModeAck    299
#define LIN_BIT_OFFSET_LI1_EvPwrCtrlModeAck    0
#define LIN_SIGNAL_SIZE_LI1_EvPwrCtrlModeAck    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlModeAck    43
#define LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlModeAck    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPwrCtrlModeAck    39
#define LIN_BYTE_OFFSET_LI1_EvInverterState    298
#define LIN_BIT_OFFSET_LI1_EvInverterState    0
#define LIN_SIGNAL_SIZE_LI1_EvInverterState    4
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInverterState    43
#define LIN_FLAG_BIT_OFFSET_LI1_EvInverterState    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInverterState    39
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteA    313
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteA    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteA    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteA    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteB    314
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteB    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteB    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteB    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteC    315
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteC    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteC    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteC    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteD    316
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteD    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteD    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteD    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteE    317
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteE    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteE    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteE    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteF    318
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteF    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteF    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteF    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072ByteG    319
#define LIN_BIT_OFFSET_LI1_EvJ3072ByteG    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072ByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteG    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteG    41
#define LIN_BYTE_OFFSET_LI1_EvJ3072Page    312
#define LIN_BIT_OFFSET_LI1_EvJ3072Page    0
#define LIN_SIGNAL_SIZE_LI1_EvJ3072Page    8
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072Page    45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072Page    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072Page    41
#define LIN_BYTE_OFFSET_LI1_SeGridCodeRequest    304
#define LIN_BIT_OFFSET_LI1_SeGridCodeRequest    1
#define LIN_SIGNAL_SIZE_LI1_SeGridCodeRequest    15
#define LIN_FLAG_BYTE_OFFSET_LI1_SeGridCodeRequest    44
#define LIN_FLAG_BIT_OFFSET_LI1_SeGridCodeRequest    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeGridCodeRequest    40
#define LIN_BYTE_OFFSET_LI1_SePwrCtrlMode    307
#define LIN_BIT_OFFSET_LI1_SePwrCtrlMode    0
#define LIN_SIGNAL_SIZE_LI1_SePwrCtrlMode    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlMode    44
#define LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlMode    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SePwrCtrlMode    40
#define LIN_BYTE_OFFSET_LI1_SePwrCtrlAuth    308
#define LIN_BIT_OFFSET_LI1_SePwrCtrlAuth    4
#define LIN_SIGNAL_SIZE_LI1_SePwrCtrlAuth    4
#define LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlAuth    44
#define LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlAuth    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SePwrCtrlAuth    40
#define LIN_BYTE_OFFSET_LI1_SeInverterRequest    306
#define LIN_BIT_OFFSET_LI1_SeInverterRequest    0
#define LIN_SIGNAL_SIZE_LI1_SeInverterRequest    4
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInverterRequest    44
#define LIN_FLAG_BIT_OFFSET_LI1_SeInverterRequest    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInverterRequest    40
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteA    321
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteA    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteA    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteA    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteA    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteA    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteB    322
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteB    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteB    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteB    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteB    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteB    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteC    323
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteC    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteC    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteC    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteC    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteC    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteD    324
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteD    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteD    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteD    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteD    4
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteD    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteE    325
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteE    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteE    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteE    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteE    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteE    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteF    326
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteF    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteF    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteF    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteF    6
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteF    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072ByteG    327
#define LIN_BIT_OFFSET_LI1_SeJ3072ByteG    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072ByteG    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteG    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteG    7
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteG    42
#define LIN_BYTE_OFFSET_LI1_SeJ3072Page    320
#define LIN_BIT_OFFSET_LI1_SeJ3072Page    0
#define LIN_SIGNAL_SIZE_LI1_SeJ3072Page    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072Page    46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072Page    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072Page    42
#define LIN_BYTE_OFFSET_LI1_SePwrCtrlUnits    308
#define LIN_BIT_OFFSET_LI1_SePwrCtrlUnits    0
#define LIN_SIGNAL_SIZE_LI1_SePwrCtrlUnits    4
#define LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlUnits    44
#define LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlUnits    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SePwrCtrlUnits    40
#define LIN_BYTE_OFFSET_LI1_SeTargets1ElementA    328
#define LIN_BIT_OFFSET_LI1_SeTargets1ElementA    0
#define LIN_SIGNAL_SIZE_LI1_SeTargets1ElementA    16
#define LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementA    47
#define LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementA    0
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementA    43
#define LIN_BYTE_OFFSET_LI1_SeTargets1ElementB    330
#define LIN_BIT_OFFSET_LI1_SeTargets1ElementB    0
#define LIN_SIGNAL_SIZE_LI1_SeTargets1ElementB    16
#define LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementB    47
#define LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementB    1
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementB    43
#define LIN_BYTE_OFFSET_LI1_SeTargets1ElementC    332
#define LIN_BIT_OFFSET_LI1_SeTargets1ElementC    0
#define LIN_SIGNAL_SIZE_LI1_SeTargets1ElementC    16
#define LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementC    47
#define LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementC    2
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementC    43
#define LIN_BYTE_OFFSET_LI1_SeTargets1ElementD    334
#define LIN_BIT_OFFSET_LI1_SeTargets1ElementD    0
#define LIN_SIGNAL_SIZE_LI1_SeTargets1ElementD    16
#define LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementD    47
#define LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementD    3
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementD    43
#define LIN_BYTE_OFFSET_LI1_SeTimeStamp    311
#define LIN_BIT_OFFSET_LI1_SeTimeStamp    0
#define LIN_SIGNAL_SIZE_LI1_SeTimeStamp    8
#define LIN_FLAG_BYTE_OFFSET_LI1_SeTimeStamp    44
#define LIN_FLAG_BIT_OFFSET_LI1_SeTimeStamp    5
#define LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTimeStamp    40



#define LIN_FLAG_BYTE_OFFSET_LI0_SeVersionList             0
#define LIN_FLAG_BIT_OFFSET_LI0_SeVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvVersionList             2
#define LIN_FLAG_BIT_OFFSET_LI0_EvVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeStatus             4
#define LIN_FLAG_BIT_OFFSET_LI0_SeStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvStatus             5
#define LIN_FLAG_BIT_OFFSET_LI0_EvStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrents             7
#define LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltages             8
#define LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrents             9
#define LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltages             10
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltages             11
#define LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvMaxMinCurrents             12
#define LIN_FLAG_BIT_OFFSET_LI0_EvMaxMinCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvInfoList             13
#define LIN_FLAG_BIT_OFFSET_LI0_EvInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeInfoList             14
#define LIN_FLAG_BIT_OFFSET_LI0_SeInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_StErrorList             15
#define LIN_FLAG_BIT_OFFSET_LI0_StErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvErrorList             16
#define LIN_FLAG_BIT_OFFSET_LI0_EvErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeID             17
#define LIN_FLAG_BIT_OFFSET_LI0_SeID              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvID             18
#define LIN_FLAG_BIT_OFFSET_LI0_EvID              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvModeCtrl             19
#define LIN_FLAG_BIT_OFFSET_LI0_EvModeCtrl              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeModeCtrl             20
#define LIN_FLAG_BIT_OFFSET_LI0_SeModeCtrl              0
#define LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072             21
#define LIN_FLAG_BIT_OFFSET_LI0_EvJ3072              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072             22
#define LIN_FLAG_BIT_OFFSET_LI0_SeJ3072              0
#define LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1             23
#define LIN_FLAG_BIT_OFFSET_LI0_SeTargets1              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeVersionList             24
#define LIN_FLAG_BIT_OFFSET_LI1_SeVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvVersionList             26
#define LIN_FLAG_BIT_OFFSET_LI1_EvVersionList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeStatus             28
#define LIN_FLAG_BIT_OFFSET_LI1_SeStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvStatus             29
#define LIN_FLAG_BIT_OFFSET_LI1_EvStatus              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrents             31
#define LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltages             32
#define LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrents             33
#define LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltages             34
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltages             35
#define LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltages              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvMaxMinCurrents             36
#define LIN_FLAG_BIT_OFFSET_LI1_EvMaxMinCurrents              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvInfoList             37
#define LIN_FLAG_BIT_OFFSET_LI1_EvInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeInfoList             38
#define LIN_FLAG_BIT_OFFSET_LI1_SeInfoList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_StErrorList             39
#define LIN_FLAG_BIT_OFFSET_LI1_StErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvErrorList             40
#define LIN_FLAG_BIT_OFFSET_LI1_EvErrorList              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeID             41
#define LIN_FLAG_BIT_OFFSET_LI1_SeID              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvID             42
#define LIN_FLAG_BIT_OFFSET_LI1_EvID              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvModeCtrl             43
#define LIN_FLAG_BIT_OFFSET_LI1_EvModeCtrl              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeModeCtrl             44
#define LIN_FLAG_BIT_OFFSET_LI1_SeModeCtrl              0
#define LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072             45
#define LIN_FLAG_BIT_OFFSET_LI1_EvJ3072              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072             46
#define LIN_FLAG_BIT_OFFSET_LI1_SeJ3072              0
#define LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1             47
#define LIN_FLAG_BIT_OFFSET_LI1_SeTargets1              0


/**********************************************************************/
/***************        Static API Functions        *******************/
/**********************************************************************/
/*
 * the static signal access macros
 */
/* static access macros for signal LI0_EvSelectedVersion */
  #define l_u8_rd_LI0_EvSelectedVersion_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList))
#define l_u8_rd_LI0_EvSelectedVersion_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus))
#define l_u8_rd_LI0_EvSelectedVersion_EvPresentCurrents() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvPresentCurrents) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents))
#define l_u8_rd_LI0_EvSelectedVersion_EvMaxVoltages() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxVoltages) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages))
#define l_u8_rd_LI0_EvSelectedVersion_EvMinVoltages() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMinVoltages) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages))
#define l_u8_rd_LI0_EvSelectedVersion_EvMaxMinCurrents() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxMinCurrents) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents))
#define l_u8_rd_LI0_EvSelectedVersion_EvInfoList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvInfoList) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList))
#define l_u8_rd_LI0_EvSelectedVersion_EvErrorList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvErrorList) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList )) >> LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList))

#define l_u8_wr_LI0_EvSelectedVersion(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvVersionList) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvStatus) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvPresentCurrents) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvPresentCurrents) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxVoltages) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxVoltages) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMinVoltages) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMinVoltages) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxMinCurrents) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvMaxMinCurrents) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvInfoList) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvInfoList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvErrorList) - 1) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSelectedVersion_EvErrorList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList] = 1;}\
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
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvResponseError_EvVersionList] = 1;}\
	{(A) ? \
  	(LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus], \
  	LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus)):\
  	(LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvResponseError_EvStatus], \
  	LIN_BIT_OFFSET_LI0_EvResponseError_EvStatus));\
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvResponseError_EvStatus] = 1;}\

/* static access macros for signal LI0_EvStatusVer */
  #define l_u8_rd_LI0_EvStatusVer_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_EvStatusVer_EvVersionList )) >> LIN_BIT_OFFSET_LI0_EvStatusVer_EvVersionList))
#define l_u8_rd_LI0_EvStatusVer_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_EvStatusVer_EvStatus )) >> LIN_BIT_OFFSET_LI0_EvStatusVer_EvStatus))

#define l_u8_wr_LI0_EvStatusVer(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvVersionList) - 1) << LIN_BIT_OFFSET_LI0_EvStatusVer_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvStatusVer_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusVer_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvStatus) - 1) << LIN_BIT_OFFSET_LI0_EvStatusVer_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvStatusVer_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvStatusVer_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusVer_EvStatus] = 1;}\
/* static access macros for signal LI0_EvStatusInit */
  #define l_u8_rd_LI0_EvStatusInit_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_EvStatusInit_EvVersionList )) >> LIN_BIT_OFFSET_LI0_EvStatusInit_EvVersionList))
#define l_u8_rd_LI0_EvStatusInit_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_EvStatusInit_EvStatus )) >> LIN_BIT_OFFSET_LI0_EvStatusInit_EvStatus))

#define l_u8_wr_LI0_EvStatusInit(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvVersionList) - 1) << LIN_BIT_OFFSET_LI0_EvStatusInit_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvStatusInit_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusInit_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvStatus) - 1) << LIN_BIT_OFFSET_LI0_EvStatusInit_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvStatusInit_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvStatusInit_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusInit_EvStatus] = 1;}\
/* static access macros for signal LI0_EvStatusOp */
  #define l_u8_rd_LI0_EvStatusOp_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_EvStatusOp_EvVersionList )) >> LIN_BIT_OFFSET_LI0_EvStatusOp_EvVersionList))
#define l_u8_rd_LI0_EvStatusOp_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_EvStatusOp_EvStatus )) >> LIN_BIT_OFFSET_LI0_EvStatusOp_EvStatus))

#define l_u8_wr_LI0_EvStatusOp(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvVersionList) - 1) << LIN_BIT_OFFSET_LI0_EvStatusOp_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvStatusOp_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvStatusOp_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvStatus) - 1) << LIN_BIT_OFFSET_LI0_EvStatusOp_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvStatusOp_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvStatusOp_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvStatusOp_EvStatus] = 1;}\
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
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvAwake_EvVersionList] = 1;}\
	{(A) ? \
  	(LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus], \
  	LIN_BIT_OFFSET_LI0_EvAwake_EvStatus)):\
  	(LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvAwake_EvStatus], \
  	LIN_BIT_OFFSET_LI0_EvAwake_EvStatus));\
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvAwake_EvStatus] = 1;}\

/* static access macros for signal LI0_EvVersionPageNumber */
   
#define l_u8_rd_LI0_EvVersionPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvVersionPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvVersionPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI0_EvVersionPageNumber )) >> LIN_BIT_OFFSET_LI0_EvVersionPageNumber))
#define l_u8_wr_LI0_EvVersionPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvVersionPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvVersionPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvVersionPageNumber) - 1) << LIN_BIT_OFFSET_LI0_EvVersionPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvVersionPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvVersionPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvVersionPageNumber] = 1;}
/* static access macros for signal LI0_EvSupportedVersion1 */
   
#define l_u8_rd_LI0_EvSupportedVersion1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSupportedVersion1 )) >> LIN_BIT_OFFSET_LI0_EvSupportedVersion1))
#define l_u8_wr_LI0_EvSupportedVersion1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion1) - 1) << LIN_BIT_OFFSET_LI0_EvSupportedVersion1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSupportedVersion1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion1] = 1;}
/* static access macros for signal LI0_EvSupportedVersion2 */
   
#define l_u8_rd_LI0_EvSupportedVersion2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSupportedVersion2 )) >> LIN_BIT_OFFSET_LI0_EvSupportedVersion2))
#define l_u8_wr_LI0_EvSupportedVersion2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion2) - 1) << LIN_BIT_OFFSET_LI0_EvSupportedVersion2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSupportedVersion2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion2] = 1;}
/* static access macros for signal LI0_EvSupportedVersion3 */
   
#define l_u8_rd_LI0_EvSupportedVersion3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSupportedVersion3 )) >> LIN_BIT_OFFSET_LI0_EvSupportedVersion3))
#define l_u8_wr_LI0_EvSupportedVersion3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion3) - 1) << LIN_BIT_OFFSET_LI0_EvSupportedVersion3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSupportedVersion3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion3] = 1;}
/* static access macros for signal LI0_EvSupportedVersion4 */
   
#define l_u8_rd_LI0_EvSupportedVersion4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion4] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion4) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSupportedVersion4 )) >> LIN_BIT_OFFSET_LI0_EvSupportedVersion4))
#define l_u8_wr_LI0_EvSupportedVersion4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion4) - 1) << LIN_BIT_OFFSET_LI0_EvSupportedVersion4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion4) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSupportedVersion4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion4] = 1;}
/* static access macros for signal LI0_EvSupportedVersion5 */
   
#define l_u8_rd_LI0_EvSupportedVersion5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion5] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion5) - 1) \
    << LIN_BIT_OFFSET_LI0_EvSupportedVersion5 )) >> LIN_BIT_OFFSET_LI0_EvSupportedVersion5))
#define l_u8_wr_LI0_EvSupportedVersion5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvSupportedVersion5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion5) - 1) << LIN_BIT_OFFSET_LI0_EvSupportedVersion5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvSupportedVersion5) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvSupportedVersion5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvSupportedVersion5] = 1;}
/* static access macros for signal LI0_EvRequestedCurrentL1 */
   
#define l_u8_rd_LI0_EvRequestedCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL1 )) >> LIN_BIT_OFFSET_LI0_EvRequestedCurrentL1))
#define l_u8_wr_LI0_EvRequestedCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL1) - 1) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentL1] = 1;}
/* static access macros for signal LI0_EvRequestedCurrentL2 */
   
#define l_u8_rd_LI0_EvRequestedCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL2 )) >> LIN_BIT_OFFSET_LI0_EvRequestedCurrentL2))
#define l_u8_wr_LI0_EvRequestedCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL2) - 1) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentL2] = 1;}
/* static access macros for signal LI0_EvRequestedCurrentL3 */
   
#define l_u8_rd_LI0_EvRequestedCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL3 )) >> LIN_BIT_OFFSET_LI0_EvRequestedCurrentL3))
#define l_u8_wr_LI0_EvRequestedCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL3) - 1) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentL3] = 1;}
/* static access macros for signal LI0_EvRequestedCurrentN */
   
#define l_u8_rd_LI0_EvRequestedCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI0_EvRequestedCurrentN )) >> LIN_BIT_OFFSET_LI0_EvRequestedCurrentN))
#define l_u8_wr_LI0_EvRequestedCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvRequestedCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentN) - 1) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvRequestedCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvRequestedCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvRequestedCurrentN] = 1;}
/* static access macros for signal LI0_SeSelectedVersion */
  #define l_u8_rd_LI0_SeSelectedVersion_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList )) >> LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList))
#define l_u8_rd_LI0_SeSelectedVersion_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus )) >> LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus))
#define l_u8_rd_LI0_SeSelectedVersion_SeNomVoltages() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeNomVoltages) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages )) >> LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages))
#define l_u8_rd_LI0_SeSelectedVersion_SeMaxCurrents() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeMaxCurrents) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents )) >> LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents))
#define l_u8_rd_LI0_SeSelectedVersion_SeInfoList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeInfoList) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList )) >> LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList))
#define l_u8_rd_LI0_SeSelectedVersion_StErrorList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_StErrorList) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList )) >> LIN_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList))

#define l_u8_wr_LI0_SeSelectedVersion(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeVersionList) - 1) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeStatus) - 1) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeNomVoltages) - 1) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeNomVoltages) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeMaxCurrents) - 1) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeMaxCurrents) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeInfoList) - 1) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_SeInfoList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_StErrorList) - 1) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSelectedVersion_StErrorList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList] = 1;}\
/* static access macros for signal LI0_SeStatusVer */
  #define l_u8_rd_LI0_SeStatusVer_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_SeStatusVer_SeVersionList )) >> LIN_BIT_OFFSET_LI0_SeStatusVer_SeVersionList))
#define l_u8_rd_LI0_SeStatusVer_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_SeStatusVer_SeStatus )) >> LIN_BIT_OFFSET_LI0_SeStatusVer_SeStatus))

#define l_u8_wr_LI0_SeStatusVer(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeVersionList) - 1) << LIN_BIT_OFFSET_LI0_SeStatusVer_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeStatusVer_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusVer_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeStatus) - 1) << LIN_BIT_OFFSET_LI0_SeStatusVer_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeStatusVer_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeStatusVer_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusVer_SeStatus] = 1;}\
/* static access macros for signal LI0_SeStatusInit */
  #define l_u8_rd_LI0_SeStatusInit_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_SeStatusInit_SeVersionList )) >> LIN_BIT_OFFSET_LI0_SeStatusInit_SeVersionList))
#define l_u8_rd_LI0_SeStatusInit_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_SeStatusInit_SeStatus )) >> LIN_BIT_OFFSET_LI0_SeStatusInit_SeStatus))

#define l_u8_wr_LI0_SeStatusInit(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeVersionList) - 1) << LIN_BIT_OFFSET_LI0_SeStatusInit_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeStatusInit_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusInit_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeStatus) - 1) << LIN_BIT_OFFSET_LI0_SeStatusInit_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeStatusInit_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeStatusInit_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusInit_SeStatus] = 1;}\
/* static access macros for signal LI0_SeStatusOp */
  #define l_u8_rd_LI0_SeStatusOp_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI0_SeStatusOp_SeVersionList )) >> LIN_BIT_OFFSET_LI0_SeStatusOp_SeVersionList))
#define l_u8_rd_LI0_SeStatusOp_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI0_SeStatusOp_SeStatus )) >> LIN_BIT_OFFSET_LI0_SeStatusOp_SeStatus))

#define l_u8_wr_LI0_SeStatusOp(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeVersionList) - 1) << LIN_BIT_OFFSET_LI0_SeStatusOp_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeStatusOp_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeStatusOp_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeStatus) - 1) << LIN_BIT_OFFSET_LI0_SeStatusOp_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeStatusOp_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeStatusOp_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeStatusOp_SeStatus] = 1;}\
/* static access macros for signal LI0_SeVersionPageNumber */
   
#define l_u8_rd_LI0_SeVersionPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeVersionPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeVersionPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI0_SeVersionPageNumber )) >> LIN_BIT_OFFSET_LI0_SeVersionPageNumber))
#define l_u8_wr_LI0_SeVersionPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeVersionPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeVersionPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeVersionPageNumber) - 1) << LIN_BIT_OFFSET_LI0_SeVersionPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeVersionPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeVersionPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeVersionPageNumber] = 1;}
/* static access macros for signal LI0_SeSupportedVersion1 */
   
#define l_u8_rd_LI0_SeSupportedVersion1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion1) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSupportedVersion1 )) >> LIN_BIT_OFFSET_LI0_SeSupportedVersion1))
#define l_u8_wr_LI0_SeSupportedVersion1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion1) - 1) << LIN_BIT_OFFSET_LI0_SeSupportedVersion1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSupportedVersion1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion1] = 1;}
/* static access macros for signal LI0_SeSupportedVersion2 */
   
#define l_u8_rd_LI0_SeSupportedVersion2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion2) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSupportedVersion2 )) >> LIN_BIT_OFFSET_LI0_SeSupportedVersion2))
#define l_u8_wr_LI0_SeSupportedVersion2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion2) - 1) << LIN_BIT_OFFSET_LI0_SeSupportedVersion2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSupportedVersion2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion2] = 1;}
/* static access macros for signal LI0_SeSupportedVersion3 */
   
#define l_u8_rd_LI0_SeSupportedVersion3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion3) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSupportedVersion3 )) >> LIN_BIT_OFFSET_LI0_SeSupportedVersion3))
#define l_u8_wr_LI0_SeSupportedVersion3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion3) - 1) << LIN_BIT_OFFSET_LI0_SeSupportedVersion3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSupportedVersion3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion3] = 1;}
/* static access macros for signal LI0_SeSupportedVersion4 */
   
#define l_u8_rd_LI0_SeSupportedVersion4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion4] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion4) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSupportedVersion4 )) >> LIN_BIT_OFFSET_LI0_SeSupportedVersion4))
#define l_u8_wr_LI0_SeSupportedVersion4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion4) - 1) << LIN_BIT_OFFSET_LI0_SeSupportedVersion4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion4) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSupportedVersion4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion4] = 1;}
/* static access macros for signal LI0_SeSupportedVersion5 */
   
#define l_u8_rd_LI0_SeSupportedVersion5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion5] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion5) - 1) \
    << LIN_BIT_OFFSET_LI0_SeSupportedVersion5 )) >> LIN_BIT_OFFSET_LI0_SeSupportedVersion5))
#define l_u8_wr_LI0_SeSupportedVersion5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeSupportedVersion5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion5) - 1) << LIN_BIT_OFFSET_LI0_SeSupportedVersion5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeSupportedVersion5) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeSupportedVersion5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeSupportedVersion5] = 1;}
/* static access macros for signal LI0_SeAvailableCurrentL1 */
   
#define l_u8_rd_LI0_SeAvailableCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL1 )) >> LIN_BIT_OFFSET_LI0_SeAvailableCurrentL1))
#define l_u8_wr_LI0_SeAvailableCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL1) - 1) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentL1] = 1;}
/* static access macros for signal LI0_SeAvailableCurrentL2 */
   
#define l_u8_rd_LI0_SeAvailableCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL2 )) >> LIN_BIT_OFFSET_LI0_SeAvailableCurrentL2))
#define l_u8_wr_LI0_SeAvailableCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL2) - 1) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentL2] = 1;}
/* static access macros for signal LI0_SeAvailableCurrentL3 */
   
#define l_u8_rd_LI0_SeAvailableCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL3 )) >> LIN_BIT_OFFSET_LI0_SeAvailableCurrentL3))
#define l_u8_wr_LI0_SeAvailableCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL3) - 1) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentL3] = 1;}
/* static access macros for signal LI0_SeAvailableCurrentN */
   
#define l_u8_rd_LI0_SeAvailableCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI0_SeAvailableCurrentN )) >> LIN_BIT_OFFSET_LI0_SeAvailableCurrentN))
#define l_u8_wr_LI0_SeAvailableCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeAvailableCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentN) - 1) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeAvailableCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeAvailableCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeAvailableCurrentN] = 1;}
/* static access macros for signal LI0_EvPresentCurrentL1 */
   
#define l_u8_rd_LI0_EvPresentCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvPresentCurrentL1 )) >> LIN_BIT_OFFSET_LI0_EvPresentCurrentL1))
#define l_u8_wr_LI0_EvPresentCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL1) - 1) << LIN_BIT_OFFSET_LI0_EvPresentCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvPresentCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentL1] = 1;}
/* static access macros for signal LI0_EvPresentCurrentL2 */
   
#define l_u8_rd_LI0_EvPresentCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvPresentCurrentL2 )) >> LIN_BIT_OFFSET_LI0_EvPresentCurrentL2))
#define l_u8_wr_LI0_EvPresentCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL2) - 1) << LIN_BIT_OFFSET_LI0_EvPresentCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvPresentCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentL2] = 1;}
/* static access macros for signal LI0_EvPresentCurrentL3 */
   
#define l_u8_rd_LI0_EvPresentCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvPresentCurrentL3 )) >> LIN_BIT_OFFSET_LI0_EvPresentCurrentL3))
#define l_u8_wr_LI0_EvPresentCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL3) - 1) << LIN_BIT_OFFSET_LI0_EvPresentCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvPresentCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentL3] = 1;}
/* static access macros for signal LI0_EvPresentCurrentN */
   
#define l_u8_rd_LI0_EvPresentCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI0_EvPresentCurrentN )) >> LIN_BIT_OFFSET_LI0_EvPresentCurrentN))
#define l_u8_wr_LI0_EvPresentCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPresentCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentN) - 1) << LIN_BIT_OFFSET_LI0_EvPresentCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvPresentCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvPresentCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPresentCurrentN] = 1;}
/* static access macros for signal LI0_SeFrequency */
   
#define l_u8_rd_LI0_SeFrequency() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeFrequency] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeFrequency) - 1) \
    << LIN_BIT_OFFSET_LI0_SeFrequency )) >> LIN_BIT_OFFSET_LI0_SeFrequency))
#define l_u8_wr_LI0_SeFrequency(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeFrequency] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeFrequency] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeFrequency) - 1) << LIN_BIT_OFFSET_LI0_SeFrequency)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeFrequency) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeFrequency))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeFrequency] = 1;}
/* static access macros for signal LI0_SeMaxCurrentL1 */
   
#define l_u8_rd_LI0_SeMaxCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI0_SeMaxCurrentL1 )) >> LIN_BIT_OFFSET_LI0_SeMaxCurrentL1))
#define l_u8_wr_LI0_SeMaxCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL1) - 1) << LIN_BIT_OFFSET_LI0_SeMaxCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeMaxCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentL1] = 1;}
/* static access macros for signal LI0_SeMaxCurrentL2 */
   
#define l_u8_rd_LI0_SeMaxCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI0_SeMaxCurrentL2 )) >> LIN_BIT_OFFSET_LI0_SeMaxCurrentL2))
#define l_u8_wr_LI0_SeMaxCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL2) - 1) << LIN_BIT_OFFSET_LI0_SeMaxCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeMaxCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentL2] = 1;}
/* static access macros for signal LI0_SeMaxCurrentL3 */
   
#define l_u8_rd_LI0_SeMaxCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI0_SeMaxCurrentL3 )) >> LIN_BIT_OFFSET_LI0_SeMaxCurrentL3))
#define l_u8_wr_LI0_SeMaxCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL3) - 1) << LIN_BIT_OFFSET_LI0_SeMaxCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeMaxCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentL3] = 1;}
/* static access macros for signal LI0_SeMaxCurrentN */
   
#define l_u8_rd_LI0_SeMaxCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI0_SeMaxCurrentN )) >> LIN_BIT_OFFSET_LI0_SeMaxCurrentN))
#define l_u8_wr_LI0_SeMaxCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeMaxCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentN) - 1) << LIN_BIT_OFFSET_LI0_SeMaxCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeMaxCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeMaxCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeMaxCurrentN] = 1;}
/* static access macros for signal LI0_SeConnectionType */
   
#define l_u8_rd_LI0_SeConnectionType() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeConnectionType] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeConnectionType) - 1) \
    << LIN_BIT_OFFSET_LI0_SeConnectionType )) >> LIN_BIT_OFFSET_LI0_SeConnectionType))
#define l_u8_wr_LI0_SeConnectionType(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeConnectionType] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeConnectionType] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeConnectionType) - 1) << LIN_BIT_OFFSET_LI0_SeConnectionType)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeConnectionType) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeConnectionType))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeConnectionType] = 1;}
/* static access macros for signal LI0_EvFrequencies */
   
#define l_u8_rd_LI0_EvFrequencies() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvFrequencies] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvFrequencies) - 1) \
    << LIN_BIT_OFFSET_LI0_EvFrequencies )) >> LIN_BIT_OFFSET_LI0_EvFrequencies))
#define l_u8_wr_LI0_EvFrequencies(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvFrequencies] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvFrequencies] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvFrequencies) - 1) << LIN_BIT_OFFSET_LI0_EvFrequencies)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvFrequencies) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvFrequencies))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvFrequencies] = 1;}
/* static access macros for signal LI0_EvConnectionType */
   
#define l_u8_rd_LI0_EvConnectionType() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvConnectionType] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvConnectionType) - 1) \
    << LIN_BIT_OFFSET_LI0_EvConnectionType )) >> LIN_BIT_OFFSET_LI0_EvConnectionType))
#define l_u8_wr_LI0_EvConnectionType(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvConnectionType] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvConnectionType] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvConnectionType) - 1) << LIN_BIT_OFFSET_LI0_EvConnectionType)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvConnectionType) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvConnectionType))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvConnectionType] = 1;}
/* static access macros for signal LI0_EvMaxCurrentL1 */
   
#define l_u8_rd_LI0_EvMaxCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMaxCurrentL1 )) >> LIN_BIT_OFFSET_LI0_EvMaxCurrentL1))
#define l_u8_wr_LI0_EvMaxCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL1) - 1) << LIN_BIT_OFFSET_LI0_EvMaxCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMaxCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentL1] = 1;}
/* static access macros for signal LI0_EvMaxCurrentL2 */
   
#define l_u8_rd_LI0_EvMaxCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMaxCurrentL2 )) >> LIN_BIT_OFFSET_LI0_EvMaxCurrentL2))
#define l_u8_wr_LI0_EvMaxCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL2) - 1) << LIN_BIT_OFFSET_LI0_EvMaxCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMaxCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentL2] = 1;}
/* static access macros for signal LI0_EvMaxCurrentL3 */
   
#define l_u8_rd_LI0_EvMaxCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMaxCurrentL3 )) >> LIN_BIT_OFFSET_LI0_EvMaxCurrentL3))
#define l_u8_wr_LI0_EvMaxCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL3) - 1) << LIN_BIT_OFFSET_LI0_EvMaxCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMaxCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentL3] = 1;}
/* static access macros for signal LI0_EvMaxCurrentN */
   
#define l_u8_rd_LI0_EvMaxCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMaxCurrentN )) >> LIN_BIT_OFFSET_LI0_EvMaxCurrentN))
#define l_u8_wr_LI0_EvMaxCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentN) - 1) << LIN_BIT_OFFSET_LI0_EvMaxCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMaxCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMaxCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxCurrentN] = 1;}
/* static access macros for signal LI0_EvMinCurrentL1 */
   
#define l_u8_rd_LI0_EvMinCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMinCurrentL1 )) >> LIN_BIT_OFFSET_LI0_EvMinCurrentL1))
#define l_u8_wr_LI0_EvMinCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL1) - 1) << LIN_BIT_OFFSET_LI0_EvMinCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMinCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinCurrentL1] = 1;}
/* static access macros for signal LI0_EvMinCurrentL2 */
   
#define l_u8_rd_LI0_EvMinCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMinCurrentL2 )) >> LIN_BIT_OFFSET_LI0_EvMinCurrentL2))
#define l_u8_wr_LI0_EvMinCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL2) - 1) << LIN_BIT_OFFSET_LI0_EvMinCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMinCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinCurrentL2] = 1;}
/* static access macros for signal LI0_EvMinCurrentL3 */
   
#define l_u8_rd_LI0_EvMinCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvMinCurrentL3 )) >> LIN_BIT_OFFSET_LI0_EvMinCurrentL3))
#define l_u8_wr_LI0_EvMinCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL3) - 1) << LIN_BIT_OFFSET_LI0_EvMinCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvMinCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvMinCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinCurrentL3] = 1;}
/* static access macros for signal LI0_EvInfoEntry1 */
   
#define l_u8_rd_LI0_EvInfoEntry1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoEntry1 )) >> LIN_BIT_OFFSET_LI0_EvInfoEntry1))
#define l_u8_wr_LI0_EvInfoEntry1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry1) - 1) << LIN_BIT_OFFSET_LI0_EvInfoEntry1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoEntry1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry1] = 1;}
/* static access macros for signal LI0_EvInfoEntry2 */
   
#define l_u8_rd_LI0_EvInfoEntry2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoEntry2 )) >> LIN_BIT_OFFSET_LI0_EvInfoEntry2))
#define l_u8_wr_LI0_EvInfoEntry2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry2) - 1) << LIN_BIT_OFFSET_LI0_EvInfoEntry2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoEntry2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry2] = 1;}
/* static access macros for signal LI0_EvInfoEntry3 */
   
#define l_u8_rd_LI0_EvInfoEntry3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoEntry3 )) >> LIN_BIT_OFFSET_LI0_EvInfoEntry3))
#define l_u8_wr_LI0_EvInfoEntry3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry3) - 1) << LIN_BIT_OFFSET_LI0_EvInfoEntry3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoEntry3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry3] = 1;}
/* static access macros for signal LI0_EvInfoEntry4 */
   
#define l_u8_rd_LI0_EvInfoEntry4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry4] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry4) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoEntry4 )) >> LIN_BIT_OFFSET_LI0_EvInfoEntry4))
#define l_u8_wr_LI0_EvInfoEntry4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry4) - 1) << LIN_BIT_OFFSET_LI0_EvInfoEntry4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry4) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoEntry4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry4] = 1;}
/* static access macros for signal LI0_EvInfoEntry5 */
   
#define l_u8_rd_LI0_EvInfoEntry5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry5] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry5) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoEntry5 )) >> LIN_BIT_OFFSET_LI0_EvInfoEntry5))
#define l_u8_wr_LI0_EvInfoEntry5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry5) - 1) << LIN_BIT_OFFSET_LI0_EvInfoEntry5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry5) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoEntry5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry5] = 1;}
/* static access macros for signal LI0_EvInfoEntry6 */
   
#define l_u8_rd_LI0_EvInfoEntry6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry6] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry6) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoEntry6 )) >> LIN_BIT_OFFSET_LI0_EvInfoEntry6))
#define l_u8_wr_LI0_EvInfoEntry6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoEntry6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry6) - 1) << LIN_BIT_OFFSET_LI0_EvInfoEntry6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoEntry6) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoEntry6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoEntry6] = 1;}
/* static access macros for signal LI0_SeInfoEntry1 */
   
#define l_u8_rd_LI0_SeInfoEntry1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry1) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoEntry1 )) >> LIN_BIT_OFFSET_LI0_SeInfoEntry1))
#define l_u8_wr_LI0_SeInfoEntry1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry1) - 1) << LIN_BIT_OFFSET_LI0_SeInfoEntry1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoEntry1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry1] = 1;}
/* static access macros for signal LI0_SeInfoEntry2 */
   
#define l_u8_rd_LI0_SeInfoEntry2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry2) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoEntry2 )) >> LIN_BIT_OFFSET_LI0_SeInfoEntry2))
#define l_u8_wr_LI0_SeInfoEntry2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry2) - 1) << LIN_BIT_OFFSET_LI0_SeInfoEntry2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoEntry2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry2] = 1;}
/* static access macros for signal LI0_SeInfoEntry3 */
   
#define l_u8_rd_LI0_SeInfoEntry3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry3) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoEntry3 )) >> LIN_BIT_OFFSET_LI0_SeInfoEntry3))
#define l_u8_wr_LI0_SeInfoEntry3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry3) - 1) << LIN_BIT_OFFSET_LI0_SeInfoEntry3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoEntry3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry3] = 1;}
/* static access macros for signal LI0_SeInfoEntry4 */
   
#define l_u8_rd_LI0_SeInfoEntry4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry4] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry4) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoEntry4 )) >> LIN_BIT_OFFSET_LI0_SeInfoEntry4))
#define l_u8_wr_LI0_SeInfoEntry4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry4) - 1) << LIN_BIT_OFFSET_LI0_SeInfoEntry4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry4) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoEntry4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry4] = 1;}
/* static access macros for signal LI0_SeInfoEntry5 */
   
#define l_u8_rd_LI0_SeInfoEntry5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry5] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry5) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoEntry5 )) >> LIN_BIT_OFFSET_LI0_SeInfoEntry5))
#define l_u8_wr_LI0_SeInfoEntry5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry5) - 1) << LIN_BIT_OFFSET_LI0_SeInfoEntry5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry5) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoEntry5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry5] = 1;}
/* static access macros for signal LI0_SeInfoEntry6 */
   
#define l_u8_rd_LI0_SeInfoEntry6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry6] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry6) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoEntry6 )) >> LIN_BIT_OFFSET_LI0_SeInfoEntry6))
#define l_u8_wr_LI0_SeInfoEntry6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoEntry6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry6) - 1) << LIN_BIT_OFFSET_LI0_SeInfoEntry6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoEntry6) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoEntry6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoEntry6] = 1;}
/* static access macros for signal LI0_EvInfoPageNumber */
   
#define l_u8_rd_LI0_EvInfoPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInfoPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInfoPageNumber )) >> LIN_BIT_OFFSET_LI0_EvInfoPageNumber))
#define l_u8_wr_LI0_EvInfoPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInfoPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInfoPageNumber) - 1) << LIN_BIT_OFFSET_LI0_EvInfoPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInfoPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInfoPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInfoPageNumber] = 1;}
/* static access macros for signal LI0_SeInfoPageNumber */
   
#define l_u8_rd_LI0_SeInfoPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInfoPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInfoPageNumber )) >> LIN_BIT_OFFSET_LI0_SeInfoPageNumber))
#define l_u8_wr_LI0_SeInfoPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInfoPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInfoPageNumber) - 1) << LIN_BIT_OFFSET_LI0_SeInfoPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInfoPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInfoPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInfoPageNumber] = 1;}
/* static access macros for signal LI0_StErrorPageNumber */
   
#define l_u8_rd_LI0_StErrorPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorPageNumber )) >> LIN_BIT_OFFSET_LI0_StErrorPageNumber))
#define l_u8_wr_LI0_StErrorPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorPageNumber) - 1) << LIN_BIT_OFFSET_LI0_StErrorPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorPageNumber] = 1;}
/* static access macros for signal LI0_StErrorCode1 */
   
#define l_u8_rd_LI0_StErrorCode1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode1) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorCode1 )) >> LIN_BIT_OFFSET_LI0_StErrorCode1))
#define l_u8_wr_LI0_StErrorCode1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode1) - 1) << LIN_BIT_OFFSET_LI0_StErrorCode1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorCode1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode1] = 1;}
/* static access macros for signal LI0_StErrorCode2 */
   
#define l_u8_rd_LI0_StErrorCode2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode2) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorCode2 )) >> LIN_BIT_OFFSET_LI0_StErrorCode2))
#define l_u8_wr_LI0_StErrorCode2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode2) - 1) << LIN_BIT_OFFSET_LI0_StErrorCode2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorCode2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode2] = 1;}
/* static access macros for signal LI0_StErrorCode3 */
   
#define l_u8_rd_LI0_StErrorCode3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode3) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorCode3 )) >> LIN_BIT_OFFSET_LI0_StErrorCode3))
#define l_u8_wr_LI0_StErrorCode3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode3) - 1) << LIN_BIT_OFFSET_LI0_StErrorCode3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorCode3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode3] = 1;}
/* static access macros for signal LI0_StErrorCode4 */
   
#define l_u8_rd_LI0_StErrorCode4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode4] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode4) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorCode4 )) >> LIN_BIT_OFFSET_LI0_StErrorCode4))
#define l_u8_wr_LI0_StErrorCode4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode4) - 1) << LIN_BIT_OFFSET_LI0_StErrorCode4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode4) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorCode4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode4] = 1;}
/* static access macros for signal LI0_StErrorCode5 */
   
#define l_u8_rd_LI0_StErrorCode5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode5] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode5) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorCode5 )) >> LIN_BIT_OFFSET_LI0_StErrorCode5))
#define l_u8_wr_LI0_StErrorCode5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode5) - 1) << LIN_BIT_OFFSET_LI0_StErrorCode5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode5) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorCode5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode5] = 1;}
/* static access macros for signal LI0_StErrorCode6 */
   
#define l_u8_rd_LI0_StErrorCode6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode6] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode6) - 1) \
    << LIN_BIT_OFFSET_LI0_StErrorCode6 )) >> LIN_BIT_OFFSET_LI0_StErrorCode6))
#define l_u8_wr_LI0_StErrorCode6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_StErrorCode6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode6) - 1) << LIN_BIT_OFFSET_LI0_StErrorCode6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_StErrorCode6) - 1) & (A)) << LIN_BIT_OFFSET_LI0_StErrorCode6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_StErrorCode6] = 1;}
/* static access macros for signal LI0_EvErrorPageNumber */
   
#define l_u8_rd_LI0_EvErrorPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorPageNumber )) >> LIN_BIT_OFFSET_LI0_EvErrorPageNumber))
#define l_u8_wr_LI0_EvErrorPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorPageNumber) - 1) << LIN_BIT_OFFSET_LI0_EvErrorPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorPageNumber] = 1;}
/* static access macros for signal LI0_EvErrorCode1 */
   
#define l_u8_rd_LI0_EvErrorCode1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode1] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode1) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorCode1 )) >> LIN_BIT_OFFSET_LI0_EvErrorCode1))
#define l_u8_wr_LI0_EvErrorCode1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode1) - 1) << LIN_BIT_OFFSET_LI0_EvErrorCode1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode1) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorCode1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode1] = 1;}
/* static access macros for signal LI0_EvErrorCode2 */
   
#define l_u8_rd_LI0_EvErrorCode2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode2] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode2) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorCode2 )) >> LIN_BIT_OFFSET_LI0_EvErrorCode2))
#define l_u8_wr_LI0_EvErrorCode2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode2) - 1) << LIN_BIT_OFFSET_LI0_EvErrorCode2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode2) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorCode2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode2] = 1;}
/* static access macros for signal LI0_EvErrorCode3 */
   
#define l_u8_rd_LI0_EvErrorCode3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode3] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode3) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorCode3 )) >> LIN_BIT_OFFSET_LI0_EvErrorCode3))
#define l_u8_wr_LI0_EvErrorCode3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode3) - 1) << LIN_BIT_OFFSET_LI0_EvErrorCode3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode3) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorCode3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode3] = 1;}
/* static access macros for signal LI0_EvErrorCode4 */
   
#define l_u8_rd_LI0_EvErrorCode4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode4] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode4) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorCode4 )) >> LIN_BIT_OFFSET_LI0_EvErrorCode4))
#define l_u8_wr_LI0_EvErrorCode4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode4) - 1) << LIN_BIT_OFFSET_LI0_EvErrorCode4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode4) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorCode4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode4] = 1;}
/* static access macros for signal LI0_EvErrorCode5 */
   
#define l_u8_rd_LI0_EvErrorCode5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode5] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode5) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorCode5 )) >> LIN_BIT_OFFSET_LI0_EvErrorCode5))
#define l_u8_wr_LI0_EvErrorCode5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode5) - 1) << LIN_BIT_OFFSET_LI0_EvErrorCode5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode5) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorCode5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode5] = 1;}
/* static access macros for signal LI0_EvErrorCode6 */
   
#define l_u8_rd_LI0_EvErrorCode6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode6] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode6) - 1) \
    << LIN_BIT_OFFSET_LI0_EvErrorCode6 )) >> LIN_BIT_OFFSET_LI0_EvErrorCode6))
#define l_u8_wr_LI0_EvErrorCode6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvErrorCode6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode6) - 1) << LIN_BIT_OFFSET_LI0_EvErrorCode6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvErrorCode6) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvErrorCode6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvErrorCode6] = 1;}
/* static access macros for signal LI0_SeIDPage */
   
#define l_u8_rd_LI0_SeIDPage() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDPage] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDPage) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDPage )) >> LIN_BIT_OFFSET_LI0_SeIDPage))
#define l_u8_wr_LI0_SeIDPage(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDPage] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDPage] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDPage) - 1) << LIN_BIT_OFFSET_LI0_SeIDPage)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDPage) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDPage))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDPage] = 1;}
/* static access macros for signal LI0_SeIDByteA */
   
#define l_u8_rd_LI0_SeIDByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteA) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteA )) >> LIN_BIT_OFFSET_LI0_SeIDByteA))
#define l_u8_wr_LI0_SeIDByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteA) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteA] = 1;}
/* static access macros for signal LI0_SeIDByteB */
   
#define l_u8_rd_LI0_SeIDByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteB) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteB )) >> LIN_BIT_OFFSET_LI0_SeIDByteB))
#define l_u8_wr_LI0_SeIDByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteB) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteB] = 1;}
/* static access macros for signal LI0_SeIDByteC */
   
#define l_u8_rd_LI0_SeIDByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteC) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteC )) >> LIN_BIT_OFFSET_LI0_SeIDByteC))
#define l_u8_wr_LI0_SeIDByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteC) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteC] = 1;}
/* static access macros for signal LI0_SeIDByteD */
   
#define l_u8_rd_LI0_SeIDByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteD) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteD )) >> LIN_BIT_OFFSET_LI0_SeIDByteD))
#define l_u8_wr_LI0_SeIDByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteD) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteD] = 1;}
/* static access macros for signal LI0_SeIDByteE */
   
#define l_u8_rd_LI0_SeIDByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteE) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteE )) >> LIN_BIT_OFFSET_LI0_SeIDByteE))
#define l_u8_wr_LI0_SeIDByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteE) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteE] = 1;}
/* static access macros for signal LI0_SeIDByteF */
   
#define l_u8_rd_LI0_SeIDByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteF) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteF )) >> LIN_BIT_OFFSET_LI0_SeIDByteF))
#define l_u8_wr_LI0_SeIDByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteF) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteF] = 1;}
/* static access macros for signal LI0_SeIDByteG */
   
#define l_u8_rd_LI0_SeIDByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteG) - 1) \
    << LIN_BIT_OFFSET_LI0_SeIDByteG )) >> LIN_BIT_OFFSET_LI0_SeIDByteG))
#define l_u8_wr_LI0_SeIDByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeIDByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteG) - 1) << LIN_BIT_OFFSET_LI0_SeIDByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeIDByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeIDByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeIDByteG] = 1;}
/* static access macros for signal LI0_EvIDPage */
   
#define l_u8_rd_LI0_EvIDPage() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDPage] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDPage) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDPage )) >> LIN_BIT_OFFSET_LI0_EvIDPage))
#define l_u8_wr_LI0_EvIDPage(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDPage] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDPage] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDPage) - 1) << LIN_BIT_OFFSET_LI0_EvIDPage)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDPage) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDPage))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDPage] = 1;}
/* static access macros for signal LI0_EvIDByteA */
   
#define l_u8_rd_LI0_EvIDByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteA) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteA )) >> LIN_BIT_OFFSET_LI0_EvIDByteA))
#define l_u8_wr_LI0_EvIDByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteA) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteA] = 1;}
/* static access macros for signal LI0_EvIDByteB */
   
#define l_u8_rd_LI0_EvIDByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteB) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteB )) >> LIN_BIT_OFFSET_LI0_EvIDByteB))
#define l_u8_wr_LI0_EvIDByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteB) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteB] = 1;}
/* static access macros for signal LI0_EvIDByteC */
   
#define l_u8_rd_LI0_EvIDByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteC) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteC )) >> LIN_BIT_OFFSET_LI0_EvIDByteC))
#define l_u8_wr_LI0_EvIDByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteC) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteC] = 1;}
/* static access macros for signal LI0_EvIDByteD */
   
#define l_u8_rd_LI0_EvIDByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteD) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteD )) >> LIN_BIT_OFFSET_LI0_EvIDByteD))
#define l_u8_wr_LI0_EvIDByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteD) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteD] = 1;}
/* static access macros for signal LI0_EvIDByteE */
   
#define l_u8_rd_LI0_EvIDByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteE) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteE )) >> LIN_BIT_OFFSET_LI0_EvIDByteE))
#define l_u8_wr_LI0_EvIDByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteE) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteE] = 1;}
/* static access macros for signal LI0_EvIDByteF */
   
#define l_u8_rd_LI0_EvIDByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteF) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteF )) >> LIN_BIT_OFFSET_LI0_EvIDByteF))
#define l_u8_wr_LI0_EvIDByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteF) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteF] = 1;}
/* static access macros for signal LI0_EvIDByteG */
   
#define l_u8_rd_LI0_EvIDByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteG) - 1) \
    << LIN_BIT_OFFSET_LI0_EvIDByteG )) >> LIN_BIT_OFFSET_LI0_EvIDByteG))
#define l_u8_wr_LI0_EvIDByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvIDByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteG) - 1) << LIN_BIT_OFFSET_LI0_EvIDByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvIDByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvIDByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvIDByteG] = 1;}
/* static access macros for signal LI0_EvGridCodeStatusMod */
   
#define l_bool_rd_LI0_EvGridCodeStatusMod() \
   	(LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatusMod], \
   	LIN_BIT_OFFSET_LI0_EvGridCodeStatusMod))
#define l_bool_wr_LI0_EvGridCodeStatusMod(A) \
	{(A) ? \
  	(LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatusMod], \
  	LIN_BIT_OFFSET_LI0_EvGridCodeStatusMod)):\
  	(LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatusMod], \
  	LIN_BIT_OFFSET_LI0_EvGridCodeStatusMod));\
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvGridCodeStatusMod] = 1;}
/* static access macros for signal LI0_EvPwrCtrlModeAck */
   
#define l_u8_rd_LI0_EvPwrCtrlModeAck() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModeAck] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvPwrCtrlModeAck) - 1) \
    << LIN_BIT_OFFSET_LI0_EvPwrCtrlModeAck )) >> LIN_BIT_OFFSET_LI0_EvPwrCtrlModeAck))
#define l_u8_wr_LI0_EvPwrCtrlModeAck(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModeAck] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModeAck] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvPwrCtrlModeAck) - 1) << LIN_BIT_OFFSET_LI0_EvPwrCtrlModeAck)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvPwrCtrlModeAck) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvPwrCtrlModeAck))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPwrCtrlModeAck] = 1;}
/* static access macros for signal LI0_EvInverterState */
   
#define l_u8_rd_LI0_EvInverterState() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInverterState] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvInverterState) - 1) \
    << LIN_BIT_OFFSET_LI0_EvInverterState )) >> LIN_BIT_OFFSET_LI0_EvInverterState))
#define l_u8_wr_LI0_EvInverterState(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInverterState] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvInverterState] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvInverterState) - 1) << LIN_BIT_OFFSET_LI0_EvInverterState)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvInverterState) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvInverterState))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvInverterState] = 1;}
/* static access macros for signal LI0_EvJ3072ByteA */
   
#define l_u8_rd_LI0_EvJ3072ByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteA) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteA )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteA))
#define l_u8_wr_LI0_EvJ3072ByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteA) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteA] = 1;}
/* static access macros for signal LI0_EvJ3072ByteB */
   
#define l_u8_rd_LI0_EvJ3072ByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteB) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteB )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteB))
#define l_u8_wr_LI0_EvJ3072ByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteB) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteB] = 1;}
/* static access macros for signal LI0_EvJ3072ByteC */
   
#define l_u8_rd_LI0_EvJ3072ByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteC) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteC )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteC))
#define l_u8_wr_LI0_EvJ3072ByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteC) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteC] = 1;}
/* static access macros for signal LI0_EvJ3072ByteD */
   
#define l_u8_rd_LI0_EvJ3072ByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteD) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteD )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteD))
#define l_u8_wr_LI0_EvJ3072ByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteD) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteD] = 1;}
/* static access macros for signal LI0_EvJ3072ByteE */
   
#define l_u8_rd_LI0_EvJ3072ByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteE) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteE )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteE))
#define l_u8_wr_LI0_EvJ3072ByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteE) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteE] = 1;}
/* static access macros for signal LI0_EvJ3072ByteF */
   
#define l_u8_rd_LI0_EvJ3072ByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteF) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteF )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteF))
#define l_u8_wr_LI0_EvJ3072ByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteF) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteF] = 1;}
/* static access macros for signal LI0_EvJ3072ByteG */
   
#define l_u8_rd_LI0_EvJ3072ByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteG) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072ByteG )) >> LIN_BIT_OFFSET_LI0_EvJ3072ByteG))
#define l_u8_wr_LI0_EvJ3072ByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072ByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteG) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072ByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072ByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072ByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072ByteG] = 1;}
/* static access macros for signal LI0_EvJ3072Page */
   
#define l_u8_rd_LI0_EvJ3072Page() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072Page] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072Page) - 1) \
    << LIN_BIT_OFFSET_LI0_EvJ3072Page )) >> LIN_BIT_OFFSET_LI0_EvJ3072Page))
#define l_u8_wr_LI0_EvJ3072Page(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072Page] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvJ3072Page] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072Page) - 1) << LIN_BIT_OFFSET_LI0_EvJ3072Page)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_EvJ3072Page) - 1) & (A)) << LIN_BIT_OFFSET_LI0_EvJ3072Page))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvJ3072Page] = 1;}
/* static access macros for signal LI0_SePwrCtrlMode */
   
#define l_u8_rd_LI0_SePwrCtrlMode() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlMode] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlMode) - 1) \
    << LIN_BIT_OFFSET_LI0_SePwrCtrlMode )) >> LIN_BIT_OFFSET_LI0_SePwrCtrlMode))
#define l_u8_wr_LI0_SePwrCtrlMode(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlMode] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlMode] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlMode) - 1) << LIN_BIT_OFFSET_LI0_SePwrCtrlMode)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlMode) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SePwrCtrlMode))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SePwrCtrlMode] = 1;}
/* static access macros for signal LI0_SePwrCtrlAuth */
   
#define l_u8_rd_LI0_SePwrCtrlAuth() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlAuth] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlAuth) - 1) \
    << LIN_BIT_OFFSET_LI0_SePwrCtrlAuth )) >> LIN_BIT_OFFSET_LI0_SePwrCtrlAuth))
#define l_u8_wr_LI0_SePwrCtrlAuth(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlAuth] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlAuth] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlAuth) - 1) << LIN_BIT_OFFSET_LI0_SePwrCtrlAuth)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlAuth) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SePwrCtrlAuth))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SePwrCtrlAuth] = 1;}
/* static access macros for signal LI0_SeInverterRequest */
   
#define l_u8_rd_LI0_SeInverterRequest() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInverterRequest] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeInverterRequest) - 1) \
    << LIN_BIT_OFFSET_LI0_SeInverterRequest )) >> LIN_BIT_OFFSET_LI0_SeInverterRequest))
#define l_u8_wr_LI0_SeInverterRequest(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInverterRequest] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeInverterRequest] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeInverterRequest) - 1) << LIN_BIT_OFFSET_LI0_SeInverterRequest)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeInverterRequest) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeInverterRequest))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeInverterRequest] = 1;}
/* static access macros for signal LI0_SeJ3072ByteA */
   
#define l_u8_rd_LI0_SeJ3072ByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteA) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteA )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteA))
#define l_u8_wr_LI0_SeJ3072ByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteA) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteA] = 1;}
/* static access macros for signal LI0_SeJ3072ByteB */
   
#define l_u8_rd_LI0_SeJ3072ByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteB) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteB )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteB))
#define l_u8_wr_LI0_SeJ3072ByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteB) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteB] = 1;}
/* static access macros for signal LI0_SeJ3072ByteC */
   
#define l_u8_rd_LI0_SeJ3072ByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteC) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteC )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteC))
#define l_u8_wr_LI0_SeJ3072ByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteC) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteC] = 1;}
/* static access macros for signal LI0_SeJ3072ByteD */
   
#define l_u8_rd_LI0_SeJ3072ByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteD) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteD )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteD))
#define l_u8_wr_LI0_SeJ3072ByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteD) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteD] = 1;}
/* static access macros for signal LI0_SeJ3072ByteE */
   
#define l_u8_rd_LI0_SeJ3072ByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteE) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteE )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteE))
#define l_u8_wr_LI0_SeJ3072ByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteE) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteE] = 1;}
/* static access macros for signal LI0_SeJ3072ByteF */
   
#define l_u8_rd_LI0_SeJ3072ByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteF) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteF )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteF))
#define l_u8_wr_LI0_SeJ3072ByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteF) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteF] = 1;}
/* static access macros for signal LI0_SeJ3072ByteG */
   
#define l_u8_rd_LI0_SeJ3072ByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteG) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072ByteG )) >> LIN_BIT_OFFSET_LI0_SeJ3072ByteG))
#define l_u8_wr_LI0_SeJ3072ByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072ByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteG) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072ByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072ByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072ByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072ByteG] = 1;}
/* static access macros for signal LI0_SeJ3072Page */
   
#define l_u8_rd_LI0_SeJ3072Page() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072Page] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072Page) - 1) \
    << LIN_BIT_OFFSET_LI0_SeJ3072Page )) >> LIN_BIT_OFFSET_LI0_SeJ3072Page))
#define l_u8_wr_LI0_SeJ3072Page(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072Page] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeJ3072Page] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072Page) - 1) << LIN_BIT_OFFSET_LI0_SeJ3072Page)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeJ3072Page) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeJ3072Page))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeJ3072Page] = 1;}
/* static access macros for signal LI0_SePwrCtrlUnits */
   
#define l_u8_rd_LI0_SePwrCtrlUnits() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlUnits] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlUnits) - 1) \
    << LIN_BIT_OFFSET_LI0_SePwrCtrlUnits )) >> LIN_BIT_OFFSET_LI0_SePwrCtrlUnits))
#define l_u8_wr_LI0_SePwrCtrlUnits(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlUnits] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SePwrCtrlUnits] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlUnits) - 1) << LIN_BIT_OFFSET_LI0_SePwrCtrlUnits)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SePwrCtrlUnits) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SePwrCtrlUnits))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SePwrCtrlUnits] = 1;}
/* static access macros for signal LI0_SeTimeStamp */
   
#define l_u8_rd_LI0_SeTimeStamp() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTimeStamp] & \
    (((1U << LIN_SIGNAL_SIZE_LI0_SeTimeStamp) - 1) \
    << LIN_BIT_OFFSET_LI0_SeTimeStamp )) >> LIN_BIT_OFFSET_LI0_SeTimeStamp))
#define l_u8_wr_LI0_SeTimeStamp(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTimeStamp] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTimeStamp] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI0_SeTimeStamp) - 1) << LIN_BIT_OFFSET_LI0_SeTimeStamp)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI0_SeTimeStamp) - 1) & (A)) << LIN_BIT_OFFSET_LI0_SeTimeStamp))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTimeStamp] = 1;}

/* static access macros for signal LI1_EvSelectedVersion */
  #define l_u8_rd_LI1_EvSelectedVersion_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList))
#define l_u8_rd_LI1_EvSelectedVersion_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus))
#define l_u8_rd_LI1_EvSelectedVersion_EvPresentCurrents() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvPresentCurrents) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents))
#define l_u8_rd_LI1_EvSelectedVersion_EvMaxVoltages() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxVoltages) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages))
#define l_u8_rd_LI1_EvSelectedVersion_EvMinVoltages() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMinVoltages) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages))
#define l_u8_rd_LI1_EvSelectedVersion_EvMaxMinCurrents() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxMinCurrents) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents))
#define l_u8_rd_LI1_EvSelectedVersion_EvInfoList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvInfoList) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList))
#define l_u8_rd_LI1_EvSelectedVersion_EvErrorList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvErrorList) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList )) >> LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList))

#define l_u8_wr_LI1_EvSelectedVersion(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvVersionList) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvStatus) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvPresentCurrents) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvPresentCurrents) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxVoltages) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxVoltages) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMinVoltages) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMinVoltages) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxMinCurrents) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvMaxMinCurrents) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvInfoList) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvInfoList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvErrorList) - 1) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSelectedVersion_EvErrorList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList] = 1;}\
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
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvResponseError_EvVersionList] = 1;}\
	{(A) ? \
  	(LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus], \
  	LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus)):\
  	(LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvResponseError_EvStatus], \
  	LIN_BIT_OFFSET_LI1_EvResponseError_EvStatus));\
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvResponseError_EvStatus] = 1;}\

/* static access macros for signal LI1_EvStatusVer */
  #define l_u8_rd_LI1_EvStatusVer_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_EvStatusVer_EvVersionList )) >> LIN_BIT_OFFSET_LI1_EvStatusVer_EvVersionList))
#define l_u8_rd_LI1_EvStatusVer_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_EvStatusVer_EvStatus )) >> LIN_BIT_OFFSET_LI1_EvStatusVer_EvStatus))

#define l_u8_wr_LI1_EvStatusVer(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvVersionList) - 1) << LIN_BIT_OFFSET_LI1_EvStatusVer_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvStatusVer_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusVer_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvStatus) - 1) << LIN_BIT_OFFSET_LI1_EvStatusVer_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvStatusVer_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvStatusVer_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusVer_EvStatus] = 1;}\
/* static access macros for signal LI1_EvStatusInit */
  #define l_u8_rd_LI1_EvStatusInit_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_EvStatusInit_EvVersionList )) >> LIN_BIT_OFFSET_LI1_EvStatusInit_EvVersionList))
#define l_u8_rd_LI1_EvStatusInit_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_EvStatusInit_EvStatus )) >> LIN_BIT_OFFSET_LI1_EvStatusInit_EvStatus))

#define l_u8_wr_LI1_EvStatusInit(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvVersionList) - 1) << LIN_BIT_OFFSET_LI1_EvStatusInit_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvStatusInit_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusInit_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvStatus) - 1) << LIN_BIT_OFFSET_LI1_EvStatusInit_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvStatusInit_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvStatusInit_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusInit_EvStatus] = 1;}\
/* static access macros for signal LI1_EvStatusOp */
  #define l_u8_rd_LI1_EvStatusOp_EvVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_EvStatusOp_EvVersionList )) >> LIN_BIT_OFFSET_LI1_EvStatusOp_EvVersionList))
#define l_u8_rd_LI1_EvStatusOp_EvStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_EvStatusOp_EvStatus )) >> LIN_BIT_OFFSET_LI1_EvStatusOp_EvStatus))

#define l_u8_wr_LI1_EvStatusOp(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvVersionList) - 1) << LIN_BIT_OFFSET_LI1_EvStatusOp_EvVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvStatusOp_EvVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvStatusOp_EvStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvStatus) - 1) << LIN_BIT_OFFSET_LI1_EvStatusOp_EvStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvStatusOp_EvStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvStatusOp_EvStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvStatusOp_EvStatus] = 1;}\
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
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvAwake_EvVersionList] = 1;}\
	{(A) ? \
  	(LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus], \
  	LIN_BIT_OFFSET_LI1_EvAwake_EvStatus)):\
  	(LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvAwake_EvStatus], \
  	LIN_BIT_OFFSET_LI1_EvAwake_EvStatus));\
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvAwake_EvStatus] = 1;}\

/* static access macros for signal LI1_EvVersionPageNumber */
   
#define l_u8_rd_LI1_EvVersionPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvVersionPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvVersionPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI1_EvVersionPageNumber )) >> LIN_BIT_OFFSET_LI1_EvVersionPageNumber))
#define l_u8_wr_LI1_EvVersionPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvVersionPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvVersionPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvVersionPageNumber) - 1) << LIN_BIT_OFFSET_LI1_EvVersionPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvVersionPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvVersionPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvVersionPageNumber] = 1;}
/* static access macros for signal LI1_EvSupportedVersion1 */
   
#define l_u8_rd_LI1_EvSupportedVersion1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSupportedVersion1 )) >> LIN_BIT_OFFSET_LI1_EvSupportedVersion1))
#define l_u8_wr_LI1_EvSupportedVersion1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion1) - 1) << LIN_BIT_OFFSET_LI1_EvSupportedVersion1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSupportedVersion1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion1] = 1;}
/* static access macros for signal LI1_EvSupportedVersion2 */
   
#define l_u8_rd_LI1_EvSupportedVersion2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSupportedVersion2 )) >> LIN_BIT_OFFSET_LI1_EvSupportedVersion2))
#define l_u8_wr_LI1_EvSupportedVersion2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion2) - 1) << LIN_BIT_OFFSET_LI1_EvSupportedVersion2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSupportedVersion2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion2] = 1;}
/* static access macros for signal LI1_EvSupportedVersion3 */
   
#define l_u8_rd_LI1_EvSupportedVersion3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSupportedVersion3 )) >> LIN_BIT_OFFSET_LI1_EvSupportedVersion3))
#define l_u8_wr_LI1_EvSupportedVersion3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion3) - 1) << LIN_BIT_OFFSET_LI1_EvSupportedVersion3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSupportedVersion3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion3] = 1;}
/* static access macros for signal LI1_EvSupportedVersion4 */
   
#define l_u8_rd_LI1_EvSupportedVersion4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion4] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion4) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSupportedVersion4 )) >> LIN_BIT_OFFSET_LI1_EvSupportedVersion4))
#define l_u8_wr_LI1_EvSupportedVersion4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion4) - 1) << LIN_BIT_OFFSET_LI1_EvSupportedVersion4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion4) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSupportedVersion4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion4] = 1;}
/* static access macros for signal LI1_EvSupportedVersion5 */
   
#define l_u8_rd_LI1_EvSupportedVersion5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion5] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion5) - 1) \
    << LIN_BIT_OFFSET_LI1_EvSupportedVersion5 )) >> LIN_BIT_OFFSET_LI1_EvSupportedVersion5))
#define l_u8_wr_LI1_EvSupportedVersion5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvSupportedVersion5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion5) - 1) << LIN_BIT_OFFSET_LI1_EvSupportedVersion5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvSupportedVersion5) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvSupportedVersion5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvSupportedVersion5] = 1;}
/* static access macros for signal LI1_EvRequestedCurrentL1 */
   
#define l_u8_rd_LI1_EvRequestedCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL1 )) >> LIN_BIT_OFFSET_LI1_EvRequestedCurrentL1))
#define l_u8_wr_LI1_EvRequestedCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL1) - 1) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentL1] = 1;}
/* static access macros for signal LI1_EvRequestedCurrentL2 */
   
#define l_u8_rd_LI1_EvRequestedCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL2 )) >> LIN_BIT_OFFSET_LI1_EvRequestedCurrentL2))
#define l_u8_wr_LI1_EvRequestedCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL2) - 1) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentL2] = 1;}
/* static access macros for signal LI1_EvRequestedCurrentL3 */
   
#define l_u8_rd_LI1_EvRequestedCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL3 )) >> LIN_BIT_OFFSET_LI1_EvRequestedCurrentL3))
#define l_u8_wr_LI1_EvRequestedCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL3) - 1) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentL3] = 1;}
/* static access macros for signal LI1_EvRequestedCurrentN */
   
#define l_u8_rd_LI1_EvRequestedCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI1_EvRequestedCurrentN )) >> LIN_BIT_OFFSET_LI1_EvRequestedCurrentN))
#define l_u8_wr_LI1_EvRequestedCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvRequestedCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentN) - 1) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvRequestedCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvRequestedCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvRequestedCurrentN] = 1;}
/* static access macros for signal LI1_SeSelectedVersion */
  #define l_u8_rd_LI1_SeSelectedVersion_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList )) >> LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList))
#define l_u8_rd_LI1_SeSelectedVersion_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus )) >> LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus))
#define l_u8_rd_LI1_SeSelectedVersion_SeNomVoltages() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeNomVoltages) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages )) >> LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages))
#define l_u8_rd_LI1_SeSelectedVersion_SeMaxCurrents() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeMaxCurrents) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents )) >> LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents))
#define l_u8_rd_LI1_SeSelectedVersion_SeInfoList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeInfoList) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList )) >> LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList))
#define l_u8_rd_LI1_SeSelectedVersion_StErrorList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_StErrorList) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList )) >> LIN_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList))

#define l_u8_wr_LI1_SeSelectedVersion(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeVersionList) - 1) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeStatus) - 1) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeNomVoltages) - 1) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeNomVoltages) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeMaxCurrents) - 1) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeMaxCurrents) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeInfoList) - 1) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_SeInfoList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_StErrorList) - 1) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSelectedVersion_StErrorList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList] = 1;}\
/* static access macros for signal LI1_SeStatusVer */
  #define l_u8_rd_LI1_SeStatusVer_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_SeStatusVer_SeVersionList )) >> LIN_BIT_OFFSET_LI1_SeStatusVer_SeVersionList))
#define l_u8_rd_LI1_SeStatusVer_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_SeStatusVer_SeStatus )) >> LIN_BIT_OFFSET_LI1_SeStatusVer_SeStatus))

#define l_u8_wr_LI1_SeStatusVer(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeVersionList) - 1) << LIN_BIT_OFFSET_LI1_SeStatusVer_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeStatusVer_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusVer_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeStatus) - 1) << LIN_BIT_OFFSET_LI1_SeStatusVer_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeStatusVer_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeStatusVer_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusVer_SeStatus] = 1;}\
/* static access macros for signal LI1_SeStatusInit */
  #define l_u8_rd_LI1_SeStatusInit_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_SeStatusInit_SeVersionList )) >> LIN_BIT_OFFSET_LI1_SeStatusInit_SeVersionList))
#define l_u8_rd_LI1_SeStatusInit_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_SeStatusInit_SeStatus )) >> LIN_BIT_OFFSET_LI1_SeStatusInit_SeStatus))

#define l_u8_wr_LI1_SeStatusInit(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeVersionList) - 1) << LIN_BIT_OFFSET_LI1_SeStatusInit_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeStatusInit_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusInit_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeStatus) - 1) << LIN_BIT_OFFSET_LI1_SeStatusInit_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeStatusInit_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeStatusInit_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusInit_SeStatus] = 1;}\
/* static access macros for signal LI1_SeStatusOp */
  #define l_u8_rd_LI1_SeStatusOp_SeVersionList() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeVersionList) - 1) \
    << LIN_BIT_OFFSET_LI1_SeStatusOp_SeVersionList )) >> LIN_BIT_OFFSET_LI1_SeStatusOp_SeVersionList))
#define l_u8_rd_LI1_SeStatusOp_SeStatus() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeStatus) - 1) \
    << LIN_BIT_OFFSET_LI1_SeStatusOp_SeStatus )) >> LIN_BIT_OFFSET_LI1_SeStatusOp_SeStatus))

#define l_u8_wr_LI1_SeStatusOp(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeVersionList) - 1) << LIN_BIT_OFFSET_LI1_SeStatusOp_SeVersionList)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeVersionList) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeStatusOp_SeVersionList))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList] = 1;}\
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeStatusOp_SeStatus] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeStatus) - 1) << LIN_BIT_OFFSET_LI1_SeStatusOp_SeStatus)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeStatusOp_SeStatus) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeStatusOp_SeStatus))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeStatusOp_SeStatus] = 1;}\
/* static access macros for signal LI1_SeVersionPageNumber */
   
#define l_u8_rd_LI1_SeVersionPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeVersionPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeVersionPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI1_SeVersionPageNumber )) >> LIN_BIT_OFFSET_LI1_SeVersionPageNumber))
#define l_u8_wr_LI1_SeVersionPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeVersionPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeVersionPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeVersionPageNumber) - 1) << LIN_BIT_OFFSET_LI1_SeVersionPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeVersionPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeVersionPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeVersionPageNumber] = 1;}
/* static access macros for signal LI1_SeSupportedVersion1 */
   
#define l_u8_rd_LI1_SeSupportedVersion1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion1) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSupportedVersion1 )) >> LIN_BIT_OFFSET_LI1_SeSupportedVersion1))
#define l_u8_wr_LI1_SeSupportedVersion1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion1) - 1) << LIN_BIT_OFFSET_LI1_SeSupportedVersion1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSupportedVersion1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion1] = 1;}
/* static access macros for signal LI1_SeSupportedVersion2 */
   
#define l_u8_rd_LI1_SeSupportedVersion2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion2) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSupportedVersion2 )) >> LIN_BIT_OFFSET_LI1_SeSupportedVersion2))
#define l_u8_wr_LI1_SeSupportedVersion2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion2) - 1) << LIN_BIT_OFFSET_LI1_SeSupportedVersion2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSupportedVersion2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion2] = 1;}
/* static access macros for signal LI1_SeSupportedVersion3 */
   
#define l_u8_rd_LI1_SeSupportedVersion3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion3) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSupportedVersion3 )) >> LIN_BIT_OFFSET_LI1_SeSupportedVersion3))
#define l_u8_wr_LI1_SeSupportedVersion3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion3) - 1) << LIN_BIT_OFFSET_LI1_SeSupportedVersion3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSupportedVersion3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion3] = 1;}
/* static access macros for signal LI1_SeSupportedVersion4 */
   
#define l_u8_rd_LI1_SeSupportedVersion4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion4] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion4) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSupportedVersion4 )) >> LIN_BIT_OFFSET_LI1_SeSupportedVersion4))
#define l_u8_wr_LI1_SeSupportedVersion4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion4) - 1) << LIN_BIT_OFFSET_LI1_SeSupportedVersion4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion4) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSupportedVersion4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion4] = 1;}
/* static access macros for signal LI1_SeSupportedVersion5 */
   
#define l_u8_rd_LI1_SeSupportedVersion5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion5] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion5) - 1) \
    << LIN_BIT_OFFSET_LI1_SeSupportedVersion5 )) >> LIN_BIT_OFFSET_LI1_SeSupportedVersion5))
#define l_u8_wr_LI1_SeSupportedVersion5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeSupportedVersion5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion5) - 1) << LIN_BIT_OFFSET_LI1_SeSupportedVersion5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeSupportedVersion5) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeSupportedVersion5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeSupportedVersion5] = 1;}
/* static access macros for signal LI1_SeAvailableCurrentL1 */
   
#define l_u8_rd_LI1_SeAvailableCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL1 )) >> LIN_BIT_OFFSET_LI1_SeAvailableCurrentL1))
#define l_u8_wr_LI1_SeAvailableCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL1) - 1) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentL1] = 1;}
/* static access macros for signal LI1_SeAvailableCurrentL2 */
   
#define l_u8_rd_LI1_SeAvailableCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL2 )) >> LIN_BIT_OFFSET_LI1_SeAvailableCurrentL2))
#define l_u8_wr_LI1_SeAvailableCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL2) - 1) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentL2] = 1;}
/* static access macros for signal LI1_SeAvailableCurrentL3 */
   
#define l_u8_rd_LI1_SeAvailableCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL3 )) >> LIN_BIT_OFFSET_LI1_SeAvailableCurrentL3))
#define l_u8_wr_LI1_SeAvailableCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL3) - 1) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentL3] = 1;}
/* static access macros for signal LI1_SeAvailableCurrentN */
   
#define l_u8_rd_LI1_SeAvailableCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI1_SeAvailableCurrentN )) >> LIN_BIT_OFFSET_LI1_SeAvailableCurrentN))
#define l_u8_wr_LI1_SeAvailableCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeAvailableCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentN) - 1) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeAvailableCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeAvailableCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeAvailableCurrentN] = 1;}
/* static access macros for signal LI1_EvPresentCurrentL1 */
   
#define l_u8_rd_LI1_EvPresentCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvPresentCurrentL1 )) >> LIN_BIT_OFFSET_LI1_EvPresentCurrentL1))
#define l_u8_wr_LI1_EvPresentCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL1) - 1) << LIN_BIT_OFFSET_LI1_EvPresentCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvPresentCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentL1] = 1;}
/* static access macros for signal LI1_EvPresentCurrentL2 */
   
#define l_u8_rd_LI1_EvPresentCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvPresentCurrentL2 )) >> LIN_BIT_OFFSET_LI1_EvPresentCurrentL2))
#define l_u8_wr_LI1_EvPresentCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL2) - 1) << LIN_BIT_OFFSET_LI1_EvPresentCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvPresentCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentL2] = 1;}
/* static access macros for signal LI1_EvPresentCurrentL3 */
   
#define l_u8_rd_LI1_EvPresentCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvPresentCurrentL3 )) >> LIN_BIT_OFFSET_LI1_EvPresentCurrentL3))
#define l_u8_wr_LI1_EvPresentCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL3) - 1) << LIN_BIT_OFFSET_LI1_EvPresentCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvPresentCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentL3] = 1;}
/* static access macros for signal LI1_EvPresentCurrentN */
   
#define l_u8_rd_LI1_EvPresentCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI1_EvPresentCurrentN )) >> LIN_BIT_OFFSET_LI1_EvPresentCurrentN))
#define l_u8_wr_LI1_EvPresentCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPresentCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentN) - 1) << LIN_BIT_OFFSET_LI1_EvPresentCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvPresentCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvPresentCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPresentCurrentN] = 1;}
/* static access macros for signal LI1_SeFrequency */
   
#define l_u8_rd_LI1_SeFrequency() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeFrequency] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeFrequency) - 1) \
    << LIN_BIT_OFFSET_LI1_SeFrequency )) >> LIN_BIT_OFFSET_LI1_SeFrequency))
#define l_u8_wr_LI1_SeFrequency(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeFrequency] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeFrequency] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeFrequency) - 1) << LIN_BIT_OFFSET_LI1_SeFrequency)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeFrequency) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeFrequency))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeFrequency] = 1;}
/* static access macros for signal LI1_SeMaxCurrentL1 */
   
#define l_u8_rd_LI1_SeMaxCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI1_SeMaxCurrentL1 )) >> LIN_BIT_OFFSET_LI1_SeMaxCurrentL1))
#define l_u8_wr_LI1_SeMaxCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL1) - 1) << LIN_BIT_OFFSET_LI1_SeMaxCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeMaxCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentL1] = 1;}
/* static access macros for signal LI1_SeMaxCurrentL2 */
   
#define l_u8_rd_LI1_SeMaxCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI1_SeMaxCurrentL2 )) >> LIN_BIT_OFFSET_LI1_SeMaxCurrentL2))
#define l_u8_wr_LI1_SeMaxCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL2) - 1) << LIN_BIT_OFFSET_LI1_SeMaxCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeMaxCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentL2] = 1;}
/* static access macros for signal LI1_SeMaxCurrentL3 */
   
#define l_u8_rd_LI1_SeMaxCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI1_SeMaxCurrentL3 )) >> LIN_BIT_OFFSET_LI1_SeMaxCurrentL3))
#define l_u8_wr_LI1_SeMaxCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL3) - 1) << LIN_BIT_OFFSET_LI1_SeMaxCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeMaxCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentL3] = 1;}
/* static access macros for signal LI1_SeMaxCurrentN */
   
#define l_u8_rd_LI1_SeMaxCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI1_SeMaxCurrentN )) >> LIN_BIT_OFFSET_LI1_SeMaxCurrentN))
#define l_u8_wr_LI1_SeMaxCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeMaxCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentN) - 1) << LIN_BIT_OFFSET_LI1_SeMaxCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeMaxCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeMaxCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeMaxCurrentN] = 1;}
/* static access macros for signal LI1_SeConnectionType */
   
#define l_u8_rd_LI1_SeConnectionType() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeConnectionType] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeConnectionType) - 1) \
    << LIN_BIT_OFFSET_LI1_SeConnectionType )) >> LIN_BIT_OFFSET_LI1_SeConnectionType))
#define l_u8_wr_LI1_SeConnectionType(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeConnectionType] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeConnectionType] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeConnectionType) - 1) << LIN_BIT_OFFSET_LI1_SeConnectionType)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeConnectionType) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeConnectionType))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeConnectionType] = 1;}
/* static access macros for signal LI1_EvFrequencies */
   
#define l_u8_rd_LI1_EvFrequencies() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvFrequencies] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvFrequencies) - 1) \
    << LIN_BIT_OFFSET_LI1_EvFrequencies )) >> LIN_BIT_OFFSET_LI1_EvFrequencies))
#define l_u8_wr_LI1_EvFrequencies(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvFrequencies] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvFrequencies] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvFrequencies) - 1) << LIN_BIT_OFFSET_LI1_EvFrequencies)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvFrequencies) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvFrequencies))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvFrequencies] = 1;}
/* static access macros for signal LI1_EvConnectionType */
   
#define l_u8_rd_LI1_EvConnectionType() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvConnectionType] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvConnectionType) - 1) \
    << LIN_BIT_OFFSET_LI1_EvConnectionType )) >> LIN_BIT_OFFSET_LI1_EvConnectionType))
#define l_u8_wr_LI1_EvConnectionType(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvConnectionType] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvConnectionType] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvConnectionType) - 1) << LIN_BIT_OFFSET_LI1_EvConnectionType)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvConnectionType) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvConnectionType))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvConnectionType] = 1;}
/* static access macros for signal LI1_EvMaxCurrentL1 */
   
#define l_u8_rd_LI1_EvMaxCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMaxCurrentL1 )) >> LIN_BIT_OFFSET_LI1_EvMaxCurrentL1))
#define l_u8_wr_LI1_EvMaxCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL1) - 1) << LIN_BIT_OFFSET_LI1_EvMaxCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMaxCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentL1] = 1;}
/* static access macros for signal LI1_EvMaxCurrentL2 */
   
#define l_u8_rd_LI1_EvMaxCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMaxCurrentL2 )) >> LIN_BIT_OFFSET_LI1_EvMaxCurrentL2))
#define l_u8_wr_LI1_EvMaxCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL2) - 1) << LIN_BIT_OFFSET_LI1_EvMaxCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMaxCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentL2] = 1;}
/* static access macros for signal LI1_EvMaxCurrentL3 */
   
#define l_u8_rd_LI1_EvMaxCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMaxCurrentL3 )) >> LIN_BIT_OFFSET_LI1_EvMaxCurrentL3))
#define l_u8_wr_LI1_EvMaxCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL3) - 1) << LIN_BIT_OFFSET_LI1_EvMaxCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMaxCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentL3] = 1;}
/* static access macros for signal LI1_EvMaxCurrentN */
   
#define l_u8_rd_LI1_EvMaxCurrentN() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentN] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentN) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMaxCurrentN )) >> LIN_BIT_OFFSET_LI1_EvMaxCurrentN))
#define l_u8_wr_LI1_EvMaxCurrentN(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentN] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxCurrentN] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentN) - 1) << LIN_BIT_OFFSET_LI1_EvMaxCurrentN)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMaxCurrentN) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMaxCurrentN))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxCurrentN] = 1;}
/* static access macros for signal LI1_EvMinCurrentL1 */
   
#define l_u8_rd_LI1_EvMinCurrentL1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMinCurrentL1 )) >> LIN_BIT_OFFSET_LI1_EvMinCurrentL1))
#define l_u8_wr_LI1_EvMinCurrentL1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL1) - 1) << LIN_BIT_OFFSET_LI1_EvMinCurrentL1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMinCurrentL1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinCurrentL1] = 1;}
/* static access macros for signal LI1_EvMinCurrentL2 */
   
#define l_u8_rd_LI1_EvMinCurrentL2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMinCurrentL2 )) >> LIN_BIT_OFFSET_LI1_EvMinCurrentL2))
#define l_u8_wr_LI1_EvMinCurrentL2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL2) - 1) << LIN_BIT_OFFSET_LI1_EvMinCurrentL2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMinCurrentL2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinCurrentL2] = 1;}
/* static access macros for signal LI1_EvMinCurrentL3 */
   
#define l_u8_rd_LI1_EvMinCurrentL3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvMinCurrentL3 )) >> LIN_BIT_OFFSET_LI1_EvMinCurrentL3))
#define l_u8_wr_LI1_EvMinCurrentL3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinCurrentL3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL3) - 1) << LIN_BIT_OFFSET_LI1_EvMinCurrentL3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvMinCurrentL3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvMinCurrentL3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinCurrentL3] = 1;}
/* static access macros for signal LI1_EvInfoEntry1 */
   
#define l_u8_rd_LI1_EvInfoEntry1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoEntry1 )) >> LIN_BIT_OFFSET_LI1_EvInfoEntry1))
#define l_u8_wr_LI1_EvInfoEntry1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry1) - 1) << LIN_BIT_OFFSET_LI1_EvInfoEntry1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoEntry1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry1] = 1;}
/* static access macros for signal LI1_EvInfoEntry2 */
   
#define l_u8_rd_LI1_EvInfoEntry2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoEntry2 )) >> LIN_BIT_OFFSET_LI1_EvInfoEntry2))
#define l_u8_wr_LI1_EvInfoEntry2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry2) - 1) << LIN_BIT_OFFSET_LI1_EvInfoEntry2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoEntry2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry2] = 1;}
/* static access macros for signal LI1_EvInfoEntry3 */
   
#define l_u8_rd_LI1_EvInfoEntry3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoEntry3 )) >> LIN_BIT_OFFSET_LI1_EvInfoEntry3))
#define l_u8_wr_LI1_EvInfoEntry3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry3) - 1) << LIN_BIT_OFFSET_LI1_EvInfoEntry3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoEntry3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry3] = 1;}
/* static access macros for signal LI1_EvInfoEntry4 */
   
#define l_u8_rd_LI1_EvInfoEntry4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry4] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry4) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoEntry4 )) >> LIN_BIT_OFFSET_LI1_EvInfoEntry4))
#define l_u8_wr_LI1_EvInfoEntry4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry4) - 1) << LIN_BIT_OFFSET_LI1_EvInfoEntry4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry4) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoEntry4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry4] = 1;}
/* static access macros for signal LI1_EvInfoEntry5 */
   
#define l_u8_rd_LI1_EvInfoEntry5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry5] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry5) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoEntry5 )) >> LIN_BIT_OFFSET_LI1_EvInfoEntry5))
#define l_u8_wr_LI1_EvInfoEntry5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry5) - 1) << LIN_BIT_OFFSET_LI1_EvInfoEntry5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry5) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoEntry5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry5] = 1;}
/* static access macros for signal LI1_EvInfoEntry6 */
   
#define l_u8_rd_LI1_EvInfoEntry6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry6] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry6) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoEntry6 )) >> LIN_BIT_OFFSET_LI1_EvInfoEntry6))
#define l_u8_wr_LI1_EvInfoEntry6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoEntry6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry6) - 1) << LIN_BIT_OFFSET_LI1_EvInfoEntry6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoEntry6) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoEntry6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoEntry6] = 1;}
/* static access macros for signal LI1_SeInfoEntry1 */
   
#define l_u8_rd_LI1_SeInfoEntry1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry1) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoEntry1 )) >> LIN_BIT_OFFSET_LI1_SeInfoEntry1))
#define l_u8_wr_LI1_SeInfoEntry1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry1) - 1) << LIN_BIT_OFFSET_LI1_SeInfoEntry1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoEntry1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry1] = 1;}
/* static access macros for signal LI1_SeInfoEntry2 */
   
#define l_u8_rd_LI1_SeInfoEntry2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry2) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoEntry2 )) >> LIN_BIT_OFFSET_LI1_SeInfoEntry2))
#define l_u8_wr_LI1_SeInfoEntry2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry2) - 1) << LIN_BIT_OFFSET_LI1_SeInfoEntry2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoEntry2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry2] = 1;}
/* static access macros for signal LI1_SeInfoEntry3 */
   
#define l_u8_rd_LI1_SeInfoEntry3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry3) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoEntry3 )) >> LIN_BIT_OFFSET_LI1_SeInfoEntry3))
#define l_u8_wr_LI1_SeInfoEntry3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry3) - 1) << LIN_BIT_OFFSET_LI1_SeInfoEntry3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoEntry3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry3] = 1;}
/* static access macros for signal LI1_SeInfoEntry4 */
   
#define l_u8_rd_LI1_SeInfoEntry4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry4] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry4) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoEntry4 )) >> LIN_BIT_OFFSET_LI1_SeInfoEntry4))
#define l_u8_wr_LI1_SeInfoEntry4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry4) - 1) << LIN_BIT_OFFSET_LI1_SeInfoEntry4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry4) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoEntry4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry4] = 1;}
/* static access macros for signal LI1_SeInfoEntry5 */
   
#define l_u8_rd_LI1_SeInfoEntry5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry5] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry5) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoEntry5 )) >> LIN_BIT_OFFSET_LI1_SeInfoEntry5))
#define l_u8_wr_LI1_SeInfoEntry5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry5) - 1) << LIN_BIT_OFFSET_LI1_SeInfoEntry5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry5) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoEntry5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry5] = 1;}
/* static access macros for signal LI1_SeInfoEntry6 */
   
#define l_u8_rd_LI1_SeInfoEntry6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry6] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry6) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoEntry6 )) >> LIN_BIT_OFFSET_LI1_SeInfoEntry6))
#define l_u8_wr_LI1_SeInfoEntry6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoEntry6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry6) - 1) << LIN_BIT_OFFSET_LI1_SeInfoEntry6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoEntry6) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoEntry6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoEntry6] = 1;}
/* static access macros for signal LI1_EvInfoPageNumber */
   
#define l_u8_rd_LI1_EvInfoPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInfoPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInfoPageNumber )) >> LIN_BIT_OFFSET_LI1_EvInfoPageNumber))
#define l_u8_wr_LI1_EvInfoPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInfoPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInfoPageNumber) - 1) << LIN_BIT_OFFSET_LI1_EvInfoPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInfoPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInfoPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInfoPageNumber] = 1;}
/* static access macros for signal LI1_SeInfoPageNumber */
   
#define l_u8_rd_LI1_SeInfoPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInfoPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInfoPageNumber )) >> LIN_BIT_OFFSET_LI1_SeInfoPageNumber))
#define l_u8_wr_LI1_SeInfoPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInfoPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInfoPageNumber) - 1) << LIN_BIT_OFFSET_LI1_SeInfoPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInfoPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInfoPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInfoPageNumber] = 1;}
/* static access macros for signal LI1_StErrorPageNumber */
   
#define l_u8_rd_LI1_StErrorPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorPageNumber )) >> LIN_BIT_OFFSET_LI1_StErrorPageNumber))
#define l_u8_wr_LI1_StErrorPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorPageNumber) - 1) << LIN_BIT_OFFSET_LI1_StErrorPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorPageNumber] = 1;}
/* static access macros for signal LI1_StErrorCode1 */
   
#define l_u8_rd_LI1_StErrorCode1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode1) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorCode1 )) >> LIN_BIT_OFFSET_LI1_StErrorCode1))
#define l_u8_wr_LI1_StErrorCode1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode1) - 1) << LIN_BIT_OFFSET_LI1_StErrorCode1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorCode1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode1] = 1;}
/* static access macros for signal LI1_StErrorCode2 */
   
#define l_u8_rd_LI1_StErrorCode2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode2) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorCode2 )) >> LIN_BIT_OFFSET_LI1_StErrorCode2))
#define l_u8_wr_LI1_StErrorCode2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode2) - 1) << LIN_BIT_OFFSET_LI1_StErrorCode2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorCode2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode2] = 1;}
/* static access macros for signal LI1_StErrorCode3 */
   
#define l_u8_rd_LI1_StErrorCode3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode3) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorCode3 )) >> LIN_BIT_OFFSET_LI1_StErrorCode3))
#define l_u8_wr_LI1_StErrorCode3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode3) - 1) << LIN_BIT_OFFSET_LI1_StErrorCode3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorCode3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode3] = 1;}
/* static access macros for signal LI1_StErrorCode4 */
   
#define l_u8_rd_LI1_StErrorCode4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode4] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode4) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorCode4 )) >> LIN_BIT_OFFSET_LI1_StErrorCode4))
#define l_u8_wr_LI1_StErrorCode4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode4) - 1) << LIN_BIT_OFFSET_LI1_StErrorCode4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode4) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorCode4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode4] = 1;}
/* static access macros for signal LI1_StErrorCode5 */
   
#define l_u8_rd_LI1_StErrorCode5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode5] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode5) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorCode5 )) >> LIN_BIT_OFFSET_LI1_StErrorCode5))
#define l_u8_wr_LI1_StErrorCode5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode5) - 1) << LIN_BIT_OFFSET_LI1_StErrorCode5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode5) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorCode5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode5] = 1;}
/* static access macros for signal LI1_StErrorCode6 */
   
#define l_u8_rd_LI1_StErrorCode6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode6] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode6) - 1) \
    << LIN_BIT_OFFSET_LI1_StErrorCode6 )) >> LIN_BIT_OFFSET_LI1_StErrorCode6))
#define l_u8_wr_LI1_StErrorCode6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_StErrorCode6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode6) - 1) << LIN_BIT_OFFSET_LI1_StErrorCode6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_StErrorCode6) - 1) & (A)) << LIN_BIT_OFFSET_LI1_StErrorCode6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_StErrorCode6] = 1;}
/* static access macros for signal LI1_EvErrorPageNumber */
   
#define l_u8_rd_LI1_EvErrorPageNumber() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorPageNumber] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorPageNumber) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorPageNumber )) >> LIN_BIT_OFFSET_LI1_EvErrorPageNumber))
#define l_u8_wr_LI1_EvErrorPageNumber(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorPageNumber] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorPageNumber] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorPageNumber) - 1) << LIN_BIT_OFFSET_LI1_EvErrorPageNumber)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorPageNumber) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorPageNumber))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorPageNumber] = 1;}
/* static access macros for signal LI1_EvErrorCode1 */
   
#define l_u8_rd_LI1_EvErrorCode1() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode1] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode1) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorCode1 )) >> LIN_BIT_OFFSET_LI1_EvErrorCode1))
#define l_u8_wr_LI1_EvErrorCode1(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode1] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode1] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode1) - 1) << LIN_BIT_OFFSET_LI1_EvErrorCode1)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode1) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorCode1))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode1] = 1;}
/* static access macros for signal LI1_EvErrorCode2 */
   
#define l_u8_rd_LI1_EvErrorCode2() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode2] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode2) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorCode2 )) >> LIN_BIT_OFFSET_LI1_EvErrorCode2))
#define l_u8_wr_LI1_EvErrorCode2(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode2] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode2] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode2) - 1) << LIN_BIT_OFFSET_LI1_EvErrorCode2)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode2) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorCode2))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode2] = 1;}
/* static access macros for signal LI1_EvErrorCode3 */
   
#define l_u8_rd_LI1_EvErrorCode3() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode3] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode3) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorCode3 )) >> LIN_BIT_OFFSET_LI1_EvErrorCode3))
#define l_u8_wr_LI1_EvErrorCode3(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode3] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode3] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode3) - 1) << LIN_BIT_OFFSET_LI1_EvErrorCode3)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode3) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorCode3))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode3] = 1;}
/* static access macros for signal LI1_EvErrorCode4 */
   
#define l_u8_rd_LI1_EvErrorCode4() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode4] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode4) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorCode4 )) >> LIN_BIT_OFFSET_LI1_EvErrorCode4))
#define l_u8_wr_LI1_EvErrorCode4(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode4] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode4] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode4) - 1) << LIN_BIT_OFFSET_LI1_EvErrorCode4)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode4) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorCode4))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode4] = 1;}
/* static access macros for signal LI1_EvErrorCode5 */
   
#define l_u8_rd_LI1_EvErrorCode5() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode5] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode5) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorCode5 )) >> LIN_BIT_OFFSET_LI1_EvErrorCode5))
#define l_u8_wr_LI1_EvErrorCode5(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode5] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode5] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode5) - 1) << LIN_BIT_OFFSET_LI1_EvErrorCode5)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode5) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorCode5))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode5] = 1;}
/* static access macros for signal LI1_EvErrorCode6 */
   
#define l_u8_rd_LI1_EvErrorCode6() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode6] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode6) - 1) \
    << LIN_BIT_OFFSET_LI1_EvErrorCode6 )) >> LIN_BIT_OFFSET_LI1_EvErrorCode6))
#define l_u8_wr_LI1_EvErrorCode6(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode6] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvErrorCode6] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode6) - 1) << LIN_BIT_OFFSET_LI1_EvErrorCode6)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvErrorCode6) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvErrorCode6))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvErrorCode6] = 1;}
/* static access macros for signal LI1_SeIDPage */
   
#define l_u8_rd_LI1_SeIDPage() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDPage] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDPage) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDPage )) >> LIN_BIT_OFFSET_LI1_SeIDPage))
#define l_u8_wr_LI1_SeIDPage(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDPage] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDPage] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDPage) - 1) << LIN_BIT_OFFSET_LI1_SeIDPage)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDPage) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDPage))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDPage] = 1;}
/* static access macros for signal LI1_SeIDByteA */
   
#define l_u8_rd_LI1_SeIDByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteA) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteA )) >> LIN_BIT_OFFSET_LI1_SeIDByteA))
#define l_u8_wr_LI1_SeIDByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteA) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteA] = 1;}
/* static access macros for signal LI1_SeIDByteB */
   
#define l_u8_rd_LI1_SeIDByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteB) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteB )) >> LIN_BIT_OFFSET_LI1_SeIDByteB))
#define l_u8_wr_LI1_SeIDByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteB) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteB] = 1;}
/* static access macros for signal LI1_SeIDByteC */
   
#define l_u8_rd_LI1_SeIDByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteC) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteC )) >> LIN_BIT_OFFSET_LI1_SeIDByteC))
#define l_u8_wr_LI1_SeIDByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteC) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteC] = 1;}
/* static access macros for signal LI1_SeIDByteD */
   
#define l_u8_rd_LI1_SeIDByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteD) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteD )) >> LIN_BIT_OFFSET_LI1_SeIDByteD))
#define l_u8_wr_LI1_SeIDByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteD) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteD] = 1;}
/* static access macros for signal LI1_SeIDByteE */
   
#define l_u8_rd_LI1_SeIDByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteE) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteE )) >> LIN_BIT_OFFSET_LI1_SeIDByteE))
#define l_u8_wr_LI1_SeIDByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteE) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteE] = 1;}
/* static access macros for signal LI1_SeIDByteF */
   
#define l_u8_rd_LI1_SeIDByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteF) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteF )) >> LIN_BIT_OFFSET_LI1_SeIDByteF))
#define l_u8_wr_LI1_SeIDByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteF) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteF] = 1;}
/* static access macros for signal LI1_SeIDByteG */
   
#define l_u8_rd_LI1_SeIDByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteG) - 1) \
    << LIN_BIT_OFFSET_LI1_SeIDByteG )) >> LIN_BIT_OFFSET_LI1_SeIDByteG))
#define l_u8_wr_LI1_SeIDByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeIDByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteG) - 1) << LIN_BIT_OFFSET_LI1_SeIDByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeIDByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeIDByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeIDByteG] = 1;}
/* static access macros for signal LI1_EvIDPage */
   
#define l_u8_rd_LI1_EvIDPage() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDPage] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDPage) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDPage )) >> LIN_BIT_OFFSET_LI1_EvIDPage))
#define l_u8_wr_LI1_EvIDPage(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDPage] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDPage] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDPage) - 1) << LIN_BIT_OFFSET_LI1_EvIDPage)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDPage) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDPage))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDPage] = 1;}
/* static access macros for signal LI1_EvIDByteA */
   
#define l_u8_rd_LI1_EvIDByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteA) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteA )) >> LIN_BIT_OFFSET_LI1_EvIDByteA))
#define l_u8_wr_LI1_EvIDByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteA) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteA] = 1;}
/* static access macros for signal LI1_EvIDByteB */
   
#define l_u8_rd_LI1_EvIDByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteB) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteB )) >> LIN_BIT_OFFSET_LI1_EvIDByteB))
#define l_u8_wr_LI1_EvIDByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteB) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteB] = 1;}
/* static access macros for signal LI1_EvIDByteC */
   
#define l_u8_rd_LI1_EvIDByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteC) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteC )) >> LIN_BIT_OFFSET_LI1_EvIDByteC))
#define l_u8_wr_LI1_EvIDByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteC) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteC] = 1;}
/* static access macros for signal LI1_EvIDByteD */
   
#define l_u8_rd_LI1_EvIDByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteD) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteD )) >> LIN_BIT_OFFSET_LI1_EvIDByteD))
#define l_u8_wr_LI1_EvIDByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteD) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteD] = 1;}
/* static access macros for signal LI1_EvIDByteE */
   
#define l_u8_rd_LI1_EvIDByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteE) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteE )) >> LIN_BIT_OFFSET_LI1_EvIDByteE))
#define l_u8_wr_LI1_EvIDByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteE) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteE] = 1;}
/* static access macros for signal LI1_EvIDByteF */
   
#define l_u8_rd_LI1_EvIDByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteF) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteF )) >> LIN_BIT_OFFSET_LI1_EvIDByteF))
#define l_u8_wr_LI1_EvIDByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteF) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteF] = 1;}
/* static access macros for signal LI1_EvIDByteG */
   
#define l_u8_rd_LI1_EvIDByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteG) - 1) \
    << LIN_BIT_OFFSET_LI1_EvIDByteG )) >> LIN_BIT_OFFSET_LI1_EvIDByteG))
#define l_u8_wr_LI1_EvIDByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvIDByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteG) - 1) << LIN_BIT_OFFSET_LI1_EvIDByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvIDByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvIDByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvIDByteG] = 1;}
/* static access macros for signal LI1_EvGridCodeStatusMod */
   
#define l_bool_rd_LI1_EvGridCodeStatusMod() \
   	(LIN_TEST_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatusMod], \
   	LIN_BIT_OFFSET_LI1_EvGridCodeStatusMod))
#define l_bool_wr_LI1_EvGridCodeStatusMod(A) \
	{(A) ? \
  	(LIN_SET_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatusMod], \
  	LIN_BIT_OFFSET_LI1_EvGridCodeStatusMod)):\
  	(LIN_CLEAR_BIT(lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatusMod], \
  	LIN_BIT_OFFSET_LI1_EvGridCodeStatusMod));\
  	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvGridCodeStatusMod] = 1;}
/* static access macros for signal LI1_EvPwrCtrlModeAck */
   
#define l_u8_rd_LI1_EvPwrCtrlModeAck() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModeAck] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvPwrCtrlModeAck) - 1) \
    << LIN_BIT_OFFSET_LI1_EvPwrCtrlModeAck )) >> LIN_BIT_OFFSET_LI1_EvPwrCtrlModeAck))
#define l_u8_wr_LI1_EvPwrCtrlModeAck(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModeAck] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModeAck] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvPwrCtrlModeAck) - 1) << LIN_BIT_OFFSET_LI1_EvPwrCtrlModeAck)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvPwrCtrlModeAck) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvPwrCtrlModeAck))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPwrCtrlModeAck] = 1;}
/* static access macros for signal LI1_EvInverterState */
   
#define l_u8_rd_LI1_EvInverterState() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInverterState] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvInverterState) - 1) \
    << LIN_BIT_OFFSET_LI1_EvInverterState )) >> LIN_BIT_OFFSET_LI1_EvInverterState))
#define l_u8_wr_LI1_EvInverterState(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInverterState] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvInverterState] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvInverterState) - 1) << LIN_BIT_OFFSET_LI1_EvInverterState)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvInverterState) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvInverterState))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvInverterState] = 1;}
/* static access macros for signal LI1_EvJ3072ByteA */
   
#define l_u8_rd_LI1_EvJ3072ByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteA) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteA )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteA))
#define l_u8_wr_LI1_EvJ3072ByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteA) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteA] = 1;}
/* static access macros for signal LI1_EvJ3072ByteB */
   
#define l_u8_rd_LI1_EvJ3072ByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteB) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteB )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteB))
#define l_u8_wr_LI1_EvJ3072ByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteB) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteB] = 1;}
/* static access macros for signal LI1_EvJ3072ByteC */
   
#define l_u8_rd_LI1_EvJ3072ByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteC) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteC )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteC))
#define l_u8_wr_LI1_EvJ3072ByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteC) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteC] = 1;}
/* static access macros for signal LI1_EvJ3072ByteD */
   
#define l_u8_rd_LI1_EvJ3072ByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteD) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteD )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteD))
#define l_u8_wr_LI1_EvJ3072ByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteD) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteD] = 1;}
/* static access macros for signal LI1_EvJ3072ByteE */
   
#define l_u8_rd_LI1_EvJ3072ByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteE) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteE )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteE))
#define l_u8_wr_LI1_EvJ3072ByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteE) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteE] = 1;}
/* static access macros for signal LI1_EvJ3072ByteF */
   
#define l_u8_rd_LI1_EvJ3072ByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteF) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteF )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteF))
#define l_u8_wr_LI1_EvJ3072ByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteF) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteF] = 1;}
/* static access macros for signal LI1_EvJ3072ByteG */
   
#define l_u8_rd_LI1_EvJ3072ByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteG) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072ByteG )) >> LIN_BIT_OFFSET_LI1_EvJ3072ByteG))
#define l_u8_wr_LI1_EvJ3072ByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072ByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteG) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072ByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072ByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072ByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072ByteG] = 1;}
/* static access macros for signal LI1_EvJ3072Page */
   
#define l_u8_rd_LI1_EvJ3072Page() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072Page] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072Page) - 1) \
    << LIN_BIT_OFFSET_LI1_EvJ3072Page )) >> LIN_BIT_OFFSET_LI1_EvJ3072Page))
#define l_u8_wr_LI1_EvJ3072Page(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072Page] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvJ3072Page] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072Page) - 1) << LIN_BIT_OFFSET_LI1_EvJ3072Page)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_EvJ3072Page) - 1) & (A)) << LIN_BIT_OFFSET_LI1_EvJ3072Page))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvJ3072Page] = 1;}
/* static access macros for signal LI1_SePwrCtrlMode */
   
#define l_u8_rd_LI1_SePwrCtrlMode() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlMode] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlMode) - 1) \
    << LIN_BIT_OFFSET_LI1_SePwrCtrlMode )) >> LIN_BIT_OFFSET_LI1_SePwrCtrlMode))
#define l_u8_wr_LI1_SePwrCtrlMode(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlMode] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlMode] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlMode) - 1) << LIN_BIT_OFFSET_LI1_SePwrCtrlMode)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlMode) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SePwrCtrlMode))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SePwrCtrlMode] = 1;}
/* static access macros for signal LI1_SePwrCtrlAuth */
   
#define l_u8_rd_LI1_SePwrCtrlAuth() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlAuth] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlAuth) - 1) \
    << LIN_BIT_OFFSET_LI1_SePwrCtrlAuth )) >> LIN_BIT_OFFSET_LI1_SePwrCtrlAuth))
#define l_u8_wr_LI1_SePwrCtrlAuth(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlAuth] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlAuth] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlAuth) - 1) << LIN_BIT_OFFSET_LI1_SePwrCtrlAuth)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlAuth) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SePwrCtrlAuth))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SePwrCtrlAuth] = 1;}
/* static access macros for signal LI1_SeInverterRequest */
   
#define l_u8_rd_LI1_SeInverterRequest() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInverterRequest] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeInverterRequest) - 1) \
    << LIN_BIT_OFFSET_LI1_SeInverterRequest )) >> LIN_BIT_OFFSET_LI1_SeInverterRequest))
#define l_u8_wr_LI1_SeInverterRequest(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInverterRequest] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeInverterRequest] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeInverterRequest) - 1) << LIN_BIT_OFFSET_LI1_SeInverterRequest)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeInverterRequest) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeInverterRequest))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeInverterRequest] = 1;}
/* static access macros for signal LI1_SeJ3072ByteA */
   
#define l_u8_rd_LI1_SeJ3072ByteA() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteA] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteA) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteA )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteA))
#define l_u8_wr_LI1_SeJ3072ByteA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteA] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteA] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteA) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteA)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteA) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteA))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteA] = 1;}
/* static access macros for signal LI1_SeJ3072ByteB */
   
#define l_u8_rd_LI1_SeJ3072ByteB() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteB] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteB) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteB )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteB))
#define l_u8_wr_LI1_SeJ3072ByteB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteB] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteB] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteB) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteB)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteB) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteB))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteB] = 1;}
/* static access macros for signal LI1_SeJ3072ByteC */
   
#define l_u8_rd_LI1_SeJ3072ByteC() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteC] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteC) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteC )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteC))
#define l_u8_wr_LI1_SeJ3072ByteC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteC] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteC] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteC) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteC)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteC) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteC))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteC] = 1;}
/* static access macros for signal LI1_SeJ3072ByteD */
   
#define l_u8_rd_LI1_SeJ3072ByteD() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteD] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteD) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteD )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteD))
#define l_u8_wr_LI1_SeJ3072ByteD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteD] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteD] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteD) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteD)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteD) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteD))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteD] = 1;}
/* static access macros for signal LI1_SeJ3072ByteE */
   
#define l_u8_rd_LI1_SeJ3072ByteE() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteE] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteE) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteE )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteE))
#define l_u8_wr_LI1_SeJ3072ByteE(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteE] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteE] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteE) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteE)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteE) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteE))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteE] = 1;}
/* static access macros for signal LI1_SeJ3072ByteF */
   
#define l_u8_rd_LI1_SeJ3072ByteF() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteF] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteF) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteF )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteF))
#define l_u8_wr_LI1_SeJ3072ByteF(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteF] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteF] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteF) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteF)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteF) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteF))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteF] = 1;}
/* static access macros for signal LI1_SeJ3072ByteG */
   
#define l_u8_rd_LI1_SeJ3072ByteG() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteG] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteG) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072ByteG )) >> LIN_BIT_OFFSET_LI1_SeJ3072ByteG))
#define l_u8_wr_LI1_SeJ3072ByteG(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteG] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072ByteG] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteG) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072ByteG)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072ByteG) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072ByteG))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072ByteG] = 1;}
/* static access macros for signal LI1_SeJ3072Page */
   
#define l_u8_rd_LI1_SeJ3072Page() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072Page] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072Page) - 1) \
    << LIN_BIT_OFFSET_LI1_SeJ3072Page )) >> LIN_BIT_OFFSET_LI1_SeJ3072Page))
#define l_u8_wr_LI1_SeJ3072Page(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072Page] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeJ3072Page] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072Page) - 1) << LIN_BIT_OFFSET_LI1_SeJ3072Page)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeJ3072Page) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeJ3072Page))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeJ3072Page] = 1;}
/* static access macros for signal LI1_SePwrCtrlUnits */
   
#define l_u8_rd_LI1_SePwrCtrlUnits() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlUnits] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlUnits) - 1) \
    << LIN_BIT_OFFSET_LI1_SePwrCtrlUnits )) >> LIN_BIT_OFFSET_LI1_SePwrCtrlUnits))
#define l_u8_wr_LI1_SePwrCtrlUnits(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlUnits] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SePwrCtrlUnits] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlUnits) - 1) << LIN_BIT_OFFSET_LI1_SePwrCtrlUnits)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SePwrCtrlUnits) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SePwrCtrlUnits))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SePwrCtrlUnits] = 1;}
/* static access macros for signal LI1_SeTimeStamp */
   
#define l_u8_rd_LI1_SeTimeStamp() \
    ((l_u8) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTimeStamp] & \
    (((1U << LIN_SIGNAL_SIZE_LI1_SeTimeStamp) - 1) \
    << LIN_BIT_OFFSET_LI1_SeTimeStamp )) >> LIN_BIT_OFFSET_LI1_SeTimeStamp))
#define l_u8_wr_LI1_SeTimeStamp(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTimeStamp] = \
    ((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTimeStamp] & \
    ((l_u8) (~(((1U << LIN_SIGNAL_SIZE_LI1_SeTimeStamp) - 1) << LIN_BIT_OFFSET_LI1_SeTimeStamp)))))  | \
    ((l_u8) ((((1U << LIN_SIGNAL_SIZE_LI1_SeTimeStamp) - 1) & (A)) << LIN_BIT_OFFSET_LI1_SeTimeStamp))));\
    lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTimeStamp] = 1;}


/* static access macros for signal LI0_SeNomVoltageL1N */
#define l_u16_rd_LI0_SeNomVoltageL1N() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N]) >> 0x00))
#define l_u16_wr_LI0_SeNomVoltageL1N(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageL1N] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeNomVoltageL1N))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeNomVoltageL1N] = 1;}

/* static access macros for signal LI0_SeNomVoltageLL */
#define l_u16_rd_LI0_SeNomVoltageLL() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL]) >> 0x00))
#define l_u16_wr_LI0_SeNomVoltageLL(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeNomVoltageLL] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeNomVoltageLL))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeNomVoltageLL] = 1;}

/* static access macros for signal LI0_EvMaxVoltageL1N */
#define l_u16_rd_LI0_EvMaxVoltageL1N() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N]) >> 0x00))
#define l_u16_wr_LI0_EvMaxVoltageL1N(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageL1N] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvMaxVoltageL1N))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxVoltageL1N] = 1;}

/* static access macros for signal LI0_EvMaxVoltageLL */
#define l_u16_rd_LI0_EvMaxVoltageLL() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL]) >> 0x00))
#define l_u16_wr_LI0_EvMaxVoltageLL(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMaxVoltageLL] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvMaxVoltageLL))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMaxVoltageLL] = 1;}

/* static access macros for signal LI0_EvMinVoltageL1N */
#define l_u16_rd_LI0_EvMinVoltageL1N() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N]) >> 0x00))
#define l_u16_wr_LI0_EvMinVoltageL1N(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageL1N] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvMinVoltageL1N))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinVoltageL1N] = 1;}

/* static access macros for signal LI0_EvMinVoltageLL */
#define l_u16_rd_LI0_EvMinVoltageLL() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL]) >> 0x00))
#define l_u16_wr_LI0_EvMinVoltageLL(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvMinVoltageLL] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvMinVoltageLL))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvMinVoltageLL] = 1;}

/* static access macros for signal LI0_EvGridCodeStatus */
#define l_u16_rd_LI0_EvGridCodeStatus() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatus + 1] & 0xff) << 7) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatus]) >> 0x01))
#define l_u16_wr_LI0_EvGridCodeStatus(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatus + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatus + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 7)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatus] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvGridCodeStatus] & (0x01))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvGridCodeStatus))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvGridCodeStatus] = 1;}

/* static access macros for signal LI0_EvPwrCtrlUnitsAvail */
#define l_u16_rd_LI0_EvPwrCtrlUnitsAvail() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail]) >> 0x00))
#define l_u16_wr_LI0_EvPwrCtrlUnitsAvail(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvPwrCtrlUnitsAvail))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail] = 1;}

/* static access macros for signal LI0_EvPwrCtrlModesAvail */
#define l_u16_rd_LI0_EvPwrCtrlModesAvail() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail]) >> 0x00))
#define l_u16_wr_LI0_EvPwrCtrlModesAvail(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_EvPwrCtrlModesAvail))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail] = 1;}

/* static access macros for signal LI0_SeGridCodeRequest */
#define l_u16_rd_LI0_SeGridCodeRequest() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeGridCodeRequest + 1] & 0xff) << 7) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeGridCodeRequest]) >> 0x01))
#define l_u16_wr_LI0_SeGridCodeRequest(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeGridCodeRequest + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeGridCodeRequest + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 7)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeGridCodeRequest] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeGridCodeRequest] & (0x01))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeGridCodeRequest))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeGridCodeRequest] = 1;}

/* static access macros for signal LI0_SeTargets1ElementA */
#define l_u16_rd_LI0_SeTargets1ElementA() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementA + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementA]) >> 0x00))
#define l_u16_wr_LI0_SeTargets1ElementA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementA + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementA + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementA] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementA] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeTargets1ElementA))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementA] = 1;}

/* static access macros for signal LI0_SeTargets1ElementB */
#define l_u16_rd_LI0_SeTargets1ElementB() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementB + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementB]) >> 0x00))
#define l_u16_wr_LI0_SeTargets1ElementB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementB + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementB + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementB] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementB] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeTargets1ElementB))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementB] = 1;}

/* static access macros for signal LI0_SeTargets1ElementC */
#define l_u16_rd_LI0_SeTargets1ElementC() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementC + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementC]) >> 0x00))
#define l_u16_wr_LI0_SeTargets1ElementC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementC + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementC + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementC] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementC] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeTargets1ElementC))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementC] = 1;}

/* static access macros for signal LI0_SeTargets1ElementD */
#define l_u16_rd_LI0_SeTargets1ElementD() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementD + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementD]) >> 0x00))
#define l_u16_wr_LI0_SeTargets1ElementD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementD + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementD + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementD] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI0_SeTargets1ElementD] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI0_SeTargets1ElementD))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI0_SeTargets1ElementD] = 1;}

/* static access macros for signal LI1_SeNomVoltageL1N */
#define l_u16_rd_LI1_SeNomVoltageL1N() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N]) >> 0x00))
#define l_u16_wr_LI1_SeNomVoltageL1N(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageL1N] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeNomVoltageL1N))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeNomVoltageL1N] = 1;}

/* static access macros for signal LI1_SeNomVoltageLL */
#define l_u16_rd_LI1_SeNomVoltageLL() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL]) >> 0x00))
#define l_u16_wr_LI1_SeNomVoltageLL(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeNomVoltageLL] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeNomVoltageLL))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeNomVoltageLL] = 1;}

/* static access macros for signal LI1_EvMaxVoltageL1N */
#define l_u16_rd_LI1_EvMaxVoltageL1N() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N]) >> 0x00))
#define l_u16_wr_LI1_EvMaxVoltageL1N(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageL1N] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvMaxVoltageL1N))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxVoltageL1N] = 1;}

/* static access macros for signal LI1_EvMaxVoltageLL */
#define l_u16_rd_LI1_EvMaxVoltageLL() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL]) >> 0x00))
#define l_u16_wr_LI1_EvMaxVoltageLL(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMaxVoltageLL] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvMaxVoltageLL))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMaxVoltageLL] = 1;}

/* static access macros for signal LI1_EvMinVoltageL1N */
#define l_u16_rd_LI1_EvMinVoltageL1N() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N]) >> 0x00))
#define l_u16_wr_LI1_EvMinVoltageL1N(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageL1N] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvMinVoltageL1N))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinVoltageL1N] = 1;}

/* static access macros for signal LI1_EvMinVoltageLL */
#define l_u16_rd_LI1_EvMinVoltageLL() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL]) >> 0x00))
#define l_u16_wr_LI1_EvMinVoltageLL(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvMinVoltageLL] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvMinVoltageLL))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvMinVoltageLL] = 1;}

/* static access macros for signal LI1_EvGridCodeStatus */
#define l_u16_rd_LI1_EvGridCodeStatus() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatus + 1] & 0xff) << 7) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatus]) >> 0x01))
#define l_u16_wr_LI1_EvGridCodeStatus(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatus + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatus + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 7)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatus] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvGridCodeStatus] & (0x01))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvGridCodeStatus))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvGridCodeStatus] = 1;}

/* static access macros for signal LI1_EvPwrCtrlUnitsAvail */
#define l_u16_rd_LI1_EvPwrCtrlUnitsAvail() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail]) >> 0x00))
#define l_u16_wr_LI1_EvPwrCtrlUnitsAvail(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvPwrCtrlUnitsAvail))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail] = 1;}

/* static access macros for signal LI1_EvPwrCtrlModesAvail */
#define l_u16_rd_LI1_EvPwrCtrlModesAvail() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail]) >> 0x00))
#define l_u16_wr_LI1_EvPwrCtrlModesAvail(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_EvPwrCtrlModesAvail))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail] = 1;}

/* static access macros for signal LI1_SeGridCodeRequest */
#define l_u16_rd_LI1_SeGridCodeRequest() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeGridCodeRequest + 1] & 0xff) << 7) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeGridCodeRequest]) >> 0x01))
#define l_u16_wr_LI1_SeGridCodeRequest(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeGridCodeRequest + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeGridCodeRequest + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 7)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeGridCodeRequest] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeGridCodeRequest] & (0x01))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeGridCodeRequest))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeGridCodeRequest] = 1;}

/* static access macros for signal LI1_SeTargets1ElementA */
#define l_u16_rd_LI1_SeTargets1ElementA() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementA + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementA]) >> 0x00))
#define l_u16_wr_LI1_SeTargets1ElementA(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementA + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementA + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementA] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementA] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeTargets1ElementA))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementA] = 1;}

/* static access macros for signal LI1_SeTargets1ElementB */
#define l_u16_rd_LI1_SeTargets1ElementB() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementB + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementB]) >> 0x00))
#define l_u16_wr_LI1_SeTargets1ElementB(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementB + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementB + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementB] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementB] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeTargets1ElementB))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementB] = 1;}

/* static access macros for signal LI1_SeTargets1ElementC */
#define l_u16_rd_LI1_SeTargets1ElementC() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementC + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementC]) >> 0x00))
#define l_u16_wr_LI1_SeTargets1ElementC(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementC + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementC + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementC] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementC] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeTargets1ElementC))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementC] = 1;}

/* static access macros for signal LI1_SeTargets1ElementD */
#define l_u16_rd_LI1_SeTargets1ElementD() \
    ((l_u16) ((lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementD + 1] & 0xff) << 8) + ((l_u16) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementD]) >> 0x00))
#define l_u16_wr_LI1_SeTargets1ElementD(A) \
    {lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementD + 1] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementD + 1] &  (0x00))) | \
	((l_u8) ((l_u8) ((A) >> 8)) & 0xff))); \
	lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementD] = \
	((l_u8) (((l_u8) (lin_pFrameBuf[LIN_BYTE_OFFSET_LI1_SeTargets1ElementD] & (0x00))) | \
	((l_u8) (A) << LIN_BIT_OFFSET_LI1_SeTargets1ElementD))); \
	lin_frame_flag_tbl[LIN_FLAG_UPDATE_BYTE_OFFSET_LI1_SeTargets1ElementD] = 1;}



/* Signal flag APIs */
 #define l_flg_tst_LI0_EvSelectedVersion_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList)
#define l_flg_tst_LI0_EvSelectedVersion_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus)
#define l_flg_tst_LI0_EvSelectedVersion_EvPresentCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents)
#define l_flg_tst_LI0_EvSelectedVersion_EvMaxVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages)
#define l_flg_tst_LI0_EvSelectedVersion_EvMinVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages)
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
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvStatus)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvPresentCurrents)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxVoltages)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMinVoltages)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvMaxMinCurrents)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvInfoList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvSelectedVersion_EvErrorList)}\
 #define l_flg_tst_LI0_EvResponseError_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList)
#define l_flg_tst_LI0_EvResponseError_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus)

#define l_flg_clr_LI0_EvResponseError_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvResponseError_EvStatus)}\
 #define l_flg_tst_LI0_EvStatusVer_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList)
#define l_flg_tst_LI0_EvStatusVer_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus)

#define l_flg_clr_LI0_EvStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusVer_EvStatus)}\
 #define l_flg_tst_LI0_EvStatusInit_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList)
#define l_flg_tst_LI0_EvStatusInit_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus)

#define l_flg_clr_LI0_EvStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusInit_EvStatus)}\
 #define l_flg_tst_LI0_EvStatusOp_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList)
#define l_flg_tst_LI0_EvStatusOp_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus)

#define l_flg_clr_LI0_EvStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatusOp_EvStatus)}\
 #define l_flg_tst_LI0_EvAwake_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList)
#define l_flg_tst_LI0_EvAwake_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus)

#define l_flg_clr_LI0_EvAwake_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvAwake_EvStatus)}\
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
#define l_flg_tst_LI0_SeSelectedVersion_SeMaxCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents)
#define l_flg_tst_LI0_SeSelectedVersion_SeInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList)
#define l_flg_tst_LI0_SeSelectedVersion_StErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList)

#define l_flg_clr_LI0_SeSelectedVersion_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeStatus)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeNomVoltages)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeMaxCurrents)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_SeInfoList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeSelectedVersion_StErrorList)}\
 #define l_flg_tst_LI0_SeStatusVer_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList)
#define l_flg_tst_LI0_SeStatusVer_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus)

#define l_flg_clr_LI0_SeStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusVer_SeStatus)}\
 #define l_flg_tst_LI0_SeStatusInit_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList)
#define l_flg_tst_LI0_SeStatusInit_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus)

#define l_flg_clr_LI0_SeStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusInit_SeStatus)}\
 #define l_flg_tst_LI0_SeStatusOp_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList)
#define l_flg_tst_LI0_SeStatusOp_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus)

#define l_flg_clr_LI0_SeStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatusOp_SeStatus)}\
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
#define l_flg_tst_LI0_SeConnectionType_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI0_SeConnectionType)
#define l_flg_clr_LI0_SeConnectionType_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI0_SeConnectionType)
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
#define l_flg_tst_LI0_EvConnectionType_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI0_EvConnectionType)
#define l_flg_clr_LI0_EvConnectionType_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI0_EvConnectionType)
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
#define l_flg_tst_LI0_SeIDPage_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDPage],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDPage)
#define l_flg_clr_LI0_SeIDPage_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDPage],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDPage)
#define l_flg_tst_LI0_SeIDByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteA)
#define l_flg_clr_LI0_SeIDByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteA)
#define l_flg_tst_LI0_SeIDByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteB)
#define l_flg_clr_LI0_SeIDByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteB)
#define l_flg_tst_LI0_SeIDByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteC)
#define l_flg_clr_LI0_SeIDByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteC)
#define l_flg_tst_LI0_SeIDByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteD)
#define l_flg_clr_LI0_SeIDByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteD)
#define l_flg_tst_LI0_SeIDByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteE)
#define l_flg_clr_LI0_SeIDByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteE)
#define l_flg_tst_LI0_SeIDByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteF)
#define l_flg_clr_LI0_SeIDByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteF)
#define l_flg_tst_LI0_SeIDByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteG)
#define l_flg_clr_LI0_SeIDByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_SeIDByteG)
#define l_flg_tst_LI0_EvIDPage_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDPage],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDPage)
#define l_flg_clr_LI0_EvIDPage_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDPage],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDPage)
#define l_flg_tst_LI0_EvIDByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteA)
#define l_flg_clr_LI0_EvIDByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteA)
#define l_flg_tst_LI0_EvIDByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteB)
#define l_flg_clr_LI0_EvIDByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteB)
#define l_flg_tst_LI0_EvIDByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteC)
#define l_flg_clr_LI0_EvIDByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteC)
#define l_flg_tst_LI0_EvIDByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteD)
#define l_flg_clr_LI0_EvIDByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteD)
#define l_flg_tst_LI0_EvIDByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteE)
#define l_flg_clr_LI0_EvIDByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteE)
#define l_flg_tst_LI0_EvIDByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteF)
#define l_flg_clr_LI0_EvIDByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteF)
#define l_flg_tst_LI0_EvIDByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteG)
#define l_flg_clr_LI0_EvIDByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_EvIDByteG)
#define l_flg_tst_LI0_EvGridCodeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvGridCodeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvGridCodeStatus)
#define l_flg_clr_LI0_EvGridCodeStatus_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvGridCodeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvGridCodeStatus)
#define l_flg_tst_LI0_EvGridCodeStatusMod_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvGridCodeStatusMod],\
         LIN_FLAG_BIT_OFFSET_LI0_EvGridCodeStatusMod)
#define l_flg_clr_LI0_EvGridCodeStatusMod_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvGridCodeStatusMod],\
         LIN_FLAG_BIT_OFFSET_LI0_EvGridCodeStatusMod)
#define l_flg_tst_LI0_EvPwrCtrlUnitsAvail_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlUnitsAvail)
#define l_flg_clr_LI0_EvPwrCtrlUnitsAvail_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlUnitsAvail],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlUnitsAvail)
#define l_flg_tst_LI0_EvPwrCtrlModesAvail_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlModesAvail)
#define l_flg_clr_LI0_EvPwrCtrlModesAvail_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlModesAvail],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlModesAvail)
#define l_flg_tst_LI0_EvPwrCtrlModeAck_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlModeAck],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlModeAck)
#define l_flg_clr_LI0_EvPwrCtrlModeAck_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPwrCtrlModeAck],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPwrCtrlModeAck)
#define l_flg_tst_LI0_EvInverterState_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInverterState],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInverterState)
#define l_flg_clr_LI0_EvInverterState_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInverterState],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInverterState)
#define l_flg_tst_LI0_EvJ3072ByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteA)
#define l_flg_clr_LI0_EvJ3072ByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteA)
#define l_flg_tst_LI0_EvJ3072ByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteB)
#define l_flg_clr_LI0_EvJ3072ByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteB)
#define l_flg_tst_LI0_EvJ3072ByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteC)
#define l_flg_clr_LI0_EvJ3072ByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteC)
#define l_flg_tst_LI0_EvJ3072ByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteD)
#define l_flg_clr_LI0_EvJ3072ByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteD)
#define l_flg_tst_LI0_EvJ3072ByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteE)
#define l_flg_clr_LI0_EvJ3072ByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteE)
#define l_flg_tst_LI0_EvJ3072ByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteF)
#define l_flg_clr_LI0_EvJ3072ByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteF)
#define l_flg_tst_LI0_EvJ3072ByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteG)
#define l_flg_clr_LI0_EvJ3072ByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072ByteG)
#define l_flg_tst_LI0_EvJ3072Page_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072Page)
#define l_flg_clr_LI0_EvJ3072Page_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072Page)
#define l_flg_tst_LI0_SeGridCodeRequest_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeGridCodeRequest],\
         LIN_FLAG_BIT_OFFSET_LI0_SeGridCodeRequest)
#define l_flg_clr_LI0_SeGridCodeRequest_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeGridCodeRequest],\
         LIN_FLAG_BIT_OFFSET_LI0_SeGridCodeRequest)
#define l_flg_tst_LI0_SePwrCtrlMode_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlMode],\
         LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlMode)
#define l_flg_clr_LI0_SePwrCtrlMode_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlMode],\
         LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlMode)
#define l_flg_tst_LI0_SePwrCtrlAuth_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlAuth],\
         LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlAuth)
#define l_flg_clr_LI0_SePwrCtrlAuth_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlAuth],\
         LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlAuth)
#define l_flg_tst_LI0_SeInverterRequest_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInverterRequest],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInverterRequest)
#define l_flg_clr_LI0_SeInverterRequest_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInverterRequest],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInverterRequest)
#define l_flg_tst_LI0_SeJ3072ByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteA)
#define l_flg_clr_LI0_SeJ3072ByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteA)
#define l_flg_tst_LI0_SeJ3072ByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteB)
#define l_flg_clr_LI0_SeJ3072ByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteB)
#define l_flg_tst_LI0_SeJ3072ByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteC)
#define l_flg_clr_LI0_SeJ3072ByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteC)
#define l_flg_tst_LI0_SeJ3072ByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteD)
#define l_flg_clr_LI0_SeJ3072ByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteD)
#define l_flg_tst_LI0_SeJ3072ByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteE)
#define l_flg_clr_LI0_SeJ3072ByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteE)
#define l_flg_tst_LI0_SeJ3072ByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteF)
#define l_flg_clr_LI0_SeJ3072ByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteF)
#define l_flg_tst_LI0_SeJ3072ByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteG)
#define l_flg_clr_LI0_SeJ3072ByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072ByteG)
#define l_flg_tst_LI0_SeJ3072Page_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072Page)
#define l_flg_clr_LI0_SeJ3072Page_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072Page)
#define l_flg_tst_LI0_SePwrCtrlUnits_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlUnits],\
         LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlUnits)
#define l_flg_clr_LI0_SePwrCtrlUnits_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SePwrCtrlUnits],\
         LIN_FLAG_BIT_OFFSET_LI0_SePwrCtrlUnits)
#define l_flg_tst_LI0_SeTargets1ElementA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementA],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementA)
#define l_flg_clr_LI0_SeTargets1ElementA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementA],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementA)
#define l_flg_tst_LI0_SeTargets1ElementB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementB],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementB)
#define l_flg_clr_LI0_SeTargets1ElementB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementB],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementB)
#define l_flg_tst_LI0_SeTargets1ElementC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementC],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementC)
#define l_flg_clr_LI0_SeTargets1ElementC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementC],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementC)
#define l_flg_tst_LI0_SeTargets1ElementD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementD],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementD)
#define l_flg_clr_LI0_SeTargets1ElementD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1ElementD],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1ElementD)
#define l_flg_tst_LI0_SeTimeStamp_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTimeStamp],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTimeStamp)
#define l_flg_clr_LI0_SeTimeStamp_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTimeStamp],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTimeStamp)

 #define l_flg_tst_LI1_EvSelectedVersion_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList)
#define l_flg_tst_LI1_EvSelectedVersion_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus)
#define l_flg_tst_LI1_EvSelectedVersion_EvPresentCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents)
#define l_flg_tst_LI1_EvSelectedVersion_EvMaxVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages)
#define l_flg_tst_LI1_EvSelectedVersion_EvMinVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages)
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
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvStatus)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvPresentCurrents)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxVoltages)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMinVoltages)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvMaxMinCurrents)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvInfoList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvSelectedVersion_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvSelectedVersion_EvErrorList)}\
 #define l_flg_tst_LI1_EvResponseError_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList)
#define l_flg_tst_LI1_EvResponseError_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus)

#define l_flg_clr_LI1_EvResponseError_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvResponseError_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvResponseError_EvStatus)}\
 #define l_flg_tst_LI1_EvStatusVer_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList)
#define l_flg_tst_LI1_EvStatusVer_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus)

#define l_flg_clr_LI1_EvStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusVer_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusVer_EvStatus)}\
 #define l_flg_tst_LI1_EvStatusInit_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList)
#define l_flg_tst_LI1_EvStatusInit_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus)

#define l_flg_clr_LI1_EvStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusInit_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusInit_EvStatus)}\
 #define l_flg_tst_LI1_EvStatusOp_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList)
#define l_flg_tst_LI1_EvStatusOp_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus)

#define l_flg_clr_LI1_EvStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatusOp_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatusOp_EvStatus)}\
 #define l_flg_tst_LI1_EvAwake_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList)
#define l_flg_tst_LI1_EvAwake_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus)

#define l_flg_clr_LI1_EvAwake_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvAwake_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvAwake_EvStatus)}\
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
#define l_flg_tst_LI1_SeSelectedVersion_SeMaxCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents)
#define l_flg_tst_LI1_SeSelectedVersion_SeInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList)
#define l_flg_tst_LI1_SeSelectedVersion_StErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList)

#define l_flg_clr_LI1_SeSelectedVersion_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeStatus)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeNomVoltages)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeMaxCurrents)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_SeInfoList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeSelectedVersion_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeSelectedVersion_StErrorList)}\
 #define l_flg_tst_LI1_SeStatusVer_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList)
#define l_flg_tst_LI1_SeStatusVer_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus)

#define l_flg_clr_LI1_SeStatusVer_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusVer_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusVer_SeStatus)}\
 #define l_flg_tst_LI1_SeStatusInit_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList)
#define l_flg_tst_LI1_SeStatusInit_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus)

#define l_flg_clr_LI1_SeStatusInit_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusInit_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusInit_SeStatus)}\
 #define l_flg_tst_LI1_SeStatusOp_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList)
#define l_flg_tst_LI1_SeStatusOp_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus)

#define l_flg_clr_LI1_SeStatusOp_flag() \
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeVersionList)}\
        {LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatusOp_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatusOp_SeStatus)}\
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
#define l_flg_tst_LI1_SeConnectionType_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI1_SeConnectionType)
#define l_flg_clr_LI1_SeConnectionType_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI1_SeConnectionType)
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
#define l_flg_tst_LI1_EvConnectionType_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI1_EvConnectionType)
#define l_flg_clr_LI1_EvConnectionType_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvConnectionType],\
         LIN_FLAG_BIT_OFFSET_LI1_EvConnectionType)
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
#define l_flg_tst_LI1_SeIDPage_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDPage],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDPage)
#define l_flg_clr_LI1_SeIDPage_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDPage],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDPage)
#define l_flg_tst_LI1_SeIDByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteA)
#define l_flg_clr_LI1_SeIDByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteA)
#define l_flg_tst_LI1_SeIDByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteB)
#define l_flg_clr_LI1_SeIDByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteB)
#define l_flg_tst_LI1_SeIDByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteC)
#define l_flg_clr_LI1_SeIDByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteC)
#define l_flg_tst_LI1_SeIDByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteD)
#define l_flg_clr_LI1_SeIDByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteD)
#define l_flg_tst_LI1_SeIDByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteE)
#define l_flg_clr_LI1_SeIDByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteE)
#define l_flg_tst_LI1_SeIDByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteF)
#define l_flg_clr_LI1_SeIDByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteF)
#define l_flg_tst_LI1_SeIDByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteG)
#define l_flg_clr_LI1_SeIDByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_SeIDByteG)
#define l_flg_tst_LI1_EvIDPage_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDPage],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDPage)
#define l_flg_clr_LI1_EvIDPage_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDPage],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDPage)
#define l_flg_tst_LI1_EvIDByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteA)
#define l_flg_clr_LI1_EvIDByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteA)
#define l_flg_tst_LI1_EvIDByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteB)
#define l_flg_clr_LI1_EvIDByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteB)
#define l_flg_tst_LI1_EvIDByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteC)
#define l_flg_clr_LI1_EvIDByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteC)
#define l_flg_tst_LI1_EvIDByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteD)
#define l_flg_clr_LI1_EvIDByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteD)
#define l_flg_tst_LI1_EvIDByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteE)
#define l_flg_clr_LI1_EvIDByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteE)
#define l_flg_tst_LI1_EvIDByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteF)
#define l_flg_clr_LI1_EvIDByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteF)
#define l_flg_tst_LI1_EvIDByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteG)
#define l_flg_clr_LI1_EvIDByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvIDByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_EvIDByteG)
#define l_flg_tst_LI1_EvGridCodeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvGridCodeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvGridCodeStatus)
#define l_flg_clr_LI1_EvGridCodeStatus_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvGridCodeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvGridCodeStatus)
#define l_flg_tst_LI1_EvGridCodeStatusMod_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvGridCodeStatusMod],\
         LIN_FLAG_BIT_OFFSET_LI1_EvGridCodeStatusMod)
#define l_flg_clr_LI1_EvGridCodeStatusMod_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvGridCodeStatusMod],\
         LIN_FLAG_BIT_OFFSET_LI1_EvGridCodeStatusMod)
#define l_flg_tst_LI1_EvPwrCtrlUnitsAvail_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlUnitsAvail)
#define l_flg_clr_LI1_EvPwrCtrlUnitsAvail_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlUnitsAvail],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlUnitsAvail)
#define l_flg_tst_LI1_EvPwrCtrlModesAvail_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlModesAvail)
#define l_flg_clr_LI1_EvPwrCtrlModesAvail_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlModesAvail],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlModesAvail)
#define l_flg_tst_LI1_EvPwrCtrlModeAck_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlModeAck],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlModeAck)
#define l_flg_clr_LI1_EvPwrCtrlModeAck_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPwrCtrlModeAck],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPwrCtrlModeAck)
#define l_flg_tst_LI1_EvInverterState_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInverterState],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInverterState)
#define l_flg_clr_LI1_EvInverterState_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInverterState],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInverterState)
#define l_flg_tst_LI1_EvJ3072ByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteA)
#define l_flg_clr_LI1_EvJ3072ByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteA)
#define l_flg_tst_LI1_EvJ3072ByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteB)
#define l_flg_clr_LI1_EvJ3072ByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteB)
#define l_flg_tst_LI1_EvJ3072ByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteC)
#define l_flg_clr_LI1_EvJ3072ByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteC)
#define l_flg_tst_LI1_EvJ3072ByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteD)
#define l_flg_clr_LI1_EvJ3072ByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteD)
#define l_flg_tst_LI1_EvJ3072ByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteE)
#define l_flg_clr_LI1_EvJ3072ByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteE)
#define l_flg_tst_LI1_EvJ3072ByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteF)
#define l_flg_clr_LI1_EvJ3072ByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteF)
#define l_flg_tst_LI1_EvJ3072ByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteG)
#define l_flg_clr_LI1_EvJ3072ByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072ByteG)
#define l_flg_tst_LI1_EvJ3072Page_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072Page)
#define l_flg_clr_LI1_EvJ3072Page_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072Page)
#define l_flg_tst_LI1_SeGridCodeRequest_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeGridCodeRequest],\
         LIN_FLAG_BIT_OFFSET_LI1_SeGridCodeRequest)
#define l_flg_clr_LI1_SeGridCodeRequest_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeGridCodeRequest],\
         LIN_FLAG_BIT_OFFSET_LI1_SeGridCodeRequest)
#define l_flg_tst_LI1_SePwrCtrlMode_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlMode],\
         LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlMode)
#define l_flg_clr_LI1_SePwrCtrlMode_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlMode],\
         LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlMode)
#define l_flg_tst_LI1_SePwrCtrlAuth_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlAuth],\
         LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlAuth)
#define l_flg_clr_LI1_SePwrCtrlAuth_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlAuth],\
         LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlAuth)
#define l_flg_tst_LI1_SeInverterRequest_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInverterRequest],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInverterRequest)
#define l_flg_clr_LI1_SeInverterRequest_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInverterRequest],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInverterRequest)
#define l_flg_tst_LI1_SeJ3072ByteA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteA)
#define l_flg_clr_LI1_SeJ3072ByteA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteA],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteA)
#define l_flg_tst_LI1_SeJ3072ByteB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteB)
#define l_flg_clr_LI1_SeJ3072ByteB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteB],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteB)
#define l_flg_tst_LI1_SeJ3072ByteC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteC)
#define l_flg_clr_LI1_SeJ3072ByteC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteC],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteC)
#define l_flg_tst_LI1_SeJ3072ByteD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteD)
#define l_flg_clr_LI1_SeJ3072ByteD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteD],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteD)
#define l_flg_tst_LI1_SeJ3072ByteE_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteE)
#define l_flg_clr_LI1_SeJ3072ByteE_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteE],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteE)
#define l_flg_tst_LI1_SeJ3072ByteF_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteF)
#define l_flg_clr_LI1_SeJ3072ByteF_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteF],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteF)
#define l_flg_tst_LI1_SeJ3072ByteG_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteG)
#define l_flg_clr_LI1_SeJ3072ByteG_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072ByteG],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072ByteG)
#define l_flg_tst_LI1_SeJ3072Page_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072Page)
#define l_flg_clr_LI1_SeJ3072Page_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072Page],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072Page)
#define l_flg_tst_LI1_SePwrCtrlUnits_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlUnits],\
         LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlUnits)
#define l_flg_clr_LI1_SePwrCtrlUnits_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SePwrCtrlUnits],\
         LIN_FLAG_BIT_OFFSET_LI1_SePwrCtrlUnits)
#define l_flg_tst_LI1_SeTargets1ElementA_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementA],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementA)
#define l_flg_clr_LI1_SeTargets1ElementA_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementA],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementA)
#define l_flg_tst_LI1_SeTargets1ElementB_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementB],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementB)
#define l_flg_clr_LI1_SeTargets1ElementB_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementB],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementB)
#define l_flg_tst_LI1_SeTargets1ElementC_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementC],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementC)
#define l_flg_clr_LI1_SeTargets1ElementC_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementC],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementC)
#define l_flg_tst_LI1_SeTargets1ElementD_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementD],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementD)
#define l_flg_clr_LI1_SeTargets1ElementD_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1ElementD],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1ElementD)
#define l_flg_tst_LI1_SeTimeStamp_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTimeStamp],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTimeStamp)
#define l_flg_clr_LI1_SeTimeStamp_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTimeStamp],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTimeStamp)



/* Frame flag APIs */
#define l_flg_tst_LI0_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeVersionList)
#define l_flg_clr_LI0_SeVersionList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeVersionList)
#define l_flg_tst_LI0_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvVersionList)
#define l_flg_clr_LI0_EvVersionList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvVersionList)
#define l_flg_tst_LI0_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatus)
#define l_flg_clr_LI0_SeStatus_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_SeStatus)
#define l_flg_tst_LI0_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatus)
#define l_flg_clr_LI0_EvStatus_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI0_EvStatus)
#define l_flg_tst_LI0_EvPresentCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrents)
#define l_flg_clr_LI0_EvPresentCurrents_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvPresentCurrents)
#define l_flg_tst_LI0_SeNomVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltages)
#define l_flg_clr_LI0_SeNomVoltages_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_SeNomVoltages)
#define l_flg_tst_LI0_SeMaxCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrents)
#define l_flg_clr_LI0_SeMaxCurrents_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_SeMaxCurrents)
#define l_flg_tst_LI0_EvMaxVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltages)
#define l_flg_clr_LI0_EvMaxVoltages_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxVoltages)
#define l_flg_tst_LI0_EvMinVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltages)
#define l_flg_clr_LI0_EvMinVoltages_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMinVoltages)
#define l_flg_tst_LI0_EvMaxMinCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxMinCurrents)
#define l_flg_clr_LI0_EvMaxMinCurrents_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI0_EvMaxMinCurrents)
#define l_flg_tst_LI0_EvInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoList)
#define l_flg_clr_LI0_EvInfoList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvInfoList)
#define l_flg_tst_LI0_SeInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoList)
#define l_flg_clr_LI0_SeInfoList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI0_SeInfoList)
#define l_flg_tst_LI0_StErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorList)
#define l_flg_clr_LI0_StErrorList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_StErrorList)
#define l_flg_tst_LI0_EvErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorList)
#define l_flg_clr_LI0_EvErrorList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI0_EvErrorList)
#define l_flg_tst_LI0_SeID_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeID],\
         LIN_FLAG_BIT_OFFSET_LI0_SeID)
#define l_flg_clr_LI0_SeID_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeID],\
         LIN_FLAG_BIT_OFFSET_LI0_SeID)
#define l_flg_tst_LI0_EvID_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvID],\
         LIN_FLAG_BIT_OFFSET_LI0_EvID)
#define l_flg_clr_LI0_EvID_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvID],\
         LIN_FLAG_BIT_OFFSET_LI0_EvID)
#define l_flg_tst_LI0_EvModeCtrl_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI0_EvModeCtrl)
#define l_flg_clr_LI0_EvModeCtrl_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI0_EvModeCtrl)
#define l_flg_tst_LI0_SeModeCtrl_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI0_SeModeCtrl)
#define l_flg_clr_LI0_SeModeCtrl_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI0_SeModeCtrl)
#define l_flg_tst_LI0_EvJ3072_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072)
#define l_flg_clr_LI0_EvJ3072_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_EvJ3072],\
         LIN_FLAG_BIT_OFFSET_LI0_EvJ3072)
#define l_flg_tst_LI0_SeJ3072_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072)
#define l_flg_clr_LI0_SeJ3072_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeJ3072],\
         LIN_FLAG_BIT_OFFSET_LI0_SeJ3072)
#define l_flg_tst_LI0_SeTargets1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1)
#define l_flg_clr_LI0_SeTargets1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI0_SeTargets1],\
         LIN_FLAG_BIT_OFFSET_LI0_SeTargets1)
#define l_flg_tst_LI1_SeVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeVersionList)
#define l_flg_clr_LI1_SeVersionList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeVersionList)
#define l_flg_tst_LI1_EvVersionList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvVersionList)
#define l_flg_clr_LI1_EvVersionList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvVersionList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvVersionList)
#define l_flg_tst_LI1_SeStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatus)
#define l_flg_clr_LI1_SeStatus_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_SeStatus)
#define l_flg_tst_LI1_EvStatus_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatus)
#define l_flg_clr_LI1_EvStatus_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvStatus],\
         LIN_FLAG_BIT_OFFSET_LI1_EvStatus)
#define l_flg_tst_LI1_EvPresentCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrents)
#define l_flg_clr_LI1_EvPresentCurrents_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvPresentCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvPresentCurrents)
#define l_flg_tst_LI1_SeNomVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltages)
#define l_flg_clr_LI1_SeNomVoltages_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeNomVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_SeNomVoltages)
#define l_flg_tst_LI1_SeMaxCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrents)
#define l_flg_clr_LI1_SeMaxCurrents_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeMaxCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_SeMaxCurrents)
#define l_flg_tst_LI1_EvMaxVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltages)
#define l_flg_clr_LI1_EvMaxVoltages_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxVoltages)
#define l_flg_tst_LI1_EvMinVoltages_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltages)
#define l_flg_clr_LI1_EvMinVoltages_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMinVoltages],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMinVoltages)
#define l_flg_tst_LI1_EvMaxMinCurrents_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxMinCurrents)
#define l_flg_clr_LI1_EvMaxMinCurrents_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvMaxMinCurrents],\
         LIN_FLAG_BIT_OFFSET_LI1_EvMaxMinCurrents)
#define l_flg_tst_LI1_EvInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoList)
#define l_flg_clr_LI1_EvInfoList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvInfoList)
#define l_flg_tst_LI1_SeInfoList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoList)
#define l_flg_clr_LI1_SeInfoList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeInfoList],\
         LIN_FLAG_BIT_OFFSET_LI1_SeInfoList)
#define l_flg_tst_LI1_StErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorList)
#define l_flg_clr_LI1_StErrorList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_StErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_StErrorList)
#define l_flg_tst_LI1_EvErrorList_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorList)
#define l_flg_clr_LI1_EvErrorList_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvErrorList],\
         LIN_FLAG_BIT_OFFSET_LI1_EvErrorList)
#define l_flg_tst_LI1_SeID_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeID],\
         LIN_FLAG_BIT_OFFSET_LI1_SeID)
#define l_flg_clr_LI1_SeID_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeID],\
         LIN_FLAG_BIT_OFFSET_LI1_SeID)
#define l_flg_tst_LI1_EvID_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvID],\
         LIN_FLAG_BIT_OFFSET_LI1_EvID)
#define l_flg_clr_LI1_EvID_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvID],\
         LIN_FLAG_BIT_OFFSET_LI1_EvID)
#define l_flg_tst_LI1_EvModeCtrl_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI1_EvModeCtrl)
#define l_flg_clr_LI1_EvModeCtrl_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI1_EvModeCtrl)
#define l_flg_tst_LI1_SeModeCtrl_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI1_SeModeCtrl)
#define l_flg_clr_LI1_SeModeCtrl_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeModeCtrl],\
         LIN_FLAG_BIT_OFFSET_LI1_SeModeCtrl)
#define l_flg_tst_LI1_EvJ3072_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072)
#define l_flg_clr_LI1_EvJ3072_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_EvJ3072],\
         LIN_FLAG_BIT_OFFSET_LI1_EvJ3072)
#define l_flg_tst_LI1_SeJ3072_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072)
#define l_flg_clr_LI1_SeJ3072_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeJ3072],\
         LIN_FLAG_BIT_OFFSET_LI1_SeJ3072)
#define l_flg_tst_LI1_SeTargets1_flag() \
         LIN_TEST_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1)
#define l_flg_clr_LI1_SeTargets1_flag() \
         LIN_CLEAR_BIT(lin_flag_handle_tbl[LIN_FLAG_BYTE_OFFSET_LI1_SeTargets1],\
         LIN_FLAG_BIT_OFFSET_LI1_SeTargets1)



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