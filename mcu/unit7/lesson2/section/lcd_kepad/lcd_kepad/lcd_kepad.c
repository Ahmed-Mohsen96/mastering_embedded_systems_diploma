/*
 * LCD.c
 *
 * Created: 10/4/2022 6:42:01 PM
 *  Author: soft
 */ 


#include "lcd.h"
#include "kepad.h"
#include <string.h>
#include <stdlib.h>
void calculate(char op1[],char op2[],char process){
	lcd_GotoXY(2,0);
	if(process == '+'){
		int num = atoi(op1) + atoi(op2);
		lcd_display_number(num);
	}
	if(process == '-'){
		int num = atoi(op1) - atoi(op2);
		lcd_display_number(num);
	}
	if(process == '*'){
		int num = atoi(op1) * atoi(op2);
		lcd_display_number(num);
	}
	if(process == '/'){
		float num = atof(op1) / atof(op2);
		lcd_display_number(num);
	}
	
}
int main(void)
{
	char keypad_pressed;
	lcd_init();
	keypad_init();
char operand1[16]={};
char operand2[16] ={};
int count1 =0;
int count2 =0;
char process;
int flag=0;
    while(1)
    {
		keypad_pressed=keypad_getkey();
		switch(keypad_pressed){
			case 'A':
				break;
			case '?':
				lcd_clear_screen();
				for(int i=0; i<16; i++){
					operand1[i] ='\0';
					operand2[i] ='\0';
				}
				count1=0;
				count2=0;
				flag=0;
				break;
			default:
				 if((keypad_pressed == '+') | (keypad_pressed == '-')| (keypad_pressed == '*')|(keypad_pressed == '/')){
					 lcd_send_char(keypad_pressed);
					 _delay_ms(1);
					 flag =1;
					 process = keypad_pressed;
				 }
				 else if(keypad_pressed == '='){
					 lcd_send_char(keypad_pressed);
					 _delay_ms(1);
					 calculate(operand1,operand2,process);
					 count1 =0;
					 count2=0;
					 flag=0;
				 }
				 else{
					 if(flag == 0){
						 lcd_send_char(keypad_pressed);
						 _delay_ms(1);
						 operand1[count1] = keypad_pressed;
						 count1++;
					 }
					 else if(flag == 1){
						 lcd_send_char(keypad_pressed);
						 _delay_ms(1);
						 operand2[count2] = keypad_pressed;
						 count2++;
					 }
				 }
							
		}
    }
	
}