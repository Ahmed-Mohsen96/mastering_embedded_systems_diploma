/*
 * pressure_sensor.c
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */
#include"pressure_sensor.h"
#include "driver.h"

//variables
int pressure_val=0;
/*int generate_random(int l, int r, int c){
	int i;
	for(i = 0; i < c; i++){
		int rand_num = (rand() % (r-l+1)) + r;
		return rand_num;
	}
}*/
//global pointer
void(*pressure_state)();
//init
void pressure_init(){
	//printf("pressure_init\n");
	pressure_state=STATE(pressure_reading);
}

STATE_define(pressure_waiting){
	//state name
	pressure_sensor_state_id=pressure_waiting;
	//state action
	Delay(200000);
	pressure_state=STATE(pressure_reading);
	//check event
	//printf("pressure_waiting\n");
}
STATE_define(pressure_reading){
	//state name
	pressure_sensor_state_id=pressure_reading;
	//state action
	pressure_val=getPressureVal();
	//pressure_val=generate_random(15,25,1);
	//check event
	//printf("pressure_reading\n");
	set_pressure_val(pressure_val);
	pressure_state=STATE(pressure_waiting);

}


