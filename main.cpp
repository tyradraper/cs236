/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "Relation.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	string test[10] = {
		"A B C D \n",
		"A B C D \na a c d \na b c c \na b c d \nd d d d \n",
		"C D E F \na a c d \na b c c \na b c d \nd d d d \n",
		"B D \na d \nb c \nb d \nd d \n",
		"A B C D \na a c d \na b c d \nd d d d \n",
		"A B C D \na b c c \nd d d d \n",
		"Z X W \na c d \nd d d \n",
		"X Y \na a \na b \n",
		"HI \nc \nd \n",
		"x y \nd d \n"
	};

	vector<string> colNames = { "A", "B", "C", "D" };
	Relation* myRelation = new Relation(colNames);
	if (myRelation->toString() == test[0]) {
		cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	vector<string> tuple = { "a", "b" , "c", "d" };
	myRelation->add(tuple);
	tuple = { "a", "a" , "c", "d" };
	myRelation->add(tuple);
	tuple = { "d", "d" , "d", "d" };
	myRelation->add(tuple);
	tuple = { "a", "b" , "c", "c" };
	myRelation->add(tuple);
	if (myRelation->toString() == test[1]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	if (myRelation->rename({ "C","D","E","F" })->toString() == test[2]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	if (myRelation->project({ 1,3 })->toString() == test[3]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	if (myRelation->select(3, "d")->toString() == test[4]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	if (myRelation->select(2, 3)->toString() == test[5]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	//abcd(Z,Z,X,W)?
	if (myRelation->select(0, 1)->project({ 0, 2, 3 })->rename({ "Z","X","W" })->toString() == test[6]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	//abcd(X,Y,"c","d")?
	if (myRelation->select(2, "c")->select(3, "d")->project({ 0,1 })->rename({ "X","Y" })->toString() == test[7]) {
		cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	//abcd("a","b","c",HI)?
	if (myRelation->select(0, "a")->select(1, "b")->select(2, "c")->project({ 3 })->rename({ "HI" })->toString() == test[8]) {
		cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	//abcd(x,x,y,y)?
	if (myRelation->select(0, 1)->select(2, 3)->project({ 0,2 })->rename({ "x","y" })->toString() == test[9]) {
	cout << "Success!" << endl;
	}
	else {
		cout << "Fail" << endl;
	}
	



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