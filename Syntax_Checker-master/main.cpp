#include "Check.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string fileName = "";

    if (argc > 1)
    {
        fileName = argv[1];
    }

    Check check(fileName);
    check.pairMatch(check.collect(),check.getCount());

    return 0;
}