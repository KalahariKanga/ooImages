#pragma once
#include "Expression.h"
class saveImageExpression :
	public Expression
{
public:
	saveImageExpression();
	~saveImageExpression();
	virtual Variable evaluate();
};

