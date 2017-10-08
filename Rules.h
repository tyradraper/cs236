#pragma once
#include "Rule.h"
#include "Lexer.h"
#include <vector>

class Rules {
public:
	Rules(Lexer lex) {
		while (true) {
			try {
				rules.push_back(new Rule(lex));
			}
			catch (Token* e) {
				break;
			}
		}
	}
protected:
	vector<Rule*> rules;
};