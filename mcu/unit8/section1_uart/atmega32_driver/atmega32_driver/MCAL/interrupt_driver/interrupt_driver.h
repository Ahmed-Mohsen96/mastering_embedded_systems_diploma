/*
 * interrupt_driver.h
 *
 * Created: 12/13/2022 12:17:40 AM
 *  Author: soft
 */ 


#ifndef INTERRUPT_DRIVER_H_
#define INTERRUPT_DRIVER_H_

//=============================
//   includes
//=============================
#include "../utilites/Registers.h"
#include "../utilites/macro.h"
#include "../utilites/platform_types.h"

////////////////////////////////////
//=================================
//         macros
//=================================
#define EXTI_INT_0  __vector_1
#define EXTI_INT_1  __vector_2
#define EXTI_INT_2  __vector_3
#define USART_RXC  __vector_13     

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#define EN_gINT()     (mySREG |= (1<<7))

//////////////////////////////////
//Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	/* ISC11 ISC10 Description
	0 0 The low level of INT1 generates an interrupt request.
	0 1 Any logical change on INT1 generates an interrupt request.
	1 0 The falling edge of INT1 generates an interrupt request.
	1 1 The rising edge of INT1 generates an interrupt request.*/
typedef enum
{
	
	EXTI_1_low_level,
	EXTI_1_any_logical,
	EXTI_1_falling_edge,
	EXTI_1_rising_edge,
	
	}EXTI_1_sence;
	
typedef enum
{
	
	EXTI_0_low_level,
	EXTI_0_any_logical,
	EXTI_0_falling_edge,
	EXTI_0_rising_edge,
	
}EXTI_0_sence;

typedef enum
{
	
	
	EXTI_2_falling_edge,
	EXTI_2_rising_edge,
	
}EXTI_2_sence;

typedef enum
{
	
	ExTI_disable,
	EXTI_0_enable,
	EXTI_1_enable,
	EXTI_2_enable,
	EXTI_all_enable,
	
	
}EXTI_req_en;




typedef struct  
{
	EXTI_req_en  EXTI_req_enable;
	EXTI_0_sence EXTI_0_sensing;
	EXTI_1_sence EXTI_1_sensing;
	EXTI_2_sence EXTI_2_sensing;
	
}EXTI_confiq_t;

//=================================
//       APIS
//=================================
error_state  EXTI_init();


extern EXTI_confiq_t EXTI_config;
#endif /* INTERRUPT_DRIVER_H_ */