#pragma once
#include "PixelModifier.h"
class Invert :
	public PixelModifier
{
	virtual Colour modifyPixel(int x, int y);
public:
	Invert();
	Invert(ImageObject* image, Selection* selection);
	~Invert();
	
};

