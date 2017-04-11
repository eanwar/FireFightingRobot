#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"
#include "stdint.h"
#include "FlameSensor.h"
#define MaxBurn 980

#ifndef FIREFIGHTING_H_
#define FIREFIGHTING_H_


void EnableFireFighting(struct FlameInfo FlameData,uint16_t Threshold);
 


#endif /* FIREFIGHTING_H_ */
