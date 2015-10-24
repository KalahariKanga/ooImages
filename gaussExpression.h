#pragma once
#include "Expression.h"
class gaussExpression :
	public Expression
{
public:
	gaussExpression();
	~gaussExpression();
	virtual Variable evaluate();
};

