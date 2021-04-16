
#include "types.h"
#include "utils.h"

#include "j1939-signals.h"

int read_EVSE1AC3PL (void *dest, uint8_t *buf, int offset, int buf_size) {
  EVSE1AC3PL_t *my_info = (EVSE1AC3PL_t *) dest;

  my_info->HVESS_Charger_RMS_current_L1 = read_int16_le(buf, &offset, buf_size);
  my_info->HVESS_Charger_RMS_current_L2 = read_int16_le(buf, &offset, buf_size);
  my_info->HVESS_Charger_RMS_current_L3 = read_int16_le(buf, &offset, buf_size);
  my_info->HVESS_Charger_RMS_current_N = read_int16_le(buf, &offset, buf_size);
  return 8;
}


int write_EVSE1AC3PL (uint8_t *can_data, void *src) {
  EVSE1AC3PL_t *my_info = (EVSE1AC3PL_t *) src;
  int offset = 0;
  int buf_size = 8;

  write_int16_le(my_info->HVESS_Charger_RMS_current_L1, can_data, &offset, buf_size);
  write_int16_le(my_info->HVESS_Charger_RMS_current_L2, can_data, &offset, buf_size);
  write_int16_le(my_info->HVESS_Charger_RMS_current_L3, can_data, &offset, buf_size);
  write_int16_le(my_info->HVESS_Charger_RMS_current_N, can_data, &offset, buf_size);
  return 8;
}


int read_EVSE1ACS1 (void *dest, uint8_t *buf, int offset, int buf_size) {
  EVSE1ACS1_t *my_info = (EVSE1ACS1_t *) dest;

  my_info->EVSE_AC_RMS_CurrentLimitL1 = read_int16_le(buf, &offset, buf_size);
  my_info->EVSE_AC_RMS_CurrentLimitL2 = read_int16_le(buf, &offset, buf_size);
  my_info->EVSE_AC_RMS_CurrentLimitL3 = read_int16_le(buf, &offset, buf_size);
  my_info->EVSE_AC_RMS_CurrentLimitN = read_int16_le(buf, &offset, buf_size);
  return 8;
}


int write_EVSE1ACS1 (uint8_t *can_data, void *src) {
  EVSE1ACS1_t *my_info = (EVSE1ACS1_t *) src;
  int offset = 0;
  int buf_size = 8;

  write_int16_le(my_info->EVSE_AC_RMS_CurrentLimitL1, can_data, &offset, buf_size);
  write_int16_le(my_info->EVSE_AC_RMS_CurrentLimitL2, can_data, &offset, buf_size);
  write_int16_le(my_info->EVSE_AC_RMS_CurrentLimitL3, can_data, &offset, buf_size);
  write_int16_le(my_info->EVSE_AC_RMS_CurrentLimitN, can_data, &offset, buf_size);
  return 8;
}


int read_EVSE1ACSV (void *dest, uint8_t *buf, int offset, int buf_size) {
  EVSE1ACSV_t *my_info = (EVSE1ACSV_t *) dest;

  my_info->SeNomVoltageL1N = read_int16_le(buf, &offset, buf_size);
  my_info->SeNomVoltageLL = read_int16_le(buf, &offset, buf_size);
  my_info->SeFrequency = buf[offset++ % buf_size];
  my_info->unused = buf[offset++ % buf_size];
  my_info->unused1 = read_int16_le(buf, &offset, buf_size);
  return 8;
}


int write_EVSE1ACSV (uint8_t *can_data, void *src) {
  EVSE1ACSV_t *my_info = (EVSE1ACSV_t *) src;
  int offset = 0;
  int buf_size = 8;

  write_int16_le(my_info->SeNomVoltageL1N, can_data, &offset, buf_size);
  write_int16_le(my_info->SeNomVoltageLL, can_data, &offset, buf_size);
  can_data[offset++ % buf_size] = my_info->SeFrequency;
  can_data[offset++ % buf_size] = my_info->unused;
  write_int16_le(my_info->unused1, can_data, &offset, buf_size);
  return 8;
}


int read_EVSE1C1 (void *dest, uint8_t *buf, int offset, int buf_size) {
  EVSE1C1_t *my_info = (EVSE1C1_t *) dest;
  uint8_t temp_8bit_var;


  temp_8bit_var = buf[offset++ % buf_size];
  my_info->unused2 = (temp_8bit_var >> 4) & 0x0f;
  my_info->EVSE1_ConnectorLockCommand = temp_8bit_var & 0x0f;
  my_info->unused3 = buf[offset++ % buf_size];
  my_info->unused4 = read_int16_le(buf, &offset, buf_size);
  my_info->unused5 = read_int16_le(buf, &offset, buf_size);
  my_info->unused6 = read_int16_le(buf, &offset, buf_size);
  return 8;
}


int write_EVSE1C1 (uint8_t *can_data, void *src) {
  EVSE1C1_t *my_info = (EVSE1C1_t *) src;
  int offset = 0;
  int buf_size = 8;
  uint8_t temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->unused2 & 0x0F) << 4; 
  temp_8bit_var |= my_info->EVSE1_ConnectorLockCommand & 0x0f;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->unused3;
  write_int16_le(my_info->unused4, can_data, &offset, buf_size);
  write_int16_le(my_info->unused5, can_data, &offset, buf_size);
  write_int16_le(my_info->unused6, can_data, &offset, buf_size);
  return 8;
}


int read_EVSE1S1 (void *dest, uint8_t *buf, int offset, int buf_size) {
  EVSE1S1_t *my_info = (EVSE1S1_t *) dest;
  uint8_t temp_8bit_var;


  temp_8bit_var = buf[offset++ % buf_size];
  my_info->unused7 = (temp_8bit_var >> 7) & 0x01;
  my_info->EVSE1_ConnectorLockState = (temp_8bit_var >> 4) & 0x07;
  my_info->EVSE1_ManualOverRide = (temp_8bit_var >> 2) & 0x03;
  my_info->EVSE1_ConnectorReleaseLatch = temp_8bit_var & 0x03;
  my_info->unused8 = buf[offset++ % buf_size];
  my_info->unused9 = read_int16_le(buf, &offset, buf_size);
  my_info->unused10 = read_int16_le(buf, &offset, buf_size);
  my_info->unused12 = read_int16_le(buf, &offset, buf_size);
  return 8;
}


int write_EVSE1S1 (uint8_t *can_data, void *src) {
  EVSE1S1_t *my_info = (EVSE1S1_t *) src;
  int offset = 0;
  int buf_size = 8;
  uint8_t temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->unused7 & 0x01) << 7; 
  temp_8bit_var |= (my_info->EVSE1_ConnectorLockState & 0x07) << 4; 
  temp_8bit_var |= (my_info->EVSE1_ManualOverRide & 0x03) << 2; 
  temp_8bit_var |= my_info->EVSE1_ConnectorReleaseLatch & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->unused8;
  write_int16_le(my_info->unused9, can_data, &offset, buf_size);
  write_int16_le(my_info->unused10, can_data, &offset, buf_size);
  write_int16_le(my_info->unused12, can_data, &offset, buf_size);
  return 8;
}


int read_InletProxAndSeInfo (void *dest, uint8_t *buf, int offset, int buf_size) {
  InletProxAndSeInfo_t *my_info = (InletProxAndSeInfo_t *) dest;
  uint8_t temp_8bit_var;


  temp_8bit_var = buf[offset++ % buf_size];
  my_info->Se_Ev_System_State = (temp_8bit_var >> 4) & 0x0f;
  my_info->Prox_Status = temp_8bit_var & 0x0f;
  my_info->SeInfoPageNumber = buf[offset++ % buf_size];
  my_info->SeInfoEntry1 = buf[offset++ % buf_size];
  my_info->SeInfoEntry2 = buf[offset++ % buf_size];
  my_info->SeInfoEntry3 = buf[offset++ % buf_size];
  my_info->SeInfoEntry4 = buf[offset++ % buf_size];
  my_info->SeInfoEntry5 = buf[offset++ % buf_size];
  my_info->SeInfoEntry6 = buf[offset++ % buf_size];
  return 8;
}


int write_InletProxAndSeInfo (uint8_t *can_data, void *src) {
  InletProxAndSeInfo_t *my_info = (InletProxAndSeInfo_t *) src;
  int offset = 0;
  int buf_size = 8;
  uint8_t temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->Se_Ev_System_State & 0x0F) << 4; 
  temp_8bit_var |= my_info->Prox_Status & 0x0f;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->SeInfoPageNumber;
  can_data[offset++ % buf_size] = my_info->SeInfoEntry1;
  can_data[offset++ % buf_size] = my_info->SeInfoEntry2;
  can_data[offset++ % buf_size] = my_info->SeInfoEntry3;
  can_data[offset++ % buf_size] = my_info->SeInfoEntry4;
  can_data[offset++ % buf_size] = my_info->SeInfoEntry5;
  can_data[offset++ % buf_size] = my_info->SeInfoEntry6;
  return 8;
}


int read_HSC1 (void *dest, uint8_t *buf, int offset, int buf_size) {
  HSC1_t *my_info = (HSC1_t *) dest;
  uint8_t temp_8bit_var;


  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridSystemShutdownCommand = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridRegenBrakingDisableRequest = (temp_8bit_var >> 4) & 0x03;
  my_info->HybridPropulsionDisableRequest = (temp_8bit_var >> 2) & 0x03;
  my_info->HybridPropulsionOverrideRequest = temp_8bit_var & 0x03;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridPropulsionModeRequest = (temp_8bit_var >> 4) & 0x0f;
  my_info->OperatorVehicleModeRequest = temp_8bit_var & 0x0f;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->ConnectedEnergySourceType = (temp_8bit_var >> 6) & 0x03;
  my_info->HVESChargeConsent = (temp_8bit_var >> 4) & 0x03;
  my_info->ExternalEnergyConnectionDemand = temp_8bit_var & 0x0f;
  my_info->Charge_DischargeRateRequest = buf[offset++ % buf_size];
  my_info->EnergySourceSetPointRequest = buf[offset++ % buf_size];
  my_info->HybridRequestedMaximumSpeed = buf[offset++ % buf_size];
  my_info->HybridModeRequestedDistance = read_int16_le(buf, &offset, buf_size);
  return 8;
#pragma MESSAGE DISABLE C12056  //debug info incorrect because of optimization or inline assembler
}


int write_HSC1 (uint8_t *can_data, void *src) {
  HSC1_t *my_info = (HSC1_t *) src;
  int offset = 0;
  int buf_size = 8;
  uint8_t temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridSystemShutdownCommand & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridRegenBrakingDisableRequest & 0x03) << 4; 
  temp_8bit_var |= (my_info->HybridPropulsionDisableRequest & 0x03) << 2; 
  temp_8bit_var |= my_info->HybridPropulsionOverrideRequest & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridPropulsionModeRequest & 0x0F) << 4; 
  temp_8bit_var |= my_info->OperatorVehicleModeRequest & 0x0f;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->ConnectedEnergySourceType & 0x03) << 6; 
  temp_8bit_var |= (my_info->HVESChargeConsent & 0x03) << 4; 
  temp_8bit_var |= my_info->ExternalEnergyConnectionDemand & 0x0f;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->Charge_DischargeRateRequest;
  can_data[offset++ % buf_size] = my_info->EnergySourceSetPointRequest;
  can_data[offset++ % buf_size] = my_info->HybridRequestedMaximumSpeed;
  write_int16_le(my_info->HybridModeRequestedDistance, can_data, &offset, buf_size);
  return 8;
}


int read_HSS1 (void *dest, uint8_t *buf, int offset, int buf_size) {
  HSS1_t *my_info = (HSS1_t *) dest;
  uint8_t temp_8bit_var;


  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridSystemOBDRelatedDTCStatus = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridSystemStopIndicator = (temp_8bit_var >> 4) & 0x03;
  my_info->HybridSystemOverheatIndicator = (temp_8bit_var >> 2) & 0x03;
  my_info->HybridSystemWarningIndicator = temp_8bit_var & 0x03;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridSystemMotorOverspeedIndicator = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridSystemServiceIndicator = (temp_8bit_var >> 4) & 0x03;
  my_info->HybridSystemEngineAssistStatus = (temp_8bit_var >> 2) & 0x03;
  my_info->PropulsionSystemActive = temp_8bit_var & 0x03;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridSystemInitializationIndicator = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridSystemRegenerativeBrakingIndicator = (temp_8bit_var >> 4) & 0x03;
  my_info->HybridSystemElectricAlternatorIndicator = (temp_8bit_var >> 2) & 0x03;
  my_info->HybridSystemMotorOverspeedAudibleAlarm = temp_8bit_var & 0x03;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->unused13 = (temp_8bit_var >> 6) & 0x03;
  my_info->StoredEnergySourceIncreasingModeAllowed = (temp_8bit_var >> 4) & 0x03;
  my_info->StoredEnergySourceOnlyModeAllowed = (temp_8bit_var >> 2) & 0x03;
  my_info->HybridSystemHighVoltageExposureIndicator = temp_8bit_var & 0x03;
  my_info->StoredEnergySourceLevel = buf[offset++ % buf_size];

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridPropulsionModeTransitionStatus = (temp_8bit_var >> 4) & 0x0f;
  my_info->HybridPropulsionModeStatus = temp_8bit_var & 0x0f;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->unused14 = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridSystemPropulsionDisableStatus = (temp_8bit_var >> 4) & 0x03;
  my_info->ExternalEnergySourceConnectionStatus = temp_8bit_var & 0x0f;
  my_info->unused15 = buf[offset++ % buf_size];
  return 8;
#pragma MESSAGE DISABLE C12056  //debug info incorrect because of optimization or inline assembler
}


int write_HSS1 (uint8_t *can_data, void *src) {
  HSS1_t *my_info = (HSS1_t *) src;
  int offset = 0;
  int buf_size = 8;
  uint8_t temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridSystemOBDRelatedDTCStatus & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridSystemStopIndicator & 0x03) << 4; 
  temp_8bit_var |= (my_info->HybridSystemOverheatIndicator & 0x03) << 2; 
  temp_8bit_var |= my_info->HybridSystemWarningIndicator & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridSystemMotorOverspeedIndicator & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridSystemServiceIndicator & 0x03) << 4; 
  temp_8bit_var |= (my_info->HybridSystemEngineAssistStatus & 0x03) << 2; 
  temp_8bit_var |= my_info->PropulsionSystemActive & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridSystemInitializationIndicator & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridSystemRegenerativeBrakingIndicator & 0x03) << 4; 
  temp_8bit_var |= (my_info->HybridSystemElectricAlternatorIndicator & 0x03) << 2; 
  temp_8bit_var |= my_info->HybridSystemMotorOverspeedAudibleAlarm & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->unused13 & 0x03) << 6; 
  temp_8bit_var |= (my_info->StoredEnergySourceIncreasingModeAllowed & 0x03) << 4; 
  temp_8bit_var |= (my_info->StoredEnergySourceOnlyModeAllowed & 0x03) << 2; 
  temp_8bit_var |= my_info->HybridSystemHighVoltageExposureIndicator & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->StoredEnergySourceLevel;
  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridPropulsionModeTransitionStatus & 0x0F) << 4; 
  temp_8bit_var |= my_info->HybridPropulsionModeStatus & 0x0f;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->unused14 & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridSystemPropulsionDisableStatus & 0x03) << 4; 
  temp_8bit_var |= my_info->ExternalEnergySourceConnectionStatus & 0x0f;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->unused15;
  return 8;
}


int read_HSI1 (void *dest, uint8_t *buf, int offset, int buf_size) {
  HSI1_t *my_info = (HSI1_t *) dest;
  uint8_t temp_8bit_var;


  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridSystemOffBoardChargerConnectionStatus = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridSystemPowerElectronicsCoolantLevelSwitch = (temp_8bit_var >> 4) & 0x03;
  my_info->HybridSystemPropulsionCoolantLevelSwitch = (temp_8bit_var >> 2) & 0x03;
  my_info->HybridSystemProtectionOverrideSwitch = temp_8bit_var & 0x03;

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->HybridSystemShutdownSwitch = (temp_8bit_var >> 6) & 0x03;
  my_info->HybridSystemPropulsionDisableSwitch = (temp_8bit_var >> 4) & 0x03;
  my_info->HybridSystemBrakePedalRegenerativeBrakingDisableSwitch = (temp_8bit_var >> 2) & 0x03;
  my_info->HybridSystemRegenerativeBrakingDisableSwitch = temp_8bit_var & 0x03;
  my_info->HybridSystemCoastingRegenerativeBrakingLevelSelector = buf[offset++ % buf_size];

  temp_8bit_var = buf[offset++ % buf_size];
  my_info->unused16 = (temp_8bit_var >> 4) & 0x0f;
  my_info->PowerElectronicsCoolantFillSwitch = (temp_8bit_var >> 2) & 0x03;
  my_info->PropulsionMotorCoolantFillSwitch = temp_8bit_var & 0x03;
  my_info->unused17 = read_int16_le(buf, &offset, buf_size);
  my_info->unused18 = read_int16_le(buf, &offset, buf_size);
  return 8;
#pragma MESSAGE DISABLE C12056  //debug info incorrect because of optimization or inline assembler
}


int write_HSI1 (uint8_t *can_data, void *src) {
  HSI1_t *my_info = (HSI1_t *) src;
  int offset = 0;
  int buf_size = 8;
  uint8_t temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridSystemOffBoardChargerConnectionStatus & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridSystemPowerElectronicsCoolantLevelSwitch & 0x03) << 4; 
  temp_8bit_var |= (my_info->HybridSystemPropulsionCoolantLevelSwitch & 0x03) << 2; 
  temp_8bit_var |= my_info->HybridSystemProtectionOverrideSwitch & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->HybridSystemShutdownSwitch & 0x03) << 6; 
  temp_8bit_var |= (my_info->HybridSystemPropulsionDisableSwitch & 0x03) << 4; 
  temp_8bit_var |= (my_info->HybridSystemBrakePedalRegenerativeBrakingDisableSwitch & 0x03) << 2; 
  temp_8bit_var |= my_info->HybridSystemRegenerativeBrakingDisableSwitch & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  can_data[offset++ % buf_size] = my_info->HybridSystemCoastingRegenerativeBrakingLevelSelector;
  temp_8bit_var = 0;
  temp_8bit_var |= (my_info->unused16 & 0x0F) << 4; 
  temp_8bit_var |= (my_info->PowerElectronicsCoolantFillSwitch & 0x03) << 2; 
  temp_8bit_var |= my_info->PropulsionMotorCoolantFillSwitch & 0x03;
  can_data[offset++ % buf_size] = temp_8bit_var;

  write_int16_le(my_info->unused17, can_data, &offset, buf_size);
  write_int16_le(my_info->unused18, can_data, &offset, buf_size);
  return 8;
}


