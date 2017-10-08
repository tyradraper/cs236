#pragma once
#include "Parameter.h"
#include "Lexer.h"
#include <vector>

class Predicate {
public:
	Predicate(Lexer* lex) {
		Parameter* param;
		predicateId = new Id(lex);
		lex->next(LEFT_PAREN);
		parameters.push_back(param->createParameter(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			parameters.push_back(param->createParameter(lex));
		}
		lex->next(RIGHT_PAREN);
	}
protected:
	Id* predicateId;
	vector<Parameter*> parameters;
};