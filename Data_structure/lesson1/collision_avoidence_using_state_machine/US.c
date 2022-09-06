/*
 * statemachine.c
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#include "US.h"


//variables
int us_distance=0;
//state global pointer to function
void(*pUS_state)();
int US_GET_distance_random(int l,int r,int count);

void US_init(){
	//init US driver
	printf("US_init\n");
}
STATE_define(US_busy){
	//state name
	US_state_id=US_busy;
	//state action

	us_distance=US_GET_distance_random(45,55,1);
	//check event

	printf("waiting state : distance =%d \n",us_distance);
	US_set_distance(us_distance);
	pUS_state=STATE(US_busy);
}

int US_GET_distance_random(int l,int r,int count)
{

		// this will generate random in range l and r
		int i;
		for(i=0;i<count;i++){
			int rand_num = (rand() % (r - l + 1 )) + 1;
			return rand_num;
		}

}

