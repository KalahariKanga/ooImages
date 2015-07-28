#pragma once
#include "Selection.h"
#include "Mask.h"

class ImageModifier
{
	
protected:
	AbstractMask* mask;
	ImageObject* image;
	ImageObject* buffer;
public:
	ImageModifier();
	ImageModifier(ImageObject* image, AbstractMask* mask);
	~ImageModifier();
	void modify();
	virtual void apply();
};

