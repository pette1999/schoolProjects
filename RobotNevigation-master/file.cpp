#include "file.h"
#include <iostream>
#include <fstream>

using namespace std;

file::file()
{
    fileRow = 0;
    fileColumn = 0;
    fileName = "";
    line = "";
    fileName = "test.txt";
    ifstream inFile(fileName);
    // ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "Could not find file." << endl;
        exit(1); //if the file is not there, return an error
    }
}

file::file(string filename)
{
    fileRow = 0;
    fileColumn = 0;
    fileName = filename;
    line = "";
    fileName = filename;
    ifstream inFile(fileName);
    // ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "Could not find file." << endl;
        exit(1); //if the file is not there, return an error
    }
}

void file::getFile() //input file
{
    inFile.open(fileName);   //opens file
    getline(inFile, line);   //read the first line from the file, which is the row numebr
    fileRow = stoi(line);    //parse string to int
    fileColumn = fileRow; //parse string to ibnt
}

int file::getFileRow()
{
    return fileRow;
}

int file::getFileColumn()
{
    return fileColumn;
}