#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <math.h>

#include "lib/MotorControl.h"

#define PI 3.14159265

int main()
{
	MotorControl motorControl;

	int period = 1; // seconds
	int maxThrust = 50; // percent

	std::cout << "Ramping up motor power to " << maxThrust << "% over a " << ((float)period/2.0) << " second period\n";
	
	int stepCount = 100 * period; // 100 steps per second
	for(int i = 0; i < stepCount; i++){
		usleep(1000*1000*period / stepCount);
		int thrustPercentage = (int) maxThrust * sin(PI*i/(float)stepCount);
		motorControl.setThrustOfAllMotors(thrustPercentage);
	}

}

