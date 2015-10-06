#pragma once
#include "Expression.h"
#include "ImageStore.h"

class minExpression :
	public Expression
{
public:
	minExpression();
	~minExpression();
	virtual Variable evaluate();
};

