#pragma once
#include "HeadPredicate.h"
#include "Predicate.h"
#include "Lexer.h"
#include <vector>

class Rule {
public:
	Rule(Lexer lex) {
		head = new HeadPredicate(lex);
		predicates.push_back(new Predicate(lex));
	}
protected:
	HeadPredicate* head;
	vector<Predicate*> predicates;
};