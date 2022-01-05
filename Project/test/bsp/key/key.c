#define __KEY_C__

#include <gd32f30x.h>
#include "led.h"


void  key_init (void)
{
	
    /* enable the key clock */
    rcu_periph_clock_enable(RCU_GPIOC);

    /* configure button pin as input */
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_13);	
}


uint8_t key_state_get(void)
{
    return gpio_input_bit_get(GPIOC, GPIO_PIN_13);
}

