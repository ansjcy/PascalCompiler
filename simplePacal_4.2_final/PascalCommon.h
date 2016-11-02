#ifndef _PASCALCOMMON__H_
#define _PASCALCOMMON__H_
#include "PascalStmt.h"
namespace myPascal {

struct consExp;
typedef consExp consExp_list;
struct consVal;
struct typeDef;
typedef typeDef typeDecl_list;
struct typeDecl;
struct simple_typeDecl;
struct array_typeDecl;
struct record_typeDecl;
struct sysType;
struct range;
struct idrange;
struct procHead;
struct subRout;
struct parameters;
struct paraTypeList;
typedef paraTypeList paraDeclList;
struct nameList;
typedef nameList varPList;
typedef nameList val_para_list;
struct elsePart;
struct caseExp;
typedef caseExp caseExp_list;

struct expr;
struct term;
struct factor;
struct sysFunc;
struct sysCon;

void stprint(simpleType s);

enum SysCon {

};

enum SysProc {
	writeW,
	writelnW
};

enum SysFunct {

};

enum Operator {
	geG,
	gtG,
	leL,
	ltL,
	equalE,
	notEqualN,
	plusP	,
	minusM,
	orO,
	mulM,
	divD,
	modM,
	andA
};

union u {
	simpleType stype;
	identifier *idref;
	array_typeDecl *array;
	record_typeDecl *record;
};

extern myPascal::program *savedRoot;
extern bool error;
myPascal::program *parse();

};

#endif
