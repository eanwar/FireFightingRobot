#ifndef _LCD_H_
#define _LCD_H_

#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"
#include "STD_TYP.h"


#define LCD_DATA_PORT 			PORTA
#define LCD_DATA_PORT_DIR		DDRA
#define LCD_CONTROL_PORT 		PORTB
#define LCD_CONTROL_PORT_DIR 	DDRB

/* Control Signals */
#define LCD_RS_PIN     PB5    
#define LCD_EN_PIN     PB7
#define LCD_RW_PIN     PB6

/* Data Signals */
#define LCD_D4_PIN     PA4
#define LCD_D5_PIN     PA5
#define LCD_D6_PIN     PA6
#define LCD_D7_PIN     PA7

/* Control Operations */
#define LCD_CONTROL_MASK  ((1<<LCD_EN_PIN)|(1<<LCD_RW_PIN)|(1<<LCD_RS_PIN))
#define LCD_DATA_MASK  ((1<<LCD_D7_PIN)|(1<<LCD_D6_PIN)|(1<<LCD_D5_PIN)|(1<<LCD_D4_PIN))

#define		  setRS()			    set(LCD_CONTROL_PORT,LCD_RS_PIN)
#define		  clearRS()				clear(LCD_CONTROL_PORT,LCD_RS_PIN)
#define		  setEN()			    set(LCD_CONTROL_PORT,LCD_EN_PIN)
#define		  clearEN()				clear(LCD_CONTROL_PORT,LCD_EN_PIN)
#define		  setRW()			    set(LCD_CONTROL_PORT,LCD_RW_PIN)
#define		  clearRW()				clear(LCD_CONTROL_PORT,LCD_RW_PIN)

/* Data Operations */
#define		  setD4()			    set(LCD_DATA_PORT,LCD_D4_PIN)
#define		  clearD4()				clear(LCD_DATA_PORT,LCD_D4_PIN)
#define		  setD5()			    set(LCD_DATA_PORT,LCD_D5_PIN)
#define		  clearD5()				clear(LCD_DATA_PORT,LCD_D5_PIN)
#define		  setD6()			    set(LCD_DATA_PORT,LCD_D6_PIN)
#define		  clearD6()				clear(LCD_DATA_PORT,LCD_D6_PIN)
#define		  setD7()			    set(LCD_DATA_PORT,LCD_D7_PIN)
#define		  clearD7()				clear(LCD_DATA_PORT,LCD_D7_PIN)

#define		  set(PORT,PIN)			    PORT|=(1<<PIN)
#define		  clear(PORT,PIN)			PORT&=~(1<<PIN)




void LCD_Init(void);
void LCD_DispChar(unsigned char data);
void LCD_DispCharXY(unsigned char x, unsigned char y,unsigned char data);
void LCD_SendCmd(unsigned char cmd);
void LCD_ClearAll(void);
void LCD_GotoXY(unsigned char x, unsigned char y);
void LCD_DispString(unsigned char *str);
void LCD_DispStringXY(unsigned char x, unsigned char y, unsigned char *str);
void LCD_DispChars(unsigned char *str, unsigned char len);
void LCD_DispCharsXY(unsigned char x, unsigned char y,unsigned char *str, unsigned char len);
void toString(unsigned short num,unsigned char * str,unsigned char dispSize);
void getString(unsigned short num,unsigned char * str);
#endif
