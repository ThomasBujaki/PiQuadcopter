/*
* defines functions used in mpu6050I2C.c 
********************************************************************************************************
*/

#ifndef MPU6050I2C_H_
#define MPU6050I2C_H_

int reset_mpu6050();
double get_mpu6050_accel_value (int axis);
short get_mpu6050_gyro_value (int axis);

#endif 
 
