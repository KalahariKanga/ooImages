#pragma once
#include "Expression.h"
#include "VariableStore.h"
class VariableExpression :
	public Expression
{
	std::string string;
public:
	VariableExpression(std::string string);
	~VariableExpression();
	virtual Variable evaluate();
};

