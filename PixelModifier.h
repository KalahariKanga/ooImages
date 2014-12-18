#pragma once
#include "ImageModifier.h"
class PixelModifier :
	public ImageModifier
{
	virtual void apply();
	virtual Colour modifyPixel(int x, int y);
public:
	PixelModifier();
	PixelModifier(ImageObject* image, Selection* selection);
	~PixelModifier();
};

