/*
 * global.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

extern char str[100];

extern uint32_t ADC_value;

// Command parser
#define INIT	 		0
#define READ			1

extern int state_parser;

// UART
#define MAX_SIZE		30

#define RST		 		2
#define OK		 		3
#define ADC				4


extern int state_uart;

// Read data
extern uint8_t character;
extern uint8_t buffer[MAX_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

// Read command
extern uint8_t command_flag;
extern uint8_t command[MAX_SIZE];
extern uint8_t command_index;

#endif /* INC_GLOBAL_H_ */

