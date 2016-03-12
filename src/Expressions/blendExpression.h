#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"
class blendExpression :
	public ImageModifierExpression
{
	float x, y;
	float r1, g1, b1, h1, s1, v1, a1;
	float r2, g2, b2, h2, s2, v2, a2;
public:
	blendExpression();
	~blendExpression();
	virtual Variable evaluate();
};

