#pragma once
#include "Expression.h"
class usingExpression :
	public Expression
{
public:
	usingExpression();
	~usingExpression();
	virtual Variable evaluate();
};

