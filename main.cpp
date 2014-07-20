#include <QCoreApplication>
#include "AvlTree.h"
int main()
{
   AvlTree *avl = new AvlTree();


   avl->Insert("a",1);
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


}
