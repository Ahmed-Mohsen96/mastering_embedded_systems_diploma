/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Oct 8, 2022
 *      Author: soft
 */

#ifndef INC_STM32F103C6_EXTI_H_
#define INC_STM32F103C6_EXTI_H_

#include "stm32f103c6.h"
#include "stm32f103c6_gpio_driver.h"


typedef struct{
	uint16_t 			EXTI_inputlinenubmer;
	GPIO_typedef* 		GPIO_port;
	uint16_t      		GPIO_pin;
	uint8_t             IVT_IRQ_NUMBER;
}EXTI_GPIO_mapping_t;

typedef struct {
	EXTI_GPIO_mapping_t EXTI_pin; //specifies external interrupt GPIO mapping
								// this parameter must be set @REF EXTI_define

	uint8_t            TRIGER_Case;// specifies rising or falling or both trigger
									//this parameter must be set@ref EXTI_TRIGGER_define
	uint8_t            IRQ_EN      ;// Enable or Disable EXTI IRQ (that will enable IRQ mask in EXTI and also the NVIC )
									//@ref EXTI_IRQ_define

	void(*p_IRQ_CALLBACk)(void);    //set the c function () which will be called once the IRQ happen
}EXTI_pinconfig_t;

//reference  macro

//@ref EXTI_IRQ_define
#define   EXTI_IRQ_Enable          1
#define   EXTI_IRQ_Disable         0




// @REF EXTI_define


//EXTI0
#define EXTI0_PA0             (EXTI_GPIO_mapping_t){EXTI0,GPIOA,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0_PB0             (EXTI_GPIO_mapping_t){EXTI0,GPIOB,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0_PC0             (EXTI_GPIO_mapping_t){EXTI0,GPIOC,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0_PD0             (EXTI_GPIO_mapping_t){EXTI0,GPIOD,GPIO_PIN_0,EXTI0_IRQ}


//EXTI1
#define EXTI1_PA1             (EXTI_GPIO_mapping_t){EXTI1,GPIOA,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1_PB1             (EXTI_GPIO_mapping_t){EXTI1,GPIOB,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1_PC1             (EXTI_GPIO_mapping_t){EXTI1,GPIOC,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1_PD1             (EXTI_GPIO_mapping_t){EXTI1,GPIOD,GPIO_PIN_1,EXTI1_IRQ}


//EXTI2
#define EXTI2_PA2             (EXTI_GPIO_mapping_t){EXTI2,GPIOA,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2_PB2             (EXTI_GPIO_mapping_t){EXTI2,GPIOB,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2_PC2             (EXTI_GPIO_mapping_t){EXTI2,GPIOC,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2_PD2             (EXTI_GPIO_mapping_t){EXTI2,GPIOD,GPIO_PIN_2,EXTI2_IRQ}


//EXTI3
#define EXTI3_PA3             (EXTI_GPIO_mapping_t){EXTI3,GPIOA,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3_PB3             (EXTI_GPIO_mapping_t){EXTI3,GPIOB,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3_PC3             (EXTI_GPIO_mapping_t){EXTI3,GPIOC,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3_PD3             (EXTI_GPIO_mapping_t){EXTI3,GPIOD,GPIO_PIN_3,EXTI3_IRQ}


//EXTI4
#define EXTI4_PA4             (EXTI_GPIO_mapping_t){EXTI4,GPIOA,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4_PB4             (EXTI_GPIO_mapping_t){EXTI4,GPIOB,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4_PC4             (EXTI_GPIO_mapping_t){EXTI4,GPIOC,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4_PD4             (EXTI_GPIO_mapping_t){EXTI4,GPIOD,GPIO_PIN_4,EXTI4_IRQ}


//EXTI5
#define EXTI5_PA5             (EXTI_GPIO_mapping_t){EXTI5,GPIOA,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5_PB5             (EXTI_GPIO_mapping_t){EXTI5,GPIOB,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5_PC5             (EXTI_GPIO_mapping_t){EXTI5,GPIOC,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5_PD5             (EXTI_GPIO_mapping_t){EXTI5,GPIOD,GPIO_PIN_5,EXTI5_IRQ}


//EXTI6
#define EXTI6_PA6             (EXTI_GPIO_mapping_t){EXTI6,GPIOA,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6_PB6             (EXTI_GPIO_mapping_t){EXTI6,GPIOB,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6_PC6             (EXTI_GPIO_mapping_t){EXTI6,GPIOC,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6_PD6             (EXTI_GPIO_mapping_t){EXTI6,GPIOD,GPIO_PIN_6,EXTI6_IRQ}


//EXTI7
#define EXTI7_PA7             (EXTI_GPIO_mapping_t){EXTI7,GPIOA,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7_PB7             (EXTI_GPIO_mapping_t){EXTI7,GPIOB,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7_PC7             (EXTI_GPIO_mapping_t){EXTI7,GPIOC,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7_PD7             (EXTI_GPIO_mapping_t){EXTI7,GPIOD,GPIO_PIN_7,EXTI7_IRQ}


//EXTI8
#define EXTI8_PA8             (EXTI_GPIO_mapping_t){EXTI8,GPIOA,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8_PB8             (EXTI_GPIO_mapping_t){EXTI8,GPIOB,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8_PC8             (EXTI_GPIO_mapping_t){EXTI8,GPIOC,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8_PD8             (EXTI_GPIO_mapping_t){EXTI8,GPIOD,GPIO_PIN_8,EXTI8_IRQ}


//EXTI9
#define EXTI9_PA9             (EXTI_GPIO_mapping_t){EXTI9,GPIOA,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9_PB9             (EXTI_GPIO_mapping_t){EXTI9,GPIOB,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9_PC9             (EXTI_GPIO_mapping_t){EXTI9,GPIOC,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9_PD9             (EXTI_GPIO_mapping_t){EXTI9,GPIOD,GPIO_PIN_9,EXTI9_IRQ}


//EXTI10
#define EXTI10_PA10             (EXTI_GPIO_mapping_t){EXTI10,GPIOA,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10_PB10             (EXTI_GPIO_mapping_t){EXTI10,GPIOB,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10_PC10             (EXTI_GPIO_mapping_t){EXTI10,GPIOC,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10_PD10             (EXTI_GPIO_mapping_t){EXTI10,GPIOD,GPIO_PIN_10,EXTI10_IRQ}


//EXTI11
#define EXTI11_PA11             (EXTI_GPIO_mapping_t){EXTI11,GPIOA,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11_PB11             (EXTI_GPIO_mapping_t){EXTI11,GPIOB,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11_PC11             (EXTI_GPIO_mapping_t){EXTI11,GPIOC,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11_PD11             (EXTI_GPIO_mapping_t){EXTI11,GPIOD,GPIO_PIN_11,EXTI11_IRQ}


//EXTI12
#define EXTI12_PA12             (EXTI_GPIO_mapping_t){EXTI12,GPIOA,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12_PB12             (EXTI_GPIO_mapping_t){EXTI12,GPIOB,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12_PC12             (EXTI_GPIO_mapping_t){EXTI12,GPIOC,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12_PD12             (EXTI_GPIO_mapping_t){EXTI12,GPIOD,GPIO_PIN_12,EXTI12_IRQ}


//EXTI13
#define EXTI13_PA13             (EXTI_GPIO_mapping_t){EXTI13,GPIOA,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13_PB13             (EXTI_GPIO_mapping_t){EXTI13,GPIOB,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13_PC13             (EXTI_GPIO_mapping_t){EXTI13,GPIOC,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13_PD13             (EXTI_GPIO_mapping_t){EXTI13,GPIOD,GPIO_PIN_13,EXTI13_IRQ}


//EXTI14
#define EXTI14_PA14             (EXTI_GPIO_mapping_t){EXTI14,GPIOA,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14_PB14             (EXTI_GPIO_mapping_t){EXTI14,GPIOB,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14_PC14             (EXTI_GPIO_mapping_t){EXTI14,GPIOC,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14_PD14             (EXTI_GPIO_mapping_t){EXTI14,GPIOD,GPIO_PIN_14,EXTI14_IRQ}


//EXTI15
#define EXTI15_PA15             (EXTI_GPIO_mapping_t){EXTI15,GPIOA,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15_PB15             (EXTI_GPIO_mapping_t){EXTI15,GPIOB,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15_PC15             (EXTI_GPIO_mapping_t){EXTI15,GPIOC,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15_PD15             (EXTI_GPIO_mapping_t){EXTI15,GPIOD,GPIO_PIN_15,EXTI15_IRQ}


//@ref EXTI_TRIGGER_define
#define   EXTI_TRIGGER_RISING                               0
#define   EXTI_TRIGGER_FALLING                              1
#define   EXTI_TRIGGER_RISINGandFALLING                     2



//=============================================
//     macros confiquration references
//=============================================
#define EXTI0                        0
#define EXTI1                        1
#define EXTI2                        2
#define EXTI3                        3
#define EXTI4                        4
#define EXTI5                        5
#define EXTI6                        6
#define EXTI7                        7
#define EXTI8                        8
#define EXTI9                        9
#define EXTI10                       10
#define EXTI11                       11
#define EXTI12                       12
#define EXTI13                       13
#define EXTI14                       14
#define EXTI15                       15



/*
 * APIS
 */

void MCAL_EXTI_GPIO_Init(EXTI_pinconfig_t* EXTI_Config);

void MCAL_EXTI_GPIO_DEInit(void);


void MCAL_EXTI_GPIO_Update(EXTI_pinconfig_t* EXTI_Config);






#endif /* INC_STM32F103C6_EXTI_H_ */
