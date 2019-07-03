#include <hwlib.hpp>
#include <mpu6050.hpp>

class hand_position {
  private:
    vec3 accel;

  public:
    hand_position(vec3 accel)
        : accel(accel) {}

    hand_position(mpu6050& mpu)
        : accel(mpu.getAcceleration()) {}

    // Could probably calculate all these booleans once in the constructor instead of on each call
    bool x_up() { return accel.x > 0.8; }
    bool x_down() { return accel.x < -0.8; }
    bool y_up() { return accel.y > 0.7; }
    bool y_down() { return accel.y < -0.7; }
    bool z_up() { return accel.z > 0.9; }
    bool z_down() { return accel.z < -0.7; }

    // Could've been defined outside of this class (where it wouldn't need the friend statement)
    // but I like to keep things like this inside the class
    friend hwlib::ostream& operator<<(hwlib::ostream& os, hand_position& pos) {
        if (pos.x_up()) os << "x_up, ";
        if (pos.x_down()) os << "x_down, ";
        if (pos.y_up()) os << "y_up, ";
        if (pos.y_down()) os << "y_down, ";
        if (pos.z_up()) os << "z_up, ";
        if (pos.z_down()) os << "z_down, ";
        return os;
    }
};

int main() {
    // Wait for the PC terminal to start
    hwlib::wait_ms(500);

    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    auto i2c = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    mpu6050 mpu(i2c, MPU_ADDR_AD0_LOW);

    uint64_t start;
    for (;;) {
        start = hwlib::now_us();

        auto accel = mpu.getAcceleration();
        auto gyro = mpu.getGyro();
        auto pos = hand_position(accel);
        hwlib::cout << accel << "    " << gyro << "\n"
                    << pos << "\n\n";

        if (pos.x_up()) {
            // Volume up
            for (;;) {
                hwlib::wait_ms(250);
                auto newpos = hand_position(mpu);
                if (newpos.x_up())
                    hwlib::cout << "action: volume_up\n";
                else
                    break;
            }
        } else if (pos.x_down()) {
            // Volume down
            for (;;) {
                hwlib::wait_ms(250);
                auto newpos = hand_position(mpu);
                if (newpos.x_down())
                    hwlib::cout << "action: volume_down\n";
                else
                    break;
            }
        } else if (pos.y_down()) {
            // Next/previous song
            // TODO:
        } else if (pos.z_down()) {
            // Toggle play/pause
            hwlib::wait_ms(1000);
            auto newpos = hand_position(mpu);
            if (newpos.z_down())
                hwlib::cout << "action: toggle_play_pause\n";
        }

        hwlib::wait_us(500'000 - (hwlib::now_us() - start));
    }

    return 0;
}
