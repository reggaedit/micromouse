#include "Cell.h"
#include <bitset>

Cell::Cell() {
    
    // set all walls to empty
    _cellWalls = 0x00;
    
    // set all cells unvisited
    cellVisited = false;
    
} // end constructor

void Cell::setCellWalls(CellWalls walls) {
    _cellWalls = walls | _cellWalls;
}

void Cell::unsetCellWalls(CellWalls walls) {
    // need to invert the input, then AND the original walls
    // E.g. to unset NORTH_W (0001) of a cell with setting 1001 it would be:
    //  ~0001 = 1110, then: 1110 & 1001 = 1000
    _cellWalls = ~walls & _cellWalls;
}

void Cell::clearCellWalls() {
    // set the number to 0000 indicating no walls
    _cellWalls = 0x00;
}

void Cell::setAllCellWalls() {
    // set the number to 1111 indicating all walls
    _cellWalls = 0x0F;
}

uint8_t Cell::getCellData() const {
    return _cellWalls;
}

void Cell::setCellVisited(bool visited){
    cellVisited = visited;
}

bool Cell::getCellVisited(){
    return cellVisited;
}