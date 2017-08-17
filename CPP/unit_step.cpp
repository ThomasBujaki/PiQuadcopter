#include <iostream>
#include <unistd.h>

#include "lib/MotorControl.h"

int main()
{
	MotorControl motorControl;

	int period = 1; // seconds
	int maxThrust = 50; // percent


	std::cout << "Turning on all motors to " << maxThrust << "% for " << period << " seconds\n";
	
	motorControl.setThrustOfAllMotors(maxThrust);

	usleep(1000*1000*period);
	
	std::cout << "Turning off motors\n";

	motorControl.setThrustOfAllMotors(0);
}

