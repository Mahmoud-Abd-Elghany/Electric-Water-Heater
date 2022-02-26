 /* 
 *  Author: Mahmoud Abdelghany
 */
 
#include <avr/io.h>
#include "screen.h"

void Screen_Init(){
	SCREEN_DIR = 0xFF;
	POWER_DIR |= (1<<0) | (1<<1);
}

void Change_Screen_Temp(char targetTemp){
	SCREEN_PORT = 0x00 | ((targetTemp%10)<<0) | ((targetTemp/10)<<4);
}

void Turn_Power_On(){
	POWER_PORT |= (1<<0);
}

void Turn_Power_Off(){
	POWER_PORT &= (~(1<<0));
}

void Turn_Heater_On(){
	POWER_PORT |= (1<<1);
}

void Turn_Heater_Off(){
	POWER_PORT &= (~(1<<1));
}