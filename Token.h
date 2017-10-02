/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: store the type, value, and line number of a token
*/

#ifndef TOKEN_H_
#define TOKEN_H_

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
		kind = UNDEFINED;
		value = "";
		line = -1;
	}
	Token(TokenType t, string v, int l) {
		kind = t;
		value = v;
		line = l;
	}
	virtual ~Token() {}
	string toString();
	TokenType type();
private:
	TokenType kind;
	string value;
	int line;
};

#endif TOKEN_H_