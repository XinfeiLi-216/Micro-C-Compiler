/***************************************************************************

                                    Parser 

***************************************************************************/
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <iostream>
	#include <vector>

     #include "Generate_MIPS/Variable_Stack.hpp"

	//instance of Class that manages the variables/generate mips
	Variable_Stack* variable_stack = new Variable_Stack();
	
	//definition for error function
	void yyerror(std::string msg);

	//prove that flex/bison can be correctly linked
	extern "C" int yyparse();
	extern "C" FILE *yyin;
	extern "C" int yylex();
%}

%union {            
   int intval;
   char *svalue;
} 

/**************************************************************************

                                    Tokens

***************************************************************************/

%token _INT
%token _MAIN
%token _VOID
%token _BREAK
%token _DO
%token _ELSE
%token _IF
%token _WHILE
%token _RETURN
%token _SCANF
%token _PRINTF
%token <svalue> _VAR
%token <intval> _NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACE
%token _RBRACE
%token _LSQUARE
%token _RSQUARE
%token _SEMICOLON
%token _COLON
%token _COMMA
%token _ASSIGN_OP
%token _MULTIPLE
%token _DIVIDE
%token _AND
%token _OR
%token _NOT
%token _LT
%token _GT
%token _SHL_OP
%token _SHR_OP
%token _EQ
%token _NOTEQ
%token _LTEQ
%token _GTEQ
%token _OROR
%token _ANDAND
%token _ADD
%token _MINUS

%left _OROR
%left _ANDAND
%left _OR
%left _AND
%left _EQ _NOTEQ
%left _LT _GT _LTEQ _GTEQ
%left _SHL_OP _SHR_OP
%left _ADD _MINUS
%left _MULTIPLE _DIVIDE
%right _NOT
%left _LSQUARE _RSQUARE
%left _LPAREN _RPAREN

%%

/**************************************************************************

                                    Rules

***************************************************************************/


/************program***********
   var_declarations statements
 ******************************/
program:    /* empty */        
          var_declarations statements 
          ;


/*****var_declarations*****
   statement {statement}
***************************/
var_declarations:  
          var_declarations var_declaration
          |
          /* Empty */
          ;


/********var_declaration*******
   INT declaration_list SEMI
*******************************/
var_declaration:
          _INT declaration_list _SEMICOLON
          ;


/**************declaration_list**********
   declaration_list COMMA declaration
   declaration
*****************************************/
declaration_list:
          declaration_list _COMMA declaration
          |
          declaration
          ;

//------------------------------------------------- TODO: NUMBER ----------------------------

/********declaration********
      ID ASSIGN NUMBER
      ID LSQUARE NUNMBER RSQUARE
      ID
****************************/
declaration:
          /* First Condition */
          _VAR _ASSIGN_OP _MINUS _NUMBER
          { variable_stack->variable_declaration_with_value($1,-1*$4); }
          |
          _VAR _ASSIGN_OP _ADD _NUMBER
          { variable_stack->variable_declaration_with_value($1,$4); }
          |
          _VAR _ASSIGN_OP _NUMBER
          { std::cout<<"ASSIGN"<<std::endl; variable_stack->variable_declaration_with_value($1,$3); }
          |
          /* Second Condition */
          _VAR _LSQUARE _MINUS _NUMBER _RSQUARE
          { std::cout<<"Cannot declare a array with minus length"<<std::endl; }
          |
          _VAR _LSQUARE _ADD _NUMBER _RSQUARE
          { variable_stack->array_declaration($1,$4); }
          |
          _VAR _LSQUARE _NUMBER _RSQUARE
          { variable_stack->array_declaration($1,$3); }
          |
          _VAR
          { variable_stack->variable_declaration_without_value($1); }
          ;


/**********code_block**********
   statement
   LBRACE statements RBRACES
*******************************/
code_block:
          statement
          { variable_stack->codeblock_end(); }
          |
          _LBRACE statements _RBRACE
          { variable_stack->codeblock_end(); }
          ;


/********statements********
     statements statement 
     statement     
***************************/
statements:
          statements statement
          |
          statement
          ;


/********statement**********
     assign_statement SEMI
     control_statement 
     read_write_statement SEMI
     SEMI     
****************************/
statement:
          assign_statement _SEMICOLON
          { std::cout<<"ASSIGN"<<std::endl; }
          |
          control_statement 
          |
          read_write_statement _SEMICOLON
          |
          _SEMICOLON
          ;


/********control_statement**********
     if_statement
     while_statement
     do_while_statement SEMI
     return_statement SEMI   
************************************/
control_statement:
          if_statement
          |
          while_statement 
          |
          do_while_statement _SEMICOLON
          |
          return_statement _SEMICOLON
          ;


/********read_write_statement********
     read_statement
     write_statement 
*************************************/
read_write_statement:
          read_statement
          |
          write_statement 
          ;


/*************assign_statement************
     ID LSQUARE exp RSQUARE ASSIGN exp
     ID ASSIGN exp
******************************************/
assign_statement:
          _VAR _LSQUARE exp _RSQUARE _ASSIGN_OP exp
          { 
               variable_stack->array_be_valued($1);
          }
          |
          _VAR _ASSIGN_OP exp
          {
               variable_stack->variable_be_valued($1);
          }
          ;


/*************if_statement************
     if_stmt
     if_stmt ELSE code_block
**************************************/
if_statement:
          if_stmt
          { 
               std::cout<<"if_stmt"<<std::endl;
          }
          |
          if_stmt else code_block
          { 
               std::cout<<"else_stmt"<<std::endl; 
               variable_stack->else_end();
          }
          ;


/******************else*****************
     else
****************************************/
else:
     _ELSE
     { variable_stack->if_else(); }
     ;    


/****************if_stmt****************
     if LPAREN exp RPAREN code_block
****************************************/
if_stmt:
          _IF _LPAREN exp if_rparen code_block
          { variable_stack->if_end(); }
          ;


/****************if_rparen**************
     _RPAREN
****************************************/
if_rparen:
     _RPAREN
     { variable_stack->if_rparen(); }
     ;    


/*************while_statement*************
     while LPAREN exp RPAREN code_block
******************************************/
while_statement:
          while _LPAREN exp while_rparen code_block
          { 
               std::cout<<"WHILE"<<std::endl;
               variable_stack->while_end();
          }
          ;


/*************do_while_statement************
     DO code_block WHILE LPAREN exp RPAREN 
********************************************/
do_while_statement:
          do code_block _WHILE _LPAREN exp do_while_rparen
          {  }
          ;


/*********************do********************
     _DO
********************************************/
do:
          _DO
          { variable_stack->do_while_stmt(); }
          ;


/**************do_while_rparen**************
     _RPAREN
********************************************/
do_while_rparen:
          _RPAREN
          { variable_stack->do_while_rparen(); }
          ;


/********************while******************
     _WHILE
********************************************/
while:
     _WHILE
     { variable_stack->while_stmt(); }
     ;


/***************while_rparen****************
     _RPAREN
********************************************/
while_rparen:
     _RPAREN
     { variable_stack->while_rparen(); }
     ;


/*************return_statement**************
     #TODO
********************************************/
return_statement:
          _RETURN
          ;


/************read_statement*********
     READ LPAREN ID RPAREN
************************************/
read_statement:
          _SCANF _LPAREN _VAR _RPAREN
          ;


/************write_statement*********
     READ LPAREN ID RPAREN
*************************************/
write_statement:
          _PRINTF _LPAREN exp _RPAREN
          ;


/******************exp***************
     # TODO
*************************************/
exp:
          // ---------------------------------TODOTODOTODOTODO
          _NUMBER
          { variable_stack->expression_declaration($1); }
          |
          _ADD _NUMBER
          { variable_stack->expression_declaration($2); }
          |
          _VAR
          {    
               if (variable_stack->variable_value_exists($1)) {
                    variable_stack->expression_variable($1);    
               } else {
                    std::cout<<"[Error] Use uninitial value in program"<<std::endl;
                    abort();
               }
          }
          |
          _VAR _LSQUARE exp _RSQUARE
          |
          _NOT exp
          {
               std::cout<<"NOT"<<std::endl;
               variable_stack->expression_operations(_not);
          }
          |
          exp _AND exp
          {
               std::cout<<"AND"<<std::endl;
               variable_stack->expression_operations(_and);
          }
          |
          exp _OR exp
          {
               std::cout<<"OR"<<std::endl;
               variable_stack->expression_operations(_or);
          }
          |
          exp _ADD exp
          {
               std::cout<<"ADD"<<std::endl;
               variable_stack->expression_operations(add);
          }
          |
          exp _MINUS exp
          { 
               std::cout<<"MINUS"<<std::endl; 
               variable_stack->expression_operations(minus);
          }
          |
          exp _MULTIPLE exp
          { 
               std::cout<<"MULTIPLE"<<std::endl;
               variable_stack->expression_operations(multiple); 
          }
          |
          exp _DIVIDE exp
          { 
               std::cout<<"DIVIDE"<<std::endl; 
               variable_stack->expression_operations(divide);
          }
          |
          exp _LT exp
          { 
               std::cout<<"LT"<<std::endl; 
               variable_stack->expression_operations(lt);
          }
          |
          exp _GT exp
          { 
               std::cout<<"GT"<<std::endl; 
               variable_stack->expression_operations(gt);
          }
          |
          exp _EQ exp
          { 
               std::cout<<"EQUAL"<<std::endl; 
               variable_stack->expression_operations(equal);
          }
          |
          exp _NOTEQ exp
          { 
               std::cout<<"NOTEQ"<<std::endl; 
               variable_stack->expression_operations(noteq);
          }
          |
          exp _LTEQ exp
          { 
               std::cout<<"LTEQ"<<std::endl; 
               variable_stack->expression_operations(lteq);
          }
          |
          exp _GTEQ exp
          { 
               std::cout<<"GTEQ"<<std::endl; 
               variable_stack->expression_operations(gteq);
          }
          |
          exp _SHL_OP exp
          { 
               std::cout<<"SHLOP"<<std::endl; 
               variable_stack->expression_operations(shlop);
          }
          |
          exp _SHR_OP exp
          { 
               std::cout<<"SHROP"<<std::endl; 
               variable_stack->expression_operations(shrop);
          }
          |
          exp _ANDAND exp
          { 
               std::cout<<"ANDAND"<<std::endl; 
               variable_stack->expression_operations(andand);
          }
          |
          exp _OROR exp
          { 
               std::cout<<"OROR"<<std::endl; 
               variable_stack->expression_operations(oror);
          }
          |
          _LPAREN exp _RPAREN
          { 
               std::cout<<"PAREN"<<std::endl; 
               variable_stack->expression_operations(paren);
          }
          |
          _MINUS exp
          {
               std::cout<<"MINUS_NUMBER"<<std::endl;
               variable_stack->expression_operations(minus_number);
          }
          ;


%%


/**************************************************************************

                                   C Code

***************************************************************************/

void yyerror(std::string msg) {
    std::cout<<msg<<std::endl;
}

int main(int argc, char* argv[]) {
	/* Read the micro code */
	if (argc < 2) {
		fprintf(stderr, "Missing input file!\n");
	}
	yyin = fopen(argv[1], "r");
	if ( yyparse() ) {
          fprintf(stderr, "Unable to parse the input!\n");
          return 1;
	}
	fclose(yyin);
	/* Output the MIPS code */
	variable_stack->generate();
	return 0;
}
