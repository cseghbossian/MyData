//
//  BTree.h
//  database
//
//  Created by Celine Seghbossian on 6/14/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database_BTree_h
#define database_BTree_h

#include <stdio.h>
#include "Bnode.h"
#include "_b_tree_functions.h"

template <typename T>
class BTree
{
public:
    BTree();
    BTree(const BTree<T> &other);
    ~BTree();
    BTree<T>& operator = (const BTree& other);
    void insert(T item);
    Bnode<T>* search(T item);
    void remove(T item);
    template <typename U> friend
    ostream& operator << (ostream& out, const BTree<U> print);
    void clear();
    
private:
    Bnode<T>* root;
    long size;
};

template <typename T>
BTree<T>:: BTree()
{
    root = NULL;
    size = 0;
}

template <typename T>
BTree<T>:: BTree(const BTree<T> &other)
{
    Bnode<T>* hello = other.root;
    root = _copy(hello);
    size = other.size;
}

template <typename T>
BTree<T>:: ~BTree<T>()
{
    _clear(root);
    size = 0;
}
template <typename T>
BTree<T>& BTree<T>:: operator = (const BTree<T> &other)
{
    Bnode<T>* hello = other.root;
    root = _copy(hello);
    size = other.size;
    return *this;
}

template <typename T>
void BTree<T>:: insert(T item)
{
    _b_insert(root, item);
    ++size;
}

template <typename T>
Bnode<T>* BTree<T>:: search(T item)
{
    return _search(root, item);
}

template <typename T>
void BTree<T>:: remove(T item)
{
    _b_delete(root, item);
    --size;
}

template <typename U>
ostream& operator << (ostream& outs, const BTree<U> print)
{
    _print(outs, print.root);
    return outs;
}

template <typename T>
void BTree<T>:: clear()
{
    _clear(root);
    size = 0;
}

#endif
