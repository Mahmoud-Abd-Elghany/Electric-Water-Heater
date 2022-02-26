 /* 
 *  Author: Mahmoud Abdelghany
 */


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 1000000
#include <xc.h>
#include "HAL/screen.h"
#include "MCAL/ADC.h"
#include "MCAL/Timer1.h"
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int read_btns();
unsigned int read_temp();

enum Btn_CMDs {
	DEF = 0, DEC = 512, INC = 683, PWR = 768
};




#endif /* MAIN_H_ */