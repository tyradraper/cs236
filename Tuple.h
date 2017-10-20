#pragma once
#include "String.h"
#include <vector>

class Tuple {
public:
	Tuple(vector<String*> input) {
		data = input;
	}
	Tuple* at(vector<int> cols) {
		vector<String*> newData;
		for (int i : cols) {
			newData.push_back(data.at(i));
		}
		return new Tuple(newData);
	}
	String* at(int col) {
		return data.at(col);
	}
private:
	vector<String*> data;
};