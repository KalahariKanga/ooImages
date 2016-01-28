#pragma once
#include "Expression.h"
class lineExpression :
	public Expression
{
public:
	lineExpression();
	~lineExpression();
	virtual Variable evaluate();
};

