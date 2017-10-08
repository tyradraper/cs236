#pragma once
#include "Id.h"
#include "Lexer.h"
#include <vector>

class Scheme {
public:
	Scheme(Lexer lex) {
		schemeId = new Id(lex);
		columnNames.push_back(new Id(lex));
	}
protected:
	Id* schemeId;
	vector<Id*> columnNames;
};