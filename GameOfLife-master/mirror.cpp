#include <iostream>
#include <time.h>
#include <fstream>
#include "mirror.h"

using namespace std;

mirror::mirror()
{
    neighbor_count = 0;
    done = false;
    mirrorFilename = "test.txt";
    mirrorGeneration = 0;
}

mirror::mirror(string filename)
{
    neighbor_count = 0;
    done = false;
    mirrorFilename = filename;
    mirrorGeneration = 0;
}

void mirror::mirrorMode(int mode, int in_row, int in_column, double in_density, int timeMode, string optFilename)
{
    classic c;
    if(mode == 1)
    {
        grid g(mirrorFilename);
        g.createGrid();
        g.printGrid();
        g.printNewGrid();

        row = g.getRow();
        column = g.getCloumn();

        while (true)
        {
            int change_count = 0;

            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < column; ++j)
                {
                    neighbor_count = 0; //reset the neighbor count
                    //To check corner, only needs to check three neighbors
                    if ((i == 0 && j == 0))
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == 0 && j == column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == 0)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    //Check the 4 borders
                    else if (i == 0 && j != 0 && j != column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j != 0 && j != column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == 0 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == column - 1 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    //The rest
                    else if (i > 0 && i < row - 1 && j > 0 && j < column - 1)
                    {
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                }
            }
            // If the different with the last one is 0, then break the loop, we found the final stage
            if (change_count == 0)
            {
                cout << "\n\nIt's the end, Press Enter to End" << endl;
                cin.ignore(); //ends after the user hits enter
                break;
            }
            if (timeMode == 1)
            {
                c.sleepcp(3000);
            }
            else if (timeMode == 2)
            {
                cin.get();
            }
            else if (timeMode == 3)
            {
                g.writeNewToFile(optFilename, mirrorGeneration);
            }
            cout << "Generation " << ++mirrorGeneration << endl;
            g.printNewGrid();
            
            

            // Cover the old grid with new grid
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < column; ++j)
                {
                    g.updateMyGrid(i, j, g.getValueFromNewGrid(i, j));
                }
            }
        }
    }
    else if(mode == 2)
    {
        grid g;
        g.generateRandomGrid(in_row, in_column, in_density);
        g.printGrid();
        g.printNewGrid();

        row = g.getRow();
        column = g.getCloumn();

        while (true)
        {
            int change_count = 0;

            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < column; ++j)
                {
                    neighbor_count = 0; //reset the neighbor count
                    //To check corner, only needs to check three neighbors
                    if ((i == 0 && j == 0))
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == 0 && j == column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == 0)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count += 3;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    //Check the 4 borders
                    else if (i == 0 && j != 0 && j != column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j != 0 && j != column - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == 0 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == column - 1 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count += 2;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    //The rest
                    else if (i > 0 && i < row - 1 && j > 0 && j < column - 1)
                    {
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        c.checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                }
            }
            // If the different with the last one is 0, then break the loop, we found the final stage
            if (change_count == 0)
            {
                cout << "\n\nIt's the end, Press Enter to End" << endl;
                cin.ignore(); //ends after the user hits enter
                break;
            }
            if (timeMode == 1)
            {
                c.sleepcp(3000);
            }
            else if (timeMode == 2)
            {
                cin.get();
            }
            else if (timeMode == 3)
            {
                g.writeNewToFile(optFilename, mirrorGeneration);
            }
            cout << "Generation " << ++mirrorGeneration << endl;
            g.printNewGrid();
            
            // Cover the old grid with new grid
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < column; ++j)
                {
                    g.updateMyGrid(i, j, g.getValueFromNewGrid(i, j));
                }
            }
        }
    }
}