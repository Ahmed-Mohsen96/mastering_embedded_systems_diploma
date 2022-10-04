/*
 * MULTIPLEXING_7SEGEMENT.c
 *
 * Created: 10/4/2022 12:50:50 PM
 *  Author: soft
 */ 


#include <avr/io.h>
#include<util/delay.h>
#define F_CPU 8000000UL
int main(void)
{
	DDRB =0xff;
	int i,j;
    while(1)
    {
				
			for (i=0;i<10;i++)
			{
				for (j=0;j<10;j++)
				{
					PORTB=(0b0001<<4)|j ;
					_delay_ms(50);
					
					PORTB=(0b0010<<4)|i ;
					_delay_ms(50);
				}
				
				
				
			}
			
					
    }
}