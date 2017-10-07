/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: implement the DatalogProgram.h file
*/

#pragma once
#include "DatalogProgram.h"

void DatalogProgram::parse() {
	myLexer->next(SCHEMES);
	myLexer->next(COLON);
	scheme();
	schemeList();
	myLexer->next(FACTS);
	myLexer->next(COLON);
	factList();
	myLexer->next(RULES);
	myLexer->next(COLON);
	ruleList();
	myLexer->next(QUERIES);
	myLexer->next(COLON);
	query();
	queryList();
	myLexer->next(MY_EOF);
	cout << "Success!" << endl;
}

void DatalogProgram::scheme() {
	myLexer->next(ID);
	myLexer->next(LEFT_PAREN);
	myLexer->next(ID);
	idList();
	myLexer->next(RIGHT_PAREN);
}

void DatalogProgram::schemeList() {
	int init = myLexer->at();
	try {
		scheme();
	}
	catch (Token* e) {
		if (myLexer->at() == init) {
			return;
		}
		else throw e;
	}
	schemeList();
}

void DatalogProgram::idList() {
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	myLexer->next(ID);
	idList();
}

void DatalogProgram::fact() {
	myLexer->next(ID);
	myLexer->next(LEFT_PAREN);
	myLexer->next(STRING);
	stringList();
	myLexer->next(RIGHT_PAREN);
	myLexer->next(PERIOD);
}

void DatalogProgram::factList() {
	int init = myLexer->at();
	try {
		fact();
	}
	catch (Token* e) {
		if (myLexer->at() == init) {
			return;
		}
		else {
			throw e;
		}
	}
	factList();
}

void DatalogProgram::rule() {
	headPredicate();
	myLexer->next(COLON_DASH);
	predicate();
	predicateList();
	myLexer->next(PERIOD);
}

void DatalogProgram::ruleList() {
	int init = myLexer->at();
	try {
		rule();
	}
	catch (Token* e) {
		if (myLexer->at() == init) {
			return;
		}
		else {
			throw e;
		}
	}
	ruleList();
}

void DatalogProgram::headPredicate() {
	myLexer->next(ID);
	myLexer->next(LEFT_PAREN);
	myLexer->next(ID);
	idList();
	myLexer->next(RIGHT_PAREN);
}

void DatalogProgram::predicate() {
	myLexer->next(ID);
	myLexer->next(LEFT_PAREN);
	parameter();
	parameterList();
	myLexer->next(RIGHT_PAREN);
}

void DatalogProgram::predicateList() {
	int init = myLexer->at();
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	predicate();
	predicateList();
}

void DatalogProgram::parameter() {
	try {
		myLexer->next(STRING);
	}
	catch (Token* e) {
		try {
			myLexer->next(ID);
		}
		catch (Token* f) {
			expression();
		}
	}
}

void DatalogProgram::parameterList() {
	int init = myLexer->at();
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	parameter();
	parameterList();
}

void DatalogProgram::expression() {
	myLexer->next(LEFT_PAREN);
	parameter();
	anOperator();
	parameter();
	myLexer->next(RIGHT_PAREN);
}

void DatalogProgram::anOperator() {
	try {
		myLexer->next(ADD);
	}
	catch (Token* e) {
		myLexer->next(MULTIPLY);
	}
}

void DatalogProgram::query() {
	predicate();
	myLexer->next(Q_MARK);
}

void DatalogProgram::queryList() {
	int init = myLexer->at();
	try {
		query();
	}
	catch (Token* e) {
		if (myLexer->at() == init) {
			return;
		}
		else {
			throw e;
		}
	}
	queryList();
}

void DatalogProgram::stringList() {
	int init = myLexer->at();
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	myLexer->next(STRING);
	stringList();
}
