#ifndef _PASCOM_H_
#define _PASCOM_H_

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>

#include "PascaltyPe.h"
#include "PascalCommon.h"
#include "PascalStmt.h"

namespace myPascal {
struct identifier {
	std::string name;
	int lineno;
	Type type;
	simpleType stype;
	std::vector<std::string> *params;
	union {
		int i;
		float f;
		char c;
		std::string *s;
		SysCon syscon;
		identifier *idref;
		nameList *e;
		range *r;
		idrange *idr;
		array_typeDecl *array;
		record_typeDecl *record;
		program *prog;
		procDecl *proc;
		funcDecl *func;
	} value;
	int offset;
	int scope;
	bool constant;
	bool typeDefn;
	bool passByReference;
	identifier(const char n[], int l):name(n),lineno(l) {}
	identifier(const std::string &n, int l):name(n),lineno(l) {}

};

struct program {
	progHead *child1;
	routine *child2;
	program(progHead *c1, routine *c2):child1(c1),child2(c2) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct progHead {
	identifier *child1;
	progHead(identifier *c1):child1(c1) {}
	bool sematicAnalysis(program *root, int scope);
	std::string assembleGenerator();
};

struct routine {
	routHead *child1;
	routBody *child2;
	routine(routHead *c1, routBody *c2):child1(c1),child2(c2) { }
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct subRout {
	routHead *child1;
	routBody *child2;
	subRout(routHead *c1, routBody *c2):child1(c1),child2(c2) { }
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct routHead {
	lbP *child1;
	consP *child2;
	typeP *child3;
	varP *child4;
	routP *child5;
	routHead(lbP *c1, consP *c2, typeP *c3, varP *c4, routP *c5):child1(c1),child2(c2),child3(c3),child4(c4),child5(c5) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct lbP {
	bool sematicAnalysis(int scope) { return true; }
	std::string assembleGenerator();
};

struct consP {
	consExp_list *child1;
	consP(consExp_list *c1):child1(c1) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct consExp {
	identifier *child1;
	consVal *child2;
	consExp *next;
	consExp(identifier *c1, consVal *c2, consExp *n):child1(c1),child2(c2),next(n) {}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct consVal {
	int choice1;
	union {
		int choice1;
		float choice2;
		char choice3;
		std::string *choice4;
		sysCon *choice5;
	} child1;
	consVal(int c, const char *buff):choice1(c) {
		switch(choice1) {
		case 1: sscanf(buff, "%d", &(child1.choice1)); break;
		case 2: sscanf(buff, "%f", &(child1.choice2)); break;
		case 3: sscanf(buff+1, "%c", &(child1.choice3)); break;
		case 4: child1.choice4 = new std::string(buff+1, strlen(buff)-2); break;
		default : break;
		}
	}
	consVal(sysCon *c1):choice1(5) { child1.choice5 = c1; }
	void negate() { choice1==1?child1.choice1 = -child1.choice1:
					choice1==2?child1.choice2 = -child1.choice2:
					child1.choice3 = -child1.choice3; }
	bool sematicAnalysis(identifier *id, int scope);
	std::string assembleGenerator();
};

struct sysCon {
	int choice1;
	SysCon child1;
	std::string assembleGenerator();
};
}

#endif
