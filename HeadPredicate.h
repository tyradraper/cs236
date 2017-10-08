#pragma once

#include "Predicate.h"
#include "Lexer.h"

class HeadPredicate : public Predicate {
public:
	HeadPredicate(Lexer* lex) {
		predicateId = new Id(lex);
		lex->next(LEFT_PAREN);
		do {
			parameters.push_back(new Id(lex));
		} while (lex->top()->type() == ID);
		lex->next(RIGHT_PAREN);
	}
};