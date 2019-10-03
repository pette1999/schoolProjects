#include "Classic.h"
#include "Grid.h"
#include <iostream>

using namespace std;

Classic::Classic(char** grid, int r, int c) //constructor
{
    classic_count = 0;
    classicGrid = grid;
    classicRow = r;
    classicColumn = c;
}

//check each cell
void Classic::classicCheck(char** newGrid)
{
    for(int i=0; i<classicRow; ++i)
    {
        for(int j=0; j<classicColumn; ++j)
        {
            classic_count = 0;
            classicCheckNeighbor(i, j);
            if(classic_count<=1)
            {
                newGrid[i][j] = '-';
            }
            else if(classic_count==2)
            {
                if(classicGrid[i][j]=='-')
                {
                    newGrid[i][j] = '-';
                }
                else if (classicGrid[i][j]=='X')
                {
                    newGrid[i][j] = 'X';
                }
            }
            else if(classic_count==3)
            {
                newGrid[i][j] = 'X';
            }
            else if(classic_count>=4)
            {
                newGrid[i][j] = '-';
            }
          
        }
    }
    classicGrid = newGrid; //updated grid becomes classic grid
}

//check neighbors around cell
void Classic::classicCheckNeighbor(int x, int y)
{
    //top left corners
    if(x==0 && y == 0)
    {
        if(classicGrid[0][1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[1][0]=='X')
        {
            classic_count++;
        }
        if(classicGrid[1][1]=='X')
        {
            classic_count++;
        }
    }
    //top right corner
    else if(x==0 && y==classicColumn-1)
    {
        if(classicGrid[0][y-1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[1][y]=='X')
        {
            classic_count++;
        }
        if(classicGrid[1][y-1]=='X')
        {
            classic_count++;
        }
    }
    //bottom left corner
    else if(x==classicRow-1 && y==0)
    {
        if(classicGrid[x-1][1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x][1]=='X')
        {
            classic_count++;
        }
        if (classicGrid[x-1][1] == 'X')
        {
            classic_count++;
        }
    }
    //botton right corner
    else if(x==classicRow-1 && y==classicColumn-1)
    {
        if (classicGrid[x - 1][y] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x][y-1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x-1][y-1] == 'X')
        {
            classic_count++;
        }
    }
    //top row
    else if(x==0 && y!=0 && y!=classicColumn-1)
    {
        if(classicGrid[0][y-1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[0][y+1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[1][y-1]=='X')
        {
            classic_count++;
        }
        if (classicGrid[1][y] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[1][y + 1] == 'X')
        {
            classic_count++;
        }
    }
    //bottom row
    else if (x == classicRow - 1 && y != 0 && y != classicColumn - 1)
    {
        if(classicGrid[x][y-1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x][y+1]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x-1][y-1]=='X')
        {
            classic_count++;
        }
        if (classicGrid[x - 1][y] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x - 1][y + 1] == 'X')
        {
            classic_count++;
        }
    }
    //left column
    else if(y==0 && x!=0 && x!=classicRow-1)
    {
        if(classicGrid[x-1][y]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x+1][y]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x-1][y+1]=='X')
        {
            classic_count++;
        }
        if (classicGrid[x][y+1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x+1][y+1] == 'X')
        {
            classic_count++;
        }
    }
    //right cloumn
    else if (y == classicColumn - 1 && x != 0 && x != classicRow - 1)
    {
        if(classicGrid[x-1][y]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x+1][y]=='X')
        {
            classic_count++;
        }
        if(classicGrid[x-1][y-1]=='X')
        {
            classic_count++;
        }
        if (classicGrid[x][y-1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x+1][y-1] == 'X')
        {
            classic_count++;
        }
    }
    //middle cells
    else if(x>0 && x<classicRow-1 && y>0 && y<classicColumn-1)
    {
        if(classicGrid[x-1][y-1]=='X')
        {
            classic_count++;
        }
        if (classicGrid[x-1][y] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x-1][y+1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x][y-1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x][y+1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x+1][y-1] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x+1][y] == 'X')
        {
            classic_count++;
        }
        if (classicGrid[x+1][y+1] == 'X')
        {
            classic_count++;
        }
    }
}
