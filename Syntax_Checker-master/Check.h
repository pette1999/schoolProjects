#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class Check
{
    public:
    Check();
    Check(string filename);

    char *delimiter;//array for collecting all the delimiters in the code source file
    int *lineNumber;//array for collecting the line number for each delimiter
    GenStack<char> myStack;//create a stack
    string fileName;
    string situation;
    string s_quote;
    int count;
    int dq_count;//to count the double quote number
    int sq_count;//to count the single quote number
    bool inDQuote;
    bool inSQuote;
    bool inComment;
    int lineNum;
    int mode;

    void pairMatch(char myarray[], int n);//check the pairs
    int getCount();//get the total count for the delimiters
    char* collect();
};