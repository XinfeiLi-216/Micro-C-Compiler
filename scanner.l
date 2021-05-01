/***************************************************************************

                                    Scanner 

***************************************************************************/
%option noyywrap

%{
#include <iostream>
#include <stdlib.h>
#include "parser.tab.h"  
extern "C" int yylex();
%}

/***************************************************************************

                              TOKEN DEFINITIONS

***************************************************************************/
VAR [a-zA-Z][a-zA-Z0-9_]*
DIGIT [0-9]
LETTER [a-zA-Z]

/***************************************************************************

                                   TOKENS

***************************************************************************/

%%

int         { std::cout<<"_INT"<<std::endl; return _INT; }
main        { std::cout<<"_MAIN"<<std::endl; return _MAIN; }
void        { std::cout<<"_VOID"<<std::endl; return _VOID; }
break       { std::cout<<"_BREAK"<<std::endl; return _BREAK; }
do          { std::cout<<"_DO"<<std::endl; return _DO; }
else        { std::cout<<"_ELSE"<<std::endl; return _ELSE; }
if          { std::cout<<"_IF"<<std::endl; return _IF; }
while       { std::cout<<"_WHILE"<<std::endl; return _WHILE; }
return      { std::cout<<"_RETURN"<<std::endl; return _RETURN; }
scanf       { std::cout<<"_SCANF"<<std::endl; return _SCANF; }
printf      { std::cout<<"_PRINTF"<<std::endl; return _PRINTF; }
{VAR}       { yylval.svalue=strdup(yytext); std::cout<<"_VAR"<<std::endl;  return _VAR; }
[0-9]+      { yylval.intval=atoi(yytext); std::cout<<"_NUMBER"<<std::endl; return _NUMBER; }
[(]         { std::cout<<"_LPAREN"<<std::endl; return _LPAREN; }
[)]         { std::cout<<"_RPAREN"<<std::endl; return _RPAREN; }
[{]         { std::cout<<"_LBRACE"<<std::endl; return _LBRACE; }
[}]         { std::cout<<"_RBRACE"<<std::endl; return _RBRACE; }
[[]         { std::cout<<"_LSQUARE"<<std::endl; return _LSQUARE; }
[]]         { std::cout<<"_RSQUARE"<<std::endl; return _RSQUARE; }
[;]         { std::cout<<"_SEMICOLON"<<std::endl; return _SEMICOLON; }
[:]         { std::cout<<"_COLON"<<std::endl; return _COLON; }
[,]         { std::cout<<"_COMMA"<<std::endl; return _COMMA; }
"<<"        { std::cout<<"_SHL_OP"<<std::endl; return _SHL_OP; }
">>"        { std::cout<<"_SHR_OP"<<std::endl; return _SHR_OP; }
"=="        { std::cout<<"_EQ"<<std::endl; return _EQ; }
"!="        { std::cout<<"_NOTEQ"<<std::endl; return _NOTEQ; }
"<="        { std::cout<<"_LTEQ"<<std::endl; return _LTEQ; }
">="        { std::cout<<"_GTEQ"<<std::endl; return _GTEQ; }
"||"        { std::cout<<"_OROR"<<std::endl; return _OROR; }
"&&"        { std::cout<<"_ANDAND"<<std::endl; return _ANDAND; }
[=]         { std::cout<<"_ASSIGN_OP"<<std::endl; return _ASSIGN_OP; }
[+]         { std::cout<<"_ADD"<<std::endl; return _ADD; }
[-]         { std::cout<<"_MINUS"<<std::endl; return _MINUS; }
[*]         { std::cout<<"_MULTIPLE"<<std::endl; return _MULTIPLE; }
[/]         { std::cout<<"_DIVIDE"<<std::endl; return _DIVIDE; }
[&]         { std::cout<<"_AND"<<std::endl; return _AND; }
[|]         { std::cout<<"_OR"<<std::endl; return _OR; }
[!]         { std::cout<<"_NOT"<<std::endl; return _NOT; }
[<]         { std::cout<<"_LT"<<std::endl; return _LT; }
[>]         { std::cout<<"_GT"<<std::endl; return _GT; }
[ ]         { /* empty */ }

%%