/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Oct 8, 2022
 *      Author: soft
 */

#include "stm32f103c6_EXTI.h"
#include "stm32f103c6_gpio_driver.h"

/*
 * GENERIC variables
 */

void(*Gp_IRQ_CALLBACk[15])(void);
/*
 * GENERIC MACRO
 */

#define AFIO_GPIO_EXTI_Mapping(x)      (   (x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0   )

/*
 *   GENERIC FUNCTION
 */


void Enable_NVIC(uint8_t IRQ){
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;


	}

}

void disable_NVIC(uint8_t IRQ){
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_disable;
		break;


	}

}
void UPDATE_EXTI(EXTI_pinconfig_t* EXTI_Config){
	// 1- configure GPIO to be AF input -> floating input
	GPIO_PIN_Config_t pincfg;
	pincfg.GPIO_pin_number=EXTI_Config->EXTI_pin.GPIO_pin;
	pincfg.GPIO_mode=GPIO_mode_INPUT_flo;
	MCAL_GPIO_Init(EXTI_Config->EXTI_pin.GPIO_port, &pincfg);
	///////////////////////////////////////////////////////////
	// 2- update AFIO to route between EXTI line with port A,B,C,D
	uint8_t AFIO_EXTICR_index=EXTI_Config->EXTI_pin.EXTI_inputlinenubmer /4;
	uint8_t AFIO_EXTICR_position=(EXTI_Config->EXTI_pin.EXTI_inputlinenubmer /4)*4;

	//clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_index] &=~(0xf<<AFIO_EXTICR_position);

	AFIO->EXTICR[AFIO_EXTICR_index] |=((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_pin.GPIO_port)&0xf)<<AFIO_EXTICR_position);
	/////////////////////////////////////////////////////////////

	//3 - update rising or falling trigger
	EXTI->RTSR &=~(1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
	EXTI->FTSR &=~(1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);

	if(EXTI_Config->TRIGER_Case == EXTI_TRIGGER_RISING)
	{
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
	}
	else if(EXTI_Config->TRIGER_Case == EXTI_TRIGGER_FALLING)
	{
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);

	}else if(EXTI_Config->TRIGER_Case == EXTI_TRIGGER_RISINGandFALLING)
	{
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
	}


	// 4-update IRQ HAndling CALLBACK

	Gp_IRQ_CALLBACk[EXTI_Config->EXTI_pin.EXTI_inputlinenubmer]=EXTI_Config->p_IRQ_CALLBACk;

	//5- ENABLE ORDISABLE IRQ EXTI & NVIC

	if(EXTI_Config->IRQ_EN==EXTI_IRQ_Enable){
		EXTI->IMR |= (1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
		Enable_NVIC(EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
	}
	else{
		EXTI->IMR &=~ (1<<EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
		disable_NVIC(EXTI_Config->EXTI_pin.EXTI_inputlinenubmer);
	}





}

/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_DEInit
 * @brief 		-reset EXTI and NVIC
 * @param[in]    -
 * @param[in]    -
 * @retval       -none
 * Note          -
 */

void MCAL_EXTI_GPIO_DEInit(void){
	EXTI->EMR=0x0000000;
	EXTI->FTSR=0x00000000;
	EXTI->IMR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->SWIER=0x00000000;
	EXTI->PR=0xffffffff;  // write 1 to clear

	//disable EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_disable	;
	NVIC_IRQ7_EXTI1_disable	;
	NVIC_IRQ8_EXTI2_disable	;
	NVIC_IRQ9_EXTI3_disable	;
	NVIC_IRQ10_EXTI4_disable	;
	NVIC_IRQ23_EXTI5_9_disable	;
	NVIC_IRQ40_EXTI10_15_disable;


}

/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief 		-init EXTi
 * @param[in]    -
 * @param[in]    -
 * @retval       -none
 * Note          -
 */
void MCAL_EXTI_GPIO_Init(EXTI_pinconfig_t* EXTI_Config){
	UPDATE_EXTI(EXTI_Config);
}



/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Update
 * @brief 		-reset EXTI and NVIC
 * @param[in]    -
 * @param[in]    -
 * @retval       -none
 * Note          -
 */

void MCAL_EXTI_GPIO_Update(EXTI_pinconfig_t* EXTI_Config){
	UPDATE_EXTI(EXTI_Config);
}

/*
 * ISR FUNCTIONS
 */
void EXTI0_IRQHandler(void){
	//clear by write 1 into the pending register (EXTI_PR)
	EXTI->PR |=1<<0;
	//call IRQ_CALL
	Gp_IRQ_CALLBACk[0]();
}
void EXTI1_IRQHandler(void){
	//clear by write 1 into the pending register (EXTI_PR)
	EXTI->PR |=1<<1;
	//call IRQ_CALL
	Gp_IRQ_CALLBACk[1]();
}
void EXTI2_IRQHandler(void){
	//clear by write 1 into the pending register (EXTI_PR)
	EXTI->PR |=1<<2;
	//call IRQ_CALL
	Gp_IRQ_CALLBACk[2]();
}
void EXTI3_IRQHandler(void){
	//clear by write 1 into the pending register (EXTI_PR)
	EXTI->PR |=1<<3;
	//call IRQ_CALL
	Gp_IRQ_CALLBACk[3]();
}
void EXTI4_IRQHandler(void){
	//clear by write 1 into the pending register (EXTI_PR)
	EXTI->PR |=1<<4;
	//call IRQ_CALL
	Gp_IRQ_CALLBACk[4]();
}
void EXTI9_5_IRQHandler(void){
	if(EXTI->PR &1<<5) {EXTI->PR |= (1<<5); Gp_IRQ_CALLBACk[5]();}
	if(EXTI->PR &1<<6) {EXTI->PR |= (1<<6); Gp_IRQ_CALLBACk[6]();}
	if(EXTI->PR &1<<7) {EXTI->PR |= (1<<7); Gp_IRQ_CALLBACk[7]();}
	if(EXTI->PR &1<<8) {EXTI->PR |= (1<<8); Gp_IRQ_CALLBACk[8]();}
	if(EXTI->PR &1<<9) {EXTI->PR |= (1<<9); Gp_IRQ_CALLBACk[9]();}
}
void EXTI15_10_IRQHandler(void){
	if(EXTI->PR &1<<10) {EXTI->PR |= (1<<10); Gp_IRQ_CALLBACk[10]();}
	if(EXTI->PR &1<<11) {EXTI->PR |= (1<<11); Gp_IRQ_CALLBACk[11]();}
	if(EXTI->PR &1<<12) {EXTI->PR |= (1<<12); Gp_IRQ_CALLBACk[12]();}
	if(EXTI->PR &1<<13) {EXTI->PR |= (1<<13); Gp_IRQ_CALLBACk[13]();}
	if(EXTI->PR &1<<14) {EXTI->PR |= (1<<14); Gp_IRQ_CALLBACk[14]();}
	if(EXTI->PR &1<<15) {EXTI->PR |= (1<<15); Gp_IRQ_CALLBACk[15]();}
}


