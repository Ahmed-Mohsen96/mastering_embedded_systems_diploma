/*
 * driver.c
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#include "driver.h"

void Delay(int ncount){
	for(;ncount!=0;ncount--);
}
int getPressureVal(){
	return (GPIOA_IDR & 0XFF);
}
void set_alarm_actuator(int i){
	if(i==1)
	{
		SET_BIT(GPIOA_ODR,13);
	}
	else if(i==0)
	{
		CLEAR_BIT(GPIOA_ODR,13);
	}
}
void GPIO_INITILAIZATION(){
	SET_BIT(APB2ENR,2);
	GPIOA_CRL &= 0xff0fffff;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x22222222;
}
