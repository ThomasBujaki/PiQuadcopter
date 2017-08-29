/*
* August 29th 2017
* By: Thomas Bujaki
*
* Writes instructions to PCA9685 chip using wiringPi
*       signal required for electronic speed controllers is a minimum of 1ms and maximum of 2ms duty cycle
*       1ms dutycycle is represented by ~205 difference between on and off (a 100% duty cycle is about 20ms and required a difference of 4096 between on and off values written to the register) a 2ms duty cycle is obtained by writing 410 difference
********************************************************************************************************
*/

#include <wiringPiI2C.h>
#include <stdio.h>

#define PCA9685_I2C_ADDRESS 0x40
#define LED_ON_LOW 0x06
#define LED_ON_HIGH 0x07
#define LED_OFF_LOW 0x08
#define LED_OFF_HIGH 0x09

/*
*Function: reset_pca9685
*------------------------------------
* sends reset signal to pca9685, this is required or else the chip will not listen to other commands until it is given this signal
*
*******************************************************************************************************
*/
int reset_pca9685(){
        int fd;

        fd = wiringPiI2CSetup(PCA9685_I2C_ADDRESS);

        wiringPiI2CWriteReg8(fd, 0x00 , 0x00 );

        return 0;
}

/*
*Function: set_pwm_signal
*-----------------------------------
* writes PWM signal to specific channel of PCA9685
* 
* 	channel: the channel the pwm signal is to come from, pca9685 has 16 channels, only channels 0, 1, 2, and 3 are available for our hardware
* 	off_value: off signal, must be between 205 and 410. 205 for no power going to motors, 410 for maximum power going to motors
*
*******************************************************************************************************
*/
int set_pwm_signal(int channel, int off_value){
        int fd;

        fd = wiringPiI2CSetup(PCA9685_I2C_ADDRESS);

        wiringPiI2CWriteReg8(fd, LED_ON_LOW+4*channel, 0x00) ;
        wiringPiI2CWriteReg8(fd, LED_ON_HIGH+4*channel, 0x00) ;
        wiringPiI2CWriteReg8(fd, LED_OFF_LOW+4*channel, off_value & 0xff) ; // only takes the bottom 8 bits from the on_value
        wiringPiI2CWriteReg8(fd, LED_OFF_HIGH+4*channel, off_value >> 8) ; // shifts top 8 bits to bottom so full coverage of the 16 bit signal is given (even though the actual values are max 12 bits long I2C uses 16 bit signals

        return 0;
}

