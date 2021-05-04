#ifndef __VARIABLE_STACK_HPP__
#define __VARIABLE_STACK_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "Generate_Mips.hpp"

struct storage_set{
    int memory_index;
    int value;
    storage_set() : memory_index(), value() {}
    storage_set(int a,int b) : memory_index(a),value(b){}
};

class Variable_Stack{
    private:
        std::unordered_map<std::string,storage_set> variable_map;
        std::unordered_map<int,storage_set> temp_var_map;
        std::unordered_set<std::string> variable_without_value;
        int index = 0, count = 0;
        Generate_Mips* generate_mips = new Generate_Mips();
    public:
        int expression_declaration(int value);
        void expression_operations(operations operation);
        void variable_declaration_without_value(std::string variable_name);
        void variable_declaration_with_value(std::string variable_name, int value);
        int get_variable_value(std::string variable_name);
        bool variable_value_exists(std::string variable_name);
        void generate();
};

int Variable_Stack::expression_declaration(int value){
    temp_var_map[count++] = storage_set(index,value);
    generate_mips->expression_decla(index++,value);
    return count;
}

void Variable_Stack::expression_operations(operations operation){
    switch (operation){
        case 1:
            std::cout<<"Case 1 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-1,index-1,_not);
        case 2:
            std::cout<<"Case 2 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,_and);
            index--;
            break;
        case 3:
            std::cout<<"Case 3 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,_or);
            index--;
            break;
        case 4:
            std::cout<<"Case 4 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,add);
            index--;
            break;
        case 5:
            std::cout<<"Case 5 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,minus);
            index--;
            break;
        case 6:
            std::cout<<"Case 6 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,multiple);
            index--;
            break;
        case 7:
            std::cout<<"Case 7 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,divide);
            index--;
            break;
        case 8:
            std::cout<<"Case 8 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,lt);
            index--;
            break;
        case 9:
            std::cout<<"Case 9 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,gt);
            index--;
            break;
        case 10:
            std::cout<<"Case 10 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,equal);
            index--;
            break;
        case 11:
            std::cout<<"Case 11 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,noteq);
            index--;
            break;
        case 12:
            std::cout<<"Case 12 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,lteq);
            index--;
            break;
        case 13:
            std::cout<<"Case 13 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,gteq);
            index--;
            break;
        case 14:
            std::cout<<"Case 14 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,shlop);
            index--;
            break;
        case 15:
            std::cout<<"Case 15 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,shrop);
            index--;
            break;
        case 16:
            std::cout<<"Case 16 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,andand);
            index--;
            break;
        case 17:
            std::cout<<"Case 17 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,oror);
            index--;
            break;
        case 18:
            std::cout<<"Case 18 Execution"<<std::endl;
            generate_mips->operations_in_memory(index-2,index-1,paren);
            break;
    }
}

void Variable_Stack::variable_declaration_without_value(std::string variable_name){
    variable_map[variable_name] = storage_set(index++,INT32_MIN);
    variable_without_value.insert(variable_name);
}

void Variable_Stack::variable_declaration_with_value(std::string variable_name,int value){
    variable_map[variable_name] = storage_set(index++,value);
}

int Variable_Stack::get_variable_value(std::string variable_name){
    if (variable_map.find(variable_name)==variable_map.end()){
        std::cout<<"[Error] Value "+variable_name+" not exists"<<std::endl;
        abort();
    }
    // return variable_map[variable_name];
}

bool Variable_Stack::variable_value_exists(std::string variable_name){
    if (variable_without_value.find(variable_name)!=variable_without_value.end()){
        return false;
    }
    return true;
}

void Variable_Stack::generate(){
    generate_mips->generate_mips_code();
}

#endif