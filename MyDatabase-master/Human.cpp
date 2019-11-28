#include "Human.h"
#include <iostream>

Human::Human()
{
    ID = 0;
    name = "N/A";
    level = "N/A";
}

Human::Human(int id, string nam, string lev)
{
    ID = id;
    name = nam;
    level = lev;
}

Human::~Human()
{
}

int Human::getID()
{
    return ID;
}

void Human::setID(int id)
{
    ID = id;
}

string Human::getName()
{
    return name;
}

void Human::setName(string nam)
{
    name = nam;
}

string Human::getLevel()
{
    return level;
}

void Human::setLevel(string lev)
{
    level = lev;
}

//operator overloading
bool Human::operator>(Human *other)
{
    return this->getID() > other->getID();
}

bool Human::operator<(Human *other)
{
    return this->getID() < other->getID();
}

bool Human::operator==(Human *other)
{
    return this->getID() == other->getID();
}

int Human::operator<<(Human *h)
{
    return h->ID;
}