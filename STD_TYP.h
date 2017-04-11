#ifndef _STD_TYP_H_
#define _STD_TYP_H_
//#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define clr_bit(reg,index)       ( reg &= ( ~(1<<index) ) )
#define set_bit(reg,index)       ( reg |= (1<<index) )
#define get_lower_nibble(reg)    (reg&0x0f)
#define tog_bit(reg,index)       (reg^=(1<<index))
#define get_bit(reg,index)       ((reg>>index)&0x01)
#define BIT_IS_CLEAR(REG,BIT)	 ( !(REG & (1<<BIT)) )

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
#endif
