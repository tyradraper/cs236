/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "Relation.h"

int main(int argc, const char* argv[]) {
	vector<string> colNames = { "A", "B", "C", "D" };
	Relation* myRelation = new Relation(colNames);
	myRelation->toString();
	cout << endl << endl;
	vector<string> tuple = { "a", "b" , "c", "d" };
	myRelation->add(tuple);
	tuple = { "a", "a" , "c", "d" };
	myRelation->add(tuple);
	tuple = { "d", "d" , "d", "d" };
	myRelation->add(tuple);
	tuple = { "a", "b" , "c", "c" };
	myRelation->add(tuple);
	myRelation->toString();
	cout << endl << endl;
	myRelation->rename({ "C","D","E","F" })->toString();
	myRelation->project({ 1,3 })->toString();
	myRelation->select(3, "d")->toString();
	myRelation->select(2, 3)->toString();



	/*
	vector<string> colNames = { "A", "B" };
	Relation* myRelation = new Relation(colNames);
	myRelation->toString();
	cout << endl << endl;
	vector<string> tuple = { "'a'", "'b'" };
	myRelation->add(tuple);
	tuple = { "'b'", "'c'" };
	myRelation->add(tuple);
	tuple = { "'b'", "'b'" };
	myRelation->add(tuple);
	tuple = { "'b'", "'c'" };
	myRelation->add(tuple);
	myRelation->toString();
	cout << endl << endl;
	myRelation->rename({ "C","D" })->toString();
	myRelation->project({ 0 })->toString();
	myRelation->select(1, "'c'")->toString();
	myRelation->select(0, 1)->toString();
	*/

	/*
//	string fn;
	DatalogProgram* myLog;
//	for (int i = 11; i < 13; ++i) {
		try {
//			fn = "file" + to_string(i) + ".txt";
			Lexer* lex = new Lexer(argv[1]);
			myLog = new DatalogProgram(lex);
			cout << "Success!" << endl;
			cout << myLog->toString();
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