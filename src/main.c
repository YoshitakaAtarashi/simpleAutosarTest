/**
 * @file main.c
 * @brief AUTOSAR Simulation Main Entry Point
 * 
 * ECUシミュレーションのメインプログラム
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

/* タスクID定義 */
#define TASK_SENSOR_READER      0
#define TASK_ENGINE_CONTROL     1
#define TASK_DIAGNOSTIC         2

/* 外部関数宣言 */
extern Std_ReturnType Os_RegisterTask(TaskType taskId, TaskFuncType taskFunc, uint32_t period_ms);

/**
 * @brief タスク1: SensorReader（10ms周期）
 */
void Task_SensorReader(void) {
    SensorReader_Run();
}

/**
 * @brief タスク2: EngineControl（20ms周期）
 */
void Task_EngineControl(void) {
    EngineControl_Run();
}

/**
 * @brief タスク3: 診断タスク（100ms周期）
 */
void Task_Diagnostic(void) {
    static uint32_t diagCount = 0;
    diagCount++;
    
    if (diagCount % 10 == 0) {  /* 1秒ごと */
        printf("[DIAG] System running normally (cycle: %u)\n", diagCount);
    }
}

/**
 * @brief メイン関数
 */
int main(void) {
    printf("========================================\n");
    printf("  AUTOSAR Learning Environment\n");
    printf("  Simple ECU Simulation\n");
    printf("========================================\n\n");
    
    /* 乱数初期化 */
    srand((unsigned int)time(NULL));
    
    /* ======== STARTUP フェーズ ======== */
    printf("=== STARTUP PHASE ===\n");
    
    /* EcuMによるBSW初期化 */
    EcuM_Init();
    
    /* RTE初期化 */
    Rte_Init();
    
    /* SWC初期化 */
    SensorReader_Init();
    EngineControl_Init();
    
    /* Startup Phase 2 */
    EcuM_StartupTwo();
    
    printf("\n=== TASK REGISTRATION ===\n");
    
    /* タスク登録 */
    Os_RegisterTask(TASK_SENSOR_READER, Task_SensorReader, 10);    /* 10ms */
    Os_RegisterTask(TASK_ENGINE_CONTROL, Task_EngineControl, 20);  /* 20ms */
    Os_RegisterTask(TASK_DIAGNOSTIC, Task_Diagnostic, 100);        /* 100ms */
    
    printf("\n=== RUN PHASE ===\n");
    printf("Simulation will run for 10 seconds...\n\n");
    
    /* ======== RUN フェーズ ======== */
    /* OSスケジューラ起動（ブロッキング） */
    Os_Start();
    
    /* ======== SHUTDOWN フェーズ ======== */
    printf("\n=== SHUTDOWN PHASE ===\n");
    EcuM_Shutdown();
    
    printf("\n========================================\n");
    printf("  Simulation Completed\n");
    printf("========================================\n");
    
    return 0;
}
