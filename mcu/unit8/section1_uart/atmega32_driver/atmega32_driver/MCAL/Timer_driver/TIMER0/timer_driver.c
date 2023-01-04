/*
 * timer_driver.c
 *
 * Created: 12/8/2022 9:53:51 AM
 *  Author: soft
 */ 

//=============================
//   includes
//=============================
#include "timer_driver.h"


#define prescaler 1024
uint8_t counter=0;
uint8_t n_flows=0;
tim0_config_struct_t TIM0;

//===============================================================================================
// function name       : timer_init
// function description: this function init timer0
// function in         : none
// function out        : error state 0 or 1
// note                : none
//===============================================================================================

error_state timer_init(void){
	error_state error_message= no_error;
	switch((TIM0.timer_mode))
	{
		case normal_max:
			myTCCR0 &= ~((1<<6)|(1<<3));
		break;
		case ctc_max:
			myTCCR0 &= ~((1<<6));
			myTCCR0 |= ((1<<3));
		break;
		default:
			error_message=error;
			break;
			
	}
	return error_message;
}

//===============================================================================================
// function name       : timer_start
// function description: this function start timer by prescaler
// function in         : none
// function out        : error state 0 or 1
// note                : none
//===============================================================================================

error_state timer_start()
{
	error_state error_message= no_error;
	//enable timers and chose prescaler
	switch((TIM0.timer_clock))
	{
		case no_clock:
			myTCCR0 &= ~((1<<0)|(1<<1)|(1<<2));
		break;
		case no_prescaler:
			myTCCR0 &= ~((1<<1)|(1<<2));
			myTCCR0 |= (1<<0);
		break;
		case prescaler_8:
			myTCCR0 &= ~((1<<2)|(1<<0));
			myTCCR0 |= (1<<1);
		break;
		case prescaler_64:
			myTCCR0  |=((1<<1)|(1<<0));
			myTCCR0  &= ~(1<<2);
		break;
		case prescaler_256:
			myTCCR0 &= ~((1<<1)|(1<<0));
			myTCCR0 |= (1<<2);
		break;
		case prescaler_1024:
			myTCCR0  |=((1<<2)|(1<<0));
			myTCCR0  &= ~(1<<1);
		break;
		default:
			error_message=error;
	}
	
	return error_message;
	
	
}
//===============================================================================================
// function name       : get_timer_state
// function description: this function get_timer_state
// function in         : none
// function out        : error state 0 or 1
// note                : none
//===============================================================================================
void get_timer_state(void){
	while(GETBIT(myTIFR,0)==0);
	
	myTIFR |= (1<<0);
}
//===============================================================================================
// function name       : timer_stop
// function description: this function stop timer
// function in         : none
// function out        : error state 0 or 1
// note                : none
//===============================================================================================
void timer_stop(void){
	myTCCR0 =0x00;
}

//===============================================================================================
// function name       : delayms
// function description: this function make delay for 5 second
// function in         : none
// function out        : none
// note                : none
//===============================================================================================

void delayms(void)
{
	
	myTCNT0=0x12;//set initial 
	n_flows=20;
	counter=0;
	
	myTCCR0  |=((1<<2)|(1<<0)); // prescaler 1024
	myTCCR0  &= ~(1<<1);
	//myTCCR0 |= (1<<0);// no pre scaler
	while(counter <n_flows)// delay 5s
	{
		while((myTIFR &(1<<0))==0);
		// clear flag
		myTIFR |= (1<<0);
		counter++;
		
	}
	
	counter =0;
	// stop timer
	//myTCCR0=0x00;
	
}
void delay(void)
{
	
	myTCNT0=0x12;//set initial
	n_flows=2;
	counter=0;
	
	myTCCR0  |=((1<<2)|(1<<0)); // prescaler 1024
	myTCCR0  &= ~(1<<1);
	//myTCCR0 |= (1<<0);// no pre scaler
	while(counter <n_flows)// delay 5s
	{
		while((myTIFR &(1<<0))==0);
		// clear flag
		myTIFR |= (1<<0);
		counter++;
		
	}
	
	counter =0;
	// stop timer
	//myTCCR0=0x00;
	
}

void test_timer0_driver()
{
	TIM0.timer_mode=normal_max;
	TIM0.timer_clock=no_prescaler;
	timer_init();
	timer_start();
	timer_stop();
	
}