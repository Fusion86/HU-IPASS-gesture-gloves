#include <hwlib.hpp>
#include <mpu6050.hpp>

int main() {
    // Wait for the PC terminal to start
    hwlib::wait_ms(500);

    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    auto i2c = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    mpu6050 mpu(i2c, MPU_ADDR_AD0_LOW);

    for (;;) {
        auto accel_x = mpu.getAccelerationX();
        hwlib::cout << "accel_x: " << accel_x << "\n";
        hwlib::wait_ms(1000);
    }

    return 0;
}
