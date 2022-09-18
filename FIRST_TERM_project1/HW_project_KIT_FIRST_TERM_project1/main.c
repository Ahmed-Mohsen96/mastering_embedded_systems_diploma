/*
 * main.c
 *
 *  Created on: Sep 11, 2022
 *      Author: soft
 */


#include "alarm_driver.h"
#include "alarm_moinitor.h"
#include "main_algo.h"
#include "pressure_sensor.h"

void setup(){
	GPIO_INITILAIZATION();
	pressure_init();
	alarm_init();
}




int main(){
	setup();
	while(1){
		pressure_state();
		pmain_algo();
		pMoinitor_alarm();
		palarm_driver();
		Delay(10000);
	}





	return 0;
}
