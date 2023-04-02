/*
 * Pre_Takeoff.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */

#include"States.h"												// included the user defined header file States.h
#include<stdio.h>												// included the header file for standard input and output

void Pre_Takeoff()												// Return type fun Pre_Takeoff is called
{
	current_state = PRE_TAKEOFF;								// check the current status that is Pre_takeoff
	printf("\nEnter the Pilot's lever Position, Squat Switch Status and Hydraulic Mechanism Status :");// Printing the given message asking for user input
	fflush(stdout);												// clearing cache memory
	scanf("%d %d %d",&pilot_lever,&squat_switch,&hydraulic_mechanism); // Scanning the user input given for pilot lever,squat switch & hydraulic mechanism
	printf("\n Wait for two seconds\n");						// print the message that wait for two second
	if (pilot_lever == Falling || squat_switch == Close)		// if statement is used to check the given condition if its true than return to given condition
	{
		Gear_Down();											// return to Gear Down fun
	}
	else if(pilot_lever == UP && squat_switch == Open && hydraulic_mechanism == Working)// else if check the other provided condition if its true than it get executed
	{
		current_state = RAISING_GR;								// check current state
		printf("\nCurrent State :%s\n",State_Machine[current_state].current_state_indication);// printing current state indication
		printf("Light Status :%s\n",State_Machine[current_state].light_status);// printing the light status of Plane
		printf("Direction Valve Status :%s\n\n",State_Machine[current_state].direction_Valve_status);// printing the direction valve status of plane
	}
	else if(pilot_lever == UP && squat_switch == Open && hydraulic_mechanism == Malfunctioning) // again else if is used to check another condition
	{
		printf("Light Status :%s\n",State_Machine[current_state].light_status);// if else if condition is true than printing the light status
		printf("Direction Valve Status :%s\n",State_Machine[current_state].direction_Valve_status);// printing the Direction valve status
		printf("Gas pressurized Spring System Status :%s\n",State_Machine[current_state].gas_pressurized_spring_status[hydraulic_mechanism]);
	}															// printing the Gas pressurized spring system status
}
