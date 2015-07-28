#pragma once
#include "PixelModifier.h"
class Convolve :
	public PixelModifier
{
	virtual Colour modifyPixel(int x, int y);
	virtual void setup();
public:
	Convolve();
	Convolve(ImageObject* image, AbstractMask* mask);
	~Convolve();


	std::string expr[9];
	ExpressionParser parser[3][3];
	Colour source[3][3];
	double x, y, r, g, b, h, s, v;
};

