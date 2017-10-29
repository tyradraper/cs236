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