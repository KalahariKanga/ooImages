#pragma once
#include "Expression.h"
class dilateExpression :
	public Expression
{
public:
	dilateExpression();
	~dilateExpression();
	virtual Variable evaluate();
};

