/*
 * atmega32_uart_driver.c
 *
 * Created: 11/11/2022 8:15:38 AM
 *  Author: soft
 */ 

#include "atmega32_uart_driver.h"


#define NULL_ptr       ((void *)0x00)
usart_config_struct  uart0={0,
								.txc_interrupt_call=NULL_ptr,
								
								.udre_interrupt_call=NULL_ptr	};
	
	
	


ISR(USART_RXC)
{
	if(uart0.txc_interrupt_call !=NULL_ptr )
	{
		uart0.txc_interrupt_call();
	}
	else
	{
		
		// handle error
	}
}
/*
ISR()
{
	if(uart0.udre_interrupt_call !=NULL_ptr )
	{
		uart0.udre_interrupt_call();
	}
	else
	{
		
		// handle error
	}
}
*/
void usart_init(void){
	unsigned char UCSRA_temp=0;
	unsigned char UCSRB_temp=0;
	unsigned char UCSRC_temp=0;
	
	float UBRR_temp=0;
	
	switch (uart0.usart_mod)
	{
		/*
		Bit 6 – UMSEL: Mode Select
		This bit selects between Asynchronous and Synchronous mode of operation.
		Table 23-4. UMSEL Bit Settings
		UMSEL Bit Settings
		Mode
		0
		Asynchronous Operation
		1
		Synchronous Operation 
		*/
	case usart_asynchronous_mode:
		UCSRC_temp &=~ (1<<UMSEL);
		break;
	case usart_synchronous_mode:
		UCSRC_temp |= (1<<UMSEL);
		switch (uart0.usart_clk_polar)
		{
			/* Bit 0 – UCPOL: Clock Polarity
			This bit is used for Synchronous mode only. Write this bit to zero when Asynchronous mode is used. The
			UCPOL bit sets the relationship between data output change and data input sample, and the
			synchronous clock (XCK).
			Table 23-8. UCPOL Bit Settings
			UCPOL Transmitted Data Changed (Output of TxD
			Pin)
			Received Data Sampled (Input on RxD
			Pin)
			0 Rising XCK Edge Falling XCK Edge
			1 Falling XCK Edge Rising XCK Edge*/
		case usart_synchronus_rising:
			UCSRC_temp &=~(1<<UCPOL);
			break;
		case  usart_synchronus_falling:
			UCSRC_temp |=(1<<UCPOL);
		break;
		default:
		break;
		}
	break;
	default:
	break;
	}
	
	switch (uart0.usart_speed)
	{
		/* Bit 1 – U2X: Double the USART Transmission Speed
		This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous
		operation.
		Writing this bit to one will reduce the divisor of the baud rate divider from 16 to 8 effectively doubling the
		transfer rate for asynchronous communication.*/
	case  usart_asynchronus_normal:
		UBRR_temp = (((float)F_CPU) / (16.0 * uart0.BAUD_RATE)) - 0.5;
		break;
	case  usart_asynchronus_double:
		UCSRA_temp |= (1<<U2X);
		UBRR_temp = (((float)F_CPU) / (8.0 * uart0.BAUD_RATE)) - 0.5;
	break;
	case  usart_synchronus_clock:
		UCSRC_temp  |=(1<<UMSEL);
		UBRR_temp = (((float)F_CPU) / (2.0 * uart0.BAUD_RATE)) - 0.5;
	break;
	default:
	break;
	}
	
	switch (uart0.usart_processor_mod)
	{
		/* Bit 0 – MPCM: Multi-processor Communication Mode
		This bit enables the Multi-processor Communication mode. When the MPCM bit is written to one, all the
		incoming frames received by the USART Receiver that do not contain address information will be
		ignored. The Transmitter is unaffected by the MPCM setting*/
	case  usart_single:
		break;
	case  usart_multi_processor:
		UCSRA_temp |= (1<<MPCM);
	break;
	default:
	break;
	}
	
	switch (uart0.usart_interrupts_mode)
	{
		/* Bit 7 – RXCIE: RX Complete Interrupt Enable
		Writing this bit to one enables interrupt on the RXC Flag. A USART Receive Complete interrupt will be
		generated only if the RXCIE bit is written to one, the Global Interrupt Flag in SREG is written to one and
		the RXC bit in UCSRA is set.
		Bit 6 – TXCIE: TX Complete Interrupt Enable
		Writing this bit to one enables interrupt on the TXC Flag. A USART Transmit Complete interrupt will be
		generated only if the TXCIE bit is written to one, the Global Interrupt Flag in SREG is written to one and
		the TXC bit in UCSRA is set.
		Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
		Writing this bit to one enables interrupt on the UDRE Flag. A Data Register Empty interrupt will be
		generated only if the UDRIE bit is written to one, the Global Interrupt Flag in SREG is written to one and
		the UDRE bit in UCSRA is set.*/
	case  usart_interrupt_disable:
		break;
	case  usart_rx_complete_en:
		UCSRB_temp |= (1<<RXCIE);
	break;
	case  usart_tx_complete_en:
		UCSRB_temp |= (1<<TXCIE);
	break;
	case  usart_dataregempty_en:
		UCSRB_temp |= (1<<UDRIE);
	break;
	case  usart_rx_tx_en:
		UCSRB_temp |= ((1<<RXCIE)|(1<<TXCIE));
	break;
	case  usart_rx_datREg_empty_en:
		UCSRB_temp |= ((1<<RXCIE)|(1<<UDRIE));
	break;
	case  usart_tx_datREg_empty_en:
		UCSRB_temp |= ((1<<TXCIE)|(1<<UDRIE));
	break;
	case  usart_all_interrupt_en:
		UCSRB_temp |= ((1<<TXCIE)|(1<<UDRIE)|(1<<RXCIE));
	break;
	default:
	break;
	}
	switch (uart0.usart_frame_control)
	{
		/* Bits 5:4 – UPMn: Parity Mode [n = 1:0]
		These bits enable and set type of Parity Generation and Check. If enabled, the Transmitter will
		automatically generate and send the parity of the transmitted data bits within each frame. The Receiver
		will generate a parity value for the incoming data and compare it to the UPM0 setting. If a mismatch is
		detected, the PE Flag in UCSRA will be set.
		Table 23-5. UPM Bits Settings
		UPM1 UPM0
		ParityMode
		0 0
		Disabled
		0 1
		Reserved
		1 0
		Enabled, Even Parity
		1 1
		Enabled, Odd Parity*/
		/* Bit 3 – USBS: Stop Bit Select
		This bit selects the number of stop bits to be inserted by the Transmitter. The Receiver ignores this seetings
		Table 23-6. USBS Bit Settings
		USBS Stop Bit(s)
		0 1-bit
		1 2-bit*/
	case  usart_parity_disable_1_stop:
		break;
		UCSRC_temp &=~((1<<UPM0)|(1<<UPM1)|(1<<USBS));
	case  usart_parity_disable_2_stop:
		UCSRC_temp &=~((1<<UPM0)|(1<<UPM1));
		UCSRC_temp |=((1<<USBS));
	break;
	case  usart_parity_even_1_stop:
		UCSRC_temp &=~((1<<UPM0)|(1<<USBS));
		UCSRC_temp |=((1<<UPM1));
	break;
	case  usart_parity_even_2_stop:
		UCSRC_temp &=~((1<<UPM0));
		UCSRC_temp |=((1<<UPM1)|(1<<USBS));
	break;
	case  usart_parity_odd_1_stop:
		UCSRC_temp &=~((1<<USBS));
		UCSRC_temp |=((1<<UPM1)|(1<<UPM0));
	break;
	case  usart_parity_odd_2_stop:
		UCSRC_temp |=((1<<UPM1)|(1<<UPM0)|(1<<USBS));
	break;
	default:
	break;
	}
	
	switch (uart0.usart_frame_data)
	{
		/* Bits 2:1 – UCSZn: Character Size [n = 1:0]
		The UCSZ1:0 bits combined with the UCSZ2 bit in UCSRB sets the number of data bits (Character Size)
		in a frame the Receiver and Transmitter use.
		Table 23-7. UCSZ Bits Settings
		UCSZ2 UCSZ1 UCSZ0 Character Size
		0 0 0 5-bit
		0 0 1 6-bit
		0 1 0 7-bit
		0 1 1 8-bit
		1 0 0 Reserved
		1 0 1 Reserved
		1 1 0 Reserved
		1 1 1 9-bit*/
	case  usart_char_size_5:
		UCSRC_temp &=~((1<<UCSZ0)|(1<<UCSZ1));
		UCSRB_temp &=~((1<<UCSZ2));
	break;
	case  usart_char_size_6:
		UCSRC_temp &=~((1<<UCSZ1));
		UCSRC_temp |=((1<<UCSZ0));
		UCSRB_temp &=~((1<<UCSZ2));
	break;
	case  usart_char_size_7:
		UCSRC_temp &=~((1<<UCSZ0));
		UCSRC_temp |=((1<<UCSZ1));
		UCSRB_temp &=~((1<<UCSZ2));
	break;
	case  usart_char_size_8:
		UCSRC_temp |=((1<<UCSZ1));
		UCSRC_temp |=((1<<UCSZ0));
		UCSRB_temp &=~((1<<UCSZ2));
	break;
	case  usart_char_size_9:
		UCSRC_temp |=((1<<UCSZ0));
		UCSRC_temp |=((1<<UCSZ1));
		UCSRB_temp |=((1<<UCSZ2));
	break;
	default:
	break;
	}
	switch (uart0.usart_operation_mod)
	{
		/* Bit 4 – RXEN: Receiver Enable
		Writing this bit to one enables the USART Receiver. The Receiver will override normal port operation for
		the RxD pin when enabled. Disabling the Receiver will flush the receive buffer invalidating the FE, DOR
		and PE Flags.
		Bit 3 – TXEN: Transmitter Enable
		Writing this bit to one enables the USART Transmitter. The Transmitter will override normal port operation
		for the TxD pin when enabled. The disabling of the Transmitter (writing TXEN to zero) will not become
		effective until ongoing and pending transmissions are completed (i.e., when the Transmit Shift Register
		and Transmit Buffer Register do not contain data to be transmitted). When disabled, the Transmitter will
		no longer override the TxD port.*/
	case  usart_disable:
		break;
	case usart_transmiter_en:
		UCSRB_temp |=(1<<TXEN);
	break;
	case  usart_reciver_en:
		UCSRB_temp |=(1<<RXEN);
	break;
	case  usart_tx_rx_en:
		UCSRB_temp |=((1<<TXEN)|(1<<RXEN));
	break;
	default:
	break;
	}
	myUBRRH = ((unsigned short)UBRR_temp)>>8;
	myUBRRL = ((unsigned short)UBRR_temp);
	myUCSRA = UCSRA_temp;
	myUCSRB = UCSRB_temp;
	myUCSRC = UCSRC_temp;
	
}


void usart_sendbyte_blocking(unsigned short data){
	/* Bit 5 – UDRE: USART Data Register Empty
	The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If UDRE is one, the
	buffer is empty, and therefore ready to be written*/
	while ((myUCSRA &(1<<UDRE))==0)
	{
	}
	if(uart0.usart_frame_data==usart_char_size_9)
	{
		
		myUCSRB |= (myUCSRB&0xFE)|((data&(1<<8))>>8);
	}
	myUDR = (unsigned char)data;
}

void usart_sendbyte_nonblocking(unsigned short data){
	
	
	if ((myUCSRA &(1<<UDRE))!=0)
	{
	
		if(uart0.usart_frame_data==usart_char_size_9)
			{
		
				myUCSRB |= (myUCSRB&0xFE)|((data&(1<<8))>>8);
			}
			myUDR = (unsigned char)data;
	}	
}

unsigned short usart_read_byte_blocking(void)
{
	unsigned short rx_data=0;
	/* Bit 7 – RXC: USART Receive Complete
	This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is
	empty (i.e. does not contain any unread data). If the Receiver is disabled, the receive buffer will be
	flushed and consequently the RXC bit will become zero. The RXC Flag can be used to generate a
	Receive Complete interrupt (see description of the RXCIE bit).*/
	while ((myUCSRA &(1<<RXC))==0)
	{
	}
	// check error flags
	/* Bit 4 – FE: Frame Error
	This bit is set if the next character in the receive buffer had a Frame Error when received (i.e., when the
	first stop bit of the next character in the receive buffer is zero). This bit is valid until the receive buffer
	(UDR) is read. The FE bit is zero when the stop bit of received data is one. Always set this bit to zero
	when writing to UCSRA.
	Bit 3 – DOR: Data OverRun
	This bit is set if a Data OverRun condition is detected. A Data OverRun occurs when the receive buffer is
	full (two characters), it is a new character waiting in the Receive Shift Register, and a new start bit is
	detected. This bit is valid until the receive buffer (UDR) is read. Always set this bit to zero when writing to
	UCSRA.
	Bit 2 – PE: Parity Error
	This bit is set if the next character in the receive buffer had a Parity Error when received and the parity
	checking was enabled at that point (UPM1 = 1). This bit is valid until the receive buffer (UDR) is read.
	Always set this bit to zero when writing to UCSRA.*/
	if(myUCSRA &((1<<FE)|(1<<DOR)|(1<<PE)))
	{
		//eror : you should handle
		if (myUCSRA&(1<<FE))
		{
			uart0.Reading_msg_err=USART_FrameError;
		}
		else if(myUCSRA&(1<<DOR))
		{
			uart0.Reading_msg_err=USART_OverRunError;
		}
		else
		{
			uart0.Reading_msg_err=USART_ParityError;
		}
	}
	if(uart0.usart_frame_data==usart_char_size_9)
	{
		/* Bit 1 – RXB8: Receive Data Bit 8
		RXB8 is the ninth data bit of the received character when operating with serial frames with nine data bits.
		Must be read before reading the low bits from UDR.*/
		rx_data= myUCSRB &(1<<RXB8)<<7;
	}
	rx_data |= myUDR;
	return rx_data;
}

unsigned short usart_read_byte_nonblocking(void)
{
	unsigned short rx_data=0;
	if ((myUCSRA &(1<<RXC))!=0)
	{
	
	if(myUCSRA &((1<<FE)|(1<<DOR)|(1<<PE)))
	{
		//eror : you should handle
		if (myUCSRA&(1<<FE))
		{
			uart0.Reading_msg_err=USART_FrameError;
		}
		else if(myUCSRA&(1<<DOR))
		{
			uart0.Reading_msg_err=USART_OverRunError;
		}
		else
		{
			uart0.Reading_msg_err=USART_ParityError;
		}
	}
	if(uart0.usart_frame_data==usart_char_size_9)
	{
		rx_data= myUCSRB &(1<<RXB8)<<7;
	}
	rx_data |= myUDR;
	}	
	return rx_data;
}
