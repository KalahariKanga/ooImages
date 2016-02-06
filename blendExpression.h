#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"
class blendExpression :
	public ImageModifierExpression
{
	Real x, y;
	Real r1, g1, b1, h1, s1, v1;
	Real r2, g2, b2, h2, s2, v2;
public:
	blendExpression();
	~blendExpression();
	virtual Variable evaluate();
};

