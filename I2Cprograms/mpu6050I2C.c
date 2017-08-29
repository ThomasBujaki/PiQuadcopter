/*
* August 29th 2017
* By:
*
* Reads acceleration and orientation values from the MPU-6050 chip using I2C as the communication protocol
*	MPU-6050 has both accelerometer and a gyroscope, accelerometer is set to +- 2g
********************************************************************************************************
*/

#include <wiringPiI2C.h>
#include <stdio.h>
#include <math.h>

// general
#define MPU6050_I2C_ADDRESS 0x68
#define MPU6050_I2C_CONFIG 0x1A

// accelerometer
#define MPU6050_I2C_ACCEL_CONFIG 0x1C 
#define MPU6050_I2C_ACCEL_XOUT_HIGH 0x3B
#define MPU6050_I2C_ACCEL_YOUT_HIGH 0x3D
#define MPU6050_I2C_ACCEL_ZOUT_HIGH 0x3F

// gyroscope
#define MPU6050_I2C_GYRO_CONFIG 0x1B
#define MPU6050_I2C_GYRO_XOUT_HIGH 0x43
#define MPU6050_I2C_GYRO_YOUT_HIGH 0x45
#define MPU6050_I2C_GYRO_ZOUT_HIGH 0x47

static double calibrate_offset[] = {-0.32288818359375, 0.153814697265, -2.053405761718};
static double calibrate_scale[] = {1.0, 0.99, 0.97503181};

static double fullScaleAccelerometerRange = 2.0;
static double localAccelerationDueToGravity = 9.81;

/*
* Function: convertToLittleEndian
*-----------------------------------
* converts the raw output from the mpu-6050 into little endian format 
*
* 	bigEndianValue: raw values given by the mpu-6050
*
*	returns: the little endian format of the input
********************************************************************************************************
*/
unsigned short convertToLittleEndian(unsigned short bigEndianValue){
	unsigned short littleEndianValue = (bigEndianValue>>8)|(bigEndianValue <<8);
	return littleEndianValue;
} 

/*
*Function: convertRegisterValueToAcceleration
*-----------------------------------
* converts the accelerometer raw values into acceleration in meters per second
*
* 	registerValue: the raw output from the accelerometer after it has been converted to little endian format 
* 	axis: the x, y, and z axes, 0=x, 1=y, and 2=z
*
* 	returns: the acceleration for that spceific axis in meters per second
********************************************************************************************************
*/
double convertRegisterValueToAcceleration(short int registerValue, unsigned int axis) {
	unsigned short registerValueInLittleEndian = convertToLittleEndian(registerValue);
	double normalizedAcceleration = (short int)registerValueInLittleEndian / 32768.0;
	double accelerationInGs = normalizedAcceleration * fullScaleAccelerometerRange;
	double accelerationInMetersPerSecond = accelerationInGs * localAccelerationDueToGravity;
	double calibratedValue = (accelerationInMetersPerSecond + calibrate_offset[axis]) * calibrate_scale[axis];
	return calibratedValue;
}

/*
*/
int reset_mpu6050(){
	int fd;
        fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
        wiringPiI2CWriteReg16(fd, 0x6B, 0); // sends reset command to gyro, accel and temp
	return 0;
}

/*
*Function: get_mpu6050_accel_value
*-----------------------------------
* gets the acceleration value for a spceific axis of the mpu-6050
*
*	axis: the axis from which the acceleration is read (0=x, 1=y, 2=z)
*
*	retruns: the acceleration in meters per second for the specific axis
********************************************************************************************************
*/
double get_mpu6050_accel_value(int axis){
	int fd;
	unsigned short read_val;
	double accel_in_mps ;

        fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);

	if ( axis == 0 ) { 
	        read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_ACCEL_XOUT_HIGH);
        }
	else if ( axis == 1 ) {
	        read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_ACCEL_YOUT_HIGH);
	}
	else if ( axis == 2 ) {
	        read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_ACCEL_ZOUT_HIGH);
	}

	accel_in_mps = convertRegisterValueToAcceleration(read_val, axis);

	return accel_in_mps;
}

/*
*Function: get_mpu6050_gyro_value
*-----------------------------------
* gets the gyroscope value for a specific axis of the mpu-6050
*
*	axis: the axis from which the acceleration is read (0=x, 1=y, 2=z)
*
*	returns: the signed short int of the gyro value
********************************************************************************************************
*/
short get_mpu6050_gyro_value(int axis){
	int fd;
	unsigned short read_val, unsigned_gyro_value;
	short signed_gyro_value ;

        fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
	
	if ( axis == 0 ) { 
	        read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_GYRO_XOUT_HIGH);
        }
	else if ( axis == 1 ) {
	        read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_GYRO_YOUT_HIGH);
	}
	else if ( axis == 2 ) {
	        read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_GYRO_ZOUT_HIGH);
	}
        
	unsigned_gyro_vlaue = convertToLittleEndian(read_val);
	signed_gyro_value = (short)unsigned_gyro_value;
	
	return signed_gyro_value;
}

/*
int get_mpu6050_accel() {
	int fd;
	unsigned short read_val;
	double ax, ay, az, root ;
	fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
	wiringPiI2CWriteReg16(fd, 0x6B, 0); // sends reset command to gyro, accel and temp

	printf("fd: %d \n",fd);

//accelerometer
while(1){
	read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_ACCEL_XOUT_HIGH);
	ax = convertRegisterValueToAcceleration(read_val, 0);	
	printf("ax %f \t",ax);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_ACCEL_YOUT_HIGH);
	ay = convertRegisterValueToAcceleration(read_val, 1);
	printf("ay %f \t",ay);

	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_ACCEL_ZOUT_HIGH);
	az = convertRegisterValueToAcceleration(read_val, 2);	

	printf("az %f \t",az);
	root=sqrt(ax*ax+ay*ay+az*az);
	printf(" magnitude %f \n", root);

	
//	printf(" %f \t",minX);
//	printf(" %f \t",minY);
//	printf(" %f \t",minZ);
//	printf(" %f \t",maxX);
//	printf(" %f \t",maxY);
//	printf(" %f \n",maxZ);

}
//gyroscope	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_XOUT_HIGH);
	read_val = (read_val>>8)|(read_val<<8);
	//printf(" %d \t",(short int)read_val);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_YOUT_HIGH);
	read_val = (read_val>>8)|(read_val<<8);
	//printf(" %d \t",(short int)read_val);

	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_ZOUT_HIGH);
	read_val = (read_val>>8)|(read_val<<8);
	//printf(" %d \n",(short int)read_val);
	return 0;

}
*/
