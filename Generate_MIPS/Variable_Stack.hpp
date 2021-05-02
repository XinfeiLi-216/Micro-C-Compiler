#ifndef __VARIABLE_STACK_HPP__
#define __VARIABLE_STACK_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>

struct storage_set{
    int memory_index;
    int value;
    storage_set(int a,int b) : memory_index(a),value(b){}
}

enum operations{lsquare,_not,_and,_or,add,minus,multiple,divide,lt,gt,
                equal,noteq,lteq,gteq,shlop,shrop,andand,oror,paren,minus}

class Variable_Stack{
    private:
        std::unordered_map<std::string,storage_set> variable_map;
        std::unordered_map<int,storage_set> temp_var_map;
        int index = 0, count = 0;
    public:
        int expression_process(int value);
        int operations_expression(operations operation){}

int Variable_Stack::expression_process(int value){
    temp_var_map[count] = storage_set(index,value);
    count++;
    index++;
    return count;
}

int Variable_Stack::operations_expression(operations operation){
    switch (operation){
        case 1:
}

#endif
