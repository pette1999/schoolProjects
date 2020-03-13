#include <iostream>
#include "file.h"

using namespace std;

file::file()
{
    fileName = "test.txt";
    ifstream inFile(fileName);//read the file
    line = "";
    int fileRow = 0;
    int fileCloumn = 0;

    if (!inFile)
    {
        cout << fileName << " does not exist. " << endl;
        exit(1);
    }
}

file::file(string filename)
{
    fileName = filename;
    ifstream inFile(fileName); //read the file
    line = "";
    int fileRow = 0;
    int fileCloumn = 0;

    if (!inFile)
    {
        cout << fileName << " does not exist. " << endl;
        exit(1);
    }
}

void file::readFile()
{
    inFile.open(fileName);
    getline(inFile,line); //get the file line from the file
    fileRow = stoi(line); //transform the string to int
    getline(inFile,line);
    fileColumn = stoi(line);
}

// void file::printFile()
// {
//     inFile.open(fileName);
//     cout << "File: " << endl;
//     while (getline(inFile, line)) //while there is a line in the file
//     {
//         cout << line << endl;
//     }
//     inFile.close();
// }

int file::getRow()
{
    return fileRow;
}

int file::getCloumn()
{
    return fileColumn;
}

//Grd part
void file::createGrid()
{
    readFile();
    myGrid = new char *[fileRow]; //create a 1-D array

    for (int i = 0; i < fileRow; ++i)
    {
        myGrid[i] = new char[fileColumn]; //for each position in the 1-D array, we create another array in there
    }

    //Set default grid
    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            myGrid[i][j] = '-';
        }
    }

    //Set Grid
    //Don't need to read the file again, because I never closed reading the file in readFile()
    for (int i = 0; i < fileRow; ++i)
    {
        getline(inFile, line);
        int lineLength = line.length();
        for (int j = 0; j < fileColumn; ++j)
        {
            myGrid[i][j] = line[j];
        }
    }
}

void file::printGrid()
{
    cout << "My Grid: " << endl;
    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            cout << myGrid[i][j] << " ";
        }
        cout << "\n";
    }
}