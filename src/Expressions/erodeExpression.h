#pragma once
#include "Expression.h"
class erodeExpression :
	public Expression
{
public:
	erodeExpression();
	~erodeExpression();
	virtual Variable evaluate();
};

