/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "softwareTimer.h"
#include "button.h"

#define INIT 				0
#define SETTING				10
#define RESET_PRESSED 		1
#define INC_PRESSED			2
#define DEC_PRESSED			3
#define AUTO_COUNT_DOWN		4

extern int status;
extern int counter;


#endif /* INC_GLOBAL_H_ */
