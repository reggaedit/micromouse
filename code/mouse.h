#include <stdint.h>

class Mouse {
    public:
        Mouse();
        void turnClockwise(float);
        void turnAntiClockwise(float);
        void moveStraight(float);
        void stopMoving();
        uint8_t getXLocation();
        uint8_t getYLocation();
//        Location getLocation();
        void setLocation(uint8_t, uint8_t);
    private:
        struct Location {
            uint8_t x;
            uint8_t y;
        };
        Location mouseLocation;
        float mouseOrientation;
        uint8_t xLocation;
        uint8_t yLocation;
};