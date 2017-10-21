#pragma once

#include "Relation.h"
#include "DatalogProgram.h"
#include <vector>

class Database {
public:
	Database(DatalogProgram* input) {

	}
private:
	vector<Relation*> relations;
};