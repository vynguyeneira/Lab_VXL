/*
 * uart.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Vy Nguyen
 */

#include "uart_fsm.h"

void uart_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch(state_uart) {

	case RST: //From the console, user types !RST# to ask for a sensory data.
		if (command_flag == 1) {
			command_flag = 0;
			if (command[0] == 'R' && command[1] == 'S' && command[2] == 'T') {
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				state_uart = ADC;
				set_timer2(3000); //The timeout for waiting the !OK# at STM32 is 3 seconds.
			}
		}
		break;

	case ADC:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
		state_uart = OK;
		break;

	case OK:  //The user ends the communication by sending !OK#
		if (command_flag == 1) {
			command_flag = 0;
			if (command[0] == 'O' && command[1] == 'K') {
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				state_uart = RST;
				reset_timer2();
			}
		}
		if(timer2_flag == 1) {
			state_uart = ADC;
			set_timer2(3000); //The timeout for waiting the !OK# at STM32 is 3 seconds.
		}
		break;
	default:
		break;
	}
}

