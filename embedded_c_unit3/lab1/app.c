#include "uart.h"
unsigned char string_buffer[100]="learn-in-depth<ahmed>";
unsigned char const string_buffer1[100]="learn-in-depth<ahmed>";
int main()
{
	uart_send_string(string_buffer);
	return 0;
}