#pragma once
#include "Expression.h"
class invertExpression :
	public Expression
{
public:
	invertExpression();
	~invertExpression();
	virtual Variable evaluate();
};

