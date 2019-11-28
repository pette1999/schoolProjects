#include <iostream>
#include <string>
#include "GenDoubleLL.h"
#include "Student.h"

using namespace std;

class Faculty : public Human
{
private:
    string department;

public:
    Faculty();
    Faculty(int id, string nam, string lev, string dep); //ID, name, level, and departmen
    ~Faculty();

    string getDepartment();
    void setDepartment(string dep);
    bool hasAdvise(int id);

    GenDoubleLL<int> *adviseIDs;
    void addAdviseId(int id);
    int removeAdviseId(int id);
    bool isAdviseEmpty();

    //operators overloading
    friend bool operator>(Faculty &stud1, Faculty &stud2);
    friend bool operator>(Faculty &stud1, int i);
    friend bool operator<(Faculty &stud1, Faculty &stud2);
    friend bool operator<(Faculty &stud1, int i);
    friend bool operator==(Faculty &stud1, Faculty &stud2);
    friend bool operator==(Faculty &stud1, int i);
    friend bool operator!=(Faculty &stud1, Faculty &stud2);
    friend bool operator!=(Faculty &stud1, int i);
};