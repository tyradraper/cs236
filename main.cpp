/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "Database.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {

	/*
	string test[10] = {
		"A B C  No",
		"A B C  No",
		"",
		"A B C D \na a c d \na b c d \nd d d d \n",
		"A B C D \na b c c \nd d d d \n",
		"Z X W \na c d \nd d d \n",
		"X Y \na a \na b \n",
		"HI \nc \nd \n",
		"x y \nd d \n"
	};

	Relation* ab = new Relation({ "A", "B" });
	Relation* bc = new Relation({ "B", "C" });
	cout << endl << "Test 1: join two empty relations" << endl;
	cout << ab->toString() << endl << "joined with" << endl << bc->toString() << endl << endl;
	cout << ab->join(bc)->toString() << endl;
	cout << "Success!" << endl << endl;
//	cout << (ab->join(bc)->toString() == test[0] ? "Success!" : "Fail") << endl;


	ab->add({ "a", "b" });
	ab->add({ "c", "b" });
	ab->add({ "d", "c" });
	bc->add({ "a", "b" });
	bc->add({ "d", "a" });
	cout << endl << "Test 2: join 2 relations to get an empty relation" << endl;
	cout << ab->toString() << endl << "joined with" << endl << bc->toString() << endl << endl;
	cout << ab->join(bc)->toString() << endl;
	cout << "Success!" << endl << endl;
//	cout << (ab->join(bc)->toString() == test[1] ? "Success!" : "Fail") << endl;


	bc->add({ "b","d" });
	cout << endl << "Test 3: natural join with results" << endl;
	cout << ab->toString() << endl << "joined with" << endl << bc->toString() << endl << endl;
	cout << ab->join(bc)->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (ab->join(bc)->toString() == test[2] ? "Success!" : "Fail") << endl;


	cout << endl << "Test 4: join with no similar schema" << endl;
	Relation* cd = new Relation({ "C", "D" });
	cd->add({ "a", "b" });
	cd->add({ "e", "j" });
	cout << ab->toString() << endl << "joined with" << endl << cd->toString() << endl << endl;
	cout << ab->join(cd)->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (ab->join(bc)->toString() == test[3] ? "Success!" : "Fail") << endl;

	cout << endl << "Test 5: join multiple (out of order)" << endl;
	Relation* abcd = new Relation({ "A", "B", "C", "D" });
	abcd->add({ "a", "b" , "d", "d" });
	abcd->add({ "b", "a" , "c", "c" });
	abcd->add({ "c", "c" , "c", "d" });
	Relation* bae = new Relation({ "B", "A", "E" });
	bae->add({ "a", "b", "c" });
	bae->add({ "c", "c", "c" });
	cout << bae->toString() << endl << "joined with" << endl << abcd->toString() << endl << endl;
	cout << bae->join(abcd)->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (bae->join(abcd)->toString() == test[4] ? "Success!" : "Fail") << endl;

	cout << endl << "Test 6: join with no new schema headers" << endl;
	Relation* bad = new Relation({ "B", "A", "D" });
	bad->add({ "a", "b" , "c" });
	bad->add({ "c","c","c" });
	cout << abcd->toString() << endl << "joined with" << endl << bad->toString() << endl << endl;
	cout << abcd->join(bad)->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (abcd->join(bad)->toString() == test[5] ? "Success!" : "Fail") << endl;

	cout << endl << "Test 7: join the same relations" << endl;
	cout << abcd->toString() << endl << "joined with itself" << endl << endl;
	cout << abcd->join(abcd)->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (abcd->join(abcd)->toString() == test[6] ? "Success!" : "Fail") << endl;

	cout << endl << "Test 8: join multiple" << endl;
	cout << ab->toString() << endl << "joined with" << endl << bc->toString() << endl << "joined with" << endl << abcd->toString() << endl << endl;
	cout << ab->join(bc->join(abcd))->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (ab->join(bc->join(abcd))->toString() == test[7] ? "Success!" : "Fail") << endl;

	cout << endl << "Test 9: union" << endl;
	bad->add({ "j","k","l" });
	Relation* x = new Relation({ "B","A","E" });
	x->add({ "j","k","l" });
	cout << bae->toString() << endl << "union with" << endl << x->toString() << endl << endl;
	bae->add(x, { "B","A","E" });
	cout << bae->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (bae->toString() == test[8] ? "Success!" : "Fail") << endl;

	cout << endl << "Test 10: union" << endl;
	Relation* y = new Relation({ "B","C" });
	y->add({ "j","k" });
	y->add({ "c","c" });
	y->add({ "b","a" });
	cout << bc->toString() << endl << "union with" << endl << y->toString() << endl << endl;
	bc->add(y, { "B","C" });
	cout << bc->toString() << endl;
	cout << "Success!" << endl << endl;
	//	cout << (bc->toString() == test[9] ? "Success!" : "Fail") << endl;

	cout << endl << endl;
	cout << bc->toString() << endl << "union with" << endl << abcd->toString() << endl << endl;
	bc->add(abcd, { "A","D" });
	cout << bc->toString() << endl;
	*/



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
			cout << myDatabase->queries();
			delete myLog;
		}
		catch (Token* e) {
			cout << "Failure!" << endl;
			cout << "  " << e->toString();
		}
//	}


//	system("pause");
	return 0;
}