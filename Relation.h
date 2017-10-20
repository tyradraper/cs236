#pragma once
#include "Tuple.h"
#include "Scheme.h"
#include "Fact.h"
#include <vector>

class Relation {
public:
	Relation(Id* n, vector<Id*> s) {
		name = n;
		schema = s;
	}
	Relation(Scheme* scheme) {
		name = scheme->schemeId;
		schema = scheme->columnNames;
	}
	void add(Fact* fact);
	void add(Tuple* tuple);
	Relation* select(int col, String* str);
	Relation* select(int col1, int col2);
	Relation* project(vector<int> cols);
	Relation* rename(vector<Id*> names);
private:
	Id* name;
	vector<Id*> schema;
	vector<Tuple*> tuples;
};