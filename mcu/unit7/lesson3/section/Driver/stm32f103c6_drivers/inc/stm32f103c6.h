/*
 * stm32f103c6.h
 *
 *  Created on: Oct 8, 2022
 *      Author: soft
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

/*-------------------------
 *		 includes
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* ------------------------
 * BASE ADDRESSES for memories
 */
#define FLASH_mem_BASE                      0x08000000
#define system_mem_BASE                     0x1ffff000

#define SRAM_mem_BASE                       0x20000000
#define peripherals_BASE                    0x40000000

#define cortex_m3_internal_peripherals      0xE0000000

/*
 * base addresses for AHB peripherals
 */

// RCC
#define RCC_BASE                            0x40021000

/*
 * base addresses for APB2 peripherals
 */
//gpio
//A,B fully included in LQFP48 package
#define GPIOA_BASE                          0x40010800
#define GPIOB_BASE                          0x40010C00

//C,D partial included in LQFP48 package
#define GPIOC_BASE                          0x40011000
#define GPIOD_BASE                          0x4001400

//E not  included in LQFP48 package

#define GPIOE_BASE                          0x40011800

//EXTI

#define EXTI_BASE                           0x40010400
// AFIO
#define AFIO_BASE                           0x40010400

//---------------------------------------------------------------

/*
 * peripherals registers
 */


/*
 * peripherals registers GPIO
 */
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;


}GPIO_typedef;
/*
 * peripherals registers RCC
 */
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;


}RCC_typedef;
/*
 * peripherals registers AFIO
 */
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;//0x18
	volatile uint32_t MAPR2;



}AFIO_typedef;
/*
 * peripherals registers EXTI
 */
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_typedef;

//==============================================================

/*
 * peripherals instants
 */

#define GPIOA                  ((GPIO_typedef *)GPIOA_BASE)
#define GPIOB                  ((GPIO_typedef *)GPIOB_BASE)
#define GPIOC                  ((GPIO_typedef *)GPIOC_BASE)
#define GPIOD                  ((GPIO_typedef *)GPIOD_BASE)
#define GPIOE                  ((GPIO_typedef *)GPIOE_BASE)

#define EXTI                   ((EXTI_typedef *)EXTI_BASE)

#define RCC                    ((RCC_typedef *)RCC_BASE)

#define AFIO                   ((AFIO_typedef *)AFIO_BASE)


//=======================================================

/*
 * clock macros
 */

#define GPIOA_EN_CLK()       (RCC->APB2ENR |= (1<<2))
#define GPIOB_EN_CLK()       (RCC->APB2ENR |= (1<<3))
#define GPIOC_EN_CLK()       (RCC->APB2ENR |= (1<<4))
#define GPIOD_EN_CLK()       (RCC->APB2ENR |= (1<<5))
#define GPIOE_EN_CLK()       (RCC->APB2ENR |= (1<<6))


#define AFIO_EN_CLK()       (RCC->APB2ENR |= (1<<0))












#endif /* INC_STM32F103C6_H_ */
