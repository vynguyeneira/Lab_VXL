/*
 * fsm.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#include "fsm.h"

void fsm_run(){
	switch(status){

		case MODE_2:
			resetTimer1ForTrafficLight();
			resetTimer2ForEn7seg();
			resetTimer3ForDisplay();

			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_SET);

			if(timer5_flag_for_toggle == 1){
				HAL_GPIO_TogglePin(LED_RED_1_3_GPIO_Port, LED_RED_1_3_Pin);
				HAL_GPIO_TogglePin(LED_RED_2_4_GPIO_Port, LED_RED_2_4_Pin);
				setTimer5ForToggle(500);
			}

			if(timer4_flag_for_7seg_follow_mode){
				led_buffer[0] = 0;
				led_buffer[1] = 2;
				led_buffer[2] = counter_led_red/10;
				led_buffer[3] = counter_led_red%10;
				update7SEG(index_led);
				setTimer4For7segFollowMode(250);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_3;
			}

			if(isButtonModifyPressed() == 1){
				status = LED_RED_ANIMATION;
				if(counter_led_red >= 99){
					counter_led_red = 1;
				}
				else counter_led_red++;
			}

			if(isButtonSetValuePressed() == 1){

			};
			break;

		case LED_RED_ANIMATION:
			if(timer5_flag_for_toggle == 1){
				HAL_GPIO_TogglePin(LED_RED_1_3_GPIO_Port, LED_RED_1_3_Pin);
				HAL_GPIO_TogglePin(LED_RED_2_4_GPIO_Port, LED_RED_2_4_Pin);
				setTimer5ForToggle(500);
			}

			if(timer4_flag_for_7seg_follow_mode){
				led_buffer[2] = counter_led_red/10;
				led_buffer[3] = counter_led_red%10;
				update7SEG(index_led);
				setTimer4For7segFollowMode(250);
			}

			if(isButtonModifyPressed() == 1){
				if(counter_led_red >= 99){
					counter_led_red = 1;
				}
				else counter_led_red++;
			}

			if(isButtonSelectPressed() == 1){

			};

			if(isButtonSetValuePressed() == 1){
				if(counter_led_red > counter_led_yellow){
					counter_led_green = counter_led_red - counter_led_yellow;
					status = MODE_2;
				}
			}
			break;


		case MODE_3:
			resetTimer1ForTrafficLight();
			resetTimer2ForEn7seg();
			resetTimer3ForDisplay();

			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_SET);

			if(timer5_flag_for_toggle == 1){
				HAL_GPIO_TogglePin( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin);
				HAL_GPIO_TogglePin( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin );
				setTimer5ForToggle(500);
			}

			if(timer4_flag_for_7seg_follow_mode){
				led_buffer[0] = 0;
				led_buffer[1] = 3;
				led_buffer[2] = counter_led_yellow/10;
				led_buffer[3] = counter_led_yellow%10;
				update7SEG(index_led);
				setTimer4For7segFollowMode(250);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_4;
			}

			if(isButtonModifyPressed() == 1){
				status = LED_YELLOW_ANIMATION;
				if(counter_led_yellow >= 10){
					counter_led_yellow = 1;
				}
				else counter_led_yellow++;
			}

			if(isButtonSetValuePressed() == 1){

			};
			break;


		case LED_YELLOW_ANIMATION:
			if(timer5_flag_for_toggle == 1){
				HAL_GPIO_TogglePin(LED_YELLOW_1_3_GPIO_Port, LED_YELLOW_1_3_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW_2_4_GPIO_Port, LED_YELLOW_2_4_Pin);
				setTimer5ForToggle(500);
			}

			if(timer4_flag_for_7seg_follow_mode){
				led_buffer[2] = counter_led_yellow/10;
				led_buffer[3] = counter_led_yellow%10;
				update7SEG(index_led);
				setTimer4For7segFollowMode(250);
			}

			if(isButtonModifyPressed() == 1){
				if(counter_led_yellow >= 10){
					counter_led_yellow = 1;
				}
				else counter_led_yellow++;
			}

			if(isButtonSelectPressed() == 1){

			};

			if(isButtonSetValuePressed() == 1){
				if(counter_led_red > counter_led_yellow){
					counter_led_green = counter_led_red - counter_led_yellow;
					status = MODE_3;
				}
			}
			break;


		case MODE_4:
			resetTimer1ForTrafficLight();
			resetTimer2ForEn7seg();
			resetTimer3ForDisplay();

			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_SET);

			if(timer5_flag_for_toggle == 1){
				HAL_GPIO_TogglePin(LED_GREEN_1_3_GPIO_Port, LED_GREEN_1_3_Pin);
				HAL_GPIO_TogglePin(LED_GREEN_2_4_GPIO_Port, LED_GREEN_2_4_Pin);
				setTimer5ForToggle(500);
			}

			if(timer4_flag_for_7seg_follow_mode){
				led_buffer[0] = 0;
				led_buffer[1] = 4;
				led_buffer[2] = counter_led_green/10;
				led_buffer[3] = counter_led_green%10;
				update7SEG(index_led);
				setTimer4For7segFollowMode(250);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_1;
				resetTimer1ForTrafficLight();
				resetTimer2ForEn7seg();
				resetTimer3ForDisplay();

				count_led_1_3 = 0;
				count_led_2_4 = 0;
				timer1_flag_for_traffic_light = 1;
				timer2_flag_for_en_7seg = 1;
				timer3_flag_for_display = 1;
			}

			if(isButtonModifyPressed() == 1){
				status = LED_GREEN_ANIMATION;
				if(counter_led_green >= 99){
					counter_led_green = 1;
				}
				else counter_led_green++;
			}

			if(isButtonSetValuePressed() == 1){
			};
			break;


		case LED_GREEN_ANIMATION:
			if(timer5_flag_for_toggle == 1){
				HAL_GPIO_TogglePin(LED_GREEN_1_3_GPIO_Port, LED_GREEN_1_3_Pin);
				HAL_GPIO_TogglePin(LED_GREEN_2_4_GPIO_Port, LED_GREEN_2_4_Pin);
				setTimer5ForToggle(500);
			}

			if(timer4_flag_for_7seg_follow_mode){
				led_buffer[2] = counter_led_green/10;
				led_buffer[3] = counter_led_green%10;
				update7SEG(index_led);
				setTimer4For7segFollowMode(250);
			}

			if(isButtonModifyPressed() == 1){
				if(counter_led_green >= 99){
					counter_led_green = 1;
				}
				else counter_led_green++;
			}

			if(isButtonSelectPressed() == 1){

			};

			if(isButtonSetValuePressed() == 1){
				if((counter_led_yellow + counter_led_green < 100) && (counter_led_green > counter_led_yellow)){
					counter_led_red = counter_led_green + counter_led_yellow;
					status = MODE_4;
				}
			}
			break;

		default:
			break;
	}
}
