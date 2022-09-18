/*
 * main_algo.h
 *
 *  Created on: Sep 11, 2022
 *      Author: soft
 */

#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_

#include"state.h"
#include"driver.h"

//states
enum {
	idle,
	high_pressure_dedect
}main_algo_state_id;

// state function
STATE_define(high_pressure_dedect);
STATE_define(idle);

//global pointer
extern void (*pmain_algo)();


#endif /* MAIN_ALGO_H_ */
