/*
 * driver.h
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdint.h>
#include <stdio.h>

#define SET_BIT(ADDRESS,BIT)	ADDRESS|=(1<<BIT)
#define CLEAR_BIT(ADDRESS,BIT)	ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)	ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT)	((ADDRESS) & (1<<BIT)))

#define GPIO_PORTA	0X40010800
#define BASE_RCC	0X40021000

#define APB2ENR	*(volatile uint32_t*)(BASE_RCC + 0X18)

#define GPIOA_CRL *(volatile uint32_t*)(GPIO_PORTA + 0X00)
#define GPIOA_CRH	*(volatile uint32_t*)(GPIO_PORTA + 0X04)
#define GPIOA_IDR	*(volatile uint32_t*)(GPIO_PORTA + 0X08)
#define GPIOA_ODR	*(volatile uint32_t*)(GPIO_PORTA + 0X0C)
//APIS
void Delay(int ncount);
int getPressureVal();
void set_alarm_actuator(int i);
void GPIO_INITILAIZATION();

#endif /* DRIVER_H_ */
