/*
 * @Descripttion: test task
 * @Author: Jerry
 * @Date: 2022-01-04 15:12:40
 * @LastEditTime: 2022-01-05 14:33:36
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "stdio.h"
#include "osal.h"
#include "systick.h"
#include "gd32f303e_eval.h"

/*******************************************************************/
/***       			    Local Function                           ***/
/*******************************************************************/
static void test_task(void *para)
{
    while(1)
    {
        LOGD("task: %s, freestack: %d, proi: %d\n", OS_TaskGetName(NULL), OS_TaskGetFreeStackSpace(NULL), OS_TaskGetPriority(NULL));

        OS_MsDelay(1000);
    }
}

/******************************************************************/
/***                    Exported Functions                      ***/
/******************************************************************/
/**
 * @brief init test task.
 */
void test_task_init(void)
{
    OS_TaskCreate(test_task, "test_task", 256, NULL, OS_TASK_PRIO1, NULL);
}
