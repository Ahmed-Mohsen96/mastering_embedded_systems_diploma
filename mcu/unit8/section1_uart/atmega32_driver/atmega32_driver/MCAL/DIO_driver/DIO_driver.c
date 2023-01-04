/*
 * DIO_driver.c
 *
 * Created: 12/6/2022 9:02:08 AM
 *  Author: soft
 */ 

//=============================
//   includes
//=============================

#include "DIO_driver.h"

//===============================================================================================
// function name       : DIO_init
// function description: this function init the direction the pinx on the portx
// function in         : this function takes port name @port_name macro
// function in         : this function takes pin name @pin_name macro 
// function in         : this function takes direction @direction macro 
// function out        : error state 0 or 1
// note                : none
//===============================================================================================
error_state DIO_init(uint8_t portNAME,uint8_t pinNAME,uint8_t DIRECTION)
{
	error_state error_message=no_error;
	switch(portNAME)
	{
		case port_A:
			if(DIRECTION==IN)
			{
				myDDRA &= ~(1<<pinNAME);
			}
			else if(DIRECTION == OUT)
			{
				myDDRA |= (1<<pinNAME);
			}
			else
			{
				// error handling
				error_message=error;
			}
			break;
		case port_B:
			if(DIRECTION==IN)
			{
				myDDRB &= ~(1<<pinNAME);
			}
			else if(DIRECTION == OUT)
			{
				myDDRB |= (1<<pinNAME);
			}
			else
			{
				// error handling
				error_message=error;
			}
			break;
		case port_C:
			if(DIRECTION==IN)
			{
				myDDRC &= ~(1<<pinNAME);
			}
			else if(DIRECTION == OUT)
			{
				myDDRC |= (1<<pinNAME);
			}
			else
			{
				// error handling
				error_message=error;
			}
			break;
		case port_D:
			if(DIRECTION==IN)
			{
				myDDRD &= ~(1<<pinNAME);
			}
			else if(DIRECTION == OUT)
			{
				myDDRD |= (1<<pinNAME);
			}
			else
			{
				// error handling
				error_message=error;
			}
			break;
			
		default:
			// error handling
			error_message=error;
			break;
	}
	return error_message;
	
	
}

//===============================================================================================
// function name       : DIO_write
// function description: this function write high or low on the pinx on the portx
// function in         : this function takes port name @port_name macro
// function in         : this function takes pin name @pin_name macro
// function in         : this function takes high or low @value_macro
// function out        : error state 0 or 1
// note                : none
//===============================================================================================
error_state DIO_write(uint8_t portNAME,uint8_t pinNAME,uint8_t value)
{
	error_state error_message=no_error;
	switch(portNAME)
	{
		case port_A:
		if(value==LOW)
		{
			myPORTA &= ~(1<<pinNAME);
		}
		else if(value == HIGH)
		{
			myPORTA |= (1<<pinNAME);
		}
		else
		{
			// error handling
			error_message= error;
		}
		break;
		case port_B:
		if(value==LOW)
		{
			myPORTB &= ~(1<<pinNAME);
		}
		else if(value == HIGH)
		{
			myPORTB |= (1<<pinNAME);
		}
		else
		{
			// error handling
			error_message= error;
		}
		break;
		case port_C:
		if(value==LOW)
		{
			myPORTC &= ~(1<<pinNAME);
		}
		else if(value == HIGH)
		{
			myPORTC |= (1<<pinNAME);
		}
		else
		{
			// error handling
			error_message= error;
		}
		break;
		case port_D:
		if(value==LOW)
		{
			myPORTD &= ~(1<<pinNAME);
		}
		else if(value == HIGH)
		{
			myPORTD |= (1<<pinNAME);
		}
		else
		{
			// error handling
			error_message= error;
		}
		break;
		
		default:
		// error handling
		error_message= error;
		break;
	}
	return error_message;
}

//===============================================================================================
// function name       : DIO_read
// function description: this function read high or low from the pinx on the portx
// function in         : this function takes port name @port_name macro
// function in         : this function takes pin name @pin_name macro
// function out         : error state 0 or 1
// note                : none
//===============================================================================================
error_state DIO_read(uint8_t portNAME,uint8_t pinNAME,uint8_t *value)
{
	error_state error_message= no_error;
	switch(portNAME)
	{
		case port_A:
			*value = GETBIT(myPINA,pinNAME);
			break;
		case port_B:
			*value = GETBIT(myPINB,pinNAME);
			break;
		case port_C:
			*value = GETBIT(myPINC,pinNAME);
			break;
		case port_D:
			*value = GETBIT(myPIND,pinNAME);
			break;
		
		default:
		// error handling
		error_message= error;
		break;
	}
	return error_message;
}
//===============================================================================================
// function name       : DIO_toggle
// function description: this function toggle the state of the pinx on the portx
// function in         : this function takes port name @port_name macro
// function in         : this function takes pin name @pin_name macro
// function out         : error state 0 or 1
// note                : none
//===============================================================================================
error_state DIO_toggle(uint8_t portNAME,uint8_t pinNAME)
{
	error_state error_message= no_error;
	switch(portNAME)
	{
		
		case port_A:
			myPORTA ^= (1<<pinNAME);
			break;
		case port_B:
			myPORTB ^= (1<<pinNAME);
			break;
		case port_C:
			myPORTC ^= (1<<pinNAME);
			break;
		case port_D:
			myPORTD ^= (1<<pinNAME);
			break;
		
		default:
		// error handling
		error_message=error;
		break;
	}
	
	return error_message;
}


void test_dio_driver()
{
	uint8_t val;
	DIO_init(port_A,pin0,OUT);
	DIO_write(port_A,pin0,HIGH);
	DIO_read(port_A,pin0,&val);
	if(val==HIGH)
	{
		DIO_toggle(port_A,pin0);
	}
}