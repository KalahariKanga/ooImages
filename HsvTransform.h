#pragma once
#include "PixelModifier.h"
class HsvTransform :
	public PixelModifier
{
	virtual Colour modifyPixel(int x, int y);
	virtual void setup();
public:
	HsvTransform();
	HsvTransform(ImageObject* image, Selection* selection);
	~HsvTransform();


	std::string expr[3];
	double x, y, r, g, b, h, s, v;
	ExpressionParser parser[3];
};

