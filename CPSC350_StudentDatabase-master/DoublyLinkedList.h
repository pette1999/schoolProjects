#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

    void insertFront(T d);
    void insertBack(T d);
    void printList();
    void printStudentList();
    T removeFront();
    T removeBack();
    T returnFront();
    T deletePos(int pos);
    T returnElement(int pos);
    int find(T value);
    ListNode<T> *remove(T d);
    bool isEmpty();
    unsigned int getSize();
};
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    size = 0;
    front = NULL;
    back = NULL;
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (front)
    {
        ListNode<T> *node = front;
        front = front->next;
        delete node;
    }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
    ListNode<T> *node = new ListNode<T>(d);
    if (size == 0)
    {
        back = node;
    }
    else
    {
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
    ListNode<T> *node = new ListNode<T>(d);
    if (isEmpty())
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
T DoublyLinkedList<T>::removeFront()
{
    ListNode<T> *ft = front;

    if (size == 0)
    {
        cerr << "Nothing to remove from Front" << endl;
    }
    else if (front->next == NULL)
    {
        //only one element in the List
        back = NULL;
        front = front->next;
        T temp = ft->data;
        ft->next = NULL;
        size--;
        delete ft;
        return temp;
    }
    else
    {
        front->next->prev = NULL;
        front = front->next;
        T temp = ft->data;
        ft->next = NULL;
        size--;
        delete ft;
        return temp;
    }
}

template <class T>
T DoublyLinkedList<T>::removeBack()
{
    ListNode<T> *bk = back;

    if (size == 0)
    {
        cerr << "Nothing to remove" << endl;
    }
    else if (front->next == NULL)
    {
        removeFront();
    }
    else
    {
        back = back->prev;
        bk->prev = NULL;
        bk->prev->next = NULL;
        T temp = bk->data;
        delete bk;
        size--;
        return temp;
    }
}

template <class T>
ListNode<T> *DoublyLinkedList<T>::remove(T d)
{
    ListNode<T> *curr = front;
    while (curr->data != d)
    {
        curr = curr->next;
        if (curr == NULL)
        {
            return NULL;
        }
    }
    if (curr == front)
    {
        front = curr->next;
    }
    else
    {
        curr->prev->next = curr->next;
    }
    if (curr == back)
    {
        back = curr->prev;
    }
    else
    {
        curr->next->prev = curr->prev;
    }
    curr->next = NULL;
    curr->prev = NULL;
    size--;
    return curr;
}

template <class T>
int DoublyLinkedList<T>::find(T value)
{
    int idx = -1;
    ListNode<T> *curr = front;

    while (curr != NULL)
    {
        idx++;

        if (curr->data == value)
        {
            break;
        }
        else
        {
            curr = curr->next;
        }
    }

    if (curr == NULL)
    {
        idx = -1;
    }

    return idx;
}

template <class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
    int idx = 0;

    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while (idx != pos)
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
T DoublyLinkedList<T>::returnElement(int pos)
{
    int idx = 0;

    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while (idx != pos)
    {
        prev = curr;
        curr = curr->next;
        ++idx;
    }

    T d = curr->data;

    return d;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
    return size;
}

template <class T>
void DoublyLinkedList<T>::printStudentList()
{
    ListNode<T> *curr = front;
    cout << curr->data.printStudent() << endl;
    while (curr->next != NULL)
    {
        curr = curr->next;
        cout << curr->data.printStudent() << endl;
    }
}

template <class T>
void DoublyLinkedList<T>::printList()
{
    ListNode<T> *curr = front;
    if(isEmpty())
    {
        
    }
    else
    {
        cout << curr->data << endl;
        while (curr->next != NULL)
        {
            curr = curr->next;
            cout << curr->data << endl;
        }
    }
}

template <class T>
T DoublyLinkedList<T>::returnFront()
{
    ListNode<T> *curr = front;
    T answer = curr->data;
    return answer;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (size == 0);
}