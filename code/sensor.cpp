include "mbed.h"
#include "motordriver.h"
#include <map>
#include <iterator>

/* Stores ADC-distance pairs in a binary tree. Distance in mm */
std::map<uint16_t,float> distance_map;

uint16_t voltageToDAC(float v)
{
    return 65530 * (v / 3.3);    
}

/* initDistances: initilise map with distances */
void initDistances()
{
    /* Map between voltages and distance */
    std::map<float, float> voltage_map;
    
    voltage_map[2.4] = 10;
    voltage_map[1.38] = 20;
    voltage_map[0.6] = 30;
    voltage_map[0.3] = 50;
       
    /* Distance/voltage pair. Distance in mm, voltage in V */
    for (std::map<float, float>::iterator it = voltage_map.begin();
         it != voltage_map.end();
         it++)
    {
        distance_map[voltageToDAC(it->first)] = it->second;   
    }
}

/* findDistance: returns the distance given a ADC reading */
float GetDistance(uint16_t adc)
{
    /* Find the first element with key value greater than adc) */
    std::map<uint16_t,float>::iterator lower_it = distance_map.lower_bound(adc);
    
    /* If this is equal to end, we are too close */
    if (lower_it == distance_map.end()) return 0;
    
    /* If this is the first element, we are too far away */
    if (lower_it == distance_map.begin()) return 9999;
    
    /* Otherwise, find preceding element */
    lower_it--;
    std::map<uint16_t,float>::iterator upper_it = lower_it;
    lower_it++;
    
    /* Calculate gradient of interpolating line */
    float gradient = (upper_it->second - lower_it->second) /
                        (upper_it->first - lower_it->first);
    
    /* Find distance in mm */
    float distance = (adc - lower_it->first) * gradient + lower_it->second;
    
    return distance;
}
