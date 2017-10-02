/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: implement the Token.h functions
*/

#include "Token.h"

string Token::toString() {
	return "(" + TOKEN_NAME[kind] + ",\"" + value + "\"," + to_string(line) + ")";
}

TokenType Token::type() { 
	return kind; 
}