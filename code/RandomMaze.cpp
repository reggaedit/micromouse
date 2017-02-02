#include "Cell.h"
#include "RandomMaze.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

using std::cout;
using std::vector;

//constructor
RandomMaze::RandomMaze() {
    uint8_t mazeSize = 16;

    rows = mazeSize;
    cols = mazeSize;

    //const uint8_t mazeWidth = mazeSize;

    // For each Cell in the maze:
    for(uint8_t r = 0; r < rows; r++) {
        for(uint8_t c = 0; c < cols; c++) { 
            // set visited to false
            // not required as the constructor already does this.
            //mazeGrid[r][c].setCellVisited(false);

            // set the Cell's walls to ALL_W
            mazeGrid[r][c].setCellWalls(ALL_W);
            mazeGrid[r][c].setCellLocation(r,c);
        }
    }


    // Randomize the random number function.
    srand(time(NULL));

    //Create curX and curY variables and set them to a random position in the maze.
    curX = rand() % rows;
    curY = rand() % cols;

}

void RandomMaze::createMaze() {
    // see here for more information on this algorithm:
    // http://www.cplusplus.com/forum/beginner/41707/

    // Create constants (ROWS, COLS) to store the size of the maze.
    //const int ROWS = 16;
    //const int COLS = 16;

    // variables
    //uint8_t ran_dir;

    // Randomize the random number function.
    //srand(time(NULL));

    //Create curX and curY variables and set them to a random position in the maze.
    //uint8_t curX = rand() % rows;
    //uint8_t curY = rand() % cols;

    // Create a vector of Cell objects named trail which will be used as a stack.
    vector<Cell> trail;

    // Create a vector of DIR values named live.
    vector<DIRECTION> live;

    // Grab the Cell at the curX, curY position and push it on the trail stack.
    trail.push_back(mazeGrid[curX][curY]);

    // While the trail stack is not empty do the following:
    while(trail.empty() == false) {
        // stay in here till display
        // Empty the live vector.
        live.clear();
        // Check the neighbors of the current cell to the north, east, south, and west.
        // If any of the neighbors have all four walls, add the direction to
        // that neighbor to the live vector.
        if(curY) {
            if(mazeGrid[curX][curY-1].getCellData() == ALL_W) {
                // West has all walls
                live.push_back(WEST);
            }
        }
        if(curY < cols-1) {
            if(mazeGrid[curX][curY+1].getCellData() == ALL_W) {
                // east has all walls
                live.push_back(EAST);
            }
        }
        if(curX) {
            if(mazeGrid[curX-1][curY].getCellData() == ALL_W) {
                // North has all walls
                live.push_back(NORTH);
            }
        }
        if(curX < rows-1) {
            if(mazeGrid[curX+1][curY].getCellData() == ALL_W) {
                // South has all walls
                live.push_back(SOUTH);
            }
        }
        // If the live vector is not empty:
        if(live.empty()==false) {
            // Choose one of the directions in the live vector at random
            // ran_dir=rand() % live.size();
            // cout << "Random dir " << ran_dir << " out of " << live.size() << "\n";
            // Remove the walls between the current cell and the neighbor in
            // that direction and Change curX and curY to refer to the neighbor
            mazeGrid[curX][curY].setCellVisited(true);
            switch(live[rand() % live.size()]) {
                case 0:
                    mazeGrid[curX][curY].unsetCellWalls(NORTH_W);
                    mazeGrid[--curX][curY].unsetCellWalls(SOUTH_W);
                    break;
                case 1:
                    mazeGrid[curX][curY].unsetCellWalls(SOUTH_W);
                    mazeGrid[++curX][curY].unsetCellWalls(NORTH_W);
                    break;
                case 2:
                    mazeGrid[curX][curY].unsetCellWalls(EAST_W);
                    mazeGrid[curX][++curY].unsetCellWalls(WEST_W);
                    break;
                case 3:
                    mazeGrid[curX][curY].unsetCellWalls(WEST_W);
                    mazeGrid[curX][--curY].unsetCellWalls(EAST_W);
                    break;
            }
            // Push the new current cell onto the trail stack
            /*cout << "Maze " << curX << ", " << curY << "\n";
            cin.ignore(); */
            trail.push_back(mazeGrid[curX][curY]);
        } //If the live vector was emtpy:
        else {
            // Pop the top item from the trail stack
            trail.pop_back();

            // If the trail stack is not empty, set curX and curY to refer to
            // the position of the top item in the trail stack.
            if(trail.empty()==false) {
                curX=trail[0].getRow();
                curY=trail[0].getColumn();
            }
        }
    }
/*
    // Do the following to display the mazeGrid:
    for (uint8_t c = 0; c < cols; c++) {
        if (c == 0)
            cout << " _";
        else
            cout << "__";
    }

    cout << '\n';
    for (uint8_t r = 0; r < rows; r++) {
        for (uint8_t c = 0; c < cols; c++) {
            cout << mazeGrid[r][c].getCellData();
        }
        cout << "|\n";
    }
*/

    // TODO: what is this return statement at end of main for?
    //return 0;
}

const Cell& RandomMaze::getCell(uint8_t x, uint8_t y) {
    return mazeGrid[x][y];
}