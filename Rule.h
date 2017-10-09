#pragma once
#include "HeadPredicate.h"
#include "Lexer.h"
#include <vector>

class Rule {
public:
	Rule(Lexer* lex) {
		head = new HeadPredicate(lex);
		lex->next(COLON_DASH);
		predicates.push_back(new Predicate(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			predicates.push_back(new Predicate(lex));
		}
		lex->next(PERIOD);
	}
protected:
	HeadPredicate* head;
	vector<Predicate*> predicates;
};