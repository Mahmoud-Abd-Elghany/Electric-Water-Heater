 /* 
 *  Author: Mahmoud Abdelghany
 */
 
#include <avr/io.h>
#define PRESCALER 1024
#define F_CPU 1000000


void Timer1_init(){
	TIMSK |= (1<<OCIE1A); // Enable Compare Interrupt
}


void Start_timer_sec(unsigned char time){
	TCNT1 = 0;
	TCCR1A = TCCR1A | (1<< FOC1A);
	TCCR1B = TCCR1B | (1<<CS10) | (1<<CS12); //setting prescaler
	TCCR1B = TCCR1B | (1<<WGM12);
	int ticks = (time*F_CPU)/PRESCALER;
	OCR1A = ticks;
}

void Stop_Timer1(){
	//TIFR |= (1<<OCF1A);
	TCCR1B = 0;
}