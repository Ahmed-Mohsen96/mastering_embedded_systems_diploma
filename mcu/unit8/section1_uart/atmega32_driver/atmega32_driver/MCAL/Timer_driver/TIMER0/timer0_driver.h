/*
 * timer_driver.h
 *
 * Created: 12/8/2022 9:53:37 AM
 *  Author: soft
 */ 


#ifndef TIMER0_DRIVER_H_
#define TIMER0_DRIVER_H_

#include "../utilites/Registers.h"
#include "../utilites/macro.h"
#include "../utilites/platform_types.h"



typedef enum
{
	normal_max,
	pwm_phase_correct_bottom,
	ctc_max,
	fastpwm_max,
	
}wave_gen_t;

typedef enum
{
	Normalportoperation_OC0_disconnected,
	toggle_oc0,
	clear_oc0,
	set_oc0,
}com_match_t;



typedef enum
{
	no_clock,
	no_prescaler,
	prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024,
	ext_clk_falling,
	ext_clk_rising,
	
	}clock_t;


typedef struct
{
	wave_gen_t               timer_mode;
	clock_t                 timer_clock;
	com_match_t            compare_match;
	}tim0_config_struct_t;



void timer_init(tim0_config_struct_t *ptr_config);

void timer_start(tim0_config_struct_t *ptr_config);

void timer_stop(void);

void init_duty(uint8_t duty);
void delayms(void);
void delayus(void);
void _delayms(uint8_t delay);
extern tim0_config_struct_t TIM0;


#endif /* TIMER_DRIVER_H_ */