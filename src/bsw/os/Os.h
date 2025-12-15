/**
 * @file Os.h
 * @brief AUTOSAR OS Interface
 * 
 * 簡易的なOSタスクスケジューラの実装
 */

#ifndef OS_H
#define OS_H

#include "Std_Types.h"

/* タスクID定義 */
typedef uint8_t TaskType;

/* タスク状態 */
typedef enum {
    TASK_STATE_SUSPENDED,
    TASK_STATE_READY,
    TASK_STATE_RUNNING
} TaskStateType;

/* タスク関数ポインタ型 */
typedef void (*TaskFuncType)(void);

/* タスク設定構造体 */
typedef struct {
    TaskType taskId;
    TaskFuncType taskFunc;
    uint32_t period_ms;      /* タスク周期[ms] */
    uint32_t lastExecution;  /* 最終実行時刻 */
    TaskStateType state;
} TaskConfigType;

/* OS API */
void Os_Init(void);
void Os_Start(void);
Std_ReturnType Os_ActivateTask(TaskType taskId);
void Os_Schedule(void);
uint32_t Os_GetTickCount(void);
void Os_Sleep(uint32_t ms);

#endif /* OS_H */
