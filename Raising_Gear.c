/*
 * Raising_Gear.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */

#include"States.h"													// included the user defined Header file states.h

void Raising_Gear()													// Return type function Raising Gear is called
{
	current_state = RAISING_GR;										// showing the current state position that is Raising Gear
	printf("\nEnter the Limit Switch Status, Pilots lever Status :");// printing input for limit switch status and pilot lever status
	fflush(stdout);													// clearing the cache memory
	scanf("%d %d",&limit_switch,&pilot_lever);						// scanning the input given by the user
	printf("\nWait for a second\n");								// printing message to wait for a second
	if(pilot_lever == Falling && limit_switch == Open)				// if statement is used to check the given condition
	{
		current_state = PRE_LANDING;								// if statement is true than current state goes to pre_landing position
		printf("\ncurrent_state : %s\n",State_Machine[current_state].current_state_indication);	// printing the current state indication
		printf("Light Status :%s\n",State_Machine[current_state].light_status);// Printing Light status
		printf("Hydraulic Control for Landing Gear Status :%s\n",State_Machine[current_state].hydraulic_pump_control_status);// Printing hydraulic pump control status
	}
	else if(limit_switch == Close && pilot_lever == UP)				// else if used to check another condition
	{
		current_state = GR_UP;										// it shows current state that Gear UP
		printf("\nCurrent State : %s\n",State_Machine[current_state].current_state_indication);	// print the current state indication
		printf("Light Status :%s\n",State_Machine[current_state].light_status);// print light status
		printf("Hydraulic Control for Landing Gear Status :%s\n",State_Machine[current_state].hydraulic_pump_control_status);//printing hydraulic pump control status
	}
	else															// checking  the false condition of if and else if
	{
		Raising_Gear;												// return to Raising Gear
	}
}
