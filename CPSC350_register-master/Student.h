#include <iostream>

using namespace std;

class Student
{
public:
    Student();
    Student(int clocktime, int worktime, int waittime);
    ~Student();

    int getClockTime();
    int getWaitTime();
    int getWorkTime();
    string printStudent();
    void timePass();
    void increaseWaitingTime();

    int clockTime;
    int waitTime;
    int workTime;
};