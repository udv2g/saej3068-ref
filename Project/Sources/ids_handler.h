#ifndef IDS_HANDLER_H
#define IDS_HANDLER_H

enum {ID_INCOMPLETE = 0, ID_COMPLETE, DATA};

bool id_parse(uint8_t ch);
void id_xmit(uint8_t ch, uint8_t page);

void data_parse(uint8_t ch);
void data_xmit(uint8_t ch, uint8_t page);

void ids_init(uint8_t ch);
void on_id_frame_receipt(uint8_t ch);
void on_id_frame_xmit(uint8_t ch);

void copy_buffer_data(uint8_t * _FAR_ source, uint8_t * _FAR_ destination, uint8_t size, bool string);
void invalidate_bytes_page(uint8_t * buffer, uint8_t mask);

#define EVSTATUSINLETLATCH_RELEASED 0x00
#define EVSTATUSINLETLATCH_ENGAGED 0x01
#define EVSTATUSINLETLATCH_ERROR 0x02
#define EVSTATUSINLETLATCH_NOT_AVAILABLE 0x03
#define EVSTATUSINLETOVERRIDE_NOT_ACTIVE 0x00
#define EVSTATUSINLETOVERRIDE_ACTIVE 0x01
#define EVSTATUSINLETOVERRIDE_ERROR 0x02
#define EVSTATUSINLETOVERRIDE_NOT_AVAILABLE 0x03
#define EVSTATUSINLETLOCK_UNLOCKED 0x00
#define EVSTATUSINLETLOCK_LOCKED 0x01
#define EVSTATUSINLETLOCK_IN_TRANSITION 0x02
#define EVSTATUSINLETLOCK_NO_LOCK 0x05
#define EVSTATUSINLETLOCK_ERROR 0x06
#define EVSTATUSINLETLOCK_NOT_AVAILABLE 0x07
#define EVSTATUSCELLVOLTDIFF_WITHIN_ACCEPTABLE_LIMITS 0x00
#define EVSTATUSCELLVOLTDIFF_CAN_BE_CORRECTED 0x01
#define EVSTATUSCELLVOLTDIFF_MAINTENANCE_CAN_RESTORE_PERFORMANCE 0x02
#define EVSTATUSCELLVOLTDIFF_MAINTENANCE_CANNOT_RESTORE_PERFORMANCE 0x03
#define EVSTATUSCELLVOLTDIFF_PERFORMANCE_RESTORATION_UNKNOWN 0x04
#define EVSTATUSCELLVOLTDIFF_ERROR 0x0E
#define EVSTATUSCELLVOLTDIFF_NOT_AVAILABLE 0x0F
#define EVSTATUSCELLBAL_BALANCED 0x00
#define EVSTATUSCELLBAL_UNBALANCED 0x01
#define EVSTATUSCELLBAL_ERROR 0x02
#define EVSTATUSCELLBAL_NOT_AVAILABLE 0x03
#define EVACTIVECELLBAL_NOT_ACTIVE 0x00
#define EVACTIVECELLBAL_ACTIVE 0x01
#define EVACTIVECELLBAL_ERROR 0x02
#define EVACTIVECELLBAL_NOT_AVAILABLE 0x03

#define SERMTMGMTSTATUS_CONNECTED 0x00
#define SERMTMGMTSTATUS_CONNECTING 0x01
#define SERMTMGMTSTATUS_NOT_CONNECTED 0x02
#define SERMTMGMTSTATUS_FALLBACK 0x03
#define SERMTMGMTSTATUS_LOCAL 0x04
#define SERMTMGMTSTATUS_ERROR 0xFE
#define SERMTMGMTSTATUS_NONE_OR_STATUS_UNKNOWN 0xFF
#define SEEVTRIPSTATUS_NOT_PRESENT 0x00
#define SEEVTRIPSTATUS_FOLLOWING 0x01
#define SEEVTRIPSTATUS_CANNOT_BE_MET 0x02
#define SEEVTRIPSTATUS_INVALID 0xFE
#define SEEVTRIPSTATUS_NOT_SUPPORTED 0xFF
#define SESETRIPSTATUS_NOT_PRESENT 0x00
#define SESETRIPSTATUS_FOLLOWING 0x01
#define SESETRIPSTATUS_CANNOT_BE_MET 0x02
#define SESETRIPSTATUS_EV_PRECEDENCE 0x03
#define SESETRIPSTATUS_CANNOT_RETRIEVE 0xFE
#define SESETRIPSTATUS_NOT_SUPPORTED 0xFF

typedef struct  {
  uint8_t EvVIN[18];
  uint8_t EvSerialNum[43];
  uint8_t EvVehicleName[22];
  uint8_t EvFirmwareRevision[29];
  uint8_t EvManufacturer[43];
} ev_ids_strings_t;

typedef struct  {
  uint8_t SeEVSEID[41];
  uint8_t SeSECCID[71];
  uint8_t SeSerialNum[43];
  uint8_t SeFirmwareRevision[29];
  uint8_t SeManufacturer[43];
  uint8_t SePublicName[43];
} se_ids_strings_t;

typedef struct  {
  uint32_t EvOdometer;
  uint8_t EvStatusInletLatch;
  uint8_t EvStatusInletOverride;
  uint8_t EvStatusInletLock;
  uint32_t EvHVESSDishargeCapacity;
  uint32_t EvHVESSChargeCapacity;
  uint16_t EvHVESSRange;
  uint16_t EvEVTimeToEnergyForDept;
  uint16_t EvDurMin;
  uint16_t EvChaDurMax;
  uint16_t EvDschDurMax;
  uint8_t EvTimeReqNum;
  uint16_t EvEVTimeToRange;
  uint16_t EvEVTimeToEnergy;
  uint16_t EvHVESSVoltage;
  uint16_t EvHVESSCurrent;
  uint8_t EvHVESSHealth;
  uint8_t EvHVESSUserSOC;
  uint16_t EvACActivePower;
  uint16_t EvACReactivePower;
  uint8_t EvACFrequency;
  uint16_t EvL1NVolts;
  uint16_t EvL2NVolts;
  uint16_t EvL3NVolts;
  uint16_t EvAmbientTemp;
  uint16_t EvCabinTemp;
  uint16_t EvHVESSCellTemp;
  uint16_t EvMaxHVESSTemp;
  uint16_t EvMinHVESSTemp;
  uint8_t EvHVESSElecTemp;
  uint16_t EvMaxHVESSCellVolt;
  uint16_t EvMinHVESSCellVolt;
  uint16_t EvNumHVESSCellBalancing;
  uint8_t EvStatusCellVoltDiff;
  uint8_t EvStatusCellBal;
  uint8_t EvActiveCellBal;
  uint16_t EvChargerTemp;
  uint16_t EvMaxChargerTemp;
  uint8_t EvInletTemp;
  uint8_t EvHVESSTemp;
} ev_data_vars_t;

typedef struct  {
  uint8_t SeRmtMgmtStatus;
  uint8_t SeEvTripStatus;
  uint8_t SeSeTripStatus;
  uint8_t SeExptTripPerct;
  uint8_t SeTimeReqNum;
  uint16_t SeHVESSRangeCalc;
  uint32_t SeHVESSEnergyCalc;
} se_data_vars_t;

typedef struct  {
  ev_ids_strings_t  s;
} ev_ids_t;

typedef struct  {
  se_ids_strings_t  s;
} se_ids_t;

typedef struct  {
  ev_data_vars_t    v;
} ev_data_t;

typedef struct  {
  se_data_vars_t    v;
} se_data_t;

#ifdef EV_CONFIG
extern ev_data_t * _FAR_ inact_data_xmit[];
#else
extern se_data_t * _FAR_ inact_data_xmit[];
#endif

#endif