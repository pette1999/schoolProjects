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
}

file::file(string filename)
{
    fileRow = 0;
    fileColumn = 0;
    fileName = filename;
    line = "";
    ifstream inFile(fileName);
}

void file::getFile() //input file
{
    //ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "Could not find file." << endl;
        exit(1); //if the file is not there, return an error
    }
    inFile.open(fileName);   //opens file
    getline(inFile, line);   //read the first line from the file, which is the row numebr
    fileRow = stoi(line);    //parse string to int
    getline(inFile, line);   //read the second line of the file, which is the column
    fileColumn = stoi(line); //parse string to ibnt
}
