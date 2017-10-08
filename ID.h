#pragma once
#include "Token.h"
#include "Lexer.h"
#include "Parameter.h"

class Id : public Parameter{
public:
	Id(Lexer* lex) {
		id = lex->next(ID);
	}
/*	string toString() {
		return id->value();
	} */
protected:
	Token* id;
};