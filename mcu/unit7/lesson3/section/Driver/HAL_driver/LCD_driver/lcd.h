/*
 * lcd.h
 *
 * Created: 10/4/2022 6:43:45 PM
 *  Author: soft
 */ 


#ifndef LCD_H_
#define LCD_H_
//
//#define F_CPU 8000000Ul
#include"stm32f103c6.h"
#include "stm32f103c6_gpio_driver.h"
//data port
//#define lcd_port GPIOA
//#define datadir_lcd_port DDRA
//control port
//#define lcd_control_port GPIOB
#define lcd_CTRL GPIOA
//#define datadir_lcd_control_port DDRB
//#define data_shift 0
#define EN_switch GPIO_PIN_10
#define RW_switch GPIO_PIN_9
#define RS_switch GPIO_PIN_8

//configure 8 or 4 mode
//#define eight_bit_mode
//#define four_bit_mode
//reg
#define  Set_8_bit 								0x38
#define  Set_4_bit 								0x28
#define  Entry_Mode 							0x06
#define  Display_off_Cursor_off 				0x08
#define  Display_on_Cursor_on 					0x0E
#define  Display_on_Cursor_off 					0x0C
#define  Display_on_Cursor_blinking 			0x0F
#define  Shift_entire_display_left  			0x18
#define  Shift_entire_display_right  			0x1C
#define  Move_cursor_left_by_one_character  	0x10
#define  Move_cursor_right_by_one_character  	0x14
#define  Clear_Display 							0x01
#define  lcd_begin_f_raw  						0x80
#define  lcd_begin_S_raw  						0xC0


GPIO_PIN_Config_t pincfg;
//APIS
void lcd_is_busy(void);
void lcd_kick(void);
void lcd_send_command(unsigned char command);
void lcd_send_char(unsigned char character);
void lcd_send_string(char *string);
void lcd_init(void);
void lcd_clear_screen();
void lcd_GotoXY(unsigned char line ,unsigned char position);
void lcd_display_number(int num);
void lcd_display_real_number(double number);




#endif /* LCD_H_ */
