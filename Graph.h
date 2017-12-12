#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Node {
	int value;
	vector<Node*> children;
	bool visited;
	Node(int v) : visited(false) { value = v; }
	void add(Node* n) {
		for (vector<Node*>::const_iterator it = children.begin(); it < children.end(); ++it) {
			if (n->value == (*it)->value) {
				return;

			}
			if (n->value < (*it)->value) {
				children.insert(it, n);
				return;
			}
		}
		children.push_back(n);
	}
};

class Graph {
public:
	Graph(int size) {
		for (int i = 0; i < size; ++i) {
			dep.push_back(new Node(i));
			rev.push_back(new Node(i));
		}
	}
	~Graph() {}
	void add(int a, int b);
	void postOrder();
	void evaluate(Node* n, vector<int>& v);
	void evaluate(Node* n, set<int>& v);
	vector<set<int>> stronglyConnected();
	string graphToString(bool forward);
	string postOrderToString();
	string connectedToString();
	void test();
private:
	vector<Node*> dep;
	vector<Node*> rev;
	vector<int> po;
};