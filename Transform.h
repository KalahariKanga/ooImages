#pragma once
#include "ImageModifier.h"
class Transform :
	public ImageModifier
{
	virtual void apply();
public:
	Transform();
	Transform(ImageObject* image, Mask* mask);
	~Transform();
	std::string expr[2];
};

