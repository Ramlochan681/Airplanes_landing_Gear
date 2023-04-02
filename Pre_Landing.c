/*
 * Pre_Landing.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */
#include"States.h"															// included the user defined header file states.h

void Pre_Landing()															// return type function Pre_Landing is called
{
	current_state = PRE_LANDING;											// shows that current state is Pre_Landing
	printf("\nEnter the Pilot's Lever Position and Status of Hydraulic Mechanism :");// Printing the message to enter the input for pilot lever and status of hydraulic
	fflush(stdout);															// cleaning the cache memory
	scanf("%d %d",&pilot_lever,&hydraulic_mechanism);						// reading the input given by the user
	if(pilot_lever == DOWN && hydraulic_mechanism == Working)				// if keyword is used to compare the given condition to the user input and if its true, than
	{
		current_state = LOWERING_GR;										// current state updated that is Lowering Gear
		printf("\nCurrent State : %s\n",State_Machine[current_state].current_state_indication);// printing the current state indication
		printf("\Light Status:%s\n",State_Machine[current_state].light_status);// printing the light status of the plane
		printf("Direction Valve Status:%s\n",State_Machine[current_state].direction_Valve_status);// printing the direction valve status
	}
	else if(pilot_lever == DOWN && hydraulic_mechanism == Malfunctioning)	// else if is used to check the other condition of the given input and printing the state
	{
		current_state = LOWERING_GR;										// it update the current state that is Lowering Gear
		printf("\nCurrent State :%s\n",State_Machine[current_state].current_state_indication);// print the current state indication value
		printf("Light Status:%s\n",State_Machine[current_state].light_status);// printing the light status of the of the plane
		printf("Direction Valve Status: %s\n",State_Machine[current_state].direction_Valve_status);// printing the direction valve status
		printf("Gas Pressurized Spring System Status :%s\n",State_Machine[current_state].gas_pressurized_spring_status[hydraulic_mechanism]);
	}		    															// printing the gas pressurized spring status
	else (pilot_lever == (UP || Raising || Falling));						// else return to false condition of 'if'
	{
		Pre_Landing();														// return to Pre_Landing condition
	}
}
