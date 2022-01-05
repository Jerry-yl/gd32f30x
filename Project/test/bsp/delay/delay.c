/*
 * @Descripttion: delay function
 * @Author: Jerry
 * @Date: 2021-12-13 17:05:25
 * @LastEditTime: 2022-01-05 11:14:46
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "delay.h"

/**
 * @brief about delay a time in microsecond
 * @param count [in] us count
 */
void delay_us(uint32_t count)
{
    uint32_t i;
    i = (count * 120) / 3;
    while(i--);
}

/**
 * @brief about delay a time in milliseconds
 * @param count [in] ms count
 */
void delay_ms(uint32_t count)
{
    uint32_t i;
    i = (count * 120) / 3;
    i = i * 1000;
    while(i--);
}
