/*
 * @Descripttion: operating system abstract layer
 * @Author: Jerry
 * @Date: 2021-12-01 15:06:50
 * @LastEditTime: 2021-12-07 17:27:27
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _OSAL_H_
#define _OSAL_H_

#include "types.h"
#include "FreeRTOS.h"
#include "task.h"

typedef void *OsTaskHandle;
typedef void (*OsTask)(void *);
typedef TickType_t OS_TICKTYPE;

#if                         1
    #define OS_TASK_PRIO0   0
    #define OS_TASK_PRIO1   1
    #define OS_TASK_PRIO2   2
    #define OS_TASK_PRIO3   3
    #define OS_TASK_PRIO4   4
#endif

#define OS_TASK_MIN_STACK_SIZE      configMINIMAL_STACK_SIZE
#define OS_MAX_WAITTIME             portMAX_DELAY
#define OS_MS_TO_TICKS(xTimeInMs)   pdMS_TO_TICKS(xTimeInMs) 

/**
 * init os, must be called at begin of main
 */
void OS_Init(void);


/**
 * @brief get os version
 * @retval version string 
 */
const char* OS_GetVersion(void);

/**
 * create task
 *
 * @param   task                    	task function
 * @param   name                    	task name
 * @param   stackSize                   task stack size in WORDS (ex: task stack size 512 bytes = 128 WORDS)
 * @param   param                       task parameter
 * @param   pri                       	task priority, (min:OS_TASK_PRIO0, max:OS_TASK_PRIO3)
 * @param   taskHandle                  task handle
 *
 * @retval  0                       	task create failed
 * @retval  1                         	task create success
 */
u8 OS_TaskCreate(OsTask task, const char *name, u16 stackSize, void *param, u32 pri, OsTaskHandle *taskHandle);

/**
 * @brief get task prioirity
 * @param taskHandle    task handle
 * @retval: priority
 */
u32 OS_TaskGetPriority(OsTaskHandle taskHandle);

/**
 * @brief set task priority
 * @param taskHandle    task handle
 * @param prio          task priority
 */
void OS_TaskSetPriority(OsTaskHandle taskHandle, u32 prio);

/**
 * delete task
 *
 * @param   taskHandle                    	NULL: delete current task
 */
void OS_TaskDelete( OsTaskHandle taskHandle );

/**
 * get task's name
 *
 * @retval task's name
 */
const char * OS_TaskGetName(OsTaskHandle taskHandle);

/**
 * get task's free stack space
 *
 * @retval task free stack size in WORDS (ex: task stack size 512 bytes = 128 WORDS)
 */
u32 OS_TaskGetFreeStackSpace(OsTaskHandle taskHandle);

/**
 * start scheduler, must be called at end of main
 */
void OS_StartScheduler(void);

/**
 * delay ms
 *
 * @param   ms                    		ms count
 */
void OS_MsDelay(u32 ms);

/**
 * delay tick
 *
 * @param   ticks                    	tick count
 */
void OS_TickDelay(OS_TICKTYPE ticks);

/**
 * specifies the absolute (exact) time at which it wishes to unblock.
 *
 * @param pxPreviousWakeTime    previous wake time
 * @param ticks                 tick count
 */
void OS_TickDelayUntil(OS_TICKTYPE * const pxPreviousWakeTime, const OS_TICKTYPE ticks);

/**
 * @brief get current system tick count
 * @retval current tick count
 */
OS_TICKTYPE OS_GetTickCount(void);

/**
 * @brief OS application stack overflow hook
 * @param xTask         [in] task handle
 * @param pcTaskName    [in] task's name
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);

#define OS_EnterCritical()  vPortEnterCritical()
#define OS_ExitCritical()   vPortExitCritical()

#endif
