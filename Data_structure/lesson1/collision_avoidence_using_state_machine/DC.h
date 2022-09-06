/*
 * statemachine.h
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#ifndef DC_H_
#define DC_H_

#include <stdio.h>
#include<stdlib.h>
#include"state.h"
//define state
enum{
	DC_idle,
	DC_busy
}DC_state_id;



//declare states functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);




extern void(*PDC_state)();
void DC_init();


#endif /* CA_H_ */
