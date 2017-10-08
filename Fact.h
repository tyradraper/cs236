#pragma once
#include "Id.h"
#include "String.h"
#include "Lexer.h"
#include <vector>

class Fact {
protected:
	Id* vectorId;
	vector<String*> strings;
};