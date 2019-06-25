#include <hwlib.hpp>

#include "gestures.hpp"

int main() {
    // Wait for the PC terminal to start
    hwlib::wait_ms(500);

    gesture_manager mgr;
    auto vec = vec3(0,0,0);
    mgr.registerGesture("hand recht omhoog", vec);
    mgr.registerGesture("hand recht omlaag", vec);
    mgr.registerGesture("hand vlak boven", vec);
    mgr.registerGesture("hand vlak onder", vec);
    mgr.printGestures();

    return 0;
}
