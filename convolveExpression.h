#pragma once
#include "ImageModifierExpression.h"
class convolveExpression :
	public ImageModifierExpression
{
	Real x, y, r, g, b, h, s, v;
public:
	convolveExpression();
	~convolveExpression();
	virtual Variable evaluate();
};

