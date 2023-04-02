/*
 ============================================================================
 Name        : main1.c
 Author      : Ramlochan
 Version     :
 Copyright   : Your copyright notice
 Description : Project for Airplane landing Gear Mechanism
 ============================================================================
 */
#include "States.h"		// User defined header file is included
						// Various return type fun is initialized and assigned to static variable to fetch the assigned data from anywhere
static void (*state_table[])(void)={Gear_Down, Pre_Takeoff,Raising_Gear, Gear_Up, Pre_Landing,Lowering_Gear};
int main()				// Main function is assigned
{
	Fnite_State_Machine();// Finite_State_Machine return type function is called
	while(1)			  // while loop is used for iteration purpose to call the fun various times that is assigned
	{
		state_table[current_state]();
	}
}
