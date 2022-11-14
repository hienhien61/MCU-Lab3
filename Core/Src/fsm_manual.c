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

void fsm_manual_run(){
	switch(status){
		case INIT1:
			red_duration = red/1000;
			green_duration = green/1000;
			yellow_duration = yellow/1000;

			status = MODE1;
			setTimer2(500);
			clearLed();
			break;
		case MODE1:
			set7SEG(4);
			display7SEG(1);
			if(isSelectPressed()==1){
				status = MODE2;
				setTimer2(500);
			}
//			fsm_automatic_run(INIT2);
			break;
		case MODE2:
			set7SEG(4);
			display7SEG(2);
			if(isSelectPressed()==1){
				status = MODE3;
			}
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer2(500);
			}
			if(isUpPressed()==1){
				red_duration++;
				status = UP_RED;
				setTimer1(500);
			}
			if(isSetPressed()==1){
				red = red_duration;
			}
			break;
		case MODE3:
			set7SEG(4);
			display7SEG(3);
			if(isSelectPressed()==1){;
				status = MODE4;
			}
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer2(500);
			}
			break;
		case MODE4:
			set7SEG(4);
			display7SEG(4);
			if(isSelectPressed()==1){
				status = MODE1;
				clearLed();
			}
			if(timer2_flag==1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer2(500);
			}
			break;
		default:
			break;
	}
}

void fsm_mofify_run(){
	switch(status){
		case UP_RED:
			if(timer1_flag==0){
				set7SEG(1);
				display7SEG(red_duration/10);
				setTimer1(500);

			} else{
				set7SEG(2);
				display7SEG(red_duration%10);
				setTimer1(500);
			}
			if(isUpPressed()==1){
				red_duration++;
				status = UP_RED;
				setTimer1(500);
			}
			if(isSetPressed()==1){
				red = red_duration;
				status = UP_RED;
				setTimer1(500);
			}
			break;
		case WAIT:
			break;
		default:
			break;
	}
}



