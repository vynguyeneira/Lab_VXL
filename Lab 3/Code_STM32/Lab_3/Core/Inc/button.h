/*
 * button.h
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonSelectPressed();
int isButtonModifyPressed();
int isButtonSetValuePressed();

void subKey1();
void subKey2();
void subKey3();

void getKeySelectInput();
void getKeyModifyInput();
void getKeySetValueInput();

#endif /* INC_BUTTON_H_ */
