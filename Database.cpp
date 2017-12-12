#include "Database.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Database::schemes() {
	for (Scheme* s : info->getSchemes()) {
		relations.insert(pair<string, Relation*>(s->getName(), new Relation(s->getSchema())));
	}
}

void Database::facts() {
	for (Fact* f : info->getFacts()) {
		relations.at(f->getName())->add(f->getTuple());
	}
}

string Database::rules() {
	string ans = "";
	bool tuplesAdded = false;
	vector<vector<int>> r = getOrder(ans);
	ans += "\nRule Evaluation\n";
	for (vector<int> set : r) {
		bool recursive = true;
		if (set.size() == 1) {
			recursive = false;
			for (Predicate* p : info->getRules().at(set.at(0))->getPredicates()) { //FIX ME PLS
				if (info->getRules().at(set.at(0))->getHead()->getName() == p->getName()) {
					recursive = true;
				}
			}
		}
		int passes = 0;
		do {
			tuplesAdded = false;
			for (int i : set) {
				if (evaluateRule(info->getRules().at(i))) {
					tuplesAdded = true;
				}
			}
			passes++;
		} while (tuplesAdded && recursive);
		ans += to_string(passes) + " passes: ";
		for (int i : set) {
			ans += "R" + to_string(i) + ",";
		}
		if (ans.back() == ',') ans.pop_back();
		ans += "\n";
	}


	/*
	do {
		tuplesAdded = false;
		for (Rule* rule : info->getRules()) {
			if (evaluateRule(rule)) tuplesAdded = true;
		}
		passes++;
	} while (tuplesAdded == true);
	*/
	return ans;
}

vector<vector<int>> Database::getOrder(string& s) {
	Graph g = Graph(info->getRules().size());
	for (int i = 0; i < info->getRules().size(); ++i) {
		for (Predicate* p : info->getRules().at(i)->getPredicates()) {
			for (int j = 0; j < info->getRules().size(); ++j) {
				if (p->getName() == info->getRules().at(j)->getHead()->getName()) {
					g.add(i, j);
				}
			}
		}
	}
	s += "Dependency Graph\n" + g.graphToString(true);
	return g.stronglyConnected();
}

bool Database::evaluateRule(Rule* rule) {
	try {
		Relation* r = answerQuery(rule->getPredicates().at(0));
		for (int i = 1; i < rule->getPredicates().size(); ++i) {
			r = r->join(answerQuery(rule->getPredicates().at(i)));
		}
		vector<string> param;
		for (Parameter* p : rule->getHead()->getParam()) {
			param.push_back(p->toString());
		}
		int x = relations.at(rule->getHead()->getName())->size();
		relations.at(rule->getHead()->getName())->add(r, param);
		if (relations.at(rule->getHead()->getName())->size() != x) {
			return true;
		}
	}
	catch (const std::out_of_range& e) {}
	return false;
}

string Database::queries() {
	string answers = "Query Evaluation\n";
	for (Query* q : info->getQueries()) {
		answers += q->toString() + answerQuery(q)->toString() + "\n";
	}
	if (!answers.empty() && answers[answers.length() - 1] == '\n') {
		answers.erase(answers.length() - 1);
	}
	return answers;
}

Relation* Database::answerQuery(Predicate* q) {
	vector<int> cols;
	vector<string> names;
	Relation* r = relations.at(q->getName());	
	for (int i = 0; i < q->getParam().size(); ++i) {
		if (q->getParam().at(i)->type() == STRING) {
			r = r->select(i, q->getParam().at(i)->toString());
		}
		else if (q->getParam().at(i)->type() == ID) {
			/*
			bool unique = true;
			for (int j = 0; j < names.size(); ++j) {
				if (names.at(j) == q->getParam().at(i)->toString()) {
					unique = false;
//					cout << "not unique at " << q->getParam().at(i)->toString() << endl;
				}
			}
			if (unique) {
				names.push_back(q->getParam().at(i)->toString());
				cols.push_back(i);
			}*/
			if (find(names.begin(), names.end(), q->getParam().at(i)->toString()) == names.end()) {
				names.push_back(q->getParam().at(i)->toString());
				cols.push_back(i);
			}
						
			for (int j = i + 1; j < q->getParam().size(); ++j) {
				if (q->getParam().at(j)->type() == ID && q->getParam().at(j)->toString() == q->getParam().at(i)->toString()) {
					r = r->select(i, j);
				}
			}
		}
		else {
			throw q->getParam().at(i);
		}
	}
	return r->project(cols)->rename(names);
}

string Database::toString() {
	string s = "";
	for (map<string, Relation*>::iterator it = relations.begin(); it != relations.end(); ++it) {
		s += it->first + '\n' + it->second->toString() + "\n\n";
	}
	return s;
}