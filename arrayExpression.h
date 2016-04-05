#pragma once
#include "Expression.h"
#include "Array.h"

class arrayExpression :
	public Expression
{
public:
	arrayExpression();
	~arrayExpression();
	virtual Variable evaluate();
};

