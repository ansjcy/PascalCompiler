#include "pascal.h"
#include "symbolTable.h"

#include <cstdio>
#include <iostream>

using namespace myPascal;
using namespace std;

int main(int argc, char *argv[]) {
	if(yyparse()) {
		fprintf(stderr, "\n");
		return 1;
	}

	program *root = savedRoot;
	if(!(root->sematicAnalysis(gtable.insertScope())
		&&gtable.checkLabel()))
	{
		fprintf(stderr, "there are errors in the sematic.\n");
		return 1;
	}

	mips_head();
	mips_body(root);

	return 0;
}
