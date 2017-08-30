/*
* tests to see if the implemetations of the I2C programs function properly
********************************************************************************************************
*/

#include <stdio.h>
#include "mpu6050I2C.h"
#include "pca9685I2C.h"

int main(){
	//write to pca
	reset_pca9685();
	set_pwm_signal( 0, 0);
	//call gyro stuff
	reset_mpu6050();
	int i;
	for (i=0; i<3; i++){
		printf("loop iteration: %d \t accelerometer value: %f \n", i, get_mpu6050_accel_value(i));
                printf("loop iteration: %d \t gyro value: %d \n", i, get_mpu6050_gyro_value(i));
	}
	return 0;
}
