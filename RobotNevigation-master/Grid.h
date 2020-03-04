#include <iostream>
#include <fstream>
#include "file.h"

using namespace std;

class Grid
{
public:
    Grid();
    Grid(int row, int column);
    ~Grid();

    void opGrid(string filename);
    void printGrid();

    int fileRow;
    int fileColumn;
    int lineLength;
    int init_x;
    int init_y;
    int final_x;
    int final_y;
    string fileName;
    string line;
    ifstream inFile;

    char **myGrid;

    file a(string username);
};