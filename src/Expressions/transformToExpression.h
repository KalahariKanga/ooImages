#pragma once
#include "ImageModifierExpression.h"
class transformToExpression :
	public ImageModifierExpression
{
	void drawQuadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, Colour col);
	float r, g, b, a, h, s, v, x, y;
public:
	transformToExpression();
	~transformToExpression();
	virtual Variable evaluate();
};

