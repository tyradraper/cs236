#include "Relation.h"

void Relation::add(Fact* fact) {
	tuples.push_back(new Tuple(fact->strings));
}


void Relation::add(Tuple* tuple) {
	tuples.push_back(tuple);
}

Relation* Relation::select(int col, String* str) {
	Relation* newRel = new Relation(name, schema);
	for (Tuple* tuple : tuples) {
		if (tuple->at(col) == str) {
			newRel->add(tuple);
		}
	}
	return newRel;
}

Relation* Relation::select(int col1, int col2) {
	Relation* newRel = new Relation(name, schema);
	for (Tuple* tuple : tuples) {
		if (tuple->at(col1) == tuple->at(col2)) {
			newRel->add(tuple);
		}
	}
	return newRel;
}

Relation* Relation::project(vector<int> cols) {
	vector<Id*> newSchema;
	for (int i : cols) {
		newSchema.push_back(schema.at(i));
	}
	Relation* newRel = new Relation(name, schema);
	for (Tuple* tuple : tuples) {
		newRel->add(tuple->at(cols));
	}
	return newRel;
}

Relation* Relation::rename(vector<Id*> names) {
	Relation* newRel = new Relation(name, names);
	for (Tuple* tuple : tuples) {
		newRel->add(tuple);
	}
	return newRel;
}