#pragma once
#include "ImageModifier.h"
class Convolve :
	public ImageModifier
{
	virtual void apply();
public:
	Convolve();
	Convolve(ImageObject* image, Selection* selection);
	~Convolve();
	std::string expr[9];
};

