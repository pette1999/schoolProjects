#include <iostream>

using namespace std;

class Window
{
public:
    Window();
    Window(int timeperiod);
    ~Window();

    int holdTime; //time that is holding students
    bool isOpen; //check if the window is available

    int getHoldTime();
    bool getIsOpen();
};