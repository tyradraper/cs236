/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "Database.h"
#include "Graph.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	Graph g = Graph(5);
	g.add(0, 2);
	g.add(0, 1);
	g.add(2, 4);
	g.add(2, 3);
	g.add(4, 0);
	g.add(3, 1);
	g.add(1, 3);
	cout << g.graphToString(true) << endl << endl;
	cout << g.graphToString(false) << endl;

	/*

//	string fn;
	DatalogProgram* myLog;
	Database* myDatabase;
//	for (int i = 11; i < 13; ++i) {
		try {
//			fn = "file" + to_string(i) + ".txt";
			Lexer* lex = new Lexer(argv[1]);
			myLog = new DatalogProgram(lex);
			myDatabase = new Database(myLog);
			myDatabase->schemes();
			myDatabase->facts();
			cout << myDatabase->rules() << endl;
			cout << myDatabase->toString() << endl;
			cout << myDatabase->queries();
			delete myLog;
		}
		catch (Token* e) {
			cout << "Failure!" << endl;
			cout << "  " << e->toString();
		}
//	}

*/

	system("pause");
	return 0;
}