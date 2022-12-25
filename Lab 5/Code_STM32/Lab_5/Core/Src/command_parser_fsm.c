/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Vy Nguyen
 */

#include "main.h"
#include "command_parser_fsm.h"


void command_parser_fsm() {
	switch(state_parser) {
	case INIT:
		if(character == '!') {
			state_parser = READ;
			command_index = 0;
		}
		break;

	case READ:
		if(character == '#') {
			state_parser = INIT;
			command[command_index] = '\0';
			command_flag = 1;
		}
		else {
			if (character == '!')
				command_index = 0;
			else {
				command[command_index++] = character;
				if (command_index == MAX_SIZE) command_index = 0;
			}
		}
		break;
	default:
		break;
	}
}

