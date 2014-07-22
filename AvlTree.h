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
    void insert(const int value, Node *node, bool hChanged);
    bool remove(const int value, Node *node, bool hChanged);
    inline Direction opposite(Direction dir);

public:

    AvlTree();
    ~AvlTree();
    void Insert(const int& value);
    bool Remove(const int& value);
    bool Search(int &value);
    void Clear();
    void print(Node *root, int level);
    Node* getRoot();

};


#endif // AVLTREE_H
