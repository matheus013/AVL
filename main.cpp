#include "avl.h"
#include <iostream>
#include <QString>

using namespace std;
// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void print(struct node* aux,int level){
    if(aux->right!= NULL){
        print(aux->right, level +1);
    }
    cout << qPrintable(QString("\t").repeated(level)) << aux->key <<endl;
    if(aux->left!= NULL){
        print(aux->left,level +1);
    }
}

/* Drier program to test above function*/
int main()
{
  struct node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  root = insert(root, 253);
  root = insert(root, 25);
  root = insert(root, 25);
  root = insert(root, 250);

  printf("Pre order traversal of the constructed AVL tree is \n");
  print(root,0);

  return 0;
}
