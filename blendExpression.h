#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"
class blendExpression :
	public ImageModifierExpression
{
public:
	blendExpression();
	~blendExpression();
	virtual Variable evaluate();
};

