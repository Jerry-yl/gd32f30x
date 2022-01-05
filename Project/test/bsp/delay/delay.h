/*
 * @Descripttion: delay function
 * @Author: Jerry
 * @Date: 2021-12-13 17:05:30
 * @LastEditTime: 2022-01-05 11:14:37
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _DELAY_H_
#define _DELAY_H_

#include "stdint.h"

/**
 * @brief about delay a time in microsecond
 * @param count [in] us count
 */
void delay_us(uint32_t count);

/**
 * @brief about delay a time in milliseconds
 * @param count [in] ms count
 */
void delay_ms(uint32_t count);

#endif
