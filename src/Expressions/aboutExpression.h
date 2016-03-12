#pragma once
#include "Expression.h"
class aboutExpression :
	public Expression
{
public:
	aboutExpression();
	~aboutExpression();
	virtual Variable evaluate();
};

