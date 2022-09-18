/*
 * pressure_sensor.h
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include"state.h"

//states
enum {
	pressure_waiting,
	pressure_reading
}pressure_sensor_state_id;

//declare state function
STATE_define(pressure_waiting);
STATE_define(pressure_reading);
void pressure_init();

extern void(*pressure_state)();



#endif /* PRESSURE_SENSOR_H_ */
