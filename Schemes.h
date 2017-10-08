#pragma once
#include "Scheme.h"
#include "Lexer.h"
#include <vector>

class Schemes {
public:
	Schemes(Lexer lex) {
		while (true) {
			try {
				schemes.push_back(new Scheme(lex));
			}
			catch (Token* e) {
				if (schemes.size() == 0) {
					throw e;
				}
				break;
			}
		}
	}
protected:
	vector<Scheme*> schemes;
};