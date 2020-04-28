#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class GenQueue
{
public:
    GenQueue();
    ~GenQueue();

    void insert(T d);
    void printQueue();
    void printStudentQueue();
    T remove();
    T peek();
    bool isFull();
    bool isEmpty();
    ListNode<T> *front;
    ListNode<T> *back;
    int numElements;
    int GetSize();

    DoublyLinkedList<T> list;
};
template <class T>
GenQueue<T>::GenQueue()
{
    DoublyLinkedList<T> list;
    numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue()
{
    
}

template <typename T>
void GenQueue<T>::insert(T d)
{
    list.insertBack(d);
    numElements++;
}

template <class T>
T GenQueue<T>::remove()
{
    if (list.getSize() == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        T answer = list.removeFront();
        return answer;
    }
}

template <class T>
T GenQueue<T>::peek()
{
    if (list.getSize() == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        T answer = list.returnFront();
        return answer;
    }
}

template <class T>
bool GenQueue<T>::isEmpty()
{
    return (list.size == 0);
}

template <class T>
int GenQueue<T>::GetSize()
{
    int answer = list.getSize();
    return answer;
}

template <class T>
void GenQueue<T>::printStudentQueue()
{
    list.printStudentList();
}

template <class T>
void GenQueue<T>::printQueue()
{
    list.printList();
}