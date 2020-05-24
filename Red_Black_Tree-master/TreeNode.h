#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
public:
    T key;
    T *data;
    int color; //0 black, 1 red
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;

    TreeNode();
    TreeNode(T *d, int k, int c);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode()
{
    key = NULL;
    data = T();
    left = NULL;
    right = NULL;
    parent = NULL;
    color = 0;
}

template <class T>
TreeNode<T>::TreeNode(T *d, int k, int c)
{
    key = k;
    data = d;
    left = NULL;
    right = NULL;
    parent = NULL;
    color = c;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    delete data;
    delete left;
    delete right;
    delete parent;
}