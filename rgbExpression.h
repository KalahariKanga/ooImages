#pragma once
#include "Expression.h"
class rgbExpression :
	public Expression
{

public:
	rgbExpression();
	~rgbExpression();
	Variable evaluate();
};

