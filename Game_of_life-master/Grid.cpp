#include "Grid.h"
#include<iostream>
#include<fstream>

using namespace std;

//default constructor
Grid::Grid()
{
  inRow = 5;
  inColumn = 5;//default grid would be 5 by 5
  myGrid = new char*[inRow];//create an 1-D array first
  myNewGrid = new char*[inRow];//crete grid for the copy grid
  for(int i=0; i<inRow; ++i)
  {
    myGrid[i] = new char[inColumn];
    //for each cell in the 1-D array, we point another 1-D array in there to make a 2-D array
  }
  for(int i=0; i<inRow; ++i)
  {
    myNewGrid[i] = new char[inColumn];
  }

  for(int i=0; i<inRow; ++i)
  {
    for(int j=0; j<inColumn; ++j)
    {
      myGrid[i][j] = '-';
      //initialize the grid with all '-'
      myNewGrid[i][j] = '-';
    }
  }
}

//overloaded constrctor
Grid::Grid(int row, int column)
{
  inRow = row;
  inColumn = column;
  myGrid = new char*[inRow];
  myNewGrid = new char*[inRow];
  for(int i=0; i<inRow; ++i)
  {
    myGrid[i] = new char[inColumn];
  }
  for(int i=0; i<inRow; ++i)
  {
    myNewGrid[i] = new char[inColumn];
  }

  for (int i = 0; i < inRow; ++i)
  {
    for (int j = 0; j < inColumn; ++j)
    {
      myGrid[i][j] = '-';
      myNewGrid[i][j] = '-';
    }
  }
  fileName = "";
}

Grid::Grid(int row, int column, string filename)
{
  inRow = row;
  inColumn = column;
  myGrid = new char *[inRow];
  myNewGrid = new char *[inRow];
  for (int i = 0; i < inRow; ++i)
  {
    myGrid[i] = new char[inColumn];
  }
  for (int i = 0; i < inRow; ++i)
  {
    myNewGrid[i] = new char[inColumn];
  }

  for (int i = 0; i < inRow; ++i)
  {
    for (int j = 0; j < inColumn; ++j)
    {
      myGrid[i][j] = '-';
      myNewGrid[i][j] = '-';
    }
  }
  fileName = "";
  ifstream inFile(fileName);
}

//destructor
Grid::~Grid()
{
  delete myGrid;
  delete myNewGrid;
}

//print out the grid in the terminal
void Grid::printGrid()
{
  cout << "myGrid" << endl;
  for(int i=0; i<inRow; ++i)
  {
    if(to_string(i).length() == 1)
    {
      cout << i;
      cout << "     ";
    }
    else if(to_string(i).length() == 2)
    {
      cout << i;
      cout << "    ";
    }
    else if(to_string(i).length() == 3)
    {
      cout << i;
      cout << "   ";
    }
    else if (to_string(i).length() == 4)
    {
      cout << i;
      cout << "  ";
    }
    for (int j=0; j<inColumn; ++j)
    {
      cout << myGrid[i][j];
      cout << "  ";
    }
    cout << "\n";
  }
}

void Grid::printNewGrid() // the second grid in terminal (put new info in it) make it 
{
  cout << "myNewGrid" << endl;
  for (int i = 0; i < inRow; ++i)
  {
    if (to_string(i).length() == 1)
    {
      cout << i;
      cout << "     ";
    }
    else if (to_string(i).length() == 2)
    {
      cout << i;
      cout << "    ";
    }
    else if (to_string(i).length() == 3)
    {
      cout << i;
      cout << "   ";
    }
    else if (to_string(i).length() == 4)
    {
      cout << i;
      cout << "  ";
    }
    for (int j = 0; j < inColumn; ++j)
    {
      cout << myNewGrid[i][j];
      cout << "  ";
    }
    cout << "\n";
  }
}

void Grid::insertPoints(int x, int y) //to insert the x
{
  myGrid[x][y] = 'X';
}

char** Grid::returnMyGrid() //grid 1
{
  return myGrid;
}

int Grid::getRow() //the rows
{
  return inRow;
}

int Grid::getColumn() //the columns
{
  return inColumn;
}

void Grid::fileOp(string filename)
{
  if (!inFile)
  {
    cout << "there are some problems.";
    exit(1); //if the file is not there, return an error
  }

  inFile.open(filename);
  
  int linenumber = 0;
  getline(inFile, line); //read the first line from the file, which is the row numebr
  fileRow = stoi(line);  //parse string to int
  inRow = fileRow;
  getline(inFile, line); //read the second line of the file, which is the column
  fileColumn = stoi(line);
  inColumn = fileColumn;

  while (getline(inFile, line)) //while there is a line in the file
  {
    for (int i = 0; i < fileColumn; ++i)
    {
      myGrid[linenumber][i] = line[i];
    }
    linenumber++;
  }

  inFile.close();
}

void Grid::randomGrid(double d, char** grid) //for the random configuration
{
  srand(time(NULL)); //to reset rand(), to prevent getting the same random number
  for(int i=0; i<inRow; ++i)
  {
    for(int j=0; j<inColumn; ++j)
    {
      double n = rand()%10/(double)10;
      if(n <= d)
      {
        grid[i][j] = 'X';
      }
      else
      {
        grid[i][j] = '-';
      }
      cout << "n: " << n << endl;
    }
  }
}

int Grid::copy() //copies the new grid onto old grid/ alternates if there are differneces
{
  difference = 0;
  for(int i=0; i<inRow; ++i)
  {
    for(int j=0; j<inColumn; ++j)
    {
      if(myGrid[i][j] != myNewGrid[i][j])
      {
        difference++; //tells if the grids stabilized or not, 0 = stable
      }
      myGrid[i][j] = myNewGrid[i][j];
    }
  }

  return difference;
}

void Grid::writeToFile(string outputFile)
{
  outFile.open(outputFile, fstream::app);

  outFile << "myGrid" << "\n";
  for (int i = 0; i < inRow; ++i)
  {
    if (to_string(i).length() == 1)
    {
      outFile << i;
      outFile << "     ";
    }
    else if (to_string(i).length() == 2)
    {
      outFile << i;
      outFile << "    ";
    }
    else if (to_string(i).length() == 3)
    {
      outFile << i;
      outFile << "   ";
    }
    else if (to_string(i).length() == 4)
    {
      outFile << i;
      outFile << "  ";
    }
    for (int j = 0; j < inColumn; ++j)
    {
      outFile << myGrid[i][j];
      outFile << "  ";
    }
    outFile << "\n";
  }

  outFile.close();
}