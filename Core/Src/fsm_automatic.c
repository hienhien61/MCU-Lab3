/*
 * fsm_automatic.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC PHUONG
*/
#include "fsm_automatic.h"

int count = 0;
int counter1 = 0;
int counter2 = 0;
int segNum = 0;

void fsm_automatic_run(){
	switch(status){
		case INIT2:
			//Turn off all LEDs
			clearLed();

			//set initial status and timers
			status = AUTO_GREEN1;
			setTimer1(1000);
			setTimer2(500);

			//count the number to change status and display 7 SEG led
			count = 1;
			counter1 = green/1000;
			counter2 = red/1000;

			segNum = 1;
			set7SEG(1);
			break;
		case AUTO_GREEN1:
			//Turn on Led Green on one lane and Red in another
			setLedGreen1();
			setLedRed2();
			//Display 2 7SEG Led to display time
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer2_flag == 1){
				segNum = 1 - segNum;
				setTimer2(500);
			}
			//When count up to duration of LED, change status
			if(timer1_flag == 1){
				if(count >= green/1000) {
					status = AUTO_YELLOW1;
					counter1 = yellow/1000 + 1;
					count = 0;
				}
				count++;
				counter1--;
				counter2--;
				setTimer1(1000);
			}
			//Fist button pressed -> change mode
			if(isSelectPressed()==1){
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
				clearLed();
			}
			break;
		case AUTO_YELLOW1:
			//Turn on Led Yellow on one lane and Red in another
			setLedYellow1();
			setLedRed2();
			//Display 2 7SEG Led to display time
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer2_flag == 1){
				segNum = 1 - segNum;
				setTimer2(500);
			}
			if(timer1_flag == 1){
				if(count >= yellow/1000) {
					status = AUTO_GREEN2;
					counter1 = red/1000 + 1;
					counter2 = green/1000 + 1;
					count = 0;
				}
				count++;
				counter1--;
				counter2--;
				setTimer1(1000);
			}
			//When count up to duration of LED, change status
			if(isSelectPressed()==1){
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
				clearLed();
			}
			break;
		case AUTO_GREEN2:
			//Turn on Led Red on one lane and Green in another
			setLedRed1();
			setLedGreen2();
			//Display 2 7SEG Led to display time
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			//When count up to duration of LED, change status
			if(timer2_flag == 1){
				segNum = 1 - segNum;
				setTimer2(500);
			}

			if(timer1_flag == 1){
				if(count >= green/1000) {
					status = AUTO_YELLOW2;
					counter2 = yellow/1000 + 1;
					count = 0;
				}
				count++;
				counter1--;
				counter2--;
				setTimer1(1000);
			}
			//When count up to duration of LED, change status
			if(isSelectPressed()==1){
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
				clearLed();
			}
			break;
		case AUTO_YELLOW2:
			//Turn on Led Red on one lane and Yellow in another
			setLedRed1();
			setLedYellow2();
			//Display 2 7SEG Led to display time
			if(segNum==0){
				set7SEG(1);
				display7SEG(counter1);
			}
			if(segNum==1){
				set7SEG(3);
				display7SEG(counter2);
			}
			if(timer2_flag == 1){
				segNum = 1 - segNum;
				setTimer2(500);
			}
			if(timer1_flag == 1){
				if(count >= yellow/1000) {
					status = AUTO_GREEN1;
					count = 0;
					counter1 = green/1000 + 1;
					counter2 = red/1000 + 1;
				}
				count++;
				counter1--;
				counter2--;
				setTimer1(1000);
			}
			//When count up to duration of LED, change status
			if(isSelectPressed()==1){
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
				clearLed();
			}
			break;
		default:
			break;
	}
}

