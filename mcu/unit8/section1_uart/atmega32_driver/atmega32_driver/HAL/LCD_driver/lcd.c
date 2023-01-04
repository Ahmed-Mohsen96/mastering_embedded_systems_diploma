/*
 * lcd.c
 *
 * Created: 10/4/2022 6:43:17 PM
 *  Author: soft
 */ 
#include "lcd.h"

void lcd_init(void){
	_delayms(20);
	//lcd_is_busy();
	datadir_lcd_control_port |= ((1<<EN_switch)|(1<<RS_switch)|(1<<RW_switch));//output
	lcd_control_port &=~((1<<EN_switch)|(1<<RW_switch)|(1<<RS_switch)); //set to 0
	
	datadir_lcd_port =0xff; //output
	_delayms(15);
	
	lcd_clear_screen();
	
	#ifdef eight_bit_mode
		lcd_send_command(Set_8_bit);
	#endif
	#ifdef four_bit_mode
		//lcd_send_command(0x02);
		lcd_send_command(Set_4_bit);
	#endif
		lcd_send_command(Entry_Mode);
		lcd_send_command(lcd_begin_f_raw);
		lcd_send_command(Display_on_Cursor_blinking);
}
void lcd_is_busy(void){
	datadir_lcd_port =0x00; //input
	lcd_control_port |= (1<<RW_switch); //read
	lcd_control_port &=~(1<<RS_switch);
	lcd_kick();
	datadir_lcd_port=0xff;
	lcd_control_port &=~(1<<RW_switch);//write
	
}
void lcd_kick(void){
	lcd_control_port &=~(1<<EN_switch);
	
	_delayms(50);
	lcd_control_port |=(1<<EN_switch);
	
}
void lcd_send_command(unsigned char command){
	#ifdef eight_bit_mode
		lcd_is_busy();
		lcd_data_port =command;
		lcd_control_port &=~ ((1<<RW_switch)|(1<<RS_switch));
		lcd_kick();
	#endif 
	#ifdef four_bit_mode
	lcd_is_busy();
	lcd_data_port &=0x0f;
	lcd_data_port |=(command &0xf0);
	lcd_control_port &=~ ((1<<RW_switch)|(1<<RS_switch));
	lcd_kick();
	lcd_data_port =(lcd_data_port&0x0f)|(command<<4);
	lcd_control_port &=~ ((1<<RW_switch)|(1<<RS_switch));
	lcd_kick();
	#endif
}
void lcd_send_char(unsigned char character){
	#ifdef eight_bit_mode
	lcd_is_busy();
	lcd_data_port =character;
	lcd_control_port |= (1<<RS_switch);
	lcd_control_port &=~(1<<RW_switch); //write
	
	
	lcd_kick();
	#endif
	#ifdef four_bit_mode
	lcd_is_busy();
	lcd_data_port =(lcd_data_port&0x0f)|(character&0xf0);
	
	lcd_control_port |= ((1<<RS_switch));
	lcd_control_port &=~(1<<RW_switch);	
	lcd_kick();
	lcd_data_port =(lcd_data_port&0x0f)|(character<<4);
	lcd_control_port |= ((1<<RS_switch));
	lcd_control_port &=~(1<<RW_switch);
	lcd_kick();
	#endif
}
void lcd_send_string(char *string){
	
	//lcd_is_busy();
	int count=0; //count how much char on line 
	while(*string>0)
	{
		count ++;
		lcd_send_char(*string++);
		if(count==16)
		{
			lcd_GotoXY(1,0);
		}
		else if(count ==32||count ==33)
		{
			lcd_clear_screen();
			lcd_GotoXY(0,0);
			count =0;
		}
	}
	
	
}

void lcd_clear_screen(){
	lcd_send_command(Clear_Display);
	
}
void lcd_GotoXY(unsigned char line ,unsigned char position){
	if(line ==0)
	{
		if(position<16 && position >=0)
		{
			lcd_send_command(lcd_begin_f_raw+position);
		}
	}
	else if(line ==1)
	{
		if(position<16 && position >=0)
		{
			lcd_send_command(lcd_begin_S_raw+position);
		}
	}
}
void lcd_display_number(int num){
	char str[7];
	sprintf(str,"%d",num);
	lcd_send_string(str);
}
void lcd_display_real_number(double number){
	char str[16];
	char *tmpsign=(number<0)?"-":"";
	float tempvalue=(number<0)?-number:number;
	
	int tmpint1=tempvalue;
	float tmpfrac= tempvalue - tmpint1;
	int tmpint2=tmpfrac * 10000;
	
	sprintf(str,"%s%d.%04d",tmpsign,tmpint1,tmpint2);
	lcd_send_string(str);
}