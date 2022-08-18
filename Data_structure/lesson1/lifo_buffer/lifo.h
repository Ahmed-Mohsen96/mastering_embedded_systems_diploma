/*
 * LIFO.h
 *
 *  Created on: Aug 18, 2022
 *      Author: soft
 */

#ifndef LIFO_H_
#define LIFO_H_

// variables definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_BUFFER_t;

typedef enum{
	lifo_null,
	lifo_empty,
	lifo_no_error,
	lifo_full

}ENUM_BUFFER_Status;
// APIS
ENUM_BUFFER_Status lifo_init(LIFO_BUFFER_t* lifo_buf,unsigned int* buf,unsigned int length);
ENUM_BUFFER_Status lifo_add_item(LIFO_BUFFER_t* lifo_buf,unsigned int item);
ENUM_BUFFER_Status lifo_get_item(LIFO_BUFFER_t* lifo_buf,unsigned int* item);

#endif /* LIFO_H_ */
