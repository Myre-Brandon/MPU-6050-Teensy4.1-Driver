#include "mpu6050.h"

uint16_t const acc_lsb_sensitivities[4] = ACC_LSB_SENSITIVITIES;
uint16_t lsb_filter;

uint8_t initialize_imu() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(PWR_MANAGEMENT_1);
  Wire.write(0);
  byte err = Wire.endTransmission(true);

  lsb_filter = acc_lsb_sensitivities[0];

  return err;
}

float get_acceleration(uint8_t address) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(address);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 2);
  if(Wire.available() == 2) {
    int16_t acc_x = Wire.read() << 8 | Wire.read();
    float acc_x_g = (float)acc_x/lsb_filter;
    return acc_x_g;
  } else {
    return 0;
  }
}

float get_x_acceleration() {
  return get_acceleration(ACC_X_REG);
}

float get_y_acceleration() {
  return get_acceleration(ACC_Y_REG);
}

float get_z_acceleration() {
  return get_acceleration(ACC_Z_REG);
}