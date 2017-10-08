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
		analyze();
	}
	virtual ~Lexer() {
		while (tokens.size() > 0) {
			delete tokens.at(tokens.size());
		}
	}
	void analyze();
	void print();
	Token* next(TokenType a);
	Token* top();
	void pop();
	void prev();
	int at();
	void move(int x);
protected:
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