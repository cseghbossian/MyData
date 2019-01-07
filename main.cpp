//
//  main.cpp
//  database
//
//  Created by Celine Seghbossian on 5/23/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <list>
#include "_test_database_functions.h"
using namespace std;


int main(int argc, const char * argv[])
{
    cout<<argv[0]<<endl<<endl; //directory where files are saved
    
    database db;
    while(true)
    db.run();
    
    
}
