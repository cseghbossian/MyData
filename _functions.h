////
////  _build_tree.h
////  database
////
////  Created by Celine Seghbossian on 5/23/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database__build_tree_h
//#define database__build_tree_h
//
//#include "dataNode.h"
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PARSE TREE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//
//dataNode* _get_select(vector<string> v, int &pos);
//    dataNode* _get_cols(vector<string> v, int &pos);
//    dataNode* _get_from(vector<string> v, int &pos);
//    dataNode* _get_where(vector<string> v, int &pos);
//dataNode* _get_load(vector<string> v, int &pos);
//dataNode* _get_store(vector<string> v, int &pos);
//dataNode* _get_drop(vector<string> v, int &pos);
//dataNode* _get_print(vector<string> v, int &pos);
//dataNode* _get_create(vector<string> v, int &pos);
//dataNode* _get_insert(vector<string> v, int &pos);
//    dataNode* _get_values(vector<string> v, int &pos);
//
//void _print_parse_tree(dataNode* head, int level = 0);
//
//
//dataNode* _get_select(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of "select" in the vector, v
// * - columns to be selected are NOT separated by commas.
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "select"
// * - this node has the children: "columns", "from", and possibly "where"
// * - pos is the index of the word after "select" (the first column name)
// */
//{
//    if(v[pos] != "select")
//        return NULL;
//    dataNode* temp = new dataNode("select");
//    temp->children[0] = _get_cols(v, ++pos);
//    temp->children[1] = _get_from(v, pos);
//    temp->children[2] = _get_where(v, pos);
//    return temp;
//}
//
//dataNode* _get_cols(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of the entry after "select" (the first column name) in the vector, v
// * 
// * Post-Conditions:
// * - creates and returns a new node containing the string "columns"
// * - this node has at least one child containing the name of a column to be selected
// * - pos is the index of "from" in the vector, v
// */
//{
//    dataNode* temp = new dataNode("columns");
//    int i = 0;
//    
//    while(v[pos] != "from" && pos < v.size())
//    {
//        dataNode* n = new dataNode(v[pos]);
//        temp->children[i] = n;
//        ++i;
//        ++pos;
//    }
//    
//    return temp;
//}
//
//
//dataNode* _get_from(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of "from" in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "from"
// * - this node has exactly one child containing the table name
// * - pos is the index of "where" in the vector, v
// */
//{
//    if(v[pos] != "from")
//        return NULL;
//    dataNode* temp = new dataNode("from");
//    temp->children[0] = new dataNode(v[++pos]);
//    ++pos;
//    return temp;
//}
//
//
//dataNode* _get_where(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of "where" in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "where"
// * - if there are no conditions, the function returns NULL
// * - otherwise, the node has ond child containing an expression tree 
// *   - NOTE: this function should later be modified to handle multiple conditions
// * - pos is the index of the last word in the vector, v
// */
//{
//    if(v[pos] != "where")
//        return NULL;
//    dataNode* temp = new dataNode("where");
//    dataNode* left = new dataNode(v[++pos]);
//    temp->children[0] = new dataNode(v[++pos]);
//    temp->children[0]->children[0] = left;
//    temp->children[0]->children[1] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_load(vector<string> v, int &pos)
///* Pre-Conditions:
// * - pos is the index of "where" in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "where"
// * - if there are no conditions, the function returns NULL
// * - otherwise, the node has ond child containing an expression tree
// *   - NOTE: this function should later be modified to handle multiple conditions
// * - pos is the index of the last word in the vector, v
// */
//{
//    if(v[pos] != "load")
//        return NULL;
//    dataNode* temp = new dataNode("load");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//dataNode* _get_store(vector<string> v, int &pos)
//{
//    if(v[pos] != "store")
//        return NULL;
//    dataNode* temp = new dataNode("store");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_drop(vector<string> v, int &pos)
//{
//    if(v[pos] != "drop")
//        return NULL;
//    dataNode* temp = new dataNode("drop");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_print(vector<string> v, int &pos)
//{
//    if(v[pos] != "print")
//        return NULL;
//    dataNode* temp = new dataNode("print");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_create(vector<string> v, int &pos)
//{
//    if(v[pos] != "create")
//        return NULL;
//    if(v[++pos] != "table")
//    {
//        --pos;
//        return NULL;
//    }
//    
//    dataNode* temp = new dataNode("create table");
//    
//    if(v[pos+2] == "as")
//    {
//        temp->children[0] = new dataNode(v[++pos]);
//        ++pos;
//        temp->children[1] = _get_select(v, ++pos);
//    }
//    else
//    {
//        temp = new dataNode("create table");
//        temp->children[0] = new dataNode(v[++pos]);
//        //cout<<"DEBUG: the tName is being stored as ("<<v[pos]<<")"<<endl;
//        temp->children[1] = _get_values(v, pos);
//    }
//    return temp;
//}
//
//dataNode* _get_insert(vector<string> v, int &pos)
//{
//    if(v[pos] != "insert")
//        return NULL;
//    if(v[++pos] != "into")
//    {
//        --pos;
//        return NULL;
//    }
//    
//    dataNode* temp = new dataNode("insert into");
//    temp->children[0] = new dataNode("table");
//    temp->children[0]->children[0] = new dataNode(v[++pos]);
//    temp->children[1] = _get_values(v, ++pos);
//    return temp;
//}
//
//dataNode* _get_values(vector<string> v, int &pos)
//{
//    dataNode* temp = new dataNode("values");
//    int i = 0;
//    while (pos < v.size()-1)
//    {
//        temp->children[i] = new dataNode(v[++pos]);
//        ++i;
//    }
//    return temp;
//}
//
//vector<string> _change_children_to_vector(dataNode* mama)
//{
//    int i = 0;
//    vector<string> kids;
//    while(mama->children[i])
//    {
//        kids.push_back(mama->children[i]->name);
//        ++i;
//    }
//    return kids;
//}
//
//void _print_parse_tree(dataNode* head, int level)
//{
//    
//    for(int i = 0; i < level*2; ++i)
//        cout<<" ";
//    cout<<head->name<<endl;
//    
//    int i = 0;
//    while(head->children[i] != NULL)
//    {
//        _print_parse_tree(head->children[i], level+2);
//        ++i;
//    }
//}
//
//
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LIST FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//template <typename T>
//void _insert_sorted(list<T>& l, T data)
///* Pre-Conditions:
// * - l is a list that is sorted from least to greatest
// *
// * Post-Conditions:
// * - data is inserted into l, keeping it sorted
// * - duplicate insertions are allowed
// */
//{
//
//    typename list<T>::iterator i = l.begin();
//    while(i != l.end() && *i < data)
//        ++i;
//    l.insert(i, data);
//}
//
//template<typename T>
//void _print(list<T> l)
///* Pre-Conditions:
// * - l is a list
// *
// * Post-Conditions:
// * - prints elements of list separated by spaces and followed by list size
// */
//{
//    for (typename list<T>::iterator i=l.begin(); i != l.end(); ++i)
//        cout << ' ' << *i;
//    cout << " [size: "<<l.size()<<"]"<<endl;
//}
//
//
//
//
//
//
//
//
//#endif
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
////
////  _build_tree.h
////  database
////
////  Created by Celine Seghbossian on 5/23/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database__build_tree_h
//#define database__build_tree_h
//
//#include "dataNode.h"
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PARSE TREE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//
//dataNode* _get_select(vector<string> v, int &pos);
//dataNode* _get_cols(vector<string> v, int &pos);
//dataNode* _get_from(vector<string> v, int &pos);
//dataNode* _get_where(vector<string> v, int &pos);
//dataNode* _get_load(vector<string> v, int &pos);
//dataNode* _get_store(vector<string> v, int &pos);
//dataNode* _get_drop(vector<string> v, int &pos);
//dataNode* _get_print(vector<string> v, int &pos);
//dataNode* _get_create(vector<string> v, int &pos);
//dataNode* _get_insert(vector<string> v, int &pos);
//dataNode* _get_values(vector<string> v, int &pos);
//
//void _print_parse_tree(dataNode* head, int level = 0);
//
//
//dataNode* _get_select(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of "select" in the vector, v
// * - columns to be selected are NOT separated by commas.
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "select"
// * - this node has the children: "columns", "from", and possibly "where"
// * - pos is the index of the word after "select" (the first column name)
// */
//{
//    if(v[pos] != "select")
//        return NULL;
//    dataNode* temp = new dataNode("select");
//    temp->children[0] = _get_cols(v, ++pos);
//    temp->children[1] = _get_from(v, pos);
//    temp->children[2] = _get_where(v, pos);
//    return temp;
//}
//
//dataNode* _get_cols(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of the entry after "select" (the first column name) in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "columns"
// * - this node has at least one child containing the name of a column to be selected
// * - pos is the index of "from" in the vector, v
// */
//{
//    dataNode* temp = new dataNode("columns");
//    int i = 0;
//    
//    while(v[pos] != "from" && pos < v.size())
//    {
//        dataNode* n = new dataNode(v[pos]);
//        temp->children[i] = n;
//        ++i;
//        ++pos;
//    }
//    
//    return temp;
//}
//
//
//dataNode* _get_from(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of "from" in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "from"
// * - this node has exactly one child containing the table name
// * - pos is the index of "where" in the vector, v
// */
//{
//    if(v[pos] != "from")
//        return NULL;
//    dataNode* temp = new dataNode("from");
//    temp->children[0] = new dataNode(v[++pos]);
//    ++pos;
//    return temp;
//}
//
//
//dataNode* _get_where(vector<string> v, int& pos)
///* Pre-Conditions:
// * - pos is the index of "where" in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "where"
// * - if there are no conditions, the function returns NULL
// * - otherwise, the node has ond child containing an expression tree
// *   - NOTE: this function should later be modified to handle multiple conditions
// * - pos is the index of the last word in the vector, v
// */
//{
//    if(v[pos] != "where")
//        return NULL;
//    dataNode* temp = new dataNode("where");
//    dataNode* left = new dataNode(v[++pos]);
//    temp->children[0] = new dataNode(v[++pos]);
//    temp->children[0]->children[0] = left;
//    temp->children[0]->children[1] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_load(vector<string> v, int &pos)
///* Pre-Conditions:
// * - pos is the index of "where" in the vector, v
// *
// * Post-Conditions:
// * - creates and returns a new node containing the string "where"
// * - if there are no conditions, the function returns NULL
// * - otherwise, the node has ond child containing an expression tree
// *   - NOTE: this function should later be modified to handle multiple conditions
// * - pos is the index of the last word in the vector, v
// */
//{
//    if(v[pos] != "load")
//        return NULL;
//    dataNode* temp = new dataNode("load");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//dataNode* _get_store(vector<string> v, int &pos)
//{
//    if(v[pos] != "store")
//        return NULL;
//    dataNode* temp = new dataNode("store");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_drop(vector<string> v, int &pos)
//{
//    if(v[pos] != "drop")
//        return NULL;
//    dataNode* temp = new dataNode("drop");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_print(vector<string> v, int &pos)
//{
//    if(v[pos] != "print")
//        return NULL;
//    dataNode* temp = new dataNode("print");
//    temp->children[0] = new dataNode(v[++pos]);
//    return temp;
//}
//
//dataNode* _get_create(vector<string> v, int &pos)
//{
//    if(v[pos] != "create")
//        return NULL;
//    if(v[++pos] != "table")
//    {
//        --pos;
//        return NULL;
//    }
//    
//    dataNode* temp = new dataNode("create table");
//    
//    if(v[pos+2] == "as")
//    {
//        temp->children[0] = new dataNode(v[++pos]);
//        ++pos;
//        temp->children[1] = _get_select(v, ++pos);
//    }
//    else
//    {
//        temp = new dataNode("create table");
//        temp->children[0] = new dataNode(v[++pos]);
//        //cout<<"DEBUG: the tName is being stored as ("<<v[pos]<<")"<<endl;
//        temp->children[1] = _get_values(v, pos);
//    }
//    return temp;
//}
//
//dataNode* _get_insert(vector<string> v, int &pos)
//{
//    if(v[pos] != "insert")
//        return NULL;
//    if(v[++pos] != "into")
//    {
//        --pos;
//        return NULL;
//    }
//    
//    dataNode* temp = new dataNode("insert into");
//    temp->children[0] = new dataNode("table");
//    temp->children[0]->children[0] = new dataNode(v[++pos]);
//    temp->children[1] = _get_values(v, ++pos);
//    return temp;
//}
//
//dataNode* _get_values(vector<string> v, int &pos)
//{
//    dataNode* temp = new dataNode("values");
//    int i = 0;
//    while (pos < v.size()-1)
//    {
//        temp->children[i] = new dataNode(v[++pos]);
//        ++i;
//    }
//    return temp;
//}
//
//vector<string> _change_children_to_vector(dataNode* mama)
//{
//    int i = 0;
//    vector<string> kids;
//    while(mama->children[i])
//    {
//        kids.push_back(mama->children[i]->name);
//        ++i;
//    }
//    return kids;
//}
//
//void _print_parse_tree(dataNode* head, int level)
//{
//    
//    for(int i = 0; i < level*2; ++i)
//        cout<<" ";
//    cout<<head->name<<endl;
//    
//    int i = 0;
//    while(head->children[i] != NULL)
//    {
//        _print_parse_tree(head->children[i], level+2);
//        ++i;
//    }
//}
//
//
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LIST FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//template <typename T>
//void _insert_sorted(list<T>& l, T data)
///* Pre-Conditions:
// * - l is a list that is sorted from least to greatest
// *
// * Post-Conditions:
// * - data is inserted into l, keeping it sorted
// * - duplicate insertions are allowed
// */
//{
//    
//    typename list<T>::iterator i = l.begin();
//    while(i != l.end() && *i < data)
//        ++i;
//    l.insert(i, data);
//}
//
//template<typename T>
//void _print(list<T> l)
///* Pre-Conditions:
// * - l is a list
// *
// * Post-Conditions:
// * - prints elements of list separated by spaces and followed by list size
// */
//{
//    for (typename list<T>::iterator i=l.begin(); i != l.end(); ++i)
//        cout << ' ' << *i;
//    cout << " [size: "<<l.size()<<"]"<<endl;
//}
//
//
//
//
//
//
//
//
//#endif
//


//
//  _build_tree.h
//  database
//
//  Created by Celine Seghbossian on 5/23/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database__build_tree_h
#define database__build_tree_h

#include "dataNode.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PARSE TREE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


dataNode* _get_select(vector<string> v, int &pos);
dataNode* _get_cols(vector<string> v, int &pos);
dataNode* _get_from(vector<string> v, int &pos);
dataNode* _get_where(vector<string> v, int &pos);
dataNode* _get_load(vector<string> v, int &pos);
dataNode* _get_store(vector<string> v, int &pos);
dataNode* _get_drop(vector<string> v, int &pos);
dataNode* _get_print(vector<string> v, int &pos);
dataNode* _get_create(vector<string> v, int &pos);
dataNode* _get_insert(vector<string> v, int &pos);
dataNode* _get_values(vector<string> v, int &pos);

void _print_parse_tree(dataNode* head, int level = 0);


dataNode* _get_select(vector<string> v, int& pos)
/* Pre-Conditions:
 * - pos is the index of "select" in the vector, v
 * - columns to be selected are NOT separated by commas.
 *
 * Post-Conditions:
 * - creates and returns a new node containing the string "select"
 * - this node has the children: "columns", "from", and possibly "where"
 * - pos is the index of the word after "select" (the first column name)
 */
{
    if(v[pos] != "select")
        return NULL;
    dataNode* temp = new dataNode("select");
    temp->children[0] = _get_cols(v, ++pos);
    temp->children[1] = _get_from(v, pos);
    temp->children[2] = _get_where(v, pos);
    return temp;
}

dataNode* _get_cols(vector<string> v, int& pos)
/* Pre-Conditions:
 * - pos is the index of the entry after "select" (the first column name) in the vector, v
 *
 * Post-Conditions:
 * - creates and returns a new node containing the string "columns"
 * - this node has at least one child containing the name of a column to be selected
 * - pos is the index of "from" in the vector, v
 */
{
    dataNode* temp = new dataNode("columns");
    int i = 0;
    
    while(v[pos] != "from" && pos < v.size())
    {
        dataNode* n = new dataNode(v[pos]);
        temp->children[i] = n;
        ++i;
        ++pos;
    }
    
    return temp;
}


dataNode* _get_from(vector<string> v, int& pos)
/* Pre-Conditions:
 * - pos is the index of "from" in the vector, v
 *
 * Post-Conditions:
 * - creates and returns a new node containing the string "from"
 * - this node has exactly one child containing the table name
 * - pos is the index of "where" in the vector, v
 */
{
    if(v[pos] != "from")
        return NULL;
    dataNode* temp = new dataNode("from");
    temp->children[0] = new dataNode(v[++pos]);
    ++pos;
    return temp;
}


dataNode* _get_where(vector<string> v, int& pos)
/* Pre-Conditions:
 * - pos is the index of "where" in the vector, v
 *
 * Post-Conditions:
 * - creates and returns a new node containing the string "where"
 * - if there are no conditions, the function returns NULL
 * - otherwise, the node has ond child containing an expression tree
 *   - NOTE: this function should later be modified to handle multiple conditions
 * - pos is the index of the last word in the vector, v
 */
{
    if(v[pos] != "where")
        return NULL;
    dataNode* temp = new dataNode("where");
    dataNode* left = new dataNode(v[++pos]);
    temp->children[0] = new dataNode(v[++pos]);
    temp->children[0]->children[0] = left;
    temp->children[0]->children[1] = new dataNode(v[++pos]);
    return temp;
}

dataNode* _get_load(vector<string> v, int &pos)
/* Pre-Conditions:
 * - pos is the index of "where" in the vector, v
 *
 * Post-Conditions:
 * - creates and returns a new node containing the string "where"
 * - if there are no conditions, the function returns NULL
 * - otherwise, the node has ond child containing an expression tree
 *   - NOTE: this function should later be modified to handle multiple conditions
 * - pos is the index of the last word in the vector, v
 */
{
    if(v[pos] != "load")
        return NULL;
    dataNode* temp = new dataNode("load");
    temp->children[0] = new dataNode(v[++pos]);
    return temp;
}
dataNode* _get_store(vector<string> v, int &pos)
{
    if(v[pos] != "store")
        return NULL;
    dataNode* temp = new dataNode("store");
    temp->children[0] = new dataNode(v[++pos]);
    return temp;
}

dataNode* _get_drop(vector<string> v, int &pos)
{
    if(v[pos] != "drop")
        return NULL;
    dataNode* temp = new dataNode("drop");
    temp->children[0] = new dataNode(v[++pos]);
    return temp;
}

dataNode* _get_print(vector<string> v, int &pos)
{
    if(v[pos] != "print")
        return NULL;
    dataNode* temp = new dataNode("print");
    temp->children[0] = new dataNode(v[++pos]);
    return temp;
}

dataNode* _get_create(vector<string> v, int &pos)
{
    if(v[pos] != "create")
        return NULL;
    if(v[++pos] != "table")
    {
        --pos;
        return NULL;
    }
    
    dataNode* temp = new dataNode("create table");
    
    if(v[pos+2] == "as")
    {
        temp->children[0] = new dataNode(v[++pos]);
        ++pos;
        temp->children[1] = _get_select(v, ++pos);
    }
    else
    {
        temp = new dataNode("create table");
        temp->children[0] = new dataNode(v[++pos]);
        //cout<<"DEBUG: the tName is being stored as ("<<v[pos]<<")"<<endl;
        temp->children[1] = _get_values(v, pos);
    }
    return temp;
}

dataNode* _get_insert(vector<string> v, int &pos)
{
    if(v[pos] != "insert")
        return NULL;
    if(v[++pos] != "into")
    {
        --pos;
        return NULL;
    }
    
    dataNode* temp = new dataNode("insert into");
    temp->children[0] = new dataNode("table");
    temp->children[0]->children[0] = new dataNode(v[++pos]);
    temp->children[1] = _get_values(v, ++pos);
    return temp;
}

dataNode* _get_values(vector<string> v, int &pos)
{
    dataNode* temp = new dataNode("values");
    int i = 0;
    while (pos < v.size()-1)
    {
        temp->children[i] = new dataNode(v[++pos]);
        ++i;
    }
    return temp;
}

vector<string> _change_children_to_vector(dataNode* mama)
{
    int i = 0;
    vector<string> kids;
    while(mama->children[i])
    {
        kids.push_back(mama->children[i]->name);
        ++i;
    }
    return kids;
}

void _print_parse_tree(dataNode* head, int level)
{
    
    for(int i = 0; i < level*2; ++i)
        cout<<" ";
    cout<<head->name<<endl;
    
    int i = 0;
    while(head->children[i] != NULL)
    {
        _print_parse_tree(head->children[i], level+2);
        ++i;
    }
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LIST FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template <typename T>
void _insert_sorted(list<T>& l, T data)
/* Pre-Conditions:
 * - l is a list that is sorted from least to greatest
 *
 * Post-Conditions:
 * - data is inserted into l, keeping it sorted
 * - duplicate insertions are allowed
 */
{
    
    typename list<T>::iterator i = l.begin();
    while(i != l.end() && *i < data)
        ++i;
    l.insert(i, data);
}

template<typename T>
void _print(list<T> l)
/* Pre-Conditions:
 * - l is a list
 *
 * Post-Conditions:
 * - prints elements of list separated by spaces and followed by list size
 */
{
    for (typename list<T>::iterator i=l.begin(); i != l.end(); ++i)
        cout << ' ' << *i;
    cout << " [size: "<<l.size()<<"]"<<endl;
}








#endif

