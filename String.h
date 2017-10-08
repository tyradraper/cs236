#pragma once
#include "Token.h"
#include "Lexer.h"

class String {
public:
	String(Lexer* lex) {
		myString = lex->next(STRING);
	}
	string toString() {
		return myString->value();
	}
protected:
	Token* myString;
};