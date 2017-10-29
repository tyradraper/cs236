#pragma once
#include "Id.h"
#include "String.h"
#include "Lexer.h"
#include <vector>

class Fact {
	friend class Relation;
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
	string getName() {
		return vectorId->toString();
	}
	vector<string> getTuple() {
		vector<string> tuple;
		for (String* id : strings) {
			tuple.push_back(id->toString());
		}
		return tuple;
	}
protected:
	Id* vectorId;
	vector<String*> strings;
};