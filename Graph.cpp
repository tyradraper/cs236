#include "Graph.h"

void Graph::add(int a, int b) {
	dep.at(a)->children.push_back(dep.at(b));
	rev.at(b)->children.push_back(rev.at(a));
}

string Graph::graphToString(bool forward) {
	string ans = "";
	vector<Node*> g = forward ? dep : rev;
	for (Node* n : g) {
		ans.append("R" + to_string(n->value) + ":");
		for (Node* c : n->children) {
			ans.append("R" + to_string(c->value) + ",");
		}
		ans.pop_back();
		ans.append("\n");
	}
	ans.pop_back();
	return ans;
}