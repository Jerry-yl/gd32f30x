/*
 * @Descripttion: test task
 * @Author: Jerry
 * @Date: 2022-01-04 15:12:40
 * @LastEditTime: 2022-01-14 16:26:48
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "stdio.h"
#include "osal.h"
#include "gd32f303e_eval.h"
#include "delay.h"

/*******************************************************************/
/***       			    Local Function                           ***/
/*******************************************************************/
static void test_task(void *para)
{
    float f = 0.3f;
    while(1)
    {
        LOGD("task: %s, freestack: %d, proi: %d\n", OS_TaskGetName(NULL), OS_TaskGetFreeStackSpace(NULL), OS_TaskGetPriority(NULL));

        f *= 3.0f;

        LOGD("delay 111111\n");
        delay_ms(1000);
        LOGD("delay 222222\n");

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
