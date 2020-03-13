#include <iostream>
#include "classic.h"

using namespace std;

class doughnut
{
public:
    doughnut();
    doughnut(string filename);

    void doughnutMode(int mode, int in_row, int in_column, double in_density, int timeMode, string optFilename);

    string doughnutFilename;
    int neighbor_count;
    int row;
    int column;
    bool done;
    int doughnutGeneration;
};