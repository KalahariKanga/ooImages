#pragma once
#include "ImageModifier.h"
class HsvTransform :
	public ImageModifier
{
	virtual void apply();
public:
	HsvTransform();
	HsvTransform(ImageObject* image, Selection* selection);

	~HsvTransform();
	std::string expr[3];
};

