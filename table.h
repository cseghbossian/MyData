////
////  table.h
////  database
////
////  Created by Celine Seghbossian on 5/25/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database_table_h
//#define database_table_h
//
//#include "record.h"
//#include "Map.h"
//
//using namespace std;
//
//class table
//{
//public:
//    table();
//    ~table();
//    table(const table& other);
//    table(string t, vector<string> fields);
//    table& operator=(const table& other);
//    bool push(vector<string> rec);
//    void print(ostream& o = cout);
//    long searchField(string column);
//    table subTable(string tName, vector<long> fieldNames);
//    list<long> getIndices(long mapIndex, string key);
//    vector<string> getRow(long rowIndex);
//    vector<string> getFieldNames();
//
//    
//    //variables
//private:
//    string tableName;
//    vector<string> fieldNames;
//    vector<record> rows;
//    vector<Map<string, long>> indices;
//    
//};
//
//table:: table()
//{
//    tableName = "";
//}
//
//table:: ~table()
//{
//    tableName = "";
//    fieldNames.clear();
//    indices.clear();
//    rows.clear();
//}
//
//table::table(const table& other)
//{
//    tableName = other.tableName;
//    fieldNames = other.fieldNames;
//    rows = other.rows;
//    indices = other.indices;
//}
//
//table::table(string t, vector<string> fields)
//{
//    fieldNames = fields;
//    tableName = t;
//}
//
//table& table:: operator=(const table& other)
//{
//    tableName = other.tableName;
//    fieldNames = other.fieldNames;
//    rows = other.rows;
//    indices = other.indices;
//    return *this;
//}
//
//bool table:: push(vector<string> rec)
//{
//    if(rec.size() != fieldNames.size())
//        return false;
//    
//    record temp(rec);
//    rows.push_back(temp);
//    
//    long index = rows.size() - 1;
//    
//    for(int i = 0; i < rec.size(); ++i)
//    {
//        Map<string, long> temp;
//        indices.push_back(temp);
//        indices[i].push(rec[i], index);
//    }
//    return true;
//}
//
//void table:: print(ostream& o)
//{
//    for(string covfefe : fieldNames)
//        o<<"|"<<setw(15)<<covfefe<<"|";
//    o<<endl;
//    for(int i = 0; i < fieldNames.size()*17; ++i)
//        o<<"-";
//    o<<endl;
//    
//    for(record covfefe : rows)
//        covfefe.print();
//    o<<endl;
//}
//
//long table:: searchField(string column)
//{
//    for(long i = 0; i < fieldNames.size(); ++i)
//        if (fieldNames[i] == column)
//            return i;
//    return -1;
//}
//
//table table:: subTable(string tName, vector<long> fields)
//{
//    vector<string> subFieldnames;
//    for(long temp : fields)
//        subFieldnames.push_back(fieldNames[temp]);
//    
//    table result (tName, subFieldnames);
//    
//    for(record temp : rows)
//    {
//        vector<string> subTemp = temp.subRecord(fields);
//        result.push(subTemp);
//    }
//    return result;
//}
//
//list<long> table:: getIndices(long mapIndex, string key)
//{
//    return (indices[mapIndex])[key];
//}
//
//vector<string> table:: getRow(long rowIndex)
//{
//    if(rowIndex < rows.size() && rowIndex > -1)
//        return rows[rowIndex].getRow();
//    else
//        return {};
//}
//
//vector<string> table:: getFieldNames()
//{
//    return fieldNames;
//}
//
//
//#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
////
////  table.h
////  database
////
////  Created by Celine Seghbossian on 5/25/17.
////  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
////
//
//#ifndef database_table_h
//#define database_table_h
//
//#include "record.h"
//#include "Map.h"
//
//using namespace std;
//
//class table
//{
//public:
//    table();
//    ~table();
//    table(const table& other);
//    table(string t, vector<string> fields);
//    table& operator=(const table& other);
//    bool push(vector<string> rec);
//    void print();
//    void basicPrint(ostream& os);
//    long searchField(string column);
//    table subTable(string tName, vector<long> fieldNames);
//    list<long> getIndices(long mapIndex, string key);
//    vector<string> getRow(long rowIndex);
//    vector<string> getFieldNames();
//    
//    
//    //variables
//    //private:
//    string tableName;
//    vector<string> fieldNames;
//    vector<record> rows;
//    vector<Map<string, long>> indices;
//    
//};
//
//table:: table()
//{
//    tableName = "";
//}
//
//table:: ~table()
//{
//    tableName = "";
//    fieldNames.clear();
//    indices.clear();
//    rows.clear();
//}
//
//table::table(const table& other)
//{
//    tableName = other.tableName;
//    fieldNames = other.fieldNames;
//    rows = other.rows;
//    indices = other.indices;
//}
//
//table::table(string t, vector<string> fields)
//{
//    fieldNames = fields;
//    tableName = t;
//    
//    for(int i = 0; i < fields.size(); ++i)
//    {
//        Map<string, long> indexStruct;
//        indices.push_back(indexStruct);
//    }
//}
//
//table& table:: operator=(const table& other)
//{
//    tableName = other.tableName;
//    fieldNames = other.fieldNames;
//    rows = other.rows;
//    indices = other.indices;
//    return *this;
//}
//
//bool table:: push(vector<string> rec)
//{
//    if(fieldNames.size() != 0 && rec.size() != fieldNames.size()) //if there are too many things in record to push into table..
//        return false;
//    
//    long index = rows.size();
//    record newRow (rec);
//    rows.push_back(newRow);
//    
//    //add the index to each map where it belongs as a string, long
//    
//    for(int i = 0; i < rec.size(); ++i)
//        indices[i].push(rec[i], index);
//    
//    return true;
//}
//
//void table:: print()
//{
//    for(string covfefe : fieldNames)
//        cout<<"|"<<setw(15)<<covfefe<<"|";
//    cout<<endl;
//    for(int i = 0; i < fieldNames.size()*17; ++i)
//        cout<<"-";
//    cout<<endl;
//    
//    for(record covfefe : rows)
//        covfefe.print();
//    cout<<endl;
//}
//
//void table:: basicPrint(ostream& o)
//{
//    for(string covfefe : fieldNames)
//        o<<covfefe<<" ";
//    o<<endl;
//    
//    for(record covfefe : rows)
//        covfefe.basicPrint(o);
//    o<<endl;
//}
//
//long table:: searchField(string column)
//{
//    for(long i = 0; i < fieldNames.size(); ++i)
//        if (fieldNames[i] == column)
//            return i;
//    return -1;
//}
//
//table table:: subTable(string tName, vector<long> fields)
//{
//    vector<string> subFieldnames;
//    for(long temp : fields)
//        subFieldnames.push_back(fieldNames[temp]);
//    
//    table result (tName, subFieldnames);
//    
//    for(record temp : rows)
//    {
//        vector<string> subTemp = temp.subRecord(fields);
//        result.push(subTemp);
//    }
//    return result;
//}
//
//list<long> table:: getIndices(long mapIndex, string key)
//{
//    list<long> temp = ((indices[mapIndex])[key]);
//    return temp;
//}
//
//vector<string> table:: getRow(long rowIndex)
//{
//    if(rowIndex < rows.size() && rowIndex > -1)
//        return rows[rowIndex].getRow();
//    else
//        return {};
//}
//
//vector<string> table:: getFieldNames()
//{
//    return fieldNames;
//}
//
//
//#endif


//
//  table.h
//  database
//
//  Created by Celine Seghbossian on 5/25/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database_table_h
#define database_table_h

#include "record.h"
#include "Map.h"

using namespace std;

class table
{
public:
    table();
    ~table();
    table(const table& other);
    table(string t, vector<string> fields);
    table& operator=(const table& other);
    bool push(vector<string> rec);
    void print();
    void basicPrint(ostream& os);
    long searchField(string column);
    table subTable(string tName, vector<long> fieldNames);
    list<long> getIndices(long mapIndex, string key);
    vector<string> getRow(long rowIndex);
    vector<string> getFieldNames();
    
    
    //variables
    //private:
    string tableName;
    vector<string> fieldNames;
    vector<record> rows;
    vector<Map<string, long>> indices;
    
};

table:: table()
{
    tableName = "";
}

table:: ~table()
{
    tableName = "";
    fieldNames.clear();
    indices.clear();
    rows.clear();
}

table::table(const table& other)
{
    tableName = other.tableName;
    fieldNames = other.fieldNames;
    rows = other.rows;
    indices = other.indices;
}

table::table(string t, vector<string> fields)
{
    fieldNames = fields;
    tableName = t;
    
    for(int i = 0; i < fields.size(); ++i)
    {
        Map<string, long> indexStruct;
        indices.push_back(indexStruct);
    }
}

table& table:: operator=(const table& other)
{
    tableName = other.tableName;
    fieldNames = other.fieldNames;
    rows = other.rows;
    indices = other.indices;
    return *this;
}

bool table:: push(vector<string> rec)
{
    if(fieldNames.size() != 0 && rec.size() != fieldNames.size()) //if there are too many things in record to push into table..
        return false;
    
    long index = rows.size();
    record newRow (rec);
    rows.push_back(newRow);
    
    //add the index to each map where it belongs as a string, long
    
    for(int i = 0; i < rec.size(); ++i)
        indices[i].push(rec[i], index);
    
    return true;
}

void table:: print()
{
    for(string covfefe : fieldNames)
        cout<<"|"<<setw(15)<<covfefe<<"|";
    cout<<endl;
    for(int i = 0; i < fieldNames.size()*17; ++i)
        cout<<"-";
    cout<<endl;
    
    for(record covfefe : rows)
        covfefe.print();
    cout<<endl;
}

void table:: basicPrint(ostream& o)
{
    for(string covfefe : fieldNames)
        o<<covfefe<<" ";
    o<<endl;
    
    for(record covfefe : rows)
        covfefe.basicPrint(o);
    o<<endl;
}

long table:: searchField(string column)
{
    for(long i = 0; i < fieldNames.size(); ++i)
        if (fieldNames[i] == column)
            return i;
    return -1;
}

table table:: subTable(string tName, vector<long> fields)
{
    vector<string> subFieldnames;
    for(long temp : fields)
        subFieldnames.push_back(fieldNames[temp]);
    
    table result (tName, subFieldnames);
    
    for(record temp : rows)
    {
        vector<string> subTemp = temp.subRecord(fields);
        result.push(subTemp);
    }
    return result;
}

list<long> table:: getIndices(long mapIndex, string key)
{
    list<long> temp = ((indices[mapIndex])[key]);
    return temp;
}

vector<string> table:: getRow(long rowIndex)
{
    if(rowIndex < rows.size() && rowIndex > -1)
        return rows[rowIndex].getRow();
    else
        return {};
}

vector<string> table:: getFieldNames()
{
    return fieldNames;
}


#endif
