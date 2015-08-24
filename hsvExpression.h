#pragma once
#include "Expression.h"
class hsvExpression :
	public Expression
{
public:
	hsvExpression();
	~hsvExpression();
	Variable evaluate();
};

