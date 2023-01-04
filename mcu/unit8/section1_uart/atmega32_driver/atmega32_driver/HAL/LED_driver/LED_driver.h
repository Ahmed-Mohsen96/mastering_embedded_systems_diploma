/*
 * LED_driver.h
 *
 * Created: 12/6/2022 10:30:11 AM
 *  Author: soft
 */ 


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "../MCAL/DIO_driver/DIO_driver.h"
//	APIS

void led_init(uint8_t ledport,uint8_t ledpin);

void led_off(uint8_t ledport,uint8_t ledpin);

void led_on(uint8_t ledport,uint8_t ledpin);

void led_toggle(uint8_t ledport,uint8_t ledpin);



#endif /* LED_DRIVER_H_ */