/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "Graph.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	cout << "Test 1: sample from TAs" << endl << endl;
	Graph g = Graph(5);
	g.add(0, 2);
	g.add(0, 1);
	g.add(2, 4);
	g.add(2, 3);
	g.add(4, 0);
	g.add(3, 1);
	g.add(1, 3);
	g.test();

	cout << "Test 2: sample from TAs - should the scc be 0123 instead?" << endl << endl;
	g = Graph(9);
	g.add(0, 1);
	g.add(0, 2);
	g.add(1, 0);
	g.add(2, 3);
	g.add(2, 2);
	g.add(3, 0);
	g.add(4, 5);
	g.add(5, 4);
	g.add(6, 7);
	g.add(7, 7);
	g.test();

	cout << "Test 3: sample from textbook, all strongly connected" << endl << endl;
	g = Graph(5);
	g.add(0, 1);
	g.add(1, 2);
	g.add(1, 3);
	g.add(2, 3);
	g.add(3, 4);
	g.add(4, 0);
	g.test();

	cout << "Test 4: sample from textbook, only side loop" << endl << endl;
	g = Graph(5);
	g.add(1, 0);
	g.add(1, 2);
	g.add(3, 1);
	g.add(2, 3);
	g.add(3, 4);
	g.add(4, 0);
	g.test();

	cout << "Test 5: sample from textbook problems" << endl << endl;
	g = Graph(6);
	g.add(0, 1);
	g.add(0, 5);
	g.add(1, 0);
	g.add(1, 2);
	g.add(1, 4);
	g.add(2, 3);
	g.add(2, 4);
	g.add(3,4);
	g.add(4,2);
	g.add(5,4);
	g.add(5,0);
	g.test();

	cout << "Test 6: sample from textbook problems" << endl << endl;
	g = Graph(8);
	g.add(1,0);
	g.add(0,4 );
	g.add(1,6 );
	g.add(2,1 );
	g.add(2,5 );
	g.add(3,2 );
	g.add(3,7 );
	g.add(4,3 );
	g.add(4,5 );
	g.add(5,6 );
	g.add(7,6 );
	g.add(7,0 );
	g.test();

	cout << "Test 7: sample from textbook problems" << endl << endl;
	g = Graph(9);
	g.add(0,2 );
	g.add(0, 8);
	g.add(1,0 );
	g.add(1,7 );
	g.add(1,2 );
	g.add(3,1 );
	g.add(3,2 );
	g.add(3,4 );
	g.add(4,3 );
	g.add(5,4 );
	g.add(5,3 );
	g.add(5,6 );
	g.add(6,3 );
	g.add(6,2 );
	g.add(7,6 );
	g.add(7,5 );
	g.add(7,8 );
	g.add(8,0 );
	g.add(8,6 );
	g.test();

	cout << "Test 8: nodes" << endl << endl;
	g = Graph(6);
	g.test();

	cout << "Test 9: sample from textbook" << endl << endl;
	g = Graph(5);
	g.add(4,0 );
	g.add(1,0 );
	g.add(1,2 );
	g.add(2,3 );
	g.add(3,1 );
	g.add(1,4 );
	g.test();

	cout << "Test 10: separate partial loops" << endl << endl;
	g = Graph(7);
	g.add(0,2 );
	g.add(0,6 );
	g.add(1,5 );
	g.add(4,1 );
	g.add(5,4 );
	g.add(3,2 );
	g.add(6,3 );
	g.test();

	/*
	cout << "Test 3: sample from textbook, only side loop" << endl << endl;
	g = Graph(8);
	g.add(, );
	g.test();
	*/


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