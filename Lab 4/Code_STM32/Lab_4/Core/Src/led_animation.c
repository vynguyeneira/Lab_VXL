/*
 * led_animation.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Vy Nguyen
 */

#include "led_animation.h"
#include "main.h"
#include "button.h"

void toggleLedRed(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void toggleLedYellow(){
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}

void toggleLedGreen(){
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}

void toggleLedBlue(){
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}

void toggleLedOneShot(){
	HAL_GPIO_TogglePin(LED_ONE_TASK_GPIO_Port, LED_ONE_TASK_Pin);
}

void toggleLedButton(){
	if(isButtonPressed()){
		HAL_GPIO_TogglePin(LED_BUTTON_GPIO_Port, LED_BUTTON_Pin);
	}
}

