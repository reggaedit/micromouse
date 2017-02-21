#ifndef Sensor_h
#define Sensor_h
#include "motordriver.h"
#include <map>
#include <iterator>

class Sensor {
    public:
        Sensor();
        float getDistance(uint16_t);

    private:
        /* Stores ADC-distance pairs in a binary tree. Distance in mm */
        map<uint16_t,float> distance_map;
        void initDistances();
        uint16_t voltageToDAC(float);

}
#endif