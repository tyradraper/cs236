#pragma once
#include "Tuple.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Relation {
public:
	Relation(vector<string> s) {
		schema = s;
	}
	void add(vector<string> t);
	void add(Tuple* tuple);
	Relation* select(int col, string str);
	Relation* select(int col1, int col2);
	Relation* project(vector<int> cols);
	Relation* rename(vector<string> names);
	string toString() {
		string str = "";
		for (string s : schema) {
			str += s + " ";
		}
		str += "\n";
		for (Tuple* tuple : tuples) {
			str += tuple->toString() + "\n";
		}
		return str;
	}
private:
	vector<string> schema;
	vector<Tuple*> tuples;
};