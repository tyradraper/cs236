/*
Tyra Draper, Section 1, tyra.draper@gmail.com
Purpose: runs the lexical analyzer
Inputs: file name passed in through command line
Outputs: tokens

Test Case 1:
Input:
	!@#$%^
	'a string
	that''s long'
	#|A non-terminating
	block
	::-
Output:
	(UNDEFINED,"!",1)
	(UNDEFINED,"@",1)
	(COMMENT,"#$%^",1)
	(STRING,"'a string
	that''s long'",2)
	(UNDEFINED,"#|A non-terminating
	block
	::-
	",4)
	(EOF,"",7)
	Total tokens = 6

Test Case 2:
Input:
	##|single line|#
	#|# block comment |#
Output:
	(COMMENT,"##|single line|#",1)
	(COMMENT,"#|# block comment |#",2)
	(EOF,"",2)
	Total tokens = 3

Test Case 3:
Input:
	:-:::---::-:
	#opfer;5
	vioar'e
Output:
	(COLON_DASH,":-",1)
	(COLON,":",1)
	(COLON,":",1)
	(COLON_DASH,":-",1)
	(UNDEFINED,"-",1)
	(UNDEFINED,"-",1)
	(COLON,":",1)
	(COLON_DASH,":-",1)
	(COLON,":",1)
	(COMMENT,"#opfer;5",2)
	(ID,"vioar",3)
	(UNDEFINED,"'e",3)
	(EOF,"",3)
	Total tokens = 13
*/

#include "Lexer.h"

int main(int argc, const char* argv[]) {
	Lexer* myLexer = new Lexer(argv[1]);
	myLexer->analyze();
	delete myLexer;
	return 0;
}