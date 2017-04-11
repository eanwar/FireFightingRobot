#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"
#include "stdint.h"
#include "STD_TYP.h"
#include "PWM.h"

void Wait()
{
	uint16_t i;
	for(i=0;i<10;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}
}


void SetPwm(uint8_t angle)
{
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	
 ICR1=2499;  //fPWM=50Hz (Period = 20ms Standard).
 
 DDRB |=(1<<PB5) |(1<<PB6);
 
 switch(angle)
 {
	 case 0:
	 OCR1A=175;   //0 degree
	 Wait();
	 break;
	 
	 case 90:
	  OCR1A=245;  //90 degree
      Wait();
	  break;
	  
	  case 180:
	  OCR1A=285;  //180 degree
	  Wait();
	  break;
	  
 }
 
 
}
