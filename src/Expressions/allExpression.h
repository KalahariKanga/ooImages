#pragma once
#include "Expression.h"
#include "ImageStore.h"

class allExpression :
	public Expression
{
public:
	allExpression();
	~allExpression();
	virtual Variable evaluate();
};

