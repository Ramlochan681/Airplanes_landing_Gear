/*
 * Lowering_Gear.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */

#include"States.h"											// included Header file States.h which is user defined

void Lowering_Gear()										// Return type function Lowering Gear is being called
{
	current_state == LOWERING_GR;							// Showing the current state that is lowering Gear
	printf("\nEnter the Limit Switch status and Pilot lever Status:");// Printing the message to enter the limit switch status and pilot lever position
	fflush(stdout);											// clearing cache memory
	scanf("%d %d",&limit_switch,&pilot_lever);				// Reading the input provided by the user for limit switch and pilot lever
	if(limit_switch == Close && pilot_lever == Raising)		// if keyword is used to compare the given input by the user
	{
		current_state = PRE_TAKEOFF;						// if condition is true than current state updated as Pre_Takeoff
		printf("\nCurrent State: %s\n",State_Machine[current_state].current_state_indication);// printing the current state indication
		printf("Light Status: %s\n",State_Machine[current_state].light_status);// printing the light status of the plane
	}
	if(limit_switch == Open && pilot_lever == DOWN)			// again if keyword is used to compare the another condition,if its true then print the given condition
	{
		current_state = GR_DWN;								// current state is updated as Gear down
		printf("\nCurrent State :%s\n",State_Machine[current_state].current_state_indication);// Again printing the current state indication
		printf("Light status :%s\n",State_Machine[current_state].light_status);// Printing the light status of the plane
		printf("Hydraulic Control for Landing Gear Status :%s\n",State_Machine[current_state].hydraulic_pump_control_status);//printing hydraulic pump control status
	}
	else													// else condition is used to check the false condition of 'if'
	{
		Lowering_Gear();									// return to Lowering Gear
	}
}

