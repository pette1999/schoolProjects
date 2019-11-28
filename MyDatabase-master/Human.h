#include "iostream"
#include <string>

using namespace std;

class Human
{
public:
    Human();
    Human(int id, string nam, string lev);
    ~Human();

    int getID();
    void setID(int id);

    string getName();
    void setName(string nam);

    string getLevel();
    void setLevel(string lev);

    //overloading operators
    bool operator>(Human *other);
    bool operator<(Human *other);
    bool operator==(Human *other);
    int operator<<(Human *h);

protected:
    int ID;
    string name;
    string level;
};