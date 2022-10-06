/*
 * LCD.c
 *
 * Created: 10/4/2022 6:42:01 PM
 *  Author: soft
 */ 


#include "lcd.h"
#include "kepad.h"

int main(void)
{
	char keypad_pressed;
	lcd_init();
	keypad_init();
	
    while(1)
    {
		keypad_pressed=keypad_getkey();
		switch(keypad_pressed){
			case 'A':
				break;
			case '?':
				lcd_clear_screen();
				break;
			default:
				lcd_send_char(keypad_pressed);
		}
		
		
		//lcd_send_string("HELLO IN EMBEDEED SYSTEM DIPLOMA BY eG KEROLES SHENODA:");
		//lcd_clear_screen();
		//lcd_send_string("NUMBERS EXAMBLES:");
		//lcd_display_real_number(30.127);
      // lcd_send_string("   ");
	  // lcd_display_number(12);
	  // lcd_clear_screen();
	   //_delay_ms(500);
    }
}