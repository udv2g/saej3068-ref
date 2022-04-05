#include "lock.h"
#include "hardware.h"
#include "scheduler.h"
#include "derivative.h"
#include "types.h"
#include "sci.h"
#include "globals.h"
#include "config.h"

// 0 for locked and 1 for undefined

static lock_status_t lockStatus[2] = {unknown, unknown};
static bool statusMismatch[2] = {FALSE, FALSE};

////////////////////////////////////////////////////
// Status Functions
////////////////////////////////////////////////////
#pragma INLINE
lock_status_t getLockStatus(uint8_t ch) {
  //PrintConsoleString("Lock status is ", 0);
  //PrintConsoleHex(lockStatus[ch]);
  //PrintConsoleString("\r\n", 0); 
  return lockStatus[ch];
}

#pragma INLINE
bool getIsLocked(uint8_t ch) {
  return (lockStatus[ch] == locked) || (lockStatus[ch] == presumedLocked);
}

#if INLET_LOCK_TYPE == NONE

#pragma INLINE 
lock_status_t getAndVerifyLockStatus(uint8_t ch) {
  return lockStatus[ch];
}
#endif

#if INLET_LOCK_TYPE == FOUR_WIRE
lock_status_t getAndVerifyLockStatus(uint8_t ch) {
  switch(lockStatus[ch])  {
    case locking:
    case unlocking:
      //PrintConsoleString("--\r\n",0);
      return lockStatus[ch];
      break;  //technically reduncant
    case locked:
    case presumedLocked:
      if (getSenseSignalValue(ch))  {      //is unlocked
        PrintConsoleString("Channel ",0);
        PrintConsoleChar( ch? 'B': 'A' );
        PrintConsoleString(" unexpectedly UNLOCKED\r\n",0);
        lockStatus[ch] = presumedUnlocked;
        statusMismatch[ch] = TRUE;
      }
      return lockStatus[ch];
      break;
    case unlocked:
    case presumedUnlocked:
      if (!getSenseSignalValue(ch))  {      //is locked
        PrintConsoleString("Channel ",0);
        PrintConsoleChar( ch? 'B': 'A' );
        PrintConsoleString(" unexpectedly LOCKED\r\n",0);
        lockStatus[ch] = locked;
        statusMismatch[ch] = TRUE;
      }
      return lockStatus[ch];    
      break;
  }
  return lockStatus[ch];
}
#endif

uint32_t verifyLockAStatus(void *a)  {
  (void)getAndVerifyLockStatus(A);
  return LOCK_CHECK_DELAY;
}

uint32_t verifyLockBStatus(void *a)  {
  (void)getAndVerifyLockStatus(B);
  return LOCK_CHECK_DELAY;
}

#pragma INLINE
bool getLockStatusMismatch(uint8_t ch)  {
  return statusMismatch[ch];
}

////////////////////////////////////////////////////
// Functions to set pins
////////////////////////////////////////////////////
void startDrivingLock(uint8_t ch) {
  lockStatus[ch] = locking;
  // Forward
  // IN1, IN3 1
  // IN2, IN4 0
  if (!ch) {
    RELAY_CONTROL_A_PLUS  = 1;
    RELAY_CONTROL_A_MINUS = 0;
  } else {
    RELAY_CONTROL_B_PLUS  = 1;
    RELAY_CONTROL_B_MINUS = 0;
  }
}

void startDrivingUnlock(uint8_t ch) {
  lockStatus[ch] = unlocking;
  // Reverse
  // IN1, IN3 0
  // IN2, IN4 1
  if (!ch) {
    RELAY_CONTROL_A_PLUS  = 0;
    RELAY_CONTROL_A_MINUS = 1;
  } else {
    RELAY_CONTROL_B_PLUS  = 0;
    RELAY_CONTROL_B_MINUS = 1;
  }
}

uint32_t endDrivingA(void *a) {
  // Coast
  RELAY_CONTROL_A_PLUS  = 0;
  RELAY_CONTROL_A_MINUS = 0;

  return 0;
}

uint32_t endDrivingB(void *a) {
  // Coast
  RELAY_CONTROL_B_PLUS  = 0;
  RELAY_CONTROL_B_MINUS = 0;

  return 0;
}

#define endDriving(ch) ((ch) ? endDrivingB : endDrivingA)

////////////////////////////////////////////////////
// Presumed Functions
////////////////////////////////////////////////////

uint32_t setPresumedLockedA(void *a) {
  // if locked
  if (!UC_SENSE_SIGNAL_A_LOCK) {
    lockStatus[A] = locked;
    statusMismatch[A] = FALSE;
    PrintConsoleString("Successfully locked A\r\n", 0);
  } else {
    PrintConsoleString("Retrying to lock A\r\n", 0);
    schedule_and_reset(RETRY_DELAY, retryLockA, NULL);
  }
  return 0;
}

uint32_t setPresumedLockedB(void *a) {
  // if locked
  if (!UC_SENSE_SIGNAL_B_LOCK) {
    lockStatus[B] = locked;
    statusMismatch[B] = FALSE;
    PrintConsoleString("Successfully locked B\r\n", 0);
  } else {
    PrintConsoleString("Retrying to lock B\r\n", 0);
    schedule_and_reset(RETRY_DELAY, retryLockB, NULL);
  }
  return 0;
}

#define setPresumedLocked(ch) ((ch) ? setPresumedLockedB : setPresumedLockedA)

uint32_t setPresumedUnlockedA(void *a) {
  // if pin says not locked and disconnected, then actually unlocked
  if (UC_SENSE_SIGNAL_A_LOCK && (IEC_Prox_Voltage[A] == IEC_DISCONNECTED)) {
    lockStatus[A] = unlocked;
    statusMismatch[A] = FALSE;
    PrintConsoleString("Succesfully unlocked A\r\n", 0);
  }
  // if pin reads locked then retry unlocking at high rate
  else if (!UC_SENSE_SIGNAL_A_LOCK) {
    PrintConsoleString("Retrying to unlock A\r\n", 0);
    schedule_and_reset(RETRY_DELAY, retryUnlockA, NULL);
  }
  // pin reads not locked and not disconnected then continue to retry unlocking at low rate
  else {
    lockStatus[A] = presumedUnlocked;
    statusMismatch[A] = FALSE;
    PrintConsoleString("A is presumed unlocked \r\n", 0);
    schedule_and_reset(UNVERIFIED_UNLOCK_DELAY, retryUnlockA, NULL);
  }
  return 0;
}

uint32_t setPresumedUnlockedB(void *a) {
  if (UC_SENSE_SIGNAL_B_LOCK && (IEC_Prox_Voltage[B] == IEC_DISCONNECTED)) {
    lockStatus[B] = unlocked;
    statusMismatch[B] = FALSE;
    PrintConsoleString("Succesfully unlocked B\r\n", 0);
  } else if (!UC_SENSE_SIGNAL_B_LOCK) {
    PrintConsoleString("Retrying to unlock B\r\n", 0);
    schedule_and_reset(RETRY_DELAY, retryUnlockB, NULL);
  } else {
    lockStatus[B] = presumedUnlocked;
    statusMismatch[B] = FALSE;
    PrintConsoleString("B is presumed unlocked \r\n", 0);
    schedule_and_reset(UNVERIFIED_UNLOCK_DELAY, retryUnlockB, NULL);
  }
  return 0;
}

#define setPresumedUnlocked(ch) ((ch) ? setPresumedUnlockedB : setPresumedUnlockedA)

////////////////////////////////////////////////////
// Retry Functions
////////////////////////////////////////////////////

uint32_t retryLockA(void *a) {
  if (IEC_Prox_Voltage[A] != IEC_DISCONNECTED)  { 
    startDrivingLock(A);
    schedule_and_reset(DRIVE_TIME, endDrivingA, NULL);
    schedule_and_reset(DRIVE_TIME, setPresumedLockedA, NULL);
  } else  {
    lockStatus[A] = unlocked;
  }
  return 0;
}

uint32_t retryLockB(void *a) {
  if (IEC_Prox_Voltage[B] != IEC_DISCONNECTED)  {
    startDrivingLock(B);
    schedule_and_reset(DRIVE_TIME, endDrivingB, NULL);
    schedule_and_reset(DRIVE_TIME, setPresumedLockedB, NULL);
  } else  {
    lockStatus[B] = unlocked;
  }
  return 0;
}

#define retryLock(ch) ((ch) ? retryLockB : retryLockA)

uint32_t retryUnlockA(void *a) {
  startDrivingUnlock(A);
  schedule_and_reset(DRIVE_TIME, endDrivingA, NULL);
  schedule_and_reset(DRIVE_TIME, setPresumedUnlockedA, NULL);
  return 0;
}

uint32_t retryUnlockB(void *a) {
  startDrivingUnlock(B);
  schedule_and_reset(DRIVE_TIME, endDrivingB, NULL);
  schedule_and_reset(DRIVE_TIME, setPresumedUnlockedB, NULL);
  return 0;
}

#define retryUnlock(ch) ((ch) ? retryUnlockB : retryUnlockA)

////////////////////////////////////////////////////
// Main lock and unlock functions
////////////////////////////////////////////////////

#if INLET_LOCK_TYPE == NONE
void lock(uint8_t ch) {
  lockStatus[ch] = locked;
}

void unlock(uint8_t ch) {
  lockStatus[ch] = unlocked;
}
#endif

#if INLET_LOCK_TYPE == FOUR_WIRE 
void lock(uint8_t ch) {
  PrintConsoleString("Lock ", 0);
  if (ch) {
    PrintConsoleString("B", 0);
  } else {
    PrintConsoleString("A", 0);
  }
  PrintConsoleString("\r\n", 0)

  unschedule(setPresumedUnlocked(ch));
  unschedule(retryUnlock(ch));

  startDrivingLock(ch);
  schedule_if_unscheduled(DRIVE_TIME, endDriving(ch), NULL);
  schedule_if_unscheduled(DRIVE_TIME, setPresumedLocked(ch), NULL);
}

void unlock(uint8_t ch) {
  PrintConsoleString("Unlock ", 0);
  if (ch) {
    PrintConsoleString("B", 0);
  } else {
    PrintConsoleString("A", 0);
  }
  PrintConsoleString("\r\n", 0)

  unschedule(setPresumedLocked(ch));
  unschedule(retryLock(ch));

  startDrivingUnlock(ch);
  schedule_if_unscheduled(DRIVE_TIME, endDriving(ch), NULL);
  schedule_if_unscheduled(DRIVE_TIME, setPresumedUnlocked(ch), NULL);
}
#endif

void lock_if_unlocked(uint8_t ch) {
  // only lock if state is unlocked or presumedUnlocked
  if ((getAndVerifyLockStatus(ch) == unlocked) || (getAndVerifyLockStatus(ch) == presumedUnlocked)) lock(ch);
}

void unlock_if_locked(uint8_t ch) {
  // only unlock if state is locked or presumedLocked
  if ((getAndVerifyLockStatus(ch) == locked) || (getAndVerifyLockStatus(ch) == presumedLocked)) unlock(ch);
}
