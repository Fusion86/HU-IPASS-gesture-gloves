#include <hwlib.hpp>
#include <hwlib-extra.hpp>

int main() {
    // Wait for the PC terminal to start
    hwlib::wait_ms(500);

    float f1 = 1.2345;
    float f2 = 12.345;
    float f3 = 123.45;
    float f4 = 1234.5;

    hwlib::cout << "f1: " << f1 << "\n";
    hwlib::cout << "f2: " << f2 << "\n";
    hwlib::cout << "f3: " << f3 << "\n";
    hwlib::cout << "f4: " << f4 << "\n";

    return 0;
}
