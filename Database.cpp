#include "Database.h"

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
		answers += q->toString();
		vector<int> goodCols;
		vector<string> newName;
		Relation* r = relations.at(q->getName());
		for (int i = 0; i < q->getParam().size(); ++i) {
			if (q->getParam().at(i)->type() == ID) {
				r = r->select(i, q->getParam().at(i)->toString());
			}
			else if (q->getParam().at(i)->type() == STRING) {
				for (int j = i + 1; j < q->getParam().size(); ++j) {
					if (q->getParam().at(j)->type() == ID && q->getParam().at(j) == q->getParam().at(i)) {
						r = r->select(i, j);
						break;
					}
				}
			}
			else if (q->getParam().at(i)->type() == -1) {
				answers += "encountered an expression";
			}
			else {
				answers += "you aren't supposed to get here";
			}
			r = r->project(goodCols)->rename(newName);
		}
		
	}
	return answers;
}

string Database::toString() {
	string s = "";
	for (map<string, Relation*>::iterator it = relations.begin(); it != relations.end(); ++it) {
		s += it->first + '\n' + it->second->toString() + "\n\n";
	}
	return s;
}