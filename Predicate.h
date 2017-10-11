#pragma once
#include "Parameter.h"
#include "Lexer.h"
#include <vector>

class Predicate {
public:
	Predicate() {}
	Predicate(Lexer* lex) {
		predicateId = new Id(lex);
		lex->next(LEFT_PAREN);
		parameters.push_back(Parameter::createParameter(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			parameters.push_back(Parameter::createParameter(lex));
		}
		lex->next(RIGHT_PAREN);
	}
	string toString() {
		string x = predicateId->toString() + "(";
		int i = 1;
		for (Parameter* param : parameters) {
			x += param->toString();
			if (i < parameters.size()) {
				x += ",";
				i++;
			}
		}
		x += ")";
		return x;
	}
protected:
	Id* predicateId;
	vector<Parameter*> parameters;
};