/*
 * @Descripttion: 
 * @Author: Jerry
 * @Date: 2021-12-01 16:39:12
 * @LastEditTime: 2022-01-04 15:31:29
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "system.h"
#include "uart_printf.h"
#include "osal.h"
#include "gd32f303e_eval.h"
#include "util.h"
#include "test_task.h"

void system_init(void)
{
    OLOGI("Software Version: %s %s\n\n", GET_SOFTWARE_VER_STR(), get_complie_time());

    test_task_init();
}
