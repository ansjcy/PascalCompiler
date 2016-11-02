/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C

      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debugeGrs
      know about them.  */
   enum yytokentype {
     INTVALUE = 258,
     REALVALUE = 259,
     CHARVALUE = 260,
     STRINGVALUE = 261,
     INTEGER = 262,
     REAL = 263,
     CHAR = 264,
     STRING = 265,
     IDENTIFIER = 266,
     PLUS = 267,
     MINUS = 268,
     MUL = 269,
     DIV = 270,
     LT = 271,
     GT = 272,
     LE = 273,
     GE = 274,
     EQUAL = 275,
     UNEQUAL = 276,
     ASSIGN = 277,
     LP = 278,
     RP = 279,
     LB = 280,
     RB = 281,
     DOT = 282,
     COMMA = 283,
     SEMI = 284,
     COLON = 285,
     DOTDOT = 286,
     AND = 287,
     ARRAY = 288,
     BBEGIN = 289,
     CASE = 290,
     CONST = 291,
     DO = 292,
     DOWNTO = 293,
     ELSE = 294,
     END = 295,
     FOR = 296,
     FUNCTION = 297,
     GOTO = 298,
     IF = 299,
     IN = 300,
     LABEL = 301,
     MOD = 302,
     NIL = 303,
     NOT = 304,
     OF = 305,
     OR = 306,
     OTHERWISE = 307,
     PROCEDURE = 308,
     PROGRAM = 309,
     RECORD = 310,
     READ = 311,
     REPEAT = 312,
     THEN = 313,
     TO = 314,
     TYPE = 315,
     UNTIL = 316,
     VAR = 317,
     WHILE = 318,
     TESTFUNC = 319,
     TESTPROC = 320,
     TESTCON = 321,
     WRITE = 322,
     WRITELN = 323
   };
#endif
/* Tokens.  */
#define INTVALUE 258
#define REALVALUE 259
#define CHARVALUE 260
#define STRINGVALUE 261
#define INTEGER 262
#define REAL 263
#define CHAR 264
#define STRING 265
#define IDENTIFIER 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define LT 271
#define GT 272
#define LE 273
#define GE 274
#define EQUAL 275
#define UNEQUAL 276
#define ASSIGN 277
#define LP 278
#define RP 279
#define LB 280
#define RB 281
#define DOT 282
#define COMMA 283
#define SEMI 284
#define COLON 285
#define DOTDOT 286
#define AND 287
#define ARRAY 288
#define BBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FOR 296
#define FUNCTION 297
#define GOTO 298
#define IF 299
#define IN 300
#define LABEL 301
#define MOD 302
#define NIL 303
#define NOT 304
#define OF 305
#define OR 306
#define OTHERWISE 307
#define PROCEDURE 308
#define PROGRAM 309
#define RECORD 310
#define READ 311
#define REPEAT 312
#define THEN 313
#define TO 314
#define TYPE 315
#define UNTIL 316
#define VAR 317
#define WHILE 318
#define TESTFUNC 319
#define TESTPROC 320
#define TESTCON 321
#define WRITE 322
#define WRITELN 323




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 22 "parser.y"

	identifier *p0;
	program *p1;
	progHead *p2;
	routine *p3;
	routHead *p4;
	routBody *p5;
	lbP *p6;
	consP *p7;
	typeP *p8;
	varP *p9;
	routP *p10;
	consExp *p11;
	consExp_list *p12;
	consVal *p13;
	typeDef *p14;
	typeDecl_list *p15;
	typeDecl *p16;
	simple_typeDecl *p17;
	array_typeDecl *p18;
	record_typeDecl *p19;
	sysType *p20;
	nameList *p21;
	range *p22;
	idrange *p23;
	fieldlDecl *p24;
	fieldDeclList *p25;
	varDecl *p26;
	varDeclList *p27;
	funcDecl *p28;
	funcDeclList *p29;
	funcHead *p30;
	procDecl *p31;
	procDecl_list *p32;
	procHead *p33;
	subRout *p34;
	parameters *p35;
	paraTypeList *p36;
	paraDeclList *p37;
	varPList *p38;
	val_para_list *p39;
	compStmt *p40;
	stmt *p41;
	stmtList *p42;
	nlbStmt *p43;
	assignStmt *p44;
	procStmt *p45;
	ifStmt *p46;
	repeatStmt *p47;
	whileStmt *p48;
	forStmt *p49;
	caseStmt *p50;
	gotoStmt *p51;
	sysProc *p52;
	expression *p53;
	argsList *p54;
	expList *p55;
	elsePart *p56;
	caseExp *p57;
	caseExp_list *p58;
	expr *p59;
	term *p60;
	factor *p61;
	sysFunc *p62;
	sysCon *p63;
	void *p64;



/* Line 2068 of yacc.c  */
#line 256 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;
