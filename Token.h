/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: store the type, value, and line number of a token
*/

#pragma once

#include <string>
using namespace std;

enum TokenType {
	COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES,
	FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, MY_EOF
};
static const string TOKEN_NAME[] = { "COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN",
"COLON", "COLON_DASH", "MULTIPLY", "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID",
"STRING", "COMMENT", "WHITESPACE", "UNDEFINED", "EOF" };

class Token {
public:
	Token() {
		theType = UNDEFINED;
		theValue = "";
		line = -1;
	}
	Token(TokenType t, string v, int l) {
		theType = t;
		theValue = v;
		line = l;
	}
	virtual ~Token() {}
	string toString();
	TokenType type();
	string value();
protected:
	TokenType theType;
	string theValue;
	int line;
};