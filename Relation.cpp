#include "Relation.h"

void Relation::add(vector<string> t) {
	add(new Tuple(t));
}

void Relation::add(Tuple* tuple) {
	for (vector<Tuple*>::const_iterator it = tuples.begin(); it < tuples.end(); ++it) {
		if (*tuple == **it) {
			return;
		}
		if (*tuple < **it) {
			tuples.insert(it,tuple);
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
	Relation* newRel = new Relation(newSchema);
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

Relation* Relation::join(Relation* r) {
	vector<string> newSchema = schema;
	vector<int> cols;
	for (int i = 0; i < schema.size(); ++i) {
		cols.push_back(i);
	}
	for (int i = 0; i < r->schema.size(); ++i) {
		if (find(schema.begin(), schema.end(), r->schema.at(i)) == schema.end()) {
			newSchema.push_back(r->schema.at(i));
			cols.push_back(i);
		}
	}
	Relation* newRel = new Relation(newSchema);
	for (Tuple* t1 : tuples) {
		for (Tuple* t2 : r->tuples) {
			Tuple* t = joinable(t1, t2, schema, r->schema);
			if (t) {
				newRel->add(t);
			}
		}
	}
	return newRel;
}

Tuple* Relation::joinable(Tuple* t1, Tuple* t2, vector<string> s1, vector<string> s2) {
	vector<string> s;
	for (int i = 0; i < t1->size(); ++i) {
		s.push_back(t1->at(i));
	}
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1.at(i) == s2.at(j) && t1->at(i) != t2->at(j)) {
				return NULL;
			}
			else {
				s.push_back(t2->at(j));
			}
		}
	}
	return new Tuple(s);
}