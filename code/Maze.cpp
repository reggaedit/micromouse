#include "Maze.h"
#include "Cell.h"
#include <stdint.h>

using namespace std;

// Member functions definitions including constructor
Maze::Maze() {

    const uint8_t mazeWidth = 16;

    // set all the west walls of the cells on the left.
    for(uint8_t i = 0; i < mazeWidth; i++) {
        mazeGrid[0][i].setCellWalls(WEST_W);
        mazeGrid[i][0].setCellWalls(NORTH_W);
        mazeGrid[mazeWidth-1][i].setCellWalls(EAST_W);
        mazeGrid[i][mazeWidth-1].setCellWalls(SOUTH_W);
    } // end for loop
    
    // set the start cell
    mazeGrid[0][15].setCellWalls(EAST_W);
    
} // end constructor

const Cell& Maze::getCell(uint8_t x, uint8_t y) {
    return mazeGrid[x][y];
}