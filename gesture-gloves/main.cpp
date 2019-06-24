#include <hwlib.hpp>

#include "gestures.hpp"

int main() {
    // Wait for the PC terminal to start
    hwlib::wait_ms(500);

    gesture_manager mgr;
    mgr.registerGesture("hand recht omhoog");
    mgr.registerGesture("hand recht omlaag");
    mgr.registerGesture("hand vlak boven");
    mgr.registerGesture("hand vlak onder");
    mgr.printGestures();

    return 0;
}
