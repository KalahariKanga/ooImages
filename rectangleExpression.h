#pragma once
#include "Expression.h"
#include "ImageStore.h"
class rectangleExpression :
	public Expression
{
public:
	rectangleExpression();
	~rectangleExpression();
	virtual Variable evaluate();
};

