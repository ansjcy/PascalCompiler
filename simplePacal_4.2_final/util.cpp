/*
Created by Jack, 2016 05/26 for complier cosntruction!
Last modified: 2016 06/12 by Anakin DogeG
*/
#include "pascal.h"
#include "symbolTable.h"
#include "util.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace myPascal {
	bool tEqual(const Type &t1, const simpleType &s1, const Type &t2, const simpleType &s2) {
		return t1==t2 && s1==s2;
	}
	bool typeEql(identifier *id, expression *exp) {
		return tEqual((id->type==functionF||id->type==arrayT)?odinaryT:id->type, id->stype, odinaryT, exp->value.stype);
	}

	bool typeEql(identifier *id1, identifier *id2) {
		return tEqual(id2->type==functionF?odinaryT:id2->type, id1->stype,
					id2->type==functionF?odinaryT:id2->type, id2->stype);
	}

	bool typeEql(expression *exp1, expression *exp2) {
		return tEqual(odinaryT, exp1->value.stype, odinaryT, exp2->value.stype);
	}
	bool parametersMatch(identifier *id, argsList *args, int lineno) {
		//Caution! ! ! written by Huang Zhao-yang,
		//if you have any question, please contact me!!!
		return true;
	}

void lower(char str[]) {
	char * p= str;
	while(*p!='\0') {
		*p = *p <= 'Z' && *p >= 'A'? *p-'A'+'a' : *p;
		p++;
	}
}

program *parse() {
	yyparse();
	return savedRoot;
}


/*
Below is the code by DogeG Huang. (Huang Zhao-yang)

*/




void findTNotMatch(int lineno, expression *exp, simpleType stype) {
	string t;
	switch(stype) {
	case integerI: t = "integer"; break;
	case realR: t = "real"; break;
	case charC: t = "char"; break;
	case stringS: t = "string"; break;
	default: break;
	}
	fprintf(stderr, "error at LINE:: %d , type mismatch, it should be %s, but found %s!!!\n",
		lineno, t.c_str(), tStringT(exp).c_str());
}


void findTNotMatch(int lineno, identifier *id, expression *exp) {
	assert(!typeEql(id, exp));
	fprintf(stderr, "error at LINE:: %d , between %s and %s -> type  mismatch!!!.\n",
		lineno, tStringT(id).c_str(), tStringT(exp).c_str());
}

void findTNotMatch(int lineno, identifier *id, Type type) {
	string t;
	switch(type) {
	case procedureP: t = "procedure"; break;
	case programP: t = "program"; break;
	case functionF: t = "function"; break;
	case canCall: t = "callable"; break;
	case odinaryT: t = "simple_type"; break;
	case arrayT: t = "array_type"; break;
	default: break;
	}
	fprintf(stderr, "error at LINE:: %d , type mismatch, it should be %s, but found %s!!!\n",
		lineno, t.c_str(), tStringT(id).c_str());

}

void findNameConflict(myPascal::identifier *id, int scope) {
	myPascal::identifier *temp = gtable.lookUp(id, scope);
	printf("Find name conflict!!!, id = %s, scope = %d; prev_id = %s, prev_scope = %d!!!\n", id->name.c_str(), id->scope, temp->name.c_str(), temp->scope);
	assert(temp->scope==id->scope&&temp->name==id->name);
	fprintf(stderr, "error at LINE:: %d , %s was already defined at LINE:: %d.!!!\n",
		 id->lineno, temp->name.c_str(), temp->lineno);
}

void findTNotMatch(int lineno, expression *exp1, expr *exp2) {
	assert(!typeEql(exp1, exp2));
	fprintf(stderr, "error at LINE:: %d , type mismatch, it should be %s, but found %s!!!\n",
		lineno, tStringT(exp1).c_str(), tStringT(exp2).c_str());

}

//finsihed at 05/26 2016
void findTNotMatch(myPascal::identifier *id, int scope) {
	if(id->type==odinaryT&&id->stype==idrefI) {
		assert(id->value.idref->typeDefn==false);
		fprintf(stderr, "error at LINE:: %d ,  %s should be a type!!!.\n",
			id->lineno, id->value.idref->name.c_str());
	}
}

std::string tStringT(identifier *id) {
	return tString(id->type, id->stype);
}

std::string tStringT(expression *exp) {
	return tString(odinaryT, exp->value.stype);
}

std::string tStringT(expr *exp) {
	return tString(odinaryT, exp->value.stype);
}

std::string tString(Type type, simpleType stype) {
	switch(type) {
	case odinaryT:
	case functionF:
	case arrayT:switch(stype) {case integerI: return string("integer");case realR: return string("real");
		case charC: return string("char");case stringS: return string("string");}
	case recordT:
	default: return string("tString() error");
	}
}


bool typeEql(expression *exp1, expr *exp2) {
	return tEqual(exp1->type, exp1->value.stype, exp2->type, exp2->value.stype);
}

void findNameLost(myPascal::identifier *id, int scope) {
	assert(gtable.lookUp(id, scope)==NULL);
	fprintf(stderr, "error at LINE:: %d , %s is not defined!!!.\n",
		id->lineno, id->name.c_str());
}



}
