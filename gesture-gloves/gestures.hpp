#pragma once

#include <hwlib.hpp>
#include <mpu6050.hpp>

class gesture {
  private:
    uint8_t id;
    const char* name;
    vec3 position;

  public:
    gesture();
    gesture(uint8_t id, const char* name, vec3 position);

    uint8_t getId();
    const char* getName();

    friend hwlib::ostream& operator<<(hwlib::ostream& os, gesture gesture);
};

class gesture_manager {
  private:
    static constexpr const int MAX_GESTURES = 16;
    gesture gestures[MAX_GESTURES];
    uint8_t gesture_count = 0;

  public:
    gesture_manager();

    bool registerGesture(const char* name, vec3 position);
    void printGestures();
};
