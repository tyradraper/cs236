#pragma once
#include "Token.h"
#include "Lexer.h"
#include "Parameter.h"

class Id : public Parameter {
public:
	Id(Lexer* lex) {
		id = lex->next(ID);
	}
	string toString() {
		return id->value();
	}
	bool operator==(Id &other) {
		return (this->toString() == other.toString());
	}
	bool operator!=(Id &other) {
		return !(*this == other);
	}
protected:
	Token* id;
};