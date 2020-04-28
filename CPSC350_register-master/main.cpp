#include <iostream>
#include "Regist.h"

using namespace std;

int main(int argc, char *argv[])
{
    string fileName = "";

    if (argc > 1)
    {
        fileName = argv[1];
    }

    Regist r(fileName);
    r.readFile();
    r.registar();
    r.stats();
}