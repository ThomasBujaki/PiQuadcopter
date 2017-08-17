#include <iostream>
#include <unistd.h>
#include <cstdlib>

#include "lib/MotorControl.h"


int main()
{
	MotorControl motorControl;

	int period = 1; // seconds
	int maxThrust = 50; // percent

	/*			___ maxThrust
		    /\           | 
		   /  \          |
       		  /    \         |  
		 /      \        |
		/________\      _|_ 0% Thrust
	       |--period--|	
	
	     <---- time ---->

	*/


	std::cout << "Ramping up motor power to " << maxThrust << "% over a " << ((float)period/2.0) << " second period\n";
	
	for(int thrustPercentage = 0; thrustPercentage <= maxThrust; thrustPercentage++){
		usleep(1000*5*period);
		motorControl.setThrustOfAllMotors(thrustPercentage);
	}

	std::cout << "Ramping down motor power to 0% over a " << ((float)period/2.0) << " second period\n";

	for(int thrustPercentage = maxThrust; thrustPercentage >= 0; thrustPercentage--){
                usleep(1000*5*period);
                motorControl.setThrustOfAllMotors(thrustPercentage);
	}		
		
}

