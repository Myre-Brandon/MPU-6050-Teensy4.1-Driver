#ifndef MPU6050_H_
#define MPU6050_H_

#include <Wire.h>

#define MPU_ADDR 0x68
#define ACC_X_REG 0x3B
#define ACC_Y_REG 0x3D
#define ACC_Z_REG 0x3F
#define PWR_MANAGEMENT_1 0x6B
#define ACC_LSB_SENSITIVITIES {16384, 8192, 4096, 2048}

uint8_t initialize_imu();

float get_acceleration(uint8_t address);

float get_x_acceleration();

float get_y_acceleration();

float get_z_acceleration();

#endif