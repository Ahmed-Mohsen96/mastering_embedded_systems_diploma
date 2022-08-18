/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: soft
 */

#include"fifo.h"




int main()
{
	fifo_buf_t uart_fifo;
	element_type i,temp=0;
	if(fifo_init(&uart_fifo, buffer, length1)==fifo_no_error)
		printf("======fifo init done =============\n");
	for(i=0;i<7;i++){
		if(fifo_enqueue(&uart_fifo, i)==fifo_no_error)
			printf("fifo enqueue (%x)-----done\n",i);
		else
			printf("fifo enqueue (%x)-----fail\n",i);
	}
	print_fifo(&uart_fifo);
	printf("fifo dequeue==== %x\n",temp);
	fifo_dequeue(&uart_fifo, &temp);
	temp++;
	printf("fifo dequeue====%x \n",temp);
	fifo_dequeue(&uart_fifo, &temp);

	print_fifo(&uart_fifo);



	return 0;
}
