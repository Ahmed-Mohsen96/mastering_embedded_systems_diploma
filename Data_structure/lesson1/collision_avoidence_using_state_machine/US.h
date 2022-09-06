/*
 * statemachine.h
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#ifndef US_H_
#define US_H_

#include <stdio.h>
#include<stdlib.h>
#include"state.h"
//define state
enum{
	US_busy
}US_state_id;



//declare states functions CA
STATE_define(US_busy);
void US_init();




extern void(*pUS_state)();


#endif /* CA_H_ */
