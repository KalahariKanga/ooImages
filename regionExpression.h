#pragma once
#include "Expression.h"
#include "ImageStore.h"
class regionExpression :
	public Expression
{
public:
	regionExpression();
	~regionExpression();
	virtual Variable evaluate();
};

