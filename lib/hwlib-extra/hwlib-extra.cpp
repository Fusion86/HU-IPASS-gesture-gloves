#include "hwlib-extra.hpp"

hwlib::ostream& operator<<(hwlib::ostream& os, float f) {
    // HACK: This is not a 'legit' float printing implementation, but it works well enough for me
    const int PRECISION = 1'000;
    char prefix = '\0';

    if (f < 0) {
        f *= -1;
        prefix = '-';
    }

    // Lets assume that `f = 2.3456` for all example comments
    int i = (int)f; // 'Full' number, eg. 2

    float tmp = (f - i); // Float minus whole number, eg. 0.3456
    int dec = (int)(tmp * PRECISION); // Decimals, eg. 345
    os << prefix << i << "." << dec; // Prints 2.345 (with precision 1000)
    return os;
}
