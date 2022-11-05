/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Vy Nguyen
 */

#include "fsm.h"
#include "display.h"
#include "button.h"
#include "global.h"
#include "softwareTimer.h"

////////////////////////////STEP3///////////////////////
void fsm_simple_buttons_run(){
	switch (status){
		case INIT:
			display7SEG(0);
			status = SETTING;
			break;

		case SETTING:
			if(isButtonResetPressed() == 1){
				status = RESET_PRESSED;
			}
			if(isButtonIncPressed() == 1){
				status = INC_PRESSED;
			}
			if(isButtonDecPressed() == 1){
				status = DEC_PRESSED;
			}
			if(timer3_flag_for_time_out == 1){
				status = AUTO_COUNT_DOWN;
			}
			break;

		case RESET_PRESSED:
			display7SEG(0);
			counter = 0;
			status = SETTING;
			break;

		case INC_PRESSED:
			counter++;
			if(counter > 9){
				counter = 0;
			}
			display7SEG(counter);
			status = SETTING;
			break;

		case DEC_PRESSED:
			counter--;
			if(counter < 0){
				counter = 9;
			}
			display7SEG(counter);
			status = SETTING;
			break;

		case AUTO_COUNT_DOWN:
			if(timer2_flag_for_auto_count_down == 1){
				if(counter > 0){
					counter--;
					display7SEG(counter);
				}
				setTimer2ForAutoCountDown(100);
			}
			if(isButtonResetPressed() == 1){
				status = RESET_PRESSED;
			}
			if(isButtonIncPressed() == 1){
				status = INC_PRESSED;
			}
			if(isButtonDecPressed() == 1){
				status = DEC_PRESSED;
			}
			break;
		default:
			break;
	}
}


/////////////////////////////////// STEP1, STEP2 /////////////////////////
/* void fsm_simple_buttons_run(){
	switch (status){
		case INIT:
			display7SEG(0);
			status = SETTING;
			break;

		case SETTING:
			if(isButtonResetPressed() == 1){
				status = RESET_PRESSED;
			}
			if(isButtonIncPressed() == 1){
				status = INC_PRESSED;
			}
			if(isButtonDecPressed() == 1){
				status = DEC_PRESSED;
			}
			break;

		case RESET_PRESSED:
			display7SEG(0);
			counter = 0;
			status = SETTING;
			break;

		case INC_PRESSED:
			counter++;
			if(counter > 9){
				counter = 0;
			}
			display7SEG(counter);
			status = SETTING;
			break;

		case DEC_PRESSED:
			counter--;
			if(counter < 0){
				counter = 9;
			}
			display7SEG(counter);
			status = SETTING;
			break;
		default:
			break;
	}
}*/
