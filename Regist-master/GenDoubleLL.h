#include "ListNode.h"
#include <iostream>

using namespace std;

template <class T>
class GenDoubleLL
{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

  public:
    GenDoubleLL();
    ~GenDoubleLL();

    void insertFront(T);
    void insertBack(T);
    T* removeFront();
    T* removeBack();
    ListNode<T> *remove(T key);

    T deletePos(int pos);
    int find(T value);

    bool isEmpty();

    void printList();
    unsigned int getSize();
    ListNode<T>* getFront();
    ListNode<T>* getBack();
};

//template functions============================================================
//constructors / destructor=====================================================
template <class T>
GenDoubleLL<T>::GenDoubleLL()
{
  front = NULL;
  size = 0;
}

template <class T>
GenDoubleLL<T>::~GenDoubleLL()
{
  while(front)
  {
    ListNode<T> *node = front;
    front = front->next;
    delete node;
  }
}

template <class T>
void GenDoubleLL<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0)
  {
    back = node;
  }

  else
  {
    front->prev = node;
    node->next = front;
  }

  front = node;
  size++;
}

template <class T>
void GenDoubleLL<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty())
  {
    front = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T* GenDoubleLL<T>::removeFront()
{
  ListNode<T> *temp = front;

  if(size == 0)
  {
    cerr << "Nothing to remove from Front" << endl;
    exit(EXIT_FAILURE);
  }

  else if (front->next == NULL)
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;

  T* data = temp->data;

  delete temp;
  size--;
  return data;
}

template <class T>
T* GenDoubleLL<T>::removeBack()
{
  ListNode<T> *temp = back;
  if(size == 0)
  {
    cerr << "Nothing to remove" << endl;
    exit(EXIT_FAILURE);
  }

  else if (front->next == NULL)
  {
    front = NULL;
  }

  else
  {
    back->prev->next = NULL;
  }
  back = back->prev;
  temp->prev = NULL;

  T data = temp->data;
  delete temp;
  size--;
  return data;
}

template <class T>
ListNode<T>* GenDoubleLL<T>::remove(T key)
{
  ListNode<T> *current = front;

  while(current->data != key)
  {
    current = current->next;

    if (current == NULL) {
      return NULL;
    }
  }

  //we found it

  if (current == front) {
    front = current->next;
  }

  else{
    current->prev->next = current->next;
  }

  if (current == back) {
    back = current->prev;
  }

  else
  {
    current->next->prev = current->prev;
  }

  current->next = NULL;
  current->prev = NULL;

  --size;

  return current;
}

template <class T>
int GenDoubleLL<T>::find(T value)
{
  int idx = -1;
  ListNode<T> *curr = front;

  while(curr != NULL)
  {
    idx++;

    if(curr->data == value)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if(curr == NULL)
  {
    idx = -1;
  }

 return idx;
}

template <class T>
T GenDoubleLL<T>::deletePos(int pos)
{
  int idx = 0;

  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(idx != pos)
  {
    prev = curr;
    curr = curr->next;
    ++idx;
  }

  prev->next = curr->next;
  curr->next = NULL;

  T d = curr->data;
  size--;

  delete curr;

  return d;
}

template <class T>
unsigned int GenDoubleLL<T>::getSize()
{
  return size;
}

template <class T>
void GenDoubleLL<T>::printList()
{
  ListNode<T> *curr = front;

  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
ListNode<T>* GenDoubleLL<T>::getFront()
{
  return front;
}

template <class T>
bool GenDoubleLL<T>::isEmpty() {
  return size == 0;
}

template <class T>
ListNode<T>* GenDoubleLL<T>::getBack()
{
  return back;
}
