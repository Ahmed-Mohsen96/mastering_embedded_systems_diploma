/*
 * main.c
 *
 *  Created on: Aug 28, 2022
 *      Author: soft
 */

#include "CA.h"
#include"US.h"
#include "DC.h"

void setup()
{
	//init all drivers
	//motor init(); //for left &right speed
	//intit soc modules
	//set states pointers for each block
	US_init();
	DC_init();
	//set status pointers
	p_ca_state=STATE(CA_waiting);
	pUS_state=STATE(US_busy);
	PDC_state=STATE(DC_idle);
}

void main(){
	volatile int d;
	setup();
	while(1)
	{
		//call state for each block
		pUS_state();
		p_ca_state();
		PDC_state();
		//delay
		for(d=0;d<=1000;d++);
	}
}
