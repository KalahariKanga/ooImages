#pragma once
#include "Expression.h"
#include "ImageStore.h"
class maxExpression :
	public Expression
{
public:
	maxExpression();
	~maxExpression();
	virtual Variable evaluate();
};

