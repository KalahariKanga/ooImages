#pragma once
#include "Expression.h"
class ifExpression :
	public Expression
{
public:
	ifExpression();
	~ifExpression();
	virtual Variable evaluate();
};

