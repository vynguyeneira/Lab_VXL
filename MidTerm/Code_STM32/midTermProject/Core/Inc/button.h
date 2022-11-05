/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonResetPressed();
int isButtonIncPressed();
int isButtonDecPressed();

void subKeyResetProcess();
void subKeyIncProcess();
void subKeyDecProcess();

void getKeyInputReset();
void getKeyInputInc();
void getKeyInputDec();

extern int button_reset_flag;
extern int button_inc_flag;
extern int button_dec_flag;

extern int stable_state1;
extern int stable_state2;
extern int stable_state3;

extern int timer_for_key_reset_press;
extern int timer_for_key_inc_press;
extern int timer_for_key_dec_press;
#endif /* INC_BUTTON_H_ */
