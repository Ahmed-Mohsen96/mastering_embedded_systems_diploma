/*
 * adc_driver.h
 *
 * Created: 12/17/2022 5:53:49 PM
 *  Author: soft
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "../utilites/Registers.h"
#include "../utilites/macro.h"
#include "../utilites/platform_types.h"

//////////////////////
/*
REFS1 REFS0       Voltage Reference Selection
0      0         AREF, Internal Vref turned off
0      1         AVCC with external capacitor at AREF pin
1      0         Reserved
1      1         Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
typedef enum
{
	internal_vref_off,
	AVCC_external,
	inernal_vref_,
	
	}Voltage_Reference_Selection;
	
/*
Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
The value of these bits selects which combination of analog inputs are connected to the ADC.
These bits also select the gain for the differential channels. See Table 84 for details. If these bits
are changed during a conversion, the change will not go in effect until this conversion is
complete (ADIF in ADCSRA is set).
Table 84. Input Channel and Gain Selections
MUX4..0  Single EndedInput  Positive DifferentialInput  Negative DifferentialInput  Gain
00000     ADC0
00001     ADC1
00010     ADC2
00011     ADC3                                    N/A
00100     ADC4
00101     ADC5
00110     ADC6
00111     ADC7
01000                          ADC0                           ADC0                    10x
01001                         ADC1                            ADC0
01010                         ADC0                            ADC0                   200x
01011                         ADC1                            ADC0
01100                         ADC2                            ADC2                   10x
01101                         ADC3                            ADC2
01110                        ADC2                             ADC2                   200x
01111                         ADC3                            ADC2
10000                         ADC0                            ADC1                   1x
10001                         ADC1                            ADC1
10010          N/A            ADC2                            ADC1
10011                         ADC3                            ADC1
10100							ADC4						 ADC1
10101							ADC5						 ADC1
10110							ADC6						 ADC1
10111							ADC7						 ADC1
11000							ADC0						 ADC2
11001							ADC1						 ADC2
11010							ADC2						 ADC2
11011							ADC3                         ADC2
11100							ADC4                         ADC2
11101                           ADC5                         ADC2                     1x
11110        1.22V (VBG)        N/A
11111        0V (GND
*/

////////////////////////
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
typedef enum{
	DivisionFactor_2,
	DivisionFactor_4,
	DivisionFactor_8,
	DivisionFactor_16,
	DivisionFactor_32,
	DivisionFactor_64,
	DivisionFactor_128,
	}Prescaler_Selections;
	
/*
Bit 7:5 – ADTS2:0: ADC Auto Trigger Source
If ADATE in ADCSRA is written to one, the value of these bits selects which source will trigger
an ADC conversion. If ADATE is cleared, the ADTS2:0 settings will have no effect. A conversion
will be triggered by the rising edge of the selected Interrupt Flag. Note that switching from a trigger
source that is cleared to a trigger source that is set, will generate a positive edge on the
trigger signal. If ADEN in ADCSRA is set, this will start a conversion. Switching to Free Running
mode (ADTS[2:0]=0) will not cause a trigger event, even if the ADC Interrupt Flag is set
Table 86. ADC Auto Trigger Source Selections
ADTS2 ADTS1 ADTS0 Trigger Source
0     0     0     Free Running mode
0     0     1     Analog Comparator
0     1     0     External Interrupt Request 0
0     1     1     Timer/Counter0 Compare Match
1     0     0     Timer/Counter0 Overflow
1     0     1     Timer/Counter1 Compare Match B
1     1     0     Timer/Counter1 Overflow
1     1     1     Timer/Counter1 Capture Event
*/
typedef enum
{
	Free_Running_mode,
	Analog_Comparator,
	External_Interrupt_Request_0,
	Timer_Counter0_Compare_Match,
	Timer_Counter0_Overflow,
	Timer_Counter1_Compare_Match_B,
	Timer_Counter1_Overflow,
	Timer_Counter1_Capture_Event,
	}Auto_Trigger_Source;
	
	typedef struct  
	{
		Voltage_Reference_Selection   ADC_Voltage_Reference_Selection;
		Prescaler_Selections          ADC_Prescaler_Selections;
		Auto_Trigger_Source           ADC_Auto_Trigger_Source;
	}ADC_config_t;

extern ADC_config_t ADC_config;

//APIS
void ADC_init();
uint16_t ADC_read();
#endif /* ADC_DRIVER._H_ */