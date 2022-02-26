/*
 * main.c
 *  Author: Mahmoud Abdelghany
 */ 


#include "main.h"

unsigned int btn_value;
unsigned char Temp;
unsigned char Target_Temp = 45;
unsigned char Power;
unsigned char *Displayed = &Temp;


ISR(TIMER1_COMPA_vect){
	Displayed = &Temp;
	btn_value = !btn_value;
	Stop_Timer1();
}

int main(void)
{
	/* Setup */
	ADC_Init();
	Timer1_init();
	Screen_Init();
	sei();
	*Displayed = Temp;
	enum Btn_CMDs Btn;
	enum Btn_CMDs prev_btn = DEF;
    while(1){
		Temp = read_temp();
		Btn = read_btns();
		Change_Screen_Temp(*Displayed);
 		if(Btn != prev_btn){
 			if(Btn == PWR){
 				if(Power == 0){
 					Turn_Power_On();
 					Displayed = &Target_Temp;
 					Start_timer_sec(3);
 				}
 				else{
 					Turn_Power_Off();
 				}
 				Power = !Power;
 			}
 			if(Power == 1){
 				if(Btn == INC){
					 if(Target_Temp < 85){
						 Target_Temp += 5;
					 }
 					Displayed = &Target_Temp;
 					Start_timer_sec(3);
				 }
 				if(Btn == DEC){
					 if(Target_Temp > 35){
						 Target_Temp -= 5;
					 }
 					Displayed = &Target_Temp;
 					Start_timer_sec(3);
 				}
 			}
			prev_btn = Btn;
 		}
		if(Power == 1 && Temp < Target_Temp){
			Turn_Heater_On();
		}
		else{
			Turn_Heater_Off();
		}
    }
}

unsigned int read_btns(){
	_delay_ms(30);
	return ADC_read_channel(0);
}

unsigned int read_temp(){
	float temp = ADC_read_channel(1);
	temp = temp * (4.88);
	temp = temp/10;
	temp = temp - 50;
	return temp;
}