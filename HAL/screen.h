 /* 
 *  Author: Mahmoud Abdelghany
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#define POWER_DIR DDRD
#define POWER_PORT PORTD
#define SCREEN_DIR DDRC
#define SCREEN_PORT PORTC

void Screen_Init();
void Change_Screen_Temp(char targetTemp);
void Turn_Power_On();
void Turn_Power_Off();
void Turn_Heater_On();
void Turn_Heater_Off();



#endif /* SCREEN_H_ */