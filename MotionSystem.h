#ifndef MOTORS_H_
#define MOTORS_H_

typedef enum {
	off=0,
	on=1
}state;


void InitCar(void);
void Forward(void);
void TurnRight(void);
void TurnLeft(void);
void Stop(void);
void Rotate(void);
void Wheel1(state wheel1_state);
void Wheel2(state wheel2_state);
void Wheel3(state wheel3_state);
void Wheel4(state wheel4_state);

#endif /* MOTORS_H_ */
