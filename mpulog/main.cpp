#include <hwlib.hpp>
#include <mpu6050.hpp>

mpu6050 mpu;

int main() {
    hwlib::cout << "Starting mpulog\n";

    mpu.initialize();

    hwlib::cout << "Started mpulog\n";

    for (;;) {
    }

    return 0;
}
