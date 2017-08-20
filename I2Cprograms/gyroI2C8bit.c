#include <wiringPiI2C.h>
#include <stdio.h>

// general
#define MPU6050_I2C_ADDRESS 0x68
#define MPU6050_I2C_CONFIG 0x1A

// accelerometer
#define MPU6050_I2C_ACCEL_CONFIG 0x1C 
#define MPU6050_I2C_ACCEL_XOUT_HIGH 0x3B
#define MPU6050_I2C_ACCEL_XOUT_LOW 0x3C
#define MPU6050_I2C_ACCEL_YOUT_HIGH 0x3D
#define MPU6050_I2C_ACCEL_YOUT_LOW 0x3E
#define MPU6050_I2C_ACCEL_ZOUT_HIGH 0x3F
#define MPU6050_I2C_ACCEL_ZOUT_LOW 0x40

// gyroscope
#define MPU6050_I2C_GYRO_CONFIG 0x1B
#define MPU6050_I2C_GYRO_XOUT_HIGH 0x43
#define MPU6050_I2C_GYRO_XOUT_LOW 0x44
#define MPU6050_I2C_GYRO_YOUT_HIGH 0x45
#define MPU6050_I2C_GYRO_YOUT_LOW 0x46
#define MPU6050_I2C_GYRO_ZOUT_HIGH 0x47
#define MPU6050_I2C_GYRO_ZOUT_LOW 0x48

int main() {
	int fd, read_val_high, read_val_low, combined;
	double temp_celcius;
	fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
	wiringPiI2CWriteReg8(fd, 0x6B, 0); // sends reset command to gyro, accel and temp

	printf("fd: %d \n",fd);

//accelerometer
	read_val_high = wiringPiI2CReadReg8(fd, MPU6050_I2C_ACCEL_XOUT_HIGH);
	read_val_low = wiringPiI2CReadReg8(fd, MPU6050_I2C_ACCEL_XOUT_LOW);
	combined = (read_val_low << 8) | (read_val_high);
	printf("ACCEL_XOUT: %d \n",combined);
	
	read_val = wiringPiI2CReadReg8(fd,MPU6050_I2C_ACCEL_YOUT_HIGH);
	printf("ACCEL_YOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg8(fd,MPU6050_I2C_ACCEL_ZOUT_HIGH);
	printf("ACCEL_ZOUT_HIGH: %d \n",read_val);

//gyroscope	
	read_val = wiringPiI2CReadReg8(fd,MPU6050_I2C_GYRO_XOUT_HIGH);
	printf("GYRO_XOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg8(fd,MPU6050_I2C_GYRO_YOUT_HIGH);
	printf("GYRO_YOUT_HIGH: %d \n",read_val);
	
	read_val = wiringPiI2CReadReg8(fd,MPU6050_I2C_GYRO_ZOUT_HIGH);
	printf("GYRO_ZOUT_HIGH: %d \n",read_val);

	return 0;
}
