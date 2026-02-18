#include <Wire.h>

#define MPU_ADDR 0x68
#define LSB_SENSITIVITY 16384

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
  float acc_x_g = (float)acc_x/LSB_SENSITIVITY;
  Serial.printf("Acc. x: %.2f\n", acc_x_g);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3D);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 2);
  int16_t acc_y = Wire.read() << 8 | Wire.read();
  float acc_y_g = (float)acc_y/LSB_SENSITIVITY;
  Serial.printf("Acc. y: %.2f\n", acc_y_g);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3F);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 2);
  int16_t acc_z = Wire.read() << 8 | Wire.read();
  float acc_z_g = (float)acc_z/LSB_SENSITIVITY;
  Serial.printf("Acc. z: %.2f\n\n", acc_z_g);
  
  delay(500);
}
