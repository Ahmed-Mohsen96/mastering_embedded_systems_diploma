/*
 * alarm_driver.h
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#ifndef ALARM_DRIVER_H_
#define ALARM_DRIVER_H_

#include"state.h"
#include"driver.h"

enum {
	alarm_driver_waiting,
	alarm_driver_on,
	alarm_driver_off
}alarm_driver_state_id;

STATE_define(alarm_driver_waiting);
STATE_define(alarm_driver_on);
STATE_define(alarm_driver_off);

extern int (*palarm_driver)();
void alarm_init();
#endif /* ALARM_DRIVER_H_ */
