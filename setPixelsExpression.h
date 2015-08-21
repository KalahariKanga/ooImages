#pragma once
#include "Expression.h"
class setPixelsExpression :
	public Expression
{
protected:
	int noArguments = 1;
	std::vector<Expression> arguments;
public:
	setPixelsExpression();
	~setPixelsExpression();

	Variable evaluate();
};

