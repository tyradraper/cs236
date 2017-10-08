#pragma once
#include "Query.h"
#include "Lexer.h"
#include <vector>

class Queries {
public:
	Queries(Lexer* lex) {
		lex->next(QUERIES);
		lex->next(COLON);
		do {
			queries.push_back(new Query(lex));
		} while (lex->top()->type() == ID);
	}
protected:
	vector<Query*> queries;
};