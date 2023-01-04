/*
 * timer_driver.c
 *
 * Created: 12/8/2022 9:53:51 AM
 *  Author: soft
 */ 

#include "timer0_driver.h"


tim0_config_struct_t TIM0;

void timer_init(tim0_config_struct_t *ptr_config){
	// enable timer
	switch((ptr_config->timer_mode))
	{
		case normal_max:
			myTCCR0 &= ~((1<<6)|(1<<3));
		break;
		case ctc_max:
			myTCCR0 &= ~((1<<6));
			myTCCR0 |= ((1<<3));
		break;
		case pwm_phase_correct_bottom:
		myTCCR0 |= ((1<<6));
		break;
		case fastpwm_max:
		myTCCR0 |= ((1<<6));
		myTCCR0 |= ((1<<3));
		break;
			
	}
	switch (TIM0.compare_match)
	{
	case Normalportoperation_OC0_disconnected:
		break;
		case toggle_oc0:
			myTCCR0 |= (1<<4);
		break;
		case clear_oc0:
			myTCCR0 |= (1<<5);
		break;
		case set_oc0:
			myTCCR0 |= (1<<5);
			myTCCR0 |= (1<<4);
		break;
	}
}

void timer_start(tim0_config_struct_t *ptr_config)
{
	
	switch((ptr_config->timer_clock))
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
	}
	
	
}

void timer_stop(void)
{
	
	myTCCR0=0x00;
}

void init_duty(uint8_t duty)
{
	myOCR0 = duty * 2.55;
}
void delayms(void)
{
	
	myTCNT0=0x12;//set initial
	uint8_t n_flows=20;
	uint8_t counter=0;
	
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
void delayus(void)
{
	
	myTCNT0=0x00;//set initial
	myTCCR0 &= ~((1<<1)|(1<<0));
	myTCCR0 |= (1<<2);
	
	
	//myTCCR0 |= (1<<0);// no pre scaler
	
		while((myTIFR &(1<<0))==0);
		// clear flag
		myTIFR |= (1<<0);
		
	
	
	
}
void _delayms(uint8_t delay)
{
	
	
	
	uint8_t n_flows=((delay / 0.256)+1);
	uint8_t counter=0;
	uint8_t start= (256-((delay /0.001)/n_flows));
	myTCNT0=start;//set initial
	
	myTCCR0 &= ~((1<<2)|(1<<0));  // 8
	myTCCR0 |= (1<<1);
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