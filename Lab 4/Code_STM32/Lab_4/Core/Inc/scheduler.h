/*
 * scheduler.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Vy Nguyen
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

#define SCH_MAX_TASKS	50
extern int TICK;

typedef struct{
	void (*pTask)(void); // Pointer to the task function
	uint32_t 	Delay; // Delay until the function will next be run
	uint32_t 	Period; // Interval between subsequent runs.
	uint8_t 	RunMe;

	uint32_t 	TaskID;
}sTasks;

void SCH_Init(void);

void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

uint8_t SCH_Delete_Task(uint32_t taskID);




#endif /* INC_SCHEDULER_H_ */
