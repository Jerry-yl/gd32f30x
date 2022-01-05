/*
 * @Descripttion: uart printf
 * @Author: Jerry
 * @Date: 2021-12-01 19:19:07
 * @LastEditTime: 2021-12-23 13:30:36
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "uart_printf.h"
#include "config.h"

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
#if(SYS_DEBUG_PRINTF_ENABLE == 1)
    while(RESET == usart_flag_get(DBG_USART, USART_FLAG_TBE));
    usart_data_transmit(DBG_USART, (uint8_t)ch);
#endif
    return ch;
}

/* uart printf init */
void uart_printf_init(void)
{
#if(SYS_DEBUG_PRINTF_ENABLE == 1)
    /* enable GPIO clock */
    rcu_periph_clock_enable(DBG_GPIO_RCU_PERIPH);
    /* enable USART clock */
    rcu_periph_clock_enable(DBG_USART_RCU_PERIPH);
    /* connect port to USARTx_Tx */
    gpio_init(DBG_GPIO_PERIPH, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, DBG_USART_TX_PIN);
    /* connect port to USARTx_Rx */
    gpio_init(DBG_GPIO_PERIPH, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, DBG_USART_RX_PIN);

    /* USART configure */
    usart_deinit(DBG_USART);
    usart_baudrate_set(DBG_USART, DBG_USART_BAUD_RATE);
    usart_word_length_set(DBG_USART, DBG_USART_DATA_BIN_LEN);
    usart_parity_config(DBG_USART, DBG_USART_PARITY_MODE);
    usart_stop_bit_set(DBG_USART, DBG_USART_STOP_BIT_LEN);
    usart_hardware_flow_rts_config(DBG_USART, USART_RTS_DISABLE);
	usart_hardware_flow_cts_config(DBG_USART, USART_CTS_DISABLE);
    usart_receive_config(DBG_USART, USART_RECEIVE_ENABLE);
    usart_transmit_config(DBG_USART, USART_TRANSMIT_ENABLE);

    usart_enable(DBG_USART);
#endif
}

