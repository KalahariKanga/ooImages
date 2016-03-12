#pragma once
#include "Expression.h"
class printExpression :
	public Expression
{
public:
	printExpression();
	~printExpression();
	virtual Variable evaluate();
};

