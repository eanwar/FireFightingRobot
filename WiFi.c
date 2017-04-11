#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include "WiFi.h"

void CallWifi(void)
{
	int i;
	unsigned char data [15],data2 [15];
	unsigned char x;
	UART1_Init(9600);
		_delay_ms(3000);
		
		UART1_Transmit_String("AT+CWMODE=3");
		UART1_Transmit_String("\r\n");
		_delay_ms(200);
		
		UART1_Transmit_String("AT+CIPMUX=0");
		UART1_Transmit_String("\r\n");
		_delay_ms(200);
		
		UART1_Transmit_String("AT+CWJAP=");
		UART1_Transmit_Char('"');
		UART1_Transmit_String("ALARM3");
		UART1_Transmit_Char('"');
		UART1_Transmit_Char(',');
		UART1_Transmit_Char('"');
		UART1_Transmit_String("123456789");
		UART1_Transmit_Char('"');
		UART1_Transmit_String("\r\n");
		_delay_ms(25000);
		
		UART1_Transmit_String("AT+CIPSTART=");
		UART1_Transmit_Char('"');
		UART1_Transmit_String("TCP");
		UART1_Transmit_Char('"');
		UART1_Transmit_Char(',');
		UART1_Transmit_Char('"');
		UART1_Transmit_String("192.168.4.1");
		UART1_Transmit_Char('"');
		UART1_Transmit_Char(',');
		UART1_Transmit_String("333");
		UART1_Transmit_String("\r\n");
		_delay_ms(7000);
	
			
	UART1_Transmit_String("AT+CIPSEND=3");
	UART1_Transmit_String("\r\n");
	_delay_ms(200);
	
	UART1_Transmit_String("ASD");
	UART1_Transmit_String("\r\n");
	_delay_ms(5000);
	
}	
