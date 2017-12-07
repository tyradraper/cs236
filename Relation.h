#pragma once
#include "Tuple.h"
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class Relation {

public:
	Relation(vector<string> s) {
		schema = s;
	}
	void add(vector<string> t);
	void add(Tuple* tuple);
	void add(Relation* r, vector<string> s);
	Relation* select(int col, string str);
	Relation* select(int col1, int col2);
	Relation* project(vector<int> cols);
	Relation* rename(vector<string> names);
	Relation* join(Relation* r);
	Tuple* joinable(Tuple* t1, Tuple* t2, vector<string> s1, vector<string> s2);
	string toString();
	int size();
protected:
	vector<string> schema;
	set<Tuple*, PointerComparer> tuples;
};