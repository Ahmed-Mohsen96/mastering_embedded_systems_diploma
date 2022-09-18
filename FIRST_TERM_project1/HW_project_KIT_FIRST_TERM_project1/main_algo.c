/*
 * main_algo.c
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#include"main_algo.h"

//variables
int pVAL=0;
int threshold=20;
//global pointer
void (*pmain_algo)()=STATE(idle);
int set_pressure_val(int pressure_Val);
//states
STATE_define(high_pressure_dedect){
	main_algo_state_id=high_pressure_dedect;
	start_alarm();
	//printf("high_pressure_dedect\n");
	high_pressure_detected(1);
	pmain_algo=STATE(idle);


}
STATE_define(idle){
	set_alarm_actuator(0);
	stop_alarm();
	high_pressure_detected(0);
	main_algo_state_id=idle;
	//printf("idle\n");

}

int set_pressure_val(int pressure_Val){
	if(pressure_Val>threshold){

			 pmain_algo=STATE(high_pressure_dedect);
			}
		else if(pVAL<=threshold)
		{
			pmain_algo=STATE(idle);
		}

}
