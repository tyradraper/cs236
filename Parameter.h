#pragma once
#include "Id.h"
#include "String.h"
#include "Expression.h"
#include "Lexer.h"

class Parameter {
public:
	static Parameter createParameter(Lexer lex) {
		new Id(lex);
		new String(lex);
		new Expression(lex);
	}
};