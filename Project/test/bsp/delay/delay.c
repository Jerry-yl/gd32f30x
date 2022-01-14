/*
 * @Descripttion: delay function
 * @Author: Jerry
 * @Date: 2021-12-13 17:05:25
 * @LastEditTime: 2022-01-14 16:23:12
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "delay.h"
#include "gd32f30x_timer.h"

#define DELAY_TIMER_RCU_PERIPH  RCU_TIMER6
#define DELAY_TIMER_PERIPH      TIMER6
#define DELAY_TIMER_NVIC_IRQ    TIMER6_IRQn
#define DELAY_TIMER_IRQ_HANDLER TIMER6_IRQHandler

//int_time = CLK / ((prescaler + 1) * period)
//int_time = 1us
#define DELAY_TIMER_PRESCALER   1
#define DELAY_TIMER_PERIOD      60

volatile static uint32_t gs_count = 0;

/*******************************************************************/
/***       			    Local Function                           ***/
/*******************************************************************/
void delay_timer_init(void)
{
    timer_parameter_struct timer_parameter;

    rcu_periph_clock_enable(DELAY_TIMER_RCU_PERIPH);
    //预分频
    timer_parameter.prescaler = DELAY_TIMER_PRESCALER;
    //对齐模式
    timer_parameter.alignedmode = TIMER_COUNTER_EDGE;
    //定时器增长方向
    timer_parameter.counterdirection = TIMER_COUNTER_UP;
    //定时器自动加载值
    timer_parameter.period = DELAY_TIMER_PERIOD;
    //时钟分频值
    timer_parameter.clockdivision = TIMER_CKDIV_DIV1;
    
    timer_init(DELAY_TIMER_PERIPH, &timer_parameter);
    timer_interrupt_enable(DELAY_TIMER_PERIPH, TIMER_INT_UP);
    nvic_irq_enable(DELAY_TIMER_NVIC_IRQ, 0, 0);
    timer_enable(DELAY_TIMER_PERIPH);
}

void DELAY_TIMER_IRQ_HANDLER(void)
{
    timer_interrupt_flag_clear(DELAY_TIMER_PERIPH, TIMER_INT_UP);

    gs_count++;
}

/******************************************************************/
/***                    Exported Functions                      ***/
/******************************************************************/
void delay_init(void)
{
    delay_timer_init();
}

/**
 * @brief delay a time in microsecond
 * @param us [in] us
 */
void delay_us(uint32_t us)
{
    uint32_t start_count = gs_count;
    while((gs_count - start_count) < us);
}

/**
 * @brief delay a time in milliseconds
 * @param ms [in] ms
 */
void delay_ms(uint32_t ms)
{
    delay_us(ms * 1000);
}
