/*
 * @Descripttion: delay function
 * @Author: Jerry
 * @Date: 2021-12-13 17:05:30
 * @LastEditTime: 2022-01-14 16:18:29
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _DELAY_H_
#define _DELAY_H_

#include "stdint.h"

void delay_init(void);

/**
 * @brief delay a time in microsecond
 * @param us [in] us
 */
void delay_us(uint32_t us);

/**
 * @brief delay a time in milliseconds
 * @param ms [in] ms
 */
void delay_ms(uint32_t ms);

#endif
