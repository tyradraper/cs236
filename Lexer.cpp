/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: implement the Lexer.h file
*/

#include "Lexer.h"

void Lexer::analyze() {
	while (ifs.peek() != EOF) {
		if (whitespace()) { continue; }
		if (alpha()) { continue; }
		if (str()) { continue; }
		if (comment()) { continue; }
		symbol();
	}
	tokens.push_back(new Token(MY_EOF, "", curLine));
	curToken = 0;
//	print();
}

bool Lexer::whitespace() {
	if (ifs.peek() == '\n') {
		ifs.get();
		curLine++;
		return true;
	}
	else if (isspace(ifs.peek())) {
		ifs.get();
		return true;
	}
	return false;
}

bool Lexer::alpha() {
	string x = "";
	while (isalpha(ifs.peek())) {
		x += ifs.get();
	}
	if (x.length() == 0) {
		return false;
	}
	if (isdigit(ifs.peek())) {
		while (isalpha(ifs.peek()) || isdigit(ifs.peek())) {
			x += ifs.get();
		}
	}
	else {
		if (x == "Schemes") {
			tokens.push_back(new Token(SCHEMES, x, curLine));
			return true;
		}
		else if (x == "Facts") {
			tokens.push_back(new Token(FACTS, x, curLine));
			return true;
		}
		else if (x == "Rules") {
			tokens.push_back(new Token(RULES, x, curLine));
			return true;
		}
		else if (x == "Queries") {
			tokens.push_back(new Token(QUERIES, x, curLine));
			return true;
		}
	}
	tokens.push_back(new Token(ID, x, curLine));
	return true;
}

bool Lexer::str() {
	if (ifs.peek() != '\'') {
		return false;
	}
	string x(1, ifs.get());
	int newLines = 0;
	while (ifs.peek() != EOF) {
		if (ifs.peek() == '\'') {
			x += ifs.get();
			if (ifs.peek() != '\'') {
				tokens.push_back(new Token(STRING, x, curLine));
				curLine += newLines;
				return true;
			}
		}
		else if (ifs.peek() == '\n') {
			newLines++;
		}
		x += ifs.get();
	}
	tokens.push_back(new Token(UNDEFINED, x, curLine));
	curLine += newLines;
	return true;
}

bool Lexer::comment() {
	if (ifs.peek() != '#') {
		return false;
	}
	ifs.get();
	if (ifs.peek() == '|') {
		return block();
	}
	else {
		return line();
	}
}

bool Lexer::block() {
	string x = "#";
	x += ifs.get();
	int newLines = 0;
	while (ifs.peek() != EOF) {
		if (ifs.peek() == '|') {
			x += ifs.get();
			if (ifs.peek() == '#') {
				x += ifs.get();
//				tokens.push_back(new Token(COMMENT, x, curLine));
				curLine += newLines;
				return true;
			}
		}
		if (ifs.peek() == '\n') {
			newLines++;
		}
		x += ifs.get();
	}
//	tokens.push_back(new Token(UNDEFINED, x, curLine));
	curLine += newLines;
	return true;
}

bool Lexer::line() {
	string x = "#";
	while (ifs.peek() != '\n' && ifs.peek() != EOF) {
		x += ifs.get();
	}
//	tokens.push_back(new Token(COMMENT, x, curLine));
	return true;
}

bool Lexer::symbol() {
	string x(1, ifs.get());
	if (x == ",") {
		tokens.push_back(new Token(COMMA, x, curLine));
		return true;
	}
	if (x == ".") {
		tokens.push_back(new Token(PERIOD, x, curLine));
		return true;
	}
	if (x == "?") {
		tokens.push_back(new Token(Q_MARK, x, curLine));
		return true;
	}
	if (x == "(") {
		tokens.push_back(new Token(LEFT_PAREN, x, curLine));
		return true;
	}
	if (x == ")") {
		tokens.push_back(new Token(RIGHT_PAREN, x, curLine));
		return true;
	}
	if (x == "*") {
		tokens.push_back(new Token(MULTIPLY, x, curLine));
		return true;
	}
	if (x == "+") {
		tokens.push_back(new Token(ADD, x, curLine));
		return true;
	}
	if (x == ":") {
		if (ifs.peek() == '-') {
			x += ifs.get();
			tokens.push_back(new Token(COLON_DASH, x, curLine));
			return true;
		}
		tokens.push_back(new Token(COLON, x, curLine));
		return true;
	}
	else {
		tokens.push_back(new Token(UNDEFINED, x, curLine));
		throw tokens.at(tokens.size() - 1);
	}
	return false;
}

void Lexer::print() {
	for (Token* t : tokens) {
		cout << t->toString() << endl;
	}
	cout << "Total Tokens = " << tokens.size() << endl;
}

Token* Lexer::next(TokenType a) {
	if (curToken < tokens.size()) {
		Token* result = tokens.at(curToken);
		if (result->type() != a) {
			throw result;
		}
		curToken++;
		return result;
	}
	else {
		cout << "ya went too far";
		return tokens.at(curToken - 1);
	}
}