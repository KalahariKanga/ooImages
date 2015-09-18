#pragma once
#include "Expression.h"
#include "ImageStore.h"

class maskExpression :
	public Expression
{
public:
	maskExpression();
	~maskExpression();
	virtual Variable evaluate();
};

