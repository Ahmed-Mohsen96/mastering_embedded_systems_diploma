/*
 * LED_driver.c
 *
 * Created: 12/6/2022 10:30:26 AM
 *  Author: soft
 */ 
#include "LED_driver.h"

void led_init(uint8_t ledport,uint8_t ledpin)
{
	DIO_init(ledport,ledpin,OUT);
}

void led_off(uint8_t ledport,uint8_t ledpin)
{
	DIO_write(ledport,ledpin,LOW);
}

void led_on(uint8_t ledport,uint8_t ledpin)
{
	DIO_write(ledport,ledpin,HIGH);
	
}

void led_toggle(uint8_t ledport,uint8_t ledpin)
{
	DIO_toggle(ledport,ledpin);
}