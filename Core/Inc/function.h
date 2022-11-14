/*
 * function.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC PHUONG
 */

#ifndef INC_FUNCTION_H_
#define INC_FUNCTION_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

void clearLed();

void setLedRed1();
void setLedGreen1();
void setLedYellow1();

void setLedRed2();
void setLedGreen2();
void setLedYellow2();

void display7SEG(int num);
void set7SEG(int num);

#endif /* INC_FUNCTION_H_ */
