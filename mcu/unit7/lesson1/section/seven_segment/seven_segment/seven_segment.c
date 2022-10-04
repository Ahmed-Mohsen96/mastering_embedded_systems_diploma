/*
 * seven_segment.c
 *
 * Created: 10/4/2022 12:53:39 AM
 *  Author: soft
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xff;
	int arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x7,0x7f,0x6f};//{1,2,3,4}
	while(1){
		int i=0;
		for(i=0;i<10;i++)
		{
			PORTC = arr[i];
			_delay_ms(500);
		}
		_delay_ms(500);
		
	}		
  



}