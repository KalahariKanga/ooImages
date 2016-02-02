#pragma once
#include "Expression.h"
class importExpression :
	public Expression
{
public:
	importExpression();
	~importExpression();
	virtual Variable evaluate();
};

