#include "pascal.h"
#include "symbolTable.h"

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;
using namespace myPascal;


symbolTable myPascal::gtable;
myPascal::program *myPascal::savedRoot;
bool myPascal::error = false;
static int currentScope = 0;
static int sbCounter = 0;
string program::assembleGenerator() {
string res;
int originalScope = currentScope;

res += child1->assembleGenerator();

currentScope = gtable.lookUpScope(this);
res += child2->assembleGenerator();

currentScope = originalScope;

return res;
}

string progHead::assembleGenerator() {
string res;
char temp[30];

sprintf(temp, "%d", currentScope);
string label = child1->name + string(temp);

res += label + ":\n";
res += "sw $ra, 0($fp)\n";

return res;
}

string routine::assembleGenerator() {
string res;

res += child2->assembleGenerator();
res += "addi $sp, $sp, 100\n";
res += "addi $v0, $zero, 17\n";

res += "syscall\n";
res += child1->assembleGenerator();

return res;
}

string routHead::assembleGenerator() {
string res;

res += child1->assembleGenerator();
res += child2->assembleGenerator();
res += child3->assembleGenerator();
res += child4->assembleGenerator();
res += child5->assembleGenerator();

return res;
}

string lbP::assembleGenerator() {
string res;

res += "";

return res;
}

string consP::assembleGenerator() {
string res;

res += "";

return res;
}

string consExp::assembleGenerator() {
string res;

res += "";

return res;
}

string consVal::assembleGenerator() {
string res;

res += "";

return res;
}

string sysCon::assembleGenerator() {
string res;

res += "";

return res;
}

string typeP::assembleGenerator() {
string res;

res += "";

return res;
}

string typeDef::assembleGenerator() {
string res;

res += "";

return res;
}

string typeDecl::assembleGenerator() {
string res;

res += "";

return res;
}

string simple_typeDecl::assembleGenerator() {
string res;

res += "";

return res;
}

string sysType::assembleGenerator() {
string res;

res += "";

return res;
}

string range::assembleGenerator() {
string res;

res += "";

return res;
}

string idrange::assembleGenerator() {
string res;

res += "";

return res;
}

string array_typeDecl::assembleGenerator() {
string res;

res += "";

return res;
}

string record_typeDecl::assembleGenerator() {
string res;

res += "";

return res;
}

string fieldlDecl::assembleGenerator() {
string res;

res += "";

return res;
}

string nameList::assembleGenerator() {
string res;

res += "";

return res;
}

string varP::assembleGenerator() {
string res;

res += "";

return res;
}

string varDecl::assembleGenerator() {
string res;

res += "";

return res;
}

string routP::assembleGenerator() {
string res;

funcDeclList * fptr = child1;
while (fptr != NULL) {
	res += fptr->assembleGenerator();
	fptr = fptr->next;
}

procDecl_list * pptr = child2;
while (pptr != NULL) {
	res += pptr->assembleGenerator();
	pptr = pptr->next;
}

return res;
}

string funcDecl::assembleGenerator() {
string res;
int originalScope = currentScope;


res += child1->assembleGenerator();

currentScope = gtable.lookUpScope(this);

res += child2->assembleGenerator();

currentScope = originalScope;

return res;
}

string funcHead::assembleGenerator() {
string res;
char temp[30];

sprintf(temp, "%d", currentScope);
string label = child1->name + string(temp);

res += label + ":\n";
res += "sw $ra, 0($fp)\n";

return res;
}

string procDecl::assembleGenerator() {
string res;

int originalScope = currentScope;


res += child1->assembleGenerator();

currentScope = gtable.lookUpScope(this);

res += child2->assembleGenerator();

currentScope = originalScope;

return res;
}

string procHead::assembleGenerator() {
string res;
char temp[30];

sprintf(temp, "%d", currentScope);
string label = child1->name + string(temp);

res += label + ":\n";
res += "sw $ra, 0($fp)\n";

return res;
}

string parameters::assembleGenerator() {
string res;

res += "";

return res;
}

string paraTypeList::assembleGenerator() {
string res;

res += "";

return res;
}

string subRout::assembleGenerator() {
string res;

res += child2->assembleGenerator();
res += "lw $ra, 0($fp)\n";
res += "jr $ra\n";
res += child1->assembleGenerator();

return res;
}

string routBody::assembleGenerator() {
string res;

res += child1->assembleGenerator();

return res;
}

string sysProc::assembleGenerator(simpleType choice1) {
string res;



switch (choice1) {
	case  integerI: {
		res += "add $t0, $zero, $v0\n";
		res += "print_int($t0)\n";
		break;}
	case  realR: {
		res += "add.s $f12, $f31, $f0\n";
		res += "li $v0, 2\n";
		res += "syscall\n";
		break;}
	case  charC: {
		res += "add $t0, $zero, $v0\n";
		res += "print_char($t0)\n";
		break;}
	default:{
		break;}
}

return res;
}

string sysFunc::assembleGenerator() {
string res;

res += "";

return res;
}

string compStmt::assembleGenerator() {
string res;

stmtList * ptr = child1;
while (ptr != NULL) {
	res += ptr->assembleGenerator();
	ptr = ptr->next;
}

return res;
}

string stmt::assembleGenerator() {
string res;
char temp[30];

if (choice1) {
	sprintf(temp, "%d", child1);
	res += "Label_" + string(temp) + ":\n";
}
res += child2->assembleGenerator();

return res;
}

string nlbStmt::assembleGenerator() {
string res;

switch (choice1) {
	case  1: { res += child1.choice1->assembleGenerator(); break;}
	case  2: { res += child1.choice2->assembleGenerator(); break;}
	case  3: { res += child1.choice3->assembleGenerator(); break;}
	case  4: { res += child1.choice4->assembleGenerator(); break;}
	case  5: { res += child1.choice5->assembleGenerator(); break;}
	case  6: { res += child1.choice6->assembleGenerator(); break;}
	case  7: { res += child1.choice7->assembleGenerator(); break;}
	case  8: { res += child1.choice8->assembleGenerator(); break;}
	case  9: { res += child1.choice9->assembleGenerator(); break;}
	default: {break;}
}

return res;
}

string assignStmt::assembleGenerator() {
string res;
char temp[30];

switch (choice2) {
	case  1: {
		res += child2.choice1->assembleGenerator();
		identifier *newChild1 = gtable.lookUp(child1, currentScope);
		if (newChild1->type == functionF) {
		}
		else {
			int scopePtr = currentScope;
			res += "add $t0, $zero, $fp\n";
			while (scopePtr != newChild1->scope) {
				res += "lw $t0, 4($t0)\n";
				scopePtr = (gtable.getScope(scopePtr)).parent;
			}
			sprintf(temp, "%d", newChild1->offset);
			res += "addi $t0, $t0, " + string(temp) + "\n";
			if(newChild1->stype == realR){
				res += "swc1 $f0, 0($t0)\n";
			}
			else{
				res += "sw $v0, 0($t0)\n";
			}
		}

		break;}
	case  2: {
		res += child2.choice2.child2->assembleGenerator();
		res += "addi $sp, $sp, -4\n";
		res += "sw   $v0, 0($sp)\n";

		res += child2.choice2.child1->assembleGenerator();

		identifier *newChild1 = gtable.lookUp(child1, currentScope);
		int scopePtr = currentScope;
		res += "add $t0, $zero, $fp\n";
		while (scopePtr != newChild1->scope) {
			res += "lw $t0, 4($t0)\n";
			scopePtr = (gtable.getScope(scopePtr)).parent;
		}
		sprintf(temp, "%d", newChild1->offset);
		res += "addi $t0, $t0, " + string(temp) + "\n";
		res += "lw   $t0, 0($t0)\n";

		res += "sll $v0, $v0, 2\n";
		res += "add $t0, $t0, $v0\n";

		res += "lw   $v0, 0($sp)\n";
		res += "addi $sp, $sp, 4\n";
		res += "sw   $v0, 0($t0)\n";

		break;}
	case  3: {
		res += child2.choice3.child2->assembleGenerator();
		break;}
	default: {break;}
}



return res;
}

string procStmt::assembleGenerator() {
string res;
char temp[30];

switch (choice1) {
	case  1: {

		identifier * newiden = gtable.lookUp(child1.choice1, currentScope);
		assert(newiden->type == functionF || newiden->type == procedureP);
		int totalSize = newiden->offset;
		int argsCounter = 0;
		int varSize = totalSize - 8 - argsCounter * 4;
		int childscope = -1;
		switch (newiden->type) {
			case functionF:
				childscope = gtable.lookUpScope(newiden->value.func);
				break;
			case procedureP:
				childscope = gtable.lookUpScope(newiden->value.proc);
				break;
			default: break;
		}
		assert(childscope != -1);

		int scopePtr = currentScope;
		res += "add $t0, $zero, $fp\n";
		while (scopePtr != newiden->scope) {
			res += "lw $t0, 4($t0)\n";
			scopePtr = gtable.getScope(scopePtr).parent;
		}
		sprintf(temp, "%d", -1 * varSize - 4);
		res += "sw $t0, " + string(temp) + "($sp)\n";

		sprintf(temp, "%d", -1 * totalSize);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		res += "add $t7, $zero, $fp\n";
		res += "add $fp, $zero, $sp\n";

		sprintf(temp, "%d", -4);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		res += "sw $t7, 0($sp)\n";

		assert(newiden->type == procedureP);
		assert(newiden->value.proc->child2->child1->child4 != NULL);
		varDeclList * vars = newiden->value.proc->child2->child1->child4->child1;

		int pscope = gtable.lookUpScope(newiden->value.proc);
		while (vars != NULL) {
			if (vars->child2->choice1 == 2) {
				assert(vars->child2->child1.choice2->child1->choice1 == 4);
				int arraySize = vars->child2->child1.choice2->child1->child1.choice4->size;

				nameList * varName = vars->child1;
				while (varName != NULL) {
					identifier * newvariden = gtable.lookUp(varName->child2, pscope);
					assert(newvariden->type == arrayT);
					sprintf(temp, "%d", -1 * arraySize * 4);
					res += "addi $sp, $sp, " + string(temp) + "\n";
					res += "sw $sp, " + to_string(newvariden->offset) + "($fp)\n";

					varName = varName->child1;
				}
			}
			else {}

			vars = vars->next;
		}

		int funcScope = gtable.lookUp(child1.choice1, currentScope)->scope;
		sprintf(temp, "%d", funcScope);

		res += "jal " + child1.choice1->name + string(temp) + "\n";

		res += "lw $fp, -4($fp)\n";
		sprintf(temp, "%d", 4);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		sprintf(temp, "%d", totalSize);
		res += "addi $sp, $sp, " + string(temp) + "\n";

		break;}
	case  2: {
		identifier * newiden = gtable.lookUp(child1.choice1, currentScope);

		assert(newiden->type == procedureP);
		int totalSize = newiden->offset;
		int argsCounter = 0;
		assert(newiden->params!=NULL);
		argsCounter = newiden->params->size();
		int varSize = totalSize - 8 - argsCounter * 4;
		int childscope = -1;
		switch (newiden->type) {
			case functionF:
				childscope = gtable.lookUpScope(newiden->value.func);
				break;
			case procedureP:
				childscope = gtable.lookUpScope(newiden->value.proc);
				break;
			default: break;
		}

		assert(childscope != -1);

		argsList * ptr = child1.choice2.child2;
		string ref_restore = "";
		for (int i = 0; i < argsCounter; i++) {
			res += ptr->assembleGenerator();
			sprintf(temp, "%d", -1 * totalSize + 8 + i * 4);
			res += "sw $v0, " + string(temp) + "($sp)\n";

			identifier * newArgId = gtable.lookUp(newiden->params->at(i), childscope);
			assert(newArgId != NULL);

			if (newArgId->passByReference) {

				ref_restore += "lw $t1, " + string(temp) + "($sp)\n";

				int scopePtr = currentScope;
				ref_restore += "add $t0, $zero, $fp\n";
				assert(ptr->child3->child3->child3->choice1 == 1);
				identifier *sbid = gtable.lookUp(ptr->child3->child3->child3->child1.choice1, currentScope);
				assert(sbid != NULL);

				while (scopePtr != sbid->scope) {
					ref_restore += "lw $t0, 4($t0)\n";
					scopePtr = gtable.getScope(scopePtr).parent;
				}
				sprintf(temp, "%d", sbid->offset);

				ref_restore += "sw $t1, " + string(temp) + "($t0)\n";
			}

			ptr = ptr->next;
		}

		int scopePtr = currentScope;
		res += "add $t0, $zero, $fp\n";
		while (scopePtr != newiden->scope) {
			res += "lw $t0, 4($t0)\n";
			scopePtr = gtable.getScope(scopePtr).parent;
		}
		sprintf(temp, "%d", -1 * totalSize + 4);
		res += "sw $t0, " + string(temp) + "($sp)\n";


		sprintf(temp, "%d", -1 * totalSize);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		res += "add $t7, $zero, $fp\n";
		res += "add $fp, $zero, $sp\n";

		sprintf(temp, "%d", -4);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		res += "sw $t7, 0($sp)\n";

		assert(newiden->type == procedureP);
		assert(newiden->value.proc->child2->child1->child4 != NULL);
		varDeclList * vars = newiden->value.proc->child2->child1->child4->child1;

		int pscope = gtable.lookUpScope(newiden->value.proc);
		while (vars != NULL) {
			if (vars->child2->choice1 == 2) {
				assert(vars->child2->child1.choice2->child1->choice1 == 4);
				int arraySize = vars->child2->child1.choice2->child1->child1.choice4->size;

				nameList * varName = vars->child1;
				while (varName != NULL) {
					identifier * newvariden = gtable.lookUp(varName->child2, pscope);
					assert(newvariden->type == arrayT);
					sprintf(temp, "%d", -1 * arraySize * 4);
					res += "addi $sp, $sp, " + string(temp) + "\n";
					res += "sw $sp, " + to_string(newvariden->offset) + "($fp)\n";

					varName = varName->child1;
				}
			}
			else {}

			vars = vars->next;
		}

		int funcScope = gtable.lookUp(child1.choice2.child1, currentScope)->scope;
		sprintf(temp, "%d", funcScope);

		res += "jal " + child1.choice2.child1->name + string(temp) + "\n";

		res += "lw $fp, -4($fp)\n";
		sprintf(temp, "%d", 4);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		sprintf(temp, "%d", totalSize);
		res += "addi $sp, $sp, " + string(temp) + "\n";


		res += ref_restore;

		break;}
	case  3: {
		break;}
	case  4: {
		if (child1.choice4.child2->child3->child3->child3->choice1 == 5 &&
			child1.choice4.child2->child3->child3->child3->child1.choice5->choice1 == 4) {
			assert(child1.choice4.child2->child3->child3->child3->child1.choice5->child1.choice4 != NULL);
			res += "print_str(\"" + *(child1.choice4.child2->child3->child3->child3->child1.choice5->child1.choice4) + "\")\n";
		}
		else {
			res += child1.choice4.child2->assembleGenerator();
			res += child1.choice4.child1->assembleGenerator(child1.choice4.child2->value.stype);
		}

		switch (child1.choice4.child1->child1) {
			case writeW: break;
			case writelnW:
				res += "addi $t0, $zero, 10\n";
				res += "print_char($t0)\n";
				break;
		}
		break;}
	case  5: {
		simpleType tarSType;

		switch (child1.choice5->choice1) {
			case  1:{
				identifier * newiden = gtable.lookUp(child1.choice5->child1.choice1, currentScope);
				assert(newiden != NULL);
				assert(newiden->type == odinaryT);
				tarSType = newiden->stype;

				int scopePtr = currentScope;
				res += "add $t0, $zero, $fp\n";
				while (scopePtr != newiden->scope) {
					res += "lw $t0, 4($t0)\n";
					scopePtr = gtable.getScope(scopePtr).parent;
				}
				char temp[30];
				sprintf(temp, "%d", newiden->offset);
				res += "addi $t0, $t0, " + string(temp) + "\n";

				break;
				}
			case  9:{
				identifier *newiden = gtable.lookUp(child1.choice5->child1.choice9.child1, currentScope);
				assert(newiden != NULL);
				assert(newiden->type == arrayT);
				tarSType = newiden->stype;
				int scopePtr = currentScope;
				res += child1.choice5->child1.choice9.child2->assembleGenerator();
				res += "add $t0, $zero, $fp\n";
				while(scopePtr != newiden->scope) {
					res += "lw $t0, 4($t0)\n";
					scopePtr = gtable.getScope(scopePtr).parent;
				}
				char temp[30];
				sprintf(temp, "%d", newiden->offset);
				res += "addi $t0, $t0, " + string(temp) + "\n";
				res += "lw $t1, 0($t0)\n";
				res += "sll $v0, $v0, 2\n";
				res += "add $t0, $t1, $v0\n";

				break;
			}
			default: break;
		}

		switch (tarSType) {
			case integerI:
				res += "li $v0, 5\n";
				res += "syscall\n";

				res += "sw $v0, 0($t0)\n";
				break;
			case realR:
				res += "li $v0, 6\n";
				res += "syscall\n";

				res += "swc1 $f0, 0($t0)\n";
				break;
			case charC:
				break;
			default: break;
		}

		break;}
	default: {break;}
}

return res;
}

string expression::assembleGenerator() {
string res;

if (child1 != NULL) {
	res += child1->assembleGenerator();
	res += "addi $sp, $sp, -4\n";
	res += "sw $v0, 0($sp)\n";

	res += child3->assembleGenerator();

	res += "lw $v1, 0($sp)\n";
	switch (child2) {
		case geG: {		res += "sge $v0, $v1, $v0\n"; break;}
		case gtG: {		res += "sgt $v0, $v1, $v0\n"; break;}
		case leL: {		res += "sle $v0, $v1, $v0\n"; break;}
		case ltL: {		res += "slt $v0, $v1, $v0\n"; break;}
		case equalE: {	res += "seq $v0, $v1, $v0\n"; break;}
		case notEqualN: {	res += "sne $v0, $v1, $v0\n"; break;}
		default:  {break;}
	}

	res += "addi $sp, $sp, 4\n";
}
else {
	res += child3->assembleGenerator();
}

return res;
}

string repeatStmt::assembleGenerator() {
string res;

sbCounter++;
string repeatAddr =  string("until_") + to_string(sbCounter);
res += repeatAddr + ":\n";

stmtList * ptr = child1;
while (ptr != NULL) {
	res += ptr->assembleGenerator();
	ptr = ptr->next;
}

res += child2->assembleGenerator();
res += "beq $v0, $zero, " + repeatAddr + "\n";

return res;
}

string whileStmt::assembleGenerator(){
string res;

sbCounter++;
string whileAddr1 = "while_start_" + to_string(sbCounter);
string whileAddr2 = "while_end_" + to_string(sbCounter);

res += whileAddr1 + ":\n";
res += child1->assembleGenerator();
res += "beq $v0, $zero, " + whileAddr2 + "\n";

res += child2->assembleGenerator();
res += "j " + whileAddr1 + "\n";
res += whileAddr2 + ":\n";

return res;
}

string forStmt::assembleGenerator() {
string res;
char temp[30];

sbCounter++;
string forAddr1 = "for_start_" + to_string(sbCounter);
string forAddr2 = "for_end_" + to_string(sbCounter);

identifier *newChild1 = gtable.lookUp(child1, currentScope);

int scopePtr = currentScope;
res += "add $t0, $zero, $fp\n";
while (scopePtr != newChild1->scope) {
	res += "lw $t0, 4($t0)\n";
	scopePtr = gtable.getScope(scopePtr).parent;
}
sprintf(temp, "%d", newChild1->offset);
string offset(temp);
res += "addi $sp, $sp, -4\n";
res += "sw $t0, 0($sp)\n";

res += child4->assembleGenerator();
switch (child3) {
	case  1: { res += "addi $v0, $v0, 1\n";  break;}
	default: {break;}
}
res += "addi $sp, $sp, -4\n";
res += "sw $v0, 0($sp)\n";

res += child2->assembleGenerator();
res += "lw $t0, 4($sp)\n";
res += "sw $v0, " + offset + "($t0)\n";

res += forAddr1 + ":\n";
switch (child3) {
	case 1: {
		res += "lw   $v1, 0($sp)\n";
		res += "slt  $t0, $v0, $v1\n";
		res += "beq  $t0, $zero, " + forAddr2 + "\n";
		break;}
	case 2: {
		res += "lw   $v1, 0($sp)\n";
		res += "slt  $t0, $v0, $v1\n";
		res += "bne  $t0, $zero, " + forAddr2 + "\n";
		break;}
	default:
		{break;}
}

res += child5->assembleGenerator();
res += "lw   $t0, 4($sp)\n";
res += "lw   $v0, " + offset + "($t0)\n";
switch (child3) {
	case  1: {
		res += "addi $v0, $v0, 1\n";
		break;
	}
	case  2: {
		res += "addi $v0, $v0, -1\n";
		break;
	}
	default: {break;}
}
res += "sw   $v0, " + offset + "($t0)\n";

res += "j " + forAddr1 + "\n";
res += forAddr2 + ":\n";

res += "lw $t0, 4($sp)\n";
res += "lw $v0, " + offset + "($t0)\n";
switch (child3) {
	case  1: res += "addi $v0, $v0, -1\n"; break;
	case  2: res += "addi $v0, $v0, 1\n";  break;
	default: break;
}
res += "sw $v0, " + offset + "($t0)\n";

res += "addi $sp, $sp, 8\n";

return res;
}

string factor::assembleGenerator() {
string res;
char temp[30];

switch (choice1) {
	case  1: {
		identifier *newChild1 = gtable.lookUp(child1.choice1, currentScope);
		int scopePtr = currentScope;
		res += "add $t0, $zero, $fp\n";
		while (scopePtr != newChild1->scope) {
			res += "lw $t0, 4($t0)\n";
			scopePtr = gtable.getScope(scopePtr).parent;
		}


		if(newChild1->constant){
			if(value.stype == realR){
				res += ".data\n";
				sbCounter++;
				string lable = to_string(sbCounter);
				res += "data_" + lable + ":\n";

				res +=".float "+ to_string(newChild1->value.f) +"\n";
				res +=".text\n";
				res += "lwc1 $f0, data_"+lable + "\n";
			}
			else{
				res += "addi $v0, $zero, " + to_string(newChild1->value.i) +"\n";
			}
		}
		else{
			sprintf(temp, "%d", newChild1->offset);
			if(value.stype == realR){
				res += "lwc1 $f0, " + string(temp) + "($t0)\n";
			}
			else{
				res += "lw $v0, " + string(temp) + "($t0)\n";
			}
		}
		break;}
	case  2: {
		identifier * newiden = gtable.lookUp(child1.choice1, currentScope);

		assert(newiden->type == functionF);
		int totalSize = newiden->offset;
		int argsCounter = 0;
		assert(newiden->params!=NULL);
		argsCounter = newiden->params->size();
		int varSize = totalSize - 8 - argsCounter * 4;
		int childscope = -1;
		switch (newiden->type) {
			case functionF:
				childscope = gtable.lookUpScope(newiden->value.func);
				break;
			case procedureP:
				childscope = gtable.lookUpScope(newiden->value.proc);
				break;
			default: break;
		}
		assert(childscope != -1);

		argsList * ptr = child1.choice2.child2;
		string ref_restore = "";
		for (int i = 0; i < argsCounter; i++) {
			res += ptr->assembleGenerator();
			sprintf(temp, "%d", -1 * totalSize + 8 + i * 4);
			res += "sw $v0, " + string(temp) + "($sp)\n";

			identifier * newArgId = gtable.lookUp(newiden->params->at(i), childscope);
			assert(newArgId != NULL);
			if (newArgId->passByReference) {
				ref_restore += "lw $t1, " + string(temp) + "($sp)\n";

				int scopePtr = currentScope;
				ref_restore += "add $t0, $zero, $fp\n";
				assert(ptr->child3->child3->child3->choice1 == 1);
				identifier *sbid = gtable.lookUp(ptr->child3->child3->child3->child1.choice1, currentScope);
				assert(sbid != NULL);

				while (scopePtr != sbid->scope) {
					ref_restore += "lw $t0, 4($t0)\n";
					scopePtr = gtable.getScope(scopePtr).parent;
				}
				sprintf(temp, "%d", sbid->offset);

				ref_restore += "sw $t1, " + string(temp) + "($t0)\n";
			}

			ptr = ptr->next;
		}

		int scopePtr = currentScope;
		res += "add $t0, $zero, $fp\n";
		while (scopePtr != newiden->scope) {
			res += "lw $t0, 4($t0)\n";
			scopePtr = gtable.getScope(scopePtr).parent;
		}
		sprintf(temp, "%d", -1 * totalSize + 4);
		res += "sw $t0, " + string(temp) + "($sp)\n";

		sprintf(temp, "%d", -1 * totalSize);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		res += "add $t7, $zero, $fp\n";
		res += "add $fp, $zero, $sp\n";

		sprintf(temp, "%d", -4);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		res += "sw $t7, 0($sp)\n";

		assert(newiden->type == functionF);
		assert(newiden->value.func->child2->child1->child4 != NULL);
		varDeclList * vars = newiden->value.func->child2->child1->child4->child1;

		int pscope = gtable.lookUpScope(newiden->value.func);
		while (vars != NULL) {
			if (vars->child2->choice1 == 2) {
				assert(vars->child2->child1.choice2->child1->choice1 == 4);
				int arraySize = vars->child2->child1.choice2->child1->child1.choice4->size;

				nameList * varName = vars->child1;
				while (varName != NULL) {
					identifier * newvariden = gtable.lookUp(varName->child2, pscope);
					assert(newvariden->type == arrayT);
					sprintf(temp, "%d", -1 * arraySize * 4);
					res += "addi $sp, $sp, " + string(temp) + "\n";
					res += "sw $sp, " + to_string(newvariden->offset) + "($fp)\n";

					varName = varName->child1;
				}
			}
			else {}

			vars = vars->next;
		}

		int funcScope = gtable.lookUp(child1.choice2.child1, currentScope)->scope;
		sprintf(temp, "%d", funcScope);

		res += "jal " + child1.choice2.child1->name + string(temp) + "\n";
		res += "lw $fp, -4($fp)\n";
		sprintf(temp, "%d", 4);
		res += "addi $sp, $sp, " + string(temp) + "\n";
		sprintf(temp, "%d", totalSize);
		res += "addi $sp, $sp, " + string(temp) + "\n";

		res += ref_restore;

		break;}
	case  3: {
		break;}
	case  4: {
		break;}
	case  5: {
		switch (child1.choice5->choice1) {
			case  1: {
				sprintf(temp, "%d", child1.choice5->child1.choice1);
				res += "addi $v0, $zero, " + string(temp) + "\n"; break;}
			case  2: {
				res += ".data\n";
				sbCounter++;
				string lable = to_string(sbCounter);
				res += "data_" + lable + ":\n";
				sprintf(temp, "%f", child1.choice5->child1.choice2);
				res +=".float "+ string(temp)+"\n";
				res +=".text\n";
				res += "lwc1 $f0, data_"+lable + "\n";
				break;}
			case  3: {
				sprintf(temp, "%d", child1.choice5->child1.choice3);
				res += "addi $v0, $zero, " + string(temp) + "\n";
				break;}
			default: {break;}
		}
		break;}
	case  6: {
		res += child1.choice6->assembleGenerator();
		break;}
	case  7: {

		break;}
	case  8: {
		res += child1.choice8->assembleGenerator();
		if(value.stype == realR){
			res += "sub.s $f0, $f31, $f0\n";
		}
		else{
			res += "sub $v0, $zero, $v0\n";
		}
		break;}
	case  9: {
		res += child1.choice9.child2->assembleGenerator();

		identifier *newChild1 = gtable.lookUp(child1.choice9.child1, currentScope);
		assert(newChild1 != NULL);
		int scopePtr = currentScope;
		res += "add $t0, $zero, $fp\n";
		while (scopePtr != newChild1->scope) {
			res += "lw $t0, 4($t0)\n";
			scopePtr = gtable.getScope(scopePtr).parent;
		}
		sprintf(temp, "%d", newChild1->offset);
		string offset(temp);
		res += "lw $t0, " + offset + "($t0)\n";

		res += "sll $v0, $v0, 2\n";
		res += "add $t0, $t0, $v0\n";
		res += "lw  $v0, 0($t0)\n";

		break;}
	case 10: {

		break;}
	default:
		{break;}
}

return res;
}

int compStmt::serial = 0;
char compStmt::buff[20];
std::string ifStmt::assembleGenerator(){
sbCounter++;
std::string lable = to_string(sbCounter);
std::string res;
std::string elseaddr = "else_" + lable;
std::string endifaddr = "endif_" + lable;
res += child1->assembleGenerator();
res = res + "beq $v0, $zero, " + elseaddr + "\n";
if(child2)
	res += child2->assembleGenerator();
res = res + "j " + endifaddr +"\n";
res = res + elseaddr + ":\n";
if(child3)
	res += child3->assembleGenerator();
res = res + endifaddr + ":\n";
return res;
}
std::string elsePart::assembleGenerator(){
std::string res;
if(choice1 != 0 && child1){
	res += child1->assembleGenerator();
}
return res;
}

std::string gotoStmt::assembleGenerator(){
std::string res;
std::string targetaddr = "Label_" + to_string(child1);
res = res + "j " + targetaddr + "\n";
return res;
}


std::string caseStmt::assembleGenerator() {
std::string res;

sbCounter++;
std::string lable = to_string(sbCounter);
std::string endcaseaddr = "endcaseaddr_" + lable;

res += child1->assembleGenerator();

caseExp *temp = child2;
int nextLabelCounter = 0;
while (temp != NULL) {
	nextLabelCounter = sbCounter + 1;
	res += temp->assembleGenerator();
	res += "j " + endcaseaddr + "\n";
	res += "nextcaseaddr_" + to_string(nextLabelCounter) + ":\n";
	temp = temp->next;
}

res = res + endcaseaddr + ":\n";
return res;
}

std::string caseExp::assembleGenerator() {
std::string res;

sbCounter++;
std::string nextcaseaddr = "nextcaseaddr_" + to_string(sbCounter);


switch (choice1) {
	case  1:
		switch (child1.choice1->choice1) {
			case  1:
				res += "addi $t1, $zero, " + to_string(child1.choice1->child1.choice1) + "\n";
				break;
			case  2:
				break;
			case  3:
				res += "addi $t1, $zero, " + to_string(child1.choice1->child1.choice3) + "\n";
				break;
			default: break;
		}
		break;
	case  2:

		break;
	default: break;
}

res += "bne  $v0, $t1 " + nextcaseaddr + "\n";

res += child2->assembleGenerator();

return res;
}


std::string expr::assembleGenerator(){
std::string res;

if(child1 != NULL) {
	res += child1->assembleGenerator();
	res = res + "addi $sp, $sp, -4\n";

	if(value.stype == realR){
		res = res + "swc1 $f0, 0($sp)\n";
		res += child3->assembleGenerator();
		res = res + "lwc1 $f1, 0($sp)\n";
		switch(child2){
		case plusP	:
			res += "add.s $f0, $f1, $f0\n";
			break;
		case minusM:
			res += "sub.s $f0, $f1, $f0\n";
			break;
		default: break;
		}
	}
	else{
		res = res + "sw $v0, 0($sp)\n";
		res += child3->assembleGenerator();
		res = res + "lw $t1, 0($sp)\n";
		switch(child2){
		case plusP	:
			res += "add $v0, $t1, $v0\n";
			break;
		case minusM:
			res += "sub $v0, $t1, $v0\n";
			break;
		case orO:
			res += "or $v0, $t1, $v0\n";
			break;
		default: break;
		}
	}
	res = res + "addi $sp, $sp, 4\n";
}
else {
	res += child3->assembleGenerator();
}

return res;
}

std::string term::assembleGenerator(){
std::string res;

if (child1 != NULL) {
	res += child1->assembleGenerator();
	res = res + "addi $sp, $sp, -4\n";

	if(value.stype == realR){
		res = res + "swc1 $f0, 0($sp)\n";
		res += child3->assembleGenerator();
		res = res + "lwc1 $f1, 0($sp)\n";
		switch(child2){


		case mulM:
			res += "mul.s $f0, $f1, $f0\n";
			break;
		case divD:
			res += "div.s $f0, $f1, $f0\n";
			break;
		default: break;
		}
	}
	else{
		res = res + "sw $v0, 0($sp)\n";
		res += child3->assembleGenerator();
		res = res + "lw $t1, 0($sp)\n";
		switch(child2){
		case mulM:
			res += "mult $t1, $v0\n";
			res += "mflo $v0\n";
			break;
		case divD:
			res += "div $t1, $v0\n";
			res += "mflo $v0\n";
			break;
		case modM:
			res += "div $v0, $t1, $v0\n";
			res += "mfhi $v0\n";
			break;
		case andA:
			res += "and $v0, $t1, $v0\n";
			break;
		default: break;
		}
	}
	res = res + "addi $sp, $sp, 4\n";
}
else {
	res += child3->assembleGenerator();
}

return res;
}
void mips_head() {
	cout <<
".macro print_int (%x)\n\
	li $v0, 1\n\
	add $a0, $zero, %x\n\
	syscall\n\
.end_macro\n\n\
.macro print_char (%x)\n\
	li $v0, 11\n\
	add $a0, $zero, %x\n\
	syscall\n\
.end_macro\n\n\
.macro print_str (%str)\n\
	.data\n\
		myLabel: .asciiz %str\n\n\
	.text\n\
	li $v0, 4\n\
	la $a0, myLabel\n\
	syscall\n\
.end_macro\n" << endl;

	cout << "addi $sp, $sp,   -100" << endl;
	cout << "add  $fp, $zero, $sp" << endl;
}
void mips_body(program *root){
	char temp[30];
	varDeclList * vars = root->child2->child1->child4->child1;
	int pscope = 1;
	while (vars != NULL) {
		if (vars->child2->choice1 == 2) {
			int arraySize = vars->child2->child1.choice2->child1->child1.choice4->size;

			nameList * varName = vars->child1;
			while (varName != NULL) {
				identifier * newvariden = gtable.lookUp(varName->child2, pscope);
				sprintf(temp, "%d", -1 * arraySize * 4);
				cout << "addi $sp, $sp, " + string(temp) << endl;
				cout << "sw $sp, " + to_string(newvariden->offset) + "($fp)" << endl;
				varName = varName->child1;
			}
		}
		else {}

		vars = vars->next;
	}

	cout << root->assembleGenerator() << endl;
}


void myPascal::stprint(simpleType s) {
	switch(s) {
		case integerI: printf("integer\n"); break;
		case realR: printf("real\n"); break;
		case charC: printf("char\n"); break;
		case stringS: printf("string\n"); break;
		case sysConS: printf("sysCon\n"); break;
		case idrefI: printf("idref\n"); break;
		case enumE: printf("enum\n"); break;
		case rangeR: printf("range\n"); break;
		case idrangeI: printf("idrange\n"); break;
		case boolB: printf("bool\n"); break;
		default: printf("error\n"); break;
	}
}

	bool program::sematicAnalysis(int scope) {
		bool temp1 = child1->sematicAnalysis(this, scope);
		bool temp2 = child2->sematicAnalysis(gtable.insertScope(this, scope));
		return temp1&&temp2;
	}

	bool progHead::sematicAnalysis(program *root, int scope) {
		child1->constant = true;
		child1->typeDefn = false;
		child1->type = programP;
		child1->value.prog = root;
		child1->scope = scope;
		child1->offset = 8;
		bool temp = gtable.insertID(child1, scope);
		if(!temp)
			findNameConflict(child1, scope);
		return temp;
	}

	bool routine::sematicAnalysis(int scope) {
		bool temp1 = child1->sematicAnalysis(scope);
		bool temp2 = child2->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool subRout::sematicAnalysis(int scope) {
		bool temp1 = child1->sematicAnalysis(scope);
		bool temp2 = child2->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool routHead::sematicAnalysis(int scope) {
		bool temp1 = child1->sematicAnalysis(scope);
		bool temp2 = child2->sematicAnalysis(scope);
		bool temp3 = child3->sematicAnalysis(scope);
		bool temp4 = child4->sematicAnalysis(scope);
		bool temp5 = child5->sematicAnalysis(scope);
		return temp1&&temp2&&temp3&&temp4&&temp5;
	}

	bool consP::sematicAnalysis(int scope) {
		return child1==NULL?true:child1->sematicAnalysis(scope);
	}

	bool consExp::sematicAnalysis(int scope) {
		child2->sematicAnalysis(child1, scope);
		bool temp1 = gtable.insertID(child1, scope);
		if(!temp1)
			findNameConflict(child1, scope);
		gtable.addConst(child1);
		bool temp2 = next==NULL?true:next->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool consVal::sematicAnalysis(identifier *id, int scope) {
		id->typeDefn = false;
		id->constant = true;
		id->type = odinaryT;
		id->scope = scope;
		switch(choice1) {
		case 1: id->stype = integerI; id->value.i = child1.choice1; break;
		case 2: id->stype = realR; id->value.f = child1.choice2; break;
		case 3: id->stype = charC; id->value.c = child1.choice3; break;
		case 4: id->stype = stringS; id->value.s = child1.choice4; break;
		case 5: id->stype = sysConS; break;
		default: break;
		}
		return true;
	}

	bool typeP::sematicAnalysis(int scope) {
		return child1==NULL?true:child1->sematicAnalysis(scope);
	}

	bool typeDef::sematicAnalysis(int scope) {
		child2->sematicAnalysis(child1, scope, 1);
		bool temp1 = gtable.insertID(child1, scope);
		if(!temp1)
			findNameConflict(child1, scope);
		bool temp2 = next==NULL?true:next->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool typeDecl::sematicAnalysis(identifier *id, int scope, int type) {
		switch(choice1) {
		case 1: return child1.choice1->sematicAnalysis(id, scope, type);
		case 2: return child1.choice2->sematicAnalysis(id, scope, type);
		case 3: return child1.choice3->sematicAnalysis(id, scope, type);
		default: break;
		}
		return true;
	}

	bool simple_typeDecl::sematicAnalysis(identifier *id, int scope, int type) {
		id->constant = id->typeDefn = type==1;
		id->scope = scope;
		id->type = odinaryT;
		switch(choice1) {
		case 1: id->stype = child1.choice1->child1;  break;
		default: break;
		}
		return true;
	}

	bool simple_typeDecl::sematicAnalysis(nameList *ids, int scope, int type) {
		while(ids!=NULL) {
			sematicAnalysis(ids->child2, scope, type);
			ids = ids->child1;
		}
		return true;
	}

	bool typeDecl::sematicAnalysis(nameList *ids, int scope, int type) {
		bool temp1 = ids->child1==NULL?true:sematicAnalysis(ids->child1, scope, type);
		bool temp2 = sematicAnalysis(ids->child2, scope, type);
		return temp1&&temp2;
	}

	bool array_typeDecl::sematicAnalysis(identifier *id, int scope, int type) {
		id->scope = scope;
		id->typeDefn = id->constant = type==1;
		id->type = arrayT;
		id->value.array = this;
		assert(child1->choice1==4);
		assert(child2->choice1==1);
		bool temp2 = child1->child1.choice4->sematicAnalysis();
		return temp2;
	}


	bool range::sematicAnalysis() {
		if(child1->choice1!=1||child2->choice1!=1) {
			printf("Error at line %d : can only use integer to index array.\n", lineno);
			return false;
		}
		size = child2->child1.choice1 - child1->child1.choice1 + 1;
		assert(size>0);
		return true;
	}

	bool nameList::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->sematicAnalysis(scope);
		scopeValue s = gtable.getScope(scope);
		switch(s.choice) {
		case 1: {
			program *pp = s.type.type1;
			child2->offset = pp->child1->child1->offset;
			pp->child1->child1->offset +=4;
			break;
		}
		case 2: {
			funcDecl *fp = s.type.type2;
			child2->offset = fp->child1->child1->offset;
			fp->child1->child1->offset+=4;
			break;
		}
		case 3: {
			procDecl *rp = s.type.type3;
			child2->offset = rp->child1->child1->offset;
			rp->child1->child1->offset+=4;
			break;
		}
		default: break;
		}
		bool temp2 = gtable.insertID(child2, scope);
		if(!temp2)
			findNameConflict(child2, scope);
		return temp1&&temp2;
	}

	bool varP::sematicAnalysis(int scope) {
		return child1==NULL?true:child1->sematicAnalysis(scope);
	}

	bool varDecl::sematicAnalysis(int scope) {
		child2->sematicAnalysis(child1, scope, 2);
		bool temp1 = child1->sematicAnalysis(scope);
		bool temp2 = next==NULL?true:next->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool routP::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->nameCheck(scope);
		bool temp2 = child2==NULL?true:child2->nameCheck(scope);
		if(!temp1||!temp2)
			return false;
		bool temp3 = child1==NULL?true:child1->sematicAnalysis(scope);
		bool temp4 = child2==NULL?true:child2->sematicAnalysis(scope);
		return temp3&&temp4;
	}

	bool funcDecl::nameCheck(int scope) {
		bool temp1 = child1->sematicAnalysis(this, scope);
		bool temp2 = next==NULL?true:next->nameCheck(scope);

		return temp1&&temp2;
	}

	void funcDecl::reversePosition(int scope) {
		int off = child1->child1->offset;
		const std::vector<std::string> *lst = child1->child1->params;
		assert(lst!=NULL);
		for(int i=0; i< lst->size(); ++i) {
			identifier *id = gtable.lookUp(lst->at(i), scope);
			assert(id!=NULL);
			int no = (id->offset-8)/4+1;
			id->offset = off-no*4;
		}
	}

	bool funcDecl::sematicAnalysis(int scope) {
		int temp = gtable.lookUpScope(this);
		bool temp1 = child2->sematicAnalysis(temp);
		bool temp2 = next==NULL?true:next->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool funcHead::sematicAnalysis(funcDecl *root, int scope) {
		child1->scope = scope;
		child1->value.func = root;
		child3->sematicAnalysis(child1, scope, 2);
		child1->type = functionF;
		child1->constant = false;
		child1->offset = 8;
		if(!gtable.insertID(child1, scope)) {
			findNameConflict(child1, scope);
			return false;
		}
		int temp = gtable.insertScope(root, scope);
		return child2==NULL?true:child2->sematicAnalysis(child1, temp);
	}

	bool procDecl::nameCheck(int scope) {
		bool temp1 = child1->sematicAnalysis(this, scope);
		bool temp2 = next==NULL?true:next->nameCheck(scope);

		return temp1&&temp2;
	}

	void procDecl::reversePosition(int scope) {
		int off = child1->child1->offset;
		const std::vector<std::string> *lst = child1->child1->params;
		assert(lst!=NULL);
		for(int i=0; i< lst->size(); ++i) {
			identifier *id = gtable.lookUp(lst->at(i), scope);
			assert(id!=NULL);
			int no = (id->offset-8)/4+1;
			id->offset = off-no*4;
		}
	}

	bool procDecl::sematicAnalysis(int scope) {
		int temp = gtable.lookUpScope(this);
		bool temp1 = child2->sematicAnalysis(temp);
		bool temp2 = next==NULL?true:next->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool procHead::sematicAnalysis(procDecl *root, int scope) {
		child1->scope = scope;
		child1->type = procedureP;
		child1->value.proc = root;
		child1->constant = true;
		child1->typeDefn = false;
		child1->params = NULL;
		child1->offset = 8;
		if(!gtable.insertID(child1, scope)) {
			findNameConflict(child1, scope);
			return false;
		}
		int temp =  gtable.insertScope(root, scope);
		return child2==NULL?true:child2->sematicAnalysis(child1, temp);
	}

	bool parameters::sematicAnalysis(identifier *root, int scope) {
		if(child1==NULL) {
			root->params = NULL;
			return true;
		}
		root->params = new std::vector<std::string>();
		return child1->sematicAnalysis(root, scope);
	}

	bool paraTypeList::sematicAnalysis(identifier *root, int scope) {
		bool temp1, temp2, temp3;
		if(choice1==1) {
			addParameters(root, child1.choice1, 1);
			temp1 = child2->sematicAnalysis(child1.choice1, scope, 2);
			temp2 = child1.choice1->sematicAnalysis(scope);
		}
		else {
			addParameters(root, child1.choice2, 2);
			temp1 = child2->sematicAnalysis(child1.choice1, scope, 2);
			temp2 = child1.choice2->sematicAnalysis(scope);
		}
		temp3 = next==NULL?true:next->sematicAnalysis(root, scope);
		return temp1&&temp2&&temp3;
	}

	void paraTypeList::addParameters(identifier *root, nameList *ids, int type) {
		if(ids->child1!=NULL)
			addParameters(root, ids->child1, type);
		root->params->push_back(ids->child2->name);
		ids->child2->passByReference = type==1;
	}

	bool routBody::sematicAnalysis(int scope) {
		return child1==NULL?true:child1->sematicAnalysis(scope);
	}

	bool compStmt::sematicAnalysis(int scope) {
		return child1==NULL?true:child1->sematicAnalysis(scope);
	}
	bool assignStmt::sematicAnalysis(int scope) {
		identifier *id = gtable.lookUp(child1, scope);
		if(id==NULL) {
			findNameLost(child1, scope);
			return false;
		}
		if(id->constant) {
			fprintf(stderr, "Error at line %d : can't assign value to constant identifier '%s'.\n",
				id->lineno, id->name.c_str());
			return false;
		}
		bool temp;
		switch(choice2) {
		case 1:	{
			if(!child2.choice1->sematicAnalysis(scope))
				return false;
			temp = typeEql(id, child2.choice1);
			if(!temp)
				findTNotMatch(child1->lineno, id, child2.choice1);
			return temp;
		}
		case 2: {
			bool temp1 = child2.choice2.child1->sematicAnalysis(scope);
			bool temp2 = child2.choice2.child2->sematicAnalysis(scope);
			if(!temp1||!temp2)
				return false;
			if(child2.choice2.child1->type!=odinaryT||child2.choice2.child1->value.stype!=integerI) {
				findTNotMatch(child1->lineno, child2.choice2.child1, integerI);
				return false;
			}

			if(!typeEql(id, child2.choice2.child2)) {
				findTNotMatch(child1->lineno, id, child2.choice2.child2);
				return false;
			}
			return temp1&&temp2;
		}
		case 3: {
			identifier *idd = gtable.lookUp(child2.choice3.child1, scope);
			child2.choice3.child2->sematicAnalysis(scope);
			if(idd==NULL) {
				findNameLost(child2.choice3.child1, scope);
				return false;
			}
			return true;
		}
		default: return false;
		}
	}

	bool procStmt::sematicAnalysis(int scope) {
		switch(choice1) {
		case 1: {
			identifier *id = gtable.lookUp(child1.choice1, scope);
			if(id==NULL) {
				findNameLost(child1.choice1, scope);
				return false;
			}
			return (id->type==functionF||id->type==procedureP)&&id->params==NULL;
		}
		case 2: {
			identifier *id = gtable.lookUp(child1.choice2.child1, scope);
			if(id==NULL) {
				findNameLost(child1.choice2.child1, scope);
				return false;
			}
			if(id->type!=functionF&&id->type!=procedureP) {
				findTNotMatch(child1.choice2.child1->lineno, id, canCall);
				return false;
			}
			if(!child1.choice2.child2->sematicAnalysis(scope))
				return false;

			return true;
		}
		case 3:
			return true;
		case 4:
			return child1.choice4.child2->sematicAnalysis(scope);
		case 5: {
			if(!child1.choice5->sematicAnalysis(scope))
				return false;
			if(child1.choice5->choice1!=1&&child1.choice5->choice1!=9) {
				printf("Error at line %d : expression inside read() is not assignable.\n", lineno);
				return false;
			}
			return true;
		}
		default: return false;
		}
	}

	bool ifStmt::sematicAnalysis(int scope) {
		bool temp1 = child1->sematicAnalysis(scope);
		bool temp2 = child2==NULL?true:child2->sematicAnalysis(scope);
		bool temp3 = child3==NULL?true:child3->sematicAnalysis(scope);
		return temp1&&temp2&&temp3;
	}

	bool elsePart::sematicAnalysis(int scope) {
		return choice1==0?true:child1->sematicAnalysis(scope);
	}

	bool repeatStmt::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->sematicAnalysis(scope);
		bool temp2 = child2==NULL?true:child2->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool whileStmt::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->sematicAnalysis(scope);
		bool temp2 = child2==NULL?true:child2->sematicAnalysis(scope);
		return temp1&&temp2;
	}


	bool forStmt::sematicAnalysis(int scope) {
		bool temp1 = gtable.lookUp(child1, scope)!=NULL;
		bool temp2 = child2==NULL?true:child2->sematicAnalysis(scope);
		bool temp3 = child4==NULL?true:child4->sematicAnalysis(scope);
		bool temp4 = child5==NULL?true:child5->sematicAnalysis(scope);
		if(!temp1)
			findNameLost(child1, scope);
		if(!temp2||!temp3) return false;
		temp2 = child2==NULL?true:
							(child2->type==odinaryT&&(child2->value.stype==integerI||child2->value.stype==charC));
		temp3 = child4==NULL?true:
							(child4->type==odinaryT&&(child4->value.stype==integerI||child4->value.stype==charC));
		return temp1&&temp2&&temp3&&temp4&&typeEql(child2, child4);
	}

	bool caseStmt::sematicAnalysis(int scope) {
		bool temp1 = child1->sematicAnalysis(scope);
		bool temp2 = child2->sematicAnalysis(scope);
		return temp1&&temp2;
	}

	bool caseExp::sematicAnalysis(int scope) {
		bool temp1;
		switch(choice1) {
		case 1:
			temp1 = true;
			break;
		case 2: {
			identifier *id = gtable.lookUp(child1.choice2, scope);
			if(id==NULL) {
				temp1=false;
				findNameLost(child1.choice2, scope);
				break;
			}
			if(!id->constant) {
				fprintf(stderr, "Error at line %d : %s is not a constant value.\n",
					id->lineno, id->name.c_str());
				temp1=false;
				break;
			}
			temp1 = true;
			break;
		}
		default: temp1=false; break;
		}
		bool temp2 = child2->sematicAnalysis(scope);
		bool temp3 = next==NULL?true:next->sematicAnalysis(scope);
		return temp1&&temp2&&temp3;
	}

	bool expression::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->sematicAnalysis(scope);
		bool temp2 = child3->sematicAnalysis(scope);
		bool temp3 = next==NULL?true:next->sematicAnalysis(scope);

		if(!temp1||!temp2)
			return false;

		if(child1!=NULL&&!typeEql(child1, child3)) {
			return false;
		}

		type = child3->type;
		value = child3->value;
		return temp3;
	}

	bool expr::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->sematicAnalysis(scope);
		bool temp2 = child3->sematicAnalysis(scope);
		if(!temp1||!temp2)
			return false;
		type = child3->type;
		value = child3->value;
		return true;
	}

	bool term::sematicAnalysis(int scope) {
		bool temp1 = child1==NULL?true:child1->sematicAnalysis(scope);
		bool temp2 = child3->sematicAnalysis(scope);
		if(!temp1||!temp2)
			return false;
		type = child3->type;
		value = child3->value;
		return true;
	}


	bool factor::sematicAnalysis(int scope) {
		switch(choice1) {
		case 1: {
			identifier *id = gtable.lookUp(child1.choice1, scope);
			if(id==NULL) {
				findNameLost(child1.choice1, scope);
				return false;
			}

			type = id->type;
			value.stype = id->stype;
			return true;
		}
		case 2: {
			identifier *id = gtable.lookUp(child1.choice2.child1, scope);
			if(id==NULL) {
				findNameLost(child1.choice2.child1, scope);
				return false;
			}

			type = id->type;
			value.stype = id->stype;
			return child1.choice2.child2->sematicAnalysis(scope);
		}
		case 3: return true;
		case 4: return child1.choice4.child2->sematicAnalysis(scope);
		case 5: {
			type = odinaryT;
			switch(child1.choice5->choice1) {
			case 1: value.stype = integerI; break;
			case 2: value.stype = realR; break;
			case 3: value.stype = charC; break;
			case 4: value.stype = stringS; break;
			default: break;
			}
			return true;
		}
		case 6:
			if(child1.choice6->sematicAnalysis(scope)) {
				type = child1.choice6->type;
				value = child1.choice6->value;
				return true;
			}
			return false;
		case 7:
			if(child1.choice7->sematicAnalysis(scope)) {
				type = child1.choice6->type;
				value = child1.choice6->value;
				return true;
			}
			return false;
		case 8:
			if(child1.choice8->sematicAnalysis(scope)) {
				type = child1.choice6->type;
				value = child1.choice6->value;
				return true;
			}
			return false;
		case 9: {
			identifier *id = gtable.lookUp(child1.choice9.child1, scope);
			if(id==NULL) {
				findNameLost(id, scope);
				return false;
			}
			if(id->type!=arrayT) {
				printf("Error at line %d : %s is not array type.\n", child1.choice9.child1->lineno, child1.choice9.child1->name.c_str());
				return false;
			}
			if(!child1.choice9.child2->sematicAnalysis(scope))
				return false;
			if(child1.choice9.child2->type!=odinaryT||child1.choice9.child2->value.stype!=integerI) {
				printf("Error at line %d : expression inside '[]' is not an integer.\n", child1.choice9.child2->lineno);
				return false;
			}
			return true;
		}
		case 10: return true;
		default: return false;
		}
	}

	bool stmt::sematicAnalysis(int scope) {
		bool temp0 = choice1==0?true:gtable.addLabel(child1);
		if(!temp0)
			fprintf(stderr, "Error : label %d redefined.\n", child1);
		bool temp1 = child2->sematicAnalysis(scope);
		bool temp2 = next==NULL?true:next->sematicAnalysis(scope);
		return temp0&&temp1&&temp2;
	}

	bool nlbStmt::sematicAnalysis(int scope) {
		switch(choice1) {
		case 1: return child1.choice1->sematicAnalysis(scope);
		case 2: return child1.choice2->sematicAnalysis(scope);
		case 3: return child1.choice3->sematicAnalysis(scope);
		case 4: return child1.choice4->sematicAnalysis(scope);
		case 5: return child1.choice5->sematicAnalysis(scope);
		case 6: return child1.choice6->sematicAnalysis(scope);
		case 7: return child1.choice7->sematicAnalysis(scope);
		case 8: return child1.choice8->sematicAnalysis(scope);
		case 9: return child1.choice9->sematicAnalysis(scope);
		default: return false;
		}
	}

	bool gotoStmt::sematicAnalysis(int scope) {
		gtable.addUsedLabel(child1);
		return true;
	}
