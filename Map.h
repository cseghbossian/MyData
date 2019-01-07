////
////  Map.h
////  database
////
////  Created by Celine Seghbossian on 6/1/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database_Map_h
//#define database_Map_h
//
//#include <list>
//#include "BSet.h"
//using namespace std;
//
//template <typename K, typename V>
//struct Pair
//{
//    Pair();
//    ~Pair();
//    Pair(const Pair& other);
//    Pair(K keyy, list<V> valuess); //coconut
//    Pair& operator =(const Pair& other);
//    bool operator <(Pair& other);
//    void push(V value);
//    void print();
//
//    K key;
//    list<V> values;
//    //BSet<V> values; //coconut
//};
//
//template <typename K, typename V>
//Pair<K,V>:: Pair()
//{
//    key = K();
//    //values = BSet<V>(); //coconut
//}
//
//template <typename K, typename V>
//Pair<K,V>:: ~Pair()
//{
//    key = K();
//    values.clear();
//}
//
//template <typename K, typename V>
//Pair<K,V>:: Pair(const Pair& other)
//{
//    key = other.key;
//    values = other.values;
//}
//
//template <typename K, typename V>
//Pair<K,V>:: Pair(K keyy, list<V> valuess) //coconut
//{
//    key = keyy;
//    values = valuess;
//}
//
//template <typename K, typename V>
//Pair<K,V>& Pair<K,V>:: operator =(const Pair& other)
//{
//    key = other.key;
//    values = other.values;
//    return *this;
//}
//
//template <typename K, typename V>
//bool Pair<K,V>:: operator <(Pair<K,V> & other)
//{
//    return key < other.key;
//}
//
//template <typename K, typename V>
//void Pair<K,V>:: push(V value)
//{
//    values.push_back(value);
//    //values.insert(value); //coconut
//}
//
//template <typename K, typename V>
//void Pair<K,V>:: print()
//{
//    cout<<"["<<key<<":";
//    for(typename list<V>::iterator i = values.begin(); i != values.end(); ++i)
//        cout<<" "<<*i;
//    cout<<"]"<<endl;
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//template <typename K, typename V>
//class Map
//{
//public:
//    Map();
//    ~Map();
//    Map(const Map& other);
//    Map& operator=(const Map& other);
//    list<V>& operator[](K key);
//    bool push(K key, V value);
//    bool erase(K keyy);
//    typename list<Pair<K,V>>::iterator search(K keyy);
//    void print();
//    
//    
//private:
//    list<Pair<K,V>> data; //sorted list
//};
//
//template <typename K, typename V>
//Map<K,V>:: Map()
//{
//    
//}
//
//template <typename K, typename V>
//Map<K,V>:: ~Map()
//{
//    data.clear();
//}
//
//template <typename K, typename V>
//Map<K,V>:: Map(const Map& other)
//{
//    data = other.data;
//}
//
//template <typename K, typename V>
//Map<K,V>& Map<K,V>:: operator=(const Map& other)
//{
//    data = other.data;
//    return *this;
//}
//
//template <typename K, typename V>
//list<V>& Map<K,V>:: operator[](K keyy)
//{
//    list<V> temp;
//    for(typename list<Pair<K,V>>::iterator i = data.begin(); i != data.end(); ++i)
//        if((*i).key == keyy)
//        {
//            cout<<"found the key!"<<endl;
//            return (*i).values;
//        }
//    return temp;
//}
//
//template <typename K, typename V>
//bool Map<K,V>:: push(K key, V value)
//{
//    //search data for key
//    //if key exists, get iterator to that pair and push value into pair
//    //if key doesnt exist, create a pair and insert it into data
//    
//    typename list<Pair<K,V>>::iterator i = search(key);
//    if (i != data.end())
//    {
//        (*i).push(value);
//        return true;
//    }
//    else
//    {
//        list<V> l;
//        l.push_back(value);
//        Pair<K,V> temp (key,l);
//        _insert_sorted(data, temp);
//        return false;
//    }
//    
//}
//
//template <typename K, typename V>
//bool Map<K,V>:: erase(K keyy)
//{
//    typename list<Pair<K,V>>::iterator i = search(keyy);
//
//    if(i == data.end())
//        return false;
//    else
//    {
//        data.erase(i);
//        return true;
//    }
//}
//
//template <typename K, typename V>
//typename list<Pair<K,V>>::iterator Map<K,V>:: search(K keyy)
//{
//    typename list<Pair<K,V>>::iterator i = data.begin();
//    while(i != data.end() && (*i).key != keyy)
//        ++i;
//    return i;
//}
//
//template <typename K, typename V>
//void Map<K,V>:: print()
//{
//    for(typename list<Pair<K,V>>::iterator i = data.begin(); i != data.end(); ++i)
//        (*i).print();
//}
//
//#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//
//  Map.h
//  database
//
//  Created by Celine Seghbossian on 6/1/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database_Map_h
#define database_Map_h

#include <list>
#include "BTree.h"
using namespace std;

template <typename K, typename V>
struct Pair
{
    Pair();
    ~Pair();
    Pair(const Pair& other);
    Pair(K keyy, list<V> valuess);
    Pair& operator =(const Pair& other);
    bool operator <(Pair& other);
    template <typename KK, typename VV>
    friend bool operator==(const Pair<KK,VV> &left, const Pair<KK,VV> &right);
    void push(V value);
    void print();
    template <typename KK, typename VV> friend
    ostream& operator<<(ostream& os, Pair<KK,VV> p);
    
    K key;
    list <V> values;
};

template <typename K, typename V>
Pair<K,V>:: Pair()
{
    key = K();
    values = list<V>();
}

template <typename K, typename V>
Pair<K,V>:: ~Pair()
{
    key = K();
    values.clear();
}

template <typename K, typename V>
Pair<K,V>:: Pair(const Pair& other)
{
    key = other.key;
    values = other.values;
}

template <typename K, typename V>
Pair<K,V>:: Pair(K keyy, list<V> valuess)
{
    key = keyy;
    values = valuess;
}

template <typename K, typename V>
Pair<K,V>& Pair<K,V>:: operator =(const Pair& other)
{
    key = other.key;
    values = other.values;
    return *this;
}

template <typename K, typename V>
bool Pair<K,V>:: operator <(Pair<K,V> & other)
{
    return key < other.key;
}

template <typename KK, typename VV>
bool operator==(const Pair<KK,VV> &left, const Pair<KK,VV> &right)
{
    return (left.key == right.key);
}

template <typename K, typename V>
void Pair<K,V>:: push(V value)
{
    values.push_back(value);
}

template <typename K, typename V>
void Pair<K,V>:: print()
{
    cout<<"["<<key<<":";
    for(typename list<V>::iterator i = values.begin(); i != values.end(); ++i)
        cout<<" "<<*i;
    cout<<"]"<<endl;
}

template <typename KK, typename VV>
ostream& operator<<(ostream& os, Pair<KK,VV> p)
{
    p.print();
    return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template <typename K, typename V>
class Map
{
public:
    Map();
    ~Map();
    Map(const Map& other);
    Map& operator=(const Map& other);
    list<V> operator[](K key);
    bool push(K key, V value);
    bool erase(K keyy);
    BTree<Pair<K,V>>* search(K keyy);
    void print();
    
    
private:
    BTree<Pair<K,V>> data; //sorted list
};

template <typename K, typename V>
Map<K,V>:: Map()
{

}

template <typename K, typename V>
Map<K,V>:: ~Map()
{
    data.clear();
}

template <typename K, typename V>
Map<K,V>:: Map(const Map& other)
{
    data = other.data;
}

template <typename K, typename V>
Map<K,V>& Map<K,V>:: operator=(const Map& other)
{
    data = other.data;
    return *this;
}

template <typename K, typename V>
list<V> Map<K,V>:: operator[](K keyy)
{
    list<V> temp;
    Pair<K,V> p(keyy, list<V>());
    if(!data.search(p))
    {
        
        return list<V>();
    }
    return (data.search(p))->data.values;
}

template <typename K, typename V>
bool Map<K,V>:: push(K key, V value)
{
    //search data for key
    //if key exists, get iterator to that pair and push value into pair
    //if key doesnt exist, create a pair and insert it into data
    
    Pair<K,V> p(key, list<V>());

    if(!data.search(p))
    {
        p.push(value);
        data.insert(p);
        return false;
    }
    else
    {
        Bnode<Pair<K,V>>* temp = data.search(p);
        temp->data.values.push_back(value);
        return true;
    }
    
    
}

template <typename K, typename V>
void Map<K,V>:: print()
{
    cout<<data;
}

#endif

////
////  Map.h
////  database
////
////  Created by Celine Seghbossian on 6/1/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database_Map_h
//#define database_Map_h
//
//#include <list>
//#include "_functions.h"
//#include "BSet.h"
//using namespace std;
//
//template <typename K, typename V>
//struct Pair
//{
//    Pair();
//    ~Pair();
//    Pair(const Pair& other);
//    Pair(K keyy, list<V> valuess);
//    Pair& operator =(const Pair& other);
//    bool operator <(Pair& other);
//    bool operator >(Pair& other);
//    template <typename KK, typename VV>
//    friend bool operator==(const Pair<KK,VV> &left, const Pair<KK,VV> &right);
//    void push(V value);
//    void print();
//    template <typename KK, typename VV> friend
//    ostream& operator<<(ostream& os, Pair<KK,VV> p);
//    
//    K key;
//    list <V> values;
//};
//
//template <typename K, typename V>
//Pair<K,V>:: Pair()
//{
//    key = K();
//    values = list<V>();
//}
//
//template <typename K, typename V>
//Pair<K,V>:: ~Pair()
//{
//    key = K();
//    values.clear();
//}
//
//template <typename K, typename V>
//Pair<K,V>:: Pair(const Pair& other)
//{
//    key = other.key;
//    values = other.values;
//}
//
//template <typename K, typename V>
//Pair<K,V>:: Pair(K keyy, list<V> valuess)
//{
//    key = keyy;
//    values = valuess;
//}
//
//template <typename K, typename V>
//Pair<K,V>& Pair<K,V>:: operator =(const Pair& other)
//{
//    key = other.key;
//    values = other.values;
//    return *this;
//}
//
//template <typename K, typename V>
//bool Pair<K,V>:: operator <(Pair<K,V> & other)
//{
//    return key < other.key;
//}
//
//template <typename K, typename V>
//bool Pair<K,V>:: operator >(Pair<K,V> & other)
//{
//    return key > other.key;
//}
//
//template <typename KK, typename VV>
//bool operator==(const Pair<KK,VV> &left, const Pair<KK,VV> &right)
//{
//    return (left.key == right.key);
//}
//
//template <typename K, typename V>
//void Pair<K,V>:: push(V value)
//{
//    values.push_back(value);
//}
//
//template <typename K, typename V>
//void Pair<K,V>:: print()
//{
//    cout<<"["<<key<<":";
//    for(typename list<V>::iterator i = values.begin(); i != values.end(); ++i)
//        cout<<" "<<*i;
//    cout<<"]"<<endl;
//}
//
//template <typename KK, typename VV>
//ostream& operator<<(ostream& os, Pair<KK,VV> p)
//{
//    p.print();
//    return os;
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//template <typename K, typename V>
//class Map
//{
//public:
//    Map();
//    ~Map();
//    Map(const Map& other);
//    Map& operator=(const Map& other);
//    list<V> operator[](K key);
//    bool push(K key, V value);
//    bool erase(K keyy);
//    BSet<Pair<K,V>>* search(K keyy);
//    void print();
//    
//    
//private:
//    BSet<Pair<K,V>> data; //sorted list
//};
//
//template <typename K, typename V>
//Map<K,V>:: Map()
//{
//    
//}
//
//template <typename K, typename V>
//Map<K,V>:: ~Map()
//{
//    data.clear();
//}
//
//template <typename K, typename V>
//Map<K,V>:: Map(const Map& other)
//{
//    data = other.data;
//}
//
//template <typename K, typename V>
//Map<K,V>& Map<K,V>:: operator=(const Map& other)
//{
//    data = other.data;
//    return *this;
//}
//
//template <typename K, typename V>
//list<V> Map<K,V>:: operator[](K keyy)
//{
//    list<V> temp;
//    Pair<K,V> p(keyy, list<V>());
//    if(!data.search(p))
//        return list<V>();
//    
//    int i;
//    cout<<"DEBUG: key: "<<keyy<<" values: ";
//    _print((data.find(p, i))->getValueAt(i).values);
//    return (data.find(p, i))->getValueAt(i).values;
//}
//
//template <typename K, typename V>
//bool Map<K,V>:: push(K key, V value)
//{
//    //search data for key
//    //if key exists, get iterator to that pair and push value into pair
//    //if key doesnt exist, create a pair and insert it into data
//    
//    Pair<K,V> p(key, list<V>());
//    
//    if(!data.search(p))
//    {
//        p.push(value);
//        data.insert(p);
//        cout<<"DEBUG: printing..."<<endl;
//        data.print(8);
//        return false;
//    }
//    else
//    {
//        int i;
//        BSet<Pair<K,V>>* temp = data.find(p, i);
//        ((temp->getValueAt(i)).values).push_back(value);
//        return true;
//    }
//}
//
//template <typename K, typename V>
//void Map<K,V>:: print()
//{
//    data.print();
//}
//
//#endif
