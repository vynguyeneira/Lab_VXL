/*
 * fsm_automatic_mode1_run.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#include "fsm_automatic_mode1_run.h"
#include "software_timer.h"

void fsm_automatic_mode1_run(){
	if(timer3_flag_for_display == 1){
		display();
		setTimer3ForDisplay(1000);
	}

	if(timer2_flag_for_en_7seg == 1){
		update7SEG(index_led);
		setTimer2ForEn7seg(250);
	}

	switch(status){

		case MODE_1:
			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_SET);

			status = RED_GREEN;
			setTimer1ForTrafficLight(counter_led_green*1000);
			break;

		case RED_GREEN:
			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_RESET );
			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_SET);
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_RESET);

			if(timer1_flag_for_traffic_light == 1){
				status = RED_YELLOW;
				setTimer1ForTrafficLight(counter_led_yellow *1000);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_2;
				HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_RESET ) ;
				HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_RESET ) ;
			}
			break;


		case RED_YELLOW:
			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_SET) ;
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_SET) ;
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_RESET) ;
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_SET) ;

			if(timer1_flag_for_traffic_light == 1){
				status = GREEN_RED;
				setTimer1ForTrafficLight(counter_led_green*1000);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_2;
				HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_RESET ) ;
				HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_RESET ) ;
			}
			break;

		case GREEN_RED:
			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_SET) ;
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_RESET) ;
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_SET) ;
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_SET) ;

			if(timer1_flag_for_traffic_light == 1){
				status = YELLOW_RED;
				setTimer1ForTrafficLight(counter_led_yellow*1000);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_2;
				HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_RESET ) ;
				HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_RESET ) ;
			}
			break;

		case YELLOW_RED:
			HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( LED_YELLOW_1_3_GPIO_Port , LED_YELLOW_1_3_Pin , GPIO_PIN_RESET) ;
			HAL_GPIO_WritePin ( LED_GREEN_1_3_GPIO_Port , LED_GREEN_1_3_Pin , GPIO_PIN_SET) ;
			HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( LED_YELLOW_2_4_GPIO_Port , LED_YELLOW_2_4_Pin , GPIO_PIN_SET) ;
			HAL_GPIO_WritePin ( LED_GREEN_2_4_GPIO_Port , LED_GREEN_2_4_Pin , GPIO_PIN_SET) ;

			if(timer1_flag_for_traffic_light == 1){
				status = RED_GREEN;
				setTimer1ForTrafficLight(counter_led_green*1000);
			}

			if(isButtonSelectPressed() == 1){
				status = MODE_2;
				HAL_GPIO_WritePin ( LED_RED_1_3_GPIO_Port , LED_RED_1_3_Pin , GPIO_PIN_RESET ) ;
				HAL_GPIO_WritePin ( LED_RED_2_4_GPIO_Port , LED_RED_2_4_Pin , GPIO_PIN_RESET ) ;
			}
			break;

		default:
			break;
	}
}
