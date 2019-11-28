#include "GenBST.h"
#include "Faculty.h"

class FacultyTable : public GenBST<Faculty>
{
public:
    void RemoveStudentId(GenTreeNode<Faculty> *node, bool &abortCmd, int id, GenBST<Faculty> bst);

    bool removeAdviseeId(Faculty val, int adviseeId, GenBST<Faculty> bst);

    // returns false if command was not aborted
    bool removeStudentId(int id, GenBST<Faculty> bst);

    bool replaceStudentId(Faculty oldVal, Faculty newVal, int studId, GenBST<Faculty> bst);
};

void FacultyTable::RemoveStudentId(GenTreeNode<Faculty> *node, bool &abortCmd, int id, GenBST<Faculty> bst)
{
    if (!abortCmd)
    {
        if (node == NULL)
            return;
        bst.recPrint(node->left);
        if (node->key.hasAdvise(id))
        {
            abortCmd = true;
            cout << "Advisee with ID " << id << "already exists" << endl;
        }
        bst.recPrint(node->right);
    }
    else
        return;
}

bool FacultyTable::removeAdviseeId(Faculty val, int adviseeId, GenBST<Faculty> bst)
{
    if (bst.getRoot() == NULL)
        return false;
    else
    {
        GenTreeNode<Faculty> *curr = bst.getRoot();
        while (curr->key != val)
        {
            if (val < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
            if (curr == NULL)
                return false;
        }
        curr->key.removeAdviseId(adviseeId);
    }
}

// returns false if command was not aborted
bool FacultyTable::removeStudentId(int id, GenBST<Faculty> bst)
{
    bool abortCmd = false;
    RemoveStudentId(bst.getRoot(), abortCmd, id, bst);
    return abortCmd;
}

bool replaceStudentId(Faculty oldVal, Faculty newVal, int studId, GenBST<Faculty> bst)
{
    if (bst.getRoot() == NULL)
        return false;
    else
    {
        GenTreeNode<Faculty> *curr = bst.getRoot(); // start at root
        while (curr->key != oldVal)
        {
            if (oldVal < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
            if (curr == NULL)
                return false; // we didn't find it
        }
        curr->key.removeAdviseId(studId);
        curr = bst.getRoot(); // start at root
        while (curr->key != newVal)
        {
            if (newVal < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
            if (curr == NULL)
                return false; // we didn't find it
        }
        curr->key.addAdviseId(studId);
    }
}