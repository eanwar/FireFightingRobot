#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"
#include "stdint.h"
#include "STD_TYP.h"


#include "adc.h"
#include "LCD_K.h"
#include "UART.h"
#include "WiFi.h"
#include "FlameSensor.h"
#include "MotionSystem.h"
#include "FireFighting.h"
#include "PWM.h"



int main(void)
{   uint16_t Threshold=633;
	uint8_t Accuracy=100;
	struct FlameInfo FlameStructure;
	uint8_t RxWifi=0;
	uint16_t maxstr[10] ,str0[10],str1[10],str2[10],str3[10],str4[10];
	
	// Initialize your drivers
	ADC_init(); // initialize ADC driver
	LCD_Init(); // initialize LCD driver
	InitCar();
	
	//Threshold=GetThresholdValue(Accuracy);
	
	LCD_DispStringXY(2,1,"DETECT FIRE");
	LCD_DispStringXY(4,2,"LOCATION");
	_delay_ms(2000);
	
	
    while(1)
    {   
	FlameStructure=EnableFlameSensor();
			
	// LCD display
	itoa(FlameStructure.MaxRead,maxstr,10);
	itoa(FlameStructure.FlameReads[0],str0,10);
	itoa(FlameStructure.FlameReads[1],str1,10);
	itoa(FlameStructure.FlameReads[2],str2,10);
		
	LCD_ClearAll();
	LCD_DispStringXY(0,1,"Max=");
	_delay_ms(500);
	LCD_DispStringXY(4,1,maxstr);
	LCD_DispStringXY(0,2,str0);
	LCD_DispStringXY(5,2,str1);
	LCD_DispStringXY(10,2,str2);
			
	// Enable Fire Fighting
	EnableFireFighting(FlameStructure,Threshold);		
		
	}    
}


 
