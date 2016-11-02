%{
/* create by Zhu Hao */

#include <cstdio>
#include "pascal.h"
#include "util.h"
using namespace myPascal;
#include "y.tab.h"

int lineno = 1;

%}

digit [0-9]
letter [a-zA-Z]
line \n
blank " "|"\t"
INTVALUE {digit}+
REALVALUE {digit}+"."{digit}+
CHARVALUE "'"."'"
STRINGVALUE \"[^\"]*\"
IDENTIFIER ("_"|{letter})("_"|{letter}|{digit})*
DOTDOT ".""."

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
%%

"(" { return LP; }
")" { return RP; }
"[" { return LB; }
"]" { return RB; }
"." { return DOT; }
"," { return COMMA; }
";" { return SEMI; }
":" { return COLON; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"<=" { return LE; }
">=" { return GE; }
"<" { return LT; }
">" { return GT; }
"=" { return EQUAL; }
"<>" { return UNEQUAL; }
":=" { return ASSIGN; }

{A}{N}{D} { return AND; }
{A}{R}{R}{A}{Y} { return ARRAY; }
{B}{E}{G}{I}{N} { return BBEGIN; }
{C}{A}{S}{E} { return CASE; }
{C}{H}{A}{R} { return CHAR; }
{C}{O}{N}{S}{T} { return CONST; }
{D}{I}{V} { return DIV; }
{D}{O} { return DO; }
{D}{O}{W}{N}{T}{O} { return DOWNTO; }
{E}{L}{S}{E} { return ELSE; }
{E}{N}{D} { return END; }
{F}{O}{R} { return FOR; }
{F}{U}{N}{C}{T}{I}{O}{N} { return FUNCTION; }
{G}{O}{T}{O} { return GOTO; }
{I}{F} { return IF; }
{I}{N} { return IN; }
{I}{N}{T}{E}{G}{E}{R} { return INTEGER; }
{L}{A}{B}{E}{L} { return LABEL; }
{M}{O}{D} { return MOD; }
{N}{I}{L} { return NIL; }
{N}{O}{T} { return NOT; }
{O}{F} { return OF; }
{O}{R} { return OR; }
{O}{T}{H}{E}{R}{W}{I}{S}{E} { return OTHERWISE; }
{P}{R}{O}{C}{E}{D}{U}{R}{E} { return PROCEDURE; }
{P}{R}{O}{G}{R}{A}{M} { return PROGRAM; }
{R}{E}{A}{L} { return REAL; }
{R}{E}{C}{O}{R}{D} { return RECORD; }
{R}{E}{A}{D} { return READ; }
{R}{E}{P}{E}{A}{T} { return REPEAT; }
{S}{T}{R}{I}{N}{G} { return STRING; }
{T}{H}{E}{N} { return THEN; }
{T}{O} { return TO; }
{T}{Y}{P}{E} { return TYPE; }
{U}{N}{T}{I}{L} { return UNTIL; }
{V}{A}{R} { return VAR; }
{W}{H}{I}{L}{E} { return WHILE; }
{W}{R}{I}{T}{E} { return WRITE; }
{W}{R}{I}{T}{E}{L}{N} { return WRITELN; }

{DOTDOT} { return DOTDOT; }
{IDENTIFIER} { lower(yytext); return IDENTIFIER; }
{INTVALUE} { return INTVALUE; }
{REALVALUE} { return REALVALUE; }
{CHARVALUE} { return CHARVALUE; }
{STRINGVALUE} { return STRINGVALUE; }
{line} { lineno++; }

"(""*" {
		char temp;
		while(true)
		{
			while((temp = yyinput()) != '*')
			{
				if(temp == '\n')
					lineno++;
			}
			while((temp = yyinput()) == '*') ;
			if(temp == ')')
				break;
			if(temp == '\n')
				lineno++;
		}
	}
{blank} { }
. {
	fprintf(stderr, "unrecognized term : %s at line %d.\n", yytext, lineno);
	exit(1);
}

%%

int yywrap ()
{
	return (1);
}
