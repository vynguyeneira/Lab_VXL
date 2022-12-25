/*
 * uart.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_

#include "stdio.h"
#include "stdlib.h"
#include "main.h"
#include "software_timer.h"
#include "global.h"
#include "command_parser_fsm.h"

void uart_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2);
#endif /* INC_UART_FSM_H_ */
