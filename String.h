#pragma once
#include "Token.h"
#include "Lexer.h"
#include "Parameter.h"

class String : public Parameter {
public:
	String(Lexer* lex) {
		myString = lex->next(STRING);
	}
	string toString() {
		return myString->value();
	}
	bool operator==(String &other) {
		return (this->toString() == other.toString());
	}
	bool operator!=(String &other) {
		return !(*this == other);
	}
	int type() {
		return STRING;
	}
protected:
	Token* myString;
};