#include "GenBST.h"
#include "Student.h"

class StudentTable : public GenBST<Student>
{
    bool replaceAdvisorId(Student val, GenBST<Student> bst);
};

bool StudentTable::replaceAdvisorId(Student val, GenBST<Student> bst)
{
    if (bst.getRoot() == NULL)
    {
        return false;
    }
    else
    {
        GenTreeNode<Student> *curr = bst.getRoot(); // start at root
        while (curr->key != val)
        {
            if (val < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
            if (curr == NULL)
                return false; // we didn't find it
        }
        curr->key.advisor = val.advisor;
        return true;
    }
}