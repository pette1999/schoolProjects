#include <iostream>
#include <algorithm>
#include "Regist.h"

using namespace std;

Regist::Regist()
{
    window_Number = 0;
    available_window = 0;
    student_Count = 0;
    final_time = 0;
    fileName = "test.txt";
    line = "";
    wait_time_count = 0;
    total_idle_time = 0;
    idle_time_count = 0;

    ifstream inFile(fileName); //read the file
    if (!inFile)
    {
        cout << fileName << " does not exist. " << endl; //if the file does not exist, set hasFile to false
    }

    //GenQueue<Student> students;
    typedef GenQueue<Student> StudentQueue;
    StudentQueue students;
    StudentQueue waitlist;
    typedef GenQueue<int> StudentHeadCount;
    StudentHeadCount headCount; //count how many people come at certain time

    typedef DoublyLinkedList<int> WindowList;
    WindowList freeWindow; //show all free windows
    WindowList fullWindow; //show all full windows with the waiting time
    WindowList idleTime;
    WindowList workingTime;
}

Regist::Regist(string filename)
{
    window_Number = 0;
    available_window = 0;
    student_Count = 0;
    final_time = 0;
    fileName = filename;
    line = "";
    wait_time_count = 0;
    total_idle_time = 0;
    idle_time_count = 0;

    ifstream inFile(fileName); //read the file
    if (!inFile)
    {
        cout << fileName << " does not exist. " << endl; //if the file does not exist, set hasFile to false
    }
    //GenQueue<Student> students;
    typedef GenQueue<Student> StudentQueue;
    StudentQueue students;
    StudentQueue waitlist;
    typedef GenQueue<int> StudentHeadCount;
    StudentHeadCount headCount; //count how many people come at certain time

    typedef DoublyLinkedList<int> WindowList;
    WindowList freeWindow; //show all free windows
    WindowList fullWindow; //show all full windows with the waiting time
    WindowList idleTime;
    WindowList workingTime;
}

Regist::~Regist()
{

}

void Regist::readFile()
{
    inFile.open(fileName);
    // Get window numbers
    getline(inFile, line); //get the file line from the file
    window_Number = stoi(line);
    available_window = window_Number;

    for(int i=0; i<window_Number; ++i)
    {
        // free window with waiting time 0
        //currently fullWindow is 0
        freeWindow.insertFront(0);
        idleTime.insertBack(0);
    }

    // Get Students then put them in the queue
    while (getline(inFile, line))
    {
        //show arrive time of the students
        int arrive_time = stoi(line);
        // to get the the time when last student came in
        if(arrive_time > final_time)
        {
            final_time = arrive_time;
        }
        getline(inFile, line);
        int student_amount = stoi(line); //show how many students arrive at this time
        student_Count += student_amount;
        headCount.insert(student_amount);
        for (int i = 0; i < student_amount; ++i)
        {
            getline(inFile, line);
            int worktime = stoi(line);
            Student student(arrive_time, worktime, 0);
            students.insert(student);
        }
    }

    wait_time_array = new int[student_Count];
    for(int i=0; i<student_Count; ++i)
    {
        wait_time_array[i] = 0;
    }
}

void Regist::registar()
{
    // time starts at 1
    for(int i=0; i<final_time+10000; ++i)
    {
        // Check the holding time for all windows
        if (fullWindow.isEmpty())
        {
            //Do nothing
        }
        else
        {
            headCount.printQueue();
            ListNode<int> *curr = fullWindow.front;
            if (curr->data == 0)
            {
                int pos = fullWindow.find(0);
                fullWindow.remove(0);
                freeWindow.insertFront(0);
                available_window++;
                if(workingTime.getSize() > 1)
                {
                    idleTime.insertBack(workingTime.remove(0)->data);
                }
                else
                {
                    idleTime.insertBack(workingTime.removeFront());
                }
                if(waitlist.isEmpty() != true) //when waitlist is not empty
                {
                    freeWindow.removeFront();
                    fullWindow.insertBack(waitlist.peek().getWorkTime());
                    total_waiting_time += waitlist.peek().getWaitTime();
                    wait_time_array[wait_time_count] = waitlist.peek().getWaitTime();
                    wait_time_count++;
                    available_window--;
                    waitlist.remove(); //remove the student from the waitlist
                    workingTime.insertBack(idleTime.removeFront());
                }
                //run through the working_students and find out who is done
                //remove the student from the working list
            }
            while (curr->next != NULL)
            {
                curr = curr->next;
                if (curr->data == 0)
                {
                    int pos = fullWindow.find(0);
                    fullWindow.remove(0);
                    freeWindow.insertFront(0);
                    available_window++;
                    if (workingTime.getSize() > 1)
                    {
                        idleTime.insertBack(workingTime.remove(0)->data);
                    }
                    else
                    {
                        idleTime.insertBack(workingTime.removeFront());
                    }
                    if (waitlist.isEmpty() != true) //when waitlist is not empty
                    {
                        freeWindow.removeFront();
                        fullWindow.insertBack(waitlist.peek().getWorkTime());
                        total_waiting_time += waitlist.peek().getWaitTime();
                        wait_time_array[wait_time_count] = waitlist.peek().getWaitTime();
                        wait_time_count++;
                        available_window--;
                        waitlist.remove(); //remove the student from the waitlist
                        workingTime.insertBack(idleTime.removeFront());
                    }
                    //run through the working_students and find out who is done
                    //remove the student from the working list
                }
            }
        }

        if(i == students.peek().getClockTime())
        {
            cout << "There are " << headCount.peek() << " students come at time " << i << endl;


            // check if current windows can hold all students
            int students_coming = headCount.peek();
            // has more winows open than coming students, can handle the situation
            if (available_window >= (students_coming + waitlist.list.size))
            {
                for (int i = 0; i < (students_coming + waitlist.list.size); ++i)
                {
                    if(waitlist.isEmpty())
                    {
                        freeWindow.removeFront();
                        fullWindow.insertBack(students.peek().getWorkTime());
                        wait_time_array[wait_time_count] = 0;
                        wait_time_count++;
                        available_window--;
                        students.remove(); //remove the student from the list to the window
                        workingTime.insertBack(idleTime.removeFront());
                    }
                    else
                    {
                        freeWindow.removeFront();
                        fullWindow.insertBack(waitlist.peek().getWorkTime());
                        total_waiting_time += waitlist.peek().getWaitTime();
                        wait_time_array[wait_time_count] = waitlist.peek().getWaitTime();
                        wait_time_count++;
                        available_window--;
                        waitlist.remove(); //remove the student from the waitlist
                        workingTime.insertBack(idleTime.removeFront());
                    }
                }
            }
            else //has more coming students than available windows, which mean some students need to go to the waitlist
            {
                int remaining_number = students_coming + waitlist.list.size - available_window;
                // get all windows filled first
                for(int j=0; j<available_window; ++j)
                {
                    if (waitlist.isEmpty())
                    {
                        freeWindow.removeFront();
                        fullWindow.insertBack(students.peek().getWorkTime());
                        wait_time_array[wait_time_count] = 0;
                        wait_time_count++;
                        available_window--;
                        students.remove(); //remove the student from the list to the window
                        workingTime.insertBack(idleTime.removeFront());
                    }
                    else
                    {
                        freeWindow.removeFront();
                        fullWindow.insertBack(waitlist.peek().getWorkTime());
                        total_waiting_time += waitlist.peek().getWaitTime();
                        wait_time_array[wait_time_count] = waitlist.peek().getWaitTime();
                        wait_time_count++;
                        available_window--;
                        waitlist.remove(); //remove the student from the waitlist
                        workingTime.insertBack(idleTime.removeFront());
                    }
                }
                // get remaining students to the waitlist
                for(int k=0; k<remaining_number; ++k)
                {
                    waitlist.insert(students.remove());
                }
            }
            headCount.remove();
        }
        else
        {
            // Do nothing
        }
        if(fullWindow.isEmpty() == false)
        {
            ListNode<int> *curr2 = fullWindow.front;
            curr2->data -= 1;
            while (curr2->next != NULL)
            {
                curr2 = curr2->next;
                curr2->data -= 1;
            }
        }
        if(waitlist.isEmpty() == false)
        {
            ListNode<Student> *curr3 = waitlist.list.front;
            for (int m = 0; m < waitlist.list.size; ++m)
            {
                curr3->data.increaseWaitingTime();
                curr3 = curr3->next;
            }
        }
        if(idleTime.isEmpty() == false)
        {
            ListNode<int> *curr4 = idleTime.front;
            curr4->data += 1;
            while (curr4->next != NULL)
            {
                curr4 = curr4->next;
                curr4->data += 1;
            }
        }

        if(fullWindow.isEmpty())
        {
            break;
        }
    }
}

void Regist::stats()
{
    double meanWait = 0.0;
    double mediumWait = 0.0;
    int long_waittime = 0;
    int waittime_over_10 = 0;
    double meanIdle = 0.0;
    int long_idletime = 0;
    int idletime_over_5 = 0;
    meanWait = double(total_waiting_time)/student_Count;

    //Sort the array
    //https://www.geeksforgeeks.org/how-to-sort-an-array-using-stl-in-c/
    int n = student_Count;
    sort(wait_time_array, wait_time_array + n);

    if (n % 2 != 0)
    {
        mediumWait = (double)wait_time_array[n/2];
    }
    else
    {
        mediumWait = (double)(wait_time_array[(n-1)/2] + wait_time_array[n/2])/2.0;
    }
    

    for(int i=0; i<wait_time_count; ++i)
    {
        if(wait_time_array[i] > long_waittime)
        {
            long_waittime = wait_time_array[i];
        }
        if (wait_time_array[i] > 10)
        {
            waittime_over_10++;
        }
    }

    ListNode<int> *curr6 = idleTime.front;
    curr6->data -= 1;
    while (curr6->next != NULL)
    {
        curr6 = curr6->next;
        curr6->data -= 1;
    }

    int idleSum = 0;
    ListNode<int> *curr5 = idleTime.front;
    idleSum += curr5->data;
    if (curr5->data > long_idletime)
    {
        long_idletime = curr5->data;
    }
    if (curr5->data > 5)
    {
        idletime_over_5++;
    }
    while (curr5->next != NULL)
    {
        curr5 = curr5->next;
        idleSum += curr5->data;
        if (curr5->data > long_idletime)
        {
            long_idletime = curr5->data;
        }
        if (curr5->data > 5)
        {
            idletime_over_5++;
        }
    }

    meanIdle = (double)idleSum/window_Number;

    cout << "1. The mean student wait time:  " << meanWait << endl;
    cout << "2. The median student wait time:  " << mediumWait << endl;
    cout << "3. The longest student wait time:  " << long_waittime << endl;
    cout << "4. The number of students waiting over 10 minutes:  " << waittime_over_10 << endl;
    cout << "5. The mean window idle time:  " << meanIdle << endl;
    cout << "6. The longest window idle time:  " << long_idletime << endl;
    cout << "7. Number of windows idle for over 5 minutes:  " << idletime_over_5 << endl;
}