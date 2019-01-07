//
//  BNode.h
//  database
//
//  Created by Celine Seghbossian on 6/15/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database_BNode_h
#define database_BNode_h

template <typename T>
struct Bnode
{
    Bnode();
    ~Bnode();
    Bnode(const Bnode& other);
    Bnode(T item);
    Bnode(T item, Bnode<T>* l, Bnode<T>* r);
    Bnode& operator = (const Bnode& other);
    
    //variables
    T data;
    Bnode<T>* left;
    Bnode<T>* right;
};

template <typename T>
Bnode<T>:: Bnode()
{
    data = T();
    left = NULL;
    right = NULL;
}

template <typename T>
Bnode<T>:: ~Bnode()
{
    data = T();
    left = NULL;
    right = NULL;
}

template <typename T>
Bnode<T>:: Bnode(const Bnode& other)
{
    data = other.data;
}

template <typename T>
Bnode<T>:: Bnode(T item)
{
    data = item;
    left = NULL;
    right = NULL;
}

template <typename T>
Bnode<T>:: Bnode(T item, Bnode<T>* l, Bnode<T>* r)
{
    data = item;
    left = l;
    right = r;
}

template <typename T>
Bnode<T>& Bnode<T>:: operator = (const Bnode& other)
{
    data = other.data;
    return *this;
}

#endif
