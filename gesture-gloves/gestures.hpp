#pragma once

#include <hwlib.hpp>

class gesture {
    friend class gesture_manager;

  private:
    uint8_t id;
    const char* name;

  public:
    uint8_t getId();
    const char* getName();

    friend hwlib::ostream& operator<<(hwlib::ostream& os, gesture gesture);
};

class gesture_manager {
  private:
    static constexpr const int MAX_GESTURES = 16;
    gesture gestures[MAX_GESTURES];
    int gesture_count = 0;

  public:
    bool registerGesture(const char* name);

    void printGestures();
};
