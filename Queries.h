#pragma once
#include "Query.h"
#include "Lexer.h"
#include <vector>

class Queries {
public:
	Queries(Lexer lex) {
		while (true) {
			try {
				queries.push_back(new Query(lex));
			}
			catch (Token* e) {
				break;
			}
		}
	}
protected:
	vector<Query*> queries;
};