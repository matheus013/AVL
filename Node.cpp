#include "Node.h"

Node::Node(int value){
    //Key   = key;
    this->value = value;
    left  = NULL;
    right = NULL;
    Balance = OK;
}

Node::Node(int value, Node *l, Node *r){
    this->value = value;
    left = l;
    right = r;
    Balance = OK;
}

Node::~Node(){

    delete left;
    delete right;
}

//string Node::getKey(){
//    return Key;
//}
//void Node::setKey(string str){
//   Key = str;
//}

Node *Node::getSub(int i){
    if(i == LEFT)
        return left;

    if(i == RIGHT)
        return right;

}
void Node::setSub(Node *no){
    //Key = no->getKey();
    //value = no->getValue();
    left = no->getLeft();
    right = no->getLeft();
    //Balance = no->Balance;
}

int Node::getValue(){
    return value;
}
void Node::setValue(int value){
    this->value = value;
}
Node* Node::getLeft(){
    return left;
}
Node* Node::getRight(){
    return right;
}
