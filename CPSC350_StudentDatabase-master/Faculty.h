#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

class Faculty
{
public:
    Faculty();
    Faculty(int id);
    Faculty(int id, string name, string level, string department, DoublyLinkedList<int> list);
    ~Faculty();

    int faculty_Id;
    string faculty_Name;
    string faculty_Level;
    string faculty_Department;

    // List to store all advisee
    typedef DoublyLinkedList<int> List;
    List list;

    int getFacultyId();
    string getFacultyName();
    string getFacultyLevel();
    string getFacultyDepartment();
    void getFacultyAdvisee();
    DoublyLinkedList<int> getList();

    friend bool operator<(const Faculty &c1, const Faculty &c2);
    friend bool operator>(const Faculty &c1, const Faculty &c2);
    friend bool operator!=(const Faculty &c1, const Faculty &c2);
};