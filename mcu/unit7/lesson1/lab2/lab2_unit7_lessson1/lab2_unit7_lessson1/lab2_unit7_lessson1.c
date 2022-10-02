/*
 * lab2_unit7_lessson1.c
 *
 * Created: 10/2/2022 5:18:25 PM
 *  Author: soft
 */ 

#include <stdint.h>
#include <stdio.h>
//#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 8000000UL

// GPIOD
#define PORTD *(volatile uint8_t*)0x32
#define PIND  *(volatile uint8_t*)0x30
#define DDRD  *(volatile uint8_t*)0x31

void wait_ms(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<2550;j++);
}
int main(void)
{
	//pd 5,6,7 output led
	DDRD |= ((1<<5)|(1<<7)|(1<<6));
	//pd 4 output buzzer
	DDRD |= 1<<4;
	//turn off all leds on port
	
    while(1)
    {
		
		
		PORTD |=(1<<5);
		_delay_ms(1000);
		PORTD &=~(1<<5);
		_delay_ms(1000);
		PORTD |=(1<<6);
		_delay_ms(1000);
		PORTD &=~(1<<6);
		_delay_ms(1000);
		//_delay_ms(1000);
		PORTD |=(1<<7);
		_delay_ms(1000);
		PORTD &=~(1<<7);
		_delay_ms(1000);
		//_delay_ms(1000);
		PORTD |=(1<<4);
		_delay_ms(1000);
		PORTD &=~(1<<4);
		_delay_ms(1000);
		
		
		
		
		
		
        
    }
}