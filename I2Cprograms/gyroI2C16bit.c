#include <wiringPiI2C.h>
#include <stdio.h>

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

int main() {
	int fd, read_val;
	double temp_celcius;
	fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
	wiringPiI2CWriteReg16(fd, 0x6B, 0); // sends reset command to gyro, accel and temp

	printf("fd: %d \n",fd);

//accelerometer
	read_val = wiringPiI2CReadReg16(fd, MPU6050_I2C_ACCEL_XOUT_HIGH);
	printf("ACCEL_XOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_ACCEL_YOUT_HIGH);
	printf("ACCEL_YOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_ACCEL_ZOUT_HIGH);
	printf("ACCEL_ZOUT_HIGH: %d \n",read_val);

//gyroscope	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_XOUT_HIGH);
	printf("GYRO_XOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_YOUT_HIGH);
	printf("GYRO_YOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg16(fd,MPU6050_I2C_GYRO_ZOUT_HIGH);
	printf("GYRO_ZOUT_HIGH: %d \n",read_val);

	return 0;
}
