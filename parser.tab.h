/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _INT = 258,                    /* _INT  */
    _MAIN = 259,                   /* _MAIN  */
    _VOID = 260,                   /* _VOID  */
    _BREAK = 261,                  /* _BREAK  */
    _DO = 262,                     /* _DO  */
    _ELSE = 263,                   /* _ELSE  */
    _IF = 264,                     /* _IF  */
    _WHILE = 265,                  /* _WHILE  */
    _RETURN = 266,                 /* _RETURN  */
    _SCANF = 267,                  /* _SCANF  */
    _PRINTF = 268,                 /* _PRINTF  */
    _VAR = 269,                    /* _VAR  */
    _NUMBER = 270,                 /* _NUMBER  */
    _LPAREN = 271,                 /* _LPAREN  */
    _RPAREN = 272,                 /* _RPAREN  */
    _LBRACE = 273,                 /* _LBRACE  */
    _RBRACE = 274,                 /* _RBRACE  */
    _LSQUARE = 275,                /* _LSQUARE  */
    _RSQUARE = 276,                /* _RSQUARE  */
    _SEMICOLON = 277,              /* _SEMICOLON  */
    _COLON = 278,                  /* _COLON  */
    _COMMA = 279,                  /* _COMMA  */
    _ASSIGN_OP = 280,              /* _ASSIGN_OP  */
    _MULTIPLE = 281,               /* _MULTIPLE  */
    _DIVIDE = 282,                 /* _DIVIDE  */
    _AND = 283,                    /* _AND  */
    _OR = 284,                     /* _OR  */
    _NOT = 285,                    /* _NOT  */
    _LT = 286,                     /* _LT  */
    _GT = 287,                     /* _GT  */
    _SHL_OP = 288,                 /* _SHL_OP  */
    _SHR_OP = 289,                 /* _SHR_OP  */
    _EQ = 290,                     /* _EQ  */
    _NOTEQ = 291,                  /* _NOTEQ  */
    _LTEQ = 292,                   /* _LTEQ  */
    _GTEQ = 293,                   /* _GTEQ  */
    _OROR = 294,                   /* _OROR  */
    _ANDAND = 295,                 /* _ANDAND  */
    _ADD = 296,                    /* _ADD  */
    _MINUS = 297                   /* _MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"
            
   int intval;
   char *svalue;

#line 111 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
