%{
/* create by Zhu Hao */
/* In accordance with the document "PASCAL Syntax - fixed.doc" */

#include <cstdio>
#include <iostream>
#include "pascal.h"

static int label;
static int global;

using namespace myPascal;

//#define YYDEBUG 1

%}

%union {
	identifier *p0;
	program *p1;
	programHead *p2;
	routine *p3;
	routineHead *p4;
	routineBody *p5;
	labelPart *p6;
	constPart *p7;
	typePart *p8;
	varPart *p9;
	routinePart *p10;
	constExpr *p11;
	constExprList *p12;
	constValue *p13;
	typeDefinition *p14;
	typeDeclList *p15;
	typeDecl *p16;
	simpleTypeDecl *p17;
	arrayTypeDecl *p18;
	recordTypeDecl *p19;
	sysType *p20;
	nameList *p21;
	range *p22;
	idrange *p23;
	fieldDecl *p24;
	fieldDeclList *p25;
	varDecl *p26;
	varDeclList *p27;
	functionDecl *p28;
	functionDeclList *p29;
	functionHead *p30;
	procedureDecl *p31;
	procedureDeclList *p32;
	procedureHead *p33;
	subRoutine *p34;
	parameters *p35;
	paraTypeList *p36;
	paraDeclList *p37;
	varParaList *p38;
	valParaList *p39;
	compoundStmt *p40;
	stmt *p41;
	stmtList *p42;
	nonLabelStmt *p43;
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
	expressionList *p55;
	elseClause *p56;
	caseExpr *p57;
	caseExprList *p58;
	expr *p59;
	term *p60;
	factor *p61;
	sysFunction *p62;
	sysCon *p63;
	void *p64;
}

%type <p0> ID
%type <p1> program command
%type <p2> programHead
%type <p3> routine
%type <p4> routineHead
%type <p5> routineBody
%type <p6> labelPart
%type <p7> constPart
%type <p8> typePart
%type <p9> varPart
%type <p10> routinePart
%type <p11> constExpr
%type <p12> constExprList
%type <p13> constValue
%type <p14> typeDefinition
%type <p15> typeDeclList
%type <p16> typeDecl
%type <p17> simpleTypeDecl
%type <p18> arrayTypeDecl
%type <p19> recordTypeDecl
%type <p20> sysType
%type <p21> nameList
%type <p24> fieldDecl
%type <p25> fieldDeclList
%type <p26> varDecl
%type <p27> varDeclList
%type <p28> functionDecl
%type <p30> functionHead
%type <p31> procedureDecl
%type <p33> procedureHead
%type <p34> subRoutine
%type <p35> parameters
%type <p36> paraTypeList
%type <p37> paraDeclList
%type <p38> varParaList
%type <p39> valParaList
%type <p40> compoundStmt
%type <p41> stmt
%type <p42> stmtList
%type <p43> nonLabelStmt
%type <p44> assignStmt
%type <p45> procStmt
%type <p46> ifStmt
%type <p47> repeatStmt
%type <p48> whileStmt
%type <p49> forStmt
%type <p50> caseStmt
%type <p51> gotoStmt
%type <p52> sysProc
%type <p53> expression
%type <p54> argsList
%type <p55> expressionList
%type <p56> elseClause
%type <p57> caseExpr
%type <p58> caseExprList
%type <p59> expr
%type <p60> term
%type <p61> factor
%type <p62> sysFunction
%type <p63> sysCon
%type <p64> INTVALUE REALVALUE CHARVALUE STRINGVALUE
%type <p64> INTEGER REAL CHAR STRING IDENTIFIER
%type <p64> PLUS MINUS MUL DIV LT GT LE GE EQUAL UNEQUAL ASSIGN
%type <p64> LP RP LB RB DOT COMMA SEMI COLON DOTDOT
%type <p64> AND ARRAY BBEGIN CASE CONST DO DOWNTO ELSE END FOR FUNCTION GOTO IF
%type <p64> IN LABEL MOD NIL NOT OF OR OTHERWISE PROCEDURE PROGRAM RECORD
%type <p64> REPEAT THEN TO TYPE UNTIL VAR WHILE
%type <p64> TESTPROC TESTFUNC TESTCON WRITE WRITELN
%type <p64> semi rp rb end colon then

%token AND ARRAY BBEGIN CASE CONST DO DOWNTO ELSE END FOR FUNCTION GOTO IF
%token IN LABEL MOD NIL NOT OF OR OTHERWISE PROCEDURE PROGRAM RECORD
%token INTEGER REAL CHAR STRING IDENTIFIER
%token INTVALUE REALVALUE CHARVALUE STRINGVALUE
%token LP RP LB RB DOT COMMA SEMI COLON DOTDOT
%token PLUS MINUS MUL DIV LT GT LE GE EQUAL UNEQUAL ASSIGN
%token READ REPEAT THEN TO TYPE UNTIL VAR WHILE
%token TESTFUNC TESTPROC TESTCON WRITE WRITELN

%start command

%%

semi : SEMI
	| error { fprintf(stderr, " : Miss ';'\n"); }
	;

rp : RP
	| error { fprintf(stderr, " : Miss ')'\n"); }
	;

rb : RB
	| error { fprintf(stderr, " : Miss ']'\n"); }
	;

end : END
	| error { fprintf(stderr, " : Miss 'end'\n"); }
	;

colon : COLON
	| error { fprintf(stderr, " : Miss ':'\n"); }
	;

then : THEN
	| error { fprintf(stderr, " : Miss 'then'\n"); }
	;

command : program { savedRoot = $1; }
		;

program : programHead routine DOT { $$ = new program($1, $2); }
		;

programHead : PROGRAM ID semi { $$ = new programHead($2); }
			;

ID : IDENTIFIER { $$ = new identifier(yytext, lineno); }
	;

routine : routineHead routineBody { $$ = new routine($1, $2); }
		;

subRoutine : routineHead  routineBody { $$ = new subRoutine($1, $2); }
			;

routineHead : labelPart  constPart  typePart  varPart  routinePart { $$ = new routineHead($1, $2, $3, $4, $5); }
			;

labelPart : { $$ = new labelPart(); }
			;

constPart : CONST  constExprList { $$ = new constPart($2); }
			| { $$ = new constPart(NULL); }
			;

constExprList : constExprList  constExpr {
					constExprList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $2;
					$$ = $1;
				}
				| constExpr { $$ = (constExprList *)$1; }
				;

constExpr : ID EQUAL  constValue  semi { $$ = new constExpr($1, $3, NULL); }
			;

constValue : INTVALUE { $$ = new constValue(1, yytext); }
			| REALVALUE { $$ = new constValue(2, yytext); }
			| CHARVALUE { $$ = new constValue(3, yytext); }
			| STRINGVALUE { $$ = new constValue(4, yytext); }
			| sysCon { $$ = new constValue(5, yytext); }
			;

sysCon : TESTCON { $$ = new sysCon(); }
		;

typePart : TYPE typeDeclList { $$ = new typePart($2); }
			| { $$ = new typePart(NULL); }
			;

typeDeclList : typeDeclList typeDefinition {
					typeDeclList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $2;
					$$ = $1;
				}
				| typeDefinition { $$ = (typeDeclList *)$1; }
				;

typeDefinition : ID EQUAL typeDecl semi { $$ = new typeDefinition($1, $3, NULL); }
				;

typeDecl : simpleTypeDecl { $$ = new typeDecl($1); }
			| arrayTypeDecl { $$ = new typeDecl($1); }
			| recordTypeDecl { $$ = new typeDecl($1); }
			;

simpleTypeDecl : sysType { $$ = new simpleTypeDecl($1); }
				| ID { $$ = new simpleTypeDecl($1); }
				| LP nameList rp { $$ = new simpleTypeDecl($2); }
                | constValue DOTDOT constValue { $$ = new simpleTypeDecl(new range($1, $3)); }
                | MINUS constValue DOTDOT constValue {
					range *temp = new range($2, $4);
					temp->negate(1);
					$$ = new simpleTypeDecl(temp);
				}
                | MINUS constValue DOTDOT MINUS constValue {
					range *temp = new range($2, $5);
					temp->negate();
					$$ = new simpleTypeDecl(temp);
				}
                | ID DOTDOT ID { $$ = new simpleTypeDecl(new idrange($1, $3)); }
				;

sysType : INTEGER { $$ = new sysType(1); }
		| REAL { $$ = new sysType(2); }
		| CHAR { $$ = new sysType(3); }
		| STRING { $$ = new sysType(4); }
		;

arrayTypeDecl : ARRAY LB simpleTypeDecl rb OF typeDecl { $$ = new arrayTypeDecl($3, $6); }
				;

recordTypeDecl : RECORD  fieldDeclList  end { $$ = new recordTypeDecl($2); }
				;

fieldDeclList : fieldDeclList fieldDecl {
					fieldDeclList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $2;
					$$ = $1;
				}
				| fieldDecl { $$ = (fieldDeclList *)$1; }
				;

fieldDecl : nameList colon typeDecl semi { $$ = new fieldDecl($1, $3, NULL); }
			;

nameList : nameList COMMA ID { $$ = new nameList($1, $3); }
		| ID { $$ = new nameList(NULL, $1); }
		;

varPart : VAR varDeclList { $$ = new varPart($2); }
		| { $$ = new varPart(NULL); }
		;

varDeclList : varDeclList varDecl {
					varDeclList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $2;
					$$ = $1;
				}
			| varDecl { $$ = (varDeclList *)$1; }
			;

varDecl : nameList colon typeDecl semi { $$ = new varDecl($1, $3, NULL); }
		;

routinePart : routinePart functionDecl {
				functionDecl *node = $1->child1;
				if(!node)
					$1->child1 = $2;
				else {
					while(node->next)
						node = node->next;
					node->next = $2;
				}
				$$ = $1;
			}
			| routinePart procedureDecl {
				procedureDecl *node = $1->child2;
				if(!node)
					$1->child2 = $2;
				else {
					while(node->next)
						node = node->next;
					node->next = $2;
				}
				$$ = $1;
			}
			| functionDecl { $$ = new routinePart($1, NULL); }
			| procedureDecl { $$ = new routinePart(NULL, $1); }
			| { $$ = new routinePart(NULL, NULL); }
			;

functionDecl : functionHead semi subRoutine semi { $$ = new functionDecl($1, $3, NULL); }
				;

functionHead : FUNCTION ID parameters colon simpleTypeDecl { $$ = new functionHead($2, $3, $5); }
				;

procedureDecl : procedureHead semi subRoutine semi { $$ = new procedureDecl($1, $3, NULL); }
				;

procedureHead : PROCEDURE ID parameters { $$ = new procedureHead($2, $3); }
				;

parameters : LP paraDeclList rp { $$ = new parameters($2); }
			| { $$ = NULL; }
			;

paraDeclList : paraDeclList semi paraTypeList {
					paraDeclList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $3;
					$$ = $1;
				}
				| paraTypeList { $$ = (paraDeclList *)$1; }
				;

paraTypeList : varParaList colon simpleTypeDecl { $$ = new paraTypeList($1, $3, NULL); }
				| valParaList colon simpleTypeDecl { $$ = new paraTypeList($1, $3, $3, NULL); }
				;

varParaList : VAR nameList { $$ = (varParaList *)$2; }
				;

valParaList : nameList { $$ = (valParaList *) $1; }
				;

routineBody : compoundStmt { $$ = new routineBody($1); }
			;

compoundStmt : BBEGIN stmtList end { $$ = new compoundStmt($2,lineno); }
			;

stmtList : stmtList stmt semi {
			stmtList *node = $1;
			if(!node)
				$1 = (stmtList *)$2;
			else {
				while(node->next)
					node = node->next;
				node->next = $2;
			}
			$$ = $1;
		}
		| { $$ = NULL; }
		;

stmt : INTVALUE {
		sscanf(yytext, "%d", &label);
	}
	colon nonLabelStmt {
		$$ = new stmt(label, $4, NULL);
	}
	| nonLabelStmt { $$ = new stmt($1, NULL); }
	;

nonLabelStmt : assignStmt { $$ = new nonLabelStmt($1); }
				| procStmt { $$ = new nonLabelStmt($1); }
				| compoundStmt { $$ = new nonLabelStmt($1); }
				| ifStmt { $$ = new nonLabelStmt($1); }
				| repeatStmt { $$ = new nonLabelStmt($1); }
				| whileStmt { $$ = new nonLabelStmt($1); }
				| forStmt { $$ = new nonLabelStmt($1); }
				| caseStmt { $$ = new nonLabelStmt($1); }
				| gotoStmt { $$ = new nonLabelStmt($1); }
				;

assignStmt : ID ASSIGN  expression { $$ = new assignStmt($1, $3); }
           | ID LB expression rb ASSIGN expression { $$ = new assignStmt($1, $3, $6); }
           | ID DOT ID ASSIGN expression  { $$ = new assignStmt($1, $3, $5); }
			;

procStmt : ID { $$ = new procStmt($1, lineno); }
          | ID LP argsList rp { $$ = new procStmt($1, $3, lineno); }
          | sysProc { $$ = new procStmt($1, lineno); }
          | sysProc LP expressionList rp { $$ = new procStmt($1, $3, lineno); }
          | READ LP factor rp{ $$ = new procStmt($3, lineno); }
		;

sysProc : WRITE { $$ = new sysProc(wwrite); }
	| WRITELN { $$ = new sysProc(wwriteln); }
		;

argsList : argsList COMMA expression {
			argsList *node = $1;
			while(node->next)
				node = node->next;
			node->next = $3;
			$$ = $1;
		}
		| expression { $$ = (argsList *)$1; }
		;

ifStmt : IF expression then stmt elseClause { $$ = new ifStmt($2, $4, $5); }
		;

elseClause : ELSE stmt { $$ = new elseClause($2); }
			| { $$ = new elseClause(); }
			;

repeatStmt : REPEAT stmtList UNTIL expression { $$ = new repeatStmt($2, $4); }
			;

whileStmt : WHILE expression DO stmt { $$ = new whileStmt($2, $4); }
			;

forStmt : FOR ID ASSIGN expression direction expression DO stmt { $$ = new forStmt($2, $4,global, $6, $8); }
			;

direction : TO { global = 1; }
		| DOWNTO { global = 2; }
		;

caseStmt : CASE expression OF caseExprList end { $$ = new caseStmt($2, $4); }
		;

caseExprList : caseExprList caseExpr {
					caseExprList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $2;
					$$ = $1;
				}
				| caseExpr { $$ = (caseExprList *)$1; }
				;

caseExpr : constValue colon stmt semi { $$ = new caseExpr($1, $3, NULL); }
          | ID colon stmt semi { $$ = new caseExpr($1, $3, NULL); }
		  ;

gotoStmt : GOTO INTVALUE {
				int temp;
				sscanf(yytext,"%d",&temp);
				$$ = new gotoStmt(temp);
			}
			;

expressionList : expressionList COMMA expression {
					expressionList *node = $1;
					while(node->next)
						node = node->next;
					node->next = $3;
					$$ = $1;
				}
				| expression { $$ = (expressionList *)$1; }
				;

expression : expression GE expr { $$ = new expression($1, 1, $3, NULL, lineno); }
			| expression GT expr { $$ = new expression($1, 2, $3, NULL, lineno); }
			| expression LE expr { $$ = new expression($1, 3, $3, NULL, lineno); }
			| expression LT expr { $$ = new expression($1, 4, $3, NULL, lineno); }
			| expression EQUAL expr { $$ = new expression($1, 5, $3, NULL, lineno); }
			| expression UNEQUAL expr { $$ = new expression($1, 6, $3, NULL, lineno); }
			| expr { $$ = new expression(NULL, 1, $1, NULL, lineno); }
			;

expr : expr PLUS term { $$ = new expr($1, 1, $3, lineno); }
	| expr MINUS term { $$ = new expr($1, 2, $3, lineno); }
	| expr OR term { $$ = new expr($1, 3, $3, lineno); }
	| term { $$ = new expr(NULL,1, $1, lineno); }
	;

term : term MUL factor { $$ = new term($1, 1, $3, lineno); }
	| term DIV factor { $$ = new term($1, 2, $3, lineno); }
	| term MOD factor { $$ = new term($1, 3, $3, lineno); }
	| term AND factor { $$ = new term($1, 4, $3, lineno); }
	| factor { $$ = new term(NULL, 1, $1, lineno); }
	;

factor : ID { $$ = new factor($1); }
		| ID LP argsList rp { $$ = new factor($1, $3); }
		| sysFunction { $$ = new factor($1); }
		| sysFunction LP argsList rp { $$ = new factor($1, $3); }
		| constValue { $$ = new factor($1); }
		| LP expression rp { $$ = new factor($2); }
		| NOT factor { $$ = new factor($2); }
		| MINUS factor { $$ = new factor($2, $2); }
		| ID LB expression rb { $$ = new factor($1, $3, $3); }
		| ID DOT ID { $$ = new factor($1, $3); }
		;

sysFunction : TESTFUNC { $$ = new sysFunction(); }
		;

%%

int yyerror(const std::string &msg)
{
	fprintf(stderr, "%s occurred at line %d", msg.cStr(), lineno);
	error = true;
	return 0;
}
