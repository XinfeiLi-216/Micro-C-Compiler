/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _INT = 258,
    _MAIN = 259,
    _VOID = 260,
    _BREAK = 261,
    _DO = 262,
    _ELSE = 263,
    _IF = 264,
    _WHILE = 265,
    _RETURN = 266,
    _SCANF = 267,
    _PRINTF = 268,
    _VAR = 269,
    _NUMBER = 270,
    _LPAREN = 271,
    _RPAREN = 272,
    _LBRACE = 273,
    _RBRACE = 274,
    _LSQUARE = 275,
    _RSQUARE = 276,
    _SEMICOLON = 277,
    _COLON = 278,
    _COMMA = 279,
    _ASSIGN_OP = 280,
    _MULTIPLE = 281,
    _DIVIDE = 282,
    _AND = 283,
    _OR = 284,
    _NOT = 285,
    _LT = 286,
    _GT = 287,
    _SHL_OP = 288,
    _SHR_OP = 289,
    _EQ = 290,
    _NOTEQ = 291,
    _LTEQ = 292,
    _GTEQ = 293,
    _OROR = 294,
    _ANDAND = 295,
    _ADD = 296,
    _MINUS = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"
            
   int intval;
   char *svalue;

#line 105 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
