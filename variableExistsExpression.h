#pragma once
#include "Expression.h"
class variableExistsExpression :
	public Expression
{
public:
	variableExistsExpression();
	~variableExistsExpression();
	virtual Variable evaluate();
};

