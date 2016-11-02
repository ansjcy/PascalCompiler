#ifndef _PASCALSTMT__H_
#define _PASCALSTMT__H_

namespace myPascal {

    struct identifier;
    struct program;
    struct progHead;
    struct routine;
    struct routHead;
    struct routBody;
    struct lbP;
    struct consP;
    struct typeP;
    struct varP;
    struct routP;
    
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
    //
    struct compStmt;
    struct stmt;
    typedef stmt stmtList;
    //
    struct nlbStmt;
    struct assignStmt;
    struct procStmt;
    struct ifStmt;
    struct repeatStmt;
    struct whileStmt;
    struct forStmt;
    struct caseStmt;
    struct gotoStmt;
    struct sysProc;
    struct expression;
    typedef expression argsList;
    typedef expression expList;

};

#endif
