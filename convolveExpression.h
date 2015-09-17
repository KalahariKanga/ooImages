#pragma once
#include "ImageModifierExpression.h"
class convolveExpression :
	public ImageModifierExpression
{
public:
	convolveExpression();
	~convolveExpression();
	virtual Variable evaluate();
};

