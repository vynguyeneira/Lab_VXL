/*
 * scheduler.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Vy Nguyen
 */

#include "scheduler.h"

int TICK;
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;
unsigned char error_code_G = 0;


void SCH_Init(void) {
    unsigned char Index;
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
        SCH_Delete_Task(Index);
    }
    error_code_G = 0; //Reset the global error variable
    // The task array is empty --> SCH_Delete_Task() will generate an error code
}


void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD) {

	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/TICK;
		SCH_tasks_G[current_index_task].Period =  PERIOD/TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}

	if(current_index_task == SCH_MAX_TASKS){
		return;   //Task list is full
	}

}


void SCH_Update(void) {
    unsigned char Index;
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].Delay > 0)
			SCH_tasks_G[Index].Delay--; // Check if there is a task at this location
		else {
			SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period; // Schedule periodic tasks to run again
			SCH_tasks_G[Index].RunMe += 1;  // The task is due to run, increase the 'RunMe' flag
		}
	}
}

void SCH_Dispatch_Tasks(void) {
	unsigned char Index;
	for(Index = 0; Index < current_index_task; Index++){
        if (SCH_tasks_G[Index].RunMe > 0) {
            SCH_tasks_G[Index].RunMe -= 1; // Reduce RunMe flag
            (*SCH_tasks_G[Index].pTask)(); // Run the task
            // Periodic tasks will automatically run again

            if (SCH_tasks_G[Index].Period == 0) // For 'one shot' task, remove it from the array
            {
                SCH_Delete_Task(Index);
            }
        }
    }
}


uint8_t SCH_Delete_Task(uint32_t taskID) {
	// If there is no task in array or taskID invalid
	if (current_index_task == 0 || taskID < 0 || taskID >= SCH_MAX_TASKS) {
		return -1;
	}
	for (int Index = taskID; Index < SCH_MAX_TASKS - 1; Index++) {
		// Move task from index Index + 1 --> Index
		SCH_tasks_G[Index].pTask = SCH_tasks_G[Index + 1].pTask;
		SCH_tasks_G[Index].Delay = SCH_tasks_G[Index + 1].Delay;
		SCH_tasks_G[Index].Period = SCH_tasks_G[Index + 1].Period;
		SCH_tasks_G[Index].RunMe = SCH_tasks_G[Index + 1].RunMe;
	}

	SCH_tasks_G[SCH_MAX_TASKS - 1].pTask = 0x0000;
	SCH_tasks_G[SCH_MAX_TASKS - 1].Delay = 0;
	SCH_tasks_G[SCH_MAX_TASKS - 1].Period = 0;
	SCH_tasks_G[SCH_MAX_TASKS - 1].RunMe = 0;
	current_index_task--;
	return taskID;
}

