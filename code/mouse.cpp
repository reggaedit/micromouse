#include "Mouse.h"
#include <stdint.h>

Mouse::Mouse() {
    
    xLocation = 0;
    yLocation = 15;
    mouseLocation.x = 0;
    mouseLocation.y = 15;
    mouseOrientation = 0.0;
    
} // end constructor

void Mouse::turnClockwise(float degrees) {
    // turn mouse clockwise by 'degrees'
}

void Mouse::turnAntiClockwise(float degrees) {
    // turn mouse anticlockwise by 'degrees'
}

void Mouse::moveStraight(float distance) {
    // move mouse by 'distance'
}

void Mouse::stopMoving() {
    // set speed to zero
}

uint8_t Mouse::getXLocation() {
    return xLocation;
}

uint8_t Mouse::getYLocation() {
    return yLocation;
}

void Mouse::setLocation(uint8_t x, uint8_t y) {
//    mouseLocation = {x,y};
}