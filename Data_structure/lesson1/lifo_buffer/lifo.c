/*
 * LIFO.c
 *
 *  Created on: Aug 18, 2022
 *      Author: soft
 */

#include "lifo.h"

ENUM_BUFFER_Status lifo_init(LIFO_BUFFER_t* lifo_buf,unsigned int* buff,unsigned int length){
	//check lifo null
	if(!lifo_buf||!lifo_buf->head||!lifo_buf->base)
		return lifo_null;
	lifo_buf->base=buff;
	lifo_buf->head=buff;
	lifo_buf->length=length;
	lifo_buf->count=0;
	// check lifo full
	//if(buff->head >= (buff->base + buff->count * 4))
	if(lifo_buf->count == lifo_buf->length)
		return lifo_full;
	// else no_error
	return lifo_no_error;
}
ENUM_BUFFER_Status lifo_add_item(LIFO_BUFFER_t* lifo_buf,unsigned int item){

	//check lifo null
	if(!lifo_buf||!lifo_buf->head||!lifo_buf->base)
		return lifo_null;
	// check lifo full
	//if(buff->head >= (buff->base + buff->count * 4))
	if(lifo_buf->count == lifo_buf->length)
		return lifo_full;
	// add item
	*(lifo_buf->head)=item;
	lifo_buf->head ++;
	lifo_buf->count ++;

	return lifo_no_error;

}
ENUM_BUFFER_Status lifo_get_item(LIFO_BUFFER_t* lifo_buf,unsigned int* item){

	//check lifo null
	if(!lifo_buf||!lifo_buf->head||!lifo_buf->base)
		return lifo_null;
	// check lifo empty
	//if(buff->base == buff->head)
	if(lifo_buf->count == 0)
		return lifo_empty;
	// get item
	lifo_buf->head --;
	*item =*(lifo_buf->head);
	lifo_buf->count--;
	return lifo_no_error;
}

