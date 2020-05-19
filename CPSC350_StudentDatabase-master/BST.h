#include <iostream>
#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

//<-------------------------------BST Class-------------------------------->
template <class T>
class BST
{
public:
    BST();
    ~BST();

    TreeNode<T> *root;
    int size;

    T *values;
    bool search(T value);
    void insert(T value);
    //helper function
    bool isEmpty();
    bool deleteNode(T value);
    TreeNode<T> *getMin();
    TreeNode<T> *getMax();
    TreeNode<T> *getSuccessor(TreeNode<T> *d);
    void printTree();
    void recPrint(TreeNode<T> *node);
};

template <class T>
BST<T>::BST()
{
    root = NULL;
}
template <class T>
BST<T>::~BST()
{
    //more character building
}
template <class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    //inorder
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

template <class T>
void BST<T>::printTree()
{
    recPrint(root);
    //calls recursive function in which prints each key
}

template <class T>
TreeNode<T> *BST<T>::getMax()
{
    TreeNode<T> *current = root;
    if (root == NULL)
    {
        return NULL;
    }
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}
template <class T>
TreeNode<T> *BST<T>::getMin()
{
    TreeNode<T> *current = root;
    if (root == NULL)
    {
        return NULL;
    }
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
//inserts value into tree
template <class T>
void BST<T>::insert(T value)
{
    // TreeNode<T> *node = new TreeNode<T>(value);
    TreeNode<T> *node;
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        while (true)
        {
            parent = current;
            if (value < current->key)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = node;
                    break;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}
//Boolean that returns true if student object could be found and stores value in values variable
template <class T>
bool BST<T>::search(T value)
{
    //TreeNode<T> *node= new TreeNode<T>(value);
    if (root == NULL)
    {
        return false;
    }
    else
    {
        //tree is not empty
        TreeNode<T> *current = root;
        while (current->key != value)
        {
            if (value < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
            if (current == NULL)
            {
                return false;
            }
        }
        if (current != NULL)
        {
            values = &(current->key);
            return true;
        }
        //  return NULL;
    }
}
//finds the node then deletes it
template <class T>
bool BST<T>::deleteNode(T value)
{
    if (root == NULL)
    {
        return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;
    //if we make it here, the tree is not empty and now we need to find the node
    while (current->key != value)
    {
        parent = current;
        if (value < current->key)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;
        }
        if (current == NULL)
        {
            return false;
        }
    }
    //now we found it, now what
    if (current->left == NULL && current->right == NULL)
    {
        if (current == root)
        {
            root = NULL;
            //  cout<<"Deleted"<<endl;
        }
        else if (isLeft)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    else if (current->right == NULL)
    {
        if (current == root)
        {
            root = current->left;
        }
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }
    else if (current->left == NULL)
    {
        if (current == root)
        {
            root = current->right;
        }
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }
    else
    {
        //node to be deleted has 2 children
        TreeNode<T> *successor = getSuccessor(current);
        if (current == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    return true;
}
template <class T>
TreeNode<T> *BST<T>::getSuccessor(TreeNode<T> *d)
{
    TreeNode<T> *current = d->right;
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    while (current != NULL)
    {
        sp = successor;
        successor = current;
        current = current->left;
    }
    if (successor != d->right)
    {
        sp->left = successor->right;
        successor->right = d->right;
    }
}