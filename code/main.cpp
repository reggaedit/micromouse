// more on header files: http://stackoverflow.com/questions/12733888/regarding-c-include-another-class

#include "mbed.h"
#include <iostream>
#include "Maze.h"
#include "Cell.h"
#include "Mouse.h"
#include <stdint.h>
#include <ctime>


static uint8_t mouseXCoord = 0;
static uint8_t mouseYCoord = 15;


PwmOut ledPWM(p21);
AnalogIn phototransistor(p15);

// communicated with the pc
Serial pc(USBTX, USBRX);

// Create the local filesystem under the name "local" for writing data to file
LocalFileSystem local("local");

// Only write to the file once
bool writtenToFile = false;

// main loop for the program
int main() {

    // reading the phototransistor
    /*
    ledPWM.period(0.01);
    ledPWM = 1.0f;
    led1.period(0.01);
    led2.period(0.01);
    led3.period(0.01);
    led4.period(0.01);

    while (true)
    {
        //pc.printf(phototransistor);
        pc.printf("The AnalogIn is: %.4f.\r\n", phototransistor.read());
        flashLeds();
        wait(0.4f);
        
    } // end while
    */

    if(!writtenToFile) {
        
        // Open "out.txt" on the local file system for writing
        //FILE *fp = fopen("/local/out.txt", "w");
        
        Maze maze;
        
        Mouse mouse;
        uint8_t xCoord = mouse.getXLocation();
        uint8_t yCoord = mouse.getYLocation();
        
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
                        pc.printf("%x ", (int) maze.getCell(x, y).getCellData());
                    }
                    
                } // end inner for()
                //fprintf(fp, "\n");
                pc.printf("\r\n");
            } // end outer for()
            
            
            
            pc.printf("\r\n");
            //fprintf(fp, "Mouse position x=%x, y=%x/n", (int) mouse.getLocation().x, (int) mouse.getLocation().y);
            
            
        
            mouseXCoord += 1;
            wait(0.5f);
            
        }
        
        //fclose(fp); // close file
        writtenToFile = true;
    }
    //while(1){
    //    wait(0.7f);
    //    pc.printf("The AnalogIn IR reading is: %.2f\r\n", phototransistor.read());
    //}
} // end main
