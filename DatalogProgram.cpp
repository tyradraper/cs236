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
//	cout << "1" << endl;
	query();
//	cout << endl << "2" << endl;;
	queryList();
//	cout << endl << "3" << endl;
	myLexer->next(MY_EOF);
//	cout << endl << "4" << endl;
	/*
	current = myLexer->next();
	if (current->type() != SCHEMES) {
		throw current;
	}
	current = myLexer->next();
	if (current->type() != COLON) {
		throw current;
	}
	scheme();
	schemeList();
	current = myLexer->next();
	if (current->type() != FACTS) {
		throw current;
	}
	current = myLexer->next();
	if (current->type() != COLON) {
		throw current;
	}
	factList();
	if (current->type() != RULES) {
		throw current;
	}
	current = myLexer->next();
	if (current->type() != COLON) {
		throw current;
	}
	ruleList();
	if (current->type() != QUERIES) {
		throw current;
	}
	current = myLexer->next();
	if (current->type() != COLON) {
		throw current;
	}
	query();
	queryList();
	*/

	cout << "Success!";
}

void DatalogProgram::scheme() {
	myLexer->next(ID);
	myLexer->next(LEFT_PAREN);
	myLexer->next(ID);
	idList();
	myLexer->next(RIGHT_PAREN);
}

void DatalogProgram::schemeList() {
	try {
		scheme();
	}
	catch (Token* e) {
		return;
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
	try {
		myLexer->next(ID);
	}
	catch (Token* e) {
		myLexer->prev();
		return;
	}
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
	try {
		fact();
	}
	catch (Token* e) {
		return;
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
	try {
		rule();
	}
	catch (Token* e) {
		return;
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
//	cout << "predicate";
	myLexer->next(ID);
//	cout << "a";
	myLexer->next(LEFT_PAREN);
//	cout << "b";
	parameter();
//	cout << "c";
	parameterList();
//	cout << "d";
	myLexer->next(RIGHT_PAREN);
}

void DatalogProgram::predicateList() {
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	try {
		predicate();
	}
	catch (Token* e) {
		myLexer->prev();
		return;
	}
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
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	try {
		parameter();
	}
	catch (Token* e) {
		myLexer->prev();
		return;
	}
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
	try {
		query();
	}
	catch (Token* e) {
		return;
	}
	queryList();
}

void DatalogProgram::stringList() {
	try {
		myLexer->next(COMMA);
	}
	catch (Token* e) {
		return;
	}
	try {
		myLexer->next(STRING);
	}
	catch (Token* e) {
		myLexer->prev();
		return;
	}
	stringList();
}
