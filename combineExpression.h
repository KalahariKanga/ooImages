#pragma once
#include "Expression.h"
class combineExpression :
	public Expression
{
public:
	combineExpression();
	~combineExpression();
	virtual Variable evaluate();
};

