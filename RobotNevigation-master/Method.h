#include <iostream>
#include "Grid.h"

using namespace std;

class Method
{
public:
    Method();
    ~Method();

    string fileName;
    int row;
    int column;
    int cost;
    int node;
    double euclideanDis;
    double manhattanDis;
    file f;
    Grid g;

    void moveEuclidean();
    void moveManhattan();
    void moveAstarEuclidean();
    void moveAstarManhattan();
    void askForFile();
    double getEuclideanDistance(int init_x, int init_y, int final_x, int final_y);
    double getManhattanDistance(int init_x, int init_y, int final_x, int final_y);
};