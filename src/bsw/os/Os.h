/**
 * @file Os.h
 * @brief AUTOSAR OS Interface
 * 
 * Simple OS task scheduler implementation
 */

#ifndef OS_H
#define OS_H

#include "Std_Types.h"

/* Task ID definition */
typedef uint8_t TaskType;

/* Task state */
typedef enum {
    TASK_STATE_SUSPENDED,
    TASK_STATE_READY,
    TASK_STATE_RUNNING
} TaskStateType;

/* Task function pointer type */
typedef void (*TaskFuncType)(void);

/* Task configuration structure */
typedef struct {
    TaskType taskId;
    TaskFuncType taskFunc;
    uint32_t period_ms;      /* Task period [ms] */
    uint32_t lastExecution;  /* Last execution time */
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
