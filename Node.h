#ifndef NODE_H
#define NODE_H
#include "Direction.h"
#include <string>

using namespace std;

 class Node{

    Node* Subtree[2];
    string Key;
    int Value;

public:
    unsigned short Balance;
    Node(const string& key, const int& value);
    ~Node();

    Node *getSub(int i);
    void setSub(Node *no);
    string getKey();
    void setKey(string str);
    int getValue();
    void setValue(int value);


};

#endif // NODE_H
