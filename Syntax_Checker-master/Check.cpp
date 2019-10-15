#include "Check.h"
#include <iostream>
#include <fstream>

using namespace std;

Check::Check()
{
    fileName = "";
    count = 0;
    dq_count = 0;
    sq_count = 0;
    inDQuote = false;
    inSQuote = false;
    inComment = false;
    s_quote = "'";
    lineNum = 1;
    mode = 0;
}

Check::Check(string filename)
{
    fileName = filename;
    count = 0;
    dq_count = 0;
    sq_count = 0;
    inDQuote = false;
    inSQuote = false;
    inComment = false;
    s_quote = "'";
    lineNum = 1;
    mode = 0;
}

char* Check::collect()
{
    //Declare an input file stream
    ifstream inFile;
    char c;           //each cahr in each string
    string line = ""; //declare a string variable for each line of teh file

    if (!inFile)
    {
        cout << "there are some problems.";
        exit(1); //if the file is not there, return an error
    }

    inFile.open(fileName);//open the file
    while(getline(inFile, line)) //while there is a line in the file
    {
        inComment = false;
        mode = 0;
        //we count for the total delimiters in the file
        for(char c : line)//go through every single letter in the line
        {
            if(mode == 0)
            {
                if (c == '(' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    count++;
                }
                else if (c == ')' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    count++;
                }
                else if (c == '{' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    count++;
                }
                else if (c == '}' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    count++;
                }
                else if (c == '[' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    count++;
                }
                else if (c == ']' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    count++;
                }
                else if (c == '"')//if the position has " , then we count the total number of quotes
                {
                    ++dq_count;
                    if (dq_count % 2 == 1)//if the quote number is odd, then we know that we are in the quote section
                    {
                        inDQuote = true;
                    }
                    else if (dq_count % 2 == 0)
                    {
                        inDQuote = false;
                    }
                }
                else if (c == '\'') //check if it is single quote
                {
                    ++sq_count;
                    if (sq_count % 2 == 1)
                    {
                        inSQuote = true;
                    }
                    else if (sq_count % 2 == 0)
                    {
                        inSQuote = false;
                    }
                }
                //if we detect a /, then we assume that we are in a comment, so we skip the line, go to the rest of the file
                else if (c == '/' && inDQuote == false && inSQuote == false)
                {
                    inComment = true;
                    mode = 1;
                }
            }
            else
            {
                continue;
            }
            
        }
    }

    inFile.close();//clse reading the file

    delimiter = new char[count];//we create an array with lengh of total count of delimiters
    lineNumber = new int[count];//we create an array for the line number of each delimiter in the file
    int loop_count = 0;

    inFile.open(fileName);        //open the file
    while (getline(inFile, line)) //while there is a line in the file
    {
        inComment = false;
        mode = 0;
        for (char c : line)
        {
            if(mode == 0)
            {
                if (c == '(' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    delimiter[loop_count] = '(';
                    lineNumber[loop_count] = lineNum;
                    ++loop_count;
                }
                else if (c == ')' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    delimiter[loop_count] = ')';
                    lineNumber[loop_count] = lineNum;
                    ++loop_count;
                }
                else if (c == '{' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    delimiter[loop_count] = '{';
                    lineNumber[loop_count] = lineNum;
                    ++loop_count;
                }
                else if (c == '}' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    delimiter[loop_count] = '}';
                    lineNumber[loop_count] = lineNum;
                    ++loop_count;
                }
                else if (c == '[' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    delimiter[loop_count] = '[';
                    lineNumber[loop_count] = lineNum;
                    ++loop_count;
                }
                else if (c == ']' && inDQuote == false && inSQuote == false && inComment == false)
                {
                    delimiter[loop_count] = ']';
                    lineNumber[loop_count] = lineNum;
                    ++loop_count;
                }
                else if (c == '"')
                {
                    ++dq_count;
                    if (dq_count % 2 == 1)
                    {
                        inDQuote = true;
                    }
                    else if (dq_count % 2 == 0)
                    {
                        inDQuote = false;
                    }
                }
                else if (c == '\'') //check if it is single quote
                {
                    ++sq_count;
                    if (sq_count % 2 == 1)
                    {
                        inSQuote = true;
                    }
                    else if (sq_count % 2 == 0)
                    {
                        inSQuote = false;
                    }
                }
                else if (c == '/' && inDQuote == false && inSQuote == false)
                {
                    inComment = true;
                    mode = 1;
                }
            }
            else
            {
                continue;
            }
        }
        lineNum++;
    }

    cout << "Delimiter Count: " << count << endl;

    return delimiter;//return the array contians all teh delimiters in the file
}

//teh method to compare the pairs
void Check::pairMatch(char myarray[], int n)
{
    if(n%2 == 0)//if the file contains even delimiters, then if there is an unmatch, we have a wrong symbol
    {
        situation = "Wrong symbol";
    }
    else if(n%2 == 1)//if the file contains odd delimiters, then if there is an unmatch, we have a missing symbol
    {
        situation = "Missing symbol";
    }

    GenStack<char> myStack(n);//create a new stack with length n

    for(int i=0; i<n; i++)
    {
        //run through every single element in the array, if it's an opening symbol, we push it to teh stack
        if (myarray[i] == '(' || myarray[i] == '{' || myarray[i] == '[')
        {
            myStack.push(myarray[i]);
        }
        else if (myarray[i] == ')')//if it's a closing symbol, then we need to do some checking
        {
            if (myStack.isEmpty())//check if the stack is empty, if it's empty, means there is something missing here
            {
                cout << "Error: Missing ( at line " << lineNumber[i] << endl;
                exit(0);
            }
            else
            {
                if (myStack.peek() != '(')
                {
                    if (situation == "Wrong simble")
                    {
                        cout << "there is something wrong with your simble." << endl;
                        exit(0);
                    }
                    else if (situation == "Missing simble")
                    {
                        cout << "You missed a simble at line " << lineNumber[i] << " " << endl;
                        exit(0);
                    }
                }
            }
            myStack.pop();//pop the element from the stack if it matches
        }
        else if (myarray[i] == '}')
        {
            if (myStack.isEmpty())
            {
                cout << "Error: Missing { at line " << lineNumber[i] << endl;
                exit(0);
            }
            else
            {
                if (myStack.peek() != '{')
                {
                    if (situation == "Wrong simble")
                    {
                        cout << "there is something wrong with your simble." << endl;
                        exit(0);
                    }
                    else if (situation == "Missing simble")
                    {
                        cout << "You missed a simble at line " << lineNumber[i] << " " << endl;
                        exit(0);
                    }
                }
            }
            myStack.pop();
        }
        else if (myarray[i] == ']')
        {
            if (myStack.isEmpty())
            {
                cout << "Error: Missing [ at line " << lineNumber[i] << endl;
                exit(0);
            }
            else
            {
                if (myStack.peek() != '[')
                {
                    if (situation == "Wrong simble")
                    {
                        cout << "there is something wrong with your simble." << endl;
                        exit(0);
                    }
                    else if (situation == "Missing simble")
                    {
                        cout << "You missed a simble at line " << lineNumber[i] << " " << endl;
                        exit(0);
                    }
                }
            }
            myStack.pop();
        }
    }
    if(myStack.isEmpty())//in the end, if the stack is empty, then everything matches
    {
        cout << "Everything matches. " << endl;
    }
    else//if there is still something in the stack, means we have missed a symbol
    {
        if(myStack.peek() == '(')
        {
            cout << "Reached end of file: Missing )" << endl;
            exit(0);
        }
        else if (myStack.peek() == '{')
        {
            cout << "Reached end of file: Missing }" << endl;
            exit(0);
        }
        else if (myStack.peek() == '[')
        {
            cout << "Reached end of file: Missing ]" << endl;
            exit(0);
        }
    }
    
}

int Check::getCount()
{
    return count;
}