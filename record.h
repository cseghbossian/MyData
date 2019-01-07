////
////  record.h
////  database
////
////  Created by Celine Seghbossian on 5/29/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database_record_h
//#define database_record_h
//
//#include <vector>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//class record
//{
//public:
//    record();
//    ~record();
//    record& operator = (const record& other);
//    record(const record& other);
//    record(vector<string> r);
//    void push(string s);
//    string& operator [] (unsigned int i);
//    void print();
//    vector<string> subRecord(vector<long> include);
//    vector<string> getRow();
//    
//    
//private:
//    vector<string> row;
//};
//
//record:: record()
//{
//    row = {};
//}
//
//record:: ~record()
//{
//    row.clear();
//}
//
//record& record:: operator = (const record& other)
//{
//    row = other.row;
//    return *this;
//}
//
//record:: record(const record& other)
//{
//    row = other.row;
//}
//
//record:: record(vector<string> r)
//{
//    row = r;
//}
//
//void record:: push(string s)
//{
//    row.push_back(s);
//}
//
//string& record:: operator [] (unsigned int i)
//{
//    return row[i];
//}
//
//void record:: print()
//{
//    for(string covfefe : row)
//        cout<<"|"<<setw(15)<<covfefe<<"|";
//    cout<<endl;
//}
//
//vector<string> record::subRecord(vector<long> include)
//{
//    vector<string> subRow;
//    for(long temp : include)
//        subRow.push_back(row[temp]);
//    return subRow;
//}
//
//vector<string> record:: getRow()
//{
//    return row;
//}
//
//#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

////
////  record.h
////  database
////
////  Created by Celine Seghbossian on 5/29/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database_record_h
//#define database_record_h
//
//#include <vector>
//#include <string>
//#include <iomanip>
//#include "record.h"
//using namespace std;
//
//class record
//{
//public:
//    record();
//    ~record();
//    record& operator = (const record& other);
//    record(const record& other);
//    record(vector<string> r);
//    void push(string s);
//    string& operator [] (unsigned int i);
//    void print();
//    void basicPrint(ostream& os);
//    vector<string> subRecord(vector<long> include);
//    vector<string> getRow();
//    
//    
//private:
//    vector<string> row;
//};
//
//record:: record()
//{
//    row = {};
//}
//
//record:: ~record()
//{
//    row.clear();
//}
//
//record& record:: operator = (const record& other)
//{
//    row = other.row;
//    return *this;
//}
//
//record:: record(const record& other)
//{
//    row = other.row;
//}
//
//record:: record(vector<string> r)
//{
//    row = r;
//}
//
//void record:: push(string s)
//{
//    row.push_back(s);
//}
//
//string& record:: operator [] (unsigned int i)
//{
//    return row[i];
//}
//
//void record:: print()
//{
//    for(string covfefe : row)
//        cout<<"|"<<setw(15)<<covfefe<<"|";
//    cout<<endl;
//}
//
//void record:: basicPrint(ostream& os)
//{
//    for(string covfefe : row)
//        os<<covfefe<<" ";
//    os<<endl;
//}
//
//vector<string> record::subRecord(vector<long> include)
//{
//    vector<string> subRow;
//    for(long temp : include)
//        subRow.push_back(row[temp]);
//    return subRow;
//}
//
//vector<string> record:: getRow()
//{
//    return row;
//}
//
//#endif

//
//  record.h
//  database
//
//  Created by Celine Seghbossian on 5/29/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database_record_h
#define database_record_h

#include <vector>
#include <string>
#include <iomanip>
#include "record.h"
using namespace std;

class record
{
public:
    record();
    ~record();
    record& operator = (const record& other);
    record(const record& other);
    record(vector<string> r);
    void push(string s);
    string& operator [] (unsigned int i);
    void print();
    void basicPrint(ostream& os);
    vector<string> subRecord(vector<long> include);
    vector<string> getRow();
    
    
private:
    vector<string> row;
};

record:: record()
{
    row = {};
}

record:: ~record()
{
    row.clear();
}

record& record:: operator = (const record& other)
{
    row = other.row;
    return *this;
}

record:: record(const record& other)
{
    row = other.row;
}

record:: record(vector<string> r)
{
    row = r;
}

void record:: push(string s)
{
    row.push_back(s);
}

string& record:: operator [] (unsigned int i)
{
    return row[i];
}

void record:: print()
{
    for(string covfefe : row)
        cout<<"|"<<setw(15)<<covfefe<<"|";
    cout<<endl;
}

void record:: basicPrint(ostream& os)
{
    for(string covfefe : row)
        os<<covfefe<<" ";
    os<<endl;
}

vector<string> record::subRecord(vector<long> include)
{
    vector<string> subRow;
    for(long temp : include)
        subRow.push_back(row[temp]);
    return subRow;
}

vector<string> record:: getRow()
{
    return row;
}

#endif
