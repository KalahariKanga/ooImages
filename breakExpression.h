#pragma once
#include "Expression.h"
class breakExpression :
	public Expression
{
public:
	breakExpression();
	~breakExpression();
	virtual Variable evaluate();
};

