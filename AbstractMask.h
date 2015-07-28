#pragma once
#include "stdafx.h"
#include "ExpressionParser.h"
#include "ImageObject.h"
#include "Colour.h"
class AbstractMask
{
public:
	AbstractMask();
	~AbstractMask();

	virtual void combine(std::string op, AbstractMask* other) = 0;
	virtual void invert() = 0;
	virtual float getValue(int x, int y) = 0;
	int width, height;
};

