#pragma once
#include "Expression.h"
#include "ImageStore.h"

class minExpression :
	public Expression
{
	float x, y, r, g, b, h, s, v;
public:
	minExpression();
	~minExpression();
	virtual Variable evaluate();
};

