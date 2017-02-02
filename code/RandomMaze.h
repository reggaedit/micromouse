#ifndef RandomMaze_h
#define RandomMaze_h
#include <stdint.h>
#include "Cell.h"

// Create an enum named DIRECTION to keep track of the four directions
enum DIRECTION {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};

class RandomMaze {
    public:
        RandomMaze();
        const Cell& getCell(uint8_t, uint8_t);
        void createMaze();

    private:
        uint8_t rows;
        uint8_t cols;
        // to keep track of the position in the maze where the path is being generated.
        uint8_t curX;
        uint8_t curY;
        Cell mazeGrid[16][16];

};
#endif