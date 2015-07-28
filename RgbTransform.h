#pragma once
#include "PixelModifier.h"
class RgbTransform :
	public PixelModifier
{
	virtual Colour modifyPixel(int x, int y);
	virtual void setup();
public:
	RgbTransform();
	RgbTransform(ImageObject* image, AbstractMask* mask);
	~RgbTransform();
	std::string expr[3]; 
	double x, y, r, g, b, h, s, v;
	ExpressionParser parser[3];
};

