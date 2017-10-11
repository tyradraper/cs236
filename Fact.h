#pragma once
#include "Id.h"
#include "String.h"
#include "Lexer.h"
#include <vector>

class Fact {
public:
	Fact(Lexer* lex) {
		vectorId = new Id(lex);
		lex->next(LEFT_PAREN);
		strings.push_back(new String(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			strings.push_back(new String(lex));
		}
		lex->next(RIGHT_PAREN);
		lex->next(PERIOD);
	}
	string toString() {
		string result = vectorId->toString() + "(";
		for (int i = 0; i < strings.size(); ++i) {
			result += strings.at(i)->toString();
			if (i != strings.size() - 1) {
				result += ",";
			}
		}
		result += ").";
		return result;
	}
	vector<string>* domain() {
		vector<string>* dom = new vector<string>;
		for (String* str : strings) {
			dom->push_back(str->toString());
		}
		return dom;
	}
protected:
	Id* vectorId;
	vector<String*> strings;
};