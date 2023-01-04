/*
 * atmega32_uart_driver.h
 *
 * Created: 11/11/2022 8:15:52 AM
 *  Author: soft
 */ 


#ifndef ATMEGA32_UART_DRIVER_H_
#define ATMEGA32_UART_DRIVER_H_


#include "../utilites/Registers.h"
#include "../utilites/macro.h"
#include "../utilites/platform_types.h"
#include "../MCAL/interrupt_driver/interrupt_driver.h"

#define RXC		 7
#define TXC		 6
#define UDRE     5
#define FE       4
#define DOR      3
#define PE       2
#define U2X      1
#define MPCM     0
//
#define RXCIE		 7
#define TXCIE		 6
#define UDRIE       5
#define RXEN         4
#define TXEN         3
#define UCSZ2        2
#define RXB8         1
#define TXP8         0

//////////////////////////////////////////////////////////////////////////
#define	URSEL		 7
#define UMSEL		 6
#define UPM1         5
#define UPM0         4
#define USBS         3
#define UCSZ1        2
#define UCSZ0        1
#define UCPOL        0
typedef enum{
		usart_asynchronus_normal,
		usart_asynchronus_double,
		usart_synchronus_clock,
	
	}usart_config_speed;

typedef enum{
		usart_single,
		usart_multi_processor,
	}usart_prosessor_mode;

typedef enum{
		usart_interrupt_disable,
		usart_rx_complete_en,
		usart_tx_complete_en,
		usart_dataregempty_en,
		usart_rx_tx_en,
		usart_rx_datREg_empty_en,
		usart_tx_datREg_empty_en,
		usart_all_interrupt_en,
	}usart_interrupt_config;

typedef enum {
	usart_disable,
	usart_transmiter_en,
	usart_reciver_en,
	usart_tx_rx_en,
	
	}usart_operation_mode;
typedef enum{
	usart_asynchronous_mode,
	usart_synchronous_mode,
	}usart_mode;
typedef enum{
	usart_parity_disable_1_stop,
	usart_parity_disable_2_stop,
	usart_parity_even_1_stop,
	usart_parity_even_2_stop,
	usart_parity_odd_1_stop,
	usart_parity_odd_2_stop,
	
	}usart_parity_stop_config;
	
typedef enum {
		usart_char_size_5,
		usart_char_size_6,
		usart_char_size_7,
		usart_char_size_8,
		usart_char_size_9,
	}usart_char_size;
typedef enum {
		usart_synchronus_rising,
		usart_synchronus_falling,
	}usart_clk_polarity;

typedef enum
{
	USART_NoError,
	USART_ParityError,
	USART_OverRunError,
	USART_FrameError,
}USART_ErrorType;	
typedef struct  
{
	usart_mode                         usart_mod;
	usart_config_speed				   usart_speed;
	usart_prosessor_mode               usart_processor_mod;
	usart_interrupt_config             usart_interrupts_mode;
	usart_parity_stop_config           usart_frame_control;
	usart_char_size                    usart_frame_data;
	usart_operation_mode               usart_operation_mod;
	usart_clk_polarity                 usart_clk_polar;
	unsigned long                      BAUD_RATE;
	/* Read This Flag Before Using Data Returned by Read Function , Clear Flag Your Self */
	USART_ErrorType                    Reading_msg_err;
	// call back members
	/* Make The Pointer points to a Function you wish to be Called by tXC Interrupt */
	void(*txc_interrupt_call)(void);
	/* Make The Pointer points to a Function you wish to be Called by RXC Interrupt */
	void(*rxc_interrupt_call)(void);
	/* Make The Pointer points to a Function you wish to be Called by udre Interrupt */
	void(*udre_interrupt_call)(void);
	
}usart_config_struct;

extern usart_config_struct  uart0;
void usart_init(void);
void usart_sendbyte_blocking(unsigned short data);
void usart_sendbyte_nonblocking(unsigned short data);

unsigned short usart_read_byte_blocking(void);
#endif /* ATMEGA32_UART_DRIVER_H_ */