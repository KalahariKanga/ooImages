#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"

class setPixelsExpression :
	public ImageModifierExpression
{

public:
	setPixelsExpression();
	~setPixelsExpression();

	Variable evaluate();
};

