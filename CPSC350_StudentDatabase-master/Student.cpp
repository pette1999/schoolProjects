#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{

}

Student::Student(int id)
{
    student_ID = id;
}

Student::Student(int id, string name, string level, string major, double gpa, int advisor)
{
    student_ID = id;
    student_Name = name;
    student_Level = level;
    student_Major = major;
    student_Gpa = gpa;
    student_Advisor = advisor;
}

Student::~Student()
{

}

int Student::getStudentId()
{
    return student_ID;
}

string Student::getStudentName()
{
    return student_Name;
}

string Student::getStudentLevel()
{
    return student_Level;
}

string Student::getStudentMajor()
{
    return student_Major;
}

double Student::getStudentGpa()
{
    return student_Gpa;
}

int Student::getStudentAdvisor()
{
    return student_Advisor;
}

void Student::setAdvisor(int id)
{
    student_Advisor = id;
}

bool operator<(const Student &c1, const Student &c2)
{
    if (c1.student_ID < c2.student_ID)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(const Student &c1, const Student &c2)
{
    if (c1.student_ID > c2.student_ID)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(const Student &c1, const Student &c2)
{
    if (c1.student_ID != c2.student_ID)
    {
        return true;
    }
    else
    {
        return false;
    }
}