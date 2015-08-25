#pragma once
#include "Expression.h"
#include "ImageStore.h"
class ImageModifierExpression :
	public Expression
{
public:
	ImageModifierExpression();
	~ImageModifierExpression();
	ImageObject *buffer, *image;
	void commitBuffer();
};

