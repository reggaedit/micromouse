// more on header files:
//http://stackoverflow.com/questions/12733888/regarding-c-include-another-class

#include "mbed.h"
#include <iostream>
#include "Maze.h"
#include "RandomMaze.h"
#include "Cell.h"
#include "Mouse.h"
#include <stdint.h>
#include <ctime>

// global variables for the mouse location.
// reading and modifying these will happen often, so must be fast.
static uint8_t mouseXCoord = 0;
static uint8_t mouseYCoord = 15;

// communication with the pc
Serial pc(USBTX, USBRX);

// create the local filesystem under the name "local" for writing data to file
LocalFileSystem local("local");

// main method that initialises Mouse, Maze and algorithms
int main() {
    // open "out.txt" on the local file system for writing
    // this is usefu for when serial COM ports are not working.
    //FILE *fp = fopen("/local/out.txt", "w");
    
    // initialise the real Maze
    Maze maze;
    
    // Initialise a random maze
    RandomMaze randomMaze;

    // initialise the Mouse
    Mouse mouse;

    // print all cells of the mazeGrid
    for(uint8_t i = 0; i<16 ; i++) {
        // write a matrix of cells to the file
        for (uint8_t y = 0; y < 16; y++) {
            //fprintf(fp, "Row: %x\t", (int) y);
            pc.printf("Row: %x\t", (int) y);
            
            for (uint8_t x = 0; x < 16; x++) {
                // convert every cell information to type int so printf may be used.
                //fprintf(fp, "%x ", (int) maze.getCell(x, y).getCellData());
                if(mouseXCoord == x && mouseYCoord == y) {
                    pc.printf("M ");
                } else {
                    pc.printf("%x ", (int) randomMaze.getCell(x, y).getCellData());
                }
                
            } // end inner for()
            //fprintf(fp, "\n");
            pc.printf("\r\n");
        } // end outer for()
        
        pc.printf("\r\n");

        // move the mouse right one space 
        mouseXCoord += 1;
        wait(0.5f);
    }

    //fclose(fp); // close file

} // end main