#ifndef LEXICALANALYZER_H_
#define LEXICALANALYZER_H_

/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: parse a text file
*/

#include "Token.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Lexer {
public:
	Lexer(string fn) {
		ifs.open(fn);
		curLine = 1;
	}
	virtual ~Lexer() {
		tokens.clear();
	}
	void analyze();
	void print();
	Token* next(TokenType a);
private:
	vector<Token*> tokens;
	int curLine;
	ifstream ifs;

	int curToken;
	bool whitespace();
	bool alpha();
	bool symbol();
	bool str();
	bool comment();
	bool block();
	bool line();
};

#endif LEXICALANALYZER_H_

/*
char .get()
char .peek()
.open(string)

pass by reference:
main:
string filename;
lexer mylex(filename);

here:
lexer(string& fn)
filename=fn;

and in in tokens:
vector<Tokens*>& 
*/