////
////  _test_database_functions.h
////  database
////
////  Created by Celine Seghbossian on 6/4/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database__test_database_functions_h
//#define database__test_database_functions_h
//
//#include "database.h"
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PARSE TREE FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//void _test_parse_get_create()
//{
//    cout<<endl<<"***** TESTING PARSE GET SELECT *****"<<endl;
//    
//    cout<<"input vector of strings: create, table, tName, as, select, *, from, tName, where, lName, ==, Seghbossian"<<endl;
//    
//    vector<string> v = {"create", "table", "tName", "as", "select", "*", "from", "tName", "where", "lName", "==", "Seghbossian"};
//    int pos = 0;
//    dataNode* dude = _get_create(v, pos);
//    _print_parse_tree(dude);
//    
//    cout<<"input vector of strings: create, table, tName, fName, lName"<<endl;
//
//    vector<string> u = {"create", "table", "tName", "fName", "lName"};
//    int poss = 0;
//    dataNode* bro = _get_create(u, poss);
//    _print_parse_tree(bro);
//}
//
//void _test_parse_get_load()
//{
//    cout<<endl<<"***** TESTING PARSE GET LOAD *****"<<endl;
//    
//    cout<<"input vector of strings: load, tName"<<endl;
//    
//    vector<string> v = {"load", "tName"};
//    int pos = 0;
//    dataNode* dude = _get_load(v, pos);
//    _print_parse_tree(dude);
//}
//
//void _test_parse_get_store()
//{
//    cout<<endl<<"***** TESTING PARSE GET STORE *****"<<endl;
//
//    cout<<"input vector of strings: store, tName"<<endl;
//
//    vector<string> v = {"store", "tName"};
//    int pos = 0;
//    dataNode* dude = _get_store(v, pos);
//    _print_parse_tree(dude);
//}
//
//void _test_parse_get_drop()
//{
//    cout<<endl<<"***** TESTING PARSE GET DROP *****"<<endl;
//
//    cout<<"input vector of strings: drop, table, tName"<<endl;
//
//    vector<string> v = {"drop", "tName"};
//    int pos = 0;
//    dataNode* dude = _get_drop(v, pos);
//    _print_parse_tree(dude);
//}
//
//void _test_parse_get_insert()
//{
//    cout<<endl<<"***** TESTING PARSE GET INSERT *****"<<endl;
//
//    cout<<"input vector of strings: insert, into, table, tName, values, yo, bro, wazzup"<<endl;
//
//    vector<string> v = {"insert", "into", "tName", "values", "yo", "bro", "wazzup"};
//    int pos = 0;
//    dataNode* dude = _get_insert(v, pos);
//    _print_parse_tree(dude);
//}
//
//void _test_parse_get_print()
//{
//    cout<<endl<<"***** TESTING PARSE GET PRINT *****"<<endl;
//    
//    cout<<"input vector of strings: print, tName"<<endl;
//
//    vector<string> v = {"print", "tName"};
//    int pos = 0;
//    dataNode* dude = _get_print(v, pos);
//    _print_parse_tree(dude);
//}
//
//void _test_parse_get_select()
//{
//    cout<<endl<<"***** TESTING PARSE GET SELECT *****"<<endl;
//    
//    cout<<"input vector of strings:select, fName, lName, from, tName, where, lName, ==, Seghbossian"<<endl;
//
//    vector<string> v = {"select", "fName", "lName", "from", "tName", "where", "lName", "==", "Seghbossian"};
//    int pos = 0;
//    dataNode* dude = _get_select(v, pos);
//    _print_parse_tree(dude);
//}
//
//void _test_change_children_to_vector()
//{
//    cout<<endl<<"***** TESTING CHANGE CHILDREN TO VECTOR *****"<<endl;
//    
//    vector<string> v = {"select", "fName", "lName", "from", "tName", "where", "lName", "==", "Seghbossian"};
//    int pos = 0;
//    dataNode* dude = _get_select(v, pos);
//    _print_parse_tree(dude);
//    cout<<endl;
//    
//    cout<<"making vector containing kids of 'columns' node..."<<endl;
//    vector<string> kids = _change_children_to_vector(dude->children[0]);
//    for(string temp: kids)
//        cout<<temp<<", ";
//    cout<<endl;
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LIST FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//void _test_list_insert_sorted()
//{
//    cout<<endl<<"***** TESTING LIST INSERT SORTED *****"<<endl;
//    
//    list<int> l;
//    l.push_back(2);
//    l.push_back(3);
//    l.push_back(5);
//    l.push_back(8);
//    l.push_back(9);
//    cout<<"this is the list: "<<endl;
//    _print(l);
//    
//    cout<<"inserting 4..."<<endl;
//    _insert_sorted(l, 4);
//    _print(l);
//    
//    cout<<"inserting 4 again..."<<endl;
//    _insert_sorted(l, 4);
//    _print(l);
//    
//    cout<<"inserting 0..."<<endl;
//    _insert_sorted(l, 0);
//    _print(l);
//    
//    cout<<"inserting 0 again..."<<endl;
//    _insert_sorted(l, 0);
//    _print(l);
//    
//    cout<<"inserting 10..."<<endl;
//    _insert_sorted(l, 10);
//    _print(l);
//    
//    cout<<"inserting -4..."<<endl;
//    _insert_sorted(l, -4);
//    _print(l);
//    
//    cout<<endl;
//    list<string> s;
//    s.push_back("hello");
//    s.push_back("world");
//    cout<<"this is the list: "<<endl;
//    _print(s);
//    
//    string kiwi = "kiwi";
//    cout<<"inserting 'kiwi'..."<<endl;
//    _insert_sorted(s, kiwi);
//    _print(s);
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PAIR FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//void _test_pair_constructor()
//{
//    cout<<endl<<"***** TESTING PAIR CONSRUCTOR *****"<<endl;
//    
//    list<int> l;
//    l.push_back(2);
//    l.push_back(3);
//    l.push_back(5);
//    l.push_back(8);
//    l.push_back(9);
//    cout<<"this is the list of values: "<<endl;
//    _print(l);
//
//    string k = "hello";
//    cout<<"the key is 'hello'"<<endl<<endl;
//    Pair<string, int> p (k,l);
//    cout<<"printing the pair:"<<endl;
//    p.print();
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAP FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//void _test_map_push()
//{
//    cout<<endl<<"***** TESTING MAP PUSH *****"<<endl;
//    
//    Map<string, long> mapp;
//    cout<<endl<<"pushing ('one', 1)..."<<endl;
//    mapp.push("one", 1);
//    mapp.print();
//    
//    cout<<endl<<"pushing ('two', 2)..."<<endl;
//    mapp.push("two", 2);
//    mapp.print();
//    
//    cout<<endl<<"pushing ('two', 12)..."<<endl;
//    mapp.push("two", 12);
//    mapp.print();
//    
//    cout<<endl<<"pushing ('two', 2)..."<<endl;
//    mapp.push("two", 2);
//    mapp.print();
//    
//    cout<<endl<<"pushing ('three', 3)..."<<endl;
//    mapp.push("three", 3);
//    mapp.print();
//    
//    cout<<endl<<"pushing ('two', 2)..."<<endl;
//    mapp.push("two", 2);
//    mapp.print();
//    
//    cout<<endl<<"pushing ('apple', 2)..."<<endl;
//    mapp.push("apple", 2);
//    mapp.print();
//    
//}
//
//void _test_map_erase()
//{
//    cout<<endl<<"***** TESTING MAP ERASE *****"<<endl;
//    
//    cout<<"this is the map: "<<endl;
//    Map<string, long> mapp;
//    mapp.push("one", 1);
//    mapp.push("two", 2);
//    mapp.push("two", 12);
//    mapp.push("two", 2);
//    mapp.push("three", 3);
//    mapp.push("two", 2);
//    mapp.push("apple", 2);
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'one'..."<<endl;
//    mapp.erase("one");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'two'..."<<endl;
//    mapp.erase("two");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'three'..."<<endl;
//    mapp.erase("three");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'hello' which is not in the map..."<<endl;
//    mapp.erase("hello");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'apple'..."<<endl;
//    mapp.erase("apple");
//    mapp.print();
//}
//
//void _test_map_bracket_operator()
//{
//    cout<<endl<<"***** TESTING MAP BRACKET OPERATOR *****"<<endl;
//    
//    cout<<"this is the map: "<<endl;
//    Map<string, long> mapp;
//    mapp.push("one", 1);
//    mapp.push("two", 2);
//    mapp.push("two", 12);
//    mapp.push("two", 2);
//    mapp.push("three", 3);
//    mapp.push("two", 2);
//    mapp.push("apple", 2);
//    mapp.print();
//    
//    
//    cout<<endl<<"accessing list of values at key 'one'"<<endl;
//    _print(mapp["one"]);
//    
//    cout<<endl<<"accessing list of values at key 'apple'"<<endl;
//    _print(mapp["apple"]);
//    
//    cout<<endl<<"accessing list of values at key 'three'"<<endl;
//    _print(mapp["three"]);
//    
//    cout<<endl<<"accessing list of values at key 'two'"<<endl;
//    _print(mapp["two"]);
//    
//    cout<<endl<<"accessing list of values at key 'hello' which is not in map"<<endl;
//    _print(mapp["hello"]);
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RECORD FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TABLE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//void _test_table_push()
//{
//    cout<<endl<<"***** TESTING TABLE PUSH *****"<<endl;
//    
//    database db;
//    ifstream is("input.txt");
//    vector<string> fields = {"fName", "lName", "age"};
//    
//    table seghan ("People", fields);
//    
//    cout<<"record: ";
//    vector<string> row1 = db.readRecord(is);
//    record rec1 (row1);
//    rec1.print();
//    
//    cout<<"record: ";
//    vector<string> row2 = db.readRecord(is);
//    for(string temp : row2)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row3 = db.readRecord(is);
//    for(string temp : row3)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row4 = db.readRecord(is);
//    for(string temp : row4)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row5 = db.readRecord(is);
//    for(string temp : row5)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row6 = db.readRecord(is);
//    for(string temp : row6)
//        cout<<temp<<", ";
//    cout<<endl<<endl;
//    
//    seghan.push(row1);
//    seghan.push(row2);
//    seghan.push(row3);
//    seghan.push(row4);
//    seghan.push(row5);
//    seghan.push(row6);
//    
//    cout<<"table:"<<endl;
//    seghan.print();
//}
//
//void _test_table_subtable()
//{
//    database db;
//    
//    ifstream is("input.txt");
//    vector<string> fields = {"fName", "lName", "age"};
//    
//    table seghan ("People", fields);
//    
//    cout<<"record: ";
//    vector<string> row1 = db.readRecord(is);
//    record rec1 (row1);
//    rec1.print();
//    
//    cout<<"record: ";
//    vector<string> row2 = db.readRecord(is);
//    for(string temp : row2)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row3 = db.readRecord(is);
//    for(string temp : row3)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row4 = db.readRecord(is);
//    for(string temp : row4)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row5 = db.readRecord(is);
//    for(string temp : row5)
//        cout<<temp<<", ";
//    cout<<endl;
//    
//    cout<<"record: ";
//    vector<string> row6 = db.readRecord(is);
//    for(string temp : row6)
//        cout<<temp<<", ";
//    cout<<endl<<endl;
//    
//    seghan.push(row1);
//    seghan.push(row2);
//    seghan.push(row3);
//    seghan.push(row4);
//    seghan.push(row5);
//    seghan.push(row6);
//    
//    cout<<"table:"<<endl;
//    seghan.print();
//    
//    cout<<"subtable (2,0):"<<endl;
//    vector<long> vek = {2,0};
//    (seghan.subTable("subtable", vek)).print();
//    
//    cout<<endl<<"subtable (0,1):"<<endl;
//    vector<long> vekk = {0, 1};
//    (seghan.subTable("subtable", vekk)).print();
//    
//    cout<<endl<<"subtable (0):"<<endl;
//    vector<long> vekkk = {0};
//    (seghan.subTable("subtable", vekkk)).print();
//}
//
//
//
//
//
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
//  _test_database_functions.h
//  database
//
//  Created by Celine Seghbossian on 6/4/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database__test_database_functions_h
#define database__test_database_functions_h

#include "database.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PARSE TREE FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void _test_parse_get_create()
{
    cout<<endl<<"***** TESTING PARSE GET SELECT *****"<<endl;
    
    cout<<"input vector of strings: create, table, tName, as, select, *, from, tName, where, lName, ==, Seghbossian"<<endl;
    
    vector<string> v = {"create", "table", "tName", "as", "select", "*", "from", "tName", "where", "lName", "==", "Seghbossian"};
    int pos = 0;
    dataNode* dude = _get_create(v, pos);
    _print_parse_tree(dude);
    
    cout<<"input vector of strings: create, table, tName, fName, lName"<<endl;
    
    vector<string> u = {"create", "table", "tName", "fName", "lName"};
    int poss = 0;
    dataNode* bro = _get_create(u, poss);
    _print_parse_tree(bro);
}

void _test_parse_get_load()
{
    cout<<endl<<"***** TESTING PARSE GET LOAD *****"<<endl;
    
    cout<<"input vector of strings: load, tName"<<endl;
    
    vector<string> v = {"load", "tName"};
    int pos = 0;
    dataNode* dude = _get_load(v, pos);
    _print_parse_tree(dude);
}

void _test_parse_get_store()
{
    cout<<endl<<"***** TESTING PARSE GET STORE *****"<<endl;
    
    cout<<"input vector of strings: store, tName"<<endl;
    
    vector<string> v = {"store", "tName"};
    int pos = 0;
    dataNode* dude = _get_store(v, pos);
    _print_parse_tree(dude);
}

void _test_parse_get_drop()
{
    cout<<endl<<"***** TESTING PARSE GET DROP *****"<<endl;
    
    cout<<"input vector of strings: drop, table, tName"<<endl;
    
    vector<string> v = {"drop", "tName"};
    int pos = 0;
    dataNode* dude = _get_drop(v, pos);
    _print_parse_tree(dude);
}

void _test_parse_get_insert()
{
    cout<<endl<<"***** TESTING PARSE GET INSERT *****"<<endl;
    
    cout<<"input vector of strings: insert, into, table, tName, values, yo, bro, wazzup"<<endl;
    
    vector<string> v = {"insert", "into", "tName", "values", "yo", "bro", "wazzup"};
    int pos = 0;
    dataNode* dude = _get_insert(v, pos);
    _print_parse_tree(dude);
}

void _test_parse_get_print()
{
    cout<<endl<<"***** TESTING PARSE GET PRINT *****"<<endl;
    
    cout<<"input vector of strings: print, tName"<<endl;
    
    vector<string> v = {"print", "tName"};
    int pos = 0;
    dataNode* dude = _get_print(v, pos);
    _print_parse_tree(dude);
}

void _test_parse_get_select()
{
    cout<<endl<<"***** TESTING PARSE GET SELECT *****"<<endl;
    
    cout<<"input vector of strings:select, fName, lName, from, tName, where, lName, ==, Seghbossian"<<endl;
    
    vector<string> v = {"select", "fName", "lName", "from", "tName", "where", "lName", "==", "Seghbossian"};
    int pos = 0;
    dataNode* dude = _get_select(v, pos);
    _print_parse_tree(dude);
}

void _test_change_children_to_vector()
{
    cout<<endl<<"***** TESTING CHANGE CHILDREN TO VECTOR *****"<<endl;
    
    vector<string> v = {"select", "fName", "lName", "from", "tName", "where", "lName", "==", "Seghbossian"};
    int pos = 0;
    dataNode* dude = _get_select(v, pos);
    _print_parse_tree(dude);
    cout<<endl;
    
    cout<<"making vector containing kids of 'columns' node..."<<endl;
    vector<string> kids = _change_children_to_vector(dude->children[0]);
    for(string temp: kids)
        cout<<temp<<", ";
    cout<<endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LIST FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void _test_list_insert_sorted()
{
    cout<<endl<<"***** TESTING LIST INSERT SORTED *****"<<endl;
    
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(5);
    l.push_back(8);
    l.push_back(9);
    cout<<"this is the list: "<<endl;
    _print(l);
    
    cout<<"inserting 4..."<<endl;
    _insert_sorted(l, 4);
    _print(l);
    
    cout<<"inserting 4 again..."<<endl;
    _insert_sorted(l, 4);
    _print(l);
    
    cout<<"inserting 0..."<<endl;
    _insert_sorted(l, 0);
    _print(l);
    
    cout<<"inserting 0 again..."<<endl;
    _insert_sorted(l, 0);
    _print(l);
    
    cout<<"inserting 10..."<<endl;
    _insert_sorted(l, 10);
    _print(l);
    
    cout<<"inserting -4..."<<endl;
    _insert_sorted(l, -4);
    _print(l);
    
    cout<<endl;
    list<string> s;
    s.push_back("hello");
    s.push_back("world");
    cout<<"this is the list: "<<endl;
    _print(s);
    
    string kiwi = "kiwi";
    cout<<"inserting 'kiwi'..."<<endl;
    _insert_sorted(s, kiwi);
    _print(s);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PAIR FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void _test_pair_constructor()
{
    cout<<endl<<"***** TESTING PAIR CONSRUCTOR *****"<<endl;
    
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(5);
    l.push_back(8);
    l.push_back(9);
    cout<<"this is the list of values: "<<endl;
    _print(l);
    
    string k = "hello";
    cout<<"the key is 'hello'"<<endl<<endl;
    Pair<string, int> p (k,l);
    cout<<"printing the pair:"<<endl;
    p.print();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAP FUNCTIONS (complete) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void _test_map_push()
{
    cout<<endl<<"***** TESTING MAP PUSH *****"<<endl;
    
    Map<string, long> mapp;
    cout<<endl<<"pushing ('one', 1)..."<<endl;
    mapp.push("one", 1);
    mapp.print();
    
    cout<<endl<<"pushing ('two', 2)..."<<endl;
    mapp.push("two", 2);
    mapp.print();
    
    cout<<endl<<"pushing ('two', 12)..."<<endl;
    mapp.push("two", 12);
    mapp.print();
    
    cout<<endl<<"pushing ('two', 2)..."<<endl;
    mapp.push("two", 2);
    mapp.print();
    
    cout<<endl<<"pushing ('three', 3)..."<<endl;
    mapp.push("three", 3);
    mapp.print();
    
    cout<<endl<<"pushing ('two', 2)..."<<endl;
    mapp.push("two", 2);
    mapp.print();
    
    cout<<endl<<"pushing ('apple', 2)..."<<endl;
    mapp.push("apple", 2);
    mapp.print();
    
}

//void _test_map_erase()
//{
//    cout<<endl<<"***** TESTING MAP ERASE *****"<<endl;
//    
//    cout<<"this is the map: "<<endl;
//    Map<string, long> mapp;
//    mapp.push("one", 1);
//    mapp.push("two", 2);
//    mapp.push("two", 12);
//    mapp.push("two", 2);
//    mapp.push("three", 3);
//    mapp.push("two", 2);
//    mapp.push("apple", 2);
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'one'..."<<endl;
//    mapp.erase("one");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'two'..."<<endl;
//    mapp.erase("two");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'three'..."<<endl;
//    mapp.erase("three");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'hello' which is not in the map..."<<endl;
//    mapp.erase("hello");
//    mapp.print();
//    
//    cout<<endl<<"erasing key 'apple'..."<<endl;
//    mapp.erase("apple");
//    mapp.print();
//}

void _test_map_bracket_operator()
{
    cout<<endl<<"***** TESTING MAP BRACKET OPERATOR *****"<<endl;
    
    cout<<"this is the map: "<<endl;
    Map<string, long> mapp;
    mapp.push("one", 1);
    mapp.push("two", 2);
    mapp.push("two", 12);
    mapp.push("two", 2);
    mapp.push("three", 3);
    mapp.push("two", 2);
    mapp.push("apple", 2);
    mapp.print();
    
    
    cout<<endl<<"accessing list of values at key 'one'"<<endl;
    _print(mapp["one"]);
    
    cout<<endl<<"accessing list of values at key 'apple'"<<endl;
    _print(mapp["apple"]);
    
    cout<<endl<<"accessing list of values at key 'three'"<<endl;
    _print(mapp["three"]);
    
    cout<<endl<<"accessing list of values at key 'two'"<<endl;
    _print(mapp["two"]);
    
    cout<<endl<<"accessing list of values at key 'hello' which is not in map"<<endl;
    _print(mapp["hello"]);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RECORD FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TABLE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void _test_table_push()
{
    cout<<endl<<"***** TESTING TABLE PUSH *****"<<endl;
    
    database db;
    ifstream is("input.txt");
    vector<string> fields = {"fName", "lName", "age"};
    
    table seghan ("People", fields);
    
    cout<<"record: ";
    vector<string> row1 = db.readRecord(is);
    record rec1 (row1);
    rec1.print();
    
    cout<<"record: ";
    vector<string> row2 = db.readRecord(is);
    for(string temp : row2)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row3 = db.readRecord(is);
    for(string temp : row3)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row4 = db.readRecord(is);
    for(string temp : row4)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row5 = db.readRecord(is);
    for(string temp : row5)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row6 = db.readRecord(is);
    for(string temp : row6)
        cout<<temp<<", ";
    cout<<endl<<endl;
    
    seghan.push(row1);
    seghan.push(row2);
    seghan.push(row3);
    seghan.push(row4);
    seghan.push(row5);
    seghan.push(row6);
    
    cout<<"table:"<<endl;
    seghan.print();
}

void _test_table_subtable()
{
    database db;
    
    ifstream is("input.txt");
    vector<string> fields = {"fName", "lName", "age"};
    
    table seghan ("People", fields);
    
    cout<<"record: ";
    vector<string> row1 = db.readRecord(is);
    record rec1 (row1);
    rec1.print();
    
    cout<<"record: ";
    vector<string> row2 = db.readRecord(is);
    for(string temp : row2)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row3 = db.readRecord(is);
    for(string temp : row3)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row4 = db.readRecord(is);
    for(string temp : row4)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row5 = db.readRecord(is);
    for(string temp : row5)
        cout<<temp<<", ";
    cout<<endl;
    
    cout<<"record: ";
    vector<string> row6 = db.readRecord(is);
    for(string temp : row6)
        cout<<temp<<", ";
    cout<<endl<<endl;
    
    seghan.push(row1);
    seghan.push(row2);
    seghan.push(row3);
    seghan.push(row4);
    seghan.push(row5);
    seghan.push(row6);
    
    cout<<"table:"<<endl;
    seghan.print();
    
    cout<<"subtable (2,0):"<<endl;
    vector<long> vek = {2,0};
    (seghan.subTable("subtable", vek)).print();
    
    cout<<endl<<"subtable (0,1):"<<endl;
    vector<long> vekk = {0, 1};
    (seghan.subTable("subtable", vekk)).print();
    
    cout<<endl<<"subtable (0):"<<endl;
    vector<long> vekkk = {0};
    (seghan.subTable("subtable", vekkk)).print();
}













#endif
