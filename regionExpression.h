#pragma once
#include "Expression.h"
#include "ImageStore.h"
class regionExpression :
	public Expression
{
	Real x, y, r, g, b, h, s, v;
public:
	regionExpression();
	~regionExpression();
	virtual Variable evaluate();
};

