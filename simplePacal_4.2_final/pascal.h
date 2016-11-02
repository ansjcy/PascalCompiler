#ifndef _myPascal_PASCAL_H_
#define _myPascal_PASCAL_H_

#include <string>
#include <cstdio>
#include <vector>
#include <cstring>

#include "PascaltyPe.h"
#include "PascalCommon.h"
#include "PascalStmt.h"
#include "PasType.h"
#include "PasCom.h"
#include "PasDec.h"
#include "PasCtrl.h"
#include "symbolTable.h"

using namespace myPascal;
extern int lineno;
extern char *yytext;
int yylex();
int yyerror(const std::string &);
int yyparse();
void mips_head();
void mips_body(program *root);

#endif
