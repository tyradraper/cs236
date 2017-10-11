#pragma once
#include "Lexer.h"

class Parameter {
public:
	Parameter() {}
	static Parameter* createParameter(Lexer* lex);
	virtual string toString() { return ""; }
};