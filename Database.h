#pragma once

#include "Relation.h"
#include "DatalogProgram.h"
#include <map>

class Database {
public:
	Database(DatalogProgram* input) { 
		info = input;
	}
	void schemes();
	void facts();
	string rules();
	string queries();
	Relation* answerQuery(Predicate* q);
	string toString();
private:
	DatalogProgram* info;
	map<string, Relation*> relations;
};