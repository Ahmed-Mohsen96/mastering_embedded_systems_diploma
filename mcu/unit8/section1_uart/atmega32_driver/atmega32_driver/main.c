/*
 * atmega32_driver.c
 *
 * Created: 1/4/2023 12:47:34 PM
 * Author : soft
 */ 

#include "HAL/BUTTON_driver/button_driver.h"
#include "HAL/LED_driver/LED_driver.h"
#include "MCAL/ADC_driver/adc_driver.h"
#include "MCAL/interrupt_driver/interrupt_driver.h"
#include "MCAL/Timer_driver/TIMER0/timer0_driver.h"
#include "MCAL/Timer_driver/TIMER2/timer2_driver.h"
#include "MCAL/UART_driver/atmega32_uart_driver.h"
#include "HAL/LCD_driver/lcd.h"
int main(void)
{
	
   lcd_init();
    while (1) 
    {
		lcd_send_command(Display_on_Cursor_blinking);
		lcd_send_char('A');
		lcd_clear_screen();
		lcd_send_string("ahmed");
    }
}

