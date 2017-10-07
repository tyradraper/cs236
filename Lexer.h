/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: parse a text file
*/

#pragma once

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
	void prev();
	int at();
	void move(int x);
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