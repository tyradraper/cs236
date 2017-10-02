/*
test1:
test2: id in a factlist (not a factlist)
(COMMA,",",9)
test3: missing period
(ID,"snap",10)
test4: junk after queries

test5:
test6:

*/

#pragma once
#include "Lexer.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"

class DatalogProgram {
public:
	DatalogProgram(string fn) {
		myLexer = new Lexer(fn);
		myLexer->analyze();
	}
	virtual ~DatalogProgram() {}
	void parse();
private:
	Lexer* myLexer;
	Token* current;
	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Rule> rules;
	vector<Predicate> queries;

	void scheme();
	void schemeList();
	void idList();
	void fact();
	void factList();
	void rule();
	void ruleList();
	void headPredicate();
	void predicate();
	void predicateList();
	void parameter();
	void parameterList();
	void expression();
	void anOperator();
	void query();
	void queryList();
	void stringList();
};