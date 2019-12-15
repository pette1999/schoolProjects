#include "inputFile.h"

using namespace std;

inputFile::inputFile()
{
    quickSortArray = new double[10];
    insertionSortAray = new double[10];
    bubbleSortArray = new double[10];
    cycleSortArray = new double[10];
}

inputFile::~inputFile()
{
    delete quickSortArray;
    delete insertionSortAray;
    delete bubbleSortArray;
    delete cycleSortArray;
}

void inputFile::getArray(string fileName)
{
    string line = "";
    if (!inFile)
    {
        cout << "there are some problems.";
        exit(1); //if the file is not there, return an error
    }
    inFile.open(fileName);
    getline(inFile, line);

    arrSize = atof(line.c_str());

    quickSortArray = new double[(int)atof(line.c_str())];
    insertionSortAray = new double[(int)atof(line.c_str())];
    bubbleSortArray = new double[(int)atof(line.c_str())];
    cycleSortArray = new double[(int)atof(line.c_str())];

    int count = 0;
    while(getline(inFile, line))
    {
        quickSortArray[count] = atof(line.c_str());
        insertionSortAray[count] = atof(line.c_str());
        bubbleSortArray[count] = atof(line.c_str());
        cycleSortArray[count] = atof(line.c_str());
        count += 1;
    }

    inFile.close();
}

void inputFile::calculateSortTime()
{
    SortAlgorithm<double> s;
    time_t b1;
    s.quickSort(quickSortArray, 0, arrSize-1);
    time_t a1;

    time_t b2;
    s.insertionSort(insertionSortAray, arrSize);
    time_t a2;

    time_t b3;
    s.bubbleSort(bubbleSortArray, arrSize);
    time_t a3;

    time_t b4;
    s.cycleSort(cycleSortArray, arrSize);
    time_t a4;

    cout << endl;
    cout << "QuickSort: " << endl;
    cout << "Time started: " << b1 << endl;
    cout << "Time ended: " << a1 << endl;
    cout << "Time difference: " << -(double)difftime(a1, b1) << endl;
    cout << endl;

    cout << "Insertion Sort" << endl;
    cout << "Time started: " << b2 << endl;
    cout << "Time ended: " << a2 << endl;
    cout << "Time difference: " << -(double)difftime(a2, b2) << endl;
    cout << endl;

    cout << "bubble Sort" << endl;
    cout << "Time started: " << b3 << endl;
    cout << "Time ended: " << a3 << endl;
    cout << "Time difference: " << -(double)difftime(a3, b3) << endl;
    cout << endl;

    cout << "Cycle Sort" << endl;
    cout << "Time started: " << b4 << endl;
    cout << "Time ended: " << a4 << endl;
    cout << "Time difference: " << -(double)difftime(a4, b4) << endl;
    cout << endl;
}