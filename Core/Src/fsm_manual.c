/*
 * fsm_manual.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC PHUONG
*/
#include "fsm_manual.h"


void fsm_manual_run(){
	switch(status){
		case MODE1:
			set7SEG(4);
			display7SEG(1);
			if(isSelectPressed()==1){
				status = MODE2;
			}
			break;
		case MODE2:
			set7SEG(4);
			display7SEG(2);
			if(isSelectPressed()==1){
				status = MODE3;
			}
			break;
		case MODE3:
			set7SEG(4);
			display7SEG(3);
			if(isSelectPressed()==1){;
				status = MODE4;
			}
			break;
		case MODE4:
			set7SEG(4);
			display7SEG(4);
			if(isSelectPressed()==1){
				status = MODE1;
			}
			break;
		default:
			break;
	}
}


