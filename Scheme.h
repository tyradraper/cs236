#pragma once
#include "Id.h"
#include "Lexer.h"
#include <vector>

class Scheme {
	friend class Relation;
public:
	Scheme(Lexer* lex) {
		schemeId = new Id(lex);
		lex->next(LEFT_PAREN);
		columnNames.push_back(new Id(lex));
		while (lex->top()->type() == COMMA) {
			lex->pop();
			columnNames.push_back(new Id(lex));
		}
		lex->next(RIGHT_PAREN);
	}
	string toString() {
		string result = "";
		result += schemeId->toString() + "(";
		for (int i = 0; i < columnNames.size(); ++i) {
			result += columnNames.at(i)->toString();
			if (i != columnNames.size() - 1) {
				result += ",";
			}
		}
		result += ")";
		return result;
	}
	string getName() {
		return schemeId->toString();
	}
	vector<string> getSchema() {
		vector<string> schema;
		for (Id* id : columnNames) {
			schema.push_back(id->toString());
		}
		return schema;
	}
private:
	Id* schemeId;
	vector<Id*> columnNames;
};