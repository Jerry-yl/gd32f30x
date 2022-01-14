/*
 * @Descripttion: main
 * @Author: Jerry
 * @Date: 2021-11-30 14:08:10
 * @LastEditTime: 2022-01-14 17:15:51
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "gd32f30x.h"
#include "gd32f303e_eval.h"
#include "osal.h"
#include "system.h"
#include "uart_printf.h"
#include "delay.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{  
    delay_init();
    uart_printf_init();

    OS_Init();
    system_init();
    OS_StartScheduler();
    while(1) { OLOGI("!"); }//OS_StartScheduler 调用失败将返回，添加死循环更容易排查问题
}
