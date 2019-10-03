#include "Grid.h"
#include "Classic.h"
#include "file.h"
#include "Doughnut.h"
#include "Mirror.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    bool run = true;
    while(run) //ask if they want file or random
    {
        string outputFilename = "";
        int boo;
        int option;
        cout << "Please choose an option: " << endl;
        cout << "1. Inport a file" << endl;
        cout << "2. Use random configeration" << endl;
        cin >> option;

        if(option != 1 && option!= 2)
        {
            cout << "Not an option!" << endl;
            exit(1);
        }

        int op;
        cout << "Please choose an output option: " << endl;
        cout << "1. Hold after each grid is printed " << endl;
        cout << "2. Print to an output file " << endl;
        cin >> op;

        if(op != 1 && op != 2)
        {
            cout << "Not an option!" << endl;
            exit(1);
        }

        if (op == 1)
        {
            boo = 0;
        }
        else if (op == 2)
        {
            boo = 1;
        }

        while(true)
        {
            if (option == 1) //ask for file
            {
                string file_name = "";
                cout << "Please enter file name: " << endl;
                cin >> file_name;
                file fileIn(file_name);
                fileIn.getFile();
                Grid grid1(fileIn.fileRow, fileIn.fileColumn, file_name);
                grid1.fileOp(file_name);

                //get the real filename from the input
                int dot;
                for(int i=0; i<file_name.length(); ++i)
                {
                    if(file_name[i] == '.')
                    {
                        dot = i;
                    }
                }
                outputFilename = file_name.substr(0, dot);

                int mode; // ask for what mode
                cout << "what mode do you want to play with? " << endl;
                cout << "1. Classic " << endl;
                cout << "2. Doughnut " << endl;
                cout << "3. Mirror " << endl;
                cin >> mode;

                if(mode != 1 && mode != 2 && mode != 3)
                {
                    cout << "Not an option!" << endl;
                    exit(1);
                }
                
                if (mode == 1) // classic mode
                {
                    while (true)
                    {
                        Classic classic(grid1.myGrid, fileIn.fileRow, fileIn.fileColumn);
                        classic.classicCheck(grid1.myNewGrid); //goes through neighbor rules
                        if (grid1.copy() == 0) //once stabilized loop ends
                        {
                            exit(1);
                        }
                        grid1.printGrid();
                        if(boo == 1)
                        {
                            grid1.writeToFile(outputFilename+"Out.txt");
                        }
                        
                        cout << "Difference: " << grid1.difference << endl; //to know if grid is stable
                        if(boo == 0)
                        {
                            cout << "Do you want to continue? Type Y to keep going. If not, press any key to leave." << endl;
                            string decision;
                            cin >> decision;
                            if (decision == "y" || decision == "Y") // continues in classic mode
                            {
                                continue;
                            }
                            else
                            {
                                exit(1);
                            }
                        }
                    }
                }
                else if (mode == 2) // doughtnut mode
                {

                    while (true)
                    {
                        Doughnut doughnut(grid1.myGrid, fileIn.fileRow, fileIn.fileColumn);
                        doughnut.doughnutCheck(grid1.myNewGrid); //checks new grid's neighbors
                        if (grid1.copy() == 0) // stops printing new grids if grid stabalizes
                        {
                            exit(1);
                        }
                        grid1.printGrid();
                        if (boo == 1)
                        {
                            grid1.writeToFile(outputFilename + "Out.txt");
                        }
                        cout << "Difference: " << grid1.difference << endl;
                        if (boo == 0)
                        {
                            cout << "Do you want to continue? Type Y to keep going. If not, press any key to leave." << endl;
                            string decision;
                            cin >> decision;
                            if (decision == "y" || decision == "Y") // continues in classic mode
                            {
                                continue;
                            }
                            else
                            {
                                exit(1);
                            }
                        }
                    }
                }
                else if (mode == 3) //mirror mode
                {
                    while (true)
                    {
                        Grid grid2(fileIn.fileRow + 2, fileIn.fileColumn + 2);
                        Mirror mirror(grid1.myGrid, grid2.myGrid, fileIn.fileRow, fileIn.fileColumn); //grid setup for mirror mode
                        grid1.printGrid();
                        grid2.printGrid();
                        mirror.setBigGrid(); //extra row and column
                        mirror.printBigGrid(); //print extra rows/columns
                        mirror.mirrorCheck(grid1.myNewGrid);
                        if (grid1.copy() == 0) //stops printing if grid is stable
                        {
                            exit(1);
                        }
                        grid1.printGrid(); //prints the grid
                        if (boo == 1)
                        {
                            grid1.writeToFile(outputFilename + "Out.txt");
                        }

                        cout << "Difference: " << grid1.difference << endl; // checks if grids are stable
                        if (boo == 0)
                        {
                            cout << "Do you want to continue? Type Y to keep going. If not, press any key to leave." << endl;
                            string decision;
                            cin >> decision;
                            if (decision == "y" || decision == "Y") // continues in classic mode
                            {
                                continue;
                            }
                            else
                            {
                                exit(1);
                            }
                        }
                    }
                }
                else
                {
                    cout << "Not an option, GOODBYE!!!!!!!!!!!!!!!!" << endl;
                    exit(1);
                }
                
            }
            else if (option == 2) // random configuration
            {
                int x;
                int y;
                double n;

                cout << "Enter Row: ";
                cin >> x;
                
                cout << "Enter Column: ";
                cin >> y;

                if(x<=0 || y<=0)
                {
                    cout << "Invalid input!!!!!" << endl;
                    exit(1);
                }

                //prompt for random configeration
                while (true)
                {
                    cout << "Please enter an number from 0 to 1: ";
                    cin >> n;

                    if (n < 0 || n > 1)
                    {
                        cout << "Pleae enter the right value!" << endl;
                    }
                    else
                    {
                        exit(1);
                    }
                }

                Grid grid1(x, y);
                grid1.randomGrid(n, grid1.myNewGrid);
                grid1.copy();
                grid1.printGrid();

                int mode; // asking what mode
                cout << "what mode do you want to play with? " << endl;
                cout << "1. Classic " << endl;
                cout << "2. Doughnut " << endl;
                cout << "3. Mirror " << endl;
                cin >> mode;

                if (mode != 1 && mode != 2 && mode != 3)
                {
                    cout << "Not an option!" << endl;
                    exit(1);
                }
                
                if (mode == 1) //classic mode
                {
                    
                    while (true)
                    {
                        Classic classic(grid1.myGrid, grid1.inRow, grid1.inColumn);
                        classic.classicCheck(grid1.myNewGrid); //checks neightbor rules
                        if (grid1.copy() == 0)
                        {
                            exit(1);
                        }
                        grid1.printGrid();
                        if (boo == 1)
                        {
                            grid1.writeToFile(outputFilename + "Out.txt");
                        }
                        //grid1.printNewGrid();
                        cout << "Difference: " << grid1.difference << endl;
                        if (boo == 0)
                        {
                            cout << "Do you want to continue? Type Y to keep going. If not, press any key to leave." << endl;
                            string decision;
                            cin >> decision;
                            if (decision == "y" || decision == "Y") // continues in classic mode
                            {
                                continue;
                            }
                            else
                            {
                                exit(1);
                            }
                        }
                    }
                }
                else if (mode == 2) //doughnut mode
                {
                    

                    while (true)
                    {
                        Doughnut doughnut(grid1.myGrid, grid1.inRow, grid1.inColumn);
                        doughnut.doughnutCheck(grid1.myNewGrid);//checks neighbor rules
                        if (grid1.copy() == 0) //grids stop printing once stabilized
                        {
                            exit(1);
                        }
                        grid1.printGrid();
                        if (boo == 1)
                        {
                            grid1.writeToFile(outputFilename + "Out.txt");
                        }

                        cout << "Difference: " << grid1.difference << endl; //number of differences, 0 means stable
                        if (boo == 0)
                        {
                            cout << "Do you want to continue? Type Y to keep going. If not, press any key to leave." << endl;
                            string decision;
                            cin >> decision;
                            if (decision == "y" || decision == "Y") // continues in classic mode
                            {
                                continue;
                            }
                            else
                            {
                                exit(1);
                            }
                        }
                    }
                }
                else if (mode == 3) // mirror mode
                {
                    while (true)
                    {
                        Grid grid2(grid1.inRow + 2, grid1.inColumn + 2);
                        Mirror mirror(grid1.myGrid, grid2.myGrid, grid1.inRow, grid1.inColumn); //mirror mode grid set up
                        grid1.printGrid();
                        grid2.printGrid();
                        mirror.setBigGrid(); //the extra rows and columns due to 'mirror walls'
                        mirror.printBigGrid(); //prints out the extra rows and columns
                        mirror.mirrorCheck(grid1.myNewGrid); //goes through neighbor rules
                        if (grid1.copy() == 0) // grids stop printing when 0
                        {
                            exit(1);
                        }
                        grid1.printGrid();
                        if (boo == 1)
                        {
                            grid1.writeToFile(outputFilename + "Out.txt");
                        }

                        cout << "Difference: " << grid1.difference << endl; //difference in each grid, 0 is stable
                        if (boo == 0)
                        {
                            cout << "Do you want to continue? Type Y to keep going. If not, press any key to leave." << endl;
                            string decision;
                            cin >> decision;
                            if (decision == "y" || decision == "Y") // continues in classic mode
                            {
                                continue;
                            }
                            else
                            {
                                exit(1);
                            }
                        }
                    }
                }
            }

            //enter Q or q to exit the program.
            string end = "";
            cout << "Press Q if you want to exit. " << endl;
            cin >> end;
            if (end == "q" || end == "Q")
            {
                return 0;
            }
            else
            {
                exit(1);
            }
        }
    }

    return 0;
}
