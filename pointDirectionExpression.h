#pragma once
#include "Expression.h"
class pointDirectionExpression :
	public Expression
{
public:
	pointDirectionExpression();
	~pointDirectionExpression();
	virtual Variable evaluate();
};

