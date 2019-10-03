#include "Mirror.h"
#include "Grid.h"
#include <iostream>

using namespace std;

Mirror::Mirror(char **grid, char** bigGrid, int r, int c)
{
    mirror_count = 0; //count
    mirrorGrid = grid;
    mirrorBigGrid = bigGrid; //extra rows and columns due to the 'wall mirror'
    mirrorRow = r;
    mirrorColumn = c;
}

void Mirror::setBigGrid()
{
    for(int i=0; i<=mirrorRow+1; ++i) //layout of the big grid including the extra row(s)
    {
        for(int j=0; j<=mirrorColumn+1; ++j) //extra column(s)
        {
            if(i==0 && j==0) //top left corner
            {
                mirrorBigGrid[i][j] = mirrorGrid[0][0];
            }
            else if(i==0 && j==mirrorColumn+1) //right top corner
            {
                mirrorBigGrid[i][j] = mirrorGrid[0][mirrorColumn-1];
            }
            else if(i==mirrorRow+1 && j==0) //bottom left corner
            {
                mirrorBigGrid[i][j] = mirrorGrid[mirrorRow-1][0];
            }
            else if(i==mirrorRow+1 && j==mirrorColumn+1) //bottom right corner
            {
                mirrorBigGrid[i][j] = mirrorGrid[mirrorRow-1][mirrorColumn-1];
            }
            else if(i==0 && j!=0 && j!=mirrorColumn+1) //top row sans corners
            {
                mirrorBigGrid[i][j] = mirrorGrid[0][j-1];
            }
            else if (i==mirrorRow+1 && j!=0 && j!=mirrorColumn+1) //bottom row sans corners
            {
                mirrorBigGrid[i][j] = mirrorGrid[mirrorRow-1][j-1];
            }
            else if (j==0 && i!=0 && i!=mirrorRow+1) //left row sans corners
            {
                mirrorBigGrid[i][j] = mirrorGrid[i-1][0];
            }
            else if (j==mirrorColumn+1 && i != 0 && i != mirrorRow + 1) //right row sans corners
            {
                mirrorBigGrid[i][j] = mirrorGrid[i-1][mirrorColumn-1];
            }
            else if(i>0 && i<mirrorRow+1 && j>0 && j<mirrorColumn+1) 
            {
                mirrorBigGrid[i][j] = mirrorGrid[i-1][j-1];
            }
        }
    }
}

void Mirror::printBigGrid()
{
    cout << "mirrorBigGrid" << endl; //prints grid with the extra cells
    for (int i = 0; i < mirrorRow+2; ++i)
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
        for (int j = 0; j < mirrorColumn+2; ++j)
        {
            cout << mirrorBigGrid[i][j];
            cout << "  ";
        }
        cout << "\n";
    }
}

void Mirror::mirrorCheck(char **newGrid) //checks the neighbor rules
{
    for(int i=1; i<mirrorRow+1; ++i)
    {
        for(int j=1; j<mirrorColumn+1; ++j)
        {
            mirror_count = 0;
            mirrorCheckNeighbor(i,j);
            if (mirror_count <= 1) //cell has dash if <=1
            {
                newGrid[i-1][j-1] = '-';
            }
            else if (mirror_count == 2) //cell stays the same if count is 2
            {
                if (mirrorBigGrid[i][j] == '-')
                {
                    newGrid[i-1][j-1] = '-';
                }
                else if (mirrorBigGrid[i][j] == 'X')
                {
                    newGrid[i-1][j-1] = 'X';
                }
            }
            else if (mirror_count == 3) //cell gets an 'x' if count is 3
            {
                if (mirrorBigGrid[i][j] == '-')
                {
                    newGrid[i-1][j-1] = 'X';
                }
                else if (mirrorBigGrid[i][j] == 'X')
                {
                    newGrid[i-1][j-1] = 'X';
                }
            }
            else if (mirror_count >= 4) //cell gets a '-' if count is >=4
            {
                newGrid[i-1][j-1] = '-';
            }
        }
    }
    mirrorGrid = newGrid; //update other grid
}

void Mirror::mirrorCheckNeighbor(int x, int y) //checking the neighbors of the cell
{
    if(mirrorBigGrid[x-1][y-1]=='X')
    {
        mirror_count++;
    }
    if(mirrorBigGrid[x-1][y]=='X')
    {
        mirror_count++;
    }
    if (mirrorBigGrid[x-1][y+1] == 'X')
    {
        mirror_count++;
    }
    if (mirrorBigGrid[x][y-1] == 'X')
    {
        mirror_count++;
    }
    if (mirrorBigGrid[x][y+1] == 'X')
    {
        mirror_count++;
    }
    if (mirrorBigGrid[x+1][y-1] == 'X')
    {
        mirror_count++;
    }
    if (mirrorBigGrid[x+1][y] == 'X')
    {
        mirror_count++;
    }
    if (mirrorBigGrid[x+1][y+1] == 'X')
    {
        mirror_count++;
    }
}
