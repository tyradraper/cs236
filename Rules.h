#pragma once
#include "Rule.h"
#include "Lexer.h"
#include <vector>

class Rules {
public:
	Rules(Lexer* lex) {
		lex->next(RULES);
		lex->next(COLON);
		while (lex->top()->type() == ID) {
			rules.push_back(new Rule(lex));
		}
	}
protected:
	vector<Rule*> rules;
};