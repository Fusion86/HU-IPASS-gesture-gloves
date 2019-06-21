/// @file

#pragma once

#include <hwlib.hpp>

// https://store.invensense.com/datasheets/invensense/MPU-6050_DataSheet_V3%204.pdf
// https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf

// i2c address for MPU6050 when AD0 is set low
#define MPU_ADDR_AD0_LOW 0x68
// i2c address for MPU6050 when AD0 is set high
#define MPU_ADDR_AD0_HIGH 0x69

#define ACCEL_XOUT_H 0x3B

#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define PWR_MGMT_1 0x6B

class acceleration {
  public:
    float x;
    float y;
    float z;

    acceleration(float x, float y, float z);

    friend hwlib::ostream& operator<<(hwlib::ostream& os, const acceleration& accel);
};

class mpu6050 {
  private:
    hwlib::i2c_bus& bus;

    /// The 7-bit i2c address of the controller
    const uint8_t address;

  public:
    mpu6050(hwlib::i2c_bus& i2c, const uint8_t address);

    /// Reset MPU6050 to initial settings.
    void reset();

    /// Get acceleration on the X-axis in g/s.
    float getAccelerationX();

    /// Get acceleration on the Y-axis in g/s.
    float getAccelerationY();

    /// Get acceleration on the Z-axis in g/s.
    float getAccelerationZ();

    /// Get acceleration for all three axis in g/s.
    acceleration getAcceleration();

    float getRotationX();
    float getRotationY();
    float getRotationZ();

  private:
    /// Read int16_t value from register.
    ///
    /// Because an int16_t value is split over two 8bit registers this will read from register and register+1.
    int16_t regReadInt16(uint8_t reg);

    /// Write uint8_t to register.
    void regWriteByte(uint8_t reg, uint8_t byte);
};
