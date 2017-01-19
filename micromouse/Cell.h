#ifndef Cell_h
#define Cell_h
#include <stdint.h>

// more on bit operators: http://stackoverflow.com/questions/11815894/how-to-read-write-arbitrary-bits-in-c-c
enum CellWalls:uint8_t {
    NORTH_W = 1, // 0001
    EAST_W = 2,  // 0010
    SOUTH_W = 4, // 0100
    WEST_W = 8   // 1000
};

class Cell {
    public:
        Cell(); // constructor
        void setCellWalls(CellWalls walls);
        void unsetCellWalls(CellWalls walls);
        void clearCellWalls();
        void setAllCellWalls();
        uint8_t getCellData() const;
        
    private:
        bool cellVisited;
        //short int cellLocation[2]; // maybe not required if each cell is in a maze array.
        uint8_t _cellWalls; // where a cell does/doesn't have walls
};
#endif