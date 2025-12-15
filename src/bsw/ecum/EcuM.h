/**
 * @file EcuM.h
 * @brief AUTOSAR ECU State Manager
 * 
 * ECUの状態管理とライフサイクル制御
 */

#ifndef ECUM_H
#define ECUM_H

#include "Std_Types.h"

/* ECU状態定義 */
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
