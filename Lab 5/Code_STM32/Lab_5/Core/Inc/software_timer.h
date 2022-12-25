/*
 * software_timer.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int TIME_CYCLE;

extern int timer1_flag;
extern int timer2_flag;

void set_timer1(int duration);
void set_timer2(int duration);

void reset_timer1();
void reset_timer2();


void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
