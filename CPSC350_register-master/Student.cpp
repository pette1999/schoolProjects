#include <iostream>
# include "Student.h"

using namespace std;

Student::Student()
{

}

Student::Student(int clocktime, int worktime, int waittime)
{
    clockTime = clocktime;
    workTime = worktime;
    waitTime = waittime;
}

Student::~Student()
{
    
}

int Student::getClockTime()
{
    return clockTime;
}

int Student::getWorkTime()
{
    return workTime;
}

int Student::getWaitTime()
{
    return waitTime;
}

void Student::timePass()
{
    waitTime--;
}

string Student::printStudent()
{
    string output = "";
    string temp = "";
    output += "==============\n";
    temp = "Clock Time: " + to_string(clockTime) + "\n";
    output += temp;
    temp = "Work Time: " + to_string(workTime) + "\n";
    output += temp;
    temp = "Wait Time: " + to_string(waitTime) + "\n";
    output += temp;
    output += "==============";

    return output;
}

void Student::increaseWaitingTime()
{
    waitTime++;
}