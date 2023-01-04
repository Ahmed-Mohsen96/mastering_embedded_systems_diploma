/*
 * interrupt_driver.c
 *
 * Created: 12/13/2022 12:18:02 AM
 *  Author: soft
 */ 

//=============================
//   includes
//=============================
#include "interrupt_driver.h"

EXTI_confiq_t EXTI_config={0};

//===============================================================================================
// function name       : EXTI_init
// function description: this function init the external interrupt
// function in         : none
// function out        : error state 0 or 1
// note                : none
//===============================================================================================

error_state  EXTI_init()
{
	error_state error_message= no_error;
	switch (EXTI_config.EXTI_req_enable)
	{
	case ExTI_disable:
		break;
	case EXTI_0_enable:
		//• Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
		/*
		ISC01 ISC00 Description
		0 0 The low level of INT0 generates an interrupt request.
		0 1 Any logical change on INT0 generates an interrupt request.
		1 0 The falling edge of INT0 generates an interrupt request.
		1 1 The rising edge of INT0 generates an interrupt request.
		*/
		switch (EXTI_config.EXTI_0_sensing)
		{
		case EXTI_0_low_level:
			break;
		case EXTI_0_any_logical:
			myMCUCR |= (1<<0);
		break;
		case EXTI_0_falling_edge:
			myMCUCR |= (1<<1);
		break;
		case EXTI_0_rising_edge:
			myMCUCR |= (1<<0);
			myMCUCR |= (1<<1);
		break;
		}
		
		//Bit 6 – INT0: External Interrupt Request 0 Enable	
		myGICR |= (1<<6);
	break;
	case EXTI_1_enable:
		//Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
		/* ISC11 ISC10 Description
		0 0 The low level of INT1 generates an interrupt request.
		0 1 Any logical change on INT1 generates an interrupt request.
		1 0 The falling edge of INT1 generates an interrupt request.
		1 1 The rising edge of INT1 generates an interrupt request.*/
		switch (EXTI_config.EXTI_1_sensing)
		{
			case EXTI_1_low_level:
				
			break;
			case EXTI_1_any_logical:
			myMCUCR |= (1<<2);
			break;
			case EXTI_1_falling_edge:
				myMCUCR |= (1<<3);
			break;
			case EXTI_1_rising_edge:
				myMCUCR |= (1<<2);
				myMCUCR |= (1<<3);

			break;
		}
		
		//Bit 7 – INT1: External Interrupt Request 1 Enable
		myGICR |= (1<<7);
	break;
	case EXTI_2_enable:
		//Bit 6 – ISC2: Interrupt Sense Control 2
		/*
		 0 The falling edge of INT2 generates an interrupt request.
		 1 The rising edge of INT2 generates an interrupt request.*/
		switch (EXTI_config.EXTI_2_sensing)
		{
			
			case EXTI_2_falling_edge:
				
				
			break;
			case EXTI_2_rising_edge:
				myMCUCR |= (1<<6);
			break;
		}
		
		//Bit 5 – INT2: External Interrupt Request 2 Enable
		myGICR |= (1<<5);
	break;
	default:
		// error handeling
		error_message=error;
		break;
	}
	
	return error_message;
}

void test_EXTI_driver()
{
	EXTI_config.EXTI_0_sensing=EXTI_0_rising_edge;
	EXTI_config.EXTI_req_enable=EXTI_0_enable;
	EXTI_init();
	
}
#if 0


ISR(EXTI_INT_0)
{
	myDDRA |=(1<<0);
	myPORTA |= (1<<0);
	myGIFR |= (1<<6);

}
#endif