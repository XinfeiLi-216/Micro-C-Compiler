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
VAR [a-z|A-Z][a-z|A-Z|0-9|_]*
DIGIT [0-9]
LETTER [a-z|A-Z]

/***************************************************************************

                                   TOKENS

***************************************************************************/

%%

{COMMENT}[^\n]*     { /* comment */ }
int         { return _INT; }
main        { return _MAIN; }
void        { return _VOID; }
break       { return _BREAK; }
do          { return _DO; }
else        { return _ELSE; }
if          { return _IF; }
while       { return _WHILE; }
return      { return _RETURN; }
scanf       { return _SCANF; }
printf      { return _PRINTF; }
{VAR}       { yylval.svalue=strdup(yytext); return _VAR; }
[0-9]+      { yylval.intval=atoi(yytext); return _NUMBER; }
[(]         { return _LPAREN; }
[)]         { return _RPAREN; }
[{]         { return _LBRACE; }
[}]         { return _RBRACE; }
[[]         { return _LSQUARE; }
[]]         { return _RSQUARE; }
[;]         { return _SEMICOLON; }
[:]         { return _COLON; }
[,]         { return _COMMA; }
[=]         { return _ASSIGN_OP; }
[+]         { return _ADD; }
[-]         { return _MINUS; }
[*]         { return _MULTIPLE; }
[/]         { return _DIVIDE; }
[&]         { return _AND; }
[|]         { return _OR; }
[!]         { return _NOT; }
[<]         { return _LT; }
[>]         { return _GT; }
[<<]        { return _SHL_OP; }
[>>]        { return _SHR_OP; }
[==]        { return _EQ; }
[!=]        { return _NOTEQ; }
[<=]        { return _LTEQ; }
[>=]        { return _GTEQ; }
[||]        { return _OROR; }
[&&]        { return _ANDAND; }
.           { /*empty*/ }

%%