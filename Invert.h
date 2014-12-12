#pragma once
#include "ImageModifier.h"
class Invert :
	public ImageModifier
{
	virtual void apply();
public:
	Invert();
	Invert(ImageObject* image, Selection* selection);
	~Invert();
	
};

