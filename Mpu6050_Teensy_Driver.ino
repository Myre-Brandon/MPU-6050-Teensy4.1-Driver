#include <Wire.h>

#define MPU_ADDR 0x68

void setup() {
  Wire.begin();
  Serial.begin(115200);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 2);
  int16_t acc_x = Wire.read() << 8 | Wire.read();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3D);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 2);
  int16_t acc_y = Wire.read() << 8 | Wire.read();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3F);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 2);
  int16_t acc_z = Wire.read() << 8 | Wire.read();
}
