/*
 * button.c
 *
 *  Created on: Nov 2, 2022
 *      Author: PC PHUONG
*/
#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0[KEY_SIZE] = {NORMAL_STATE};
int KeyReg1[KEY_SIZE] = {NORMAL_STATE};
int KeyReg2[KEY_SIZE] = {NORMAL_STATE};

int KeyReg3[KEY_SIZE] = {NORMAL_STATE};
int button_state[KEY_SIZE] = {0};

int TimerForKeyPress = 2000;

void readButton(){
	button_state[0] = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
	button_state[1] = HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin);
	button_state[2] = HAL_GPIO_ReadPin(B_SET_GPIO_Port, B_SET_Pin);
}

int isSelectPressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isUpPressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isSetPressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int i){
	if(i==0)button1_flag = 1;
	if(i==1) button2_flag = 1;
	if(i==2) button3_flag = 1;
}

void getKeyInput(){
	//Chong rung
	for(int i = 0; i < KEY_SIZE; i++){
		readButton();
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = button_state[i];
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					TimerForKeyPress = 2000;
				}
			}
			//Nhan de voi thoi gian TimerForKeyPress
			else{
				   TimerForKeyPress--;
					if (TimerForKeyPress == 0){
					   if(KeyReg2[i] == PRESSED_STATE){
						  subKeyProcess(i);
					   }
					  TimerForKeyPress = 2000;
					}
			}
		}
	}
}


