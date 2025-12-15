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
 * @brief EcuM initialization
 */
void EcuM_Init(void) {
    printf("[ECUM] ECU State Manager Initializing...\n");
    
    currentState = ECUM_STATE_STARTUP;
    
    /* Initialize BSW modules */
    Det_Init();
    Com_Init();
    Os_Init();
    
    printf("[ECUM] State: STARTUP\n");
}

/**
 * @brief Startup Phase 2
 */
void EcuM_StartupTwo(void) {
    printf("[ECUM] Startup Phase 2\n");
    
    /* Execute RTE initialization etc. */
    
    currentState = ECUM_STATE_RUN;
    printf("[ECUM] State: RUN\n");
}

/**
 * @brief ECU shutdown
 */
void EcuM_Shutdown(void) {
    printf("[ECUM] Shutting down...\n");
    
    currentState = ECUM_STATE_SHUTDOWN;
    
    /* De-initialization of each module */
    
    currentState = ECUM_STATE_OFF;
    printf("[ECUM] State: OFF\n");
}

/**
 * @brief Get ECU state
 */
EcuM_StateType EcuM_GetState(void) {
    return currentState;
}
