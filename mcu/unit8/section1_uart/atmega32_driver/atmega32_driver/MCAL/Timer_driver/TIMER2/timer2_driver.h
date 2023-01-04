/*
 * timer_driver.h
 *
 * Created: 12/8/2022 9:53:37 AM
 *  Author: soft
 */ 


#ifndef TIMER2_DRIVER_H_
#define TIMER2_DRIVER_H_


#include "../utilites/Registers.h"
#include "../utilites/macro.h"
#include "../utilites/platform_types.h"



typedef enum
{
	tim2_normal_max,
	tim2_pwm_phase_correct_bottom,
	tim2_ctc_max,
	tim2_fastpwm_max,
	
}wave2_gen_t;

typedef enum
{
	tim2_Normalportoperation_OC0_disconnected,
	tim2_toggle_oc2,
	tim2_clear_oc2,
	tim2_set_oc2,
}com2_match_t;



typedef enum
{
	tim2_no_clock,
	tim2_no_prescaler,
	tim2_prescaler_8,
	tim2_prescaler_32,
	tim2_prescaler_64,
	tim2_prescaler_128,
	tim2_prescaler_256,
	tim2_prescaler_1024,
	
	
	}clock2_t;


typedef struct
{
	wave2_gen_t               timer_mode;
	clock2_t                 timer_clock;
	com2_match_t            compare_match;
	}tim2_config_struct_t;



void timer2_init(tim2_config_struct_t *ptr_config);

void timer2_start(tim2_config_struct_t *ptr_config);

void timer2_stop(void);

void init_duty2(uint8_t duty);

extern tim2_config_struct_t TIM2;


#endif /* TIMER_DRIVER_H_ */