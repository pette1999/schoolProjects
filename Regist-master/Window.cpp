#include "GenQueue.h"
#include "GenDoubleLL.h"
#include "Student.h"
#include "Window.h"
#include <iostream>

using namespace std;

Window::Window() {
  curLineTime =0;
  waitingTime =0;
  curStud = NULL;
}
Window::~Window(){
  clearStudent();
}

Student* Window::getStudent(){ //pointer to student to get num of students
  return curStud;
}

void Window::setStudent(Student* s){ //pointer to students, s
  curStud = s
}

Student* Window::clearStudent(){ //delete the student node
  Student* temp(curStud); //a temp to
  curStud =NULL //if there are no more current students, node points to null
  curLineTime = 0; //no time in line since no students
  return temp
}

bool Window::hasStudent(){
  return curStud != NULL; //if there are students
}

int Window::getCurLineTime(){
  return curLineTime
}

void Window::setCurLineTime(int k){
  CurLineTime = k;
}
void Window::incCurLineTime(){
  curLineTime++; //increase line time by one
}
void Window::incWaitingTime(){
  waitingTime++; //the waiting time increases
}
