/*
 * Gear_Up.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */
#include"States.h"												// included user defined header file states.h

void Gear_Up()													// return type fun Gear_Up is initialized
{
	current_state = GR_UP;										// fetch the current state that is Gear Up
	printf("\nEnter the Pilot's Lever Position :");				// Asking pilot lever position from user
	fflush(stdout);												// clearing cache memory
	scanf("%d",&pilot_lever);									// scanning the pilot lever status given by the user
	if(pilot_lever == Falling)									// if condition is used to compare the given statement if its true then update the current state
	{
		current_state = PRE_LANDING;							// updating the current state
		printf("\nCurrent_State : %s\n",State_Machine[current_state].current_state_indication);// print current state indication
		printf("Light Status :%s\n",State_Machine[current_state].light_status);// printing light status
		printf("Hydraulic Control for Landing Gear Status :%s\n",State_Machine[current_state].hydraulic_pump_control_status);// print hydraulic pump current status
	}
	else														// used to print the false condition of if statement
	{
		Gear_Up;												// reach to again Gear Up condition
	}
}
