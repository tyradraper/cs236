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
		if (tuples.size() == 0) {
			str += " No";
			return str;
		}
		str += " Yes(" + to_string(tuples.size()) + ")";
		for (Tuple* tuple : tuples) {
			for (int i = 0; i < tuple->size(); ++i) {
				if (i == 0) {
					str += "\n  ";
				}
				str += schema.at(i) + "=" + tuple->at(i);
				if (i != tuple->size() - 1) {
					str += ", ";
				}
			}
		}
		return str;
	}
private:
	vector<string> schema;
	vector<Tuple*> tuples;
};