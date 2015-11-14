#pragma once
#include "Expression.h"
class FunctionCallExpression :
	public Expression
{
	std::string name;
public:
	FunctionCallExpression(std::string name);
	~FunctionCallExpression();
	virtual Variable evaluate();
};

