
#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"
#include "stdint.h"
#include "STD_TYP.h"
#include "adc.h"

void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX =0;
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADPS2:0 = 110 to choose ADC_Clock=F_CPU/128=8Mhz/64=125Khz --> ADC must operate in range 50-200Khz
	 this specified in data sheet for 10 bit precision*/
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS2) ;
}

  uint16_t ADC_read(uint8_t channel_num)
{
 channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits these bits selects which combination of analog inputs are connected to the ADC) before set the required channel */
	//ADMUX=0;
	/* choose the correct channel by setting the channel number in MUX4:0 bits
    these bits selects which combination of analog inputs are connected to the ADC */
	ADMUX |= channel_num;
	
	/* start conversion write '1' to ADSC */
	set_bit(ADCSRA,ADSC); 
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
	set_bit(ADCSRA,ADIF); /* clear ADIF by write '1' to it for compelete conversion:) */
	return ADC; /* return the data register */
}
