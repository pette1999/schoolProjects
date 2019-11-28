#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
//temp class
template <class T>
class GenTreeNode
{
public:
    GenTreeNode();
    GenTreeNode(T k); //k=key, which in this exampel is also the value(data)
    ~GenTreeNode();   //when creating a template class destructor must be virtual

    T key;
    GenTreeNode<T> *left;  //pointer to the left
    GenTreeNode<T> *right; //pointer to the right
};
//------------------------------------------------------------------------------
template <class T>
GenTreeNode<T>::GenTreeNode()
{
    key = NULL;
    left = NULL;
    right = NULL;
}

template <class T>
GenTreeNode<T>::GenTreeNode(T k)
{
    key = k;
    left = NULL;
    right = NULL;
}

template <class T>
GenTreeNode<T>::~GenTreeNode()
{
    delete right;
    delete left;
}
