/*
 * global.h
 *
 *  Created on: Nov 3, 2022
 *      Author: PC PHUONG
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "main.h"
#include "function.h"

#define INIT1 			1
#define INIT2 			2
#define AUTO_GREEN1 	3
#define AUTO_YELLOW1	4
#define AUTO_GREEN2 	5
#define AUTO_YELLOW2	6

#define MODE1		12
#define MODE2		13
#define MODE3		14
#define MODE4		15
#define WAIT		16
#define UP_RED		17

extern int status;
extern int red;
extern int yellow;
extern int green;

#endif /* INC_GLOBAL_H_ */
