#ifndef _PASTYPE_H_
#define _PASTYPE_H_

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>

#include "PascaltyPe.h"
#include "PascalCommon.h"
#include "PascalStmt.h"

extern int lineno;
extern char *yytext;

namespace myPascal {
void lower(char str[]);
void findNameConflict(myPascal::identifier *id, int scope);
void findNameLost(myPascal::identifier *id, int scope);
void findTNotMatch(myPascal::identifier *id, int scope);
void findTNotMatch(int lineno, identifier *id, expression *exp);
void findTNotMatch(int lineno, expression *exp1, expr *exp2);
void findTNotMatch(int lineno, expression *exp, simpleType stype);
void findTNotMatch(int lineno, myPascal::identifier *id, Type type);
std::string tStringT(myPascal::identifier *id);
std::string tStringT(expression *exp);
std::string tStringT(expr *exp);
std::string tString(Type type, simpleType stype);
bool typeEql(myPascal::identifier *id, expression *exp);
bool typeEql(myPascal::identifier *id1, myPascal::identifier *id2);
bool typeEql(expression *exp1, expression *exp2);
bool typeEql(expression *exp1, expr *exp2);
bool tEqual(const Type &t1, const simpleType &s1, const Type &t2, const simpleType &s2);
bool parametersMatch(identifier *id, argsList *args);
}
#endif
