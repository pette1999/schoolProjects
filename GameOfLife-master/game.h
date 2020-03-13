#include <iostream>
#include "mirror.h"

using namespace std;

class game
{
public:
    game();

    int importmode;
    int gamemode;
    int gridRow;
    int gridColumn;
    int runTimemode;
    double gameDensity;
    string gameFilename;
    string outputFilename;

    void inputGridSize();
    void inputFilename();
    void inputGameMode();
    double inputDensity();
    void inputMode();
    void inputRunTime();
    void askOutputfileName();
    void gameStart();
};