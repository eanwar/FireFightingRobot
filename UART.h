#ifndef UART_H_
#define UART_H_

#define get_bit(reg,index)       ((reg>>index)&0x01)
#include <avr/io.h>
#define  F_CPU   8000000UL
void  UART1_Init(unsigned int BaudRate);
void  UART1_Transmit_Char(unsigned char data);
void UART1_Transmit_String(unsigned char *srt);
unsigned char UART1_Receive_Char(void);
void UART1_Receive_String(unsigned char *srt);




#endif /* UART_H_ */
