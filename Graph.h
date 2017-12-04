#pragma once
#include <vector>
#include <string>
using namespace std;

struct Node {
	int value;
	vector<Node*> children;
	bool visited;
	Node(int v) : visited(false) { value = v; }
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
	string graphToString(bool forward);
private:
	vector<Node*> dep;
	vector<Node*> rev;
};