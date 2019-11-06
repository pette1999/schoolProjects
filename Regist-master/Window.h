#include <iostream>
#include "Student.h"
using namespace std;

class Window{
public:
  Window();
  ~Window();

  Student* getStudent();
  void setStudent()(Student* s);
  Student* clearStudent();
  bool thereIsStudent();

  int getCurLineTime();
  void setCurLineTime(int k);
  void incCurLineTime();

  int waitingTime;
  void incWaitingTime();
};
