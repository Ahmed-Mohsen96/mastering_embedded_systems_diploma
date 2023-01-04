/*
 * timer_driver.c
 *
 * Created: 12/8/2022 9:53:51 AM
 *  Author: soft
 */ 

#include "timer2_driver.h"


tim2_config_struct_t TIM2;

void timer2_init(tim2_config_struct_t *ptr_config){
	// enable timer
	switch((ptr_config->timer_mode))
	{
		case tim2_normal_max:
			myTCCR2 &= ~((1<<6)|(1<<3));
		break;
		case tim2_ctc_max:
			myTCCR2 &= ~((1<<6));
			myTCCR2 |= ((1<<3));
		break;
		case tim2_pwm_phase_correct_bottom:
		myTCCR2 |= ((1<<6));
		break;
		case tim2_fastpwm_max:
		myTCCR2 |= ((1<<6));
		myTCCR2 |= ((1<<3));
		break;
			
	}
	switch (TIM2.compare_match)
	{
	case tim2_Normalportoperation_OC0_disconnected:
		break;
		case tim2_toggle_oc2:
			myTCCR2 |= (1<<4);
		break;
		case tim2_clear_oc2:
			myTCCR2 |= (1<<5);
		break;
		case tim2_set_oc2:
			myTCCR2 |= (1<<5);
			myTCCR2 |= (1<<4);
		break;
	}
}

void timer2_start(tim2_config_struct_t *ptr_config)
{
	
	switch((ptr_config->timer_clock))
	{
		case tim2_no_clock:
			myTCCR2 &= ~((1<<0)|(1<<1)|(1<<2));
		break;
		case tim2_no_prescaler:
			myTCCR2 &= ~((1<<1)|(1<<2));
			myTCCR2 |= (1<<0);
		break;
		case tim2_prescaler_8:
			myTCCR2 &= ~((1<<2)|(1<<0));
			myTCCR2 |= (1<<1);
		break;
		case tim2_prescaler_32:
			myTCCR2  |=((1<<1)|(1<<0));
			myTCCR2  &= ~(1<<2);
		break;
		case tim2_prescaler_64:
		   myTCCR2  &= ~((1<<1)|(1<<0));
		   myTCCR2  |= (1<<2);
		break;
		case tim2_prescaler_128:
			myTCCR2 &= ~((1<<1));
			myTCCR2 |= ((1<<2)|(1<<0));
		break;
		case tim2_prescaler_256:
			myTCCR2  |=((1<<2)|(1<<1));
			myTCCR2  &= ~(1<<0);
		break;
		case tim2_prescaler_1024:
		 myTCCR2  |= ((1<<2)|(1<<1)|(1<<0));
		
		break;
	}
	
	
}

void timer2_stop(void)
{
	
	myTCCR2=0x00;
}

void init_duty2(uint8_t duty)
{
	myOCR2 = duty * 2.55;
}