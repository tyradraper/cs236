#pragma once
#include "Id.h"
#include "Parameter.h"
#include "Lexer.h"
#include <vector>

class Predicate {
public:
	Predicate(Lexer lex) {
		predicateId = new Id(lex);
		parameters.push_back(new Parameter(lex));
	}
protected:
	Id* predicateId;
	vector<Parameter*> parameters;
};