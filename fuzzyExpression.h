#pragma once
#include "Expression.h"
#include "ImageStore.h"
#include <queue>

class fuzzyExpression :
	public Expression
{
public:
	fuzzyExpression();
	~fuzzyExpression();
	virtual Variable evaluate();
};

