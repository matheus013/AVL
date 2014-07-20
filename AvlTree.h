#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"

class AvlTree{
    Node* root;
    void rotateTwice(Node*& node, Direction dir);
    void rotateOnce (Node*& node, Direction dir);
    void updateBalance  (Node* tree,  Direction dir);
    void rebalanceInsert(Node*& tree, Direction dir,bool& hChanged);
    void rebalanceRemove(Node*& tree, Direction dir, bool& hChanged);
    void insert(const string& key, const int& value,Node*& node, bool& hChanged);
    bool remove(const string& chave, Node*& node,bool& hChanged);
    inline Direction opposite(Direction dir);

public:

    AvlTree();
    ~AvlTree();
    void Insert(const string& key, const int& value);
    bool Remove(const string& value);
    bool Search(const string& key, int & value);
    void Clear();
    void Print();

};


#endif // AVLTREE_H
