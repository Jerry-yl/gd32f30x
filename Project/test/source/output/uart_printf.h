/*
 * @Descripttion: uart printf
 * @Author: Jerry
 * @Date: 2021-12-01 19:19:22
 * @LastEditTime: 2021-12-22 14:55:33
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _UART_PRINTF_H_
#define _UART_PRINTF_H_

#include "stdio.h"
#include "gd32f303e_eval.h"

#define DBG_USART_BAUD_RATE       115200
#define DBG_USART_DATA_BIN_LEN    USART_WL_8BIT
#define DBG_USART_PARITY_MODE     USART_PM_NONE
#define DBG_USART_STOP_BIT_LEN    USART_STB_1BIT

#define DBG_GPIO_RCU_PERIPH       RCU_GPIOA
#define DBG_GPIO_PERIPH           GPIOA

#define DBG_USART_RCU_PERIPH      RCU_USART1
#define DBG_USART                 USART1
#define DBG_USART_TX_PIN          GPIO_PIN_2
#define DBG_USART_RX_PIN          GPIO_PIN_3

/* uart printf init */
void uart_printf_init(void);

#endif
