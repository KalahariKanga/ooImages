#pragma once
#include "Expression.h"

class loadImageExpression :
	public Expression
{
public:
	loadImageExpression();
	~loadImageExpression();
	virtual Variable evaluate();
};

