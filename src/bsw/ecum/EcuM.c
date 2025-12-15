/**
 * @file EcuM.c
 * @brief AUTOSAR ECU State Manager Implementation
 */

#include "EcuM.h"
#include "Os.h"
#include "Com.h"
#include "Det.h"
#include <stdio.h>

static EcuM_StateType currentState = ECUM_STATE_OFF;

/**
 * @brief EcuM初期化
 */
void EcuM_Init(void) {
    printf("[ECUM] ECU State Manager Initializing...\n");
    
    currentState = ECUM_STATE_STARTUP;
    
    /* BSWモジュール初期化 */
    Det_Init();
    Com_Init();
    Os_Init();
    
    printf("[ECUM] State: STARTUP\n");
}

/**
 * @brief スタートアップフェーズ2
 */
void EcuM_StartupTwo(void) {
    printf("[ECUM] Startup Phase 2\n");
    
    /* RTE初期化などを実行 */
    
    currentState = ECUM_STATE_RUN;
    printf("[ECUM] State: RUN\n");
}

/**
 * @brief ECUシャットダウン
 */
void EcuM_Shutdown(void) {
    printf("[ECUM] Shutting down...\n");
    
    currentState = ECUM_STATE_SHUTDOWN;
    
    /* 各モジュールのデ初期化処理 */
    
    currentState = ECUM_STATE_OFF;
    printf("[ECUM] State: OFF\n");
}

/**
 * @brief ECU状態取得
 */
EcuM_StateType EcuM_GetState(void) {
    return currentState;
}
