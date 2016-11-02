#ifndef _PASCALTYPE__H_
#define _PASCALTYPE__H_
namespace myPascal {
    struct fieldlDecl;
    typedef fieldlDecl fieldDeclList;
    //
    struct fieldlDecl;
    typedef fieldlDecl fieldDeclList;
    //
    struct varDecl;
    typedef varDecl varDeclList;
    //
    struct funcDecl;
    typedef funcDecl funcDeclList;
    //
    struct funcHead;
    struct procDecl;
    typedef procDecl procDecl_list;

    enum Type {
    	odinaryT,
    	arrayT,
    	recordT,
    	programP,
    	procedureP,
    	functionF,
    	canCall
    };

    enum simpleType {
    	integerI,
    	realR,
    	charC,
    	stringS,
    	sysConS,
    	idrefI,
    	enumE,
    	rangeR,
    	idrangeI,
    	boolB
    };


};

#endif
