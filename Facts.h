#pragma once
#include "Fact.h"
#include "Lexer.h"
#include <vector>
#include <algorithm>
using namespace std;

class Facts {
public:
	Facts(Lexer* lex) {
		lex->next(FACTS);
		lex->next(COLON);
		while (lex->top()->type() == ID) {
			facts.push_back(new Fact(lex));
		}		
	}
	string toString() {
		string result = "";
		result = result + "Facts(" + to_string(facts.size()) + "):\n";
		for (int i = 0; i < facts.size(); ++i) {
			result += "  " + facts.at(i)->toString() + "\n";
		}
		return result;
	}
	string domain() {
		string result = "Domain(";
		vector<string> values;
		for (Fact* fact : facts) {
			vector<string>* individual = fact->domain();
			values.insert(values.end(), individual->begin(), individual->end());
		}
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		result += to_string(values.size()) + "):";
		for (int i = 0; i < values.size(); ++i) {
			result += "\n  " + values.at(i);
		}
		return result;
	}
	vector<Fact*> info() {
		return facts;
	}
protected:
	vector<Fact*> facts;
};