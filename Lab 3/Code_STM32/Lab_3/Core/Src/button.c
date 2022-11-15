/*
 * button.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#include "button.h"

int button_select_flag = 0;
int button_modify_flag = 0;
int button_set_value_flag = 0;

int key_reg0_button1 = NORMAL_STATE;
int key_reg1_button1 = NORMAL_STATE;
int key_reg2_button1 = NORMAL_STATE;
int stable_state1 = NORMAL_STATE;

int key_reg0_button2 = NORMAL_STATE;
int key_reg1_button2 = NORMAL_STATE;
int key_reg2_button2 = NORMAL_STATE;
int stable_state2 = NORMAL_STATE;

int key_reg0_button3 = NORMAL_STATE;
int key_reg1_button3 = NORMAL_STATE;
int key_reg2_button3 = NORMAL_STATE;
int stable_state3 = NORMAL_STATE;

int timer_for_key_select_press = 200;
int timer_for_key_modify_press = 50;
int timer_for_key_set_value_press = 200;


int isButtonSelectPressed(){
	if(button_select_flag == 1){
		button_select_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonModifyPressed(){
	if(button_modify_flag == 1){
		button_modify_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonSetValuePressed(){
	if(button_set_value_flag == 1){
		button_set_value_flag = 0;
		return 1;
	}
	return 0;
}

/////////////////////////////////////
void subKey1(){
	button_select_flag = 1;
}

void subKey2(){
	button_modify_flag = 1;
}

void  subKey3(){
	button_set_value_flag = 1;
}

///////////////////////////////////////////

void getKeySelectInput(){
	key_reg0_button1 = key_reg1_button1;
    key_reg1_button1 = key_reg2_button1;
    key_reg2_button1 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
    if ((key_reg0_button1 == key_reg1_button1) && (key_reg1_button1 == key_reg2_button1))
    {
        if (key_reg2_button1 != stable_state1)
        {
            stable_state1 = key_reg2_button1;

            if (key_reg2_button1 == PRESSED_STATE)
            {
            	subKey1();
                timer_for_key_select_press = 200;
            }
        }
        else
        {
            timer_for_key_select_press--;
            if (timer_for_key_select_press == 0)
            {
            	stable_state1 = NORMAL_STATE;
            }
        }
    }
}


void getKeyModifyInput(){
	key_reg0_button2 = key_reg1_button2;
    key_reg1_button2 = key_reg2_button2;
    key_reg2_button2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
    if ((key_reg0_button2 == key_reg1_button2) && (key_reg1_button2 == key_reg2_button2))
    {
        if (key_reg2_button2 != stable_state2)
        {
            stable_state2 = key_reg2_button2;

            if (key_reg2_button2 == PRESSED_STATE)
            {
                subKey2();
                timer_for_key_modify_press = 50;
            }
        }
        else
        {
            timer_for_key_modify_press--;
            if (timer_for_key_modify_press == 0)
            {
            	stable_state2 = NORMAL_STATE;
            }
        }
    }
}


void getKeySetValueInput(){
	key_reg0_button3 = key_reg1_button3;
    key_reg1_button3 = key_reg2_button3;
    key_reg2_button3 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
    if ((key_reg0_button3 == key_reg1_button3) && (key_reg1_button3 == key_reg2_button3))
    {
        if (key_reg2_button3 != stable_state3)
        {
            stable_state3 = key_reg2_button3;

            if (key_reg2_button3 == PRESSED_STATE)
            {
                subKey3();
                timer_for_key_set_value_press = 200;
            }
        }
        else
        {
            timer_for_key_set_value_press--;
            if (timer_for_key_set_value_press == 0)
            {
            	stable_state3 = NORMAL_STATE;
            }
        }
    }
}

