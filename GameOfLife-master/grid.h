#include <iostream>
#include <fstream>

using namespace std;

class grid
{
public:
    grid();
    grid(string filename);
    ~grid();

    //File reading part
    void readFile();
    void printFile();
    int getRow();
    int getCloumn();

    //Grid part
    void createGrid();
    void generateRandomGrid(int row, int column, double density);
    void printGrid();
    void printNewGrid();
    void writeNewToFile(string fileName, int c);
    void updateMyGrid(int r, int c, char ch);
    void updateNewGrid(int r, int c, char ch);
    char getValueFromGrid(int r, int c);
    char getValueFromNewGrid(int r, int c);
    char** getMyGrid();
    char** getNewGrid();

    ifstream inFile;
    string line;
    string fileName;
    int fileRow;
    int fileColumn;
    char **myGrid;
    char **newGrid; //a copy grid
};