#pragma once
#include "ImageModifier.h"
class RgbTransform :
	public ImageModifier
{
	virtual void apply();
public:
	RgbTransform();
	RgbTransform(ImageObject* image, Selection* selection);
	~RgbTransform();
	std::string expr[3]; 
};

