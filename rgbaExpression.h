#pragma once
#include "Expression.h"
class rgbaExpression :
	public Expression
{
public:
	rgbaExpression();
	~rgbaExpression();
	virtual Variable evaluate();
};

