#include "gestures.hpp"

gesture::gesture() {}

gesture::gesture(uint8_t id, const char* name, vec3 position)
    : id(id), name(name), position(position) {}

uint8_t gesture::getId() {
    return id;
}

const char* gesture::getName() {
    return name;
}

gesture_manager::gesture_manager() {
}

bool gesture_manager::registerGesture(const char* name, vec3 position) {
    if (gesture_count == MAX_GESTURES)
        return false;

    gesture new_gesture(gesture_count, name, position);
    gestures[gesture_count++] = new_gesture;
    return true;
}

void gesture_manager::printGestures() {
    hwlib::cout << "Registered gestures:\n";
    for (int i = 0; i < gesture_count; i++)
        hwlib::cout << gestures[i];
}

hwlib::ostream& operator<<(hwlib::ostream& os, gesture gesture) {
    os << gesture.getId() << ": " << gesture.getName() << "\n";
    return os;
}
