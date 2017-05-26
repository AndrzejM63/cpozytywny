//
//  main.cpp
//  just first test
//
//  Created by AndrzejM63 on 10.05.2017.
//  Copyright © 2017 Andrzej Micialkiewicz. All rights reserved.
//

#include <iostream>
using namespace std;


struct Vector {
    int *v=NULL, size=0;
    
    Vector()
    {
        v = new int [0];
        size = 0;
    }
    
    ~Vector() { delete [] v; }
    
    
    int size_of()
    {
        /* return sizeof(v)/sizeof(*v); */
        return size;
    }
    
    /* allocate has to be the first and only one used action on new Vector */
    bool allocate(unsigned cells_no)
    {
        if (cells_no == 0)
            return false;
        
        if (v != NULL)
            return false;
        
        v = new (nothrow) int [cells_no];
        if (v == nullptr)
            return false;
        size = cells_no;
        // memset(v, 0, size*sizeof(int));
        fill_n(v, cells_no, 0);
        
        return true;
    }
    
    bool resize(unsigned no)
    {
        int *tmp;
        
        if (no == 0)
            return true;
        
        tmp = new (nothrow) int [size + no];
        if (tmp == nullptr)
            return false;
        memcpy(tmp, v, size*sizeof(int));
        //memset(&tmp[size], 0, no*sizeof(int));
        fill_n(&tmp[size], no, 0);
        delete [] v;
        v = tmp;
        size += no;
        return true;
    }
    
    bool append_new_cell(int new_value)
    {
        int *tmp;
        
        tmp = new (nothrow) int [size+1];
        if (tmp == nullptr)
            return false;
        memcpy(tmp, v, size*sizeof(int));
        tmp[size++] = new_value;
        
        delete [] v;
        v = tmp;
        return true;
    }
    
    int get(unsigned index, bool &success)
    {
        if (index < size)
        {
            success = true;
            return v[index];
        }

        success = false;
        return 0;
    }
    
    bool change(unsigned index, int value)
    {
        if (index < size)
        {
            v[index] = value;
            return true;
        }
        else
            return false;
    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int i;
    bool success;
    Vector table;
    
    // simply init
    table.allocate(1);
    // add 10 celss
    table.resize(10);
    
    // just check what is the size and content
    cout << "the table should be filled with zeros:\n";
    for (i=0; i < table.size_of(); i++)
        cout << table.v[i] << ", ";
    cout << "\n bye \n";
    cout << "table size: " << table.size_of() << "\n";

    // adding new cell with value 155
    table.append_new_cell(155);
    // just check what is the size and content
    for (i=0; i < table.size_of(); i++)
        cout << table.v[i] << ", ";
    cout << "\n bye \n";
    std::cout << "table size: " << table.size_of() << "\n";
    
    // change the value of 3rd element
    table.change(2, 8);
    cout << "3rd value is: " << table.get(2, success) << "\n";
    
    table.get(150, success);
    cout << "success is: " << success << "\n";
    cout << "Hello, World!\n";
    for (i=0; i < table.size_of(); i++)
        cout << table.v[i] << ", ";
    cout << "\n bye \n";
    
    return 0;
}
