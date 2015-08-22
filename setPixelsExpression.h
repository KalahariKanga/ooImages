#pragma once
#include "Expression.h"
#include "ImageStore.h"

class setPixelsExpression :
	public Expression
{

public:
	setPixelsExpression();
	~setPixelsExpression();

	Variable evaluate();
};

