#pragma once
#include "ImageModifier.h"
class PixelModifier :
	public ImageModifier
{
	virtual void apply();
	virtual Colour modifyPixel(int x, int y);
	virtual void setup();
public:
	PixelModifier();
	PixelModifier(ImageObject* image, Selection* selection);
	~PixelModifier();
};

