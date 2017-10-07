/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "DatalogProgram.h"

int main(int argc, const char* argv[]) {
	string fn;
	DatalogProgram* myLog;
	for (int i = 1; i < 11; ++i) {
		try {
			fn = "test" + to_string(i) + ".txt";
			myLog = new DatalogProgram(fn);
			myLog->parse();
			delete myLog;
		}
		catch (Token* e) {
			cout << "Failure!" << endl;
			cout << "\t" << e->toString() << endl;
		}
	}
	system("pause");
	return 0;
}