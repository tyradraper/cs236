#pragma once

#include "Predicate.h"
#include "Lexer.h"

class HeadPredicate : public Predicate {
public:
	HeadPredicate(Lexer* lex) {
		predicateId = new Id(lex);
		lex->next(LEFT_PAREN);
		parameters.push_back(new Id(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			parameters.push_back(new Id(lex));
		}
		lex->next(RIGHT_PAREN);
	}
	string toString() { //same as predicate's tostring
		string result = "";
		result += " " + predicateId->toString() + "(";
		for (int i = 0; i < parameters.size(); ++i) {
			result += parameters.at(i)->toString();
			if (i != parameters.size() - 1) {
				result += ",";
			}
		}
		result += ")";
		return result;
	}
};