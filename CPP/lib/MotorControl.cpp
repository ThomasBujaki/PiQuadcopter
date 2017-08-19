// Motor control abstraction layer

#include "MotorControl.h"
#include <iostream>
#include <cstdlib>

#include <signal.h>
#include <stdio.h>


/******
	BEGIN SAFETY HACK
******/

static MotorControl * hackyPointer = NULL;

void exiting() {
	hackyPointer->setThrustOfAllMotors(0); 	   
}

void sigint(int a)
{
	hackyPointer->setThrustOfAllMotors(0);		
	exit(0);
}

void sigterm(int a){
	hackyPointer->setThrustOfAllMotors(0);	
	exit(0);
}

MotorControl::MotorControl(){
	std::atexit(exiting);
	signal(SIGINT, sigint);
	signal(SIGTERM, sigterm);
	hackyPointer = this;
}


/*******
	END SAFETY HACK
*******/

void MotorControl::setMotorThrust(int motorIndex, int percentage){
	
}

void MotorControl::setThrustOfAllMotors(int percentage){
	std::cout << "Setting all motor thrust: " << percentage << "%\n";
	for(int i = 0; i < 4; i++) {
		this->setMotorThrust(i, percentage);	
	}
}
