#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
public:
    T key;
    T *data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode();
    TreeNode(T *d, int k);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode()
{
    key = NULL;
    data = T();
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T *d, int k)
{
    key = k;
    data = d;
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    delete data;
    delete left;
    delete right;
}