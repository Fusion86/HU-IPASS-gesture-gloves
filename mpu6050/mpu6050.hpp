#pragma once

#include <hwlib.hpp>

class mpu6050 {
  public:
    void initialize();

    int16_t getAccelerationX();
    int16_t getAccelerationY();
    int16_t getAccelerationZ();

    int16_t getRotationX();
    int16_t getRotationY();
    int16_t getRotationZ();
};
