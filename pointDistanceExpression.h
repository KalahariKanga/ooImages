#pragma once
#include "Expression.h"
class pointDistanceExpression :
	public Expression
{
public:
	pointDistanceExpression();
	~pointDistanceExpression();
	virtual Variable evaluate();
};

