#pragma once
#include "Expression.h"
class imageExpression :
	public Expression
{
public:
	imageExpression();
	~imageExpression();
	virtual Variable evaluate();
};

