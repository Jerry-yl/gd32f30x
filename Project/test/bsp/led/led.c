#define __LED_C__

#include <gd32f30x.h>
#include "led.h"


void  led_init (void)
{
	//LED 1
    /* 使能对应得时钟源 */
    rcu_periph_clock_enable(RCU_GPIOF);
    /* 配置引脚 */ 
    gpio_init(GPIOF, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);

	
	//LED 2
    /* 使能对应得时钟源 */
    rcu_periph_clock_enable(RCU_GPIOF);
    /* 配置引脚 */ 
    gpio_init(GPIOF, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_1);

	
	//LED 3
    /* 使能对应得时钟源 */
    rcu_periph_clock_enable(RCU_GPIOF);
    /* 配置引脚 */ 
    gpio_init(GPIOF, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);

	//LED 4
    /* 使能对应得时钟源 */
    rcu_periph_clock_enable(RCU_GPIOF);
    /* 配置引脚 */ 
    gpio_init(GPIOF, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_3);
}



void led_on(int lednum)
{
	switch(lednum)
	{
		case 0:
    		gpio_bit_set(GPIOF,GPIO_PIN_0);
			break;
			
		case 1:
    		gpio_bit_set(GPIOF,GPIO_PIN_1);
			break;
			
		case 2:
    		gpio_bit_set(GPIOF,GPIO_PIN_2);
			break;

		case 3:
    		gpio_bit_set(GPIOF,GPIO_PIN_3);
			break;
	}
}


void led_off(int lednum)
{
	switch(lednum)
    {
		case 0:
    		gpio_bit_reset(GPIOF,GPIO_PIN_0);
			break;
			
		case 1:
    		gpio_bit_reset(GPIOF,GPIO_PIN_1);
			break;
			
		case 2:
    		gpio_bit_reset(GPIOF,GPIO_PIN_2);
			break;

		case 3:
    		gpio_bit_reset(GPIOF,GPIO_PIN_3);
			break;
	}
}

