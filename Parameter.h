#pragma once
#include "Id.h"
#include "String.h"
#include "Expression.h"
#include "Lexer.h"

class Parameter {
public:
	static Parameter* createParameter(Lexer* lex) {
		if (lex->top()->type() == ID) {
			return new Id(lex);
		}
		else if (lex->top()->type() == STRING) {
			return new Id(lex);
		}
		else {
			return new Expression(lex);
		}
	}
};