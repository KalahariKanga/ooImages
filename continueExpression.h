#pragma once
#include "Expression.h"
class continueExpression :
	public Expression
{
public:
	continueExpression();
	~continueExpression();
	virtual Variable evaluate();
};

