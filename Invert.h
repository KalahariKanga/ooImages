#pragma once
#include "PixelModifier.h"
class Invert :
	public PixelModifier
{
	virtual Colour modifyPixel(int x, int y);
	virtual void setup();
public:
	Invert();
	Invert(ImageObject* image, Selection* selection);
	~Invert();
	
};

