#include "GenBST.h"
#include <sys/stat.h> //for checking file stat
#include <fstream>
#include <iostream>

using namespace std;

class Table
{
    public:
    Table();
    ~Table();

    void showMenu();
};