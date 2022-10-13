/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Oct 8, 2022
 *      Author: soft
 */

#include<stm32f103c6_gpio_driver.h>


uint8_t GETPOSITION_CRLH(uint16_t pinnumber){
	switch(pinnumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;


	}
	return 0;
}

/**================================================================
 * @Fn			-GPIO_Init
 * @brief 		-this function initiate GPIOX and PINY
 * @param[in]    -GPIOX
 * @param[in]    -PINY
 * @retval       -none
 * Note          -
 */
void MCAL_GPIO_Init(GPIO_typedef *GPIOX,GPIO_PIN_Config_t *PINConfig){
	//Port configuration register low (GPIOx_CRL) (x=A..G) from pin 0 to 7

	//Port configuration register high (GPIOx_CRH) (x=A..G) from pin 8 to 15
	volatile uint32_t *configregister=NULL;
	uint8_t pin_config=0;

	configregister=(PINConfig->GPIO_pin_number<8? &GPIOX->CRL : &GPIOX->CRH );
	//clear CNFy[1:0]:MODE[1:0]
	(*configregister) &=~(0xf<<GETPOSITION_CRLH(PINConfig->GPIO_pin_number));
	//	In output mode (MODE[1:0] > 00):
	//	00: General purpose output push-pull
	//	01: General purpose output Open-drain
	//	10: Alternate function output Push-pull
	//	11: Alternate function output Open-drain

	if((PINConfig->GPIO_mode == GPIO_mode_OUTPUT_AF_OD)||(PINConfig->GPIO_mode==GPIO_mode_OUTPUT_AF_PP)||(PINConfig->GPIO_mode==GPIO_mode_OUTPUT_OD)||(PINConfig->GPIO_mode==GPIO_mode_OUTPUT_PP))
	{
		//set CNFy[1:0]:MODE[1:0]
		pin_config= ((((PINConfig->GPIO_mode -4)<<2) | (PINConfig->GPIO_speed))&0x0f);
	}
	else // input mode
	{
		if((PINConfig->GPIO_mode == GPIO_mode_INPUT_flo)||(PINConfig->GPIO_mode == GPIO_mode_analog))
		{
			//set CNFy[1:0]:MODE[1:0]
			pin_config= ((((PINConfig->GPIO_mode )<<2) | (PINConfig->GPIO_speed))&0x0f);
		}
		else if(PINConfig->GPIO_mode == GPIO_mode_output_AF_input)
		{
			//set CNFy[1:0]:MODE[1:0]
			pin_config= ((((GPIO_mode_output_AF_input )<<2) | (PINConfig->GPIO_speed))&0x0f);


		}
		else //pu pd
		{
			pin_config= ((((GPIO_mode_INPUT_PU )<<2) |0x0)&0x0f);
			if(PINConfig->GPIO_mode == GPIO_mode_INPUT_PU)
			{
				//pxoDR =1 input pullup
				GPIOX->ODR |= PINConfig->GPIO_pin_number;
			}
			else//pxoDR =0 input pulldown
			{
				GPIOX->ODR &=~ PINConfig->GPIO_pin_number;
			}

		}
	}
	//write on CRH CRL

	(*configregister) |=((pin_config)<<GETPOSITION_CRLH(PINConfig->GPIO_pin_number));



}
/**================================================================
 * @Fn			-GPIO_DEInit
 * @brief 		-this function reset GPIOX
 * @param[in]    -GPIOX
 * @retval       -none
 * Note          -
 */

void MCAL_GPIO_DEInit(GPIO_typedef *GPIOX){

	//GPIOX->BRR =0x00000000;
	//GPIOX->BSRR=0x00000000;
	//GPIOX->CRH=0x44444444;
	//GPIOX->CRL=0x44444444;
	////GPIOX->IDR= ; //(READONLY)
	//GPIOX->LCKR =0x00000000;
	//GPIOX->ODR=0x00000000;

	// or ypu can use the reset controler
	// apB2
	if(GPIOX==GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &=~ (1<<2);
	}
	else if(GPIOX==GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &=~ (1<<3);
	}
	else if(GPIOX==GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &=~ (1<<4);

	}
	else if(GPIOX==GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &=~ (1<<5);

	}
	else if(GPIOX==GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &=~ (1<<6);
	}




}
/**================================================================
 * @Fn			-GPIO__READ_PIN
 * @brief 		-this function read specific pin
 * @param[in]    -GPIOX
 * @param[in]    -piny
 * @retval       -pin statues according to @ref GPIO_PIN_status
 * Note          -
 */
uint8_t MCAL_GPIO_READ_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq){

	uint8_t bitstatus;
	if(((GPIOX->IDR)&pinconfiq) != (uint32_t)GPIO_PIN_RESET){
		bitstatus=GPIO_PIN_SET;
	}
	else
	{
		bitstatus=GPIO_PIN_RESET;
	}

	return bitstatus;


}
/**================================================================
 * @Fn			-GPIO__READ_Port
 * @brief 		-this function read specific port
 * @param[in]    -GPIOX
 * @retval       -port statues according to @ref GPIO_PORT_status
 * Note          -
 */
uint16_t MCAL_GPIO_READ_PORT(GPIO_typedef *GPIOX){

	uint16_t port_value;

	port_value=(uint16_t)(GPIOX->IDR);
	return port_value;




}
/**================================================================
 * @Fn			-MCAL_GPIO_WRITE_PIN
 * @brief 		-this function write specific pin
 * @param[in]    -GPIOX
 * @param[in]    -piny
 * @retval       -none
 * Note          -
 */
void MCAL_GPIO_WRITE_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq,uint8_t value){

	if(value != GPIO_PIN_RESET)
	{
		//GPIOX->ODR |= pinconfiq;
		GPIOX->BSRR=(uint32_t)pinconfiq;
	}
	else
	{
		GPIOX->BRR=(uint32_t)pinconfiq;

	}

}
/**================================================================
 * @Fn			-MCAL_GPIO_WRITE_port
 * @brief 		-this function write specific port
 * @param[in]    -GPIOX
 * @retval       -none
 * Note          -
 */
void MCAL_GPIO_WRITE_PORT(GPIO_typedef *GPIOX,uint16_t value){

	GPIOX->ODR=(uint32_t)value;

}
/**================================================================
 * @Fn			-MCAL_GPIO_TOOGLE_PIN
 * @brief 		-this function toggle specific pin
 * @param[in]    -GPIOX
 * @param[in]    -piny
 * @retval       -none
 * Note          -
 */
void MCAL_GPIO_TOGGLE_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq){


	GPIOX->ODR=(uint32_t)pinconfiq;

}
/**================================================================
 * @Fn			-MCAL_GPIO_lock_PIN
 * @brief 		-this function lock specific pin
 * @param[in]    -GPIOX
 * @param[in]    -piny
 * @retval       -pin status according to @ref GPIO_PIN_LOCKED or not
 * Note          -
 */
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq){

	//set lckk 16
	volatile uint32_t temp=1<<16;
	//set lcky
	temp|= pinconfiq;
	//write 1
	GPIOX->LCKR =temp;
	//write 0
	GPIOX->LCKR =pinconfiq;
	// write 1

	GPIOX->LCKR =temp;
	//read 0
	temp=GPIOX->LCKR;
	//read 1
	if((uint16_t)(GPIOX->LCKR&1<<16)){
		return GPIO_PIN_LOCKED_En;
	}
	else
	{
		return GPIO_PIN_LOCKED_err;
	}


}
