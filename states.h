/*
 * states.h
 *
 *  Created on: 28-Apr-2022
 *      Author: Ramlochan
 */
#ifndef STATES_H_								// Defining the header file States.h
#define STATES_H_
#include<stdio.h>								// including header file for standard input output

void Fnite_State_Machine();						// Various return type function is being created like Finite_state_machine
void Gear_Down();								// Gear_Down return type fun is declared
void Pre_Takeoff();								// Pre_Takeoff is declared
void Raising_Gear();							// Raising Gear type function is declared
void Gear_Up();									// Gear up is declared
void Pre_Landing();								// Pre_Landing return type function is declared
void Lowering_Gear();							// Lowering Gear return type function is declared

typedef enum State								// Enumerated data type State is defined which consists of various integer data type which shows itself a position
{
	GR_DWN,										// GR_DWN is declared
	PRE_TAKEOFF,								// Pre_takeoff is declared
	RAISING_GR,									// RAISING_GR is declared
	GR_UP,										// GR_UP data type is declared
	PRE_LANDING,								// Pre_landing data type is declared
	LOWERING_GR									// Lowering_gear data type is declared
}State_Type;									// here State type enumerated data type is declared
typedef enum Switch								// Again Enumerated data type Switch is defined which has two condition Open and Close
{
	Open,
	Close
}Switch_Status;									// Switch status enumerated data type is declared
typedef enum Pilot_Lever						// Enumerated data type Pilot_lever is defined which has four condition like Raising,Falling,Up,and Down
{
	Raising,
	Falling,
	UP,
	DOWN
}Pilot_Lever_Status;							// Pilot_lever_status data type is created
typedef enum Hydraulic_Mechanism				// Enumerated data type hydraulic machine is created which have two condition working and malfunctioning
{
	Working,
	Malfunctioning
}Hydraulic_Mechanism_Status;					// Hydraulic Mechanism status data type is declared
static volatile Switch_Status squat_switch;		// Static and Volatile both the type of variable is declared here we used static to fetch it from all instances
static volatile Switch_Status limit_switch;		// we made it volatile to use for read and write to various times from main memory
static volatile Pilot_Lever_Status pilot_lever;
static volatile Hydraulic_Mechanism_Status hydraulic_mechanism;
State_Type current_state;
typedef struct									// here we define various data type variable using typedef struct command
{
	char* current_state_indication;				// character type variable current state indication is declared
	char* light_status;
	char* direction_Valve_status;
	char* hydraulic_pump_control_status;
	char* gas_pressurized_spring_status[2];
}State_Table;									// state table is declared

static State_Table State_Machine[6]=			// Here we again assign variables of static type for fetching from all instances for various purpose
{
		{"GearDown","Green","Down","Enabled",0,0},
		{"Pre Takeoff","Green","Down","Enabled",0,0},
		{"Raising_Gear","Red","Up","Enabled",{"Disabled","Enabled"}},
		{"Gear Up","off","Null","Disabled",0,0},
		{"Pre Landing","Red","Down","Enabled",0,0},
		{"Lowering Gear","Green","Down","Enabled",{"Disabled","Enabled"}}
};

#endif     // STATE_H_ is terminated
