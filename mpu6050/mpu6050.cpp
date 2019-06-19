#include "mpu6050.hpp"

mpu6050::mpu6050(hwlib::i2c_bus& i2c, const uint8_t address)
    : bus(i2c), address(address) {
    reset();
}

void mpu6050::reset() {
    auto tx = bus.write(address);
    tx.write(PWR_MGMT_1); // Command
    tx.write(0); // Parameter
}

int16_t mpu6050::getAccelerationX() {
    auto tx = bus.write(address);
    tx.write(ACCEL_XOUT_H);
    tx.~i2c_write_transaction();

    auto rx = bus.read(address);
    return rx.read_byte() << 8 | rx.read_byte();
}
