#include "Relation.h"


void Relation::add(Tuple* tuple) {
	for (int i = 0; i < tuples.size(); ++i) {
		if (tuple == tuples.at(i)) {
			return;
		}
	}
	tuples.push_back(tuple);
}

Relation* Relation::select(int col, string str) {
	Relation* newRel = new Relation(schema);
	for (Tuple* tuple : tuples) {
		if (tuple->at(col) == str) {
			newRel->add(tuple);
		}
	}
	return newRel;
}

Relation* Relation::select(int col1, int col2) {
	Relation* newRel = new Relation(schema);
	for (Tuple* tuple : tuples) {
		if (tuple->at(col1) == tuple->at(col2)) {
			newRel->add(tuple);
		}
	}
	return newRel;
}

Relation* Relation::project(vector<int> cols) {
	vector<string> newSchema;
	for (int i : cols) {
		newSchema.push_back(schema.at(i));
	}
	Relation* newRel = new Relation(schema);
	for (Tuple* tuple : tuples) {
		newRel->add(tuple->at(cols));
	}
	return newRel;
}

Relation* Relation::rename(vector<string> names) {
	Relation* newRel = new Relation(names);
	for (Tuple* tuple : tuples) {
		newRel->add(tuple);
	}
	return newRel;
}