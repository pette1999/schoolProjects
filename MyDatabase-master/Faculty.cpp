#include <iostream>
#include "Faculty.h"

Faculty::Faculty()
{
    ID = 0;
    name = "N/A";
    level = "N/A";
    department = "N/A";
    adviseIDs = new GenDoubleLL<int>();
}

Faculty::Faculty(int id, string nam, string lev, string dep)
{
    ID = id;
    name = nam;
    level = lev;
    department = dep;
    adviseIDs = new GenDoubleLL<int>();
}

Faculty::~Faculty()
{
    delete adviseIDs;
}

string Faculty::getDepartment()
{
    return department;
}
void Faculty::setDepartment(string dep)
{
    department = dep;
}

//operator overloading
bool operator>(Faculty &teach1, Faculty &teach2)
{
    return teach1.getID() > teach2.getID();
}
bool operator>(Faculty &teach1, int i)
{
    return teach1.getID() > i;
}
bool operator<(Faculty &teach1, Faculty &teach2)
{
    return teach1.getID() < teach2.getID();
}
bool operator<(Faculty &teach1, int i)
{
    return teach1.getID() < i;
}
bool operator==(Faculty &teach1, Faculty &teach2)
{
    return teach1.getID() == teach2.getID();
}
bool operator==(Faculty &teach1, int i)
{
    return teach1.getID() == i;
}
bool operator!=(Faculty &teach1, Faculty &teach2)
{
    return teach1.getID() != teach2.getID();
}
bool operator!=(Faculty &teach1, int i)
{
    return teach1.getID() != i;
}

bool Faculty::hasAdvise(int id)
{
    return adviseIDs->has(id);
}

void Faculty::addAdviseId(int id)
{
    adviseIDs->insertBack(id);
}

int Faculty::removeAdviseId(int id)
{
    return adviseIDs->remove(id);
}

bool Faculty::isAdviseEmpty()
{
    return adviseIDs->isEmpty();
}