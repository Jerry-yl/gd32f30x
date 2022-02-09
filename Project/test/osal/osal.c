/*
 * @Descripttion: operating system abstract layer
 * @Author: Jerry
 * @Date: 2021-12-01 15:06:50
 * @LastEditTime: 2022-02-09 10:29:48
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "types.h"
#include "osal.h"
#include "task.h"
#include "gd32f30x_misc.h"
#include "log.h"

/**
 * init os, must be called at begin of main
 */
void OS_Init(void)
{
    OLOGI("OS Version: %s\n", OS_GetVersion());
    nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);
}

/**
 * @brief get os version
 * @retval version string 
 */
const char* OS_GetVersion(void)
{
    return tskKERNEL_VERSION_NUMBER;
}

/**
 * @brief printf system info, include task list and run time
 */
void OS_SysInfo(void)
{
    char *pBuf = OS_MemAlloc(uxTaskGetNumberOfTasks() * (60 + configMAX_TASK_NAME_LEN));
    OLOGF("taskname     state     priority    freestack   number\n");
    if(pBuf){
        vTaskList(pBuf);
        OLOGF("%s", pBuf);

        OLOGF("\ntaskname     count     %%cpu\n");
        vTaskGetRunTimeStats(pBuf);
        OLOGF("%s", pBuf);
        OS_MemFree(pBuf);
    }else{
        OLOGF("Heap space is not enough\n");
    }
}

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
u8 OS_TaskCreate(OsTask task, const char *name, u16 stackSize, void *param, u32 pri, OsTaskHandle *taskHandle)
{
    if(pdPASS == xTaskCreate(task, name, stackSize, param, pri, (TaskHandle_t *)taskHandle)) return 1;
    else return 0;
}

/**
 * @brief get task prioirity
 * @param taskHandle    task handle
 * @retval: priority
 */
u32 OS_TaskGetPriority(OsTaskHandle taskHandle)
{
    return uxTaskPriorityGet(taskHandle);
}

/**
 * @brief set task priority
 * @param taskHandle    task handle
 * @param prio          task priority
 */
void OS_TaskSetPriority(OsTaskHandle taskHandle, u32 prio)
{
    vTaskPrioritySet(taskHandle, prio);
}

/**
 * delete task
 *
 * @param   taskHandle                    	NULL: delete current task
 */
void OS_TaskDelete(OsTaskHandle taskHandle)
{
    vTaskDelete(taskHandle);
}

/**
 * get task's name
 *
 * @retval task's name string
 */
const char * OS_TaskGetName(OsTaskHandle taskHandle)
{
    return pcTaskGetTaskName(taskHandle);
}

/**
 * get task's free stack space
 *
 * @retval task free stack size in WORDS (ex: task stack size 512 bytes = 128 WORDS)
 */
u32 OS_TaskGetFreeStackSpace(OsTaskHandle taskHandle)
{
    return uxTaskGetStackHighWaterMark(taskHandle);
}

/**
 * start scheduler, must be called at end of main
 */
void OS_StartScheduler(void)
{
    vTaskStartScheduler();
}

/* Delay: */
/**
 * delay ms
 *
 * @param   ms                    		ms count
 */
void OS_MsDelay(u32 ms)
{
    const TickType_t xDelay = ms / portTICK_PERIOD_MS;
    vTaskDelay(xDelay);
}

/**
 * delay tick
 *
 * @param   ticks                    	tick count
 */
void OS_TickDelay(OS_TICKTYPE ticks)
{
    vTaskDelay(ticks);
}

/**
 * specifies the absolute (exact) time at which it wishes to unblock.
 *
 * @param pxPreviousWakeTime    previous wake time
 * @param ticks                 tick count
 */
void OS_TickDelayUntil(OS_TICKTYPE * const pxPreviousWakeTime, const OS_TICKTYPE ticks)
{
    vTaskDelayUntil(pxPreviousWakeTime, ticks);
}

/**
 * @brief get current system tick count
 * @retval current tick count
 */
OS_TICKTYPE OS_GetTickCount(void)
{
    return xTaskGetTickCount();
}

/**
 * @brief OS memory alloc
 * @param {u32} size    - alloc size
 * @retval memory address, NULL is failed
 */
void *OS_MemAlloc(u32 size)
{
    return pvPortMalloc(size);
}

/**
 * @brief OS memory free
 * @param {void} *m     - memory address
 */
void OS_MemFree(void *m)
{
    vPortFree(m);
}

/**
 * @brief OS application stack overflow hook
 * @param xTask         [in] task handle
 * @param pcTaskName    [in] task's name
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName )
{
    OLOGF("<!!!OS stack overflow!!!> task: %s\n", pcTaskName);
}

void vApplicationIdleHook( void )
{
    
}
