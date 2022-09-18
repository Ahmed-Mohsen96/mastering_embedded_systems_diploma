/*
 * alarm_moinitor.c
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#include "alarm_moinitor.h"

//variables
//int alarm_period=60;
//int timer;

//states pointer
void (*pMoinitor_alarm)()=STATE(alarm_off);


//states function
STATE_define(alarm_off){
	alarm_monitor_state_id=alarm_moinitor_off;
	stop_alarm();
	//printf("alarm_off\n");

}
STATE_define(alarm_on){
	alarm_monitor_state_id=alarm_moinitor_on;
	start_alarm();
	//printf("alarm_on\n");
	pMoinitor_alarm=STATE(alarm_waiting);
}
STATE_define(alarm_waiting){
	alarm_monitor_state_id=alarm_moinitor_waiting;
	Delay(200000);
	//printf("alarm_waiting\n");
	pMoinitor_alarm=STATE(alarm_off);


}
int high_pressure_detected(int i){

	//((i==1)?pMoinitor_alarm=STATE(alarm_on):pMoinitor_alarm=STATE(alarm_off));
	if(i==1){
		pMoinitor_alarm=STATE(alarm_on);
	}
	else
	{
		pMoinitor_alarm=STATE(alarm_off);
	}
}

