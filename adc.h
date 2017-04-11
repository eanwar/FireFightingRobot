/*
 * adc.h
 *  Created on: Sep 5, 2015
 *  Author: Mohamed Tarek
 */

#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"
#include "stdint.h"



extern uint16_t data;
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16_t ADC_read(uint8_t channel_num);


#endif /* ADC_H_ */
