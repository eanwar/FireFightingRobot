#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

void  UART1_Init(unsigned  int BaudRate){
	unsigned short int UBRR0 = (short) (F_CPU/(BaudRate*16UL)-1);
	UBRR1L = UBRR0 ;
	UBRR1H = (UBRR0>>8);
	UCSR1C = ((0<<UMSEL1)|(0<<UPM11)|(0<<UPM11)|(0<<USBS1)|(1<<UCSZ11)|(1<<UCSZ10));
	UCSR1B = ((1<<RXEN1)|(1<<TXEN1)|(0<<UCSZ12));
}

void  UART1_Transmit_Char(unsigned char data)
{
	while(!(UCSR1A & (1<<UDRE1)));   //UDRE0 = 0 "not empty"
	UDR1 = data ;
}

void UART1_Transmit_String(unsigned char *srt){
	unsigned int i = 0;
	while(srt[i] != '\0'){
		UART1_Transmit_Char(srt[i]);
		i++;
	}
}

unsigned char UART1_Receive_Char(void){
	while(!(UCSR1A & (1<<RXC1)));
	return UDR1 ;
}

void UART1_Receive_String(unsigned char *srt){
	unsigned int i =0;
	srt[i] = UART1_Receive_Char();
	while (srt[i] !='#')
	{
		i++ ;
		srt[i] = UART1_Receive_Char();
	} i++ ;
	srt[i] ='\0' ;
}
char UART_Receive_ascii_byte(void)
{
	unsigned char data;
	while((get_bit(UCSR1A,RXC1))==0);
	data=UDR1;
if((data<=(9+'0')&&(data>=(0+'0')))){data=data-'0';}
return data;
}
char UART1_ReceiveByte(void)
{
	if((get_bit(UCSR1A,RXC1))==1);
	return UDR1;
}
