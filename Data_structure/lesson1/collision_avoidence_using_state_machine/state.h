/*
 * state.h
 *
 *  Created on: Sep 5, 2022
 *      Author: soft
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdio.h>
#include<stdlib.h>
//Automatic state function genrated
#define STATE_define(_statefunc_)  void ST_##_statefunc_()
#define STATE(_statefunc_)    ST_##_statefunc_

// states connection

void US_set_distance(int d);
void DC_motor(int s);
#endif /* STATE_H_ */
