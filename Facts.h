#pragma once
#include "Fact.h"
#include "Lexer.h"
#include <vector>

class Facts {
public:
	Facts(Lexer* lex) {
		lex->next(FACTS);
		lex->next(COLON);
		while (lex->top()->type() == ID) {
			facts.push_back(new Fact(lex));
		}		
	}
protected:
	vector<Fact*> facts;
};