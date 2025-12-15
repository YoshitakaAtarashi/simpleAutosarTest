/**
 * @file main.c
 * @brief AUTOSAR Simulation Main Entry Point
 * 
 * Main program for ECU simulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* BSW Headers */
#include "bsw/ecum/EcuM.h"
#include "bsw/os/Os.h"

/* RTE Headers */
#include "rte/Rte.h"

/* SWC Headers */
#include "swc/SensorReader/SensorReader.h"
#include "swc/EngineControl/EngineControl.h"

/* Task ID definitions */
#define TASK_SENSOR_READER      0
#define TASK_ENGINE_CONTROL     1
#define TASK_DIAGNOSTIC         2

/* External function declarations */
extern Std_ReturnType Os_RegisterTask(TaskType taskId, TaskFuncType taskFunc, uint32_t period_ms);

/**
 * @brief Task 1: SensorReader (10ms cycle)
 */
void Task_SensorReader(void) {
    SensorReader_Run();
}

/**
 * @brief Task 2: EngineControl (20ms cycle)
 */
void Task_EngineControl(void) {
    EngineControl_Run();
}

/**
 * @brief Task 3: Diagnostic task (100ms cycle)
 */
void Task_Diagnostic(void) {
    static uint32_t diagCount = 0;
    diagCount++;
    
    if (diagCount % 10 == 0) {  /* Every 1 second */
        printf("[DIAG] System running normally (cycle: %u)\n", diagCount);
    }
}

/**
 * @brief Main function
 */
int main(void) {
    printf("========================================\n");
    printf("  AUTOSAR Learning Environment\n");
    printf("  Simple ECU Simulation\n");
    printf("========================================\n\n");
    
    /* Initialize random number generator */
    srand((unsigned int)time(NULL));
    
    /* ======== STARTUP phase ======== */
    printf("=== STARTUP PHASE ===\n");
    
    /* Initialize BSW via EcuM */
    EcuM_Init();
    
    /* Initialize RTE */
    Rte_Init();
    
    /* Initialize SWC */
    SensorReader_Init();
    EngineControl_Init();
    
    /* Startup Phase 2 */
    EcuM_StartupTwo();
    
    printf("\n=== TASK REGISTRATION ===\n");
    
    /* Register tasks */
    Os_RegisterTask(TASK_SENSOR_READER, Task_SensorReader, 10);    /* 10ms */
    Os_RegisterTask(TASK_ENGINE_CONTROL, Task_EngineControl, 20);  /* 20ms */
    Os_RegisterTask(TASK_DIAGNOSTIC, Task_Diagnostic, 100);        /* 100ms */
    
    printf("\n=== RUN PHASE ===\n");
    printf("Simulation will run for 10 seconds...\n\n");
    
    /* ======== RUN phase ======== */
    /* Start OS scheduler (blocking) */
    Os_Start();
    
    /* ======== SHUTDOWN phase ======== */
    printf("\n=== SHUTDOWN PHASE ===\n");
    EcuM_Shutdown();
    
    printf("\n========================================\n");
    printf("  Simulation Completed\n");
    printf("========================================\n");
    
    return 0;
}
