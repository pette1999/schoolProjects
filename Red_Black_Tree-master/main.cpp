#include <iostream>
#include "RBT.h"

using namespace std;

int main(int argc, char** argv)
{
    RBT<int> rbt;
    rbt.insert(8);
    rbt.insert(18);
    rbt.insert(5);
    rbt.insert(15);
    rbt.insert(17);
    rbt.insert(25);
    rbt.insert(40);
    rbt.insert(80);
    rbt.deleteNode(25);
    rbt.print(rbt.root, "", true);
    return 0;
}