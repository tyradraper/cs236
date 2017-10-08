#pragma once
#include "Parameter.h"
#include "Predicate.h"
#include "Lexer.h"
#include <string>
using namespace std;

enum Operator { PLUS, TIMES };
//static const string OPERATOR_STRING[] = { "+", "*" };

class Expression : public Parameter {
public:
	Expression(Lexer* lex) {
		lex->next(LEFT_PAREN);
		parameter1 = createParameter(lex);
		if (lex->top()->type() == ADD) {
			lex->pop();
			myOperator = PLUS;
		}
		else {
			lex->next(MULTIPLY);
			myOperator = TIMES;
		}
		parameter2 = createParameter(lex);
		lex->next(RIGHT_PAREN);
	}
protected:
	Parameter* parameter1;
	Operator myOperator;
	Parameter* parameter2;
};