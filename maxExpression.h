#pragma once
#include "Expression.h"
#include "ImageStore.h"
class maxExpression :
	public Expression
{
	Real x, y, r, g, b, h, s, v;
public:
	maxExpression();
	~maxExpression();
	virtual Variable evaluate();
};

