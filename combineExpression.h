#pragma once
#include "Expression.h"
class combineExpression :
	public Expression
{
	float v1, v2;
public:
	combineExpression();
	~combineExpression();
	virtual Variable evaluate();
};

