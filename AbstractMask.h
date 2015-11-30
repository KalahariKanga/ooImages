#pragma once
#include "stdafx.h"
#include "ImageObject.h"
#include "Colour.h"
#include "ResourcePropertyHelper.h"

class AbstractMask : public ResourcePropertyHelper<AbstractMask>
{
public:
	AbstractMask();
	~AbstractMask();

	virtual void invert() = 0;
	virtual float getValue(int x, int y) = 0;
	virtual void about();
	int width, height;
};

