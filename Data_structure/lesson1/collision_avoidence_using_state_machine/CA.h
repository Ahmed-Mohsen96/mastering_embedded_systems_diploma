/*
 * statemachine.h
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include<stdlib.h>
#include"state.h"
//define state
enum{
	CA_waiting,
	CA_driving
}CA_state_id;



//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);



extern void(*p_ca_state)();


#endif /* CA_H_ */
