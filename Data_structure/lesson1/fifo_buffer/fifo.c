/*
 * fifo.c
 *
 *  Created on: Aug 18, 2022
 *      Author: soft
 */

#include"fifo.h"

num_status_buf_t fifo_init(fifo_buf_t* fifo_buf,element_type* buf,unsigned int length){
	if(buf=='\0')
		return fifo_null;
	fifo_buf->base=buf;
	fifo_buf->head=buf;
	fifo_buf->tail=buf;
	fifo_buf->length=length;
	fifo_buf->count=0;
	//buf full
	if(fifo_buf->count==fifo_buf->length)
		return fifo_full;
	return fifo_no_error;

}
num_status_buf_t fifo_enqueue(fifo_buf_t* fifo_buf,element_type item){
	if(!fifo_buf->tail ||!fifo_buf->head ||!fifo_buf->base )
		return fifo_null;
	//check full
	if(fifo_buf->count==fifo_buf->length)
		return fifo_full;
	*(fifo_buf->head)=item;

	fifo_buf->count ++;
	//fifo circular
	if(fifo_buf->head==(fifo_buf->base + (fifo_buf->length * sizeof(element_type))))
		fifo_buf->head==fifo_buf->base;
	fifo_buf->head++;

	return fifo_no_error;

}
num_status_buf_t fifo_dequeue(fifo_buf_t* fifo_buf,element_type* item){
	if(!fifo_buf->tail ||!fifo_buf->head ||!fifo_buf->base )
		return fifo_null;
	//check empty
	if(fifo_buf->count==0)
		return fifo_empty;
	*item=*(fifo_buf->tail);
	fifo_buf->count --;
	if(fifo_buf->tail==(fifo_buf->tail + (fifo_buf->length * sizeof(element_type))))
		fifo_buf->tail==fifo_buf->base;
	fifo_buf->tail++;
	return fifo_no_error;

}
num_status_buf_t print_fifo(fifo_buf_t* fifo_buf){
	element_type i,*temp;
	if(fifo_buf->count==0)
			return fifo_empty;
	temp=fifo_buf->tail;
	printf("========fifo print=========\n");
	for(i=0;i<fifo_buf->count;i++)
	{
		printf("\t %x \n",*temp);
		temp++;
	}
	printf("\n==================\n");

}
num_status_buf_t fifo_buf_is_full(fifo_buf_t* fifo_buf){
	if(!fifo_buf->tail ||!fifo_buf->head ||!fifo_buf->base )
			return fifo_null;
		//check full
		if(fifo_buf->count==fifo_buf->length)
			return fifo_full;
}

