/*
 * kepad.c
 *
 * Created: 10/6/2022 1:32:15 PM
 *  Author: soft
 */ 
#include "kepad.h"
int keypad_row[]={r0,r1,r2,r3};
int keypad_col[]={c0,c1,c2,c3};
void keypad_init(){
	datadir_keypad &=~ ((1<<r0)|(1<<r1)|(1<<r2)|(1<<r3)); //input
	datadir_keypad |= ((1<<c0)|(1<<c1)|(1<<c2)|(1<<c3));
	keypad_port =0xff;
}
char keypad_getkey(){
	int i,j;
	for(i=0;i<4;i++)
	{
		keypad_port |= ((1<<keypad_col[0])|(1<<keypad_col[1])|(1<<keypad_col[2])|(1<<keypad_col[3]));
		keypad_port &=~(1<<keypad_col[i]);
		for(j=0;j<4;j++){
			if(!(keypad_pin&(1<<keypad_row[j])))// check key pressed
			{
				while(!(keypad_pin&(1<<keypad_row[j]))); //single press
				switch(i)
				{
					case 0:
						if(j==0) return '7';
						else if(j==1) return '4';
						else if(j==2) return '1';
						else if(j==3) return '?';
						break;
					case 1:
						if(j==0) return '8';
						else if(j==1) return '5';
						else if(j==2) return '2';
						else if(j==3) return '0';
						break;
					case 2:
						if(j==0) return '9';
						else if(j==1) return '6';
						else if(j==2) return '3';
						else if(j==3) return '=';
						break;
					case 3:
						if(j==0) return '/';
						else if(j==1) return '*';
						else if(j==2) return '-';
						else if(j==3) return '+';
						break;
				}
			}
		}
	}
	
	return 'A';// if no keys ispressed
}