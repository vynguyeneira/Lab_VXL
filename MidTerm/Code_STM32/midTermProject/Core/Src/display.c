/*
 * display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Vy Nguyen
 */

#include "display.h"

void blinkyLedRed(){
	  if(timer1_flag_for_led == 1){
		  setTimer1ForLed(100);
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  }

}


void display7SEG(int num)
{
	if (num == 0)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_6_Pin, GPIO_PIN_SET);
	}
	else if (num == 1)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_1_Pin|LED7_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_SET);
	}
	else if (num == 2)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_3_Pin|LED7_4_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_2_Pin|LED7_5_Pin, GPIO_PIN_SET);
	}
	else if (num == 3)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_4_Pin|LED7_5_Pin, GPIO_PIN_SET);
	}
	else if (num == 4)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_1_Pin|LED7_2_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_3_Pin|LED7_4_Pin, GPIO_PIN_SET);
	}
	else if (num == 5)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_2_Pin|LED7_3_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_1_Pin|LED7_4_Pin, GPIO_PIN_SET);
	}
	else if (num == 6)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_1_Pin, GPIO_PIN_SET);
	}
	else if (num == 7)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_SET);
	}
	else if (num == 8)
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin (GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, LED7_4_Pin, GPIO_PIN_SET);
	}
}
