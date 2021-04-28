/**************************************************************************************
 *         Function Definition of Generate_MIPS Class && Variable_Stack Class         *
 **************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "generate_mips.h"

/**************************************************************************************
 *                                Generate_MIPS Class                                 *
 **************************************************************************************/

/* 
 * This function generate the mips code for an assignment instruction in Micro Language
 */
void Generate_MIPS::generate_code(Variable_Stack* var_stack,std::string var_id){
	//If variable not exist, output the MIPS code for declaration
	output_var_declaration(var_stack,var_id);
	//If rightside of = has only one element
	if ( var_stack->size() == 1 ){
		if ( var_stack->get_type_idx(0)==0 ){
			text_segment.push_back("la $t0 ,"+*((std::string*)var_stack->get_value_idx(0)));
			text_segment.push_back("lw $t0 ,0($t0)");
			text_segment.push_back("sw $t0 ,"+var_id);
		} else {
			text_segment.push_back("li $t0 ,"+std::to_string(*((int*)var_stack->get_value_idx(0))));
			text_segment.push_back("sw $t0 ,"+var_id);
		}
	//If rightside of = has more than one element
	} else {
		//Firstly we process the initial two elements
		/**********************************************************************
		 * Here the four condition is the str+-str str+-int int+-str int+-int *
		 **********************************************************************/
		if ( var_stack->get_type_idx(0)==0 && var_stack->get_type_idx(1)==1 ){
			std::string value1 = *((std::string*)var_stack->get_value_idx(0));
			int value2 = *((int*)var_stack->get_value_idx(1));
			if ( var_stack->get_op_idx(0)==0){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		} else if ( var_stack->get_type_idx(0)==1 && var_stack->get_type_idx(1)==0 ){
			std::string value1 = *((std::string*)var_stack->get_value_idx(1));
			int value2 = *((int*)var_stack->get_value_idx(0));
			if ( var_stack->get_type_idx(0)==0 ){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		} else if ( var_stack->get_type_idx(0)==1 && var_stack->get_type_idx(1)==1 ){
			int value1 = *((int*)var_stack->get_value_idx(0));
			int value2 = *((int*)var_stack->get_value_idx(1));
			if ( var_stack->get_type_idx(0)==0 ){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		} else if ( var_stack->get_type_idx(0)==0 && var_stack->get_type_idx(1)==0 ){
			std::string value1 = *((std::string*)var_stack->get_value_idx(0));
			std::string value2 = *((std::string*)var_stack->get_value_idx(1));
			if ( var_stack->get_op_idx(0)==0 ){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		}
		//Then the following elements can be processed by loop
		for ( int i=2; i<var_stack->size(); i++ ){
			if ( var_stack->get_type_idx(i)==0 ){
				if ( var_stack->get_op_idx(i-1)==0 ){
					output_op_temp_var(*((std::string*)var_stack->get_value_idx(i)),minus);
				} else {
					output_op_temp_var(*((std::string*)var_stack->get_value_idx(i)),add);
				}
			} else {
				if ( var_stack->get_op_idx(i-1)==0 ){
					output_op_temp_var(*((int*)var_stack->get_value_idx(i)),minus);
				} else {
					output_op_temp_var(*((int*)var_stack->get_value_idx(i)),add);
				}
			}
		}
		//Finally store the result to variable
		text_segment.push_back("la $t0, "+var_id);
		text_segment.push_back("sw $v0, 0($t0)");
	}
}

/* 
 * This function generate the mips code for an write instruction in Micro Language
 */
void Generate_MIPS::generate_code(Variable_Stack* var_stack){
	//If rightside of = has only one element
	if ( var_stack->size() == 1 ){
		if ( var_stack->get_type_idx(0)==0 ){
			text_segment.push_back("la $t0 ,"+*((std::string*)var_stack->get_value_idx(0)));
			text_segment.push_back("lw $v0 ,0($t0)");
		} else {
			text_segment.push_back("li $v0 ,"+std::to_string(*((int*)var_stack->get_value_idx(0))));
		}
	//If rightside of = has more than one element
	} else {
		//Firstly we process the initial two elements
		/**********************************************************************
		 * Here the four condition is the str+-str str+-int int+-str int+-int *
		 **********************************************************************/
		if ( var_stack->get_type_idx(0)==0 && var_stack->get_type_idx(1)==1 ){
			std::string value1 = *((std::string*)var_stack->get_value_idx(0));
			int value2 = *((int*)var_stack->get_value_idx(1));
			if ( var_stack->get_op_idx(0)==0){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		} else if ( var_stack->get_type_idx(0)==1 && var_stack->get_type_idx(1)==0 ){
			std::string value1 = *((std::string*)var_stack->get_value_idx(1));
			int value2 = *((int*)var_stack->get_value_idx(0));
			if ( var_stack->get_type_idx(0)==0 ){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		} else if ( var_stack->get_type_idx(0)==1 && var_stack->get_type_idx(1)==1 ){
			int value1 = *((int*)var_stack->get_value_idx(0));
			int value2 = *((int*)var_stack->get_value_idx(1));
			if ( var_stack->get_type_idx(0)==0 ){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		} else if ( var_stack->get_type_idx(0)==0 && var_stack->get_type_idx(1)==0 ){
			std::string value1 = *((std::string*)var_stack->get_value_idx(0));
			std::string value2 = *((std::string*)var_stack->get_value_idx(1));
			if ( var_stack->get_op_idx(0)==0 ){
				output_op_two_var(value1,value2,minus);
			} else {
				output_op_two_var(value1,value2,add);
			}
		}
		//Then the following elements can be processed by loop
		for ( int i=2; i<var_stack->size(); i++ ){
			if ( var_stack->get_type_idx(i)==0 ){
				if ( var_stack->get_op_idx(i-1)==0 ){
					output_op_temp_var(*((std::string*)var_stack->get_value_idx(i)),minus);
				} else {
					output_op_temp_var(*((std::string*)var_stack->get_value_idx(i)),add);
				}
			} else {
				if ( var_stack->get_op_idx(i-1)==0 ){
					output_op_temp_var(*((int*)var_stack->get_value_idx(i)),minus);
				} else {
					output_op_temp_var(*((int*)var_stack->get_value_idx(i)),add);
				}
			}
		}
	}
	//Finally print the result to screen
	text_segment.push_back("move $a0, $v0");
	text_segment.push_back("li $v0, 1");
	text_segment.push_back("syscall");
	text_segment.push_back("la $a0, _enter");
	text_segment.push_back("li $v0, 4");
	text_segment.push_back("syscall");
}

/* 
 * This function output the mips code that declare a variable [when the variable not declared] 
 */
void Generate_MIPS::output_var_declaration(Variable_Stack* var_stack, std::string var_id){
	if ( !var_stack->if_var_exist(var_id) ){
		var_stack->var_id_update(var_id);
		data_segment.push_back(var_id+": .word 0");
		data_segment.push_back("_"+var_id+": .asciiz \""+var_id+": \"");
	}
}

/*
 * This three functions output the mips code that add two variable with different types[overload] 
 */
void Generate_MIPS::output_op_two_var(std::string var1,std::string var2,op_type indicator){
	text_segment.push_back("lw $t0 ,"+var1);
	text_segment.push_back("lw $t1 ,"+var2);
	text_segment.push_back(op_instr[indicator]+" $v0, $t0, $t1");
}
void Generate_MIPS::output_op_two_var(std::string var1,int var2,op_type indicator){
	text_segment.push_back("li $t1 ,"+std::to_string(var2));
	text_segment.push_back("lw $t0 ,"+var1);
	text_segment.push_back(op_instr[indicator]+" $v0, $t0, $t1");
}
void Generate_MIPS::output_op_two_var(int var1,int var2,op_type indicator){
	text_segment.push_back("li $t0 ,"+std::to_string(var1));
	text_segment.push_back("li $t1 ,"+std::to_string(var2));
	text_segment.push_back(op_instr[indicator]+" $v0, $t0, $t1");
}

/* 
 * This three functions output the mips code that add a variable with different types with the existed value in register(temp value) [overload] 
 */
void Generate_MIPS::output_op_temp_var(int var1,op_type indicator){
	text_segment.push_back("li $t0 ,"+std::to_string(var1));
	text_segment.push_back(op_instr[indicator]+" $v0, $v0, $t0");
}
void Generate_MIPS::output_op_temp_var(std::string var1,op_type indicator){
	text_segment.push_back("lw $t0 ,"+var1);
	text_segment.push_back(op_instr[indicator]+" $v0 ,$v0 ,$t0");
}

/*
 * This function generate the MIPS code for reading integers from keyboard by syscall instruction. 
 */
void Generate_MIPS::output_read_var(std::string var1){
	text_segment.push_back("li $v0 ,4");
	text_segment.push_back("la $a0 ,_prompt");
	text_segment.push_back("syscall");
	text_segment.push_back("li $v0 ,4");
	text_segment.push_back("la $a0 ,_"+var1);
	text_segment.push_back("syscall");
	text_segment.push_back("li $v0 ,5");
	text_segment.push_back("syscall");
	text_segment.push_back("sw $v0 ,"+var1);
}

/* This function write the mips code to "mips.asm" */
void Generate_MIPS::output_mips(){
	std::ofstream out;
	out.open("mips.asm",std::ios::out);
	for ( auto data: data_segment ) { out<<data<<std::endl; }
	for ( auto text: text_segment ) { out<<text<<std::endl; }
}

/**************************************************************************************
 *                                  Variable_Stack Class                              *
 **************************************************************************************/

/* 
 * These two function push the new variable to stack, overload for two type 
 */
void Variable_Stack::variable_push(int int_literal){
	number_elements += 1;
	variable* temp = new variable();
	temp->indicator = integer;
	temp->value = int_literal;
	var_vec.push_back(*temp);
}
void Variable_Stack::variable_push(std::string var_id){
	varid_set.insert(var_id);
	number_elements += 1;
	variable* temp = new variable();
	temp->indicator = str;
	temp->name = var_id;
	var_vec.push_back(*temp);
}

/* These two function push the new operator to stack */
void Variable_Stack::operator_push(std::string op_str){
	if ( op_str=="+" ){ op_vec.push_back(add); } 
	else { op_vec.push_back(minus); }
}

/* This function clear this stack and set the size to 0 */
void Variable_Stack::reset(){
	var_vec.erase(var_vec.begin(),var_vec.end());
	op_vec.erase(op_vec.begin(),op_vec.end());
	number_elements = 0;
}

/* This function return the number of variables in this stack */
int Variable_Stack::size(){
	return number_elements;
}

/* This function return the pointer in form of void* of variable by index */
void* Variable_Stack::get_value_idx(int idx){
	if ( var_vec[idx].indicator == str ){
		return (void*)&var_vec[idx].name;
	} else {
		return (void*)&var_vec[idx].value;
	}
}

/* This function return the type of variable by index, 0 for string, 1 for int */
int Variable_Stack::get_type_idx(int idx){
	if ( var_vec[idx].indicator == str ) { return 0; }
	else { return 1; }
}

/* This function return the type of operator by index[not same with var], 0 for minus, 1 for add */
int Variable_Stack::get_op_idx(int idx){
	if ( op_vec[idx] == add ) { return 1; }
	else { return 0; }
}

/* This function check if this variable has been recorded */
bool Variable_Stack::if_var_exist(std::string var_id){
	if ( varid_set.find(var_id) != varid_set.end() ){ return true; }
	return false;
}

/* This function update the varid_set, which should be called by read() */
void Variable_Stack::var_id_update(std::string var_id){
	varid_set.insert(var_id);
}
