/*
 * state.h
 *
 *  Created on: Sep 10, 2022
 *      Author: soft
 */

#ifndef STATE_H_
#define STATE_H_

#include<stdio.h>
#include <stdlib.h>

//Automatic state function genrated
#define STATE_define(_statefunc_)  void ST_##_statefunc_()
#define STATE(_statefunc_)    ST_##_statefunc_

//state connections
int set_pressure_val(int pressure_Val);
int high_pressure_detected(int i);
void start_alarm();
void stop_alarm();

#endif /* STATE_H_ */
