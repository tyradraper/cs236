#pragma once

#include "Parameter.h"
#include <string>
using namespace std;

enum Operator { PLUS, TIMES };
static const string OPERATOR_STRING[] = { "+", "*" };

class Expression : public Parameter {
	
};