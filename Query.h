#pragma once
#include "Predicate.h"
#include "Lexer.h"

class Query : public Predicate {
public:
	Query(Lexer* lex) : Predicate(lex) {
		lex->next(Q_MARK);
	}
};