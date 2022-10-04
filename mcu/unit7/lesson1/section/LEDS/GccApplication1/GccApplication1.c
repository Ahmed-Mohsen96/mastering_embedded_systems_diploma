#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>


int main()
{
	DDRA=0xff;
	DDRD |= (1<<0);
	unsigned char flag=0;
	while(1)
	{
		if((PIND >>0)&1)
		{
			if(flag==1){
				PORTA ^= (1<<1);
				while((PIND >>0)&1);
				
				
			}
			else if(flag==2)
			{
				PORTA ^= (1<<2);
				while((PIND >>0)&1);
				
			}
			else if(flag==3)
			{
				PORTA ^= (1<<3);
				while((PIND >>0)&1);
				
			}
			else if(flag==4)
			{
				PORTA ^= (1<<4);
				while((PIND >>0)&1);
				
			}
			else if(flag==5)
			{
				PORTA ^= (1<<5);
				while((PIND >>0)&1);
				
			}
			else if(flag==6)
			{
				PORTA ^= (1<<6);
				while((PIND >>0)&1);
				
			}
			else if(flag==7)
			{
				PORTA ^= (1<<7);
				while((PIND >>0)&1);
				
			}
			/*else if(flag==8)
			{
				PORTA =0;
				while((PIND >>0)&1);
				
			}*/
			else
			{
				flag=0;
				while((PIND >>0)&1);
				
			}
		}
		else
		{
			flag++;
			while(((PIND >>0)&1)==0);
		}
		
		
		
	}
}