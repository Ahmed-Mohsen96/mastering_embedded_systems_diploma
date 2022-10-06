/*
 * kepad.h
 *
 * Created: 10/6/2022 1:32:26 PM
 *  Author: soft
 */ 


#ifndef KEPAD_H_
#define KEPAD_H_

#define F_CPU 8000000Ul
//avr
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define keypad_port PORTD
#define datadir_keypad DDRD
#define keypad_pin PIND

#define r0 0
#define r1 1
#define r2 2
#define r3 3
#define c0 4
#define c1 5
#define c2 6
#define c3 7

//APIS
void keypad_init();
char keypad_getkey();




#endif /* KEPAD_H_ */