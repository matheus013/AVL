#include "AvlTree.h"
#include <iostream>
#include <QString>

using namespace std;

AvlTree::AvlTree(){
    root = 0;
}

AvlTree::~AvlTree(){
    Clear();
}

void AvlTree::Clear(){
    delete root;
    root = 0;
}

bool AvlTree::Search(int &value){

    Node* current = root;
    while (current != 0){

        if (value > current->getValue()){
            current = current->getSub(RIGHT);
        }

        else if (value < current->getValue()){
            current = current->getSub(LEFT);
        }

        else{
            value = current->getValue();
            return true;
        }
    }

    return false;
}

void AvlTree::rotateOnce(Node*& node, Direction dir){

    int opposite = this->opposite(dir);
    Node* child;
    child->setSub(node->getSub(dir));
    node->setSub(child->getSub(opposite));
    child->setSub(node);
    node->setSub(child);
}

void AvlTree::rotateTwice(Node*& node, Direction dir){

    int opposite = this->opposite(dir);
    Node* child = node->getSub(dir)->getSub(opposite);

    node->getSub(dir)->getSub(opposite)->setSub(child->getSub(dir));
    child->getSub(dir)->setSub(node->getSub(dir));
    node->getSub(dir)->setSub(child);
    child->setSub(node->getSub(dir));
    node->getSub(dir)->setSub(child->getSub(opposite));
    child->getSub(opposite)->setSub(node);
    node->setSub(child);
}

void AvlTree::updateBalance(Node* node, Direction dir){

    int opposite = this->opposite(dir);
    int bal = node->getSub(dir)->getSub(opposite)->Balance;

    if (bal == dir){
        node->Balance = OK;
        node->getSub(dir)->Balance = opposite;
    }

    else if (bal == opposite){
        node->Balance = dir;
        node->getSub(dir)->Balance = OK;
    }

    else{
        node->Balance = node->getSub(dir)->Balance = OK;
    }

    node->getSub(dir)->getSub(opposite)->Balance = OK;
}

void AvlTree::rebalanceInsert(Node*& node, Direction dir,bool& hChanged){

    int opposite = this->opposite(dir);

    if (node->Balance == dir)    {
        if (node->getSub(dir)->Balance == dir)        {
            node->getSub(dir)->Balance = 2;
            node->Balance = OK;
            rotateOnce(node, dir);
        }
        else{
            updateBalance(node, dir);
            rotateTwice(node, dir);
        }

        hChanged = false;
    }


    else if (node->Balance == opposite){
        node->Balance = OK;
        hChanged = false;
    }

    else{
        node->Balance = dir;
    }
}


void AvlTree::rebalanceRemove(Node*& node, Direction dir,bool& hChanged){

    Direction opposite = this->opposite(dir);
    if (node->Balance == dir){
        node->Balance = OK;
    }

    else if (node->Balance == opposite){

        if (node->getSub(opposite)->Balance == opposite){

            node->getSub(opposite)->Balance = OK;
            node->Balance = OK;
            rotateOnce(node, opposite);
        }

        else if (node->getSub(opposite)->Balance == OK){

            node->getSub(opposite)->Balance = dir;
            rotateOnce(node, opposite);
        }

        else{

            updateBalance(node, opposite);
            rotateTwice(node, opposite);
        }

        hChanged = false;
    }

    else{
        node->Balance = opposite;
        hChanged = false;
    }
}


void AvlTree::Insert( const int &value){
    //cout << key << endl;
    //cout << value << endl;
    bool hChanged = false;
    this->insert(value, root, hChanged);
}


void AvlTree::insert(const int value,Node* node, bool hChanged){
    if (node == 0){
        node = new Node(value);
        hChanged = true;
    }

    else if (node->getValue() == value){
        return;
    }
    else{

        Direction dir = (value > node->getValue()) ? RIGHT : LEFT;
        hChanged = false;
        insert(value,node->getSub(dir), hChanged);
        if (hChanged){
            rebalanceInsert(node, dir, hChanged);
        }
    }
}

bool AvlTree::Remove(const int &value){
    bool hChanged = false;
    return remove(value, root, hChanged);
}

bool AvlTree::remove(const int value, Node* node,bool hChanged){
    bool success = false;

    if (node == 0){
        hChanged = false;
        return false;
    }


    else if (value == node->getValue()){
        if (node->getSub(LEFT) != 0 && node->getSub(RIGHT) != 0 ){
            Node* substitute = node->getSub(LEFT);
            while (substitute->getSub(RIGHT) != 0){
                substitute = substitute->getSub(RIGHT);
            }
            node->setValue(substitute->getValue());
            success = remove(node->getValue(), node->getSub(LEFT), hChanged);
            if (hChanged){
                rebalanceRemove(node, LEFT, hChanged);
            }
        }

        else{
            Node* temp = node;
            Direction dir = (node->getSub(LEFT) == 0) ? RIGHT : LEFT;
            node = node->getSub(dir);
            temp->~Node();
            delete temp;
            hChanged = true;
        }

        return true;
    }

    else{
        Direction dir = (value > node->getValue()) ? RIGHT : LEFT;
        if (node->getSub(dir) != 0){
            success = remove(value, node->getSub(dir), hChanged);
        }

        else{
            hChanged = false;
            return false;
        }

        if (hChanged){

            this->rebalanceRemove(node, dir, hChanged);
        }

        return success;
    }
}

void AvlTree::print(Node* root,int level){
    if(root->getLeft()!= NULL){
        print(root->getLeft(), level +1);
    }
    cout << qPrintable(QString("\t").repeated(level)) << "element=" << root->getValue() <<endl;
    if(root->getRight()!= NULL){
        print(root->getRight(),level +1);
    }
    cout << "test" << endl;

}
Node* AvlTree::getRoot(){
    return root;
}

inline Direction AvlTree::opposite(Direction dir){
    return (dir == RIGHT) ? LEFT : RIGHT;
}
