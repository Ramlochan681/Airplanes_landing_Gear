/*
 * Finite_State_Machine.c
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */

#include "States.h"                                       // user defined header file is included

void Fnite_State_Machine()			                      // return type function Finite_State_Machine is created
{
	current_state = GR_DWN;								  // it shows that current state is in GEAR DOWN condition
	printf("\nState Machine is initialized & Program is in Gear Down State & Light Status :%s\n",State_Machine[current_state].light_status);
}	//printing the given message that State machine is initialized and tells the light status.
