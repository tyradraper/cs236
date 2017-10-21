#pragma once
#include "Tuple.h"
#include <vector>
#include <string>
using namespace std;

class Relation {
public:
	Relation(vector<string> s) {
		schema = s;
	}
	void add(Tuple* tuple);
	Relation* select(int col, string str);
	Relation* select(int col1, int col2);
	Relation* project(vector<int> cols);
	Relation* rename(vector<string> names);
private:
	vector<string> schema;
	vector<Tuple*> tuples;
};