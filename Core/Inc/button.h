/*
 * button.h
 *
 *  Created on: Nov 2, 2022
 *      Author: PC PHUONG
*/

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

#define KEY_SIZE	3

int isSelectPressed();
int isUpPressed();
int isSetPressed();

void getKeyInput();

#endif  /*INC_BUTTON_H_*/

