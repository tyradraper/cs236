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
	bool Tuple::operator==(Tuple &other) {
		for (int i = 0; i < data.size(); ++i) {
			if (this->at(i) != other.at(i)) {
				return false;
			}
		}
		return true;
	}
	bool Tuple::operator!=(Tuple &other) {
		return !(*this == other);
	}
private:
	vector<String*> data;
};