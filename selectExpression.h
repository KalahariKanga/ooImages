#pragma once
#include "Expression.h"
#include "ImageStore.h"
class selectExpression :
	public Expression
{
public:
	selectExpression();
	~selectExpression();
	virtual Variable evaluate();
};

