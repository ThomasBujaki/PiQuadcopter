/*
* tests to see if the implemetations of the I2C programs function properly
********************************************************************************************************
*/

#include <stdio.h>
#include "mpu6050I2C.h"
#include "pca9685I2C.h"

int main(){
	char c ; 
	
	//write to pca
	reset_pca9685();
	while (c != 'q'){
		c = getchar();
		printf("%c", c);
		if (c == 'w') { // max power
			printf("\n maximum \n");
			set_pwm_signal( 0, 0, 6);
			set_pwm_signal( 1, 410, 416);
			set_pwm_signal( 2, 820, 826);
			set_pwm_signal( 3, 1230, 1236);
			set_pwm_signal( 4, 1640, 1646);
		}
		else if (c == 's'){ // zero power
			printf("\n zero \n ");
//			set_pwm_signal( 0, 4093, 3);
//			set_pwm_signal( 1, 202, 208);
			set_pwm_signal( 0, 0, 6);
			set_pwm_signal( 1, 205, 211);
			set_pwm_signal( 2, 410, 416);
			set_pwm_signal( 3, 615, 621);
			set_pwm_signal( 4, 820, 826);
		}
		else if (c == 'd'){ // just above 0 power
			printf("\n ~20 percent");
			set_pwm_signal( 0, 4093, 3);
//			set_pwm_signal( 1, 250, 256);
		}
		else if (c == 'x'){ // just above 0 power
//			set_pwm_signal( 0, 506, 512);
//			set_pwm_signal( 1, 0, 0);
			set_pwm_signal( 0, 0, 6);
			set_pwm_signal( 1, 205, 211);
			set_pwm_signal( 2, 410, 416);
			set_pwm_signal( 3, 615, 621);
			set_pwm_signal( 4, 820, 826);
		}
	}
	return 0;
}
