#pragma once
#include "Expression.h"
class returnExpression :
	public Expression
{
public:
	returnExpression();
	~returnExpression();
	virtual Variable evaluate();
};

