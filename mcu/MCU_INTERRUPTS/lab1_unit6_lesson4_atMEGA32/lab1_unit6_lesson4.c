/*
 * lab1_unit6_lesson4.c
 *
 * Created: 9/28/2022 4:31:10 PM
 *  Author: soft
 */ 
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

	//PD5,6,7 output to led
	//PD2,3 as an input interrupt from switch
	
	
	


	// enable general interrupt
	//SREG |=(1<<7);
	
	//enable Int0 ,INT1, INt2
	
	
	
	
	

ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(100);
}
ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(100);
}
ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(100);
}
int main(void)
{
	DDRD |= (1<<5) | (1<<6) | (1<<7) ;
	GICR |=((1<<5)|(1<<6)|(1<<7));
	// make Int0 any logical change
	MCUCR |= ((1<<0));
	//MCUCR &=~(1<<)
	//make int1 rising edge
	MCUCR |= ((1<<2)|(1<<3));
	
	// make int2 falling edge
	MCUCSR &=~(1<<6);
	sei();
    while(1)
    {
	// make leds off
      PORTD &= ~((1<<5)|(1<<6)|(1<<7));
	  _delay_ms(100);
    }
}
