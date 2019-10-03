#include <iostream>

using namespace std;

class Doughnut
{
    public:
    Doughnut();
    Doughnut(char **grid, int r, int c);

    void doughnutCheck(char** newGrid);
    void doughnutCheckNeighbor(int x, int y);
    char** returnDoughnutGrid();

    int doughnut_count;
    int doughnutRow;
    int doughnutColumn;
    char** doughnutGrid;
};