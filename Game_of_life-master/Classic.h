#include <iostream>

using namespace std;

class Classic
{
    public:
    Classic();
    Classic(char** grid,int r,int c);

    void classicCheck(char** newGrid);
    void classicCheckNeighbor(int x,int y);


    int classic_count;
    int classicRow;
    int classicColumn;
    char **classicGrid;
};