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

static short calibrate_x=-1500, calibrate_y=250, calibrate_z=-4000 ;
static double fullScaleAccelerometerRange = 2.0;
static double localAccelerationDueToGravity = 9.81;

unsigned short convertToLittleEndian(unsigned short bigEndianValue){
	unsigned short littleEndianValue = (bigEndianValue>>8)|(bigEndianValue <<8);
	return littleEndianValue;
} 

double convertRegisterValueToAcceleration(short int registerValueInLittleEndian) {
//	unsigned short registerValueInLittleEndian = convertToLittleEndian(registerValue);
	double normalizedAcceleration = (short int)registerValueInLittleEndian / 32768.0;
	double accelerationInGs = normalizedAcceleration * fullScaleAccelerometerRange;
	double accelerationInMetersPerSecond = accelerationInGs * localAccelerationDueToGravity;
	return accelerationInMetersPerSecond;
}

//double getAccelInMperS (unsigned short int accel_raw){
//	double accel_mpers;
//	accel_mpers = ((accel_raw/32768.0)*2.0)*9.81 ;
//	return accel_mpers;
//}

//int convertEndianness (){
	 
//	read_val = (read_val>>8)|(read_val<<8);
//	return 
//}


int main() {
	int fd;
	unsigned short int read_val;
	double ax, ay, az, root ;
	float minX=0, minY=0, minZ=0; 
	float maxX=0, maxY=0, maxZ=0; 
	short signed_read_val	;
	fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
	wiringPiI2CWriteReg16(fd, 0x6B, 0); // sends reset command to gyro, accel and temp

	printf("fd: %d \n",fd);

//accelerometer
while(1){
	read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_ACCEL_XOUT_HIGH);
	signed_read_val = (short)convertToLittleEndian(read_val)+calibrate_x;
	printf("%d \t",signed_read_val);
	ax = convertRegisterValueToAcceleration(signed_read_val);	
	minX= fmin(ax, minX);
	maxX= fmax(ax, maxX);

	printf(" %f \t",ax);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_ACCEL_YOUT_HIGH);
	signed_read_val = (short)convertToLittleEndian(read_val)+calibrate_y;
	printf("%d \t",signed_read_val);
	ay = convertRegisterValueToAcceleration(signed_read_val);
	minY= fmin(ay, minY);
	maxY= fmax(ay, maxY);
	printf(" %f \t",ay);

	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_ACCEL_ZOUT_HIGH);
	signed_read_val = (short)convertToLittleEndian(read_val)+calibrate_z;
	printf("%d \t",signed_read_val);
	az = convertRegisterValueToAcceleration(signed_read_val);	
	minZ= fmin(az, minZ);
	maxZ= fmax(az, maxZ);

	printf(" %f \t",az);
	root=sqrt(ax*ax+ay*ay+az*az);
	printf(" %f \n", root);

	
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
	printf(" %d \t",(short int)read_val);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_YOUT_HIGH);
	read_val = (read_val>>8)|(read_val<<8);
	printf(" %d \t",(short int)read_val);

	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_ZOUT_HIGH);
	read_val = (read_val>>8)|(read_val<<8);
	printf(" %d \n",(short int)read_val);
	return 0;

}
