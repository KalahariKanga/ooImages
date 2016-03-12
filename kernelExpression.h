#pragma once
#include "Expression.h"
class kernelExpression :
	public Expression
{
public:
	kernelExpression();
	~kernelExpression();
	virtual Variable evaluate();
};

