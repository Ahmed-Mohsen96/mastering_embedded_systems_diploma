/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
//#include "main.h"
#include <stdint.h>

#define RCC_BASE 	0x40021000
#define PORTA_BASE  0x40010800

#define RCC_APB2ENR 	*(volatile unsigned int *) (RCC_BASE+0x18)
#define GPIO_CRH 		*(volatile unsigned int *) (PORTA_BASE+0x04)
#define GPIO_ODR 		*(volatile unsigned int *) (PORTA_BASE+0x0C)

int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIO_CRH =0XFF0FFFFF;
	GPIO_CRH |= 00200000;
	while(1)
	{
		GPIO_ODR |=1<<13;
		for(int i=0;i<5000;i++);
		GPIO_ODR &=~(1<<13);
		for(int i=0;i<5000;i++);

	}

	return 0;

}
