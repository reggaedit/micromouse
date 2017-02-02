#ifndef Cell_h
#define Cell_h
#include <stdint.h>

// more on bit operators: http://stackoverflow.com/questions/11815894/how-to-read-write-arbitrary-bits-in-c-c
enum CellWalls:uint8_t {
    NORTH_W = 1, // 0001
    EAST_W = 2,  // 0010
    SOUTH_W = 4, // 0100
    WEST_W = 8,   // 1000
    ALL_W = 15   // 1111
};

class Cell {
    public:
        Cell(); // constructor
        void setCellWalls(CellWalls walls);
        void unsetCellWalls(CellWalls walls);
        void clearCellWalls();
        void setAllCellWalls();
        void setCellVisited(bool);
        bool getCellVisited();
        uint8_t getCellData() const;

        // temp variables for the RandomMaze, so it knows which location the cell has.
        void setCellLocation(uint8_t, uint8_t);
        uint8_t getRow();
        uint8_t getColumn();
        
    private:
        bool cellVisited;
        // where a cell does/doesn't have walls (see CellWalls enum)
        uint8_t _cellWalls;

        // temp variables for the RandomMaze, so it knows which location the cell has.
        uint8_t row;
        uint8_t col;
};
#endif