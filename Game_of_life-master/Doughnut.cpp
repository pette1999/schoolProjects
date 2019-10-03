#include "Doughnut.h"
#include "Grid.h"
#include <iostream>

using namespace std;

Doughnut::Doughnut(char** grid, int r, int c) //constructor
{
    doughnut_count = 0;
    doughnutRow = r;
    doughnutColumn = c;
    doughnutGrid = grid;
}

void Doughnut::doughnutCheck(char** newGrid)
{
    for(int i=0; i<doughnutRow; ++i)
    {
        for(int j=0; j<doughnutColumn; ++j)
        {
            doughnut_count = 0; // neighbor rules
            doughnutCheckNeighbor(i,j);
            if (doughnut_count <= 1) // cell become '-' if count become <=1
            {
                newGrid[i][j] = '-';
            }
            else if (doughnut_count == 2) // cell stays the same if count is 2
            {
                if (doughnutGrid[i][j] == '-')
                {
                    newGrid[i][j] = '-';
                }
                else if (doughnutGrid[i][j] == 'X')
                {
                    newGrid[i][j] = 'X';
                }
            }
            else if (doughnut_count == 3) //cell changes to 'X' if count = 3
            {
                if (doughnutGrid[i][j] == '-')
                {
                    newGrid[i][j] = 'X';
                }
                else if (doughnutGrid[i][j] == 'X')
                {
                    newGrid[i][j] = 'X';
                }
            }
            else if (doughnut_count >= 4) //cell become '-' if count is >=4
            {
                newGrid[i][j] = '-';
            }
        }
    }
    doughnutGrid = newGrid; // updates second grid with info from first grid
}

void Doughnut::doughnutCheckNeighbor(int x, int y)
{
    int i;
    int j;
    i = (x - 1) % doughnutRow; // end rows are circular
    j = (y - 1) % doughnutColumn; // end columns are circular
    if(i<0)
    {
        i = i + doughnutRow;
    }
    if(j<0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X') //
    {
        doughnut_count++;
    }
    i = (x - 1) % doughnutRow;//
    j = (y) % doughnutColumn;
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if(doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
    i = (x - 1) % doughnutRow; //
    j = (y + 1) % doughnutColumn;//
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
    i = (x) % doughnutRow;
    j = (y - 1) % doughnutColumn;
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
    i = (x) % doughnutRow;
    j = (y + 1) % doughnutColumn;
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
    i = (x + 1) % doughnutRow;
    j = (y - 1) % doughnutColumn;
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
    i = (x + 1) % doughnutRow;
    j = (y) % doughnutColumn;
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
    i = (x + 1) % doughnutRow;
    j = (y + 1) % doughnutColumn;
    if (i < 0)
    {
        i = i + doughnutRow;
    }
    if (j < 0)
    {
        j = j + doughnutColumn;
    }
    if (doughnutGrid[i][j] == 'X')
    {
        doughnut_count++;
    }
}
