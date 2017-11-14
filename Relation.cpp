#include "Relation.h"

void Relation::add(vector<string> t) {
	add(new Tuple(t));
}

int Relation::size() {
	return tuples.size();
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
			cols.push_back(i + schema.size());
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
	if (t1->size() != s1.size() || t2->size() != s2.size()) cout << "ERROR";
	for (int i = 0; i < t1->size(); ++i) {
		s.push_back(t1->at(i));
	}
	for (int j = 0; j < s2.size(); ++j) {
		bool unique = true;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1.at(i) == s2.at(j)) {
				unique = false;
				if (t1->at(i) != t2->at(j)) {
					return NULL;
				}
			}
		}
		if (unique) {
			s.push_back(t2->at(j));
		}
	}
	return new Tuple(s);
}

void Relation::add(Relation* r, vector<string> s) {
	vector<int> cols;
	for (string str : s) {
		for (int i = 0; i < r->schema.size(); ++i) {
			if (r->schema.at(i) == str) {
				cols.push_back(i);
				break;
			}
		}
	}
	r = r->project(cols);
	for (Tuple* t : r->tuples) {
		this->add(t);
	}
}

string Relation::toString() {
	string str = "";
	for (string s : schema) {
		str += s;
		str += " ";
	}
	str += "\n";
	if (tuples.size() == 0) {
		str += " No";
		return str;
	}
	str += " Yes(" + to_string(tuples.size()) + ")";
	for (Tuple* tuple : tuples) {
		for (int i = 0; i < tuple->size(); ++i) {
			if (i == 0) {
				str += "\n  ";
			}
			str += schema.at(i) + "=" + tuple->at(i);
			if (i != tuple->size() - 1) {
				str += ", ";
			}
		}
	}
	return str;
}