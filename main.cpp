/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the datalog program
Inputs: test cases in the folder
Outputs: success or failure with the offending token
*/

#include "DatalogProgram.h"

int main(int argc, const char* argv[]) {
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
//	system("pause");
	return 0;
}