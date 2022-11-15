/*
 * global.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#include "global.h"

int status = 0;

int counter_led_red = 5;
int counter_led_yellow = 2;
int counter_led_green = 3;

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

int count_led_1_3 = 0;
int count_led_2_4 = 0;

//////////////////////////////////////
void display7SEG(int num)
{
	if (num == 0)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG6_Pin, GPIO_PIN_SET);
	}
	else if (num == 1)
	{
		HAL_GPIO_WritePin (GPIOB, SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
	}
	else if (num == 2)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG2_Pin|SEG5_Pin, GPIO_PIN_SET);
	}
	else if (num == 3)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
	}
	else if (num == 4)
	{
		HAL_GPIO_WritePin (GPIOB, SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
	}
	else if (num == 5)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG1_Pin|SEG4_Pin, GPIO_PIN_SET);
	}
	else if (num == 6)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG1_Pin, GPIO_PIN_SET);
	}
	else if (num == 7)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
	}
	else if (num == 8)
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin (GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (GPIOB, SEG4_Pin, GPIO_PIN_SET);
	}
}



void update7SEG(int index){
	switch (index){
	case 0:
		//Display the first 7SEG with led_buffer[0]
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, SET);
		index_led = 1;
		break;

	case 1:
		//Display the first 7SEG with led_buffer[1]
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, SET);
		index_led = 2;
		break;

	case 2:
		//Display the first 7SEG with led_buffer[2]
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, SET);
		index_led = 3;
		break;

	case 3:
		//Display the first 7SEG with led_buffer[3]
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, RESET);
		index_led = 0;
		break;

	default:
		break;
	}
}


void display()
{
    if (count_led_1_3 < counter_led_red)
    {
        led_buffer[0] = (counter_led_red - count_led_1_3) / 10;
        led_buffer[1] = (counter_led_red - count_led_1_3) % 10;
    }
    else
    {
        if (count_led_1_3 < (counter_led_red + counter_led_green))
        {
            led_buffer[0] = (counter_led_red + counter_led_green - count_led_1_3) / 10;
            led_buffer[1] = (counter_led_red + counter_led_green - count_led_1_3) % 10;
        }
        else
        {
            led_buffer[0] = (counter_led_red + counter_led_green + counter_led_yellow - count_led_1_3) / 10;
            led_buffer[1] = (counter_led_red + counter_led_green + counter_led_yellow - count_led_1_3) % 10;
        }
    }
    count_led_1_3++;
    if (count_led_1_3 >= counter_led_red + counter_led_green + counter_led_yellow)
        count_led_1_3 = 0;

    if (count_led_2_4 < counter_led_green)
    {
        led_buffer[2] = (counter_led_green - count_led_2_4) / 10;
        led_buffer[3] = (counter_led_green - count_led_2_4) % 10;
    }
    else
    {
        if (count_led_2_4 < (counter_led_green + counter_led_yellow))
        {
            led_buffer[2] = (counter_led_green + counter_led_yellow - count_led_2_4) / 10;
            led_buffer[3] = (counter_led_green + counter_led_yellow - count_led_2_4) % 10;
        }
        else
        {
            led_buffer[2] = (counter_led_red + counter_led_green + counter_led_yellow - count_led_2_4) / 10;
            led_buffer[3] = (counter_led_red + counter_led_green + counter_led_yellow - count_led_2_4) % 10;
        }
    }
    count_led_2_4++;
    if (count_led_2_4 >= counter_led_red + counter_led_green + counter_led_yellow)
        count_led_2_4 = 0;
}
///////////////////////////////////


