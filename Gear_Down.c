/*
 * Gear_Down.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */
#include"States.h"									// included the user defined header file States.h
#include<stdio.h>									// included the header file stdio.h for standard input and output

void Gear_Down(void)								// Return type fun Gear_Down is called for execution
{
	current_state = GR_DWN;							// showing the current position that is Gear Down
	printf("\nEnter the Pilot lever Position and Squat Switch Status :"); // Printing message to enter pilot lever position and squat switch position
	fflush(stdout);									// clearing the cache memory
	scanf("%d %d",&pilot_lever,&squat_switch);		// Reading the input provided by the user and assigning it to respective variable
	if(pilot_lever == Raising && squat_switch == Open)// if statement is used to compare the given condition
	{
		current_state = PRE_TAKEOFF;				// assigning the current state if 'if' condition is true
		printf("\n Current State : %s\n",State_Machine[current_state].current_state_indication);// printing the current state indication
		printf("\nLight Status :%s\n",State_Machine[current_state].light_status);// printing the light status of plane
	}
	else											// else is used to check the false condition of 'If'
	{
		Gear_Down();								// return to Gear Down fun
	}
}
