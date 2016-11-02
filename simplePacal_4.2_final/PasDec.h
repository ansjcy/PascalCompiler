#ifndef _PASDEC_H_
#define _PASDEC_H_

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>

#include "PascaltyPe.h"
#include "PascalCommon.h"
#include "PascalStmt.h"

namespace myPascal {

struct factor {
	int choice1;
	union {
		identifier *choice1;
		struct {
			identifier *child1;
			argsList *child2;
		} choice2;
		sysFunc *choice3;
		struct {
			sysFunc *child1;
			argsList *child2;
		} choice4;
		consVal *choice5;
		expression *choice6;
		factor *choice7;
		factor *choice8;
		struct {
			identifier *child1;
			expression *child2;
		} choice9;
		struct {
			identifier *child1;
			identifier *child2;
		} choice10;
	} child1;
	Type type;
	u value;
	factor(identifier *c1):choice1(1) { child1.choice1 = c1; }
	factor(identifier *c11,argsList *c12):choice1(2) {
		child1.choice2.child1 = c11;
		child1.choice2.child2 = c12;
	}
	factor(sysFunc *c1):choice1(3) { child1.choice3 = c1; }
	factor(sysFunc *c11,argsList *c12):choice1(4) {
		child1.choice4.child1 = c11;
		child1.choice4.child2 = c12;
	}
	factor(consVal *c1):choice1(5) { child1.choice5 = c1; }
	factor(expression *c1):choice1(6) { child1.choice6 = c1; }
	factor(factor *c1):choice1(7) { child1.choice7 = c1; }
	factor(factor *c1, factor *dummy):choice1(8) { child1.choice8 = c1; }
	factor(identifier *c11,expression *c12, expression *dummy):choice1(9) {
		child1.choice9.child1 = c11;
		child1.choice9.child2 = c12;
	}
	factor(identifier *c11,identifier *c12):choice1(10) {
		child1.choice10.child1 = c11;
		child1.choice10.child2 = c12;
	}
	bool sematicAnalysis(int scope);
	std::string assembleGenerator();
};

struct sysProc {
	SysProc child1;
	sysProc(SysProc s):child1(s) {}
	std::string assembleGenerator(simpleType t);
};

struct sysFunc {
	SysFunct child1;
	std::string assembleGenerator();
};

}
#endif
