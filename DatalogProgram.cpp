/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: implement the DatalogProgram.h file
*/

/*
#pragma once
#include "DatalogProgram.h"

void DatalogProgram::parse() {
	lex->next(SCHEMES);
	lex->next(COLON);
	scheme();
	schemeList();
	lex->next(FACTS);
	lex->next(COLON);
	factList();
	lex->next(RULES);
	lex->next(COLON);
	ruleList();
	lex->next(QUERIES);
	lex->next(COLON);
	query();
	queryList();
	lex->next(MY_EOF);
	cout << "Success!" << endl;
}

void DatalogProgram::scheme() {
	lex->next(ID);
	lex->next(LEFT_PAREN);
	lex->next(ID);
	idList();
	lex->next(RIGHT_PAREN);
}

void DatalogProgram::schemeList() {
	int init = lex->at();
	try {
		scheme();
	}
	catch (Token* e) {
		if (lex->at() == init) {
			return;
		}
		else throw e;
	}
	schemeList();
}

void DatalogProgram::idList() {
	try {
		lex->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	lex->next(ID);
	idList();
}

void DatalogProgram::fact() {
	lex->next(ID);
	lex->next(LEFT_PAREN);
	lex->next(STRING);
	stringList();
	lex->next(RIGHT_PAREN);
	lex->next(PERIOD);
}

void DatalogProgram::factList() {
	int init = lex->at();
	try {
		fact();
	}
	catch (Token* e) {
		if (lex->at() == init) {
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
	lex->next(COLON_DASH);
	predicate();
	predicateList();
	lex->next(PERIOD);
}

void DatalogProgram::ruleList() {
	int init = lex->at();
	try {
		rule();
	}
	catch (Token* e) {
		if (lex->at() == init) {
			return;
		}
		else {
			throw e;
		}
	}
	ruleList();
}

void DatalogProgram::headPredicate() {
	lex->next(ID);
	lex->next(LEFT_PAREN);
	lex->next(ID);
	idList();
	lex->next(RIGHT_PAREN);
}

void DatalogProgram::predicate() {
	lex->next(ID);
	lex->next(LEFT_PAREN);
	parameter();
	parameterList();
	lex->next(RIGHT_PAREN);
}

void DatalogProgram::predicateList() {
	int init = lex->at();
	try {
		lex->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	predicate();
	predicateList();
}

void DatalogProgram::parameter() {
	try {
		lex->next(STRING);
	}
	catch (Token* e) {
		try {
			lex->next(ID);
		}
		catch (Token* f) {
			expression();
		}
	}
}

void DatalogProgram::parameterList() {
	int init = lex->at();
	try {
		lex->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	parameter();
	parameterList();
}

void DatalogProgram::expression() {
	lex->next(LEFT_PAREN);
	parameter();
	anOperator();
	parameter();
	lex->next(RIGHT_PAREN);
}

void DatalogProgram::anOperator() {
	try {
		lex->next(ADD);
	}
	catch (Token* e) {
		lex->next(MULTIPLY);
	}
}

void DatalogProgram::query() {
	predicate();
	lex->next(Q_MARK);
}

void DatalogProgram::queryList() {
	int init = lex->at();
	try {
		query();
	}
	catch (Token* e) {
		if (lex->at() == init) {
			return;
		}
		else {
			throw e;
		}
	}
	queryList();
}

void DatalogProgram::stringList() {
	int init = lex->at();
	try {
		lex->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	lex->next(STRING);
	stringList();
}

*/