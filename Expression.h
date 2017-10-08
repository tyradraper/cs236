#pragma once
#include "Parameter.h"
#include "Predicate.h"
#include "Lexer.h"
#include <string>
using namespace std;

enum Operator { PLUS, TIMES };
static const string OPERATOR_STRING[] = { "+", "*" };

class Expression : public Parameter {
public:
	Expression(Lexer lex) {
		createParameter(lex);
	}
protected:
	Predicate* predicate1;
	Operator myOperator;
	Predicate* predicate2;
};