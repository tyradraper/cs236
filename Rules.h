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
	string toString() {
		string result = "";
		result = result + "Rules(" + to_string(rules.size()) + "):\n";
		for (int i = 0; i < rules.size(); ++i) {
			result += " " + rules.at(i)->toString() + "\n";
		}
		return result;
	}
protected:
	vector<Rule*> rules;
};