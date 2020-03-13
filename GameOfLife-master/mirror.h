#include <iostream>
#include "doughnut.h"

using namespace std;

class mirror
{
public:
    mirror();
    mirror(string filename);

    void mirrorMode(int mode, int in_row, int in_column, double in_density, int timeMode, string optFilename);

    string mirrorFilename;
    int neighbor_count;
    int row;
    int column;
    bool done;
    int mirrorGeneration;
};