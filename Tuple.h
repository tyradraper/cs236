#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Tuple {
public:
	Tuple(vector<string> input) {
		data = input;
	}
	Tuple* at(vector<int> cols) {
		vector<string> newData;
		for (int i : cols) {
			newData.push_back(data.at(i));
		}
		return new Tuple(newData);
	}
	string at(int col) {
		return data.at(col);
	}
	string toString() {
		string output = "";
		for (string s : data) {
			output += s + " ";
		}
		return output;
	}
	bool operator==(Tuple &other) {
		for (int i = 0; i < data.size(); ++i) {
			if (this->at(i) != other.at(i)) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(Tuple &other) {
		return !(*this == other);
	}
	bool operator<(Tuple &other) {
		for (int i = 0; i < data.size(); ++i) {
			if (this->at(i) != other.at(i)) {
				return (this->at(i).compare(other.at(i)) < 0);
			}
		}
		return false;
	}
private:
	vector<string> data;
};