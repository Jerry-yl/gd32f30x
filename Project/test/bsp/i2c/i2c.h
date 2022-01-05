/*
 * @Descripttion: gpio simulation i2c
 * @Author: Jerry
 * @Date: 2021-12-08 14:24:32
 * @LastEditTime: 2021-12-08 17:09:03
 * 
 * reference url: https://bbs.huaweicloud.com/forum/forum/thread-57842-1-1.html
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _I2C_H_
#define _I2C_H_

#define IIC_OK		0
#define IIC_Err		1

#define IIC_RCU_GPIO    RCU_GPIOA
#define IIC_GPIO_PERIPH GPIOA
#define SCLK_PIN        GPIO_PIN_11
#define SDAT_PIN        GPIO_PIN_12

void IIC_Init(void);

void IIC_SpeedCtl(unsigned short speed);

_Bool I2C_WriteByte(unsigned char slaveAddr, unsigned char regAddr, unsigned char *byte);

_Bool I2C_ReadByte(unsigned char slaveAddr, unsigned char regAddr, unsigned char *val);

_Bool I2C_WriteBytes(unsigned char slaveAddr, unsigned char regAddr, unsigned char *buf, unsigned char num);

_Bool I2C_ReadBytes(unsigned char slaveAddr, unsigned char regAddr, unsigned char *buf, unsigned char num);

void IIC_Start(void);

void IIC_Stop(void);

_Bool IIC_WaitAck(unsigned int timeOut);

void IIC_Ack(void);

void IIC_NAck(void);

void IIC_SendByte(unsigned char byte);

unsigned char IIC_RecvByte(void);

#endif

