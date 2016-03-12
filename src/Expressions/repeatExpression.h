#pragma once
#include "Expression.h"
class repeatExpression :
	public Expression
{
public:
	repeatExpression();
	~repeatExpression();
	virtual Variable evaluate();
};

