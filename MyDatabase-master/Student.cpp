#include <iostream>
#include "Student.h"

Student::Student()
{
    ID = 0;
    name = "N/A";
    level = "N/A";
    major = "N/A";
    GPA = 0;
    advisor = 0;
}

Student::Student(int id, string nam, string lev, string maj, double gpa, int aid)
{
    ID = id;
    name = nam;
    level = lev;
    major = maj;
    GPA = gpa;
    advisor = aid;
}

Student::~Student()
{
}

string Student::getMajor()
{
    return major;
}
void Student::setMajor(string maj)
{
    major = maj;
}

double Student::getGPA()
{
    return GPA;
}
void Student::setGPA(double gpa)
{
    GPA = gpa;
}

//operator overloading //not done
bool operator>(Student &stud1, Student &stud2)
{
    return (stud1.getID() > stud2.getID());
}
bool operator<(Student &stud1, Student &stud2)
{
    return (stud1.getID() < stud2.getID());
}
bool operator==(Student &stud1, Student &stud2)
{
    return (stud1.getID() == stud2.getID());
}
bool operator!=(Student &stud1, Student &stud2)
{
    return (stud1.getID() != stud2.getID());
}
bool operator>(Student &stud1, int i)
{
    return (stud1.getID() > i);
}
bool operator<(Student &stud1, int i)
{
    return (stud1.getID() < i);
}
bool operator==(Student &stud1, int i)
{
    return (stud1.getID() == i);
}
bool operator!=(Student &stud1, int i)
{
    return (stud1.getID() != i);
}

// void operator<<(const Student &stud1)
// {
//     cout << "ID: " << stud1.ID << " Name: " << stud1.name << " Level: " << stud1.level << " Major: " << stud1.major << " GPA: " << stud1.GPA << " Advisor ID: " << stud1.advisor;
//     return;
// }