#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"
class transformExpression :
	public ImageModifierExpression
{
	float x, y, r, g, b, h, s, v;
public:
	transformExpression();
	~transformExpression();
	Variable evaluate();
};

