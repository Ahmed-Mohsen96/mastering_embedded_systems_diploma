/*
 * alarm_moinitor.h
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#ifndef ALARM_MOINITOR_H_
#define ALARM_MOINITOR_H_

#include"state.h"
#include"driver.h"

//states
enum {
	alarm_moinitor_off,
	alarm_moinitor_on,
	alarm_moinitor_waiting
}alarm_monitor_state_id;

//functions
STATE_define(alarm_off);
STATE_define(alarm_on);
STATE_define(alarm_waiting);

//pointer
extern void (*pMoinitor_alarm)();


#endif /* ALARM_MOINITOR_H_ */
