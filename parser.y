/***************************************************************************

                                    Parser 

***************************************************************************/
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <iostream>
	#include <vector>

     #include "Generate_MIPS/generate_mips.h"

	//Instance of Class that manages the variables/generate mips
	Variable_Stack* var_stack = new Variable_Stack();
     Generate_MIPS* mips_code = new Generate_MIPS();
	
	//Definition for error function
	void yyerror(std::string msg);

	//Proof that flex/bison can be correctly linked
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

%left _LPAREN _RPAREN
%left _LSQUARE _RSQUARE
%right _NOT
%left _MULTIPLE _DIVIDE
%left _ADD _MINUS
%left _SHL_OP _SHR_OP
%left _LT _GT _LTEQ _GTEQ
%left _EQ _NOTEQ
%left _AND
%left _ANDAND
%left _OROR

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
            |
            _VAR _ASSIGN_OP _ADD _NUMBER
            |
            _VAR _ASSIGN_OP _NUMBER
            |
            /* Second Condition */
            _VAR _LSQUARE _MINUS _NUMBER _RSQUARE
            |
            _VAR _LSQUARE _ADD _NUMBER _RSQUARE
            |
            _VAR _LSQUARE _NUMBER _RSQUARE
            |
            _VAR
            ;


/**********code_block**********
   statement
   LBRACE statements RBRACES
*******************************/
code_block:
            statement
            |
            _LBRACE statements _RBRACE
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
            |
            _VAR _ASSIGN_OP exp 
            ;


/*************if_statement************
     if_stmt
     if_stmt ELSE code_block
**************************************/
if_statement:
            if_stmt
            { std::cout<<"if_stmt"<<std::endl; }
            |
            if_stmt _ELSE code_block
            { std::cout<<"else_stmt"<<std::endl; }
            ;


/****************if_stmt****************
     if LPAREN exp RPAREN code_block
****************************************/
if_stmt:
            _IF _LPAREN exp _RPAREN code_block
            ;


/*************while_statement*************
     while LPAREN exp RPAREN code_block
******************************************/
while_statement:
            _WHILE _LPAREN exp _RPAREN code_block
            ;


/*************do_while_statement************
     DO code_block WHILE LPAREN exp RPAREN 
********************************************/
do_while_statement:
            _DO code_block _WHILE _LPAREN exp _RPAREN
            ;


/*************return_statement**************
     while LPAREN exp RPAREN code_block
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
            |
            _ADD _NUMBER
            |
            _VAR
            |
            _VAR _LSQUARE exp _RSQUARE
            |
            _NOT exp
            |
            exp _AND exp
            |
            exp _OR exp
            |
            exp _ADD exp
            { std::cout<<"ADD"<<std::endl; }
            |
            exp _MINUS exp
            { std::cout<<"ADD"<<std::endl; }
            |
            exp _MULTIPLE exp
            |
            exp _DIVIDE exp
            |
            exp _LT exp
            |
            exp _GT exp
            |
            exp _EQ exp
            |
            exp _NOTEQ exp
            |
            exp _LTEQ exp
            |
            exp _GTEQ exp
            |
            exp _SHL_OP exp
            |
            exp _SHR_OP exp
            |
            exp _ANDAND exp
            |
            exp _OROR exp
            |
            _LPAREN exp _RPAREN
            |
            _MINUS exp
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
	//fclose(yyin);
	/* Output the MIPS code */
	//mips_code->output_mips();
	//return 0;
}