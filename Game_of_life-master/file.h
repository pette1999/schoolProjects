#include <iostream>
#include <fstream>

using namespace std;

class file
{
    public:
        file();
        file(string filename);

        void getFile();
        ifstream inFile;
        int fileRow;
        int fileColumn;
        string fileName;
        string line;
};