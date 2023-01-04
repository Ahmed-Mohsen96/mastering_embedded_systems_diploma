/*
 * DIO_driver.h
 *
 * Created: 12/6/2022 9:01:54 AM
 *  Author: soft
 */ 


#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

// add includes you will need
//======================================
//   INCLUDES
//======================================
#include "../utilites/Registers.h"
#include "../utilites/macro.h"
#include "../utilites/platform_types.h"


// add macros
//=================================
//         macros
//=================================
//@port_name macro

#define port_A 'A'
#define port_B 'B'
#define port_C 'C'
#define port_D 'D'

//@pin_name macro
#define pin0    0
#define pin1    1
#define pin2    2
#define pin3    3
#define pin4    4
#define pin5    5
#define pin6    6
#define pin7    7

//@direction macro
#define IN  0
#define OUT 1

//@value_macro

#define LOW  0
#define HIGH 1








// add APIS
//=================================
//       APIS
//=================================

error_state DIO_init(uint8_t portNAME,uint8_t pinNAME,uint8_t DIRECTION);

error_state DIO_write(uint8_t portNAME,uint8_t pinNAME,uint8_t value);

error_state DIO_read(uint8_t portNAME,uint8_t pinNAME,uint8_t *value);

error_state DIO_toggle(uint8_t portNAME,uint8_t pinNAME);




#endif /* DIO_DRIVER_H_ */