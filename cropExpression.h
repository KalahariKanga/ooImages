#pragma once
#include "Expression.h"
#include "ImageStore.h"
class cropExpression :
	public Expression
{
public:
	cropExpression();
	~cropExpression();
	virtual Variable evaluate();
};

