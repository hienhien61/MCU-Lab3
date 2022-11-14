/*
 * fsm_automatic.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC PHUONG
*/
#include "fsm_automatic.h"

int count = 0;
int counter1 = green/1000;
int counter2 = red/1000;
int segNum = 0;

void fsm_automatic_run(){
	switch(status){
		case INIT:
			//TODO
			clearLed();

			status = AUTO_GREEN1;
			setTimer1(1000);
			count = 1;
			counter1 = green/1000;
			counter2 = red/1000;
			segNum = 1;
			set7SEG(1);
			break;
		case AUTO_GREEN1:
			setLedGreen1();
			setLedRed2();
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer1_flag == 1){
				if(count >= 3) {
					status = AUTO_YELLOW1;
					counter1 = 3;
				}
				count++;
				counter1--;
				counter2--;
				segNum = 1 - segNum;
				setTimer1(1000);
			}
//			if(isButton1Pressed() == 1){
//				status = MAN_GREEN;
//				setTimer1(1000);
//			}
			break;
		case AUTO_YELLOW1:
			setLedYellow1();
			setLedRed2();
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer1_flag == 1){
				if(count >= 5) {
					status = AUTO_GREEN2;
					counter1 = 6;
					counter2 = 4;
				}
				count++;
				counter1--;
				counter2--;
				segNum = 1 - segNum;
				setTimer1(1000);
			}
//			if(isButton1Pressed() == 1){
//				status = MAN_YELLOW;
//				setTimer1(1000);
//			}
			break;
		case AUTO_GREEN2:
			setLedGreen2();
			setLedRed1();
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer1_flag == 1){
				if(count >= 8) {
					status = AUTO_YELLOW2;
					counter2 = 3;
				}
				count++;
				counter1--;
				counter2--;
				segNum = 1 - segNum;
				setTimer1(1000);
			}
			break;
		case AUTO_YELLOW2:
			setLedYellow2();
			setLedRed1();
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer1_flag == 1){
				if(count >= 10) {
					status = AUTO_GREEN1;
					count = -1;
					counter1 = 4;
					counter2 = 6;
				}
				count++;
				counter1--;
				counter2--;
				segNum = 1 - segNum;
				setTimer1(1000);
			}
			break;
		default:
			break;
	}
}

