#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"

class setPixelsExpression :
	public ImageModifierExpression
{
	float x, y, r, g, b, h, s, v;
public:
	setPixelsExpression();
	~setPixelsExpression();

	Variable evaluate();
};

