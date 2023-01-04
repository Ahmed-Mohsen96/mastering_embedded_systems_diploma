/*
 * timer_driver.h
 *
 * Created: 12/8/2022 9:53:37 AM
 *  Author: soft
 */ 


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

//=============================
//   includes
//=============================
#include "utilites/macro.h"
#include "utilites/platform_types.h"
#include "utilites/Registers.h"


//=================================
//         macros
//=================================
typedef enum
{
	normal_max,
	pwm_phase_correct_bottom,
	ctc_max,
	fastpwm_max,
	
}wave_gen_t;

typedef enum
{
	//Normalportoperation_OC0_disconnected,
	toggle_oc0,
	clear_oc0,
	set_oc0,
}com_match_nonpwm_t;

typedef enum
{
	Normalportoperation_OC0_disconnected,
	reserved,
	clear_oc0_setoc0_buttom,
	set_oc0_clear_buttom,
}com_match_fastpwm_t;

typedef enum
{
	//Normalportoperation_OC0_disconnected,
	//reserved,
	clear_oc0_setoc0_downcount,
	set_oc0_clear_downcount,
}com_match_phasecorrectpwm_t;


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
	com_match_nonpwm_t      compare_match_no_pwm;
	}tim0_config_struct_t;


//=================================
//       APIS
//=================================
error_state timer_init();

error_state timer_start();

void get_timer_state(void);

void timer_stop(void);

void delayms(void);
void delay(void);
extern tim0_config_struct_t TIM0;
#endif /* TIMER_DRIVER_H_ */