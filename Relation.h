#pragma once
#include "Tuple.h"
#include "Scheme.h"
#include "Fact.h"
#include <vector>

class Relation {
public:
	Relation(vector<Id*> s) {
		schema = s;
	}
	Relation(Scheme* scheme) {
		schema = scheme->columnNames;
	}
	void add(Fact* fact);
	void add(Tuple* tuple);
	Relation* select(int col, String* str);
	Relation* select(int col1, int col2);
	Relation* project(vector<int> cols);
	Relation* rename(vector<Id*> names);
private:
	vector<Id*> schema;
	vector<Tuple*> tuples;
};