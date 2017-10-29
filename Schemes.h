#pragma once
#include "Scheme.h"
#include "Lexer.h"
#include <vector>

class Schemes {
public:
	Schemes(Lexer* lex) {
		lex->next(SCHEMES);
		lex->next(COLON);
		do {
			schemes.push_back(new Scheme(lex));
		} while (lex->top()->type() == ID);
	}
	string toString() {
		string result = "";
		result = result + "Schemes(" + to_string(schemes.size()) + "):\n";
		for (int i = 0; i < schemes.size(); ++i) {
			result += "  " + schemes.at(i)->toString() + "\n";
		}
		return result;
	}
	vector<Scheme*> info() {
		return schemes;
	}
protected:
	vector<Scheme*> schemes;
};