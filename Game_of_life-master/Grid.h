#include<iostream>
#include<fstream>

using namespace std;

class Grid
{
public:
  Grid();
  Grid(int row, int column);
  Grid(int row, int column, string filename);
  ~Grid();

  void printGrid();
  void printNewGrid();
  void insertPoints(int x, int y);
  void fileOp(string filename);
  void randomGrid(double d, char** grid);
  void writeToFile(string outputFile);
  int copy();
  char** returnMyGrid();
  int getRow();
  int getColumn();
  string fileName;
  string line;
  ifstream inFile;
  int fileRow;
  int fileColumn;
  int lineLength;
  int difference;
  int inRow;
  int inColumn;

  char **myGrid;
  char **myNewGrid;

  ofstream outFile;
};
