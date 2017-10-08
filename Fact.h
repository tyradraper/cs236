#pragma once
#include "Parameter.h"
#include "String.h"
#include "Lexer.h"
#include <vector>

class Fact {
public:
	Fact(Lexer* lex) {
		vectorId = new Id(lex);
		lex->next(LEFT_PAREN);
		strings.push_back(new String(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			strings.push_back(new String(lex));
		}
		lex->next(RIGHT_PAREN);
		lex->next(PERIOD);
	}
protected:
	Id* vectorId;
	vector<String*> strings;
};