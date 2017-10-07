/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: checks the syntax of a given file

test1: expressions & nested expressions
Success!
test2: id in a factlist (not a factlist)
(COMMA,",",9)
test3: facts before queries
(FACTS,"Facts",1)
test4: junk after queries
(ID,"Hello",20)
test5: two commas in a row
(COMMA,",",13)
test6: second period missing (right before a new section)
(RULES,"Rules",12)
test7: comment block inside functions
Success!
test8: colon instead of colon-dash for rules
(COLON,":",13)
test9: empty file
(EOF,"",1)
test10: undefined token
(UNDEFINED,"&",6)
*/

#pragma once

#include "Lexer.h"

#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"

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
	Schemes scemes;
	Facts facts;
	Rules rules;
	Queries queries;

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