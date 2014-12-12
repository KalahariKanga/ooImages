#pragma once
#include "Selection.h"

class ImageModifier
{
	
protected:
	Selection* selection;
	ImageObject* image;
	ImageObject* buffer;
public:
	ImageModifier();
	ImageModifier(ImageObject* image, Selection* selection);
	~ImageModifier();
	void modify();
	virtual void apply();
};

