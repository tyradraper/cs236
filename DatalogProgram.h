/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: checks the syntax of a given file

test1: expressions & nested expressions
Success!
test2: id in a factlist (not a factlist)
(ID,"id",9)
test3: facts before queries
(FACTS,"Facts",1)
test4: junk after queries
(EOF,"",20)
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
#include "Queries.h"
#include <vector>

class DatalogProgram {
public:
	DatalogProgram(Lexer* lex) {
		schemes = new Schemes(lex);
		facts = new Facts(lex);
		rules = new Rules(lex);
		queries = new Queries(lex);
		lex->next(MY_EOF);
	}
	string toString() {
		return schemes->toString() + facts->toString() + rules->toString() + queries->toString() + facts->domain();
	}
	virtual ~DatalogProgram() {}
	vector<Scheme*> getSchemes() {
		return schemes->info();
	}
	vector<Fact*> getFacts() {
		return facts->info();
	}
	vector<Rule*> getRules() {
		return rules->info();
	}
	vector<Query*> getQueries() {
		return queries->info();
	}
protected:
	Schemes* schemes;
	Facts* facts;
	Rules* rules;
	Queries* queries;
};