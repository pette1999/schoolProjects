#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
  waitTime =0;
  LineLength= 0;

}

Student::Student(int wait, int arrival, int line){
  waitTime = wait;
  arrivalTime = arrival;
  LineLength = line;
}

Student::~Student(){

}

int Student::getWaitTime(){
  return waitTime;
}

void Student::setWaitTime(int k){
  waitTime = k;
}

void Student::incWaitTime(){
  waitTime++;
}

int Student::getLineLength(){
  return LineLength;
}

void Student::setLineLength(int k){
  LineLength = k;
}

bool Student::isWaitOverTen(){
  return waitTime >10;
}
