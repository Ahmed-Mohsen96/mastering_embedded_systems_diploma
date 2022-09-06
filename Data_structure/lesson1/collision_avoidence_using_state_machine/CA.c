/*
 * statemachine.c
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#include "CA.h"


//variables
 int ca_distance=0,ca_speed=0,ca_threshold=50;
//state global pointer to function
void(*p_ca_state)();
void US_set_distance(int d);


STATE_define(CA_waiting){
	//state name
	CA_state_id=CA_waiting;
	printf("waiting state : distance =%d  speed=%d \n",ca_distance,ca_speed);

	//state action
	ca_speed =0;
	//dc motor (speed)
	DC_motor(ca_speed);
}
STATE_define(CA_driving){
	//state action
	CA_state_id=CA_driving;
	printf("driving state : distance =%d  speed=%d \n",ca_distance,ca_speed);
	//state action
	ca_speed =30;
	DC_motor(ca_speed);


}
void US_set_distance(int d){
	ca_distance=d;
	(ca_distance<=ca_threshold)?(p_ca_state=STATE(CA_waiting)):(p_ca_state=STATE(CA_driving));
	printf("US------distance=%d--->\n",ca_distance);
}


