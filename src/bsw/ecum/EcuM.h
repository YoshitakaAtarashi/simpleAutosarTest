/**
 * @file EcuM.h
 * @brief AUTOSAR ECU State Manager
 * 
 * ECU state management and lifecycle control
 */

#ifndef ECUM_H
#define ECUM_H

#include "Std_Types.h"

/* ECU state definitions */
typedef enum {
    ECUM_STATE_STARTUP,
    ECUM_STATE_RUN,
    ECUM_STATE_SHUTDOWN,
    ECUM_STATE_SLEEP,
    ECUM_STATE_OFF
} EcuM_StateType;

/* EcuM API */
void EcuM_Init(void);
void EcuM_StartupTwo(void);
void EcuM_Shutdown(void);
EcuM_StateType EcuM_GetState(void);

#endif /* ECUM_H */
