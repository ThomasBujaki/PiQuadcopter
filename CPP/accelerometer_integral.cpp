#include <iostream>
#include <unistd.h>
#include <cstdlib>

#include "lib/MotorControl.h"


int main()
{
	MotorControl motorControl;


	float destinationHeight = 1.0f; // Height in meters
	
	float hoverTime = 1.0f; // Time to hover when you hit the destination height	
	
	float maxAscentVelocity = 0.5f; // Maximum velocity in m/s at which we can safely ascend
	float maxDescentVelocity = 0.5f; // Maximum velocity in m/s at which we can safely descend
	
	float gravity = -1.0f; // The acceleration due to gravity will be determined at startup.

	float currentHeight = 0.0f;


	/*
		Determine gravity
	*/
	
	// We are at rest right now.
	// Read a bunch of samples from the accelerometer and average them.
	// This will give us a good idea of the acceleration due to gravity at this location
	
	/*
		Ascend
	*/

	// Keep the ascent velocity close to maxAscentVelocity
	

	/*
		Hover
	*/
		

	/*
		Descend
	*/	
		
}

