#include <iostream>

using namespace std;

class Mirror
{
    public:
    Mirror();
    Mirror(char** grid, char** bigGrid, int r, int c);

    void setBigGrid();
    void mirrorCheck(char** newGrid);
    void mirrorCheckNeighbor(int x, int y);
    void printBigGrid();

    int mirror_count;
    int mirrorRow;
    int mirrorColumn;
    char** mirrorGrid;
    char** mirrorBigGrid;
};