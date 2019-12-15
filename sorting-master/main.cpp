#include "inputFile.h"

using namespace std;

int main(int argc, char** argv)
{
    string fileName = "";

    if (argc > 1)
    {
        fileName = argv[1];
    }

    inputFile *i = new inputFile();
    i->getArray(fileName);
    i->calculateSortTime();

    return 0;
}