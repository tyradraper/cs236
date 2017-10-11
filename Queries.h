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
	string toString() {
		string result = "";
		result += "Queries(" + to_string(queries.size()) + "):\n";
		for (int i = 0; i < queries.size(); ++i) {
			result += "  " + queries.at(i)->toString() + "\n";
		}
		return result;
	}
protected:
	vector<Query*> queries;
};