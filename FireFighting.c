
#define F_CPU 8000000 
#include <avr/io.h>
#include "util/delay.h"
#include "stdint.h"
#include "FireFighting.h"



void EnableFireFighting(struct FlameInfo FlameData,uint16_t Threshold){
	uint8_t i;
	
	if(FlameData.MaxRead>= Threshold && (FlameData.MaxRead <= MaxBurn))
	{
		
		switch(FlameData.position)
		{
			case 0:
			TurnRight();
			_delay_ms(500);
			break;
			case 1:
			Forward();
			_delay_ms(500);
			break;
			case 2:
			TurnLeft();
			_delay_ms(500);
			break;
		}
	}
	
	else if (FlameData.MaxRead>= MaxBurn)
	{
		Stop();
				
	}
	
	else if(FlameData.MaxRead< Threshold)
	{
		Stop();
		_delay_ms(1000);
	}
		
}
