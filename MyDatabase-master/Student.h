#include <iostream>
#include <string>
#include "Human.h"

using namespace std;

class Student : public Human
{
private:
    string major;
    double GPA;

public:
    Student();
    Student(int id, string nam, string lev, string maj, double gpa, int aid); //student ID, name ,level major, GPA, and advisor id
    ~Student();

    string getMajor();
    void setMajor(string maj);

    double getGPA();
    void setGPA(double gpa);

    int getAdvisor();
    void setAdvisor(int aid);

    //externally declared operator
    friend bool operator>(Student &stud1, Student &stud2);
    friend bool operator<(Student &stud1, Student &stud2);
    friend bool operator==(Student &stud1, Student &stud2);
    friend bool operator!=(Student &stud1, Student &stud2);
    friend bool operator>(Student &stud1, int i);
    friend bool operator<(Student &stud1, int i);
    friend bool operator==(Student &stud1, int i);
    friend bool operator!=(Student &stud1, int i);
    // friend operator<<(const Student &stud1);

    int advisor;
};