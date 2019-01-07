
//
//  database.h
//  database
//
//  Created by Celine Seghbossian on 5/29/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database_database_h
#define database_database_h

#include "table.h"
#include "_functions.h"
#include <sstream>

using namespace std;

class database
{
public:
    database();
    ~database();
    database(database& other);
    database& operator=(database& other);
    vector<string> getInput();
    
    bool selectCommand(table& t, dataNode* tree);
    bool applyCondition(table& original, dataNode* where, long index);
    
    void createCommand(dataNode* tree);
    bool printCommand(dataNode* tree);
    bool loadCommand(dataNode* tree);
    void storeCommand(dataNode* tree);
    bool dropCommand(dataNode* tree);
    void insertCommand(dataNode* tree);
    
    vector<string> readRecord(ifstream& is);
    void run();
    void invalidCommand(int i = 0);
    long search(string tName);
    bool addTable(string tName, vector<string> fields);
    bool addTable(string tName, table t);
    
private:
    vector<table> tables;
    vector<string> tableNames;
};

database:: database()
{
    
}

database:: ~database()
{
    tableNames.clear();
    tables.clear();
}

database::database(database& other)
{
    tables = other.tables;
    tableNames = other.tableNames;
}

database& database:: operator=(database& other)
{
    tables = other.tables;
    tableNames = other.tableNames;
    return *this;
}

vector<string> database:: getInput() //tested
{
    //SAMPLE: select fName, lName from tName where lName == Seghbossian
    
    vector<string> result;
    string line;
    
    cout<<"ENTER COMMAND: ";
    getline(cin,line);
    
    stringstream ss (line);
    string cell;
    
    while(getline(ss, cell, ' '))
    {
        if (cell.back() == ',' || cell.back() == ')')
            cell.pop_back();
        if(cell.front() == '(')
            cell.erase(cell.begin());
        
        result.push_back(cell);
    }
    
    if (!ss && cell.empty())
        result.push_back("");
    return result;
}

bool database:: selectCommand(table& t, dataNode* tree)
{
    //pass in a table and return a bool so that if the command is invalid, an empty table is not returned!!!!
    if(!(tree->children[1] && tree->children[1]->children[0]))
    {
        invalidCommand();
        return false;
    }
    string tName = tree->children[1]->children[0]->name;
    
    long index = search(tName); //index of the table in this database
    
    if(index != -1)
    {
        vector<string> kids = _change_children_to_vector(tree->children[0]);
        table subtable;
        
        if (kids.size() == 0)
        {
            invalidCommand(3);
            return false;
        }
        if(kids[0] == "*")
        {
            subtable = tables[index];
            if (kids.size() > 1)
            {
                invalidCommand();
                return false;
            }
        }
        else
        {
            vector<long> colIndex; //index of columns to be selected
            
            for(string temp : kids)
            {
                long c = tables[index].searchField(temp);
                if(c == -1)
                {
                    invalidCommand(1); //if the columns do not exist inside table ERROR
                    return false;
                }
                colIndex.push_back(c);
                
            }
            
            subtable = tables[index].subTable("subtable", colIndex);
        }
        
        if(tree->children[2])
        {
            bool validCond = applyCondition(subtable, tree->children[2], index);
            if(!validCond)
                invalidCommand(7);
        }
        
        t = subtable;
        return true;
    }
    else
    {
        invalidCommand(2);
        return false;
    }
}

bool database:: applyCondition(table& original, dataNode* where, long index)
{
    if(where->children[0] && where->children[0]->children[0] && where->children[0]->children[1])
    {
        string condRight = where->children[0]->children[1]->name;
        string condLeft = where->children[0]->children[0]->name;
        long condLeftIndex = original.searchField(condLeft);
        
        if(condLeftIndex == -1)
            return false;
        
        list<long> indices = original.getIndices(condLeftIndex, condRight);
        
        if (indices == list<long>())
        {
            original = table();
            return true;
        }
        
        table subtable("temp", original.getFieldNames());
        
        
        for(long temp : indices)
            subtable.push(original.getRow(temp));
        
        original = subtable;
        return true;
    }
    else
    {
        invalidCommand(7);
        return false;
    }
    
}

void database:: createCommand(dataNode* tree)
{
    //cout<<"DEBUG: "<<tree->children[0]->name<<endl;
    if(!tree->children[0])
        invalidCommand();
    else
    {
        string tName = tree->children[0]->name;
        long index = search(tName);
        if (index != -1)
        {
            tables.erase(tables.begin()+index);
            tableNames.erase(tableNames.begin()+index);
        }
        if(!tree->children[1])
            invalidCommand();
        else if(tree->children[1]->name == "select")
        {
            table t;
            selectCommand(t, tree->children[1]);
            addTable(tName, t);
        }
        else if(tree->children[1]->name == "values")
        {
            vector<string> fields = _change_children_to_vector(tree->children[1]);
            addTable(tName, fields);
        }
        else
            invalidCommand();
    }
    
}

bool database::printCommand(dataNode* tree)
{
    string tName = tree->children[0]->name;
    long index = search(tName);
    if (index == -1)
    {
        invalidCommand(2);
        return false;
    }
    cout<<endl;
    tables[index].print();
    return true;
}

bool database::loadCommand(dataNode* tree)
{
    string tableName = tree->children[0]->name;
    string fileName = tableName + ".txt";
    ifstream is;
    is.open(fileName);
    
    if(!is.is_open())
    {
        invalidCommand();
        return false;
    }
    
    string line;
    getline(is, line);
    stringstream s (line);
    
    string field;
    vector<string> fieldNames;
    while (getline(s, field, ' '))
        fieldNames.push_back(field);
    
    table t (tableName, fieldNames);
    
    while(getline(is, line))
    {
        stringstream ss (line);
        string cell;
        vector<string> result;
        
        while(getline(ss, cell, ' '))
            result.push_back(cell);
        t.push(result);
    }
    
    long index = search(tableName);
    
    if(index != -1)
    {
        tables.erase(tables.begin()+index);
        tableNames.erase(tableNames.begin()+index);
    }
    
    addTable(tableName, t);
    
    return true;
}

void database:: storeCommand(dataNode* tree)
{
    string tableName = tree->children[0]->name;
    long index = search(tableName);
    if (index == -1)
        invalidCommand(2);
    else
    {
        string fileName = tableName + ".txt";
        ofstream os;
        os.open(fileName.c_str());
        tables[index].basicPrint(os);
    }
}

bool database::dropCommand(dataNode* tree)
{
    string tName = tree->children[0]->name;
    long index = search(tName);
    if (index == -1)
    {
        invalidCommand(2);
        return false;
    }
    tables.erase(tables.begin()+index);
    tableNames.erase(tableNames.begin()+index);
    return true;
}

void database:: insertCommand(dataNode* tree)
{
    if(!tree->children[0] || !tree->children[0]->children[0])
        invalidCommand();
    else
    {
        string tName = tree->children[0]->children[0]->name;
        long index = search(tName);
        if (index == -1)
            invalidCommand(2);
        else
        {
            if (!tree->children[1]->children[0])
                invalidCommand(6);
            else
            {
                vector<string> values = _change_children_to_vector(tree->children[1]);
                if (!tables[index].push(values))
                    invalidCommand(6);
            }
        }
    }
    
}

vector<string> database::readRecord(ifstream& is)
{
    //NORMAL TEXT FILE
    
    vector<string> result;
    string line;
    
    if(is.is_open())
    {
        getline(is, line);
        stringstream ss (line);
        string cell;
        
        while(getline(ss, cell, ' '))
            result.push_back(cell);
    }
    return result;
}

void database::run()
{
    vector<string> result = getInput();
    dataNode* tree;
    int pos = 0;
    
    if(*result.begin() == "create") //done
    {
        tree = _get_create(result, pos);
        createCommand(tree);
    }
    else if(*result.begin() == "load") //done
    {
        tree = _get_load(result, pos);
        loadCommand(tree);
    }
    else if(*result.begin() == "store")
    {
        tree = _get_store(result, pos);
        storeCommand(tree);
    }
    else if(*result.begin() == "drop") //done
    {
        tree = _get_drop(result, pos);
        if (!dropCommand(tree))
            invalidCommand(2);
    }
    else if(*result.begin() == "insert") //done
    {
        tree = _get_insert(result, pos);
        insertCommand(tree);
    }
    else if(*result.begin() == "print") //done
    {
        tree = _get_print(result, pos);
        if (!printCommand(tree))
            invalidCommand();
    }
    else if(*result.begin() == "select") //almost done but needs to consider condition
    {
        tree = _get_select(result, pos);
        table t;
        if (selectCommand(t, tree))
            t.print();
        
    }
    else
        invalidCommand();
    
}

void database:: invalidCommand(int i)
{
    switch (i)
    {
        case 1:
            cout<<"INVALID COLUMN NAME. TRY AGAIN."<<endl;
            break;
        case 2:
            cout<<"INVALID TABLE NAME. TRY AGAIN."<<endl;
            break;
        case 3:
            cout<<"MUST GIVE AT LEAST ONE COLUMN NAME. TRY AGAIN."<<endl;
            break;
        case 4:
            cout<<"UNKNOWN CONDITION. TRY AGAIN."<<endl;
            break;
        case 5:
            cout<<"INVALID FILE NAME. TRY AGAIN."<<endl;
        case 6:
            cout<<"NUMBER OF VALUES DOES NOT MATCH NUMBER OF TABLE COLUMNS"<<endl;
        case 7:
            cout<<"INVALID CONDITION. TRY AGAIN."<<endl;
        default:
            cout<<"INVALID COMMAND. TRY AGAIN."<<endl;
            break;
    }
}

long database:: search(string tName)
{
    for(long i = 0; i < tableNames.size(); ++i)
        if(tableNames[i] == tName)
            return i;
    return -1;
}

bool database:: addTable(string tName, vector<string> fields)
{
    if(search(tName) == -1)
    {
        tableNames.push_back(tName);
        table temp (tName, fields);
        tables.push_back(temp);
        return true;
    }
    return false;
}

bool database:: addTable(string tName, table t)
{
    if(search(tName) == -1)
    {
        tableNames.push_back(tName);
        tables.push_back(t);
        return true;
    }
    return false;
}

#endif
