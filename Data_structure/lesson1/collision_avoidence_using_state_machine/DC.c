/*
 * statemachine.c
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#include "DC.h"


//variables
 int dc_speed=0;
//state global pointer to function
void(*PDC_state)();


void DC_init(){
	//init pwm
	printf("DC_init\n");
}
void DC_motor(int s){
	dc_speed=s;
	PDC_state=STATE(DC_busy);
	printf("CA------speed=%d--->\n",dc_speed);
}

STATE_define(DC_idle){
	//state name
	DC_state_id=DC_idle;
	//state action
	//call pwm to make speed =DC_speed
	//DC_motor(DC_speed)
	printf("waiting state : speed=%d \n",dc_speed);
}
STATE_define(DC_busy){
	//state action
	DC_state_id=DC_busy;
	PDC_state=STATE(DC_idle);
	printf("driving state : speed=%d \n",dc_speed);

}

