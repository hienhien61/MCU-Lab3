/*
 * fsm_manual.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC PHUONG
*/
#include "fsm_manual.h"

int red_duration = 0;
int green_duration = 0;
int yellow_duration = 0;
int segNumber = 1;

void fsm_manual_run(){
	switch(status){
		case INIT1:
			//Set up some variable to use in MODEs
			red_duration = red/1000;
			green_duration = green/1000;
			yellow_duration = yellow/1000;
			segNumber = 1;

			//Initial state
			status = MODE1;
			setTimer1(500);
			setTimer2(500);
			clearLed();
			break;
		case MODE1:
			//Display 7SEG Led MODE
			set7SEG(4);
			display7SEG(1);
			if(timer1_flag==1){
				segNumber++;
				if(segNumber >= 5) segNumber = 1;
				setTimer1(500);
			}
			//Fist button pressed -> change MODE
			if(isSelectPressed()==1){
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
			}
			//Change to auto traffic lights
			else{
				status = INIT2;
			}
			break;
		case MODE2:
			//Display 7SEG Led corresponding to duration(1-2) and MODE (3-4)
			set7SEG(segNumber);
			if(segNumber == 1) display7SEG(red_duration/10);
			if(segNumber == 2) display7SEG(red_duration%10);
			if(segNumber == 3) display7SEG(0);
			if(segNumber == 4) display7SEG(2);
			if(timer1_flag==1){
				segNumber++;
				if(segNumber >= 5) segNumber = 1;
				setTimer1(500);
			};
			//Blinking LEDs
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer2(500);
			}
			//Fist button pressed -> change MODE
			if(isSelectPressed()==1){
				status = MODE3;
				segNumber = 1;
				setTimer1(500);
				setTimer2(500);
			}
			//Second button pressed -> increase time duration of LED
			if(isUpPressed()==1){
				red_duration++;
				if(red_duration >= 100) red_duration = 1;
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
			}
			//Third button pressed -> set time duration to LED
			if(isSetPressed()==1){
				red = red_duration*1000;
				status = MODE2;
				setTimer1(500);
				setTimer2(500);
			}
			break;
		case MODE3:
			//Display 7SEG Led corresponding to duration(1-2) and MODE (3-4)
			set7SEG(segNumber);
			if(segNumber == 1) display7SEG(yellow_duration/10);
			if(segNumber == 2) display7SEG(yellow_duration%10);
			if(segNumber == 3) display7SEG(0);
			if(segNumber == 4) display7SEG(3);
			if(timer1_flag==1){
				segNumber++;
				if(segNumber >= 5) segNumber = 1;
				setTimer1(500);
			};
			//Blinking LEDs
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer2(500);
			}
			//Fist button pressed -> change MODE
			if(isSelectPressed()==1){
				status = MODE4;
				segNumber = 1;
				setTimer1(500);
				setTimer2(500);
			}
			//Second button pressed -> increase time duration of LED
			if(isUpPressed()==1){
				yellow_duration++;
				if(yellow_duration >= 100) yellow_duration = 1;
				status = MODE3;
				setTimer1(500);
				setTimer2(500);
			}
			//Third button pressed -> set time duration to LED
			if(isSetPressed()==1){
				yellow = yellow_duration*1000;
				status = MODE3;
				setTimer1(500);
				setTimer2(500);
			}
			break;
		case MODE4:
			//Display 7SEG Led corresponding to duration(1-2) and MODE (3-4)
			set7SEG(segNumber);
			if(segNumber == 1) display7SEG(green_duration/10);
			if(segNumber == 2) display7SEG(green_duration%10);
			if(segNumber == 3) display7SEG(0);
			if(segNumber == 4) display7SEG(4);
			if(timer1_flag==1){
				segNumber++;
				if(segNumber >= 5) segNumber = 1;
				setTimer1(500);
			};
			//Blinking LEDs
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer2(500);
			}
			//Fist button pressed -> change MODE
			if(isSelectPressed()==1){
				status = MODE1;
				segNumber = 1;
				setTimer1(500);
				setTimer2(500);
				clearLed();
			}
			//Second button pressed -> increase time duration of LED
			if(isUpPressed()==1){
				green_duration++;
				if(green_duration >= 100) green_duration = 1;
				status = MODE4;
				setTimer1(500);
				setTimer2(500);
			}
			//Third button pressed -> set time duration to LED
			if(isSetPressed()==1){
				green = green_duration*1000;
				status = MODE4;
				setTimer1(500);
				setTimer2(500);
			}
			break;
		default:
			break;
	}
}




