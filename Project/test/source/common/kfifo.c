/*
 * @Descripttion: kfifo circle queue
 * @Author: Jerry
 * @Date: 2021-12-21 16:07:44
 * @LastEditTime: 2021-12-22 10:40:36
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#include "kfifo.h"

#define min(a,b) ((a) < (b) ? (a):(b))

int kFifoInit(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int size)
{
    if (!fifo)
        return -1;

    if(!buffer)
        return -1;

    fifo->buffer = buffer;
    fifo->size = size;
    fifo->in = fifo->out = 0;

    return 0;
}

unsigned int kFifoPut(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int len)
{
	unsigned int l;

	len = min(len, fifo->size - fifo->in + fifo->out);/*可能是缓冲区的空闲长度或者要写长度*/

	/* first put the data starting from fifo->in to buffer end*/
	//l = min(len, fifo->size - (fifo->in & (fifo->size -1)));
	l = min(len, fifo->size - (fifo->in % (fifo->size)));

	//memcpy((fifo->buffer + (fifo->in & (fifo->size -1))), buffer, l);
	memcpy((void *)(fifo->buffer + (fifo->in % (fifo->size))), buffer, l);

	/* then put the rest (if any) at the beginning of the buffer*/
	memcpy((void *)fifo->buffer, buffer + l, len - l);

	fifo->in += len;

	return len;
}

unsigned int kFifoGet(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int len)
{
    unsigned int l;

    len = min(len, fifo->in - fifo->out); /*可读数据*/

    /* first get the data from fifo->out until the end of the buffer*/
    //l = min(len, fifo->size - (fifo->out & (fifo->size -1)));
    l = min(len, fifo->size - (fifo->out % (fifo->size)));
    //memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size -1)), l);
    memcpy(buffer, (const void *)(fifo->buffer + (fifo->out % (fifo->size))), l);

    /* then get the rest (if any) from the beginning of the buffer*/
    memcpy(buffer + l, (const void *)fifo->buffer, len - l);

    fifo->out += len;

    return len;
}

unsigned int kFifoPeer(volatile kfifo_t *fifo, unsigned char *buffer, unsigned int len)
{
    unsigned int l;

    len = min(len, fifo->in - fifo->out); /*可读数据*/

    /* first get the data from fifo->out until the end of the buffer*/
    //l = min(len, fifo->size - (fifo->out & (fifo->size -1)));
	l = min(len, fifo->size - (fifo->out % (fifo->size)));
    //memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size -1)), l);
	memcpy(buffer, (const void *)(fifo->buffer + (fifo->out % (fifo->size))), l);

    /* then get the rest (if any) from the beginning of the buffer*/
    memcpy(buffer + l, (const void *)fifo->buffer, len - l);

    return len;
}

void kFifoReset(volatile kfifo_t *fifo)
{
    fifo->in = fifo->out = 0;
}

unsigned int kFifoLen(volatile kfifo_t *fifo)
{
    return fifo->in - fifo->out;
}

unsigned int kFifoAviable(volatile kfifo_t *fifo)
{
    return fifo->size - kFifoLen(fifo);
}

//full 1
unsigned int kFifoFull(volatile kfifo_t *fifo)
{
    return fifo->size == kFifoLen(fifo);
}

//empty 1
unsigned int kFifoEmpty(volatile kfifo_t *fifo)
{
    return fifo->in == fifo->out;
}
