/*
 * button.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Vy Nguyen
 */

#include "button.h"

int button_flag = 0;

int key_reg0_button = NORMAL_STATE;
int key_reg1_button = NORMAL_STATE;
int key_reg2_button = NORMAL_STATE;
int stable_state = NORMAL_STATE;

int timer_for_key_pressed = 100;

int isButtonPressed(){
	if(button_flag == 1){
		button_flag = 0;
		return 1;
	}
	return 0;
}


void subKey(){
	button_flag = 1;
}


void getKeyInput(){
	key_reg0_button = key_reg1_button;
	key_reg1_button = key_reg2_button;
	key_reg2_button = HAL_GPIO_ReadPin(Button_GPIO_Port, Button_Pin);

	if((key_reg0_button == key_reg1_button) && (key_reg1_button == key_reg2_button))
	{
		if(key_reg2_button != stable_state)
		{
			stable_state = key_reg2_button;
			if (key_reg2_button == PRESSED_STATE)
			{
				subKey();
				timer_for_key_pressed = 100;
			}
		}

		else
		{
			timer_for_key_pressed--;
			if(timer_for_key_pressed == 0){
				if(key_reg2_button == PRESSED_STATE){
					subKey();
				}
				timer_for_key_pressed = 100;
			}
		}
	}

}
