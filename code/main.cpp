// more on header files: http://stackoverflow.com/questions/12733888/regarding-c-include-another-class

#include "mbed.h"
#include <iostream>
#include "Maze.h"
#include "Cell.h"
#include <stdint.h>
#include <ctime>

/*
PwmOut ledPWM(p21);
AnalogIn phototransistor(p15);

PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

void flashLeds()
{
    if (phototransistor.read() < 0.25)
    {
        led1 = 1.0f;
        led2 = 0.0f;
        led3 = 0.0f;
        led4 = 0.0f;
    }
    else if (phototransistor.read() >= 0.25 && phototransistor.read() < 0.5)
    {
        led1 = 1.0f;
        led2 = 1.0f;
        led3 = 0.0f;
        led4 = 0.0f;
    }  else if (phototransistor.read() >= 0.5 && phototransistor.read() < 0.75)
    {
        led1 = 1.0f;
        led2 = 1.0f;
        led3 = 1.0f;
        led4 = 0.0f;
    }
        else
    {
        led1 = 1.0f;
        led2 = 1.0f;
        led3 = 1.0f;
        led4 = 1.0f;
    }
}

*/

// communicated with the pc
Serial pc(USBTX, USBRX);

// Create the local filesystem under the name "local"
LocalFileSystem local("local");
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
        FILE *fp = fopen("/local/out.txt", "w");

        // attempting to calculate time taken to create a maze:
        // http://stackoverflow.com/questions/728068/how-to-calculate-a-time-difference-in-c
        const clock_t begin_time = clock();
        Maze theMaze;
        float time = (float) (clock() - begin_time) / CLOCKS_PER_SEC;

        fprintf(fp, "Time taken: %f.\n\n", time);

        for (uint8_t y = 0; y < 16; y++) {
            fprintf(fp, "Row: %x\t", (int) y);
            for (uint8_t x = 0; x < 16; x++) {
                fprintf(fp, "%x ", (int) theMaze.getCell(x, y).getCellData());
            } // end inner for()
            fprintf(fp, "\n");
        } // end outer for()
        
        fclose(fp);
        writtenToFile = true;
    }
    
    wait(1.5f);
    
} // end main
