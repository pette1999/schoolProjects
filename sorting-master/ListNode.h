#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
    ListNode();
    ListNode(T d);
    ~ListNode();

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
};

template <class T>
ListNode<T>::ListNode()
{
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d)
{
    data = d;
    next = NULL; //nullptr
    prev = NULL; //nullptr
}

template <class T>
ListNode<T>::~ListNode()
{
    delete next;
    delete prev;
}