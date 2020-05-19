#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{

}

Faculty::Faculty(int id)
{
    faculty_Id = id;
}

Faculty::Faculty(int id, string name, string level, string department, DoublyLinkedList<int> list)
{
    faculty_Id = id;
    faculty_Name = name;
    faculty_Level = level;
    faculty_Department = department;
    list = list;
}

Faculty::~Faculty()
{

}

int Faculty::getFacultyId()
{
    return faculty_Id;
}

string Faculty::getFacultyName()
{
    return faculty_Name;
}

string Faculty::getFacultyLevel()
{
    return faculty_Level;
}

string Faculty::getFacultyDepartment()
{
    return faculty_Department;
}

void Faculty::getFacultyAdvisee()
{
    list.printList();
}

DoublyLinkedList<int> Faculty::getList()
{
    return list;
}

//overloads the operators to compare ids of each object
bool operator<(const Faculty &c1, const Faculty &c2)
{
    if (c1.faculty_Id < c2.faculty_Id)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(const Faculty &c1, const Faculty &c2)
{
    if (c1.faculty_Id > c2.faculty_Id)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(const Faculty &c1, const Faculty &c2)
{
    if (c1.faculty_Id != c2.faculty_Id)
    {
        return true;
    }
    else
    {
        return false;
    }
}