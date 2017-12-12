#include "Graph.h"

void Graph::add(int a, int b) {
	dep.at(a)->add(dep.at(b));
	rev.at(b)->add(rev.at(a));
}

string Graph::graphToString(bool forward) {
	string ans = "";
	vector<Node*> g = forward ? dep : rev;
	for (Node* n : g) {
		ans.append("R" + to_string(n->value) + ":");
		for (Node* c : n->children) {
			ans.append("R" + to_string(c->value) + ",");
		}
		if (ans.back() == ',') ans.pop_back();
		ans.append("\n");
	}
	return ans;
}

void Graph::postOrder() {
	for (Node* n : rev) {
		evaluate(n, po);
	}
	reverse(po.begin(), po.end());
}

void Graph::evaluate(Node* n, vector<int>& v) {
	if (n->visited) return;
	n->visited = true;
	for (Node* c : n->children) {
		evaluate(c, v);
	}
	v.push_back(n->value);
}

string Graph::postOrderToString() {
	po.clear();
	postOrder();
	string ans = "";
	for (int i : po) {
		ans.append(to_string(i) + " ");
	}
	return ans;
}

vector<vector<int>> Graph::stronglyConnected() {
	po.clear();
	postOrder();
	vector<vector<int>> strong;
	for (int i : po) {
		if (dep.at(i)->visited) continue;
		vector<int> v;
		evaluate(dep.at(i), v);
//		reverse(v.begin(), v.end());
		sort(v.begin(), v.end());
		strong.push_back(v);
	}
	return strong;
}

string Graph::connectedToString() {
	string ans = "";
	vector<vector<int>> strong = stronglyConnected();
	for (vector<int> v : strong) {
		ans += "{";
		for (int i : v) {
			ans += to_string(i) + ",";
		}
		if (ans.back() == ',') ans.pop_back();
		ans += "} ";
	}
	return ans;
}

void Graph::test() {
	cout << "Dependency Graph" << endl;
	cout << graphToString(true) << endl;
	cout << "Reverse Graph" << endl;
	cout << graphToString(false) << endl;
	cout << "Post-Order Transversal" << endl;
	cout << postOrderToString() << endl << endl;
	cout << "Strongly Connected Components" << endl;
	cout << connectedToString() << endl << endl;
	cout << "Success!" << endl << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}