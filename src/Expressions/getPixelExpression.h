#pragma once
#include "Expression.h"
#include "ImageStore.h"

class getPixelExpression :
	public Expression
{
public:
	getPixelExpression();
	~getPixelExpression();
	virtual Variable evaluate();
};

