/*
 * buton_driver.c
 *
 * Created: 12/6/2022 11:39:55 AM
 *  Author: soft
 */ 


#include "button_driver.h"

void button_init(uint8_t button_port,uint8_t buttonpin)
{
	DIO_init(button_port,buttonpin,IN);
	
}

void button_read(uint8_t button_port,uint8_t buttonpin,uint8_t *value)
{
	 DIO_read(button_port,buttonpin,value);
}
