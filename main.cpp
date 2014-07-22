#include <iostream>
#include "AvlTree.h"
using namespace std;
int main()
{
    AvlTree *avl = new AvlTree();

    cout << 1;
    avl->Insert(10);
    avl->Insert(323);
    avl->print(avl->getRoot(),0);
}
