#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "MotionSystem.h"



void InitCar(void){
	// port C as output
	DDRC=0XFF;
}


void Wheel1(state Wheel1_state){
	switch (Wheel1_state){
		case on: // wheel 1 on
		PORTC |=(1<<PC0); 
		PORTC &=~(1<<PC1); 
		break;
		case off: // wheel 1 off
		PORTC &=~(1<<PC0); 
		PORTC &=~(1<<PC1); 
		break;
		
		
	}
}


void Wheel2(state Wheel2_state)
{
	switch (Wheel2_state){
		case on: // Wheel2 ON
		PORTC|=(1<<PC2); 
		PORTC&=~(1<<PC3); 
		break;
		case off: // Wheel2 Off
		PORTC &=~(1<<PC2); 
		PORTC &=~(1<<PC3); 
		break;
	}
}
void Wheel3(state Wheel3_state){
	
	switch (Wheel3_state){
		case on: // wheel 3 on
		PORTC &=~(1<<PC4); 
		PORTC |=(1<<PC5); 
		break;
		case off: // wheel 3 off
		PORTC &=~(1<<PC4); 
		PORTC &=~(1<<PC5); 
		break;
	}
}

void Wheel4(state Wheel4_state){
	switch (Wheel4_state){
		case on: // wheel 4 on
		PORTC&=~(1<<PC6); 
		PORTC |=(1<<PC7); 
		break;
		case off: // wheel 4 off
		PORTC &=~(1<<PC6); 
		PORTC &=~(1<<PC7); 
		break;
	}
}

void Forward(void){
	Wheel1(on);
	Wheel2(on);
	Wheel3(on);
	Wheel4(on);
		
}

void TurnRight(void){
	Wheel3(on);
	Wheel4(on);
	Wheel1(off);
	Wheel2(off);
}
void TurnLeft(void){
	
	Wheel1(on);
	Wheel2(on);
	Wheel3(off);
	Wheel4(off);
}
void Stop(void){
	
	Wheel1(off);
	Wheel2(off);
	Wheel3(off);
	Wheel4(off);
}

void Rotate(void){
	
	TurnRight();
	_delay_ms(5000);
}


void MoveToTheTarget(void){

Forward();
_delay_ms(5000);
}


