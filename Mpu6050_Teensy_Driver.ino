#include "mpu6050.h"

#define MPU_ADDR 0x68
#define LSB_SENSITIVITY 16384

void setup() {
  Wire.begin();
  Serial.begin(115200);

  byte err = initialize_imu();
  if(err != 0) {
    Serial.println("An error occured while initializing the imu");
  }
}

void loop() {
  float acc_x_g = get_x_acceleration();
  Serial.printf("Acc. x: %.2f\n", acc_x_g);

  float acc_y_g = get_y_acceleration();
  Serial.printf("Acc. y: %.2f\n", acc_y_g);

  float acc_z_g = get_z_acceleration();
  Serial.printf("Acc. z: %.2f\n\n", acc_z_g);
  
  delay(100);
}
