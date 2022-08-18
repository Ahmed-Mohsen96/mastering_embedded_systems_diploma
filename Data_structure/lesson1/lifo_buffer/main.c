/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: soft
 */

#include<stdio.h>
#include<stdlib.h>
#include "lifo.h"


//create static buffer
unsigned int buff1[5];


int main()
{
	int i,temp=0;
	LIFO_BUFFER_t uart_lifo,i2c_lifo;
	// static allocation
	lifo_init(&uart_lifo,buff1,5);
	//create dynamic buffer
	unsigned int* buff2=(unsigned int*)malloc(5*sizeof(unsigned int));
	lifo_init(&i2c_lifo,buff2,5);
	//adding item
	for(i=0;i<5;i++){
		if(lifo_add_item(&uart_lifo,i)==lifo_no_error)
			printf("uart lifo add :%d\n",i);
	}
	for(i=0;i<5;i++){
		if(lifo_get_item(&uart_lifo,&temp)==lifo_no_error)
					printf("uart lifo get :%d\n",temp);
		}







	return 0;
}
