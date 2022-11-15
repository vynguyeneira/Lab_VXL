/*
 * software_timer.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Vy Nguyen
 */

#include "software_timer.h"

int TIMER_CYCLE = 10;

int timer1_counter_for_traffic_light = 0;
int timer1_flag_for_traffic_light = 0;

int timer2_counter_for_en_7seg = 0;
int timer2_flag_for_en_7seg = 0;

int timer3_counter_for_display = 0;
int timer3_flag_for_display = 0;

int timer4_counter_for_7seg_follow_mode = 0;
int timer4_flag_for_7seg_follow_mode = 0;

int timer5_counter_for_toggle = 0;
int timer5_flag_for_toggle = 0;
/////////////////////////
void setTimer1ForTrafficLight(int duration){
	timer1_counter_for_traffic_light = duration / TIMER_CYCLE;
	timer1_flag_for_traffic_light = 0;
}

void setTimer2ForEn7seg(int duration){
	timer2_counter_for_en_7seg = duration / TIMER_CYCLE;
	timer2_flag_for_en_7seg = 0;
}

void setTimer3ForDisplay(int duration){
	timer3_counter_for_display = duration / TIMER_CYCLE;
	timer3_flag_for_display = 0;
}

void setTimer4For7segFollowMode(int duration){
	timer4_counter_for_7seg_follow_mode = duration / TIMER_CYCLE;
	timer4_flag_for_7seg_follow_mode = 0;
}

void setTimer5ForToggle(int duration){
	timer5_counter_for_toggle = duration / TIMER_CYCLE;
	timer5_flag_for_toggle = 0;
}
///////////////////////////////
void resetTimer1ForTrafficLight(){
	timer1_counter_for_traffic_light = 0;
	timer1_flag_for_traffic_light = 0;
}

void resetTimer2ForEn7seg(){
	timer2_counter_for_en_7seg = 0;
	timer2_flag_for_en_7seg = 0;
}

void resetTimer3ForDisplay(){
	timer3_counter_for_display = 0;
	timer3_flag_for_display = 0;
}

void resetTimer4For7segFollowMode(){
	timer4_counter_for_7seg_follow_mode = 0;
	timer4_flag_for_7seg_follow_mode = 0;
}

void resetTimer5ForToggle(){
	timer5_counter_for_toggle = 0;
	timer5_flag_for_toggle = 0;
}
//////////////////////////////
void timerRun(){
	if (timer1_counter_for_traffic_light > 0){
		timer1_counter_for_traffic_light--;
		if(timer1_counter_for_traffic_light == 0){
			timer1_flag_for_traffic_light = 1;
		}
	}

	if(timer2_counter_for_en_7seg > 0){
		timer2_counter_for_en_7seg--;
		if(timer2_counter_for_en_7seg == 0){
			timer2_flag_for_en_7seg = 1;
		}
	}

	if(timer3_counter_for_display >  0){
		timer3_counter_for_display--;
		if(timer3_counter_for_display == 0){
			timer3_flag_for_display = 1;
		}
	}

	if(timer4_counter_for_7seg_follow_mode > 0){
		timer4_counter_for_7seg_follow_mode--;
		if(timer4_counter_for_7seg_follow_mode == 0){
			timer4_flag_for_7seg_follow_mode = 1;
		}
	}

	if(timer5_counter_for_toggle > 0){
		timer5_counter_for_toggle--;
		if(timer5_counter_for_toggle == 0){
			timer5_flag_for_toggle = 1;
		}
	}

}
