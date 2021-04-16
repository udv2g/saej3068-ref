
#ifndef __J1939_SIGNALS_H__
#define __J1939_SIGNALS_H__

#include "types.h"

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the supply frequency.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* 50 Hz */
  J1939_SPN13008_FIFTYHZ                        = 0x0000,

  /* 60 Hz */
  J1939_SPN13008_SIXTYHZ                        = 0x0002,

  /* Error */
  J1939_SPN13008_ERROR                          = 0x00FE,

  /* Not available */
  J1939_SPN13008_NOTAVAILABLE                   = 0x00FF,
} SPN13008_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Command to engage or disengage the locking mechanism fitted to this
 * EVSE connector to the vehicle.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Unlock Request */
  J1939_SPN12864_UNLOCK                         = 0x0000,

  /* Lock Request */
  J1939_SPN12864_LOCK                           = 0x0001,

  /* Don't care / Take no action */
  J1939_SPN12864_NOACTION                       = 0x00FF,
} SPN12864_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the state of this EVSE Connector Lock (if present).
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Unlocked */
  J1939_SPN12863_UNLOCKED                       = 0x0000,

  /* Locked */
  J1939_SPN12863_LOCKED                         = 0x0001,

  /* In transition to/from Locked */
  J1939_SPN12863_INTRANSITION                   = 0x0002,

  /* No locking mechanism is available on this vehicle */
  J1939_SPN12863_NOLOCK                         = 0x0005,

  /* Error */
  J1939_SPN12863_ERROR                          = 0x0006,

  /* Not available */
  J1939_SPN12863_NOTAVAILABLE                   = 0x0007,
} SPN12863_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the state of a manual override switch on the vehicle, if
 * present. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Manual override not active */
  J1939_SPN12862_NOTOVERRIDEN                   = 0x0000,

  /* Manual override active */
  J1939_SPN12862_OVERRIDEN                      = 0x0001,

  /* Error */
  J1939_SPN12862_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN12862_NOTAVAILABLE                   = 0x0003,
} SPN12862_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the Release Latch status of this EVSE Connector.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Latch released (S3 open) */
  J1939_SPN12861_RELEASED                       = 0x0000,

  /* Latch engaged (S3 closed) */
  J1939_SPN12861_ENGAGED                        = 0x0001,

  /* Error */
  J1939_SPN12861_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN12861_NOTAVAILABLE                   = 0x0003,
} SPN12861_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the Hybrid System Shutdown Request state. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off; hybrid system may operate normally */
  J1939_SPN7560_NORMAL                         = 0x0000,

  /* On; hybrid system functionality is not allowed */
  J1939_SPN7560_SHUTDOWN                       = 0x0001,

  /* Don't Care / Take No Action */
  J1939_SPN7560_NOACTION                       = 0x0003,
} SPN7560_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the hybrid system regenerative braking disable request
 * state. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Regenerative braking disable request is not active.  Regenerative
   * braking is allowed. */
  J1939_SPN7559_REGENENABLED                   = 0x0000,

  /* Regenerative braking disable request is active.  Regenerative braking
   * is not allowed. */
  J1939_SPN7559_REGENDISABLED                  = 0x0001,

  /* Don't Care / Take No Action */
  J1939_SPN7559_NOACTION                       = 0x0003,
} SPN7559_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the Hybrid System Disable Request state. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off; hybrid propulsion is allowed */
  J1939_SPN7558_HYBRIDENABLED                  = 0x0000,

  /* On; hybrid propulsion is not allowed */
  J1939_SPN7558_HYBRIDDISABLED                 = 0x0001,

  /* Don't Care / Take No Action */
  J1939_SPN7558_NOACTION                       = 0x0003,
} SPN7558_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the hybrid system protection override request state. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Not active */
  J1939_SPN7557_NOTACTIVE                      = 0x0000,

  /* Active */
  J1939_SPN7557_ACTIVE                         = 0x0001,

  /* Don't Care / Take No Action */
  J1939_SPN7557_NOACTION                       = 0x0003,
} SPN7557_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Hybrid Propulsion Mode Request is the operator intended propulsion
 * mode.  ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* No mode requested */
  J1939_SPN7889_NOREQUEST                      = 0x0000,

  /* Stored Energy Source Sustaining */
  J1939_SPN7889_SUSTAINING                     = 0x0001,

  /* Stored Energy Source Increasing */
  J1939_SPN7889_INCREASING                     = 0x0002,

  /* Stored Energy Source Depleting */
  J1939_SPN7889_DEPLETING                      = 0x0003,

  /* Stored Energy Source Offline */
  J1939_SPN7889_OFFLINE                        = 0x0004,

  /* Stored Energy Source Only */
  J1939_SPN7889_ONLY                           = 0x0005,

  /* Error */
  J1939_SPN7889_ERROR                          = 0x000E,

  /* Not available */
  J1939_SPN7889_NOTAVAILABLE                   = 0x000F,
} SPN7889_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Operator Vehicle Mode Request is the operator intended vehicle mode. 
 * ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off */
  J1939_SPN7888_SHUTDOWN                       = 0x0000,

  /* Low Voltage Accessory */
  J1939_SPN7888_LOWVOLTAGEACCESSORY            = 0x0001,

  /* Stored Energy Source Active */
  J1939_SPN7888_STOREDENERGYSOURCEACTIVE       = 0x0002,

  /* Propulsion Active */
  J1939_SPN7888_PROPULSIONACTIVE               = 0x0003,

  /* Error */
  J1939_SPN7888_ERROR                          = 0x000E,

  /* Not available */
  J1939_SPN7888_NOTAVAILABLE                   = 0x000F,
} SPN7888_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * The type of energy source (EVSE) currently connected as specified in
 * SPN 7890.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* AC Energy source */
  J1939_SPN13154_ACSOURCE                       = 0x0000,

  /* DC Energy source */
  J1939_SPN13154_DCSOURCE                       = 0x0001,

  /* Don't Care / Take No Action */
  J1939_SPN13154_NOACTION                       = 0x0003,
} SPN13154_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the sender's consent to charge the system's HVES
 * (high-voltage energy storage) from EVSE...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Charging of HVES system is not allowed (i.e. vetoed) */
  J1939_SPN10148_DISALLOWED                     = 0x0000,

  /* Charging of HVES system is allowed */
  J1939_SPN10148_ALLOWED                        = 0x0001,

  /* Not available */
  J1939_SPN10148_NOTAVAILABLE                   = 0x0003,
} SPN10148_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * External Energy Source Connection Demand indicates how the hybrid
 * system should engage with...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* No Connection */
  J1939_SPN7890_NOCONNECTION                   = 0x0000,

  /* Perform Connection 1 Verification */
  J1939_SPN7890_VERIFICATION1                  = 0x0001,

  /* Energy Drain or Source Connection 1 */
  J1939_SPN7890_DRAINSOURCE1                   = 0x0002,

  /* Energy Source Connection 1 */
  J1939_SPN7890_SOURCE1                        = 0x0003,

  /* Energy Drain Connection 1 */
  J1939_SPN7890_DRAIN1                         = 0x0004,

  /* Perform Connection 2 Verification */
  J1939_SPN7890_VERIFICATION2                  = 0x0005,

  /* Energy Drain or Source Connection 2 */
  J1939_SPN7890_DRAINSOURCE2                   = 0x0006,

  /* Energy Source Connection 2 */
  J1939_SPN7890_SOURCE2                        = 0x0007,

  /* Energy Drain Connection 2 */
  J1939_SPN7890_DRAIN2                         = 0x0008,

  /* Disconnect Request */
  J1939_SPN7890_DISCONNECT                     = 0x000E,

  /* No Request / Take No Action */
  J1939_SPN7890_NOREQUEST                      = 0x000F,
} SPN7890_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from hybrid system indicating the status of OBD related DTCs
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid System does not have an active OBD related DTC */
  J1939_SPN6810_NOOBDDTC                       = 0x0000,

  /* Hybrid System has an active OBD related DTC */
  J1939_SPN6810_OBCDTC                         = 0x0001,

  /* Not available */
  J1939_SPN6810_NOTAVAILABLE                   = 0x0003,
} SPN6810_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from a hybrid system indicating that some aspect of its
 * operation is not functioning correctly...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid System Stop Indicator is off */
  J1939_SPN5874_STOPINDCOFF                    = 0x0000,

  /* Hybrid System Stop Indicator is on continuously */
  J1939_SPN5874_STOPINDCCONT                   = 0x0001,

  /* Hybrid System Stop Indicator is flashing */
  J1939_SPN5874_STOPINDCFLASH                  = 0x0002,

  /* Not available */
  J1939_SPN5874_NOTAVAILABLE                   = 0x0003,
} SPN5874_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from a hybrid system indicating that at least one of its
 * monitored temperatures is above normal acceptable limits...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid System Temperature Indicator is off */
  J1939_SPN5873_TEMPINDCOFF                    = 0x0000,

  /* Hybrid System Temperature Indicator is on continuously */
  J1939_SPN5873_TEMPINDCCONT                   = 0x0001,

  /* Hybrid System Temperature Indicator is flashing */
  J1939_SPN5873_TEMPINDCFLASH                  = 0x0002,

  /* Not available */
  J1939_SPN5873_NOTAVAILABLE                   = 0x0003,
} SPN5873_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from a hybrid system indicating that some aspect of its
 * operation is not functioning correctly...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid System Warning Indicator is off */
  J1939_SPN5872_WARNINDCOFF                    = 0x0000,

  /* Hybrid System Warning Indicator is on continuously */
  J1939_SPN5872_WARNINDCCONT                   = 0x0001,

  /* Hybrid System Warning Indicator is flashing */
  J1939_SPN5872_WARNINDCFLASH                  = 0x0002,

  /* Not available */
  J1939_SPN5872_NOTAVAILABLE                   = 0x0003,
} SPN5872_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from the hybrid system indicating that the hybrid system motor
 * is exceeding maximum speed limit.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid System Motor Overspeed Indicator is off */
  J1939_SPN7449_OVERSPEEDINDCOFF               = 0x0000,

  /* Hybrid System Motor Overspeed Indicator is on continuously */
  J1939_SPN7449_OVERSPEEDINDCCONT              = 0x0001,

  /* Hybrid System Motor Overspeed Indicator is flashing */
  J1939_SPN7449_OVERSPEEDINDCFLASH             = 0x0002,

  /* Not available */
  J1939_SPN7449_NOTAVAILABLE                   = 0x0003,
} SPN7449_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from the hybrid system indicating that the hybrid system or one
 * of its components requires servicing...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid Service Indicator is off */
  J1939_SPN7448_SERVINDCOFF                    = 0x0000,

  /* Hybrid Service Indicator is on continuously */
  J1939_SPN7448_SERVINDCCONT                   = 0x0001,

  /* Hybrid Service Indicator is flashing */
  J1939_SPN7448_SERVINDCFLASH                  = 0x0002,

  /* Not available */
  J1939_SPN7448_NOTAVAILABLE                   = 0x0003,
} SPN7448_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Provides the engine an indication of when the hybrid system is not
 * mechanically assisting rotation...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Hybrid system is not mechanically assisting engine rotation */
  J1939_SPN7418_HYBRIDON                       = 0x0000,

  /* Hybrid system may or may not mechanically assist engine rotation */
  J1939_SPN7418_HYBRIDMAYBE                    = 0x0001,

  /* Error */
  J1939_SPN7418_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7418_NOTAVAILABLE                   = 0x0003,
} SPN7418_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates when the hybrid system or electric vehicle system is ready
 * to provide or is actively providing propulsion...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Propulsion System is not ready to move vehicle if commanded by
   * operator */
  J1939_SPN7315_PROPNOTREADY                   = 0x0000,

  /* Propulsion System is ready to move, or is moving the vehicle as
   * commanded by operator */
  J1939_SPN7315_PROPREADY                      = 0x0001,

  /* Not available */
  J1939_SPN7315_NOTAVAILABLE                   = 0x0003,
} SPN7315_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal indicating when the hybrid system or electric vehicle system is
 * initialized and ready to start the engine...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* System Initialization Indicator is not active */
  J1939_SPN7453_SYSTEMNOTINITIALIZED           = 0x0000,

  /* System Initialization Indicator is active */
  J1939_SPN7453_SYSTEMINITIALIZED              = 0x0001,

  /* Error */
  J1939_SPN7453_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7453_NOTAVAILABLE                   = 0x0003,
} SPN7453_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from the hybrid system indicating when regenerative braking is
 * active.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Regenerative braking is inactive, but not disabled */
  J1939_SPN7452_INACTIVE                       = 0x0000,

  /* Regenerative braking is active */
  J1939_SPN7452_ACTIVE                         = 0x0001,

  /* Regenerative braking is disabled due to normal operating conditions or
   * because a faulted condition is active */
  J1939_SPN7452_DISABLED                       = 0x0002,

  /* Not available */
  J1939_SPN7452_NOTAVAILABLE                   = 0x0003,
} SPN7452_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from the hybrid system indicating that the electric alternator
 * is failed or needs servicing. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Alternator Indicator is off */
  J1939_SPN7451_ALTERNATORINDCOFF              = 0x0000,

  /* Alternator Indicator is on */
  J1939_SPN7451_ALTERNATORINDCON               = 0x0001,

  /*  Alternator Indicator is flashing */
  J1939_SPN7451_ALTERNATORINDCFLASH            = 0x0002,

  /* Not available */
  J1939_SPN7451_NOTAVAILABLE                   = 0x0003,
} SPN7451_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Signal from the hybrid system indicating that the overspeed audible
 * alarm should be activated.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Motor Overspeed Audible Alarm is off */
  J1939_SPN7450_NOOVERSPEEDALRM                = 0x0000,

  /* Motor Overspeed Audible Alarm is on */
  J1939_SPN7450_OVERSPEEDALRM                  = 0x0001,

  /* Error */
  J1939_SPN7450_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7450_NOTAVAILABLE                   = 0x0003,
} SPN7450_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Stored Energy Source Increasing Mode Allowed is sent by the Hybrid
 * System controller to indicate when the Stored Energy...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Mode NOT allowed */
  J1939_SPN7894_MODENOTALLOWED                 = 0x0000,

  /* Mode allowed */
  J1939_SPN7894_MODEALLOWED                    = 0x0001,

  /* Error */
  J1939_SPN7894_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7894_NOTAVAILABLE                   = 0x0003,
} SPN7894_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Stored Energy Source Only Mode Allowed is sent by the Hybrid System
 * controller to indicate when Stored Energy Source...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Mode NOT allowed */
  J1939_SPN7893_MODENOTALLOWED                 = 0x0000,

  /* Mode allowed */
  J1939_SPN7893_MODEALLOWED                    = 0x0001,

  /* Error */
  J1939_SPN7893_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7893_NOTAVAILABLE                   = 0x0003,
} SPN7893_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * This signal indicates the condition and state of the the hybrid system
 * or electric vehicle system high voltage exposure...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* System is operational and intact; no potential high voltage exposure
   * has been detected */
  J1939_SPN7454_SAFE                           = 0x0000,

  /* System is operational and has detected a compromise; potential high
   * voltage exposure exists */
  J1939_SPN7454_UNSAFE                         = 0x0001,

  /* Error */
  J1939_SPN7454_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7454_NOTAVAILABLE                   = 0x0003,
} SPN7454_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Hybrid Propulsion Mode Transition Status is sent by the Hybrid System
 * controller to indicate the reason for a mode...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* No transition requested */
  J1939_SPN7897_NOTRANSITION                   = 0x0000,

  /* Transition requested and in process */
  J1939_SPN7897_TRANSITIONINPROC               = 0x0001,

  /* Requested mode denied - Requested mode not available */
  J1939_SPN7897_MODEUNAVAIL                    = 0x0002,

  /* Requested mode denied - Vehicle Speed unacceptable for requested mode */
  J1939_SPN7897_SPEEDUNACCEPTABLE              = 0x0003,

  /* Requested mode denied - HVES State of Charge unacceptable for
   * requested mode */
  J1939_SPN7897_SOCUNACCEPTABLE                = 0x0004,

  /* Requested mode denied - Temporary limit exceeded. The temporary limit
   * may be bounded by elapsed time, distance travelled, driving
   * conditions, or something else that the manufacturer has specified. */
  J1939_SPN7897_LIMITEXCEEDED                  = 0x0005,

  /* Requested mode denied - HVES temporary limit threshold exceeded for
   * one or more HVES */
  J1939_SPN7897_LIMITTHRESHEXCEEDED            = 0x0006,

  /* Requested mode denied - reason not specified */
  J1939_SPN7897_DENIED                         = 0x000D,

  /* Error */
  J1939_SPN7897_ERROR                          = 0x000E,

  /* No Request / Take No Action */
  J1939_SPN7897_NOREQUEST                      = 0x000F,
} SPN7897_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Hybrid Propulsion Mode Status is the current Hybrid System Controller
 * propulsion mode.  ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* No mode requested */
  J1939_PGN7896_NOREQUEST                      = 0x0000,

  /* Stored Energy Source Sustaining */
  J1939_PGN7896_SUSTAINING                     = 0x0001,

  /* Stored Energy Source Increasing */
  J1939_PGN7896_INCREASING                     = 0x0002,

  /* Stored Energy Source Depleting */
  J1939_PGN7896_DEPLETING                      = 0x0003,

  /* Stored Energy Source Offline */
  J1939_PGN7896_OFFLINE                        = 0x0004,

  /* Stored Energy Source Only */
  J1939_PGN7896_SOURCEONLY                     = 0x0005,

  /* Error */
  J1939_PGN7896_ERROR                          = 0x000E,

  /* Not available */
  J1939_PGN7896_NOTAVAILABLE                   = 0x000F,
} PGN7896_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates if the hybrid system is in a state where propulsion is not
 * available. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Propulsion not disabled */
  J1939_SPN8267_ENABLED                        = 0x0000,

  /* Propulsion is disabled */
  J1939_SPN8267_DISABLED                       = 0x0001,

  /* Error */
  J1939_SPN8267_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN8267_NOTAVAILABLE                   = 0x0003,
} SPN8267_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * External Energy Source Connection Status provides feedback to the
 * External Energy Source Connection Demand...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* No Connection */
  J1939_SPN7898_NOCONNECTION                   = 0x0000,

  /* Connection 1 - Error (Verification failed) */
  J1939_SPN7898_FAILED1                        = 0x0001,

  /* Connection 1 - Verification in Process */
  J1939_SPN7898_VERIFICATION1                  = 0x0002,

  /* Connection 1 - Energy Source and Drain */
  J1939_SPN7898_DRAINSOURCE1                   = 0x0003,

  /*  Connection 1 - Energy Source */
  J1939_SPN7898_SOURCE1                        = 0x0004,

  /* Connection 1 - Energy Drain */
  J1939_SPN7898_DRAIN1                         = 0x0005,

  /* Connection 2 - Error (Verification failed) */
  J1939_SPN7898_FAILED2                        = 0x0006,

  /* Connection 2 - Verification in Process */
  J1939_SPN7898_VERIFICATION2                  = 0x0007,

  /* Connection 2 - Energy Source and Drain */
  J1939_SPN7898_DRAINSOURCE2                   = 0x0008,

  /*  Connection 2 - Energy Source */
  J1939_SPN7898_SOURCE2                        = 0x0009,

  /* Connection 2 - Energy Drain */
  J1939_SPN7898_DRAIN2                         = 0x000A,

  /* Error */
  J1939_SPN7898_ERROR                          = 0x000E,

  /* Not available */
  J1939_SPN7898_NOTAVAILABLE                   = 0x000F,
} SPN7898_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the off-board plug-in charger connection status. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off-board charger is not connected */
  J1939_SPN7551_NOTCONNECTED                   = 0x0000,

  /* Off-board charger is connected */
  J1939_SPN7551_CONNECTED                      = 0x0001,

  /* Error */
  J1939_SPN7551_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7551_NOTAVAILABLE                   = 0x0003,
} SPN7551_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the coolant level switch position in the hybrid system power
 * electronics...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Coolant Level is not sufficient */
  J1939_SPN7550_COOLANTLOW                     = 0x0000,

  /* Coolant Level is sufficient */
  J1939_SPN7550_COOLANTGOOD                    = 0x0001,

  /* Error */
  J1939_SPN7550_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7550_NOTAVAILABLE                   = 0x0003,
} SPN7550_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the coolant level switch position in the hybrid system
 * propulsion...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Coolant Level is not sufficient */
  J1939_SPN7549_COOLANTLOW                     = 0x0000,

  /* Coolant Level is sufficient */
  J1939_SPN7549_COOLANTGOOD                    = 0x0001,

  /* Error */
  J1939_SPN7549_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7549_NOTAVAILABLE                   = 0x0003,
} SPN7549_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the Protection Override switch position.  This switch allows
 * the operator to override hybrid system protection...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Not Active */
  J1939_SPN7548_NOTACTIVE                      = 0x0000,

  /* Active */
  J1939_SPN7548_ACTIVE                         = 0x0001,

  /* Error */
  J1939_SPN7548_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7548_NOTAVAILABLE                   = 0x0003,
} SPN7548_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * When the operator enables this switch, all hybrid system functionality
 * is disabled including propulsion...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off; hybrid system may operate normally. */
  J1939_SPN7555_ENABLED                        = 0x0000,

  /* On; hybrid system functionality is not allowed. */
  J1939_SPN7555_DISABLED                       = 0x0001,

  /* Error */
  J1939_SPN7555_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7555_NOTAVAILABLE                   = 0x0003,
} SPN7555_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * When the operator enables this switch, the propulsion aspect of hybrid
 * system operation will be disabled. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off; Off; hybrid propulsion is allowed. */
  J1939_SPN7554_ENABLED                        = 0x0000,

  /* On; hybrid propulsion is not allowed. */
  J1939_SPN7554_DISABLED                       = 0x0001,

  /* Error */
  J1939_SPN7554_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7554_NOTAVAILABLE                   = 0x0003,
} SPN7554_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the brake pedal regenerative braking disable switch
 * position. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Brake pedal regenerative braking disable switch is off.  When this
   * switch is off, regenerative braking may be activated by brake pedal
   * application. */
  J1939_SPN7553_BRAKEPEDALREGEN                = 0x0000,

  /* Brake pedal regenerative braking disable switch is on.  When this
   * switch is on, regenerative braking shall not be activated by brake
   * pedal application. */
  J1939_SPN7553_NOBRAKEPEDALREGEN              = 0x0001,

  /* Error */
  J1939_SPN7553_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7553_NOTAVAILABLE                   = 0x0003,
} SPN7553_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the regenerative braking disable switch position. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Regenerative Braking Disable Switch is off.  Regenerative braking is
   * allowed. */
  J1939_SPN7552_REGENENABLED                   = 0x0000,

  /* Regenerative Braking  Disable Switch is on.  Regenerative braking is
   * not allowed. */
  J1939_SPN7552_REGENDISABLED                  = 0x0001,

  /* Error */
  J1939_SPN7552_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN7552_NOTAVAILABLE                   = 0x0003,
} SPN7552_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the coolant fill switch position for the propulsion motor
 * cooling system. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off */
  J1939_SPN8476_PUMPOFF                        = 0x0000,

  /* On */
  J1939_SPN8476_PUMPON                         = 0x0001,

  /* Error */
  J1939_SPN8476_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN8476_NOTAVAILABLE                   = 0x0003,
} SPN8476_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Indicates the coolant fill switch position for the power electronics
 * cooling system. ...
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
typedef enum {

  /* Off */
  J1939_SPN8475_PUMPOFF                        = 0x0000,

  /* On */
  J1939_SPN8475_PUMPON                         = 0x0001,

  /* Error */
  J1939_SPN8475_ERROR                          = 0x0002,

  /* Not available */
  J1939_SPN8475_NOTAVAILABLE                   = 0x0003,
} SPN8475_t;


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 64197-EVSE1 AC 3-Phase Load--This message from an HVESS Charger that
 * is connected to 3-Phase AC Electric Vehicle Supply (EVSE) 1.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_EVSE1AC3PL (419087616) // 0x18FAC500
typedef struct EVSE1AC3PL {
  /* 13009-Current presently being drawn from a single phase EVSE or from
   * L1 of a three phase supply.
   */
  uint16_t HVESS_Charger_RMS_current_L1;

  /* 13010-Current presently being drawn from L2 of a three phase supply.
   */
  uint16_t HVESS_Charger_RMS_current_L2;

  /* 13011-Current presently being drawn from L3 of a three phase supply.
   */
  uint16_t HVESS_Charger_RMS_current_L3;

  /* 13012-Current flowing through the neutral connection. ...
   */
  uint16_t HVESS_Charger_RMS_current_N;

} EVSE1AC3PL_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 64213-EVSE 1 AC Status 1--This message is sent by a CA that manages
 * the connection to an AC Electric Vehicle Supply Equipment (EVSE)
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_EVSE1ACS1 (419091712) // 0x18FAD500
typedef struct EVSE1ACS1 {
  /* 12865-Maximum AC RMS current that can be supplied by the EVSE on a
   * single phase AC supply or L1 of a 3-phase AC supply.
   */
  uint16_t EVSE_AC_RMS_CurrentLimitL1;

  /* 13003-Maximum AC RMS current that can be supplied by the EVSE on L2 of
   * a 3-phase AC supply.
   */
  uint16_t EVSE_AC_RMS_CurrentLimitL2;

  /* 13004-Maximum AC RMS current that can be supplied by the EVSE on L3 of
   * a 3-phase AC supply.
   */
  uint16_t EVSE_AC_RMS_CurrentLimitL3;

  /* 13005-Maximum AC RMS current that can carried on the neutral
   * connection from the EVSE.
   */
  uint16_t EVSE_AC_RMS_CurrentLimitN;

} EVSE1ACS1_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 64196-EVSE 1 AC Supply Voltage--This message is sent by a CA that
 * manages the connection to 3-phase AC Electric Vehicle Supply Equipment
 * (EVSE)
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_EVSE1ACSV (419087360) // 0x18FAC400
typedef struct EVSE1ACSV {
  /* 13006-Indicates the nominal RMS voltage between contacts L1 and
   * Neutral.
   */
  uint16_t SeNomVoltageL1N;

  /* 13007-Indicates the nominal line to line RMS voltage.  For single
   * phase supplies this is set to Not Available.
   */
  uint16_t SeNomVoltageLL;

  /* 13008-Indicates the supply frequency.
   */
  uint8_t SeFrequency;

  /*  
   */
  uint8_t unused;

  /*  
   */
  uint16_t unused1;

} EVSE1ACSV_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 21248-EVSE 1 Control 1--This PG carries SPs associated with the
 * control of the connection to the external power source
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_EVSE1C1 (408092672) // 0x18530000
typedef struct EVSE1C1 {
  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /*  
   */
  unsigned int unused2 : 4;

  /* 12864-Command to engage or disengage the locking mechanism fitted to
   * this EVSE connector to the vehicle.
   */
  unsigned int EVSE1_ConnectorLockCommand : 4;

  /*  
   */
  uint8_t unused3;

  /*  
   */
  uint16_t unused4;

  /*  
   */
  uint16_t unused5;

  /*  
   */
  uint16_t unused6;

} EVSE1C1_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 64214-EVSE 1 Status 1--This message is sent by the CA that manages the
 * connection to Electric Vehicle Supply Equipment (EVSE). This PG is
 * related to the physical connection and is generic to all types of EVSE
 * (AC or DC)
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_EVSE1S1 (419091968) // 0x18FAD600
typedef struct EVSE1S1 {
  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /*  
   */
  unsigned int unused7 : 1;

  /* 12863-Indicates the state of this EVSE Connector Lock (if present).
   */
  unsigned int EVSE1_ConnectorLockState : 3;

  /* 12862-Indicates the state of a manual override switch on the vehicle,
   * if present. ...
   */
  unsigned int EVSE1_ManualOverRide : 2;

  /* 12861-Indicates the Release Latch status of this EVSE Connector.
   */
  unsigned int EVSE1_ConnectorReleaseLatch : 2;

  /*  
   */
  uint8_t unused8;

  /*  
   */
  uint16_t unused9;

  /*  
   */
  uint16_t unused10;

  /*  
   */
  uint16_t unused12;

} EVSE1S1_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 *  
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_INLETPROXANDSEINFO (436207104) // 0x19FFFE00
typedef struct InletProxAndSeInfo {
  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* Interpreted system state based on EvStatus and SeStatus
   */
  unsigned int Se_Ev_System_State : 4;

  /*  
   */
  unsigned int Prox_Status : 4;

  /*  
   */
  uint8_t SeInfoPageNumber;

  /*  
   */
  uint8_t SeInfoEntry1;

  /*  
   */
  uint8_t SeInfoEntry2;

  /*  
   */
  uint8_t SeInfoEntry3;

  /*  
   */
  uint8_t SeInfoEntry4;

  /*  
   */
  uint8_t SeInfoEntry5;

  /*  
   */
  uint8_t SeInfoEntry6;

} InletProxAndSeInfo_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 32768-Hybrid System Control 1--This messages is sent to the hybrid
 * system to control hybrid related features.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_HSC1 (411041792) // 0x18800000
typedef struct HSC1 {
  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7560-Indicates the Hybrid System Shutdown Request state. ...
   */
  unsigned int HybridSystemShutdownCommand : 2;

  /* 7559-Indicates the hybrid system regenerative braking disable request
   * state. ...
   */
  unsigned int HybridRegenBrakingDisableRequest : 2;

  /* 7558-Indicates the Hybrid System Disable Request state. ...
   */
  unsigned int HybridPropulsionDisableRequest : 2;

  /* 7557-Indicates the hybrid system protection override request state.
   * ...
   */
  unsigned int HybridPropulsionOverrideRequest : 2;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7889-Hybrid Propulsion Mode Request is the operator intended
   * propulsion mode.  ...
   */
  unsigned int HybridPropulsionModeRequest : 4;

  /* 7888-Operator Vehicle Mode Request is the operator intended vehicle
   * mode.  ...
   */
  unsigned int OperatorVehicleModeRequest : 4;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 13154-The type of energy source (EVSE) currently connected as
   * specified in SPN 7890.
   */
  unsigned int ConnectedEnergySourceType : 2;

  /* 10148-Indicates the sender's consent to charge the system's HVES
   * (high-voltage energy storage) from EVSE...
   */
  unsigned int HVESChargeConsent : 2;

  /* 7890-External Energy Source Connection Demand indicates how the hybrid
   * system should engage with...
   */
  unsigned int ExternalEnergyConnectionDemand : 4;

  /* 7891-Stored Energy Source Charge/Discharge Rate Request is used to
   * control the rate at which the stored energy...
   */
  uint8_t Charge_DischargeRateRequest;

  /* 7892-Stored Energy Source Set Point Request is used to set the
   * percentage that the Stored Energy Source...
   */
  uint8_t EnergySourceSetPointRequest;

  /* 9706-The requested maximum speed for the vehicle while in a Hybrid
   * Propulsion Mode (see SPN 7889)...
   */
  uint8_t HybridRequestedMaximumSpeed;

  /* 9707-The requested distance to maintain a Hybrid Propulsion Mode (see
   * SPN 7889)...
   */
  uint16_t HybridModeRequestedDistance;

} HSC1_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 64706-Hybrid System Status 1--Status information of a hybrid system.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_HSS1 (419217920) // 0x18FCC200
typedef struct HSS1 {
  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 6810-Signal from hybrid system indicating the status of OBD related
   * DTCs
   */
  unsigned int HybridSystemOBDRelatedDTCStatus : 2;

  /* 5874-Signal from a hybrid system indicating that some aspect of its
   * operation is not functioning correctly...
   */
  unsigned int HybridSystemStopIndicator : 2;

  /* 5873-Signal from a hybrid system indicating that at least one of its
   * monitored temperatures is above normal acceptable limits...
   */
  unsigned int HybridSystemOverheatIndicator : 2;

  /* 5872-Signal from a hybrid system indicating that some aspect of its
   * operation is not functioning correctly...
   */
  unsigned int HybridSystemWarningIndicator : 2;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7449-Signal from the hybrid system indicating that the hybrid system
   * motor is exceeding maximum speed limit.
   */
  unsigned int HybridSystemMotorOverspeedIndicator : 2;

  /* 7448-Signal from the hybrid system indicating that the hybrid system
   * or one of its components requires servicing...
   */
  unsigned int HybridSystemServiceIndicator : 2;

  /* 7418-Provides the engine an indication of when the hybrid system is
   * not mechanically assisting rotation...
   */
  unsigned int HybridSystemEngineAssistStatus : 2;

  /* 7315-Indicates when the hybrid system or electric vehicle system is
   * ready to provide or is actively providing propulsion...
   */
  unsigned int PropulsionSystemActive : 2;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7453-Signal indicating when the hybrid system or electric vehicle
   * system is initialized and ready to start the engine...
   */
  unsigned int HybridSystemInitializationIndicator : 2;

  /* 7452-Signal from the hybrid system indicating when regenerative
   * braking is active.
   */
  unsigned int HybridSystemRegenerativeBrakingIndicator : 2;

  /* 7451-Signal from the hybrid system indicating that the electric
   * alternator is failed or needs servicing. ...
   */
  unsigned int HybridSystemElectricAlternatorIndicator : 2;

  /* 7450-Signal from the hybrid system indicating that the overspeed
   * audible alarm should be activated.
   */
  unsigned int HybridSystemMotorOverspeedAudibleAlarm : 2;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /*  
   */
  unsigned int unused13 : 2;

  /* 7894-Stored Energy Source Increasing Mode Allowed is sent by the
   * Hybrid System controller to indicate when the Stored Energy...
   */
  unsigned int StoredEnergySourceIncreasingModeAllowed : 2;

  /* 7893-Stored Energy Source Only Mode Allowed is sent by the Hybrid
   * System controller to indicate when Stored Energy Source...
   */
  unsigned int StoredEnergySourceOnlyModeAllowed : 2;

  /* 7454-This signal indicates the condition and state of the the hybrid
   * system or electric vehicle system high voltage exposure...
   */
  unsigned int HybridSystemHighVoltageExposureIndicator : 2;

  /* 7895-Stored Energy Source Level indicates the current operating stored
   * energy source capacity.
   */
  uint8_t StoredEnergySourceLevel;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7897-Hybrid Propulsion Mode Transition Status is sent by the Hybrid
   * System controller to indicate the reason for a mode...
   */
  unsigned int HybridPropulsionModeTransitionStatus : 4;

  /* 7896-Hybrid Propulsion Mode Status is the current Hybrid System
   * Controller propulsion mode.  ...
   */
  unsigned int HybridPropulsionModeStatus : 4;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /*  
   */
  unsigned int unused14 : 2;

  /* 8267-Indicates if the hybrid system is in a state where propulsion is
   * not available. ...
   */
  unsigned int HybridSystemPropulsionDisableStatus : 2;

  /* 7898-External Energy Source Connection Status provides feedback to the
   * External Energy Source Connection Demand...
   */
  unsigned int ExternalEnergySourceConnectionStatus : 4;

  /*  
   */
  uint8_t unused15;

} HSS1_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * 65238-Hybrid System Inputs 1--This message can be sent by any
 * controller that has hybrid system related information.
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define J1939_ID_HSI1 (419354112) // 0x18FED600
typedef struct HSI1 {
  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7551-Indicates the off-board plug-in charger connection status.  One
   * of the uses of this signal is to protect against vehicle motion while
   * a charger is plugged in.
   */
  unsigned int HybridSystemOffBoardChargerConnectionStatus : 2;

  /* 7550-Indicates the coolant level switch position in the hybrid system
   * power electronics...
   */
  unsigned int HybridSystemPowerElectronicsCoolantLevelSwitch : 2;

  /* 7549-Indicates the coolant level switch position in the hybrid system
   * propulsion...
   */
  unsigned int HybridSystemPropulsionCoolantLevelSwitch : 2;

  /* 7548-Indicates the Protection Override switch position.  This switch
   * allows the operator to override hybrid system protection...
   */
  unsigned int HybridSystemProtectionOverrideSwitch : 2;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /* 7555-When the operator enables this switch, all hybrid system
   * functionality is disabled including propulsion...
   */
  unsigned int HybridSystemShutdownSwitch : 2;

  /* 7554-When the operator enables this switch, the propulsion aspect of
   * hybrid system operation will be disabled. ...
   */
  unsigned int HybridSystemPropulsionDisableSwitch : 2;

  /* 7553-Indicates the brake pedal regenerative braking disable switch
   * position. ...
   */
  unsigned int HybridSystemBrakePedalRegenerativeBrakingDisableSwitch : 2;

  /* 7552-Indicates the regenerative braking disable switch position. ...
   */
  unsigned int HybridSystemRegenerativeBrakingDisableSwitch : 2;

  /* 7556-Indicates the coasting regenerative braking level selector
   * position. ...
   */
  uint8_t HybridSystemCoastingRegenerativeBrakingLevelSelector;

  
  /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
   * Starting a bitmapped block of 1 bytes
   * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  /*  
   */
  unsigned int unused16 : 4;

  /* 8476-Indicates the coolant fill switch position for the propulsion
   * motor cooling system. ...
   */
  unsigned int PowerElectronicsCoolantFillSwitch : 2;

  /* 8475-Indicates the coolant fill switch position for the power
   * electronics cooling system. ...
   */
  unsigned int PropulsionMotorCoolantFillSwitch : 2;

  /*  
   */
  uint16_t unused17;

  /*  
   */
  uint16_t unused18;

} HSI1_t;



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * Read/Write Function Prototypes
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
int read_EVSE1AC3PL (void *dest, uint8_t *buf, int offset, int buf_size);
int write_EVSE1AC3PL (uint8_t *can_data, void *src);
int read_EVSE1ACS1 (void *dest, uint8_t *buf, int offset, int buf_size);
int write_EVSE1ACS1 (uint8_t *can_data, void *src);
int read_EVSE1ACSV (void *dest, uint8_t *buf, int offset, int buf_size);
int write_EVSE1ACSV (uint8_t *can_data, void *src);
int read_EVSE1C1 (void *dest, uint8_t *buf, int offset, int buf_size);
int write_EVSE1C1 (uint8_t *can_data, void *src);
int read_EVSE1S1 (void *dest, uint8_t *buf, int offset, int buf_size);
int write_EVSE1S1 (uint8_t *can_data, void *src);
int read_InletProxAndSeInfo (void *dest, uint8_t *buf, int offset, int buf_size);
int write_InletProxAndSeInfo (uint8_t *can_data, void *src);
int read_HSC1 (void *dest, uint8_t *buf, int offset, int buf_size);
int write_HSC1 (uint8_t *can_data, void *src);
int read_HSS1 (void *dest, uint8_t *buf, int offset, int buf_size);
int write_HSS1 (uint8_t *can_data, void *src);
int read_HSI1 (void *dest, uint8_t *buf, int offset, int buf_size);
int write_HSI1 (uint8_t *can_data, void *src);

#endif // HEADER GUARD
