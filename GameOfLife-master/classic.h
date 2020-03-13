#include <iostream>
#include "grid.h"

using namespace std;

class classic
{
public:
    classic();
    classic(string filename);

    void sleepcp(int milliseconds);
    void checkNeighnorCount(grid &g, int count, int r, int c);
    void classicMode(int mode, int in_row, int in_column, double in_density, int timeMode, string optFilename);

    string classicFilename;
    int neighbor_count;
    int row;
    int column;
    bool done;
    int classicGeneration;
};