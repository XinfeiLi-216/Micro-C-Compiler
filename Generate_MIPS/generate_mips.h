#ifndef __GENERATE_MIPS_H__
#define __GENERATE_MIPS_H__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <map>

/*
 * This class preserve the occurence variable's type and value. For more details, there are 3 data structure to store the variable.
 * They are [varid_set,var_vec,op_vec]. The {varid_set} record all variables name, so that we can know if a new variable should be declared.
 * {var_vec,op_vec} are two vectors for storing the variable and operator.
 */
class Variable_Stack{
	public:
		/*************************************
		 *           Defined Struct          *
		 *************************************/
		/* Struct used as parameters in function */
		enum add_op{minus,add};	
		enum var_type{str,integer};
		/* Struct that record a variable's type and value(any form) */
		struct variable{
			var_type indicator;
			int value;
			std::string name;
		};

		/*************************************
		 *         Attribute Function        *
		 *************************************/
		/* This function return the number of variables in this stack */
		int size();
		/* This function clear this stack and set the size to 0, but no operation to varid_set[Because the varid_set should record var in all program] */
		void reset();

		/*************************************
		 *      Variable Update Function     *
		 *************************************/
		/* These two function push the new variable to stack, override for two type */
		void variable_push(int int_literal);
		void variable_push(std::string var_id);
		/* These two function push the new operator to stack */
		void operator_push(std::string op_str);
		
		/*************************************
		 *          Get Value Function       *
		 *************************************/
		/* This function return the pointer in form of void* of variable by index */
		void* get_value_idx(int idx);
		/* This function return the type of variable by index, 0 for string, 1 for int */
		int get_type_idx(int idx);
		/* This function return the type of operator by index[not same with var], 0 for minus, 1 for add */
		int get_op_idx(int idx);
		/* This function check if this variable has been recorded */
		bool if_var_exist(std::string var_id);
		/* This function update the varid_set, which should be called by variable_declaration() */
		void var_id_update(std::string var_id);

	private:
		/*************************************
		 *    Data Structure for Variable    *
		 *************************************/
		/* Store the declared variables, used for avoid redundant declaration MIPS code */
		std::unordered_set<std::string> varid_set;
		/* Store the variable value&type */
		std::vector<variable> var_vec;
		/* Store the occurence operators */
		std::vector<add_op> op_vec;
		/* Store the number of variables */
		int number_elements = 0;
};

/*
 * This class correspond for generating the MIPS code. 
 * The main process is {Variable_Stack -> Functions -> MIPS Code[Stored in vector] -> mips.asm}
 * [What is more, there is two vector, data_segment and text_segment, represent the data/text segment in mips]      
 */
class Generate_MIPS{
	public:
		/*************************************
		 *           Defined Struct          *
		 *************************************/
		/* Struct used as parameters in function */
		enum op_type{minus,add};
		/* Struct used as parameters in function */
		std::map<op_type,std::string> op_instr{{minus,"sub"},{add,"add"}};

		/*************************************
		 *          Generate Functions       *
		 *************************************/
		/* 
		 * This two function generate mips code by variable stack, override for write&assign instr
		 * First function for assign operation, var_id is the variable be assigned.
		 * Second function for write operation, which print the value to screen
		 */
		void generate_code(Variable_Stack* var_stack,std::string var_id);
		void generate_code(Variable_Stack* var_stack);
		/* This function generate the mips code for read var_id form keyboard with prompt */
		void output_read_var(std::string var1);
		/* This function write the mips code to "mips.asm" */
		void output_mips();

		/***********************************************
		 *          Tool functions in generating       *
		 ***********************************************/
		/* This function output the mips code that declare a variable[when variable not declared, in form [var_name .word(.asciiz) value]*/
		void output_var_declaration(Variable_Stack* var_stack, std::string var_id);
		/* This three functions output the mips code that add two variable with different types[override] */
		void output_op_two_var(std::string var1,std::string var2,op_type indicator);
		void output_op_two_var(std::string var1,int var2,op_type indicator);
		void output_op_two_var(int var1,int var2,op_type indicator);
		/* This three functions output the mips code that add a variable with different types with the existed value in register(temp value) [override] */
		void output_op_temp_var(std::string var1,op_type indicator);
		void output_op_temp_var(int var1,op_type indicator);
	private:
		/* This vector store the data segment of mips code */
		std::vector<std::string> data_segment{".data",
			"_prompt: .asciiz \"Enter the value of variable \" ",
			"_enter: .asciiz \"  \\n\" "};
		/* This vector store the text segment of mips code */
		std::vector<std::string> text_segment{".text"};
};

#endif
