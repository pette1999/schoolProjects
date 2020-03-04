#include "Grid.h"
#include <iostream>
#include <fstream>

using namespace std;

Grid::Grid()
{
    fileRow = 5;
    fileColumn = 5;
    myGrid = new char *[fileRow]; //create an 1-D array first
    for (int i = 0; i < fileRow; ++i)
    {
        myGrid[i] = new char[fileColumn];
        //for each cell in the 1-D array, we point another 1-D array in there to make a 2-D array
    }

    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            myGrid[i][j] = '-';
            //initialize the grid with all '-'
        }
    }
}

Grid::Grid(int row, int column)
{
    fileRow = row;
    fileColumn = column;
    myGrid = new char *[fileRow]; //create an 1-D array first
    for (int i = 0; i < fileRow; ++i)
    {
        myGrid[i] = new char[fileColumn];
        //for each cell in the 1-D array, we point another 1-D array in there to make a 2-D array
    }

    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            myGrid[i][j] = '-';
            //initialize the grid with all '-'
        }
    }
}

//destructor
Grid::~Grid()
{
    delete myGrid;
}

void Grid::printGrid()
{
    cout << "myGrid" << endl;
    for (int i = 0; i < fileRow; ++i)
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
        for (int j = 0; j < fileColumn; ++j)
        {
            cout << myGrid[i][j];
            cout << "  ";
        }
        cout << "\n";
    }
}

void Grid::opGrid(string filename)
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
    fileColumn = fileRow;

    while (getline(inFile, line)) //while there is a line in the file
    {
        for (int i = 0; i < fileColumn; ++i)
        {
            myGrid[linenumber][i] = line[i];
        }
        linenumber++;
    }

    // get the initial state and final goal
    for(int i=0; i < fileRow; ++i)
    {
        for(int j=0; j < fileColumn; ++j)
        {
            if(myGrid[i][j] == 'i')
            {
                init_x = i;
                init_y = j;
                cout << "Initial state: (" << init_x << ", " << init_y << ")" << endl;
            }
            else if(myGrid[i][j] == 'g')
            {
                final_x = i;
                final_y = j;
                cout << "Final state: (" << final_x << ", " << final_y << ")" << endl;
            }
        }
    }
    printGrid();
}
