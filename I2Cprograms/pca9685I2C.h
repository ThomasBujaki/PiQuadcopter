/*
* defines functions used in pca9685I2C.c
********************************************************************************************************
*/

#ifndef PAC9685I2C_H_
#define PAC9685I2C_H_

int reset_pca9685();
int set_pwm_signal (int channel, int off_value);

#endif 
 
