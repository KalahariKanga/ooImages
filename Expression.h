#pragma once
#include "core.h"
#include "Variable.h"

class Expression
{

public:
	Expression();
	~Expression();

	Expression* acquire(std::vector<Expression*>* tokens);
	virtual Variable evaluate() = 0;
	std::vector<Expression*> arguments;
	int noArguments;
};

