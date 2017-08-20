#include <wiringPiI2C.h>
#include <stdio.h>

#define PCA9685_I2C_ADDRESS 0x40
#define LED_ON_LOW 0x06
#define LED_ON_HIGH 0x07
#define LED_OFF_LOW 0x08
#define LED_OFF_HIGH 0x09

int main(){
	int fd, channel, on_value, off_value; // channel is 
	fd = wiringPiI2CSetup(PCA9685_I2C_ADDRESS);
	channel = 0;	
	on_value = 0 ;
	off_value = 0; 
	printf("%d \n",fd);
	//pwm on function
	wiringPiI2CWriteReg8(fd, 0x00 , 0x00 );
	wiringPiI2CWriteReg8(fd, LED_ON_LOW+4*channel, on_value & 0xff) ; // only takes the bottom 8 bits from the on_value
        wiringPiI2CWriteReg8(fd, LED_ON_HIGH+4*channel, on_value >> 8) ;// shifts top 8 bits to bottom so full coverage of the 16 bit signal is given (even though the actual values are max 12 bits long I2C uses 16 bit signals
        wiringPiI2CWriteReg8(fd, LED_OFF_LOW+4*channel, off_value & 0xff) ;
        wiringPiI2CWriteReg8(fd, LED_OFF_HIGH+4*channel, off_value >> 8) ;






	return 0;
}
