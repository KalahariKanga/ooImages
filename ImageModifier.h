#pragma once
#include "Selection.h"

class ImageModifier
{
	
protected:
	Mask* mask;
	ImageObject* image;
	ImageObject* buffer;
public:
	ImageModifier();
	ImageModifier(ImageObject* image, Mask* mask);
	~ImageModifier();
	void modify();
	virtual void apply();
};

