#pragma once
#include "Expression.h"
class createImageExpression :
	public Expression
{
public:
	createImageExpression();
	~createImageExpression();
	virtual Variable evaluate();
};

