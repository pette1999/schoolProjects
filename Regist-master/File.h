#include "GenDoubleLL.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

class File
{
  public:
  File(string fileName); //default constructor
  ~File(); //destructor

  void readFile();
  void get_timeList();
  void get_waitingTimeList();

  string filename;
  int num_window;
  int num_student;
  int time;
  int current_student_num;
  bool is_time;
  bool is_student_num;
  bool is_waiting_time;

  GenDoubleLL<int> timeList;
  GenDoubleLL<int> waitingTimeList;
};

File::File(string fileName)
{
  filename = fileName;
  num_window = 0;
  num_student = 0;
  time = -1;
  current_student_num = 0;
  is_time = true;
  is_student_num = false;
  is_waiting_time = false;
}

File::~File()
{

}

void File::readFile()
{
  ifstream inFile;
  char c;           //each cahr in each string
  string line = ""; //declare a string variable for each line of teh file

  if (!inFile)
  {
      cout << "there are some problems.";
      exit(1); //if the file is not there, return an error
  }

  inFile.open(filename);//open the file
  getline(inFile, line);
  stringstream geek(line);
  geek >> num_window;

  while(getline(inFile, line)) //while there is a line in the file
  {
    int temp_num = 0;
    stringstream geek(line);
    geek >> temp_num;

    if(is_time)
    {
      time = temp_num;
      timeList.insertBack(time);
      is_time = false;
      is_student_num = true;
    }
    else if(is_student_num)
    {
      num_student += temp_num;
      current_student_num = temp_num;
      is_student_num = false;
      is_waiting_time = true;
    }
    else if(is_waiting_time)
    {
      waitingTimeList.insertBack(temp_num);
      current_student_num--;
      if(current_student_num <= 0)
      {
        is_waiting_time = false;
        is_time = true;
      }
    }
  }
  inFile.close();
}

void File::get_timeList()
{
  cout << "timeList: " << endl;
  timeList.printList();
}

void File::get_waitingTimeList()
{
  cout << "waitingTimeList: " << endl;
  waitingTimeList.printList();
}
