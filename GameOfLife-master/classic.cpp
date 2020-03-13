#include <iostream>
#include <time.h>
#include <fstream>
#include "classic.h"

using namespace std;

classic::classic()
{
    neighbor_count = 0;
    done = false;
    classicFilename = "test.txt";
    classicGeneration = 0;
}

classic::classic(string filename)
{
    neighbor_count = 0;
    done = false;
    classicFilename = filename;
    classicGeneration = 0;
}

// https://stackoverflow.com/questions/4184468/sleep-for-milliseconds/4184493
// This method would allow the program to sleep for certain seconds while running
void classic::sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end)
    {
    }
}

// A method to count the neighbor of a vell
void classic::checkNeighnorCount(grid &g, int count, int r, int c)
{
    //A location that has one or fewer neighbors will be empty in the next generation
    if(count < 2)
    {
        g.updateNewGrid(r, c, '-');
    }
    //A location with two neighbors remains stable
    else if(count == 2)
    {
        g.updateNewGrid(r, c, g.getMyGrid()[r][c]);
    }
    //A location with three neighbors will contain a cell in the next generation
    else if(count == 3)
    {
        g.updateNewGrid(r, c, 'X');
    }
    //A location with four or more neighbors will be empty in the next generation
    else if(count > 3)
    {
        g.updateNewGrid(r, c, '-');
    }
}

// The classic mode
void classic::classicMode(int mode, int in_row, int in_column, double in_density, int timeMode, string optFilename)
{
    // If the user chose to import a file, then we call the overwrite constructor from grid
    if(mode == 1)
    {
        grid g(classicFilename);
        g.createGrid();
        g.printGrid();
        g.printNewGrid();

        row = g.getRow();
        column = g.getCloumn();

        while (true)
        {
            int change_count = 0; //To check if the grid still changes

            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < column; ++j)
                {
                    neighbor_count = 0; //reset the neighbor count
                    //To check corner, only needs to check three neighbors
                    if ((i == 0 && j == 0))
                    {
                        if (g.getValueFromGrid(0, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, 0) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == 0 && j == column - 1)
                    {
                        if (g.getValueFromGrid(0, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == 0)
                    {
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == column - 1)
                    {
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    //Check the 4 borders
                    else if (i == 0 && j != 0 && j != column - 1)
                    {
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
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j != 0 && j != column - 1)
                    {
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
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
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == 0 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
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
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == column - 1 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
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
                        checkNeighnorCount(g, neighbor_count, i, j);
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
                        checkNeighnorCount(g, neighbor_count, i, j);
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
                cin.get(); //ends after the user hits enter
                break;
            }
            if(timeMode == 1)
            {
                sleepcp(3000);
            }
            else if(timeMode == 2)
            {
                cin.get();
            }
            else if(timeMode == 3)
            {
                g.writeNewToFile(optFilename, classicGeneration);
            }
            cout << "Generation " << ++classicGeneration << endl;
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
    // If the user chose to generate a random grid, then we would generate the grid using the information user inputs
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
                        if (g.getValueFromGrid(0, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, 0) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == 0 && j == column - 1)
                    {
                        if (g.getValueFromGrid(0, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == 0)
                    {
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j == column - 1)
                    {
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    //Check the 4 borders
                    else if (i == 0 && j != 0 && j != column - 1)
                    {
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
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (i == row - 1 && j != 0 && j != column - 1)
                    {
                        if (g.getValueFromGrid(i, j - 1) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i, j + 1) == 'X')
                        {
                            neighbor_count++;
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
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == 0 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
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
                        checkNeighnorCount(g, neighbor_count, i, j);
                        //check if chenged
                        if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                        {
                            change_count++;
                        }
                    }
                    else if (j == column - 1 && i != 0 && i != row - 1)
                    {
                        if (g.getValueFromGrid(i - 1, j) == 'X')
                        {
                            neighbor_count++;
                        }
                        if (g.getValueFromGrid(i + 1, j) == 'X')
                        {
                            neighbor_count++;
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
                        checkNeighnorCount(g, neighbor_count, i, j);
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
                        checkNeighnorCount(g, neighbor_count, i, j);
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
                sleepcp(3000);
            }
            else if (timeMode == 2)
            {
                //https://stackoverflow.com/questions/21257544/c-wait-for-user-input
                // Allow user to hit Enter to continue
                cin.get();
            }
            else if (timeMode == 3)
            {
                g.writeNewToFile(optFilename, classicGeneration);
            }
            cout << "Generation " << ++classicGeneration << endl;
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