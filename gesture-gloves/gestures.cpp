#include "gestures.hpp"

bool gesture_manager::registerGesture(const char* name) {
    if (gesture_count == MAX_GESTURES)
        return false;

    gesture new_gesture;
    new_gesture.id = gesture_count;
    new_gesture.name = name;
    gestures[gesture_count++] = new_gesture;
    return true;
}

void gesture_manager::printGestures() {
    hwlib::cout << "Registered gestures:\n";
    for (int i = 0; i < gesture_count; i++)
        hwlib::cout << gestures[i];
}

hwlib::ostream& operator<<(hwlib::ostream& os, gesture gesture) {
    os << gesture.id << ": " << gesture.name << "\n";
    return os;
}
