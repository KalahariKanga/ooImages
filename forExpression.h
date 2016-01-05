#pragma once
#include "Expression.h"
class forExpression :
	public Expression
{
public:
	forExpression();
	~forExpression();
	virtual Variable evaluate();
};

