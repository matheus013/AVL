#include <iostream>
#include "AvlTree.h"
using namespace std;
int main()
{
    AvlTree *avl = new AvlTree();

cout << 1;
    avl->Insert("a",1);
    cout << avl->getRoot()->getValue();
    avl->Insert("ads",3);
    avl->Insert("ds",4);
    avl->Insert("aqr",435);
    avl->Insert("aqw",23);
    avl->Insert("awqw",155);
    avl->Insert("arr",767);
    avl->Insert("arvxz",68);
    avl->Insert("azxc",56);
    avl->Insert("axzcx",685);
    avl->Insert("axzc",5685);
    avl->Remove("arr");
    avl->print(avl->getRoot(),0);
}
