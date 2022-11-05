/*
 * softwareTimer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timer1_flag_for_led;
extern int timer2_flag_for_auto_count_down;
extern int timer3_flag_for_time_out;

void setTimer1ForLed(int duration);
void setTimer2ForAutoCountDown(int duration);
void setTimer3ForTimeOut(int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
