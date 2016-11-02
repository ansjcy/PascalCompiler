#ifndef _PASCTRL_H_
#define _PASCTRL_H_

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>

#include "PascaltyPe.h"
#include "PascalCommon.h"
#include "PascalStmt.h"

namespace myPascal {

struct typeP {
	typeDecl_list *child1;
	typeP(typeDecl_list *c1):child1(c1) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct typeDef {
	identifier *child1;
	typeDecl *child2;
	typeDef *next;
	typeDef(identifier *c1, typeDecl *c2, typeDef *n):child1(c1),child2(c2),next(n) { printf("typeDef constructor : %s\n", c1->name.c_str()); }
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct typeDecl {
	int choice1;
	union {
		simple_typeDecl *choice1;
		array_typeDecl *choice2;
		record_typeDecl *choice3;
	} child1;
	typeDecl(simple_typeDecl *c1):choice1(1) { child1.choice1 = c1; }
	typeDecl(array_typeDecl *c2):choice1(2) { child1.choice2 = c2; }
	typeDecl(record_typeDecl *c3):choice1(3) { child1.choice3 = c3; }
	bool sematicAnalysis(identifier *id, int scope, int type);
	bool sematicAnalysis(nameList *ids, int scope, int type);
	std::string assembleGenerator();
};

struct simple_typeDecl {
	int choice1;
	union {
		sysType *choice1;
		myPascal::identifier *choice2;
		nameList *choice3;
		range *choice4;
		idrange *choice5;
	} child1;
	simple_typeDecl(sysType *c1):choice1(1) { child1.choice1 = c1; }
	simple_typeDecl(myPascal::identifier *c2):choice1(2) { child1.choice2 = c2; }
	simple_typeDecl(nameList *c3):choice1(3) { child1.choice3 = c3; }
	simple_typeDecl(range *c4):choice1(4) { child1.choice4 = c4; }
	simple_typeDecl(idrange *c5):choice1(5) { child1.choice5 = c5; }
	bool sematicAnalysis(identifier *id, int scope, int type);
	bool sematicAnalysis(nameList *ids, int scope, int type);
	std::string assembleGenerator();
};

struct sysType {
	simpleType child1;
	sysType(int c1) {
		switch(c1) {
		case 1: child1 = integerI; break;
		case 2: child1 = realR; break;
		case 3: child1 = charC; break;
		case 4: child1 = stringS; break;
		default: break;
		}
	}
	std::string assembleGenerator();
};

struct range {
	int lineno;
	consVal *child1;
	consVal *child2;
	range(consVal *c1, consVal *c2):child1(c1),child2(c2),size(-1) {}
	int size;
	void negate() { child1->negate(); child2->negate(); }
	void negate(int c) { c==1?child1->negate():child2->negate(); }
	bool sematicAnalysis();
	std::string assembleGenerator();
};

struct idrange {
	identifier *child1;
	identifier *child2;
	idrange(identifier *c1, identifier *c2):child1(c1),child2(c2) {}
	std::string assembleGenerator();
};

struct array_typeDecl {
	simple_typeDecl *child1;
	typeDecl *child2;
	array_typeDecl(simple_typeDecl *c1, typeDecl *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(identifier *id, int scope, int type);
	std::string assembleGenerator();
};

struct record_typeDecl {
	fieldDeclList *child1;
	record_typeDecl(fieldDeclList *c1):child1(c1) {}
	bool sematicAnalysis(identifier *id, int scope, int type) {
		return true;
	}
	std::string assembleGenerator();
};

struct fieldlDecl {
	nameList *child1;
	typeDecl *child2;
	fieldlDecl *next;
	fieldlDecl(nameList *c1, typeDecl *c2, fieldlDecl *n):child1(c1),child2(c2),next(n) {}
	std::string assembleGenerator();
};

struct nameList {
	nameList *child1;
	identifier *child2;
	nameList(nameList *c1, identifier *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct varP {
	varDeclList *child1;
	varP(varDeclList *c1):child1(c1) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct varDecl {
	nameList *child1;
	typeDecl *child2;
	varDecl *next;
	varDecl(nameList *c1, typeDecl *c2, varDecl *n):child1(c1),child2(c2),next(n) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct routP {
	funcDeclList *child1;
	procDecl_list *child2;
	routP(funcDeclList *c1, procDecl_list *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct funcDecl {
	funcHead *child1;
	subRout *child2;
	funcDecl *next;
	funcDecl(funcHead *c1, subRout *c2, funcDecl *n):child1(c1),child2(c2),next(n) {}
	bool nameCheck(int scope);
	bool sematicAnalysis(int scope);
	void reversePosition(int scope);
	std::string assembleGenerator();
};

struct funcHead {
	identifier *child1;
	parameters *child2;
	simple_typeDecl *child3;
	funcHead(identifier *c1, parameters *c2, simple_typeDecl *c3):child1(c1),child2(c2),child3(c3) {}
	bool sematicAnalysis(funcDecl *root, int scope);
	std::string assembleGenerator();
};

struct procDecl {
	procHead *child1;
	subRout *child2;
	procDecl *next;
	procDecl(procHead *c1, subRout *c2, procDecl *n):child1(c1),child2(c2),next(n) {}
	bool nameCheck(int scope);
	bool sematicAnalysis(int scope);
	void reversePosition(int scope);
	std::string assembleGenerator();
};

struct procHead {
	identifier *child1;
	parameters *child2;
	procHead(identifier *c1, parameters *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(procDecl *root, int scope);
	std::string assembleGenerator();
};

struct parameters {
	paraDeclList *child1;
	parameters(paraDeclList *c1):child1(c1) {}
	bool sematicAnalysis(identifier *root, int scope);
	std::string assembleGenerator();
};

struct paraTypeList {
	int choice1;
	union {
		varPList *choice1;
		val_para_list *choice2;
	} child1;
	simple_typeDecl *child2;
	paraTypeList *next;
	paraTypeList(varPList *c1, simple_typeDecl *c2, paraTypeList *n):choice1(1),child2(c2),next(n) { child1.choice1 = c1; }
	paraTypeList(val_para_list *c1, simple_typeDecl *c2, simple_typeDecl *dummy,paraTypeList *n):choice1(2),child2(c2),next(n) { child1.choice2 = c1; }
	bool sematicAnalysis(identifier *root, int scope);
	void addParameters(identifier *root, nameList *ids, int type);
	std::string assembleGenerator();
};

struct routBody {
	compStmt *child1;
	routBody(compStmt *c):child1(c) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct compStmt {
	static int serial;
	static char buff[20];
	stmtList *child1;
	identifier *temp;
	compStmt(stmtList *c1, identifier *t):child1(c1),temp(t) {}
	compStmt(stmtList *c1, int lineno):child1(c1){
		sprintf(buff,"#comp%d", serial++);
		temp = new identifier(buff, lineno);
	}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct stmt {
	int choice1;
	int child1;
	nlbStmt *child2;
	stmt *next;
	stmt(int c1,nlbStmt *c2, stmt *n):choice1(1),child1(c1),child2(c2),next(n) {}
	stmt(nlbStmt *c2, stmt *n):choice1(0),child2(c2),next(n) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct nlbStmt {
	int choice1;
	union {
		assignStmt *choice1;
		procStmt *choice2;
		compStmt *choice3;
		ifStmt *choice4;
		repeatStmt *choice5;
		whileStmt *choice6;
		forStmt *choice7;
		caseStmt *choice8;
		gotoStmt *choice9;
	} child1;
	nlbStmt(assignStmt *c1):choice1(1) { child1.choice1 = c1; }
	nlbStmt(procStmt *c1):choice1(2) { child1.choice2 = c1; }
	nlbStmt(compStmt *c1):choice1(3) { child1.choice3 = c1; }
	nlbStmt(ifStmt *c1):choice1(4) { child1.choice4 = c1; }
	nlbStmt(repeatStmt *c1):choice1(5) { child1.choice5 = c1; }
	nlbStmt(whileStmt *c1):choice1(6) { child1.choice6 = c1; }
	nlbStmt(forStmt *c1):choice1(7) { child1.choice7 = c1; }
	nlbStmt(caseStmt *c1):choice1(8) { child1.choice8 = c1; }
	nlbStmt(gotoStmt *c1):choice1(9) { child1.choice9 = c1; }
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct assignStmt {
	identifier *child1;
	int choice2;
	union {
		expression *choice1;
		struct {
			expression *child1;
			expression *child2;
		} choice2;
		struct {
			identifier *child1;
			expression *child2;
		} choice3;
	} child2;
	assignStmt(identifier *c1, expression *c2):child1(c1),choice2(1) { child2.choice1 = c2; }
	assignStmt(identifier *c1, expression *c21, expression *c22):child1(c1),choice2(2) {
		child2.choice2.child1 = c21;
		child2.choice2.child2 = c22;
	}
	assignStmt(identifier *c1, identifier *c21, expression *c22):child1(c1),choice2(3) {
		child2.choice3.child1 = c21;
		child2.choice3.child2 = c22;
	}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct procStmt {
	int lineno;
	int choice1;
	union {
		identifier *choice1;
		struct {
			identifier *child1;
			argsList *child2;
		} choice2;
		sysProc *choice3;
		struct {
			sysProc *child1;
			expList *child2;
		} choice4;
		factor *choice5;
	} child1;
	procStmt(identifier *c1, int l):choice1(1), lineno(l) { child1.choice1 = c1; }
	procStmt(identifier *c11,argsList *c12, int l):choice1(2), lineno(l) {
		child1.choice2.child1 = c11;
		child1.choice2.child2 = c12;
	}
	procStmt(sysProc *c1, int l):choice1(3), lineno(l) { child1.choice3 = c1; }
	procStmt(sysProc *c11,expList *c12, int l):choice1(4), lineno(l) {
		child1.choice4.child1 = c11;
		child1.choice4.child2 = c12;
	}
	procStmt(factor *c1, int l):choice1(5), lineno(l) { child1.choice5 = c1; }
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct ifStmt {
	expression *child1;
	stmt *child2;
	elsePart *child3;
	ifStmt(expression *c1,stmt *c2,elsePart *c3)
		:child1(c1),child2(c2),child3(c3) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct elsePart {
	int choice1;
	stmt *child1;
	elsePart():choice1(0) {}
	elsePart(stmt *c1):choice1(1),child1(c1) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct repeatStmt {
	stmtList *child1;
	expression *child2;
	repeatStmt(stmtList *c1,expression *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct whileStmt {
	expression *child1;
	stmt *child2;
	whileStmt(expression *c1, stmt *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct forStmt {
	identifier *child1;
	expression *child2;
	int child3;
	expression *child4;
	stmt *child5;
	forStmt(identifier *c1,expression *c2,int c3,expression *c4,stmt *c5)
		:child1(c1),child2(c2),child3(c3),child4(c4),child5(c5) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct caseStmt {
	expression *child1;
	caseExp_list *child2;
	caseStmt(expression *c1,caseExp_list *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct caseExp {
	int choice1;
	union {
		consVal *choice1;
		identifier *choice2;
	} child1;
	stmt *child2;
	caseExp *next;
	caseExp(consVal *c1,stmt *c2,caseExp *n)
		:choice1(1),child2(c2),next(n) { child1.choice1 = c1; }
	caseExp(identifier *c1,stmt *c2,caseExp *n)
		:choice1(2),child2(c2),next(n) { child1.choice2 = c1; }
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct gotoStmt {
	int child1;
	gotoStmt(int c1):child1(c1) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct expression {
	int lineno;
	expression *child1;
	Operator child2;
	expr *child3;
	expression *next;
	Type type;
	u value;
	expression(expression *c1, int c2, expr *c3, expression *n, int l)
		:child1(c1),child3(c3),next(n), lineno(l) {
		switch(c2) {
		case 1: child2 = geG; break;
		case 2: child2 = gtG; break;
		case 3: child2 = leL; break;
		case 4: child2 = ltL; break;
		case 5: child2 = equalE; break;
		case 6: child2 = notEqualN; break;
		default: break;
		}
	}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct expr {
	expr *child1;
	Operator child2;
	term *child3;
	Type type;
	int lineno;
	u value;
	expr(expr *c1, int c2, term *c3, int l):child1(c1),child3(c3), lineno(l) {
		switch(c2) {
		case 1: child2 = plusP	; break;
		case 2: child2 = minusM; break;
		case 3: child2 = orO; break;
		default: break;
		}
	}
	bool sematicAnalysis(int scope);

	std::string assembleGenerator();
};

struct term {
	term *child1;
	Operator child2;
	factor *child3;
	Type type;
	int lineno;
	u value;
	term(term *c1,int c2,factor *c3, int l):child1(c1),child3(c3), lineno(l) {
		switch(c2) {
		case 1: child2 = mulM; break;
		case 2: child2 = divD; break;
		case 3: child2 = modM; break;
		case 4: child2 = andA; break;
		default: break;
		}
	}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};
}

#endif
