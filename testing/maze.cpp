#include <iostream>

// test comment

using namespace std;

class Maze {
    public:
        void setCellData(int x, int y, int z, int val);
        int getCellData(int x, int y, int z);
        Maze(); // constructor
        
    private:
        int mazeArray[16][16][8];

};

// Member functions definitions including constructor
Maze::Maze() {
    cout << "Object is being created" << endl;
    int a = 1;
    for(int x = 0; x < 16; x++) {
        for(int y = 0; y < 16; y++) {
            for(int z = 0; z < 8; z++) {
                mazeArray[x][y][z] = a;
                a++;
            } //end for 3
            a = 1; // reset a
        } // end for 2
    } // end for 1
} // end constructor

void Maze::setCellData(int x, int y, int z, int val) {
    mazeArray[x][y][z] = val;
}

int Maze::getCellData(int x, int y, int z) {
    return mazeArray[x][y][z];
}

// main function for the program
int main() {
    Maze aMaze;
    //aMaze.setCellData(0,0, 1);
    //int values[2] = {aMaze.getCellData(0,0), aMaze.getCellData(0,1)};
    //cout << values[0] << ", " << values[1] << endl;
    for (int x = 0; x < 16; x++) {
    //cout << "[";
        for (int y = 0; y < 16; y++) {
            for(int z = 0; z < 8; z++) {
                cout << aMaze.getCellData(x,y,z) << "" ;
            }
            cout << "-";
        } // end inner for()
    
    cout << endl;
    } // end outer for()
    //cout << "]" << endl;
    return 0;
} // end main


