/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include"stm32f103c6.h"
#include "stm32f103c6_gpio_driver.h"


void RCC_init()
{
	//enable rcc pa
	GPIOA_EN_CLK();
	//enable rcc pb
	GPIOB_EN_CLK();
}
void GPIO_init()
{
	GPIO_PIN_Config_t pincfg;
	//pA1 input rest state
	pincfg.GPIO_pin_number=GPIO_PIN_1;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(GPIOA,&pincfg);




	//pB1 (output push pull mode)
	pincfg.GPIO_pin_number=GPIO_PIN_1;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB,&pincfg);

	//pa13 input floating
	pincfg.GPIO_pin_number=GPIO_PIN_13;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(GPIOA,&pincfg);
	//pB13 (output push pull mode)
	pincfg.GPIO_pin_number=GPIO_PIN_13;
	pincfg.GPIO_mode=GPIO_mode_OUTPUT_PP;
	pincfg.GPIO_speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB,&pincfg);

}
void wait_ms(int x){
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);
}
int main(void)
{
	RCC_init();
	GPIO_init();

	while(1){
		if(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_1)==0) //single press
		{
			MCAL_GPIO_TOGGLE_PIN(GPIOB,GPIO_PIN_1);
			while(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_1)==0);
		}
		if(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_13)==1) //single press
		{
			MCAL_GPIO_TOGGLE_PIN(GPIOB,GPIO_PIN_13);

		}
		wait_ms(1);


	}
}
