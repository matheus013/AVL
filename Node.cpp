#include "Node.h"

Node::Node(const string &chave, const int &value){
    this->Key   = chave;
    this->Value = value;
    this->Subtree[LEFT]  = NULL;
    this->Subtree[RIGHT] = NULL;
    this->Balance = OK;
}


Node::~Node(){

    delete this->Subtree[LEFT];
    delete this->Subtree[RIGHT];
}

string Node::getKey(){
    return Key;
}
void Node::setKey(string str){
    this->Key.append(str);
}

Node *Node::getSub(int i){
    return this->Subtree[i];
}
void Node::setSub(Node *no){
    this->Key = no->getKey();
    this->Value = no->getValue();
    this->Subtree[LEFT] = no->getSub(LEFT);
    this->Subtree[RIGHT] = no->getSub(RIGHT);
    this->Balance = no->Balance;
}

int Node::getValue(){
    return Value;
}
void Node::setValue(int value){
    this->Value = value;
}

