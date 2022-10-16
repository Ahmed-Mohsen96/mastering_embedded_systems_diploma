/*
 * lcd.c
 *
 * Created: 10/4/2022 6:43:17 PM
 *  Author: soft
 */ 
#include "lcd.h"
#include"stm32f103c6.h"
#include "stm32f103c6_gpio_driver.h"



void wait_ms(int x){
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);
}

void lcd_init(void){
	wait_ms(20);
	//lcd_is_busy();
	//lcd_control_port |= ((1<<EN_switch)|(1<<RS_switch)|(1<<RW_switch));//output
	pincfg.GPIO_pin_number=EN_switch;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL,&pincfg );
	pincfg.GPIO_pin_number=RS_switch;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL,&pincfg );
	pincfg.GPIO_pin_number=RW_switch;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL,&pincfg );
//	//lcd_control_port &=~((1<<EN_switch)|(1<<RW_switch)|(1<<RS_switch)); //reset to 0



	//lcd_port =0xff; //output
	pincfg.GPIO_pin_number=GPIO_PIN_0;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_1;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_2;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_3;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_4;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_5;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_6;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_7;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);


	MCAL_GPIO_WRITE_PIN(lcd_CTRL, EN_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RW_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RS_switch, GPIO_PIN_RESET);
	wait_ms(15);
	lcd_clear_screen();


	lcd_send_command(Set_8_bit);
	lcd_send_command(Entry_Mode);
	lcd_send_command(lcd_begin_f_raw);
	lcd_send_command(Display_on_Cursor_blinking);
}
void lcd_is_busy(void){
	//lcd_port =0x00; //input
	pincfg.GPIO_pin_number=GPIO_PIN_0;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_1;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_2;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_3;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_4;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_5;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_6;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	pincfg.GPIO_pin_number=GPIO_PIN_7;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(lcd_CTRL, &pincfg);
	//lcd_control_port |= (1<<RW_switch); //read
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RW_switch, GPIO_PIN_SET);
	//lcd_control_port &=~(1<<RS_switch);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RS_switch, GPIO_PIN_RESET);
	lcd_kick();
	//lcd_port=0xff;
//	pincfg.GPIO_pin_number=GPIO_PIN_0;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_1;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_2;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_3;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_4;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_5;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_6;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
//	pincfg.GPIO_pin_number=GPIO_PIN_7;
//	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
//	pincfg.GPIO_speed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(lcd_port, &pincfg);
	//lcd_control_port &=~(1<<RW_switch);//write
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RW_switch, GPIO_PIN_RESET);
}
void lcd_kick(void){
	//lcd_control_port &=~(1<<EN_switch);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, EN_switch, GPIO_PIN_SET);
	wait_ms(50);
	//lcd_control_port |=(1<<EN_switch);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, EN_switch, GPIO_PIN_RESET);
}
void lcd_send_command(unsigned char command){
//#ifdef eight_bit_mode
	//lcd_is_busy();
	//lcd_data_port =command;
	MCAL_GPIO_WRITE_PORT(lcd_CTRL, command);
	//lcd_control_port &=~ ((1<<RW_switch)|(1<<RS_switch));
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RW_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RS_switch, GPIO_PIN_RESET);
	lcd_kick();
//#endif
//#ifdef four_bit_mode
//	lcd_is_busy();
//	lcd_data_port &=0x0f;
//	lcd_data_port |=(command &0xf0);
//	lcd_control_port &=~ ((1<<RW_switch)|(1<<RS_switch));
//	lcd_kick();
//	lcd_data_port =(lcd_data_port&0x0f)|(command<<4);
//	lcd_control_port &=~ ((1<<RW_switch)|(1<<RS_switch));
//	lcd_kick();
//#endif
}
void lcd_send_char(unsigned char character){
//#ifdef eight_bit_mode
	//lcd_is_busy();
	//lcd_data_port =character;
	MCAL_GPIO_WRITE_PORT(lcd_CTRL, character);
	//lcd_control_port |= (1<<RS_switch);
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RS_switch, GPIO_PIN_RESET);
	//lcd_control_port &=~(1<<RW_switch); //write
	MCAL_GPIO_WRITE_PIN(lcd_CTRL, RW_switch, GPIO_PIN_SET);


	lcd_kick();
//#endif
//#ifdef four_bit_mode
//	lcd_is_busy();
//	lcd_data_port =(lcd_data_port&0x0f)|(character&0xf0);
//
//	lcd_control_port |= ((1<<RS_switch));
//	lcd_control_port &=~(1<<RW_switch);
//	lcd_kick();
//	lcd_data_port =(lcd_data_port&0x0f)|(character<<4);
//	lcd_control_port |= ((1<<RS_switch));
//	lcd_control_port &=~(1<<RW_switch);
//	lcd_kick();
//#endif
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
			lcd_GotoXY(2,0);
		}
		else if(count ==32||count ==33)
		{
			lcd_clear_screen();
			lcd_GotoXY(1,0);
			count =0;
		}
	}


}

void lcd_clear_screen(){
	lcd_send_command(Clear_Display);

}
void lcd_GotoXY(unsigned char line ,unsigned char position){
	if(line ==1)
	{
		if(position<16 && position >=0)
		{
			lcd_send_command(lcd_begin_f_raw+position);
		}
	}
	else if(line ==2)
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
