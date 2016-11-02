#ifndef _myPascal_SYMBOLTABLE_H_
#define _myPascal_SYMBOLTABLE_H_
#include "pascal.h"
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <iostream>
namespace myPascal {
	struct scopeValue{
		int parent;
		int choice;
		union {
			myPascal::program *type1;
			myPascal::funcDecl *type2;
			myPascal::procDecl *type3;
		} type;
		scopeValue(int p, myPascal::program *t):parent(p),choice(1) { type.type1 = t; }
		scopeValue(int p, myPascal::funcDecl *t):parent(p),choice(2) { type.type2 = t; }
		scopeValue(int p, myPascal::procDecl *t):parent(p),choice(3) { type.type3 = t; }
		scopeValue(int p):parent(p),choice(0) { }
		scopeValue(int p, const std::string &s): parent(p), choice(0) { }
};

class symbolTable {
private :
	std::vector<scopeValue> scope;
	std::map<std::string,std::vector<myPascal::identifier *> > table;
	std::set<int> label;
	std::set<int> usedlabel;
	std::set<identifier *> const_pool;
public :
	void printScope();
	void printIdentifier();
	void printConst();
	void addConst(myPascal::identifier *id) { const_pool.insert(id); }
	std::set<myPascal::identifier *> &getConstPoll() { return const_pool; }
	int insertScope() {scope.push_back(scopeValue(-1, "global"));return scope.size()-1;}
	int insertScope(myPascal::program *id, int parent_scope) {
		if(lookUpScope(id)!=-1) {return -1;}
		scope.push_back(scopeValue(parent_scope, id));
		return scope.size()-1;
	}
	int insertScope(myPascal::funcDecl *id, int parent_scope) {
		if(lookUpScope(id)!=-1) {return -1;}
		scope.push_back(scopeValue(parent_scope, id));
		return scope.size()-1;
	}
	int insertScope(myPascal::procDecl *id, int parent_scope) {
		if(lookUpScope(id)!=-1) {return -1;}
		scope.push_back(scopeValue(parent_scope, id));
		return scope.size()-1;
	}
	int lookUpScope(myPascal::program *id);
	int lookUpScope(myPascal::funcDecl *id);
	int lookUpScope(myPascal::procDecl *id);
	scopeValue getScope(int s) const {assert(s<scope.size());return scope.at(s);}
	bool insertID(myPascal::identifier *id, int scope);
	myPascal::identifier *lookUp(const myPascal::identifier * const id, int s, int &is) const ;
	myPascal::identifier *lookUp(const std::string &id, int s, int &is) const;
	myPascal::identifier *lookUp(const myPascal::identifier * const id, int s) const {return lookUp(id, s, s);}
	myPascal::identifier *lookUp(const std::string &id, int s) const
	{
		int temp;
		return lookUp(id, s, temp);
	}
	bool addLabel(int l)
	{
		label.insert(l);
		return true;
	}
	bool addUsedLabel(int l)
	{
		usedlabel.insert(l);
		return true;
	}
	bool checkLabel();
};
extern symbolTable gtable;
}





#endif
