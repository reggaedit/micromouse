// include guards: https://en.wikipedia.org/wiki/Include_guard
#ifndef Maze_h
#define Maze_h
#include <stdint.h>
#include "Cell.h"

class Maze {
    public:
        Maze(); // constructor
        const Cell& getCell(uint8_t, uint8_t);
        
    private:
        const uint8_t mazeWidth = 16;
        Cell mazeGrid[16][16];
        
       //Cell mazeGrid[][];
};
#endif