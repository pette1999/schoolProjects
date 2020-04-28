#include <iostream>
#include <fstream>
#include "Student.h"
#include "GenQueue.h"

using namespace std;

class Regist
{
public:
    Regist();
    Regist(string filename);
    ~Regist();

    ifstream inFile; //read the input file
    string line;
    string fileName;
    int window_Number;
    int available_window;
    int student_Count;
    int final_time; // the last time that students come in
    int total_waiting_time;
    int wait_time_count;
    int *wait_time_array;

    int total_idle_time;
    int idle_time_count;

    typedef GenQueue<int> StudentHeadCount;
    StudentHeadCount headCount; //count how many people come at certain time

    typedef DoublyLinkedList<int> WindowList;
    WindowList freeWindow; //show all free windows
    WindowList fullWindow; //show all full windows with the waiting time
    WindowList idleTime;
    WindowList workingTime;
    // Create a type of GenQueue of Students for further use
    typedef GenQueue<Student> StudentQueue;
    // Create a queue of students
    StudentQueue students;
    StudentQueue waitlist; 
    //GenQueue<Student> students;

    // This method would read through the file, get windows numbers and create a queue of students using the data in the file
    void readFile();
    // Start the simulation
    void registar();
    void stats();
};