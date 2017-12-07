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
	/*
	Tuple(Tuple* t1, Tuple* t2) {
		for (string s : t1->data) {
			this->data.push_back(s);
		}
		for (string s : t2->data) {
			this->data.push_back(s);
		}
	}
	*/
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
	int size() {
		return data.size();
	}
	string toString() {
		string output = "";
		for (string s : data) {
			output += s + " ";
		}
		return output;
	}
	bool operator==(Tuple &other) {
		return this->data == other.data;
	}
	bool operator!=(Tuple &other) {
		return !(*this == other);
	}
	bool operator<(Tuple &other) {
		return this->data < other.data;
	}
	vector<string> data;
};