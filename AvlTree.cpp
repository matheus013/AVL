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

bool AvlTree::Search(const string& key,int &value){

    Node* current = root;
    while (current != 0){

        if (key > current->getKey()){
            current = current->getSub(RIGHT);
        }

        else if (key < current->getKey()){
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
    node = child;
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


void AvlTree::Insert(const string& key, const int &value){
    //cout << key << endl;
    //cout << value << endl;
    bool hChanged = false;
    this->insert(key, value, root, hChanged);
}


void AvlTree::insert(const string key, const int value,Node* node, bool hChanged){
    if (node == 0){
        node = new Node(key, value);
        hChanged = true;
    }

    else if (node->getKey() == key){
        return;
    }
    else{

        Direction dir = (key > node->getKey()) ? RIGHT : LEFT;
        hChanged = false;
        insert(key, value,node->getSub(dir), hChanged);
        if (hChanged){
            rebalanceInsert(node, dir, hChanged);
        }
    }
}

bool AvlTree::Remove(const string &key){
    bool hChanged = false;
    return remove(key, root, hChanged);
}

bool AvlTree::remove(const string key, Node* node,bool hChanged){
    bool success = false;

    if (node == 0){
        hChanged = false;
        return false;
    }


    else if (key == node->getKey()){
        if (node->getSub(LEFT) != 0 && node->getSub(RIGHT) != 0 ){
            Node* substitute = node->getSub(LEFT);
            while (substitute->getSub(RIGHT) != 0){
                substitute = substitute->getSub(RIGHT);
            }
            node->getKey()   = substitute->getKey();
            success = remove(node->getKey(), node->getSub(LEFT), hChanged);
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
        Direction dir = (key > node->getKey()) ? RIGHT : LEFT;
        if (node->getSub(dir) != 0){
            success = remove(key, node->getSub(dir), hChanged);
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
    cout << "test" << endl;
    cout << root->getSub(RIGHT) << endl;

    if(root->getSub(LEFT)!= 0){
        print(root->getSub(LEFT), level +1);
    }
    cout << qPrintable(QString("\t").repeated(level)) << "element=" << root->getValue() <<endl;
    if(root->getSub(RIGHT)!= 0){
        print(root->getSub(RIGHT),level +1);
    }

}
Node* AvlTree::getRoot(){
    return root;
}

inline Direction AvlTree::opposite(Direction dir){
    return (dir == RIGHT) ? LEFT : RIGHT;
}
