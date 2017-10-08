#pragma once
#include "Fact.h"
#include "Lexer.h"
#include <vector>

class Facts {
public:
	Facts(Lexer lex) {
		while (true) {
			try {
				facts.push_back(new Fact(lex));
			}
			catch (Token* e) {
				break;
			}
		}
	}
protected:
	vector<Fact*> facts;
};