/*
 * alarm_driver.c
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#include "alarm_driver.h"

int (*palarm_driver)();
void alarm_init(){
	//printf("alarm_init\n");
	palarm_driver=STATE(alarm_driver_waiting);
}
void start_alarm(){
	//printf("start_alarm\n");
	set_alarm_actuator(1);
}
void stop_alarm(){
	set_alarm_actuator(0);
	//printf("stop_alarm\n");
}
STATE_define(alarm_driver_waiting){
	Delay(200000);
	//printf("alarm_driver_waiting\n");
}
STATE_define(alarm_driver_on){
	start_alarm();
	palarm_driver=STATE(alarm_driver_waiting);
}
STATE_define(alarm_driver_off){
	stop_alarm();
	palarm_driver=STATE(alarm_driver_waiting);
}
