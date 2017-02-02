#include <stdint.h>

class Mouse {
    public:
        Mouse();
        void turnClockwise(float);
        void turnAntiClockwise(float);
        void moveStraight(float);
        void stopMoving();
        void setLocation(uint8_t, uint8_t);
    private:
        float mouseOrientation;
};