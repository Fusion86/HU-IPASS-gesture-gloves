#pragma once

#include <hwlib.hpp>

// https://store.invensense.com/datasheets/invensense/MPU-6050_DataSheet_V3%204.pdf
// https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf

// i2c address for MPU6050 when AD0 is set low
#define MPU_ADDR_AD0_LOW 0x68
// i2c address for MPU6050 when AD0 is set high
#define MPU_ADDR_AD0_HIGH 0x69

#define ACCEL_XOUT_H 0x3B
// #define ACCEL_XOUT_L 0x60 etc
#define ACCEL_ZOUT_L 0x40
#define PWR_MGMT_1 0x6B

class mpu6050 {
  private:
    hwlib::i2c_bus& bus;

    // The 7-bit i2c address of the controller
    const uint8_t address;

  public:
    mpu6050(hwlib::i2c_bus& i2c, const uint8_t address);

    void reset();

    int16_t getAccelerationX();
    int16_t getAccelerationY();
    int16_t getAccelerationZ();

    int16_t getRotationX();
    int16_t getRotationY();
    int16_t getRotationZ();
};
