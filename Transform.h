#pragma once
#include "ImageModifier.h"
class Transform :
	public ImageModifier
{
	virtual void apply();
public:
	Transform();
	Transform(ImageObject* image, AbstractMask* mask);
	~Transform();
	std::string expr[2];
};

