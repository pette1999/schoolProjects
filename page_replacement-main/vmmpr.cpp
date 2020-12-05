#include <queue>
#include <unordered_set>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

//reference https://www.slader.com/discussion/question/write-a-program-that-implements-the-fifo-lru-and-optimal-page-replacement/
//reference: got help from Gabriela Pinto

#define NUM_PAGES 3

int pageTable[NUM_PAGES];
int tlbIdx = 0;

//FIFO replacement
//reference https://www.slader.com/discussion/question/write-a-program-that-implements-the-fifo-lru-and-optimal-page-replacement/
int fifo(char *pages[])
{
  //a set of the set values in the page table that are easily searchable
  //http://www.cplusplus.com/reference/unordered_set/unordered_set/
  unordered_set<int> set;
  //the page table
  queue<int> pageTable;
  int pageFaults = 0;

  for (int i = 0; i < strlen(pages[1]); i += 2)
  {

    if (set.size() < NUM_PAGES)
    {
      if (set.find(pages[1][i]) == set.end())
      {
        set.insert(pages[1][i]);
        pageFaults++;
        pageTable.push(pages[1][i]);
      }
    }
    else
    {
      if (set.find(pages[1][i]) == set.end())
      {
        // get the front
        char front = pageTable.front();
        pageTable.pop();
        set.erase(front);
        set.insert(pages[1] [i]);
        pageTable.push(pages[1][i]);
        pageFaults++;
      }
    }
  }

  return pageFaults;
}

//optimal page replacement
//reference: got help from Gabriela Pinto
int optimal(char *pages[])
{
  vector<int> pageTable;
  int pageFaults = 0;

  for (int i = 0; i < strlen(pages[1]); i += 2)
  {
    for (int j = 0; j < pageTable.size(); j++)
    {
      if (pages[1][i] == pageTable[j])
      {
        continue;
      }
    }
    //not found in page table, so add to pageFaults
    pageFaults++;

    if (pageTable.size() < 3)
    {
      pageTable.push_back(pages[1][i]);
    }
    else
    {
      // To find which page to delete for optimal replacement
      int del = 0;
      int n1 = -1;
      int n2 = -1;
      for (int j = i; j < strlen(pages[1]); j += 2)
      {
        for (int i = 0; i < pageTable.size(); i++)
        {
          if (pages[1][j] == pageTable[i])
          {
            if (n1 == -1)
              n1 = pages[1][j];
            else
            {
              n2 = pages[1][j];
              break;
            }
          }
        }
      }
      for (int k = 0; k < pageTable.size(); k++)
      {
        if (pageTable[k] == n1)
          continue;
        else if (pageTable[k] == n2)
          continue;
        else
          del = pageTable[k];
      }

      for (int j = 0; j < pageTable.size(); j++)
      {
        if (pageTable[j] == del)
          pageTable[j] = pages[1][i];
      }
    }
  }
  return pageFaults;
}

//LRU
//reference: worked with Gabriela Pinto
int lru(char *pages[])
{
  int pageFaults = 0;
  int pageTable[3] = {0, 0, 0};
  for (int i = 0; i < strlen(pages[1]); i += 2)
  {
    //reset
    for (int i = 0; i < 3; i++)
    {
      if (pages[1][i] == pageTable[i])
        continue;
    }

    //if page table is not full yet
    if (pageTable[0] == -1)
    {
      pageTable[0] = pages[1][i] - '0';
      pageFaults++;
    }
    else if (pageTable[1] == -1)
    {
      pageTable[1] = pages[1][i] - '0';
      pageFaults++;
    }
    else if (pageTable[2] == -1)
    {
      pageTable[2] = pages[1][i] - '0';
      pageFaults++;
    }
    else
    {
      //page table is already full
      for (int i = 0; i < 3; i++)
      {
        if (pages[1][i] - '0' == pageTable[i])
        {
          if (pageTable[2] == pages[1][i] - '0')
            continue;
          else if (pageTable[1] == pages[1][i] - '0')
          {
            pageTable[1] = pageTable[2];
            pageTable[2] = pages[1][i] - '0';
          }
          else
          {
            pageTable[0] = pageTable[1];
            pageTable[1] = pageTable[2];
            pageTable[2] = pages[1][i] - '0';
          }
        }
        else
        {
          pageFaults++;
          for (int j = 0; j < 2; j++)
          {
            pageTable[j] = pageTable[j + 1];
          }
          pageTable[2] = pages[1][i] - '0';
        }
        
      }
    }
  }
  return pageFaults;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "Wrong number of arguments" << endl;
    return 1;
  }

  int numFaults = 0;
  numFaults = fifo(argv);
  cout << "number of page faults FIFO: " << numFaults << endl;
  numFaults = lru(argv);
  cout << "number of page faults LRU: " << numFaults << endl;
  numFaults = optimal(argv);
  cout << "number of page faults Optimal Page Replacement: " << numFaults << endl;
}