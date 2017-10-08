#pragma once
#include "Token.h"
#include "Lexer.h"
#include "Parameter.h"

class String : public Parameter {
public:
	String(Lexer* lex) {
		myString = lex->next(STRING);
	}
/*	string toString() {
		return myString->value();
	} */
protected:
	Token* myString;
};