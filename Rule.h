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
	string toString() {
		string result = "";
		result += head->toString() + " :- ";
		for (int i = 0; i < predicates.size(); ++i) {
			result += predicates.at(i)->toString();
			if (i != predicates.size() - 1) {
				result += ",";
			}
		}
		result += ".";
		return result;
	}
protected:
	HeadPredicate* head;
	vector<Predicate*> predicates;
};