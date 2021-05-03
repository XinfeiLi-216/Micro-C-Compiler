#ifndef __VARIABLE_STACK_HPP__
#define __VARIABLE_STACK_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>

struct storage_set{
    int memory_index;
    int value;
    storage_set() : memory_index(), value() {}
    storage_set(int a,int b) : memory_index(a),value(b){}
};

enum operations{lsquare,_not,_and,_or,add,minus,multiple,divide,lt,gt,
                equal,noteq,lteq,gteq,shlop,shrop,andand,oror,paren};

class Variable_Stack{
    private:
        std::unordered_map<std::string,storage_set> variable_map;
        std::unordered_map<int,storage_set> temp_var_map;
        std::unordered_set<std::string> variable_without_value;
        int index = 0, count = 0;
    public:
        int expression_declaration(int value);
        int expression_operations(operations operation);
        int variable_declaration_without_value(std::string variable_name);
        int variable_declaration_with_value(std::string variable_name, int value);
        int get_variable_value(std::string variable_name);
        bool variable_value_exists(std::string variable_name);
};

int Variable_Stack::expression_declaration(int value){
    temp_var_map[count++] = storage_set(index++,value);
    return count;
}

int Variable_Stack::expression_operations(operations operation){
    switch (operation){
        case 4:
            std::cout<<"Case 4 Execution"<<std::endl;
            // TODO: Add the last two value in memory togother
    }
}

int Variable_Stack::variable_declaration_without_value(std::string variable_name){
    variable_map[variable_name] = storage_set(index++,INT32_MIN);
    variable_without_value.insert(variable_name);
}

int Variable_Stack::variable_declaration_with_value(std::string variable_name,int value){
    variable_map[variable_name] = storage_set(index++,value);
}

int Variable_Stack::get_variable_value(std::string variable_name){
    
}

bool Variable_Stack::variable_value_exists(std::string variable_name){
    if (variable_without_value.find(variable_name)!=variable_without_value.end()){
        return false;
    }
    return true;
}

#endif