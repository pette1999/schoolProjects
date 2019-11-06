#include "GenQueue.h"
#include <iostream>


using namespace std;

class Student
{
public:
  Student();
  Student(int wait, int arrival, int line);
  ~Student();

  int getWaitTime();
  void setWaitTime( int k);
  void incWaitTime();

  int getLineLength();
  int setLineLength(int k);

  bool isWaitOverTen()l

  int arrivalTime();


};
