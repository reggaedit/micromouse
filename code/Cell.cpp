#include "Cell.h"
#include <bitset>

Cell::Cell() {
    
    // set all walls to empty
    _cellWalls = 0x00;
    
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
    _cellWalls = 0x00;
}

void Cell::setAllCellWalls() {
    _cellWalls = 0x0F;
}

uint8_t Cell::getCellData() const {
    return _cellWalls;
}