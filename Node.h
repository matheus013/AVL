#ifndef NODE_H
#define NODE_H
#include "Direction.h"
#include <string>

using namespace std;

 class Node{

    //Node* Subtree[2];
    //string Key;
    Node *left;
    Node *right;
    int value;

public:
    unsigned short Balance;
    Node(int value);
    Node(int value, Node *l,Node *r);
    ~Node();
    Node* getLeft();
    Node* getRight();
    Node* getSub(int i);
    void setSub(Node *no);
    //string getKey();
    //void setKey(string str);
    int getValue();
    void setValue(int value);
    bool isEmpty();


};

#endif // NODE_H
