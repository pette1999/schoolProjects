#include <iostream>
#include "TreeNode.h"
using namespace std;

//reference
//https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
//https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html
//https://www.youtube.com/watch?v=gcULXE7ViZw&t=607s


template <class T>
class RBT
{
public:
    RBT();
    ~RBT();

    TreeNode<T> *root;
    int size;

    T *values;
    // rotation to balance the tree
    void rightRotation(TreeNode<T> *node);
    void leftRotation(TreeNode<T> *node);
    void insert(T value);
    void deleteNode(T value);
    void print(TreeNode<T> *node, string indent, bool last);
};

template <class T>
RBT<T>::RBT()
{
    root = NULL;
    root->left = NULL;
    root->right = NULL;
    root->left->parent = root;
    root->right->parent = root;
}

template <class T>
RBT<T>::~RBT()
{
    //more character building
}

template <class T>
void RBT<T>::rightRotation(TreeNode<T> *node)
{
    TreeNode<T> *x = node->left; //set a node x to the left child of node
    
    //we need to check if x node has a right child, since the right node of x would be left node of "node" after rotation
    //case1: node x has a right node, then we need to set it as the let node of "node"
    if(x->right != NULL)
    {
        node->left = x->right;
        x->right->parent = node;
    }
    else
    {
        //case2: we will set the left node of "node" to be NULL
        node->left = NULL;
    }

    //now we need to check if node has a parent node
    //case1: has a parent node, we need to replace the position of node to be x
    if(node->parent != NULL)
    {
        x->parent = node->parent;
    }
    else
    {
        //case2: if node doesn't have a parent node, we set node y to be the root
        root = x;
    }

    if(node->parent != NULL)
    {
        //check node is a left node of its parent or a right node
        //case1: it is a left node
        if(node == node->parent->left)
        {
            //set that position to be new node x
            node->parent->left = x;
        }
        else
        {
            //case2: it is a right node
            node->parent->right = x;
        }
    }
    
    //connect x and node
    x->right = node;
    node->parent = x;
    
}

//same thing with left rotation, just the opposite way
template <class T>
void RBT<T>::leftRotation(TreeNode<T> *node)
{
    TreeNode<T> *x = node->right;
    if(x->left != NULL)
    {
        node->right = x->left;
        x->left->parent = node;
    }
    else
    {
        node->right = NULL;
    }

    if (node->parent != NULL)
    {
        x->parent = node->parent;
    }
    else
    {
        root = x;
    }

    if (node->parent != NULL)
    {
        if (node == node->parent->left)
        {
            node->parent->left = x;
        }
        else
        {
            node->parent->right = x;
        }
    }

    x->left = node;
    node->parent = x;
}

template <class T>
void RBT<T>::insert(T value)
{
    TreeNode<T> *node;
    
    node->parent = NULL;
    node->key = value;
    // node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->color = 1;

    //if node is the root node, then change the color to black
    if (root == NULL)
    {
        node->color = 1;
        root = node;
        return;
    }
    else
    {
        TreeNode<T> *current = root;
        while (true)
        {
            node->parent = current;
            if (value < current->key)
            {
                current = current->left;
                if (current == NULL)
                {
                    node->parent->left = node;
                    break;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    node->parent->right = node;
                    break;
                }
            }
        }
    }

    //if the tree has at least two generations, then might be a chance to fix the tree
    if(node->parent->parent == NULL)
    {
        return;
    }

    //check and rebalance the tree
    //checking doubel red
    while(node->parent->color == 1)
    {
        TreeNode<T> *uncle = NULL;
        //case1: parent node is the right node of grandparent node
        if(node->parent == node->parent->parent->right)
        {
            //find uncle node
            uncle = node->parent->parent->left;
            //check uncle color
            if(uncle->color == 1)
            {
                //in this case, we have double red and uncle red, we just need to recolor granparent to red, uncle and parent to black
                node->parent->parent->color = 1; //grandparent
                uncle->color = 0; //uncle
                node->parent->color = 0; //parent
                //make sure root node is not red since this would change the grandparent node to red
                if(node->parent->parent == root)
                {
                    break;
                }
                else
                {
                    root->color = 0;
                }
            }
            else
            {
                //uncle is black, now we need to do rotation
                //check node is a left node or a right node
                //case1: it's a left node
                if(node == node->parent->left)
                {
                    //since parent is a right node and node is a left node, and we both red, we first need to do a right rotation at parent node
                    node = node->parent;
                    rightRotation(node);
                    //after the rotation, the node would go back to node at teh bottom
                }
                //now we have node and parent node both red and both are right child, we need to make a left rotation 
                //since we made the right rotation before, the node went back to teh bottom node
                //when we make a left rotation now, we need to go back to it's grandparent node
                leftRotation(node->parent->parent);
                //recolor the nodes
                node->parent->color = 0;
                node->parent->left->color = 1;
            }
        }
        else
        {
            //case2: parent node is the left node of granfparent node
            uncle = node->parent->parent->right;

            if(uncle->color == 1)
            {
                //same as above, just need to change colors
                node->parent->parent->color = 1; //grandparent
                uncle->color = 0;                //uncle
                node->parent->color = 0;         //parent
                if (node->parent->parent == root)
                {
                    break;
                }
                else
                {
                    root->color = 0;
                }
            }
            else
            {
                //check if the node is the right node
                if(node == node->parent->right)
                {
                    //since the parent node is right and grandparent node is also red, we need to make a leftrotation first
                    node = node->parent;
                    leftRotation(node);
                }
                rightRotation(node->parent->parent);
                node->parent->color = 0;
                node->parent->right->color = 1;
            }
            
        }
    }
    root->color = 0;
}

template <class T>
void RBT<T>::deleteNode(T value)
{
    //check if the tree is empty
    if(root == NULL)
    {
        return;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *target = NULL;
    TreeNode<T> *temp = NULL;
    bool isLeft = true;

    while (current->key != value)
    {
        current->parent = current;
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
            return;
            //we can't find the node
        }
    }
    target = current;
    int targetColor = target->color;
    //now we find the node that needs to be deleted, current
    if(current->left == NULL && current->right != NULL)
    {
        //if current node doesn't have a left node
        temp = current->right;
        //sweep nodes
        if(current->parent == NULL)
        {
            //if the current node is the root, after deletion, the right node would be the new root
            root = current->right;
        }
        else if(current == current->parent->left)
        {
            //if current node is the left node of its parent node
            //we just need to delete the current node, so just disconnect them
            current->parent->left = current->right;
        }
        else
        {
            //current node is a right node
            //do the same thing, just need to disconnect them
            current->parent->right = current->right;
        }
        //connect the right node of current node to the parent node of current node, which would disconnect the current node
        current->right->parent = current->parent;
    }
    else if(current->right == NULL && current->left != NULL)
    {
        //if current node doesn't have a right node
        temp = current->left;
        //basically, we need to do the same thing as above
        if (current->parent == NULL)
        {
            root = current->left;
        }
        else if (current == current->parent->left)
        {
            current->parent->left = current->left;
        }
        else
        {
            current->parent->right = current->left;
        }
        current->left->parent = current->parent;
    }
    else if(current->right == NULL && current->left == NULL)
    {
        //in this case, we just need to disconnect the current node, since current node is the leaf
        if(current == root)
        {
            //check if current node is teh root
            root = NULL;
        }
        else if(current == current->parent->left)
        {
            //check if current node is a left node
            current->parent->left = NULL;
        }
        else
        {
            current->parent->right = NULL;
        }
    }
    else
    {
        //in this class, current node has two children
        //the current node position should be repalced by the minimum node on the right subtree
        //get minimum node on the right subtree
        while(current->right->left != NULL)
        {
            current->right = current->right->left;
        }
        target = current->right;
        targetColor = target->color;
        temp = target->right;
        if(target->parent == current)
        {
            temp->parent = target;
        }
        else
        {
            if(target->parent == NULL)
            {
                root = target->right;
            }
            else if(target == target->parent->left)
            {
                target->parent->left = target->right;
            }
            else
            {
                target->parent->right = target->right;
            }
            target->right->parent = target->parent;

            target->right = current->right; //replace the orginal current node with the new minimum node we got
            target->right->parent = target; // connect the target node
        }
        
        //get rid of the duplicate target code at the current node position, and now we back to delete one child problem
        if(current->parent == NULL)
        {
            root = target;
        }
        else if(current == current->parent->left)
        {
            current->parent->left = target;
        }
        else
        {
            current->parent->right = target;
        }
        target->parent = current->parent;
        
        //reconnect the nodes
        target->left = current->left;
        target->left->parent = target;
        target->color = current->color;
    }
    delete current; //delete the node

    if(targetColor == 0)
    {
        //if the deleted node is black, we need to rebalance the tree, since it would violate property 5
        //we need to check on node temp, which is the right child of current target node
        TreeNode<T> *s = NULL;
        while(temp != root && temp->color == 0)
        {
            //we will continue to check while our node is not root node and the node is black
            if(temp == temp->parent->left)
            {
                //check if temp is a left node
                //store the right node to s
                s = temp->parent->right;
                if(s->color == 1)
                {
                    //now we have x's siblings red, we need to recolor s and have a left rotation
                    s->color = 0;
                    temp->parent->color = 1;
                    leftRotation(temp->parent);
                    s = temp->parent->right;
                }

                if(s->left->color == 0 && s->right->color == 0)
                {
                    //x ’s sibling S is black, and both of S’s children are black
                    //we can change the color of s and make temp node be it's parent
                    //then it will go back to the situation above
                    s->color = 1;
                    temp = temp->parent;
                }
                else
                {
                    if(s->right->color == 0 && s->left->color == 1)
                    {
                        //right node of s is black and left node is red
                        //we do a right rotation to make put all nodes to the right subtree
                        s->left->color = 0;
                        s->color = 1;
                        rightRotation(s);
                        s = temp->parent->right;
                    }

                    //if right node of s is red and don't know about left node
                    //we do a left rotation
                    s->color = temp->parent->color;
                    temp->parent->color = 0;
                    s->right->color = 0;
                    leftRotation(temp->parent);
                    temp = root;
                }
            }
            else
            {
                //temp if a right node now, basically just mirror the situations above
                s = temp->parent->left;
                if(s->color == 1)
                {
                    s->color = 0;
                    temp->parent->color = 1;
                    rightRotation(temp->parent);
                    s = temp->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0)
                {
                    // case 3.2
                    s->color = 1;
                    temp = temp->parent;
                }
                else
                {
                    if (s->left->color == 0)
                    {
                        // case 3.3
                        s->right->color = 0;
                        s->color = 1;
                        leftRotation(s);
                        s = temp->parent->left;
                    }

                    // case 3.4
                    s->color = temp->parent->color;
                    temp->parent->color = 0;
                    s->left->color = 0;
                    rightRotation(temp->parent);
                    temp = root;
                }
            }
        }
        temp->color = 0; //make sure root is black
    }
}

//100% copied from https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
template <class T>
void RBT<T>::print(TreeNode<T> *node, string indent, bool last)
{
    if(root != NULL)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "     ";
        }
        else
        {
            cout << "L----";
            indent += "|    ";
        }

        string sColor = root->color ? "RED" : "BLACK";
        cout << root->key <<"("<<sColor<<")"<<endl;
        print(root->left, indent, false);
        print(root->right, indent, true);
    }
}