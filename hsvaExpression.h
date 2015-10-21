#pragma once
#include "Expression.h"
class hsvaExpression :
	public Expression
{
public:
	hsvaExpression();
	~hsvaExpression();
	virtual Variable evaluate();
};

