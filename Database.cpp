#include "Database.h"
#include <iostream>
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

void Database::rules() {

}

string Database::queries() {
	string answers = "";
	for (Query* q : info->getQueries()) {
		answers += q->toString() + answerQuery(q)->toString() + "\n";
	}
	if (!answers.empty() && answers[answers.length() - 1] == '\n') {
		answers.erase(answers.length() - 1);
	}
	return answers;
}

Relation* Database::answerQuery(Query* q) {
	vector<int> cols;
	vector<string> names;
	Relation* r = relations.at(q->getName());
	for (int i = 0; i < q->getParam().size(); ++i) {
//		cout << "processing parameter " << i << endl;
		if (q->getParam().at(i)->type() == STRING) {
			r = r->select(i, q->getParam().at(i)->toString());
//			cout << "selecting on " << q->getParam().at(i)->toString() << endl;
		}
		else if (q->getParam().at(i)->type() == ID) {
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
			}
			/*			if (find(names.begin(), names.end(), q->getParam().at(i)->toString()) == names.end()) {
							names.push_back(q->getParam().at(i)->toString());
							cols.push_back(i);
						}
						*/
			for (int j = i + 1; j < q->getParam().size(); ++j) {
				if (q->getParam().at(j)->type() == ID && q->getParam().at(j)->toString() == q->getParam().at(i)->toString()) {
					r = r->select(i, j);
//					cout << "selecting" << q->getParam().at(j)->toString() << " and " << q->getParam().at(i)->toString() << endl;

				}
			}
		}
		else {
			throw q->getParam().at(i);
		}
	}
	r = r->project(cols)->rename(names);
	return r;
}

string Database::toString() {
	string s = "";
	for (map<string, Relation*>::iterator it = relations.begin(); it != relations.end(); ++it) {
		s += it->first + '\n' + it->second->toString() + "\n\n";
	}
	return s;
}