#include <iostream>
#include "game.h"

using namespace std;

game::game()
{
    importmode = -1;
    gamemode = -1;
    gridRow = 0;
    gridColumn = 0;
    gameFilename = "";
    gameDensity = 0.0;
}

// Ask the user to input the grid size
void game::inputGridSize()
{
    string r = "";
    string c = "";

    while(true)
    {
        cout << "Please input the gird size: " << endl;
        cout << "Row: ";
        cin >> r;
        cout << "Column: ";
        cin >> c;

        // change string type to int type
        gridRow = stoi(r);
        gridColumn = stoi(c);

        // to check if the input grid size is negative number
        if(gridRow > 0 && gridColumn > 0)
        {
            break;
        }
        else
        {
            cout << "You can't have negative grid size, please input again. " << endl;
            continue;
        }
    }

    cout << "Your random grid is: " << gridRow << " X " << gridColumn << endl;
}

// Input input filename
void game::inputFilename()
{
    cout << "Please input the filename here: ";
    cin  >> gameFilename;
}

// Let the user choose the game mode
void game::inputGameMode()
{
    string i = "";

    while (true)
    {
        cout << "What game mode do you want to choose? " << endl;
        cout << "1) Classic Mode " << endl;
        cout << "2) Doughnut Mode " << endl;
        cout << "3) Mirror Mode " << endl;

        cin >> i;

        if (i == "1")
        {
            gamemode = 1;
            break;
        }
        else if (i == "2")
        {
            gamemode = 2;
            break;
        }
        else if (i == "3")
        {
            gamemode = 3;
            break;
        }
        else
        {
            cout << "Wrong option, Please try again.\n" << endl;
            continue;
        }
    }
}

// Let the user to input the density
double game::inputDensity()
{
    string i = "";

    while(true)
    {
        cout << "Please input the density for your grid:  ";

        cin >> i;

        if (atof(i.c_str()) > 0 && atof(i.c_str()) < 1)
        {
            gameDensity = atof(i.c_str());
            break;
        }
        else
        {
            cout << "Invalid input value, Please try again.\n" << endl;
            continue;
        }
    }
}

// Let the user to choose the import mode
void game::inputMode()
{
    string i = "";

    while(true)
    {
        cout << "How do you want to generate the grid? " << endl;
        cout << "1) Import a file " << endl;
        cout << "2) Generate a random grid " << endl;

        cin >> i;

        if (i == "1")
        {
            importmode = 1;
            break;
        }
        else if (i == "2")
        {
            importmode = 2;
            break;
        }
        else
        {
            cout << "Wrong option, Please try again.\n" << endl;
            continue;
        }
        
    }
}

// Let user to input the ourfile filename
void game::askOutputfileName()
{
    cout << "Please give a name for you output file: ";
    cin >> outputFilename;
}

// Let the user to choose how to dislay the results
void game::inputRunTime()
{
    string i = "";

    while (true)
    {
        cout << "How do you want to display the grid:  " << endl;
        cout << "1) A brief pause between generations " << endl;
        cout << "2) Press “Enter” to display the next generation " << endl;
        cout << "3) Output everything to a file" << endl;
        
        cin >> i;

        if (i == "1")
        {
            runTimemode = 1;
            break;
        }
        else if (i == "2")
        {
            runTimemode = 2;
            break;
        }
        else if (i == "3")
        {
            runTimemode = 3;
            askOutputfileName();
            break;
        }
        else
        {
            cout << "Wrong option, Please try again.\n" << endl;
            continue;
        }
    }
}

// The actual game
void game::gameStart()
{
    inputMode();
    if(importmode == 1)
    {
        inputFilename();
        inputGameMode();
        inputRunTime();
        if (gamemode == 1)
        {
            classic c(gameFilename);
            c.classicMode(1, 0, 0, 0, runTimemode, outputFilename);
        }
        else if(gamemode == 2)
        {
            doughnut d(gameFilename);
            d.doughnutMode(1, 0, 0, 0, runTimemode, outputFilename);
        }
        else if(gamemode == 3)
        {
            mirror m(gameFilename);
            m.mirrorMode(1, 0, 0, 0, runTimemode, outputFilename);
        }
    }
    else if(importmode == 2)
    {
        inputGridSize();
        inputDensity();
        inputGameMode();
        inputRunTime();
        if (gamemode == 1)
        {
            classic c;
            c.classicMode(2, gridRow, gridColumn, gameDensity, runTimemode, outputFilename);
        }
        else if (gamemode == 2)
        {
            doughnut d;
            d.doughnutMode(2, gridRow, gridColumn, gameDensity, runTimemode, outputFilename);
        }
        else if (gamemode == 3)
        {
            mirror m;
            m.mirrorMode(2, gridRow, gridColumn, gameDensity, runTimemode, outputFilename);
        }
    }
}