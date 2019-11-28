#include "GenTreeNode.h"
#include "Student.h"
#include <fstream>

using namespace std;

//template class================================================================
template <class T>
class GenBST
{
public:
    GenBST();
    ~GenBST();

    void insert(T value);
    bool contains(T value);

    //delete placeholder
    bool deleteRec(T k);
    bool isEmpty();

    GenTreeNode<T> *search(T key);
    GenTreeNode<T> *search(int key);
    GenTreeNode<T> *getSuccessor(GenTreeNode<T> *d);

    void printTree();
    void recPrint(GenTreeNode<T> *node); //in-order traversal, print subtree
    void saveTree(ofstream &os, GenTreeNode<T> *node);
    bool replaceAdvisorId(Student val)

    GenTreeNode<T> *root;
    GenTreeNode<T> *getRoot();

    void loadInFile(string filename);//load data from local file to the BST
};
//------------------------------------------------------------------------------
//template functions

template <class T>
GenBST<T>::GenBST()
{
    root = NULL;
}

template <class T>
GenBST<T>::~GenBST()
{
    delete root;
}

template <class T>
void GenBST<T>::printTree()
{
    recPrint(root);
}

template <class T>
bool GenBST<T>::isEmpty()
{
    return root == NULL;
}

template <class T>
GenTreeNode<T> *GenBST<T>::getRoot()
{
    return root;
}
//------------------------------------------------------------------------------
template <class T>
void GenBST<T>::recPrint(GenTreeNode<T> *node) //recursive tree
{
    if (node == NULL)
    {
        return;
    }

    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

template <class T>
void GenBST<T>::saveTree(ofstream &os, GenTreeNode<T> *node)
{
    if (node == NULL)
    {
        return;
    }

    os << node->key << endl;
    saveTree(os, node->left);
    saveTree(os, node->right);
}

template <class T>
void GenBST<T>::insert(T value)
{
    // check for duplicates

    GenTreeNode<T> *node = new GenTreeNode<T>(value);

    if (isEmpty())
    {
        root = node;
    }

    else //not an empty GenTreeNode, find insertion point
    {
        GenTreeNode<T> *curr = root;
        GenTreeNode<T> *par; //empty GenTreeNode

        while (true) //while par == null;  begin search for insertion point
        {
            par = curr;
            if (value < curr->key) //go left
            {
                curr = curr->left;
                if (curr == NULL) //we found the insertion point
                {
                    par->left = node;
                    break;
                }
            }

            else //go right
            {
                curr = curr->right;
                if (curr == NULL) //we found the insertion point
                {
                    par->right = node;
                    break;
                }
            }
        }
    }
}

//search method
template <class T>
bool GenBST<T>::contains(T value)
{
    if (isEmpty())
    {
        return false;
    }
    else //not empty continue search
    {
        GenTreeNode<T> *curr = root;

        while (curr->key != value)
        {
            if (curr == NULL)
            {
                return false;
            }

            //check if leaf
            if (curr->left == NULL && curr->right == NULL)
            {
                return value == curr->key;
            }

            else if (value < curr->key)
            {
                curr = curr->left;
            }

            else
            {
                curr = curr->right;
            }
        }
    }
    return true;
}

template <class T>
GenTreeNode<T> *GenBST<T>::search(T key)
{
    GenTreeNode<T> *curr = root;
    while (curr != NULL)
    {
        if (curr->key == key)
        {
            return curr;
        }
        else
        {
            if (curr->key > key)
            {
                curr = curr->left;
            }
            else if (curr->key < key)
            {
                curr = curr->right;
            }
        }
    }
    return curr;
}

template <class T>
GenTreeNode<T> *GenBST<T>::search(int key)
{
    GenTreeNode<T> *curr = root;
    while (curr != NULL)
    {
        if (curr->key == key)
        {
            return curr;
        }
        else
        {
            if (curr->key > key)
            {
                curr = curr->left;
            }
            else if (curr->key < key)
            {
                curr = curr->right;
            }
        }
    }
    return curr;
}

template <class T>
bool GenBST<T>::deleteRec(T k) //garbage collected
{
    //use contains method
    if (!contains(k))
    {
        return false;
    }

    //find the GenTreeNode
    GenTreeNode<T> *curr = root; //curr
    GenTreeNode<T> *par = root;  //par
    bool isLeft = true;

    // look for the GenTreeNode
    while (curr->key != k)
    {

        par = curr;

        if (k < curr->key) //go left
        {
            isLeft = true;
            curr = curr->left;
        }
        else
        {
            isLeft = false;
            curr = curr->right;
        }

        if (curr == NULL) //in the event you do not use contains
        {
            return false;
        }
    }
    //found the node to be deleted

    //check whether a leaf or not

    if (curr->left == NULL && curr->right == NULL) //then it's a leaf
    {

        if (curr == root)
        {
            root = NULL;
        }

        else if (isLeft)
        {
            par->left = NULL;
        }
        else
        {
            par->right = NULL;
        }
        delete curr;
    }

    //check if it has one child
    else if (curr->right == NULL) //no right child
    {
        if (curr == root)
        {
            root = curr->left;
            curr->left = NULL;
            delete curr;
        }
        else if (isLeft)
        {
            par->left = curr->left;
        }
        else //right child
        {
            par->right = curr->left;
        }
    }

    else if (curr->left == NULL) //no left child
    {
        if (curr == root)
        {
            root = curr->right;
        }
        else if (isLeft)
        {
            par->left = curr->right;
        }
        else //right child
        {
            par->right = curr->right;
        }
    }

    else // the node to be deleted has 2 children
    {
        GenTreeNode<T> *successor = getSuccessor(curr);

        if (curr == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            par->left = successor;
        }
        else
        {
            par->right = successor;
        }

        successor->left = curr->left;
    }

    return true;
}

//d is the node we are deleting
template <class T>
GenTreeNode<T> *GenBST<T>::getSuccessor(GenTreeNode<T> *d) //d is the node to be deleteNode
{
    GenTreeNode<T> *sp = d; // sp is the successor's parent and is initiialized to d
    GenTreeNode<T> *successor = d;
    GenTreeNode<T> *curr = d->right; //start one right

    while (curr != NULL) // one right all the way left
    {
        sp = successor;
        successor = curr;
        curr = curr->left;
    }

    if (successor != d->right) //descendant of right child
    {
        sp->left = successor->right;
        successor->right = d->right;
    }

    return successor;
}

template <class T>
void GenBST<T>::loadInFile(string filename)
{
    ifstream fileIn;
    string line;
    fileIn.open(filename);
    while(getline(fileIn, line))
    {
        T node = T(line);
        this.insert(line);
    }
    fileIn.close();
}