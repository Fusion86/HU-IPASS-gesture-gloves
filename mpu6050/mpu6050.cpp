#include "mpu6050.hpp"

#include <hwlib-extra.hpp>

vec3::vec3()
    : x(0), y(0), z(0) {}

vec3::vec3(float x, float y, float z)
    : x(x), y(y), z(z) {}

hwlib::ostream& operator<<(hwlib::ostream& os, const vec3& accel) {
    os << "x: " << accel.x << "  y: " << accel.y << "  z: " << accel.z;

    return os;
}

mpu6050::mpu6050(hwlib::i2c_bus& i2c, const uint8_t address)
    : bus(i2c), address(address) {
    reset();
}

void mpu6050::reset() {
    regWriteByte(PWR_MGMT_1, 0);
}

float mpu6050::getAccelerationX() {
    return regReadInt16(ACCEL_XOUT_H) / 16384.f;
}

float mpu6050::getAccelerationY() {
    return regReadInt16(ACCEL_YOUT_H) / 16384.f;
}

float mpu6050::getAccelerationZ() {
    return regReadInt16(ACCEL_ZOUT_H) / 16384.f;
}

vec3 mpu6050::getAcceleration() {
    return vec3(getAccelerationX(), getAccelerationY(), getAccelerationZ());
}

float mpu6050::getGyroX() {
    return regReadInt16(GYRO_XOUT_H) / 131.f;
}

float mpu6050::getGyroY() {
    return regReadInt16(GYRO_YOUT_H) / 131.f;
}

float mpu6050::getGyroZ() {
    return regReadInt16(GYRO_ZOUT_H) / 131.f;
}

vec3 mpu6050::getGyro() {
    return vec3(getGyroX(), getGyroY(), getGyroZ());
}

int16_t mpu6050::regReadInt16(uint8_t reg) {
    auto tx = bus.write(address);
    tx.write(reg);
    tx.~i2c_write_transaction();

    auto rx = bus.read(address);
    return rx.read_byte() << 8 | rx.read_byte();
}

void mpu6050::regWriteByte(uint8_t reg, uint8_t byte) {
    auto tx = bus.write(address);
    tx.write(reg);
    tx.write(byte);
}
