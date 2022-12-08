/*
 * button.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed();

void subKey();

void getKeyInput();


#endif /* INC_BUTTON_H_ */
