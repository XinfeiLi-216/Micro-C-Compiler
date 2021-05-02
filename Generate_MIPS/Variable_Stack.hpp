#ifndef __VARIABLE_STACK_HPP__
#define __VARIABLE_STACK_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Variable_Stack{
    private:
        std::vector<int> table;
    public:
        Variable_Stack();
        ~Variable_Stack();
};

Variable_Stack::Variable_Stack(){
    
}

Variable_Stack::~Variable_Stack(){

}

#endif