/*
 * adc_driver.c
 *
 * Created: 12/17/2022 5:53:34 PM
 *  Author: soft
 */ 

#include "adc_driver.h"

ADC_config_t ADC_config;

void ADC_init()
{
	//set vref
	/*
	REFS1 REFS0       Voltage Reference Selection
	0      0         AREF, Internal Vref turned off
	0      1         AVCC with external capacitor at AREF pin
	1      0         Reserved
	1      1         Internal 2.56V Voltage Reference with external capacitor at AREF pin
	*/
	switch (ADC_config.ADC_Voltage_Reference_Selection)
	{
	case internal_vref_off:
	
		break;
	case AVCC_external:
		SETBIT(myADMUX ,6);
		break;
	case inernal_vref_:
		SETBIT(myADMUX ,6);
		SETBIT(myADMUX ,7);
		break;
	}
	switch (ADC_config.ADC_Prescaler_Selections)
	{
		/*
		Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
		These bits determine the division factor between the XTAL frequency and the input clock to the
		ADC
		Table 85. ADC Prescaler Selections
		ADPS2 ADPS1 ADPS0 DivisionFactor
		0       0   0           2
		0		0	1			2
		0		1	0			4
		0		1	1			8
		1		0	0			16
		1		0	1			32
		1		1	0			64
		1		1	1           128
		*/
	case DivisionFactor_2:
		break;
		case DivisionFactor_4:
			SETBIT(myADCSRA,1); 
		break;
		case DivisionFactor_8:
		SETBIT(myADCSRA,0); 
		SETBIT(myADCSRA,1); 
		break;
		case DivisionFactor_16:
		SETBIT(myADCSRA,2); 
		break;
		case DivisionFactor_32:
		SETBIT(myADCSRA,0);
		SETBIT(myADCSRA,2);
		break;
		case DivisionFactor_64:
		SETBIT(myADCSRA,1);
		SETBIT(myADCSRA,2);
		break;
		case DivisionFactor_128:
		SETBIT(myADCSRA,0);
		SETBIT(myADCSRA,1);
		SETBIT(myADCSRA,2);

		break;
	}
	
}
uint16_t ADC_read()
{
	
}