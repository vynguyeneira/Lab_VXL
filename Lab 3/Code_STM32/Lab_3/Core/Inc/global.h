/*
 * global.h
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define RED_GREEN 		1
#define RED_YELLOW		2
#define GREEN_RED		3
#define YELLOW_RED		4

#define MODE_1			11
#define MODE_2			12
#define MODE_3			13
#define MODE_4			14

#define LED_RED_ANIMATION 		21
#define LED_YELLOW_ANIMATION	22
#define LED_GREEN_ANIMATION		23

extern int status;
extern int counter_led_red;
extern int counter_led_yellow;
extern int counter_led_green;

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

extern int count_led_1_3;
extern int count_led_2_4;

void display7SEG(int num);
void update7SEG(int index);
void display();

#endif /* INC_GLOBAL_H_ */
