#include <iostream>
#include <fstream>
#include <time.h>
#include "SortAlgorithm.h"
using namespace std;

class inputFile
{
    public:
    inputFile();
    ~inputFile();

    ifstream inFile;

    int arrSize;

    double *quickSortArray;
    double *insertionSortAray;
    double *bubbleSortArray;
    double *cycleSortArray;

    string removeSpace(string str);
    void getArray(string fileName);
    void calculateSortTime();
};