#pragma once
#include "Expression.h"
#include "ImageStore.h"
class andExpression :
	public Expression
{
public:
	andExpression();
	~andExpression();
	virtual Variable evaluate();
};

