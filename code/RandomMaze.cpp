#include "Cell.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::cout;
using std::vector;

// Create constants (ROWS, COLS) to store the size of the maze.
const int ROWS = 20;
const int COLS = 20;


// Create an enum named DIR to keep track of the four directions (NORTH, EAST, SOUTH, WEST)
enum DIR { NORTH, SOUTH, EAST, WEST };

int main(void){ 
    // variables
    int ran_dir;

    // Randomize the random number function.
    srand(time(NULL));

    // Create a 2-D array ([ROWS][COLS]) of Cell objects.
    Cell maze[ROWS][COLS];

    // For each Cell in the maze:
    for(int row = 0; row < ROWS; row++)
        for(int col = 0; col < COLS; col++) { 
            // set visited to false
            maze[row][col].setVisited(false);
            // set its position to its row and column in the maze
            maze[row][col].setPosition(row, col);
            // set the Cell's walls to Cell::WALL_ALL
            maze[row][col].setWalls(Cell::WALL_ALL);
    }

    //Create curX and curY variables and set them to a random position in the maze.
    int curX = rand() % ROWS;
    int curY = rand() % COLS;

    // Create a vector of Cell objects named trail which will be used as a stack.
    vector<Cell> trail;

    // Create a vector of DIR values named live.
    vector<DIR> live;

    // Grab the Cell at the curX, curY position and push it on the trail stack.
    trail.push_back(maze[curX][curY]);

    // While the trail stack is not empty do the following:
    while(trail.empty()==false) { // stay in here till display
        // Empty the live vector.
        live.clear();
        // Check the neighbors of the current cell to the north, east, south, and west.
        // If any of the neighbors have all four walls, add the direction to that 
        // neighbor to the live vector.
        if(curY)
            if(maze[curX][curY-1].getWalls()==Cell::WALL_ALL) // West has all walls
                live.push_back(WEST);
        if(curY<COLS-1)
        if(maze[curX][curY+1].getWalls()==Cell::WALL_ALL) // east has all walls
            live.push_back(EAST);
        if(curX)
            if(maze[curX-1][curY].getWalls()==Cell::WALL_ALL) // North has all walls
                live.push_back(NORTH);
        if(curX<ROWS-1)
            if(maze[curX+1][curY].getWalls()==Cell::WALL_ALL) // South has all walls
                live.push_back(SOUTH);
        // If the live vector is not empty:
        if(live.empty()==false) {
            // Choose one of the directions in the live vector at random
            // ran_dir=rand() % live.size();
            // cout << "Random dir " << ran_dir << " out of " << live.size() << "\n";
            // Remove the walls between the current cell and the neighbor in that direction
            // and Change curX and curY to refer to the neighbor
            maze[curX][curY].setVisited(true);
            switch(live[rand() % live.size()]) {
                case 0:
                    maze[curX][curY].removeWall(Cell::WALL_NORTH);
                    curX--;
                    break;
                case 1:
                    maze[curX][curY].removeWall(Cell::WALL_SOUTH);
                    curX++;
                    break;
                case 2:
                    maze[curX][curY].removeWall(Cell::WALL_EAST);
                    curY++;
                    break;
                case 3:
                    maze[curX][curY].removeWall(Cell::WALL_WEST);
                    curY--;
                    break;
            }
            // Push the new current cell onto the trail stack
            /*cout << "Maze " << curX << ", " << curY << "\n";
            cin.ignore(); */
            trail.push_back(maze[curX][curY]);
        } //If the live vector was emtpy:
        else {
            // Pop the top item from the trail stack
            trail.pop_back();

            // If the trail stack is not empty, set curX and curY to refer to the 
            // position of the top item in the trail stack.
            if(trail.empty()==false) {
                curX=trail[0].getRow();
                curY=trail[0].getColumn();
            }
        }
    }

    // Do the following to display the maze:
     int r, c;
     for (c=0; c<COLS; c++) {
          if (c == 0) cout << " _";
          else cout << "__";
     }
     cout << '\n';
     for (r=0; r<ROWS; r++) {
          for (c=0; c<COLS; c++) {
                cout << maze[r][c];
          }
          cout << "|\n";
     }
    return 0;
}