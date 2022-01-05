/*
 * @Descripttion: 
 * @Author: Jerry
 * @Date: 2021-11-30 14:08:10
 * @LastEditTime: 2021-12-13 17:05:37
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
/*!
    \file  systick.h
    \brief the header file of systick
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-05-19, V1.0.0, demo for GD32F30x
*/

#ifndef SYS_TICK_H
#define SYS_TICK_H

#include <stdint.h>

/* configure systick */
void systick_config(void);
/* delay a time in milliseconds */
void delay_1ms(uint32_t count);
/* delay decrement */
void delay_decrement(void);

#endif /* SYS_TICK_H */
