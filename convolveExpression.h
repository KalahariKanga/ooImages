#pragma once
#include "ImageModifierExpression.h"
class convolveExpression :
	public ImageModifierExpression
{
	float x, y, r, g, b, h, s, v, a;
public:
	convolveExpression();
	~convolveExpression();
	virtual Variable evaluate();
};

