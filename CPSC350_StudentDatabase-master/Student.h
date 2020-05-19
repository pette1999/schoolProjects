#include <iostream>

using namespace std;

class Student
{
public:
    Student();
    Student(int id); //this constructor would allow easy search for students in tree
    Student(int id, string name, string level, string major, double gpa, int advisor);
    ~Student();

    int student_ID;
    string student_Name;
    string student_Level;
    string student_Major;
    double student_Gpa;
    int student_Advisor;

    int getStudentId();
    string getStudentName();
    string getStudentLevel();
    string getStudentMajor();
    double getStudentGpa();
    int getStudentAdvisor();
    void setAdvisor(int id);

    //used for overloading the operators to compare ids
    friend bool operator<(const Student &c1, const Student &c2);
    friend bool operator!=(const Student &c1, const Student &c2);
    friend bool operator>(const Student &c1, const Student &c2);
};