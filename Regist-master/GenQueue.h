#include "GenDoubleLL.h"
#include <iostream>

using namespace std;

template <class T>
class GenQueue
{
  public:
  GenQueue(); //constructor
  ~GenQueue(); //destructor
  void insert(T* data); //insert T pointer
  T* remove(); //remove and return T pointer
  T* peek();

  bool isEmpty();
  int getSize();

  void printQueue();

  GenDoubleLL<T> *myQueue;

  private:
  int size;

};

//Template Functions============================================================
template <class T>
GenQueue<T>::GenQueue() {
  size = 0;
  myQueue = new GenDoubleLL<T>;
}

template <class T>
GenQueue<T>::~GenQueue() {
  delete myQueue;
}

template <class T>
void GenQueue<T>::insert(T* data) {
  myQueue->insertBack(data);
  size++;
}

template <class T>
T* GenQueue<T>::remove() {
  if(size < 1) {
    cout << "Queue empty." << endl;
    exit(EXIT_FAILURE);
  }
  else {
    size--;
    return myQueue->removeFront();
  }
}

template <class T>
T* GenQueue<T>::peek() {
  if(size < 1) {
    cout << "Queue empty." << endl;
    exit(EXIT_FAILURE);
  }
  else {
    return myQueue->getFront()->data;
  }
}

template <class T>
bool GenQueue<T>::isEmpty() {
  return size == 0;
}

template <class T>
int GenQueue<T>::getSize() {
  return size;
}

template <class T>
void GenQueue<T>::printQueue() {
  myQueue->printList();
}
