/*
 * button_driver.h
 *
 * Created: 12/6/2022 11:39:36 AM
 *  Author: soft
 */ 


#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include "../MCAL/DIO_driver/DIO_driver.h"

// APIS

void button_init(uint8_t button_port,uint8_t buttonpin);

void button_read(uint8_t button_port,uint8_t buttonpin,uint8_t *value);




#endif /* BUTTON_DRIVER_H_ */