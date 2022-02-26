 /* 
 *  Author: Mahmoud Abdelghany
 */


#include "ADC.h"
#include <avr/io.h>



void ADC_Init(){
	ADCSRA |= (1<<ADEN); //Enable ADC
	ADCSRA |= (1<<0) | (1<<1) | (1<<2); // Setting Prescaler to 128
}

unsigned int ADC_read_channel(char channel){
	ADMUX &= (0b11100000);
	ADMUX |= (channel & 0b00011111); //Setting which channel to read
	ADCSRA |= (1<<ADSC); // Start Conversion
	while((ADCSRA & (1<<ADIF)) == 0){}; //Waiting till ADC finish reading
	ADCSRA |= (1<<ADIF);
	unsigned int value = ADCL | ((ADCH & (0x03)) << 8); // Reading ADC data registers
	return value;
}