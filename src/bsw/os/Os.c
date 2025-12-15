/**
 * @file Os.c
 * @brief AUTOSAR OS Implementation
 * 
 * 簡易的なタスクスケジューラの実装
 */

#include "Os.h"
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/* 最大タスク数 */
#define OS_MAX_TASKS 10

/* タスク管理テーブル */
static TaskConfigType taskTable[OS_MAX_TASKS];
static uint8_t taskCount = 0;
static volatile bool osRunning = false;

/* システムティックカウンタ（ミリ秒） */
static uint32_t systemTick = 0;

/**
 * @brief OS初期化
 */
void Os_Init(void) {
    taskCount = 0;
    systemTick = 0;
    osRunning = false;
    
    for (int i = 0; i < OS_MAX_TASKS; i++) {
        taskTable[i].state = TASK_STATE_SUSPENDED;
    }
    
    printf("[OS] Initialized\n");
}

/**
 * @brief タスクをシステムに登録
 */
Std_ReturnType Os_RegisterTask(TaskType taskId, TaskFuncType taskFunc, uint32_t period_ms) {
    if (taskCount >= OS_MAX_TASKS) {
        return E_NOT_OK;
    }
    
    taskTable[taskCount].taskId = taskId;
    taskTable[taskCount].taskFunc = taskFunc;
    taskTable[taskCount].period_ms = period_ms;
    taskTable[taskCount].lastExecution = 0;
    taskTable[taskCount].state = TASK_STATE_READY;
    
    taskCount++;
    
    printf("[OS] Task %d registered (period: %u ms)\n", taskId, period_ms);
    
    return E_OK;
}

/**
 * @brief タスクアクティベート
 */
Std_ReturnType Os_ActivateTask(TaskType taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (taskTable[i].taskId == taskId) {
            taskTable[i].state = TASK_STATE_READY;
            return E_OK;
        }
    }
    return E_NOT_OK;
}

/**
 * @brief システムティックカウント取得
 */
uint32_t Os_GetTickCount(void) {
    return systemTick;
}

/**
 * @brief スリープ
 */
void Os_Sleep(uint32_t ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

/**
 * @brief タスクスケジューラ
 */
void Os_Schedule(void) {
    uint32_t currentTick = systemTick;
    
    for (int i = 0; i < taskCount; i++) {
        if (taskTable[i].state == TASK_STATE_READY) {
            /* 周期チェック */
            if ((currentTick - taskTable[i].lastExecution) >= taskTable[i].period_ms) {
                /* タスク実行 */
                taskTable[i].state = TASK_STATE_RUNNING;
                taskTable[i].taskFunc();
                taskTable[i].lastExecution = currentTick;
                taskTable[i].state = TASK_STATE_READY;
            }
        }
    }
}

/**
 * @brief OS開始
 */
void Os_Start(void) {
    printf("[OS] Starting scheduler...\n");
    osRunning = true;
    
    const uint32_t TICK_INTERVAL_MS = 1; /* 1msティック */
    
    while (osRunning) {
        /* スケジューラ実行 */
        Os_Schedule();
        
        /* ティック更新 */
        Os_Sleep(TICK_INTERVAL_MS);
        systemTick += TICK_INTERVAL_MS;
        
        /* 10秒でシミュレーション終了 */
        if (systemTick >= 10000) {
            osRunning = false;
        }
    }
    
    printf("[OS] Scheduler stopped\n");
}

#endif /* OS_C */
