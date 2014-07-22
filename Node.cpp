#include "Node.h"

Node::Node(const string &key, const int &value){
    Key   = key;
    Value = value;
    Subtree[LEFT]  = 0;
    Subtree[RIGHT] = 0;
    Balance = OK;
}


Node::~Node(){

    delete Subtree[LEFT];
    delete Subtree[RIGHT];
}

string Node::getKey(){
    return Key;
}
void Node::setKey(string str){
    Key = str;
}

Node *Node::getSub(int i){
    return this->Subtree[i];
}
void Node::setSub(Node *no){
    Key = no->getKey();
    Value = no->getValue();
    Subtree[LEFT] = no->getSub(LEFT);
    Subtree[RIGHT] = no->getSub(RIGHT);
    Balance = no->Balance;
}

int Node::getValue(){
    return Value;
}
void Node::setValue(int value){
    Value = value;
}

