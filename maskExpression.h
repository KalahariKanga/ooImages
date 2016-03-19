#pragma once
#include "Expression.h"
class maskExpression :
	public Expression
{
public:
	maskExpression();
	~maskExpression();
	virtual Variable evaluate();
};

