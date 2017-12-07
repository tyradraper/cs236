#pragma once

#include "Relation.h"
#include "DatalogProgram.h"
#include "Graph.h"
#include <map>

class Database {
public:
	Database(DatalogProgram* input) { 
		info = input;
	}
	void schemes();
	void facts();
	string rules();
	vector<set<int>> getOrder(string& s);
	bool evaluateRule(Rule* r);
	string queries();
	Relation* answerQuery(Predicate* q);
	string toString();
private:
	DatalogProgram* info;
	map<string, Relation*> relations;
};