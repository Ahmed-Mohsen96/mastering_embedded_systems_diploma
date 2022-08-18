/*
 * fifo.h
 *
 *  Created on: Aug 18, 2022
 *      Author: soft
 */

#ifndef FIFO_H_
#define FIFO_H_
#include<stdio.h>
#include "stdint.h"
//user configration

// select element type (uint8,uint16,.....)
#define element_type uint8_t
//create a static buffer
#define length1 5
element_type buffer[length1];
//fifo data types
typedef struct{
	unsigned int count;
	unsigned int length;
	element_type* base;
	element_type* head;
	element_type* tail;

}fifo_buf_t;
typedef enum{
	fifo_no_error,
	fifo_null,
	fifo_empty,
	fifo_full
}num_status_buf_t;
// fifo APIS
num_status_buf_t fifo_init(fifo_buf_t* fifo_buf,element_type* buf,unsigned int length);
num_status_buf_t fifo_enqueue(fifo_buf_t* fifo_buf,element_type item);
num_status_buf_t fifo_dequeue(fifo_buf_t* fifo_buf,element_type* item);
num_status_buf_t print_fifo(fifo_buf_t* fifo_buf);
num_status_buf_t fifo_buf_is_full(fifo_buf_t* fifo_buf);

#endif /* FIFO_H_ */
