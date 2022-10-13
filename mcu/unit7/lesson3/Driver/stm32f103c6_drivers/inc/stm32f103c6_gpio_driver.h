/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Oct 8, 2022
 *      Author: soft
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

/*
 * includes
 */
#include "stm32f103c6.h"

//===========================================
/*
 * user type definitions (structures)
 */
typedef struct{
	uint16_t GPIO_pin_number;   //specifies the gpio pins to be configured.
								//this parameter can be a value of @ref GPIO_PIN_define.
	uint8_t GPIO_mode       ; //specifies the gpio mode to be configured.
					          //this parameter can be a value of @ref GPIO_mode_define.
	uint8_t GPIO_speed      ; // specifies the speed for the selected pins
							  // this parameter can be a value of @ref GPIO_SPEED_define
}GPIO_PIN_Config_t;



//======================================
//macro configuration references
//=========================================

//@ref GPIO_PIN_define.
#define GPIO_PIN_0                (uint16_t) 0x0001U//01
#define GPIO_PIN_1                (uint16_t) 0x0002U//10
#define GPIO_PIN_2                (uint16_t) 0x0004U//100
#define GPIO_PIN_3                (uint16_t) 0x0008U//1000
#define GPIO_PIN_4                (uint16_t) 0x0010U//10000
#define GPIO_PIN_5                (uint16_t) 0x0020U
#define GPIO_PIN_6                (uint16_t) 0x0040U
#define GPIO_PIN_7                (uint16_t) 0x0080U
#define GPIO_PIN_8                (uint16_t) 0x0100U
#define GPIO_PIN_9                (uint16_t) 0x0200U
#define GPIO_PIN_10               (uint16_t) 0x0400U
#define GPIO_PIN_11               (uint16_t) 0x0800U
#define GPIO_PIN_12               (uint16_t) 0x1000U
#define GPIO_PIN_13               (uint16_t) 0x2000U
#define GPIO_PIN_14               (uint16_t) 0x4000U
#define GPIO_PIN_15               (uint16_t) 0x8000U
#define GPIO_MASK_PIN             (uint16_t) 0x0000ffffU
//@ref GPIO_mode_define

//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up /
//3: pull-down

//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input
#define GPIO_mode_analog           		0x00000000U    //Analog mode
#define GPIO_mode_INPUT_flo           	0x00000001U    //Floating input (reset state)
#define GPIO_mode_INPUT_PU          	0x00000002U    //Input with pull-up /
#define GPIO_mode_INPUT_PD              0x00000003U    //pull-down
#define GPIO_mode_OUTPUT_PP             0x00000004U    //General purpose output push-pull
#define GPIO_mode_OUTPUT_OD             0x00000005U    // General purpose output Open-drain
#define GPIO_mode_OUTPUT_AF_PP          0x00000006U    //Alternate function output Push-pull
#define GPIO_mode_OUTPUT_AF_OD          0x00000007U    //Alternate function output Open-drain
#define GPIO_mode_output_AF_input       0x00000008U    //Alternate function input



//@ref GPIO_SPEED_define
//0: Input mode (reset state)
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M           	0x00000001U    //max speed 10 MHz.
#define GPIO_SPEED_2M          		0x00000002U    // max speed 2 MHz
#define GPIO_SPEED_50M              0x00000003U    //max speed 50 MHz.

//@ref GPIO_PIN_status
#define GPIO_PIN_SET      1
#define GPIO_PIN_RESET    0

/*@ref GPIO_PORT_status*/
#define GPIO_PORT_TRUE      1
#define GPIO_PORT_FALSE     0


//@ref GPIO_PIN_LOCKED or not
#define GPIO_PIN_LOCKED_En      1
#define GPIO_PIN_LOCKED_err     0



//===============================================================
//       APIS supported by MCAL GPIO drivers
//===============================================================

void MCAL_GPIO_Init(GPIO_typedef *GPIOX,GPIO_PIN_Config_t *PINConfig);
void MCAL_GPIO_DEInit(GPIO_typedef *GPIOX);

//READ APIs
uint8_t MCAL_GPIO_READ_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq);
uint16_t MCAL_GPIO_READ_PORT(GPIO_typedef *GPIOX);

//write APIS
void MCAL_GPIO_WRITE_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq,uint8_t value);
void MCAL_GPIO_WRITE_PORT(GPIO_typedef *GPIOX,uint16_t value);

void MCAL_GPIO_TOGGLE_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq);
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_typedef *GPIOX,uint8_t pinconfiq);
#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
