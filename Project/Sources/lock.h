#include "types.h"

#ifndef _LOCK_H
#define _LOCK_H

#define DRIVE_TIME              500
#define RETRY_DELAY             1000
#define UNVERIFIED_UNLOCK_DELAY 5000

typedef enum {
  unknown,
  locked,
  unlocked,
  locking,
  unlocking,
  presumedLocked,
  presumedUnlocked
} lock_status_t;

#define getSenseSignalValue(ch) ((ch) ? UC_SENSE_SIGNAL_B_LOCK : UC_SENSE_SIGNAL_A_LOCK)

lock_status_t getLockStatus(uint8_t);
bool getIsLocked(uint8_t ch);

bool getLockStatusMismatch(uint8_t ch);

void startDrivingLock(uint8_t);
void startDrivingUnlock(uint8_t);
uint32_t endDrivingA(void *);
uint32_t endDrivingB(void *);

uint32_t setPresumedLockedA(void *);
uint32_t setPresumedLockedB(void *);
uint32_t setPresumedUnlockedA(void *);
uint32_t setPresumedUnlockedB(void *);

uint32_t retryLockA(void *);
uint32_t retryLockB(void *);
uint32_t retryUnlockA(void *);
uint32_t retryUnlockB(void *);

uint32_t verifyLockAStatus(void *);
uint32_t verifyLockBStatus(void *);

void lock(uint8_t);
void lock_if_unlocked(uint8_t);
void unlock(uint8_t);
void unlock_if_locked(uint8_t);

#endif