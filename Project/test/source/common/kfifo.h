/*
 * @Descripttion: kfifo circle queue
 * @Author: Jerry
 * @Date: 2021-12-21 16:07:50
 * @LastEditTime: 2021-12-22 10:40:20
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _KFIFO_H_
#define _KFIFO_H_

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct kfifo
{
    volatile unsigned char *buffer;/* the buffer holding the data*/
    unsigned int size;/* the size of the allocated buffer*/
    volatile unsigned int in;/* data is added at offset (in % size)*/
    volatile unsigned int out;/* data is extracted from off. (out % size)*/
}kfifo_t;

extern int kFifoInit(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int size);
extern unsigned int kFifoPut(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int len);
extern unsigned int kFifoGet(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int len);
extern unsigned int kFifoPeer(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int len);
extern void kFifoReset(volatile kfifo_t *fifo);
extern unsigned int kFifoLen(volatile kfifo_t *fifo);
extern unsigned int kFifoAviable(volatile kfifo_t *fifo);
extern unsigned int kFifoFull(volatile kfifo_t *fifo); //full 1
extern unsigned int kFifoEmpty(volatile kfifo_t *fifo); //empty 1

#endif
