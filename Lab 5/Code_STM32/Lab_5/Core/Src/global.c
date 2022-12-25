/*
 * globla.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Vy Nguyen
 */
#include "global.h"

uint8_t buffer[MAX_SIZE];
uint8_t command[MAX_SIZE];
char str[100];

// State init
int state_parser = INIT;
int state_uart = RST;

// Variables

uint8_t character = 0;
uint32_t ADC_value = 0;

uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command_flag = 0;
uint8_t command_index = 0;

