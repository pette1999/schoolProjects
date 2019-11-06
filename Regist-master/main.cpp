#include "File.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  string fileName = "";

    if (argc > 1)
    {
        fileName = argv[1];
    }

    File red(fileName);
    red.readFile();
    red.get_timeList();
    red.get_waitingTimeList();
}
